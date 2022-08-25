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
 * BTMMIBipGprots.h
 *
 * Project:
 * --------
 *   BT BIP MMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_BIP_GPROTS_H__
#define __MMI_BIP_GPROTS_H__

#include "MMI_features.h"

#ifdef __MMI_BT_MTK_SUPPORT__

#if defined(__MMI_BIP_SUPPORT__)

/***************************************************************************** 
 * Include 
 *****************************************************************************/

#ifndef BT_MMI_CM_H
#include "BtcmSrvGprot.h"
#endif

#ifndef __BT_MMI_SCR_H__
#include "BTMMIScr.h"
#endif
#include "MMIDataType.h"
#include "kal_general_types.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MMI_BT_BIP_IMGLIST_SCR_CACHE_SIZE (20 * 1024)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* sending error type */
typedef enum
{
    MMI_BIP_SUCCESS,                /* Success */
    MMI_BIP_PARTIAL_CONTENT,        /* Partial Content */
    MMI_BIP_ERR_CANCELED_BY_USER,   /* Canceled by user */
    MMI_BIP_ERR_TIMEOUT,            /* BIP Request time out */
    MMI_BIP_ERR_XML_GEN_FAIL,       /* xml generate error */
    MMI_BIP_ERR_FILE_OPEN_FAIL,     /* File OPEN error */
    MMI_BIP_ERR_FILE_READ_FAIL,     /* File Read error */
    MMI_BIP_ERR_FILE_WRITE_FAIL,    /* File Write error */
    MMI_BIP_ERR_DISK_FULL,          /* Disk full */
    MMI_BIP_ERR_ROOT_DIR_FULL,      /* Root dir full */
    MMI_BIP_ERR_MEDIA_CHANGED,      /* Memory Card is plug-out */
    MMI_BIP_ERR_REJECT_BY_SERVER,   /* Reject by Server */
    MMI_BIP_ERR_DISCONNECTED,       /* transport layer disconnected */
    MMI_BIP_ERR_BUSY,               /* bipi is busy: sending or getting */
    MMI_BIP_ERR_SCO_REJECT,         /* rejected by SCO */
    MMI_BIP_ERR_BTCHIP_REASON,      /* BT Chip reason */
    MMI_BIP_ERR_INVALID_STATUS,     /* Invalid status */
    MMI_BIP_ERR_INVALID_PARAM,      /* Invalid param */
    MMI_BIP_ERR_FS_DEVICE_BUSY,            /* FS busy */
    MMI_BIP_ERR_OUT_OF_MEMORY,      /* out of memory */
    MMI_BIP_ERR_BROWSE_FAILED,      /* browse image list failed */
    MMI_BIP_ERR_SERVICE_UNAVAILABLE,/* Service unavailable */
    MMI_BIP_ERR_XML_PARSE_FAIL,       /* xml parse error */
    MMI_BIP_ERR_FSQUOTA_FULL,         /* fs quota full */
    MMI_BIP_ERR_FS_WRITE_PROTECTION, /* FS_WRITE_PROTECTION */
    MMI_BIP_ERR_DRM_NO_RIGHTS,       /* received DCFs has no rights */

    /* OBEX error code */    
    MMI_BIP_ERR_BAD_REQUEST,           /* Bad Request */
    MMI_BIP_ERR_UNAUTHORIZED,          /* Unauthorized */
    MMI_BIP_ERR_FORBIDDEN,          /* forbidden */
    MMI_BIP_ERR_NOT_FOUND,          /* Not found */
    MMI_BIP_ERR_METHOD_NOT_ALLOWED,    /* Method Not Allowed */
    MMI_BIP_ERR_NOT_ACCEPTABLE,        /* Not Acceptable */
    MMI_BIP_ERR_REQUEST_TIME_OUT,      /* Request Timed Out */
    MMI_BIP_ERR_UNSUPPORT_MEDIA_TYPE,  /* Unsupported Media Type */
    MMI_BIP_ERR_INTERNAL_SERVER_ERR,   /* Internal Server Error */
    MMI_BIP_ERR_REQ_URL_TOO_LARGE,     /* Request URL too large */

    /* general for getting files result */
    MMI_BIP_ERR_NO_FILES_RECEIVED,   /* No files received */
    MMI_BIP_ERR_SHAREDFOLDER_GONE,   /* shared folder has gone */
    MMI_BIP_ERR_CONFLICT,            /* get file when server is copying*/
    MMI_BIP_RECV_ERR,
    MMI_BIP_ERR_GEN_FILE_FAIL,


    MMI_BIP_ERR_LAST    /* the last error */
} mmi_bt_bip_error_enum;

/************************************************************************
    Extern Global Function
*************************************************************************/
extern void mmi_bt_bip_init(void);      /* global bip init function for CM */
extern void mmi_bt_bip_deinit(void);    /* global bip deinit function for CM */

//extern void mmi_bt_bipr_activate(void);                     /* server activate function for CM */
//extern void mmi_bt_bipr_deactivate(void);                   /* server deactivate function for CM */

extern void mmi_bt_bipr_disconnect_client(srv_bt_cm_bt_addr bd_addr, U32 g_conn_id);      /* server disconnect function for CM */

extern void mmi_bt_bipi_disconnect_responder(srv_bt_cm_bt_addr bd_addr, U32 cm_conn_id);


extern MMI_BOOL mmi_bt_bip_server_is_working(void);  /* check if BIP responder is sending or recieving data */
extern MMI_BOOL mmi_bt_bip_is_run(void);  /* check if BIP initiator is sending or recieving data */
extern MMI_BOOL mmi_bt_bip_client_is_idle(void);  /* check if BIP initiator is idle */
extern MMI_BOOL mmi_bt_bip_is_receiving(void);   /*check bip responder or initiator is sending file or receiving*/


extern U32 mmi_bt_bip_get_recv_images_cnt(void);
extern void mmi_bt_bip_set_recv_images_cnt(U32 cnt);


/* usb mode handler */
#ifdef __MMI_USB_SUPPORT__
#ifdef __MMI_USB_SPLIT_SUPPORT__
extern mmi_ret mmi_bt_bip_enter_usb_mode_hdlr(mmi_event_struct *evt);
#else
BOOL mmi_bt_bip_usb_mode_check(void);
void mmi_bt_bip_enter_usb_mode_hdlr(void);
void mmi_bt_bip_usb_mode_cnf_hdlr(void *msg);
#endif
#else
extern mmi_ret mmi_bt_bip_enter_usb_mode_hdlr(mmi_event_struct *evt);
#endif
/* responder FS operation: pause and continue */
void mmi_bt_bip_server_pause_fs_operation(void);
void mmi_bt_bip_server_continue_fs_operation(void);

/* get server's received folder for IMAGE PUSH */
S8 * mmi_bt_bip_get_server_received_folder(void);
/*BT Concurrency*/
//extern void mmi_bt_bip_connection_authorize_rsp_hdler(srv_bt_cm_bt_addr bd_addr, U32 result);
/*BT Concurrency*/
#endif /* defined(__MMI_BIP_SUPPORT__) */ 

#endif /* __MMI_BT_MTK_SUPPORT__ */ 
#endif /* __BT_MMI_BIP_GPROTS_H__ */ 

