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
 * EngineerModeGPS.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for MiniGPS Engineering mode
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ENGINEER_MODE_GPS_H_
#define _ENGINEER_MODE_GPS_H_

#include "MMI_features.h"

#ifdef __GPS_SUPPORT__
#include "mmidatatype.h"
//#include "mmi_include.h"
#ifdef __AGPS_USER_PLANE__
typedef enum
{
    EM_GPS_SUPL_USE_TLS_NONE,
    EM_GPS_SUPL_USE_TLS_SI,
    EM_GPS_SUPL_USE_TLS_NI,
    EM_GPS_SUPL_USE_TLS_BOTH,
    EM_GPS_SUPL_USE_TLS_END
} em_gps_supl_use_tls_enum;
#endif

typedef enum
{
#if defined(__AGPS_USER_PLANE__)
    EM_GPS_POS_TYPE_AGPS_UP,
#endif
    EM_GPS_POS_TYPE_AGPS_CP,
    EM_GPS_POS_TYPE_GPS_ONLY,
    EM_GPS_POS_TYPE_END
} em_gps_pos_type_enum;

typedef enum
{
    EM_GPS_UP_MOLR_PREF_MB = 0,
    EM_GPS_UP_MOLR_PREF_MA,
    EM_GPS_UP_MOLR_PREF_NONE,
    EM_GPS_UP_MOLR_MB_ONLY,
    EM_GPS_UP_MOLR_MA_ONLY,
    EM_GPS_UP_MOLR_END
} em_gps_up_molr_enum;

typedef enum
{
    EM_GPS_SEND_CMD_WARM_START = 0,
    EM_GPS_SEND_CMD_COLD_START,
    EM_GPS_SEND_CMD_CLEAR_NVRAM,
    EM_GPS_SEND_CMD_AGPS_START,
    EM_GPS_SEND_CMD_SLEEP,
    EM_GPS_SEND_CMD_WAKE_UP,
    EM_GPS_SEND_CMD_STOP,
    EM_GPS_SEND_CMD_END
} em_gps_send_cmd_enum;

typedef enum
{
    EM_GPS_CP_LOC_METHOD_NONE = 0,
	EM_GPS_CP_LOC_METHOD_AGPS,
    EM_GPS_CP_LOC_METHOD_MB_EOTD,
    EM_GPS_CP_LOC_METHOD_MA_EOTD,
    EM_GPS_CP_LOC_METHOD_MB_OTDOA,
    EM_GPS_CP_LOC_METHOD_END
} em_gps_cp_loc_method_enum;

extern void mmi_em_dev_minigps_enter_main_src(void);
extern MMI_ID mmi_em_dev_minigps_get_parent_id(void);

#endif /* __GPS_SUPPORT__ */

#endif /* _ENGINEER_MODE_GPS_H_ */

