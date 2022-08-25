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
 *   Res_DevApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   wgui-level functions for touch screen.
 *
 *	
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "PopulateRes.h"
#include "CustDataProts.h"
#include "DevAppDef.h"


/*****************************************************************************
 * FUNCTION
 *  PopulateDevApp1Res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateDevApp1Res(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ADD_APPLICATION_STRING2(STR_ID_DEVAPP_1, "Str1", "description of Str1");
    ADD_APPLICATION_STRING2(STR_ID_DEVAPP_2, "Str2", "description of Str2");
    ADD_APPLICATION_STRING2(STR_ID_DEVAPP_3, "Str3", "description of Str3");
    ADD_APPLICATION_STRING2(STR_ID_DEVAPP_4, "Str4", "description of Str4");
    ADD_APPLICATION_STRING2(STR_ID_DEVAPP_5, "Str5", "description of Str5");

    ADD_APPLICATION_IMAGE2(IMG_ID_DEVAPP_1,"..\\\\DevResource\\\\Images\\\\EmptyImage.bmp","description of Image1");
    ADD_APPLICATION_IMAGE2(IMG_ID_DEVAPP_2,"..\\\\DevResource\\\\Images\\\\Default.bmp","description of Image2");
    ADD_APPLICATION_IMAGE2(IMG_ID_DEVAPP_3,"..\\\\DevResource\\\\Images\\\\EmptyImage.bmp","description of Image3");
    ADD_APPLICATION_IMAGE2(IMG_ID_DEVAPP_4,"..\\\\DevResource\\\\Images\\\\EmptyImage.bmp","description of Image4");
    ADD_APPLICATION_IMAGE2(IMG_ID_DEVAPP_5,"..\\\\DevResource\\\\Images\\\\EmptyImage.bmp","description of Image5");

    ADD_APPLICATION_AUDIO2(ADO_ID_DEVAPP_1,"..\\\\DevResource\\\\Audio\\\\Default.mp3","demo audio");

    ADD_APPLICATION_MENUITEM((MENU_ID_DEVAPP_1,0,1,MENU_ID_DEVAPP_2,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_DEVAPP_1,IMG_ID_DEVAPP_1));
    ADD_APPLICATION_MENUITEM((MENU_ID_DEVAPP_2,MENU_ID_DEVAPP_1,0,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_DEVAPP_2,IMG_ID_DEVAPP_2));


}

