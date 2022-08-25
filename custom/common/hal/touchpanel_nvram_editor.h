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
 * touchpanel_nvram_editor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __TOUCHPANEL_NVRAM_EDITOR_H__
#define __TOUCHPANEL_NVRAM_EDITOR_H__
#ifndef NVRAM_NOT_PRESENT

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */


/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
 
/*
 *   User Headers
 */
#include "touchpanel_nvram_def.h"


/*
 *   Bit Level Description Language
 */
#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA

LID_BIT VER_LID(NVRAM_EF_TOUCHPANEL_PARA_LID)
    nvram_touchpanel_para_struct *NVRAM_EF_TOUCHPANEL_PARA_TOTAL
    {
        point_low_bound:"touch dual -- single point low bound"
          {
          };
        negative_low_bound:"touch dual max distance on 1/3 coordinate"
          {
          };
        negative_up_bound:"touch dual min distance on 1/3 coordinate"
          {
          };
        positive_up_bound:"touch dual max distance on 2/4 coordinate"
          {
          };
        positive_low_bound:"touch dual min distance on 2/4 coordinate"
          {
          };
        min_x_low_bound:"touch dual vertical max distance on min X"
          {
          };
        min_x_up_bound:"touch dual vertical min distance on min X"
          {
          };
        max_x_low_bound:"touch dual vertical max distance on max X"
          {
          };
        max_x_up_bound:"touch dual vertical min distance on max X"
          {
          };
        min_y_low_bound:"touch dual horizontal max distance on min Y"
          {
          };
        min_y_up_bound:"touch dual horizontal min distance on min Y"
          {
          };
        max_y_low_bound:"touch dual horizontal max distance on max Y"
          {
          };
        max_y_up_bound:"touch dual horizontal min distance on max Y"
          {
          };
    };

 
 
END_NVRAM_DATA

#endif  /* GEN_FOR_PC */
#endif  /* !NVRAM_NOT_PRESENT */
#endif  /* __TOUCHPANEL_NVRAM_EDITOR_H__ */
