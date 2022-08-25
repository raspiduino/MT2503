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
 *  ProcedureConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ID configuration of procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PROCEDURE_CONFIG_H__
#define __PROCEDURE_CONFIG_H__


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    MMI_FRM_PROC_ID_START = 0, /* MMI_FRM_PROC_ID_INVALID */
    /* === Add new procedure ID after this wall === */

    /* Bootup */
    MMI_FRM_PROC_ID_BOOTUP_MAIN,
    MMI_FRM_PROC_ID_BOOTUP_WAIT_FOR_EVENTS,
    MMI_FRM_PROC_ID_BOOTUP_WAITING_TIMER,
    MMI_FRM_PROC_ID_BOOTUP_WAIT_FOR_GPIO,
    MMI_FRM_PROC_ID_BOOTUP_INCEPTION,
    MMI_FRM_PROC_ID_BOOTUP_EARLY_INIT,
    MMI_FRM_PROC_ID_BOOTUP_DISK_CHECK,
    MMI_FRM_PROC_ID_BOOTUP_DISABLE_INTERRUPT,
    MMI_FRM_PROC_ID_BOOTUP_INIT_SIM,
    MMI_FRM_PROC_ID_BOOTUP_MODE_DECISION,
    MMI_FRM_PROC_ID_BOOTUP_ANI_PHASE,
    MMI_FRM_PROC_ID_BOOTUP_PROTOCOL,
    MMI_FRM_PROC_ID_BOOTUP_ANIMATION,
#ifdef  __MMI_BTBOX_NOLCD__
    MMI_FRM_PROC_ID_BOOTUP_PLAYTONE,
#endif    
    MMI_FRM_PROC_ID_BOOTUP_NORMAL_INIT,
    MMI_FRM_PROC_ID_BOOTUP_ENABLE_INTERRUPT,
    MMI_FRM_PROC_ID_BOOTUP_PEN_CALIBRATION,
    MMI_FRM_PROC_ID_BOOTUP_BATTERY_CHECK,
    MMI_FRM_PROC_ID_BOOTUP_SECURITY,
    MMI_FRM_PROC_ID_BOOTUP_WELCOME,
    MMI_FRM_PROC_ID_BOOTUP_PREINSTALL_WIDGET,
    MMI_FRM_PROC_ID_BOOTUP_FTU,

    /* Shutdown */
    MMI_FRM_PROC_ID_SHUTDOWN = 100,
    MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_APPS,
    MMI_FRM_PROC_ID_SHUTDOWN_WAITING,
    MMI_FRM_PROC_ID_SHUTDOWN_ANIMATION,
    MMI_FRM_PROC_ID_SHUTDOWN_BT_DIALER_OFF,
    MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_PROTOCOL,
    MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_WAP,
    MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_MMS_WAP,
    MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_EMAIL,
    MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_OPERA_BROWSER,
    MMI_FRM_PROC_ID_SHUTDOWN_DEINIT_CALL_LOG,
    
    MMI_FRM_PROC_ID_BOOTUP_SHUTDOWN_DUMMY,

    
    /* ----- Following is for service ----- */
    MMI_FRM_PROC_ID_SRV_BEGIN = 5000,


    /* === Add new procedure ID before this wall === */
    MMI_FRM_PROC_ID_FREE_ID_BEGIN = 10000,
    MMI_FRM_PROC_ID_END_OF_ENUM
} mmi_frm_proc_id_enum;

#endif /* __PROCEDURE_CONFIG_H__ */
