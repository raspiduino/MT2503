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
*  mdi_agps.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  AGPS related interface
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*******************************************************************************/

#include "MMI_features.h"
#if defined(__AGPS_SUPPORT__)
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mdi_agps.h"
#include "gps2lcsp_struct.h"
#include "gps_agps_process.h"

/*****************************************************************************
* FUNCTION
*  mdi_gps_agps_get_history_pos
* DESCRIPTION
*  return the history data
* PARAMETERS
*  void
* RETURNS           
*  MMI_TRUE    meet qop
*  MMI_FALSE   not meet qop 
*****************************************************************************/
MMI_BOOL mdi_gps_agps_get_history_pos(gps_pos_qop_struct *qop,gps_pos_result_struct *history_pos,kal_uint16 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gps_agps_get_history_pos(qop,history_pos,bitmap);
}


/*****************************************************************************
* FUNCTION
*  mdi_gps_agps_set_pos
* DESCRIPTION
*  store pos to gps task
* PARAMETERS
*  
* RETURNS           
*  NULL
*****************************************************************************/
void mdi_gps_agps_set_pos(mdi_gps_agps_set_pos_struct *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_agps_set_pos_struct new_pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_pos.latitude      =pos->latitude;     
    new_pos.sign_latitude =pos->sign_latitude;
    new_pos.longtitude    =pos->longtitude;   
    new_pos.sign_altitude =pos->sign_altitude;
    new_pos.altitude      =pos->altitude;     
    new_pos.unc_major     =pos->unc_major;    
    new_pos.unc_minor     =pos->unc_minor;    
    new_pos.unc_bear      =pos->unc_bear;     
    new_pos.unc_vert      =pos->unc_vert;     
    new_pos.confidence    =pos->confidence;   
    new_pos.h_speed       =pos->h_speed;      
    new_pos.bearing       =pos->bearing;      
    new_pos.gps_week      =pos->gps_week;      
    new_pos.tow           =pos->tow;      
    gps_agps_set_history_pos(&new_pos);

}

#endif /*defined(__AGPS_SUPPORT__)*/

