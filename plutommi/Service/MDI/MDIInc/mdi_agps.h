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
 *  mdi_agps.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS related interface hand file, such as GPS uart and NMEA parser
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/

#ifndef _MDI_AGPS_H_
#define _MDI_AGPS_H_

#include "MMI_features.h"
#if defined(__AGPS_SUPPORT__)
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mdi_agps.h"
#include "gps2lcsp_struct.h"
#include "gps_agps_process.h"
typedef struct 
{
    kal_uint32  latitude;         /*latitude */
    MMI_BOOL    sign_latitude;    /* true: SOUTH, false: NORTH */
    kal_int32   longtitude;       /* N2, encoded longtitude with 2's complement */
    MMI_BOOL    sign_altitude;    /* true: DEPTH, false: HEIGHT */
    kal_uint16  altitude;         /* no encoding, unit in meter */
    kal_uint16  unc_major;        /* K1, encoded r1 */
    kal_uint16  unc_minor;        /* K2, encoded r2 */
    kal_uint16  unc_bear;         /* N3, encoded a = 2N3, Bearing of semi-major axis (degrees)*/
    kal_uint16  unc_vert;         /* K3, encode r3, vertical uncertain */
    kal_uint8   confidence;       /* %, The confidence by which the position of a target 
                                  entity is known to be within the shape description, 
                                  expressed as a percentage. [0 ~ 100] (%)*/
    kal_int32   h_speed;          /*horizontal speed*/
    kal_uint16  bearing;          /*Direction of the horizontal speed*/
    kal_uint32  gps_week;
    kal_uint32  tow;
} mdi_gps_agps_set_pos_struct;

extern MMI_BOOL mdi_gps_agps_get_history_pos(gps_pos_qop_struct *qop,gps_pos_result_struct *history_pos,kal_uint16 *bitmap);
extern MMI_BOOL mdi_gps_is_need_assist_data(void);
extern void mdi_gps_agps_set_pos(mdi_gps_agps_set_pos_struct* pos);

#endif /*__AGPS_SUPPORT__*/
#endif /* _MDI_AGPS_H_*/ 




