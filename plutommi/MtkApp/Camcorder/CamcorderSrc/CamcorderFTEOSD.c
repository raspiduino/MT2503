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
 *  CamcorderOSD.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camcorder OSD relative function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#ifndef MMI_CAMCOFTEOSD_C
#define MMI_CAMCOFTEOSD_C

#include "MMI_include.h"
#ifdef __MMI_CAMCORDER__

#include "lcd_if.h"
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mmi_features_camcorder.h"

#include "CamcorderResDef.h"
#include "CamcorderSetting.h"
#ifdef __MMI_CAMCO_FTE__
#include "CamcorderFTEOSD.h"
#endif 
#include "resource_camcorder_skins.h"
#include "CamcorderApp.h"
#include "app_datetime.h"
#ifdef GDI_USING_2D_ENGINE_V3
#include "gdi_2d_engine.h"
#endif 

#ifdef __MMI_MMS_2__
#include "mmi_rp_srv_mms_def.h"
#endif
#ifdef __MMI_BT_SEND_SUPPORT__
#include "mmi_rp_app_bluetooth_def.h"
#endif

#include "MMI_features.h"
#include "gdi_features.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_general_types.h"
#include "lcd_sw_inc.h"
#include "gdi_datatype.h"
#include "g2d_enum.h"
#include "gdi_include.h"
#include "gui_themes.h"
#include "gui.h"
#include "mmi_rp_app_camco_def.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "string.h"
#include "gdi_const.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "FileMgrSrvGProt.h"
#include "GlobalMenuItems.h"
#include "wgui_inputs.h"
#include "lcd_sw_rnd.h"
#include "med_api.h"
#include "kal_trace.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "gui_windows.h"
#include "Unicodexdcl.h"
#include "gui_inputs.h"
#include "wgui_categories_inputs.h"
#include "gdi_lcd_config.h"
#include "fd_comm_def.h"
#include "GlobalConstants.h"
#include "CamcorderGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_touch_screen.h"
#include "gui_typedef.h"

#ifdef __MMI_CAMCO_FTE__

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS    (4)
#define MMI_CAMCO_OSD_RECORD_TIME_TIMER_SHIFT   (4)
#define MMI_CAMCO_OSD_ADD_FRAME_ARROW_SHIFT     (50)
#define MMI_CAMCO_OSD_ADD_FRAME_FILE_INDEX_SHIFT    (20)
#define MMI_CAMCO_OSD_ADD_FRAME_ARROW_OFFSET_Y      (2)
#define MMI_CAMCO_OSD_TOUCH_DUMMY_VAL   (-1)
#define MMI_CAMCO_OSD_FOCUSE_EDGE_RATIO  (20)
#define MMI_CAMCO_OSD_FACE_EDGE_RATIO  (20)

#define SEND_EVT(evt,param) do{ g_mmi_camco_osd_cntx.evt_hdlr(evt, param);        } while(0)
#define img_press_shift(x) ((x?1:0))

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

#if defined(__MTK_TARGET__)
#pragma arm section zidata = "NONCACHEDZI", rwdata = "NONCACHEDRW"
#endif 
mmi_camco_osd_cntx_struct g_mmi_camco_osd_cntx;
mmi_camco_osd_cntx_struct *const mmi_camco_osd_p = &g_mmi_camco_osd_cntx;
mmi_camco_skin_struct *mmi_camco_osd_skin_p = &mmi_camco_main_skin_cntx;

#if defined(__MTK_TARGET__)
#pragma arm section zidata, rwdata
#endif 
/***************************************************************************** 
 * Local Function Prototype
 *****************************************************************************/

extern U8 mmi_camco_osd_touch_translate_object_to_setting(mmi_camco_osd_touch_obj_enum obj);

#ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
static void mmi_camco_osd_panorama_direct_up_press(void);
static void mmi_camco_osd_panorama_direct_up_release(void);
static void mmi_camco_osd_panorama_direct_down_press(void);
static void mmi_camco_osd_panorama_direct_down_release(void);
static void mmi_camco_osd_panorama_direct_left_press(void);
static void mmi_camco_osd_panorama_direct_left_release(void);
static void mmi_camco_osd_panorama_direct_right_press(void);
static void mmi_camco_osd_panorama_direct_right_release(void);
#endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
static void mmi_camco_osd_draw_reduced_progress(U16 ratio);
#endif 
static void mmi_camco_osd_draw_progress(U16 ratio);

static void mmi_camco_osd_iconlist_prev_cyclic(void);
static void mmi_camco_osd_iconlist_next_cyclic(void);
static void mmi_camco_osd_menulist_prev_cyclic(void);
static void mmi_camco_osd_menulist_next_cyclic(void);

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
static void mmi_camco_osd_add_frame_prev_cyclic(void);
static void mmi_camco_osd_add_frame_next_cyclic(void);
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
static void mmi_camco_osd_imgselect_prev_cyclic(void);
static void mmi_camco_osd_imgselect_next_cyclic(void);
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

#ifdef __MMI_TOUCH_SCREEN__
static void mmi_camco_osd_touch_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_camco_osd_touch_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_camco_osd_touch_pen_move_hdlr(mmi_pen_point_struct pos);
static MMI_BOOL mmi_camco_osd_touch_hit_test(S32 pos_x, S32 pos_y, mmi_camco_osd_touch_obj_struct *touch_obj);
static MMI_BOOL mmi_camco_osd_touch_hit_test_ext(S32 pos_x, S32 pos_y, mmi_camco_osd_touch_obj_struct *touch_obj);
static void mmi_camco_osd_touch_iconlist_prev_cyclic(void);
static void mmi_camco_osd_touch_iconlist_next_cyclic(void);
static void mmi_camco_osd_touch_menulist_prev_cyclic(void);
static void mmi_camco_osd_touch_menulist_next_cyclic(void);
void mmi_camco_osd_touch_setting_excute_hdlr(MMI_BOOL execute);
void mmi_camco_osd_touch_cam_advance_setting_pen_down_hdlr(S32 x, S32 y);
void mmi_camco_osd_touch_cam_advance_setting_pen_up_hdlr(S32 x, S32 y);
void mmi_camco_osd_touch_cam_direct_setting_pen_down_hdlr(S32 x, S32 y);
void mmi_camco_osd_touch_cam_direct_setting_pen_up_hdlr(S32 x, S32 y);
void mmi_camco_osd_touch_rec_advance_setting_pen_down_hdlr(S32 x, S32 y);
void mmi_camco_osd_touch_rec_advance_setting_pen_up_hdlr(S32 x, S32 y);
void mmi_camco_osd_touch_rec_direct_setting_pen_down_hdlr(S32 x, S32 y);
void mmi_camco_osd_touch_rec_direct_setting_pen_up_hdlr(S32 x, S32 y);

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
void mmi_camco_sublcd_osd_set_center_processing_hint_str(CHAR *str_ptr);
void mmi_camco_sublcd_osd_draw_hint_process_cyclic(void);
void mmi_camco_sublcd_osd_draw_hint(void);
static void mmi_camco_osd_sublcd_blt(void);
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

static void mmi_camco_osd_draw_focus_hint_process_cyclic(void);

MMI_BOOL mmi_camco_osd_is_in_smile_dect_scrn(void);

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
static void mmi_camco_osd_recording_setup_environment(void);
static void mmi_camco_osd_recording_reset_environment(void);

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
static void mmi_camco_osd_sublcd_stop_hint_set_environment(void);
static void mmi_camco_osd_sublcd_stop_hint_reset_environment(void);
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
static void mmi_camco_osd_draw_multiline_center_hint(CHAR * str_ptr);
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
#ifdef __MMI_INTERACTIVE_PROFILNG__
extern MMI_BOOL mmi_frm_profiling_interactive_is_enabled(void);
#endif 
void mmi_camco_osd_draw_multiline_confirm_hint(CHAR * str_ptr);

void mmi_camco_osd_touch_setting_menu_pen_up_hdlr(mmi_cameco_osd_advance_setting_action_enum is_enter, S32 idx);


/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_reg_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hdlr_func_ptr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_is_horz_UI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        return MMI_TRUE;
    }
#ifdef DUAL_CAMERA_SUPPORT
    else
    {
        return MMI_FALSE;
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
#else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
    return MMI_FALSE;
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_reg_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hdlr_func_ptr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_reg_evt_hdlr(mmi_camco_evt_hdlr hdlr_func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_camco_osd_cntx.evt_hdlr = hdlr_func_ptr;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_round
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_camco_round(double input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 dig;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dig = (int)input;

    if ((input - (double)dig) >= 0.5)
        dig += 1;
    return dig;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_setting_menu_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enter        [IN]        
 *  idx             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_touch_slider_normalize(S32 *y, S32 s, S32 e, S32 range)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((*y) < s && (*y) > s - range)
    {
        (*y) = s + 1;
    }
    else if((*y) > e && (*y) < e + range)
    {
        (*y) = e - 1;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rotate_270_coordinate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_x     [OUT]       
 *  p_y     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rotate_270_coordinate(S16 *p_x, S16 *p_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 org_x = *p_x;
    S16 org_y = *p_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *p_y = LCD_WIDTH - org_x - 1;
    *p_x = org_y;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_rotate_90
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pDst            [IN]        
 *  pSrc            [IN]        
 *  src_width       [IN]        
 *  src_height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_rotate_90(U8 *pDst, U8 *pSrc, U32 const src_width, U32 const src_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < src_height; i++)
    {
        for (j = 0; j < src_width; j++)
        {
            *(pDst + (j * src_height * 2) + ((src_height - i - 1) * 2)) = *(pSrc++);
            *(pDst + (j * src_height * 2) + ((src_height - i - 1) * 2 + 1)) = *(pSrc++);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rotate_for_hw_rotate
 * DESCRIPTION
 *  Rotate OSD if we have HW rotator in IDP or LCD
 *  (only supported when src/dst are same size but only 90 degree rotated)
 * PARAMETERS
 *  src_handle      [IN]        Srource layer handle
 *  dst_handle      [IN]        Destination layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rotate_for_hw_rotate(gdi_handle src_handle, gdi_handle dst_handle)
{
#ifdef GDI_USING_2D_ENGINE_V3
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_2d_begin();
    gdi_2d_set_layer_as_dest_buffer(dst_handle);
    gdi_2d_set_layer_as_src_bitblt_buffer(src_handle);
    gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
    gdi_2d_end();

#elif defined(MMI_CAMCO_FEATURE_ROTATE_ON)
        mdi_util_rotate_osd_for_hw_rotator(src_handle, dst_handle);
#else 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;
    S32 src_width, src_height;
    U8 *dst_p, *src_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(src_handle);
    gdi_layer_get_dimension(&src_width, &src_height);
    gdi_layer_get_buffer_ptr(&src_p);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(dst_handle);
    gdi_layer_get_buffer_ptr(&dst_p);
    gdi_layer_pop_and_restore_active();

    for (i = 0; i < src_height; i++)
    {
        for (j = 0; j < src_width; j++)
        {
            *(dst_p + (j * src_height * 2) + ((src_height - i - 1) * 2)) = *(src_p++);
            *(dst_p + (j * src_height * 2) + ((src_height - i - 1) * 2 + 1)) = *(src_p++);
        }
    }

#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_dummy_func
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_dummy_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty function */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_set_mainlist_type(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);
    mmi_camco_osd_p->iconlist.highlighted_idx = 0;
    mmi_camco_osd_p->add_frame.is_picked = FALSE;
#ifdef DUAL_CAMERA_SUPPORT
    if (mmi_camco_is_switching_maincamera())
    {
        mmi_camco_osd_p->add_frame.subcam_highlighted_idx = mmi_camco_osd_p->add_frame.highlighted_idx;
        mmi_camco_osd_p->add_frame.highlighted_idx = mmi_camco_osd_p->add_frame.maincam_highlighted_idx;
    }
    else if (mmi_camco_is_switching_subcamera())
    {
        mmi_camco_osd_p->add_frame.maincam_highlighted_idx = mmi_camco_osd_p->add_frame.highlighted_idx;
        mmi_camco_osd_p->add_frame.highlighted_idx = mmi_camco_osd_p->add_frame.subcam_highlighted_idx;
    }
    else
#endif /* DUAL_CAMERA_SUPPORT */ 
    {
        mmi_camco_osd_p->add_frame.highlighted_idx = 0;
        mmi_camco_osd_p->add_frame.maincam_highlighted_idx = 0;
        mmi_camco_osd_p->add_frame.subcam_highlighted_idx = 0;
    }

    mmi_camco_setting_set_default();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_is_horz_UI())
    {
        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
        {
            gdi_layer_blt(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->video_recoding_osd.osd_layer_ev_zoom_area_h,
                mmi_camco_osd_p->video_recoding_osd.osd_layer_rec_time_area_h,
                mmi_camco_osd_p->video_recoding_osd.osd_layer_softkey_area_h,
                0,
                0,
                LCD_WIDTH - 1,
                LCD_HEIGHT - 1);
        }
        else
        {
            gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
        }
    }
    else
    {
        gdi_layer_blt_previous(0, 0, mmi_camco_osd_p->osd_width - 1, mmi_camco_osd_p->osd_height - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_setting_menulist_interrupt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_interrupt        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_setting_menulist_interrupt(MMI_BOOL is_interrupt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->setting_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menulist_p->is_interrupt = is_interrupt;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_setting_menulist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_setting_menulist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained;
    S32 str_width;
    S32 str_height;
    U16 i;
    mmi_camco_osd_menulist_struct *menulist_p;
    U16 prev_item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    mmi_camco_osd_p->act_menulist_p = &mmi_camco_osd_p->setting_menulist;
    menulist_p = mmi_camco_osd_p->act_menulist_p;

    /* shall gen setting item list first, otherwise will have no data */

    if (menulist_p->is_interrupt)
    {
        prev_item_count = menulist_p->item_count;
    }

    menulist_p->item_count = mmi_camco_setting_get_itemlist_count();
    menulist_p->state = MMI_CAMCO_OSD_MENULIST_STATE_EXIT;

    if (mmi_camco_setting_get_mainlist_type() == MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
    {
        menulist_p->hilite_img_id = IMG_ID_CAMCO_MENUITEM_HL_MAIN;
    }
    else
    {
        menulist_p->hilite_img_id = IMG_ID_CAMCO_MENUITEM_HL_MISC;
    }

    /* get title str */
    mmi_camco_setting_get_cur_main_title(&menulist_p->title_str_id);
    gui_measure_string((UI_string_type) GetString(menulist_p->title_str_id), &str_width, &str_height);

    menulist_p->active_idx = mmi_camco_setting_get_itemlist_idx();

    if (!menulist_p->is_interrupt)
    {
        menulist_p->highlighted_idx = mmi_camco_setting_get_itemlist_idx();
        if (menulist_p->max_disp_item_count >= menulist_p->item_count)
        {
            /* menu item count did not excced display limit */
            menulist_p->disp_item_count = menulist_p->item_count;
            menulist_p->first_disp_idx = 0;
        }
        else
        {
            menulist_p->disp_item_count = menulist_p->max_disp_item_count;

            remained = menulist_p->item_count - menulist_p->highlighted_idx;

            if (remained < menulist_p->disp_item_count)
            {
                menulist_p->first_disp_idx = menulist_p->item_count - menulist_p->disp_item_count;

                if (menulist_p->first_disp_idx < 0)
                {
                    menulist_p->first_disp_idx = 0;
                }
            }
            else
            {
                menulist_p->first_disp_idx = menulist_p->highlighted_idx;
            }
        }

    }
    else
    {
        menulist_p->is_interrupt = MMI_FALSE;

        if (menulist_p->item_count != prev_item_count)
        {
            if (prev_item_count > menulist_p->item_count)
            {
                if (menulist_p->highlighted_idx > menulist_p->item_count - 1)
                {
                    menulist_p->highlighted_idx = mmi_camco_setting_get_itemlist_idx();
                }
            }

            if (menulist_p->max_disp_item_count >= menulist_p->item_count)
            {
                /* menu item count did not excced display limit */
                menulist_p->disp_item_count = menulist_p->item_count;
                menulist_p->first_disp_idx = 0;
            }
            else
            {
                menulist_p->disp_item_count = menulist_p->max_disp_item_count;

                remained = menulist_p->item_count - menulist_p->highlighted_idx;

                if (remained < menulist_p->disp_item_count)
                {
                    menulist_p->first_disp_idx = menulist_p->item_count - menulist_p->disp_item_count;

                    if (menulist_p->first_disp_idx < 0)
                    {
                        menulist_p->first_disp_idx = 0;
                    }
                }
                else
                {
                    menulist_p->first_disp_idx = menulist_p->highlighted_idx;
                }
            }
        }
        
        /* no need do that because the menu will back to level 1 in FTE*/
    #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    }
    /* get all item data (img, str) */
    for (i = 0; i < menulist_p->item_count; i++)
    {
        mmi_camco_setting_get_item_resource(
            mmi_camco_setting_get_itemlist_value(i),
            &menulist_p->item_list[i].str_id,
            &menulist_p->item_list[i].status_img_id);

        if (mmi_camco_setting_is_main_show_radio())
        {
            if (i == menulist_p->active_idx)
            {
                menulist_p->item_list[i].radio_img_id = IMG_ID_CAMCO_RADIO_FULL;
            }
            else
            {
                menulist_p->item_list[i].radio_img_id = IMG_ID_CAMCO_RADIO_EMPTY;
            }
        }
        else
        {
            menulist_p->item_list[i].radio_img_id = 0;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_menulist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->highlighted_idx < menulist_p->item_count - 1)
    {
        menulist_p->highlighted_idx++;

        if (menulist_p->highlighted_idx < menulist_p->first_disp_idx + menulist_p->disp_item_count)
        {
            /* within same page, do nothing */
        }
        else
        {
            menulist_p->first_disp_idx++;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_menulist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->highlighted_idx > 0)
    {
        menulist_p->highlighted_idx--;

        if (menulist_p->highlighted_idx >= menulist_p->first_disp_idx)
        {
            /* within same page, do nothing */
        }
        else
        {
            menulist_p->first_disp_idx--;

        }

        return MMI_TRUE;

    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_menulist_idx_from_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_x       [IN]        
 *  pos_y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_camco_osd_get_menulist_idx_from_pos(S32 pos_x, S32 pos_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 menu_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->setting_menulist.item_count < mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count)
        menu_num = mmi_camco_osd_p->setting_menulist.item_count;
    else
        menu_num = mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count;

    for (i = 0; i < menu_num; i++)
    {
        if (mmi_camco_osd_touch_hit_test
            (pos_x, (pos_y - mmi_camco_osd_p->advance_setting_screen.menu_pos_y_shift),
             &mmi_camco_osd_p->advance_setting_screen.Level2_setting_wnd_item[i]))
        {
            return i;
        }
    }
    return -1;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_iconlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_iconlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained;
    U16 i;

    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall gen setting item list first, otherwise will have no data */

    iconlist_p->icon_count = mmi_camco_setting_get_mainlist_count();
    iconlist_p->state = MMI_CAMCO_OSD_ICONLIST_STATE_EXIT;
    iconlist_p->highlighted_idx = mmi_camco_setting_get_mainlist_idx();

    remained = iconlist_p->icon_count - iconlist_p->highlighted_idx;

    if (remained < iconlist_p->disp_icon_count)
    {
        iconlist_p->first_disp_idx = iconlist_p->icon_count - iconlist_p->disp_icon_count;

        if (iconlist_p->first_disp_idx < 0)
        {
            iconlist_p->first_disp_idx = 0;
        }
    }
    else
    {
        iconlist_p->first_disp_idx = iconlist_p->highlighted_idx;
    }

    /* get all item data (img, str) */
    for (i = 0; i < iconlist_p->icon_count; i++)
    {
        mmi_camco_setting_get_main_resource(
            i,
            &iconlist_p->icon_list[i].str_id,
            &iconlist_p->icon_list[i].img_id,
            &iconlist_p->icon_list_cur_value[i],
            &iconlist_p->icon_list_cur_value_img[i]);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_update_iconlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_update_iconlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained;
    U16 i;

    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall gen setting item list first, otherwise will have no data */

    iconlist_p->icon_count = mmi_camco_setting_get_mainlist_count();

    /* get all item data (img, str) */
    for (i = 0; i < iconlist_p->icon_count; i++)
    {
        mmi_camco_setting_get_main_resource(
            i,
            &iconlist_p->icon_list[i].str_id,
            &iconlist_p->icon_list[i].img_id,
            &iconlist_p->icon_list_cur_value[i],
            &iconlist_p->icon_list_cur_value_img[i]);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_iconlist_highlight_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_iconlist_highlight_idx(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->iconlist.highlighted_idx = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_iconlist_highlight_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  index               [OUT]
 *****************************************************************************/
U16 mmi_camco_osd_get_iconlist_highlight_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->iconlist.highlighted_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_iconlist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iconlist_p->highlighted_idx < iconlist_p->icon_count - 1)
    {
        iconlist_p->highlighted_idx++;

        if (iconlist_p->highlighted_idx < iconlist_p->first_disp_idx + iconlist_p->disp_icon_count)
        {
            /* within same page, do nothing */
        }
        else
        {
            iconlist_p->first_disp_idx++;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_iconlist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iconlist_p->highlighted_idx > 0)
    {
        iconlist_p->highlighted_idx--;

        if (iconlist_p->highlighted_idx >= iconlist_p->first_disp_idx)
        {
            /* within same page, do nothing */
        }
        else
        {
            iconlist_p->first_disp_idx--;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_imgselect_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_cache_p->highlighted_idx < imgselect_cache_p->img_count - 1)
    {
        imgselect_cache_p->highlighted_idx++;

        if (imgselect_cache_p->highlighted_idx <
            imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count)
        {
            /* within same page, do nothing */
        }
        else
        {
            imgselect_cache_p->first_disp_idx++;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_imgselect_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_cache_p->highlighted_idx > 0)
    {
        imgselect_cache_p->highlighted_idx--;

        if (imgselect_cache_p->highlighted_idx >= imgselect_cache_p->first_disp_idx)
        {
            /* within same page, do nothing */
        }
        else
        {
            imgselect_cache_p->first_disp_idx--;
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_add_frame_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_frame_p->highlighted_idx < add_frame_p->frame_count - 1)
    {
        add_frame_p->highlighted_idx++;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_add_frame_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_frame_p->highlighted_idx > 0)
    {
        add_frame_p->highlighted_idx--;
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_iconlist_idx_from_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_x       [IN]        
 *  pos_y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_camco_osd_get_iconlist_idx_from_pos(S32 pos_x, S32 pos_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U8 icon_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->iconlist.icon_count < mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count)
        icon_num = mmi_camco_osd_p->iconlist.icon_count;
    else
        icon_num = mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count;

    for (i = 0; i < icon_num; i++)
    {
        if (mmi_camco_osd_touch_hit_test
            (pos_x, pos_y, &mmi_camco_osd_p->advance_setting_screen.Level1_setting_wnd_item[i]))
        {
            return i;
        }
    }
    return -1;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_camera_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_camera_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    MMI_ID_TYPE img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->status_icon, 0, sizeof(mmi_camco_osd_p->status_icon));

    /* get setting values */
#define CAMCO_OSD_GEN_CAMERA_STATUS_ICON(__X__,__x__)                                                         \
    img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                                 \
    if (img_id != 0)                                                                                          \
    {                                                                                                         \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                    \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                            \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_x;                                        \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                            \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_y;                                        \
        idx++;                                                                                                \
    }

#define CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(__X__,__x__)                                                 \
    img_id = 0;                                                                                                \
    if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_##__X__##) == MMI_CAMCO_SETTING_CAP_ENABLED)\
    {                                                                                                          \
        img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                              \
    }                                                                                                          \
    if (img_id != 0)                                                                                           \
    {                                                                                                          \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                     \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                             \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_x;                                         \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                             \
            = mmi_camco_osd_skin_p->camera_preview.##__x__##.offset_y;                                         \
        idx++;                                                                                                 \
    }

    CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(CAPMODE, capmode);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(CAMSCENEMODE, camscenemode);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(CAPSIZE, capsize);

    if (mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_LED &&
        mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_EV_BRACKET_SEL &&
        mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) != MMI_CAMCO_CAPMODE_PANORAMA)
    {
        CAMCO_OSD_GEN_CAMERA_STATUS_ICON(FLASH, flash);
    }
    else if (mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_XENON &&
             (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_NORMAL ||
        #ifdef __SMILE_SHUTTER_SUPPORT__    
             mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_SMILE_SHOT||
        #endif             
             mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_ADD_FRAME)
            )
    {
        CAMCO_OSD_GEN_CAMERA_STATUS_ICON(FLASH, flash);
    }

    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(AFRANGE, afrange);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(ISO, iso);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(WB, wb);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(STORAGE, storage);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(CAPQTY, capqty);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(AEMETER, aemeter);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(TIMESTAMP, timestamp);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON_WITH_CAP(SELFTIMER, selftimer);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(FACEDETECT, facedetect);
    CAMCO_OSD_GEN_CAMERA_STATUS_ICON(HIGHLIGHT, highlight);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_video_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_video_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx = 0;
    MMI_ID_TYPE img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->status_icon, 0, sizeof(mmi_camco_osd_p->status_icon));

    /* get setting values */
#define CAMCO_OSD_GEN_VIDEO_STATUS_ICON(__X__,__x__)                                                          \
    img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                                 \
    if (img_id != 0)                                                                                          \
    {                                                                                                         \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                    \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                            \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_x;                                         \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                            \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_y;                                         \
        idx++;                                                                                                \
    }

#define CAMCO_OSD_GEN_VIDEO_STATUS_ICON_WITH_CAP(__X__,__x__)                                                  \
    img_id = 0;                                                                                                \
    if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_##__X__##) == MMI_CAMCO_SETTING_CAP_ENABLED)\
    {                                                                                                          \
        img_id = mmi_camco_setting_get_setting_icon(MMI_CAMCO_SETTING_##__X__##);                              \
    }                                                                                                          \
    if (img_id != 0)                                                                                           \
    {                                                                                                          \
        mmi_camco_osd_p->status_icon[idx].img_id = img_id;                                                     \
        mmi_camco_osd_p->status_icon[idx].offset_x                                                             \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_x;                                          \
        mmi_camco_osd_p->status_icon[idx].offset_y                                                             \
            = mmi_camco_osd_skin_p->video_preview.##__x__##.offset_y;                                          \
        idx++;                                                                                                 \
    }

    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(VDOSCENEMODE, vdoscenemode);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(RECSIZE, recsize);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON_WITH_CAP(AFRANGE, afrange);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(WB, wb);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(LIMIT, limit);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(STORAGE, storage);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(VISQTY, visqty);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(AFMODE, afmode);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(RECAUD, recaud);
    CAMCO_OSD_GEN_VIDEO_STATUS_ICON(HIGHLIGHT, highlight);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_OSD_MAX_STATUS_ICON_COUNT; i++)
    {
        if (mmi_camco_osd_p->status_icon[i].img_id != 0)
        {
            gdi_image_draw_id(
                mmi_camco_osd_p->status_icon[i].offset_x,
                mmi_camco_osd_p->status_icon[i].offset_y,
                mmi_camco_osd_p->status_icon[i].img_id);
        }
    }
}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_draw_reduce_video_slider
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_draw_reduce_video_slider(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            mmi_camco_osd_rec_screen_struct *scr_p = &mmi_camco_osd_p->recording_screen;
            U16 curr_value;
            U16 ind_center_pos_y, ind_center_pos_x;
            U16 re_offset_x = mmi_camco_osd_p->video_recoding_osd.rotate_ev_zoom_area.x1;
            U16 re_offset_y = mmi_camco_osd_p->video_recoding_osd.rotate_ev_zoom_area.y1;

            gdi_image_draw_id(
                scr_p->slider_zoom_top.offset_x - re_offset_x,
                scr_p->slider_zoom_top.offset_y - re_offset_y,
                scr_p->slider_zoom_top.img_id);
            gdi_image_draw_id(
                scr_p->slider_bar.offset_x - re_offset_x,
                scr_p->slider_bar.offset_y - re_offset_y,
                scr_p->slider_bar.img_id);
            gdi_image_draw_id(
                scr_p->slider_zoom_botton.offset_x - re_offset_x,
                scr_p->slider_zoom_botton.offset_y - re_offset_y,
                scr_p->slider_zoom_botton.img_id);

            curr_value = mmi_camco_setting_get_vdozoom_step();

            if (mmi_camco_osd_is_horz_UI())
            {
                ind_center_pos_y =
                    (1.0 - (((curr_value - mmi_camco_osd_p->rec_slider.min_value) * (1.0)) / (mmi_camco_osd_p->rec_slider.step_count - 1))) *
                    scr_p->slider_region.height;

                scr_p->slider_location.offset_y = (ind_center_pos_y - (scr_p->slider_location.height >> 1) + scr_p->slider_region.offset_y - re_offset_y);
                scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;

                gdi_layer_set_clip(
                    scr_p->slider_bar.offset_x - re_offset_x,
                    scr_p->slider_location.offset_y + (scr_p->slider_location.height >> 1) - re_offset_y,
                    scr_p->slider_bar.offset_x + scr_p->slider_bar.width - re_offset_x,
                    scr_p->slider_bar.offset_y + scr_p->slider_bar.height - re_offset_y);

                gdi_image_draw_id(
                    scr_p->slider_bar.offset_x - re_offset_x ,
                    scr_p->slider_bar.offset_y - re_offset_y,
                    scr_p->slider_bar.img_id + 1);

                gdi_layer_reset_clip();
                
                gdi_image_draw_id(
                    scr_p->slider_location.offset_x - re_offset_x,
                    scr_p->slider_location.offset_y - re_offset_y,
                    scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));
            }
            else
            {
                ind_center_pos_x =
                    ((((curr_value - mmi_camco_osd_p->rec_slider.min_value) * (1.0)) / (mmi_camco_osd_p->rec_slider.step_count - 1))) *
                    scr_p->slider_region.width;

                scr_p->slider_location.offset_x = (ind_center_pos_x - (scr_p->slider_location.width>> 1) + scr_p->slider_region.offset_x - re_offset_x);
                scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;

                gdi_layer_set_clip(     
                    scr_p->slider_bar.offset_x - re_offset_x,
                    scr_p->slider_bar.offset_y - re_offset_y,
                    scr_p->slider_location.offset_x + (scr_p->slider_location.width>> 1) - re_offset_x,
                    scr_p->slider_bar.offset_y+ scr_p->slider_bar.height - re_offset_y);

                gdi_image_draw_id(
                    scr_p->slider_bar.offset_x - re_offset_x ,
                    scr_p->slider_bar.offset_y - re_offset_y,
                    scr_p->slider_bar.img_id + 1);

                gdi_layer_reset_clip();
                
                gdi_image_draw_id(
                    scr_p->slider_location.offset_x - re_offset_x,
                    scr_p->slider_location.offset_y - re_offset_y,
                    scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));
            }                        
            break;
        }
    }

}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_draw_video_slider
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_draw_video_slider(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            mmi_camco_osd_rec_screen_struct *scr_p = &mmi_camco_osd_p->recording_screen;
            U16 curr_value;
            U16 ind_center_pos_y, ind_center_pos_x;

            if (mmi_camco_osd_is_horz_UI())
            {

                gdi_image_draw_id(
                    scr_p->slider_zoom_top.offset_x,
                    scr_p->slider_zoom_top.offset_y,
                    scr_p->slider_zoom_top.img_id);
                gdi_image_draw_id(scr_p->slider_bar.offset_x, scr_p->slider_bar.offset_y, scr_p->slider_bar.img_id);
                gdi_image_draw_id(
                    scr_p->slider_zoom_botton.offset_x,
                    scr_p->slider_zoom_botton.offset_y,
                    scr_p->slider_zoom_botton.img_id);

                curr_value = mmi_camco_setting_get_vdozoom_step();


                ind_center_pos_y =
                    (1.0 - (((curr_value - mmi_camco_osd_p->rec_slider.min_value) * (1.0)) / (mmi_camco_osd_p->rec_slider.step_count - 1))) *
                    scr_p->slider_region.height;
                
                scr_p->slider_location.offset_y = (ind_center_pos_y - (scr_p->slider_location.height >> 1) + scr_p->slider_region.offset_y);
                scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;
                
                gdi_layer_set_clip(
                    scr_p->slider_bar.offset_x,
                    scr_p->slider_location.offset_y + (scr_p->slider_location.height >> 1),
                    scr_p->slider_bar.offset_x + scr_p->slider_bar.width,
                    scr_p->slider_bar.offset_y + scr_p->slider_bar.height);

                gdi_image_draw_id(
                    scr_p->slider_bar.offset_x ,
                    scr_p->slider_bar.offset_y,
                    scr_p->slider_bar.img_id + 1);

                gdi_layer_reset_clip();            
                
                gdi_image_draw_id(
                     scr_p->slider_location.offset_x,
                     scr_p->slider_location.offset_y,
                     scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));
            }
            else
            {

                gdi_image_draw_id(
                    scr_p->slider_zoom_top.offset_x,
                    scr_p->slider_zoom_top.offset_y,
                    scr_p->slider_zoom_botton.img_id);
                
                gdi_image_draw_id(scr_p->slider_bar.offset_x, scr_p->slider_bar.offset_y, scr_p->slider_bar.img_id);

                gdi_image_draw_id(
                    scr_p->slider_zoom_botton.offset_x,
                    scr_p->slider_zoom_botton.offset_y,
                    scr_p->slider_zoom_top.img_id);

                curr_value = mmi_camco_setting_get_vdozoom_step();
                
                ind_center_pos_x =
                    ((((curr_value - mmi_camco_osd_p->rec_slider.min_value) * (1.0)) / (mmi_camco_osd_p->rec_slider.step_count - 1))) *
                    scr_p->slider_region.width;
                
                scr_p->slider_location.offset_x = (ind_center_pos_x - (scr_p->slider_location.width>> 1) + scr_p->slider_region.offset_x);
                scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;
                
                gdi_layer_set_clip(
                    scr_p->slider_bar.offset_x,
                    scr_p->slider_bar.offset_y,
                    scr_p->slider_location.offset_x + (scr_p->slider_location.width>> 1),                    
                    scr_p->slider_bar.offset_y + scr_p->slider_bar.height);

                gdi_image_draw_id(
                    scr_p->slider_bar.offset_x ,
                    scr_p->slider_bar.offset_y,
                    scr_p->slider_bar.img_id + 1);

                gdi_layer_reset_clip();            
                
                gdi_image_draw_id(
                     scr_p->slider_location.offset_x,
                     scr_p->slider_location.offset_y,
                     scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));
            
            }
            break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_right_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_right_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }
    
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
                if (mmi_camco_osd_p->current_dir_setting_object != MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM)
                {
                    mmi_camco_osd_menulist_struct* p = &(mmi_camco_osd_p->setting_menulist);
                    
                    p->highlighted_idx = (p->highlighted_idx + 1)%(p->item_count);
                    
                    mmi_camco_osd_draw_osd();                     
                }
            }
            else
            {
                mmi_camco_setting_mainlist_type_enum type;
                U16 count;

                type = mmi_camco_setting_get_mainlist_type();

                if (type != MMI_CAMCO_SETTING_MAINLIST_SECONDARY)
                {
                    mmi_camco_setting_restore_hilite_mod();
                    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_SECONDARY);
                    count = mmi_camco_setting_get_mainlist_count();
                    MMI_ASSERT(count != 0);

                    mmi_camco_setting_set_mainlist_idx(0);

                    mmi_camco_osd_gen_iconlist();
                    mmi_camco_osd_gen_setting_menulist();

                    mmi_camco_osd_draw_osd();           
                }
            }
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {

            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            add_frame_p->ra_touch.is_press = MMI_TRUE;
            mmi_camco_osd_add_frame_next_cyclic();

            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_imgselect_next_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_right_press();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            mmi_camco_osd_menulist_struct *p = &(mmi_camco_osd_p->option_menulist);
            p->highlighted_idx = (p->highlighted_idx + 1) %(p->item_count);  
            mmi_camco_osd_draw_osd();                      
            break;
        }    
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_right_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_right_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }
    
    
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            if (!add_frame_p->ra_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
            add_frame_p->ra_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {            
            gui_cancel_timer(mmi_camco_osd_imgselect_next_cyclic);
            mmi_camco_updata_key_handler();
            mmi_camco_osd_draw_osd();

            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_right_release();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:  
        {
            break;              
        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            break;
        }           
        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_left_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_left_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }   
    
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:  
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
                if (mmi_camco_osd_p->current_dir_setting_object != MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM)
                {            
                    mmi_camco_osd_menulist_struct* p = &(mmi_camco_osd_p->setting_menulist);
                    
                    p->highlighted_idx = (p->highlighted_idx + p->item_count -1)%(p->item_count);
                    
                    mmi_camco_osd_draw_osd();            
                }
            }
            else
            {
                mmi_camco_setting_mainlist_type_enum type;
                U16 count;

                type = mmi_camco_setting_get_mainlist_type();

                if (type != MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
                {
                    mmi_camco_setting_restore_hilite_mod();
                    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);
                    count = mmi_camco_setting_get_mainlist_count();
                    MMI_ASSERT(count != 0);

                    mmi_camco_setting_set_mainlist_idx(0);

                    mmi_camco_osd_gen_iconlist();
                    mmi_camco_osd_gen_setting_menulist();

                    mmi_camco_osd_draw_osd();
                }
            }      
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            add_frame_p->la_touch.is_press = MMI_TRUE;
            mmi_camco_osd_add_frame_prev_cyclic();
               
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
      

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_imgselect_prev_cyclic();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_left_press();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            mmi_camco_osd_menulist_struct *p = &(mmi_camco_osd_p->option_menulist);
            p->highlighted_idx = (p->highlighted_idx + p->item_count - 1) %(p->item_count);            
            mmi_camco_osd_draw_osd();                      
            break;
        }   
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }
        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_left_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_left_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }
    
    
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {            
            mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

            if (!add_frame_p->la_touch.is_press)
            {
                /* not pressed, return */
                return;
            }

            gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
            add_frame_p->la_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            gui_cancel_timer(mmi_camco_osd_imgselect_prev_cyclic);
            mmi_camco_updata_key_handler();
            mmi_camco_osd_draw_osd();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_left_release();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:  
        {
            break;              
        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            break;
        }        
        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_up_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_up_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }
        
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
                mmi_camco_osd_menulist_struct* p = &(mmi_camco_osd_p->setting_menulist);
                if(p->highlighted_idx >= (p->item_count % MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT) )
                {
                    p->highlighted_idx = (p->highlighted_idx + p->item_count -MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT)%(p->item_count);
                }
                else
                {
                    p->highlighted_idx = (p->highlighted_idx + p->item_count - (p->item_count % MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT))%(p->item_count);
                }
                mmi_camco_osd_draw_osd();                      
                
            }
            else
            {            
                if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
                {
                    mmi_camco_osd_iconlist_prev_cyclic();            
                }
                else if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
                {
                    mmi_camco_osd_menulist_prev_cyclic();
                }
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_up_press();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 
        default:
            MMI_ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_up_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_up_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }
        
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
            }
            else
            {            
                if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
                {
                    gui_cancel_timer(mmi_camco_osd_iconlist_prev_cyclic);          
                }
                else if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
                {
                    gui_cancel_timer(mmi_camco_osd_menulist_prev_cyclic);
                }
            }
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_up_release();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_down_arrow_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_down_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }
        
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING: 
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
      
                mmi_camco_osd_menulist_struct* p = &(mmi_camco_osd_p->setting_menulist);

                if(p->highlighted_idx >= (p->item_count - MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT))
                {
                    if((p->item_count %MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT) != 0)
                    {
                        p->highlighted_idx = (p->highlighted_idx + (p->item_count %MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT))%(p->item_count);
                    }
                    else
                    {
                        p->highlighted_idx = (p->highlighted_idx + (MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT))%(p->item_count);                    
                    }
                }
                else
                {
                    p->highlighted_idx = (p->highlighted_idx + MMI_CAMCO_OSD_MAX_DIRECT_SETTING_LINE_COUNT)%(p->item_count);
                }
                                                   
                mmi_camco_osd_draw_osd();                      

            }
            else
            {            
                if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
                {
                    mmi_camco_osd_iconlist_next_cyclic();            
                }
                else if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
                {
                    mmi_camco_osd_menulist_next_cyclic();
                }
            }                
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_down_press();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_down_arrow_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_down_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }
        
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* Do nothing */
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING: 
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
            }
            else
            {            
                if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
                {
                    gui_cancel_timer(mmi_camco_osd_iconlist_next_cyclic);      
                }
                else if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
                {
                    gui_cancel_timer(mmi_camco_osd_menulist_next_cyclic);
                }
            }
            break;
        }


    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_direct_down_release();
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_option_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title_str_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_option_title(MMI_ID_TYPE title_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    U8 i;
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menulist_p->item_count = 0;
    menulist_p->state = MMI_CAMCO_OSD_MENULIST_STATE_EXIT;

    /* get title str */
    menulist_p->title_str_id = title_str_id;

    gui_measure_string((UI_string_type) GetString(menulist_p->title_str_id), &str_width, &str_height);

    mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.tool_bar[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.tool_bar[2].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.tool_bar[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.item[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.item[2].is_usable = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.item[2].is_usable = MMI_FALSE;
    for(i = 0; i< SRV_FMGR_DRV_TOTAL; i++)
    {
        mmi_camco_osd_p->storage_select_screen.item[i].is_usable = MMI_FALSE;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_insert_option_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_id         [IN]        
 *  item_str_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_insert_option_item(U32 item_id, MMI_ID_TYPE item_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {

        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            if (item_id == MMI_CAMCO_CAM_OPTION_DELETE)
            {
                mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_TRUE;
            }
            else if (item_id == MMI_CAMCO_CAM_OPTION_FORWARD)
            {
                mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_TRUE;
            }
        #ifdef __MMI_PHOTOEDITOR__
            else if (item_id == MMI_CAMCO_CAM_OPTION_PHOTOEDITOR)
            {
                mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_TRUE;
            }
        #endif /* __MMI_PHOTOEDITOR__ */ 
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            if (item_id == MMI_CAMCO_CAM_OPTION_DELETE || item_id == MMI_CAMCO_REC_OPTION_DELETE)
            {
                mmi_camco_osd_p->captured_screen.tool_bar[1].is_usable = MMI_TRUE;
            }
            else if (item_id == MMI_CAMCO_CAM_OPTION_FORWARD || item_id == MMI_CAMCO_REC_OPTION_FORWARD)
            {
                mmi_camco_osd_p->captured_screen.tool_bar[2].is_usable = MMI_TRUE;
            }
        #ifdef __MMI_PHOTOEDITOR__
            else if (item_id == MMI_CAMCO_CAM_OPTION_PHOTOEDITOR)
            {
                mmi_camco_osd_p->captured_screen.tool_bar[0].is_usable = MMI_TRUE;
            }
        #endif /* __MMI_PHOTOEDITOR__ */ 
        #if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)
            else if (item_id == MMI_CAMCO_REC_OPTION_PLAY)
            {
                mmi_camco_osd_p->captured_screen.tool_bar[0].is_usable = MMI_TRUE;
            }
        #endif /* __MMI_VIDEO_PLAYER__ */ 

            break;
        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
        #ifdef __MMI_BT_SEND_SUPPORT__
            if (item_id == MENU_ID_FMGR_FWD_BT)
        #else
            if (0)
        #endif
            {
                mmi_camco_osd_p->fw_option_idx_lookup_table[0] = menulist_p->item_count;
                mmi_camco_osd_p->forward_screen.item[0].is_usable = MMI_TRUE;
            }
        #ifdef __MMI_MMS_2__    
            else if (item_id == MENU_ID_FMGR_FWD_MMS)
            {
                mmi_camco_osd_p->fw_option_idx_lookup_table[1] = menulist_p->item_count;
                mmi_camco_osd_p->forward_screen.item[1].is_usable = MMI_TRUE;
            }
        #endif
            else if (item_id == MENU_ID_FMGR_FWD_EMAIL)
            {
                mmi_camco_osd_p->fw_option_idx_lookup_table[2] = menulist_p->item_count;
                mmi_camco_osd_p->forward_screen.item[2].is_usable = MMI_TRUE;
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:            
        {
            mmi_camco_osd_p->storage_select_screen.item[item_id].is_usable = MMI_TRUE;
            break;
        }    
    }
    menulist_p->item_list[menulist_p->item_count].item_id = item_id;
    menulist_p->item_list[menulist_p->item_count].str_id = item_str_id;
    menulist_p->item_list[menulist_p->item_count].radio_img_id = 0;
    menulist_p->item_list[menulist_p->item_count].status_img_id = 0;
    menulist_p->item_count++;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_insert_option_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_insert_option_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (menulist_p->item_count > menulist_p->max_disp_item_count)
    {
        menulist_p->disp_item_count = menulist_p->max_disp_item_count;
    }
    else
    {
        menulist_p->disp_item_count = menulist_p->item_count;
    }

    if (mmi_camco_osd_p->forward_screen.item[0].is_usable)
        menulist_p->highlighted_idx = mmi_camco_osd_p->fw_option_idx_lookup_table[0];
    else if (mmi_camco_osd_p->forward_screen.item[1].is_usable)
        menulist_p->highlighted_idx = mmi_camco_osd_p->fw_option_idx_lookup_table[1];
    else
        menulist_p->highlighted_idx = mmi_camco_osd_p->fw_option_idx_lookup_table[2];

    if (r2lMMIFlag)
    {

    #ifdef HORIZONTAL_CAMERA
        if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
        {
            menulist_p->max_disp_item_count = 4;
        }
    #endif /* HORIZONTAL_CAMERA */ 
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_option_hilite_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_camco_osd_get_option_hilite_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->option_menulist.highlighted_idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_option_item_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  highlight_idx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_camco_osd_get_option_item_id(S32 highlight_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->option_menulist.item_list[highlight_idx].item_id;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_hilite_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_camco_osd_get_imgselect_hilite_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->imgselect_cache.highlighted_idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_option_hilite_idx
 * DESCRIPTION
 *  dummy in FTE project
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_option_hilite_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_fw_hilite_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_fw_hilite_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 remained;
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menulist_p->highlighted_idx = idx;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_option_menulist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_option_menulist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = &mmi_camco_osd_p->option_menulist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->act_menulist_p = &mmi_camco_osd_p->option_menulist;
    menulist_p = mmi_camco_osd_p->act_menulist_p;

    memset(menulist_p->item_list, 0, sizeof(menulist_p->item_list));

    menulist_p->item_count = 0;
    menulist_p->state = MMI_CAMCO_OSD_MENULIST_STATE_EXIT;
    menulist_p->hilite_img_id = IMG_ID_CAMCO_MENUITEM_HL_MAIN;
    menulist_p->active_idx = 0;
    menulist_p->item_count = 0;
    menulist_p->first_disp_idx = 0;
    menulist_p->disp_item_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_video_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_video_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &progress_p->num_img_width, &progress_p->num_img_height);
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_COLON, &progress_p->col_img_width, &progress_p->col_img_height);

    progress_p->dot_offset_x = mmi_camco_osd_skin_p->video_record.record_dot.offset_x;
    progress_p->dot_offset_y = mmi_camco_osd_skin_p->video_record.record_dot.offset_y;

    progress_p->time_offset_x = progress_p->dot_offset_x + 2 * MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS +   /* 2 means one diameter is two radius */
        MMI_CAMCO_OSD_RECORD_TIME_TIMER_SHIFT;

    progress_p->time_offset_y = progress_p->dot_offset_y;

    progress_p->progress_offset_x = progress_p->time_offset_x + 2 * MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS + 6 * progress_p->num_img_width +      /* 6 means there are six numbers */
        2 * progress_p->col_img_width + /* 2 means there are two colon   */
        MMI_CAMCO_OSD_RECORD_TIME_TIMER_SHIFT;

    progress_p->progress_offset_y = progress_p->time_offset_y;

}

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_set_cache_img_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset_x            [IN]        
 *  offset_y            [IN]        
 *  resized_width       [IN]        
 *  resized_height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_imageselect_set_cache_img_info(S32 offset_x, S32 offset_y, S32 resized_width, S32 resized_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.cache_resized_offset_x = offset_x;
    mmi_camco_osd_p->imgselect_cache.cache_resized_offset_y = offset_y;
    mmi_camco_osd_p->imgselect_cache.cache_resized_width = resized_width;
    mmi_camco_osd_p->imgselect_cache.cache_resized_height = resized_height;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_set_cache_layer_buf_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_imageselect_set_cache_layer_buf_p(void *buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imageselect_cache_layer_buf_p = (CHAR *) buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_imageselect_setup_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_size = 0;
    S32 cache_osd_width;
    S32 cache_osd_height;
    S32 frame_w, frame_h;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_CAM_IMG_LIST_ITEM_ICON, &frame_w, &frame_h);

    if (mmi_camco_osd_is_horz_UI())
    {
        // it is fianl rotated layer on vertical direction
        cache_osd_height = mmi_camco_osd_p->osd_width;
        cache_osd_width = frame_h + (2 * MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH);
    }
    else
    {
        cache_osd_width = mmi_camco_osd_p->osd_width;
        cache_osd_height = frame_h + (2 * MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH);
    }

    buf_size = ((cache_osd_width * cache_osd_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);

    mmi_camco_osd_p->imgselect_cache.cache_layer_width = cache_osd_width;
    mmi_camco_osd_p->imgselect_cache.cache_layer_height = cache_osd_height;

    MMI_ASSERT(mmi_camco_osd_p->imageselect_cache_layer_buf_p != NULL);

    gdi_layer_create_using_outside_memory(
        0,
        0,
        cache_osd_width,
        cache_osd_height,
        &mmi_camco_osd_p->imageselect_cache_layer_h,
        (U8*) mmi_camco_osd_p->imageselect_cache_layer_buf_p,
        buf_size);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->imageselect_cache_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    if (mmi_camco_osd_is_horz_UI())
    {
        gdi_layer_set_position(0, 0);
    }
    else
    {
        gdi_layer_set_position(mmi_camco_osd_skin_p->multiselect_cache.img_frame.offset_x, mmi_camco_osd_skin_p->multiselect_cache.img_frame.offset_y);
    }

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imageselect_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_imageselect_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->imageselect_cache_layer_h == GDI_NULL_HANDLE)
    {
        return;
    }

    if (mmi_camco_osd_p->imageselect_cache_layer_h)
    {
        gdi_layer_free(mmi_camco_osd_p->imageselect_cache_layer_h);
        mmi_camco_osd_p->imageselect_cache_layer_h = GDI_NULL_HANDLE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_imgselect_highlight_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_imgselect_highlight_idx(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_IMAGE_SELECTION)
    {
        mmi_camco_osd_p->imgselect_cache.highlighted_idx = index;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_shown_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_p               [OUT]       
 *  buf_filename_pp     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_get_imgselect_shown_size(U16 *w, U16 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    (*w) = mmi_camco_osd_p->captured_img_select_screen.image_list[0].width;
    (*h) = mmi_camco_osd_p->captured_img_select_screen.image_list[0].height;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_cur_img_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_p               [OUT]       
 *  buf_filename_pp     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_get_imgselect_cur_img_info(U16 *idx_p, CHAR **buf_filename_pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *idx_p = imgselect_cache_p->highlighted_idx;
    *buf_filename_pp = imgselect_cache_p->buf_filename[imgselect_cache_p->highlighted_idx];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_imgselect_filepath
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  buf_filename_p      [OUT]
 *****************************************************************************/
CHAR* mmi_camco_osd_get_imgselect_filepath(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return imgselect_cache_p->buf_filename[idx];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_image_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    imgselect_cache_p->cache_img_width = mmi_camco_osd_skin_p->multiselect_cache.img_w;
    imgselect_cache_p->cache_img_height = mmi_camco_osd_skin_p->multiselect_cache.img_h;

    imgselect_cache_p->is_horizontal_display = (MMI_BOOL) mmi_camco_osd_skin_p->multiselect_cache.is_horizontal_display;
    imgselect_cache_p->max_display_count = mmi_camco_osd_skin_p->multiselect_cache.display_count;
    imgselect_cache_p->disp_cache_count = 0;

    imgselect_cache_p->highlight_color = gdi_act_color_from_rgb(255, 240, 228, 15);
    imgselect_cache_p->highlight_border_color = GDI_COLOR_WHITE;

    imgselect_cache_p->is_cache_img_osd_redraw = MMI_TRUE;
    mmi_camco_osd_p->imgselect_cache.is_cache_highlight_osd_redraw = MMI_TRUE;
    mmi_camco_osd_p->imageselect_cache_layer_h = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_image_select_filename_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buff_address        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_image_select_filename_buffer(CHAR * buff_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    CHAR  i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_CAM_CACHE_IMAGE_COUNT; i++)
    {
        imgselect_cache_p->buf_filename[i] = buff_address;
        memset(imgselect_cache_p->buf_filename[i], 0, SRV_FMGR_PATH_BUFFER_SIZE);
        buff_address += SRV_FMGR_PATH_BUFFER_SIZE;
    }

    imgselect_cache_p->first_disp_idx = 0;
    imgselect_cache_p->highlighted_idx = imgselect_cache_p->first_disp_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_deinit_image_select_filename_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_deinit_image_select_filename_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->imgselect_cache.buf_filename[0] != NULL)
    {
        CHAR  i;

        for (i = 0; i < MMI_CAMCO_CAM_CACHE_IMAGE_COUNT; i++)
        {
            mmi_camco_osd_p->imgselect_cache.buf_filename[i] = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_image_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    S32 image_width = 0;
    S32 image_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_get_multiselect_img_info(
        &imgselect_cache_p->img_count,
        &imgselect_cache_p->img_p,
        &imgselect_cache_p->cache_imgdata_pp,
        &imgselect_cache_p->save_flag_p);

    imgselect_cache_p->disp_cache_count = imgselect_cache_p->img_count;
    mmi_camco_osd_p->captured_img_select_screen.img_select_pos_shift =  (mmi_camco_osd_p->captured_img_select_screen.img_list_count - imgselect_cache_p->img_count >> 1);  

    for (i = 0; i < MMI_CAMCO_CAM_CACHE_IMAGE_COUNT; i++)
    {
        imgselect_cache_p->cache_is_mem_blt[i] = MMI_FALSE;
    }
    mmi_camco_osd_p->captured_img_select_screen.is_hilite_img_saved = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_image_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR  start_idx, end_idx;
    CHAR  cache_highlighted_idx = 0;
    gdi_rect_struct clip;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    S32 resized_offset_x = 0;
    S32 resized_offset_y = 0;
    S32 resized_width = 0;
    S32 resized_height = 0;
    S32 image_width = 0;
    S32 image_height = 0;
    S32 pick_offset_x = 0;
    S32 pick_offset_y = 0;
    S32 offset_x;
    S32 offset_y;
    S32 img_layer_offset_x;
    S32 img_layer_offset_y;
    PU8 image_buf_ptr;
    U32 image_buf_size;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    mmi_camco_osd_captured_struct *imgselect_retion_p = &mmi_camco_osd_p->captured_img_select_screen;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    U32 tempticks_start = 0;
    U32 tempticks_end = 0;
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_retion_p->is_bypass_update_img_list)
        return;

    end_idx = imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count;

    /* draw highlight image */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->base_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    if (1)
    {
        mmi_camco_get_preview_region(
            &image_region_offset_x,
            &image_region_offset_y,
            &image_region_width,
            &image_region_height);

        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    #ifdef __MMI_INTERACTIVE_PROFILNG__
        if (mmi_frm_profiling_interactive_is_enabled())
        {
            kal_get_time(&tempticks_start);
        }
    #endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

        MMI_CAMCO_START_LOGGING("DEC");

        image_buf_ptr = (PU8) imgselect_cache_p->img_p->file_address[imgselect_cache_p->highlighted_idx];
        image_buf_size = imgselect_cache_p->img_p->file_size[imgselect_cache_p->highlighted_idx];
        gdi_image_jpeg_get_dimension(image_buf_ptr, image_buf_size, &image_width, &image_height);

        if ((imgselect_retion_p->hilite_picture.width >= image_width) &&
            (imgselect_retion_p->hilite_picture.height >= image_height))
        {
            /* align preview window at the center of screen */
            offset_x = ((imgselect_retion_p->hilite_picture.width - image_width) >> 1);
            offset_y = ((imgselect_retion_p->hilite_picture.height - image_height) >> 1);

            gdi_image_jpeg_draw(offset_x, offset_y, image_buf_ptr, image_buf_size);
        }
        else
        {
            gdi_image_util_fit_bbox(
                image_region_width,
                image_region_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_image_jpeg_draw_resized(
                resized_offset_x,
                resized_offset_y,
                resized_width,
                resized_height,
                image_buf_ptr,
                image_buf_size);
        }
        imgselect_cache_p->prev_highlighted_idx = imgselect_cache_p->highlighted_idx;

    #ifdef __MMI_INTERACTIVE_PROFILNG__
        if (mmi_frm_profiling_interactive_is_enabled())
        {
            kal_get_time(&tempticks_end);
            MMI_TRACE(
                MMI_MEDIA_TRC_G2_APP,
                MMI_TRC_CAMCO_CAM_DEC_DUR,
                (U32) ((tempticks_end - tempticks_start) * 4.615));
        }
    #endif /* __MMI_INTERACTIVE_PROFILNG__ */ /* __MMI_INTERACTIVE_PROFILNG_ */

        MMI_CAMCO_STOP_LOGGING("DEC");
    }

    gdi_layer_pop_and_restore_active();

    /* draw cache image */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->imageselect_cache_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_get_position(&img_layer_offset_x, &img_layer_offset_y);

    if (imgselect_cache_p->is_cache_img_osd_redraw)
    {

        for (start_idx = 0; start_idx < imgselect_cache_p->draw_cache_image_count; start_idx++)
        {

            //if (!imgselect_cache_p->cache_is_mem_blt[start_idx])
            {

                clip.x1 = imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].offset_x;
                clip.y1 = imgselect_retion_p->image_list[start_idx].offset_y;
                clip.x2 =
                    imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].offset_x +
                    imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].width - 1;
                clip.y2 = clip.y1 + imgselect_retion_p->image_list[start_idx].height - 1;

                gdi_2d_memory_blt_without_transpant_check(
                    imgselect_cache_p->cache_imgdata_pp[start_idx],
                    imgselect_cache_p->cache_img_width,
                    0,
                    0,
                    imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].width,
                    imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].height,
                    (U8*) mmi_camco_osd_p->imageselect_cache_layer_buf_p,
                    imgselect_cache_p->cache_layer_width,
                    clip.x1,
                    clip.y1,
                    clip,
                    GDI_MAINLCD_BIT_PER_PIXEL);

                imgselect_cache_p->cache_is_mem_blt[start_idx] = MMI_TRUE;

            }

        }

    }

    gdi_layer_pop_and_restore_active();

    if (!imgselect_cache_p->is_cache_highlight_osd_redraw)
    {
        return;
    }
    
    for (start_idx = 0; start_idx < end_idx; start_idx++)
    {
        S32 width, height;
        
        /* Put the save flag on 75% of width and height */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        gdi_image_get_dimension_id(IMG_ID_CAMCO_PICK, &width, &height);
        
        pick_offset_x = imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].offset_x +
                (imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].width)  - width;        
        
        pick_offset_y = imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].offset_y +
            (imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].height * 3) / 4;
        
        //gdi_draw_solid_rect(pick_offset_x + width, pick_offset_y + 0.25 * height, pick_offset_x + width, pick_offset_y + height, GDI_COLOR_WHITE);                

        if (imgselect_cache_p->save_flag_p[start_idx] == TRUE)
        {
            gdi_image_draw_id(pick_offset_x, pick_offset_y, IMG_ID_CAMCO_PICK);
        }
    }
    
    /* draw highlight rectangle on osd layer */
    cache_highlighted_idx = imgselect_cache_p->highlighted_idx - imgselect_cache_p->first_disp_idx;
    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + img_layer_offset_y,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + img_layer_offset_y,
        imgselect_cache_p->highlight_border_color);

    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x - 1 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y - 1 + img_layer_offset_y,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + 1 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + 1 + img_layer_offset_y,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x - 2 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y - 2 + img_layer_offset_y,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + 2 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + 2 + img_layer_offset_y,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x - 3 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y - 3 + img_layer_offset_y,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + 3 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + 3 + img_layer_offset_y,
        imgselect_cache_p->highlight_border_color);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select_osd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_image_select_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR  start_idx, end_idx;
    CHAR  cache_highlighted_idx = 0;
    S32 pick_offset_x = 0;
    S32 pick_offset_y = 0;
    S32 img_layer_offset_x;
    S32 img_layer_offset_y;
    S32 frame_w, frame_h;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    mmi_camco_osd_captured_struct *imgselect_retion_p = &mmi_camco_osd_p->captured_img_select_screen;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    U32 tempticks_start;
    U32 tempticks_end;
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_retion_p->is_bypass_update_img_list)
        return;

    end_idx = imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count;

    if (!imgselect_cache_p->is_cache_highlight_osd_redraw)
    {
        return;
    }

    gdi_image_get_dimension_id(IMG_ID_CAMCO_CAM_IMG_LIST_ITEM_ICON, &frame_w, &frame_h);
  
    img_layer_offset_x = 0;
    img_layer_offset_y = mmi_camco_osd_p->osd_height - (frame_h + (2 * MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH));

    /* draw saved flag on osd layer */
    for (start_idx = 0; start_idx < end_idx; start_idx++)
    {
        S32 width, height;
        
        /* Put the save flag on 75% of width and height */
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        gdi_image_get_dimension_id(IMG_ID_CAMCO_PICK, &width, &height);
        
        pick_offset_x = imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].offset_x +
                (imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].width)  - width;        
        
        pick_offset_y = imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].offset_y +
            (imgselect_retion_p->image_list_touch[start_idx + imgselect_retion_p->img_select_pos_shift].height * 3) / 4;
        
        if(pick_offset_y + height > mmi_camco_osd_p->osd_height - 1)
        {
            pick_offset_y = mmi_camco_osd_p->osd_height - 1 - height;
        }
                
        if (imgselect_cache_p->save_flag_p[start_idx] == TRUE)
        {
            gdi_image_draw_id(pick_offset_x, pick_offset_y, IMG_ID_CAMCO_PICK);
        }
    }
    
    /* draw highlight rectangle on osd layer */
    cache_highlighted_idx = imgselect_cache_p->highlighted_idx - imgselect_cache_p->first_disp_idx;
    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + img_layer_offset_y + 1,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + img_layer_offset_y + 1,
        imgselect_cache_p->highlight_border_color);

    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x - 1 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y - 1 + img_layer_offset_y + 1,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + 1 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + 1 + img_layer_offset_y + 1,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x - 2 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y - 2 + img_layer_offset_y + 1,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + 2 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + 2 + img_layer_offset_y + 1,
        imgselect_cache_p->highlight_color);

    gdi_draw_rect(
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x - 3 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y - 3 + img_layer_offset_y + 1,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_x + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].width + 3 + img_layer_offset_x,
        imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].offset_y + imgselect_retion_p->image_frame_list[cache_highlighted_idx + imgselect_retion_p->img_select_pos_shift].height + 3 + img_layer_offset_y + 1,
        imgselect_cache_p->highlight_border_color);



}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b_ptr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_image_select_cache(U8 *b_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR  start_idx, end_idx;
    gdi_rect_struct clip;
    S32 img_layer_offset_x;
    S32 img_layer_offset_y;
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    mmi_camco_osd_captured_struct *imgselect_retion_p = &mmi_camco_osd_p->captured_img_select_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_retion_p->is_bypass_update_img_list)
        return;

    end_idx = imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count;

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_get_position(&img_layer_offset_x, &img_layer_offset_y);

    /* in 38 img select case, we need to use LCD rorate only on base screen and g2d rotate on others */
    /* because cache content is rotate by draw layer each time, we need to draw all small pic every time */
    for (start_idx = 0; start_idx < imgselect_cache_p->draw_cache_image_count; start_idx++)
    {
        clip.x1 = imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].offset_x;
        clip.y1 = imgselect_retion_p->image_list[start_idx].offset_y;
        clip.x2 = imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].offset_x +
            imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].width - 1;
        clip.y2 = clip.y1 + imgselect_retion_p->image_list[start_idx].height - 1;

        gdi_2d_memory_blt_without_transpant_check(
            imgselect_cache_p->cache_imgdata_pp[start_idx],
            imgselect_cache_p->cache_img_width,
            0,
            0,
            imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].width,
            imgselect_retion_p->image_list[start_idx + imgselect_retion_p->img_select_pos_shift].height,
            (U8*) b_ptr,
            imgselect_cache_p->cache_layer_height,
            clip.x1,
            clip.y1,
            clip,
            GDI_MAINLCD_BIT_PER_PIXEL);

        imgselect_cache_p->cache_is_mem_blt[start_idx] = MMI_TRUE;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_image_select_hilite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_image_select_hilite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR  end_idx;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    S32 resized_offset_x = 0;
    S32 resized_offset_y = 0;
    S32 resized_width = 0;
    S32 resized_height = 0;
    S32 image_width = 0;
    S32 image_height = 0;
    S32 offset_x;
    S32 offset_y;
    PU8 image_buf_ptr;
    U32 image_buf_size;

    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;
    mmi_camco_osd_captured_struct *imgselect_retion_p = &mmi_camco_osd_p->captured_img_select_screen;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    U32 tempticks_start = 0;
    U32 tempticks_end = 0;
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (imgselect_retion_p->is_bypass_update_img_list)
        return;

    end_idx = imgselect_cache_p->first_disp_idx + imgselect_cache_p->disp_cache_count;

    /* draw highlight image */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->base_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    mmi_camco_get_preview_region(
        &image_region_offset_x,
        &image_region_offset_y,
        &image_region_width,
        &image_region_height);

    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

#ifdef __MMI_INTERACTIVE_PROFILNG__
    if (mmi_frm_profiling_interactive_is_enabled())
    {
        kal_get_time(&tempticks_start);
    }
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ 

    MMI_CAMCO_START_LOGGING("DEC");

    image_buf_ptr = (PU8) imgselect_cache_p->img_p->file_address[imgselect_cache_p->highlighted_idx];
    image_buf_size = imgselect_cache_p->img_p->file_size[imgselect_cache_p->highlighted_idx];
    gdi_image_jpeg_get_dimension(image_buf_ptr, image_buf_size, &image_width, &image_height);

    if ((imgselect_retion_p->hilite_picture.width >= image_width) &&
        (imgselect_retion_p->hilite_picture.height >= image_height))
    {
        /* align preview window at the center of screen */
        offset_x = ((imgselect_retion_p->hilite_picture.width - image_width) >> 1);
        offset_y = ((imgselect_retion_p->hilite_picture.height - image_height) >> 1);

        gdi_image_jpeg_draw(offset_x, offset_y, image_buf_ptr, image_buf_size);
    }
    else
    {
        gdi_image_util_fit_bbox(
            image_region_width,
            image_region_height,
            image_width,
            image_height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);

        gdi_image_jpeg_draw_resized(
            resized_offset_x,
            resized_offset_y,
            resized_width,
            resized_height,
            image_buf_ptr,
            image_buf_size);
    }
    imgselect_cache_p->prev_highlighted_idx = imgselect_cache_p->highlighted_idx;

#ifdef __MMI_INTERACTIVE_PROFILNG__
    if (mmi_frm_profiling_interactive_is_enabled())
    {
        kal_get_time(&tempticks_end);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_CAMCO_CAM_DEC_DUR, (U32) ((tempticks_end - tempticks_start) * 4.615));
    }
#endif /* __MMI_INTERACTIVE_PROFILNG__ */ /* __MMI_INTERACTIVE_PROFILNG_ */

    MMI_CAMCO_STOP_LOGGING("DEC");

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_redraw_image_select_highlight_osd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_redraw       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_redraw_image_select_highlight_osd(MMI_BOOL is_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.is_cache_highlight_osd_redraw = is_redraw;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_redraw_image_select_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_redraw       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_redraw_image_select_cache(MMI_BOOL is_redraw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.is_cache_img_osd_redraw = is_redraw;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_draw_image_select_cache_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  draw_count      [IN]        Display cache count
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_draw_image_select_cache_count(U16 draw_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->imgselect_cache.draw_cache_image_count = draw_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_imgselect_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_imgselect_move_prev())
    {
        if(!mmi_camco_osd_p->imgselect_cache.save_flag_p[mmi_camco_osd_p->imgselect_cache.highlighted_idx ])
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_TRUE;                    
        }
        else
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_FALSE;               
            SEND_EVT(MMI_CAMCO_EVT_OK, NULL);             
        }        
        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_prev_cyclic);

    }
    else
    {
        imgselect_cache_p->highlighted_idx = imgselect_cache_p->img_count - 1;    
        if(!mmi_camco_osd_p->imgselect_cache.save_flag_p[mmi_camco_osd_p->imgselect_cache.highlighted_idx ])
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_TRUE;                    
        }
        else
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_FALSE;               
            SEND_EVT(MMI_CAMCO_EVT_OK, NULL);             
        }         

        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_prev_cyclic);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_imgselect_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_imgselect_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_img_select_struct *imgselect_cache_p = &mmi_camco_osd_p->imgselect_cache;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_imgselect_move_next())
    {
        if(!mmi_camco_osd_p->imgselect_cache.save_flag_p[mmi_camco_osd_p->imgselect_cache.highlighted_idx ])
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_TRUE;                    
        }
        else
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_FALSE;
            SEND_EVT(MMI_CAMCO_EVT_OK, NULL);                            
        }         
        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_next_cyclic);

    }
    else
    {
        imgselect_cache_p->highlighted_idx = 0;    
        if(!mmi_camco_osd_p->imgselect_cache.save_flag_p[mmi_camco_osd_p->imgselect_cache.highlighted_idx ])
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_TRUE;                    
        }
        else
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
            mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_FALSE; 
            SEND_EVT(MMI_CAMCO_EVT_OK, NULL);                              
        }         

        mmi_camco_updata_key_handler();
        mmi_camco_osd_draw_osd();

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_IMGSELECT_MOVE_DUR, mmi_camco_osd_imgselect_next_cyclic);
    }
}
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_panorama
 * DESCRIPTION
 *  Draw panorama icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_panorama(void)
{
#ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_panorama_direction_enum panorama_direct;
    MMI_ID_TYPE panorama_icon = IMG_ID_CAMCO_PANORAMA_UP_STEP_0;
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    panorama_direct = mmi_camco_setting_get_panorama_direction();

    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP || panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_DOWN)
    {
        offset_x = mmi_camco_osd_skin_p->camera_preview.panorama_ver.offset_x;
        offset_y = mmi_camco_osd_skin_p->camera_preview.panorama_ver.offset_y;

        if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP)
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_UP_STEP_0;
        }
        else
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_DOWN_STEP_0;
        }
    }
    else if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_LEFT ||
             panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_RIGHT)
    {
        offset_x = mmi_camco_osd_skin_p->camera_preview.panorama_hor.offset_x;
        offset_y = mmi_camco_osd_skin_p->camera_preview.panorama_hor.offset_y;

        if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_LEFT)
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_LEFT_STEP_0;
        }
        else
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_RIGHT_STEP_0;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

    gdi_image_draw_id(offset_x, offset_y, panorama_icon);
#endif    
}

#ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_panorama_selection
 * DESCRIPTION
 *  Draw panorama direction selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_panorama_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ua_offset_x, ua_offset_y;
    S32 da_offset_x, da_offset_y;
    S32 la_offset_x, la_offset_y;
    S32 ra_offset_x, ra_offset_y;
    mmi_camco_panorama_direction_enum panorama_direct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ua_offset_x = mmi_camco_osd_skin_p->panorama.ua.offset_x;
    ua_offset_y = mmi_camco_osd_skin_p->panorama.ua.offset_y;
    da_offset_x = mmi_camco_osd_skin_p->panorama.da.offset_x;
    da_offset_y = mmi_camco_osd_skin_p->panorama.da.offset_y;
    la_offset_x = mmi_camco_osd_skin_p->panorama.la.offset_x;
    la_offset_y = mmi_camco_osd_skin_p->panorama.la.offset_y;
    ra_offset_x = mmi_camco_osd_skin_p->panorama.ra.offset_x;
    ra_offset_y = mmi_camco_osd_skin_p->panorama.ra.offset_y;

    panorama_direct = mmi_camco_osd_p->panorama.highlighted_idx;

    if (mmi_camco_osd_p->panorama.ua_touch.is_press)
    {
        ua_offset_x++;
        ua_offset_y++;
    }
    else if (mmi_camco_osd_p->panorama.da_touch.is_press)
    {
        da_offset_x++;
        da_offset_y++;
    }
    else if (mmi_camco_osd_p->panorama.la_touch.is_press)
    {
        la_offset_x++;
        la_offset_y++;
    }
    else if (mmi_camco_osd_p->panorama.ra_touch.is_press)
    {
        ra_offset_x++;
        ra_offset_y++;
    }

    /* draw up icon */
    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP)
    {
        gdi_image_draw_id(ua_offset_x, ua_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_UP_SEL);
    }
    else
    {
        gdi_image_draw_id(ua_offset_x, ua_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_UP);
    }

    /* draw down icon */
    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_DOWN)
    {
        gdi_image_draw_id(da_offset_x, da_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_DOWN_SEL);
    }
    else
    {
        gdi_image_draw_id(da_offset_x, da_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_DOWN);
    }

    /* draw left icon */
    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_LEFT)
    {
        gdi_image_draw_id(la_offset_x, la_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_LEFT_SEL);
    }
    else
    {
        gdi_image_draw_id(la_offset_x, la_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_LEFT);
    }

    /* draw right icon */
    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_RIGHT)
    {
        gdi_image_draw_id(ra_offset_x, ra_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_RIGHT_SEL);
    }
    else
    {
        gdi_image_draw_id(ra_offset_x, ra_offset_y, IMG_ID_CAMCO_PANORAMA_DIRECT_RIGHT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_panorama_shot
 * DESCRIPTION
 *  Draw panorama shot
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_panorama_shot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_panorama_direction_enum panorama_direct;
    U8 capture_count;
    MMI_ID_TYPE panorama_icon = IMG_ID_CAMCO_PANORAMA_UP_STEP_0;
    S32 offset_x = 0;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    panorama_direct = mmi_camco_setting_get_panorama_direction();
    capture_count = mmi_camco_get_panorama_capture_count();

    if (capture_count > MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT)
    {
        MMI_ASSERT(0);
    }

    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP || panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_DOWN)
    {
        offset_x = mmi_camco_osd_skin_p->panorama.shot_ver.offset_x;
        offset_y = mmi_camco_osd_skin_p->panorama.shot_ver.offset_y;

        if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP)
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_UP_STEP_0 + capture_count;
        }
        else
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_DOWN_STEP_0 + capture_count;
        }
    }
    else if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_LEFT ||
             panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_RIGHT)
    {
        offset_x = mmi_camco_osd_skin_p->panorama.shot_hor.offset_x;
        offset_y = mmi_camco_osd_skin_p->panorama.shot_hor.offset_y;

        if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_LEFT)
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_LEFT_STEP_0 + capture_count;
        }
        else
        {
            panorama_icon = IMG_ID_CAMCO_PANORAMA_RIGHT_STEP_0 + capture_count;
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
    gdi_image_draw_id(offset_x, offset_y, panorama_icon);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_panorama
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_panorama(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    mmi_camco_osd_panorama_shot_struct *scr_p = &(mmi_camco_osd_p->panorama_screen);
    mmi_camco_osd_panorama_struct *pano  = &(mmi_camco_osd_p->panorama);
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama.is_interrupt = MMI_FALSE;

    scr_p->cancel.offset_x = setting_skin_p->back.offset_x;
    scr_p->cancel.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &scr_p->cancel.width, &scr_p->cancel.height);
    scr_p->cancel.img_id = IMG_ID_CAMCO_BACK_ICON;

    scr_p->OK.offset_x = setting_skin_p->advance_setting.offset_x;
    scr_p->OK.offset_y = setting_skin_p->advance_setting.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OK_ICON, &scr_p->OK.width, &scr_p->OK.height);
    scr_p->OK.img_id = IMG_ID_CAMCO_OK_ICON;

    scr_p->capture.offset_x = setting_skin_p->advance_setting.offset_x;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_CAM_CAP_ICON, &scr_p->capture.width, &scr_p->capture.height);    
    scr_p->capture.offset_y = (mmi_camco_osd_p->osd_height - scr_p->capture.height)>>1;
    scr_p->capture.img_id = IMG_ID_CAMCO_PREVIEW_CAM_CAP_ICON;
    
    pano->ua_touch.offset_x = mmi_camco_osd_skin_p->panorama.ua.offset_x;
    pano->ua_touch.offset_y = mmi_camco_osd_skin_p->panorama.ua.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PANORAMA_DIRECT_UP,&pano->ua_touch.width, &pano->ua_touch.height);
    pano->ua_touch.img_id = IMG_ID_CAMCO_PANORAMA_DIRECT_UP;

    pano->da_touch.offset_x = mmi_camco_osd_skin_p->panorama.da.offset_x;
    pano->da_touch.offset_y = mmi_camco_osd_skin_p->panorama.da.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PANORAMA_DIRECT_DOWN,&pano->da_touch.width, &pano->da_touch.height);
    pano->da_touch.img_id = IMG_ID_CAMCO_PANORAMA_DIRECT_DOWN;

    pano->la_touch.offset_x = mmi_camco_osd_skin_p->panorama.la.offset_x;
    pano->la_touch.offset_y = mmi_camco_osd_skin_p->panorama.la.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PANORAMA_DIRECT_LEFT,&pano->la_touch.width, &pano->la_touch.height);
    pano->la_touch.img_id = IMG_ID_CAMCO_PANORAMA_DIRECT_LEFT;

    pano->ra_touch.offset_x = mmi_camco_osd_skin_p->panorama.ra.offset_x;
    pano->ra_touch.offset_y = mmi_camco_osd_skin_p->panorama.ra.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PANORAMA_DIRECT_RIGHT,&pano->ra_touch.width, &pano->ra_touch.height);
    pano->ra_touch.img_id = IMG_ID_CAMCO_PANORAMA_DIRECT_RIGHT;
       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_panorama_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_gen_panorama_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->panorama.is_interrupt)
    {
        mmi_camco_osd_p->panorama.highlighted_idx = mmi_camco_setting_get_panorama_direction();
    }
    else
    {
        mmi_camco_osd_p->panorama.is_interrupt = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_set_direct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_set_direct(U8 dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama.highlighted_idx = dir;

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_up_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_up_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->panorama.ua_touch.is_press)
    {
        /* already pressed */
        return;
    }

    mmi_camco_osd_p->panorama.ua_touch.is_press = MMI_TRUE;
    mmi_camco_osd_p->panorama.highlighted_idx = MMI_CAMCO_PANORAMA_DIRECTION_UP;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_up_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_up_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama.ua_touch.is_press = MMI_FALSE;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_down_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_down_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->panorama.da_touch.is_press)
    {
        /* already pressed */
        return;
    }

    mmi_camco_osd_p->panorama.da_touch.is_press = MMI_TRUE;
    mmi_camco_osd_p->panorama.highlighted_idx = MMI_CAMCO_PANORAMA_DIRECTION_DOWN;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_down_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_down_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama.da_touch.is_press = MMI_FALSE;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_left_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_left_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->panorama.la_touch.is_press)
    {
        /* already pressed */
        return;
    }

    mmi_camco_osd_p->panorama.la_touch.is_press = MMI_TRUE;
    mmi_camco_osd_p->panorama.highlighted_idx = MMI_CAMCO_PANORAMA_DIRECTION_LEFT;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_left_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_left_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama.la_touch.is_press = MMI_FALSE;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_right_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_right_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->panorama.ra_touch.is_press)
    {
        /* already pressed */
        return;
    }

    mmi_camco_osd_p->panorama.ra_touch.is_press = MMI_TRUE;
    mmi_camco_osd_p->panorama.highlighted_idx = MMI_CAMCO_PANORAMA_DIRECTION_RIGHT;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_direct_right_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_panorama_direct_right_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama.ra_touch.is_press = MMI_FALSE;
    mmi_camco_osd_draw_osd();

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_panorama_shot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_gen_panorama_shot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 preview_roi_offset_x;
    S32 preview_roi_offset_y;
    S32 preview_roi_width;
    S32 preview_roi_height;
    PU8 image_buf_ptr;
    U32 image_buf_size;
    S32 cache_layer_width;
    S32 cache_layer_height;
    S32 cache_layer_offset_x;
    S32 cache_layer_offset_y;
    S32 decode_offset_x;
    S32 decode_offset_y;
    U32 image_width;
    U32 image_height;

    U8 *dst_p;
    S32 width, height;
    S32 pos_x, pos_y;
    gdi_rect_struct clip;

    mmi_camco_panorama_direction_enum panorama_direct;
    GDI_RESULT gdi_handle_result = GDI_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_is_preview())
    {
        return;
    }

    panorama_direct = mmi_camco_setting_get_panorama_direction();

    mmi_camco_get_preview_region(&preview_roi_offset_x, &preview_roi_offset_y, &preview_roi_width, &preview_roi_height);

    mmi_camco_get_panorama_capture_image(&image_buf_ptr, &image_buf_size, &image_width, &image_height);
    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP || panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_DOWN)
    {
        cache_layer_width = preview_roi_width;
        cache_layer_height = (preview_roi_height * MMI_CAMCO_OSD_PANORAMA_CACHE_RATIO) / 100;

        if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP)
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            cache_layer_offset_x = 0 + preview_roi_offset_y;
            cache_layer_offset_y = 0 + preview_roi_offset_x;
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            cache_layer_offset_x = 0 + preview_roi_offset_x;
            cache_layer_offset_y = preview_roi_height - cache_layer_height + preview_roi_offset_y;
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        }
        else
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            cache_layer_offset_x = preview_roi_height - cache_layer_height + preview_roi_offset_y;
            cache_layer_offset_y = 0 + preview_roi_offset_x;
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            cache_layer_offset_x = 0 + preview_roi_offset_x;
            cache_layer_offset_y = 0 + +preview_roi_offset_y;
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        }
    }
    else
    {
        cache_layer_width = (preview_roi_width * MMI_CAMCO_OSD_PANORAMA_CACHE_RATIO) / 100;
        cache_layer_height = preview_roi_height;

        if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_LEFT)
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            cache_layer_offset_x = 0 + preview_roi_offset_y;
            cache_layer_offset_y = preview_roi_width - cache_layer_width + preview_roi_offset_x;
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            cache_layer_offset_x = preview_roi_width - cache_layer_width + preview_roi_offset_x;
            cache_layer_offset_y = 0 + preview_roi_offset_y;
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        }
        else
        {
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            cache_layer_offset_x = 0 + preview_roi_offset_y;
            cache_layer_offset_y = 0 + preview_roi_offset_x;
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            cache_layer_offset_x = 0 + preview_roi_offset_x;
            cache_layer_offset_y = 0 + preview_roi_offset_y;
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        }
    }

    if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_LEFT || panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_UP)
    {
        decode_offset_x = 0;
        decode_offset_y = 0;
    }
    else if (panorama_direct == MMI_CAMCO_PANORAMA_DIRECTION_RIGHT)
    {
        decode_offset_x = -(preview_roi_width - cache_layer_width);
        decode_offset_y = 0;
    }
    else
    {
        decode_offset_x = 0;
        decode_offset_y = -(preview_roi_height - cache_layer_height);
    }

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
    gdi_layer_resize(cache_layer_width, cache_layer_height);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);

    gdi_layer_get_dimension(&width, &height);
    gdi_layer_get_position(&pos_x, &pos_y);
    gdi_layer_get_buffer_ptr(&dst_p);
    clip.x1 = pos_x;
    clip.y1 = pos_y;
    clip.x2 = pos_x + width;
    clip.y2 = pos_y + height;

    gdi_2d_memory_blt(
        image_buf_ptr,
        preview_roi_width,
        0 - decode_offset_x,
        0 - decode_offset_y,
        preview_roi_width + decode_offset_x,
        preview_roi_height + decode_offset_y,
        dst_p,
        width,
        0,
        0,
        clip,
        GDI_MAINLCD_BIT_PER_PIXEL);

    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(mmi_camco_osd_p->panorama_cache_layer_h);
    gdi_layer_lock_frame_buffer();
    gdi_layer_resize(cache_layer_height, cache_layer_width);
    gdi_layer_set_position(cache_layer_offset_x, cache_layer_offset_y);
    gdi_layer_set_opacity(MMI_TRUE, MMI_CAMCO_OSD_PANORAMA_CACHE_OPACITY);

    mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->panorama_cache_layer_h);

    gdi_layer_unlock_frame_buffer();
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
    gdi_layer_resize(mmi_camco_osd_p->osd_width, mmi_camco_osd_p->osd_height);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
    gdi_layer_push_and_set_active(mmi_camco_osd_p->panorama_cache_layer_h);
    gdi_layer_resize(cache_layer_width, cache_layer_height);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_position(cache_layer_offset_x, cache_layer_offset_y);
    gdi_layer_set_opacity(MMI_TRUE, MMI_CAMCO_OSD_PANORAMA_CACHE_OPACITY);

    gdi_layer_get_dimension(&width, &height);
    gdi_layer_get_position(&pos_x, &pos_y);
    gdi_layer_get_buffer_ptr(&dst_p);
    clip.x1 = pos_x;
    clip.y1 = pos_y;
    clip.x2 = pos_x + width;
    clip.y2 = pos_y + height;

    gdi_2d_memory_blt(
        image_buf_ptr,
        preview_roi_width,
        0 - decode_offset_x,
        0 - decode_offset_y,
        preview_roi_width + decode_offset_x,
        preview_roi_height + decode_offset_y,
        dst_p,
        width,
        0,
        0,
        clip,
        GDI_MAINLCD_BIT_PER_PIXEL);

    gdi_layer_pop_and_restore_active();
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_shot_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_panorama_shot_setup_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf_size = 0;
    CHAR  *align_osd_layer_p;
    S32 db_working_buffer_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->panorama.is_init)
    {
        return;
    }
    MMI_ASSERT(mmi_camco_osd_p->panorama_cache_layer_buf_p != NULL);

    buf_size = ((mmi_camco_osd_p->osd_width * mmi_camco_osd_p->osd_height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);

    align_osd_layer_p = (CHAR *)(((((U32)mmi_camco_osd_p->panorama_cache_layer_buf_p) >>5) +1) <<5);
    gdi_layer_create_using_outside_memory(
        0,
        0,
        mmi_camco_osd_p->osd_width,
        mmi_camco_osd_p->osd_height,
        &mmi_camco_osd_p->panorama_cache_layer_h,
        (U8*) align_osd_layer_p,
        buf_size);

#ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    db_working_buffer_size = mmi_camco_osd_p->osd_width*mmi_camco_osd_p->osd_height*2
    align_osd_layer_p = (CHAR *)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) + 1) <<5);
    gdi_bltdb_set_blt_buffer(
        mmi_camco_osd_p->panorama_cache_layer_h, 
        align_osd_layer_p + MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2, 
        db_working_buffer_size, 
        align_osd_layer_p + MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2 + db_working_buffer_size, 
        db_working_buffer_size);            
#endif

    gdi_layer_push_and_set_active(mmi_camco_osd_p->panorama_cache_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active();
    mmi_camco_osd_p->panorama.is_init = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_shot_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_panorama_shot_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->panorama.is_init)
    {
        return;
    }
    else if (mmi_camco_osd_p->panorama.is_init && mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_PANORAMA_SHOT)
    {
        return;
    }

    if (mmi_camco_osd_p->panorama_cache_layer_h)
    {
        gdi_layer_free(mmi_camco_osd_p->panorama_cache_layer_h);
        mmi_camco_osd_p->panorama_cache_layer_h = GDI_NULL_HANDLE;
    }
    mmi_camco_osd_p->panorama.is_init = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_set_cache_layer_buf_p
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_panorama_set_cache_layer_buf_p(void *buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama_cache_layer_buf_p = (CHAR *) buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_is_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_panorama_is_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->panorama.is_picked;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_panorama_set_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_panorama_set_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->panorama.is_picked = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_panorama_selection_interrupt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_interrupt        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_panorama_selection_interrupt(MMI_BOOL is_interrupt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_panorama_struct *panorama_p = &mmi_camco_osd_p->panorama;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    panorama_p->is_interrupt = is_interrupt;

}
#endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_zooming
 * DESCRIPTION
 *  qeury if zooming
 * PARAMETERS
 *  void
 * RETURNS
 *  result  [OUT]
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_is_zooming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND_MOVE ||
            mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_stop_zoom
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_stop_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_value;
    mmi_camco_osd_rec_screen_struct *scr_p = &mmi_camco_osd_p->recording_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW)
    {
        zoom_value = mmi_camco_setting_get_vdozoom_step();

        if (mmi_camco_osd_is_horz_UI())
        {        
            scr_p->slider_location.offset_y = (S32)
                (scr_p->slider_bar.offset_y + scr_p->slider_region.height *
                 (((zoom_value - mmi_camco_osd_p->rec_slider.min_value) * 1.0) / (mmi_camco_osd_p->rec_slider.step_count - 1)));

            scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;
        }
        else
        {        
            scr_p->slider_location.offset_x = (S32)
                (scr_p->slider_bar.offset_x + scr_p->slider_region.width*
                 (((zoom_value - mmi_camco_osd_p->rec_slider.min_value) * 1.0) / (mmi_camco_osd_p->rec_slider.step_count - 1)));

            scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;
        }            
        mmi_camco_setting_set_vdozoom_step(zoom_value);
        mdi_camera_update_para_zoom(zoom_value);
        mmi_camco_setting_set_vdozoom_value(mmi_camco_update_zoom_factor());

        mmi_camco_osd_p->rec_slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
    }
}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_record_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_msec       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_reduced_record_time(U64 time_msec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    S32 offset_x;
    U64 time_sec = time_msec / 1000;
#ifdef __MMI_OP02_LEMEI__       
    U64 predict_time_sec = mmi_camco_get_predict_record_time();        
#endif
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    gdi_rect_struct *rotate_rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_rec_time_area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hour = time_sec / 3600;
    hour_remain = time_sec % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS - rotate_rec_time_area_p->x1,
            progress_p->dot_offset_y + progress_p->num_img_height / 2 - rotate_rec_time_area_p->y1,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_RED);
    }
    else
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS - rotate_rec_time_area_p->x1,
            progress_p->dot_offset_y + progress_p->num_img_height / 2 - rotate_rec_time_area_p->y1,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_GREEN);
    }

    /* hr */
    gdi_image_draw_id(
        progress_p->time_offset_x - rotate_rec_time_area_p->x1,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

    offset_x = progress_p->time_offset_x + progress_p->num_img_width + 1 - rotate_rec_time_area_p->x1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* min */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* sec */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(
        offset_x,
        progress_p->time_offset_y - rotate_rec_time_area_p->y1,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));

#ifdef __MMI_OP02_LEMEI__   
    if (!mmi_camco_setting_app_switch_is_enable())
    {
        hour = predict_time_sec / 3600;
        hour_remain = predict_time_sec % 3600;
        min = hour_remain / 60;
        sec = hour_remain % 60;

        /* / */   
        offset_x += progress_p->num_img_width + 1;
        gui_move_text_cursor(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1);
        gui_print_bordered_text((UI_string_type) L"/");    

        /* hr */    
        offset_x += progress_p->num_img_width + 1;    
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* min */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* sec */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y - rotate_rec_time_area_p->y1, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));
    }
#endif
}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_record_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time_msec       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_record_time(U64 time_msec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    S32 offset_x;
    U64 time_sec = time_msec / 1000;
#ifdef __MMI_OP02_LEMEI__       
    U64 predict_time_sec = mmi_camco_get_predict_record_time();    
#endif
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hour = time_sec / 3600;
    hour_remain = time_sec % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            progress_p->dot_offset_y + progress_p->num_img_height / 2,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_RED);
    }
    else
    {
        gdi_draw_solid_circle(
            progress_p->dot_offset_x + MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            progress_p->dot_offset_y + progress_p->num_img_height / 2,
            MMI_CAMCO_OSD_RECORD_TIME_DOT_RADIUS,
            GDI_COLOR_GREEN);
    }

    /* hr */
    gdi_image_draw_id(
        progress_p->time_offset_x,
        progress_p->time_offset_y,
        (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

    offset_x = progress_p->time_offset_x + progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* min */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

    /* sec */
    offset_x += progress_p->col_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

    offset_x += progress_p->num_img_width + 1;
    gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));

#ifdef __MMI_OP02_LEMEI__   
    if (!mmi_camco_setting_app_switch_is_enable())
    {
        hour = predict_time_sec / 3600;
        hour_remain = predict_time_sec % 3600;
        min = hour_remain / 60;
        sec = hour_remain % 60;

        /* / */   
        offset_x += progress_p->num_img_width + 1;
        gui_move_text_cursor(offset_x, progress_p->time_offset_y);
        gui_print_bordered_text((UI_string_type) L"/");    

        /* hr */    
        offset_x += progress_p->num_img_width + 1;    
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) hour % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* min */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) min % 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_COLON));

        /* sec */
        offset_x += progress_p->col_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec / 10));

        offset_x += progress_p->num_img_width + 1;
        gdi_image_draw_id(offset_x, progress_p->time_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + (U16) sec % 10));
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_record_time_only
 * DESCRIPTION
 *  dummy function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_record_time_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_camco_osd_is_horz_UI())
    {
        mmi_camco_osd_vdo_recording_osd_struct *video_recoding_osd_p = &mmi_camco_osd_p->video_recoding_osd;

        /* Record time */
        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

        gdi_layer_resize(
            video_recoding_osd_p->rotate_rec_time_area.x2 - video_recoding_osd_p->rotate_rec_time_area.x1 + 1,
            video_recoding_osd_p->rotate_rec_time_area.y2 - video_recoding_osd_p->rotate_rec_time_area.y1 + 1);
        mmi_camco_osd_clear_bg();
        mmi_camco_osd_draw_reduced_record_time(mmi_camco_get_record_time());

        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_rec_time_area_h);
        gdi_layer_toggle_double();
        gdi_layer_lock_frame_buffer();

        mmi_camco_osd_rotate_for_hw_rotate(
            mmi_camco_osd_p->osd_layer_draw_h,
            video_recoding_osd_p->osd_layer_rec_time_area_h);

        gdi_layer_unlock_frame_buffer();
        gdi_layer_pop_and_restore_active();

        if (mmi_camco_osd_p->is_blt)
        {
            mmi_camco_osd_blt();
        }
    }
    else
    {
        /* Subcamera - Portait */
        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
        gdi_layer_toggle_double();
        gdi_layer_lock_frame_buffer();

        mmi_camco_osd_clear_bg();
        mmi_camco_draw_video_slider();
        mmi_camco_osd_draw_softkey();
        mmi_camco_osd_draw_record_time(mmi_camco_get_record_time());

    #ifdef __MMI_OP02_LEMEI__    
        if (mmi_camco_setting_app_switch_is_enable())
        {
            if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
            {
                mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
            }            
        }
    #else
        if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
        {
            mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
        }
    #endif

        gdi_layer_unlock_frame_buffer();
        gdi_layer_pop_and_restore_active();

        mmi_camco_osd_blt();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_xenon_flash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_xenon_flash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->xenon_flash_state = MMI_CAMCO_OSD_XENON_FLASH_STATE_EXIT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_xenon_flash_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  xenon_flash_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_xenon_flash_state(mmi_camco_osd_xenon_flash_state_enum xenon_flash_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->xenon_flash_state = xenon_flash_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_xenon_flash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_xenon_flash(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x = mmi_camco_osd_skin_p->xenon_status.offset_x;
    S32 offset_y = mmi_camco_osd_skin_p->xenon_status.offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_CAMCO_CAM_XENON_FLASH_DRAW, mmi_camco_osd_p->xenon_flash_state);

    switch (mmi_camco_osd_p->xenon_flash_state)
    {
        case MMI_CAMCO_OSD_XENON_FLASH_STATE_SUCCESS:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_SUCCESS));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_CHARGING:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_CHARGING));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_TIMEOUT:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_TIMEOUT));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_LOW_BATTERY:
            gdi_image_draw_id(offset_x, offset_y, (U16) (IMG_ID_CAMCO_XENON_LOW_BATTERY));
            break;

        case MMI_CAMCO_OSD_XENON_FLASH_STATE_EXIT:
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduced_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ratio       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_reduced_progress(U16 ratio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    U32 progress_width;
    GDI_RESULT ret;
    gdi_rect_struct *rotate_rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_rec_time_area;
    gdi_rect_struct clip;
    S32 num_width;
    S32 num_height;
    S32 img_width;
    S32 img_height;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &num_width, &num_height);
    gdi_image_get_dimension_id(IMG_ID_CAMCO_VIDEO_PROGRESS_BG, &img_width, &img_height);
    if (num_height > img_height)
    {
        offset_y = (num_height - img_height) >> 1;
    }

    clip.x1 = progress_p->progress_offset_x - rotate_rec_time_area_p->x1;
    clip.y1 = progress_p->progress_offset_y - rotate_rec_time_area_p->y1;

    /* draw progress bg */
    gdi_layer_set_clip(
        clip.x1,
        clip.y1 + offset_y,
        clip.x1 + mmi_camco_osd_skin_p->video_record.progress_width,
        clip.y1 + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

    ret = gdi_image_draw_id(clip.x1, clip.y1 + offset_y, IMG_ID_CAMCO_VIDEO_PROGRESS_BG);
    gdi_layer_reset_clip();

    /* draw progress fg according to the ratio */
    progress_width = (U32) ((mmi_camco_osd_skin_p->video_record.progress_width * ratio) / 100);

    gdi_layer_set_clip(
        clip.x1,
        clip.y1 + offset_y,
        clip.x1 + progress_width,
        clip.y1 + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

    ret = gdi_image_draw_id(clip.x1, clip.y1 + offset_y, IMG_ID_CAMCO_VIDEO_PROGRESS_FG);
    gdi_layer_reset_clip();

}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ratio       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_progress(U16 ratio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    U32 progress_width;
    GDI_RESULT ret;
    S32 num_width;
    S32 num_height;
    S32 img_width;
    S32 img_height;
    S32 offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &num_width, &num_height);
    gdi_image_get_dimension_id(IMG_ID_CAMCO_VIDEO_PROGRESS_BG, &img_width, &img_height);
    if (num_height > img_height)
    {
        offset_y = (num_height - img_height) >> 1;
    }

    /* draw progress bg */
    gdi_layer_set_clip(
        progress_p->progress_offset_x,
        progress_p->progress_offset_y + offset_y,
        progress_p->progress_offset_x + mmi_camco_osd_skin_p->video_record.progress_width,
        progress_p->progress_offset_y + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

    ret = gdi_image_draw_id(
            progress_p->progress_offset_x,
            progress_p->progress_offset_y + offset_y,
            IMG_ID_CAMCO_VIDEO_PROGRESS_BG);
    gdi_layer_reset_clip();

    /* draw progress fg according to the ratio */
    progress_width = (U32) ((mmi_camco_osd_skin_p->video_record.progress_width * ratio) / 100);

    gdi_layer_set_clip(
        progress_p->progress_offset_x,
        progress_p->progress_offset_y + offset_y,
        progress_p->progress_offset_x + progress_width,
        progress_p->progress_offset_y + mmi_camco_osd_skin_p->video_record.progress_height + offset_y);

    ret = gdi_image_draw_id(
            progress_p->progress_offset_x,
            progress_p->progress_offset_y + offset_y,
            IMG_ID_CAMCO_VIDEO_PROGRESS_FG);
    gdi_layer_reset_clip();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_bg_black
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_bg_black(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(mmi_camco_osd_p->base_layer_h);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_clear_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_clear_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

}

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_reduce_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_reduce_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            mmi_camco_osd_rec_screen_struct *scr_p = &(mmi_camco_osd_p->recording_screen);
            U16 re_offset_x = mmi_camco_osd_p->video_recoding_osd.rotate_softkey_area.x1;
            U16 re_offset_y = mmi_camco_osd_p->video_recoding_osd.rotate_softkey_area.y1;

            gdi_image_draw_id(
                scr_p->stop.offset_x - re_offset_x + img_press_shift(scr_p->stop.is_press),
                scr_p->stop.offset_y - re_offset_y + img_press_shift(scr_p->stop.is_press),
                scr_p->stop.img_id + img_press_shift(scr_p->stop.is_press));
        #ifdef __MMI_OP02_LEMEI__             
            if (mmi_camco_setting_app_switch_is_enable())
            {
        #endif  
            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
            {
                gdi_image_draw_id(
                    scr_p->pause.offset_x - re_offset_x + img_press_shift(scr_p->start.is_press),
                    scr_p->pause.offset_y - re_offset_y + img_press_shift(scr_p->start.is_press),
                    scr_p->pause.img_id + img_press_shift(scr_p->start.is_press));
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->start.offset_x - re_offset_x + img_press_shift(scr_p->start.is_press),
                    scr_p->start.offset_y - re_offset_y + img_press_shift(scr_p->start.is_press),
                    scr_p->start.img_id + img_press_shift(scr_p->start.is_press));
            }
        #ifdef __MMI_OP02_LEMEI__             
            }
        #endif                
            break;

        }
    }

}
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            mmi_camco_osd_cam_direct_setting_struct *scr_p = &(mmi_camco_osd_p->cam_direct_setting_screen);

            gdi_image_draw_id(
                scr_p->back.offset_x + img_press_shift(scr_p->back.is_press), 
                scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                scr_p->back.img_id + img_press_shift(scr_p->back.is_press));

            if (!mmi_camco_osd_is_in_smile_dect_scrn())
            {

                if (mmi_camco_setting_app_switch_is_enable())
                {
                    gdi_image_draw_id(
                        scr_p->switch_mode_top.offset_x,
                        scr_p->switch_mode_top.offset_y,
                        scr_p->switch_mode_top.img_id + img_press_shift(scr_p->switch_mode_top.is_press));
                    
                    if (scr_p->switch_mode_botton.is_press)
                    {
                        gdi_image_draw_id(
                            scr_p->switch_mode_botton.offset_x,
                            scr_p->switch_mode_botton.offset_y,
                            scr_p->switch_mode_botton.img_id - 2);
                    
                    }
                    else
                    {                                            
                        gdi_image_draw_id(
                            scr_p->switch_mode_botton.offset_x,
                            scr_p->switch_mode_botton.offset_y,
                            scr_p->switch_mode_botton.img_id - 1);
                    }                    
                }
                else
                {
                    gdi_image_draw_id(
                        scr_p->capture.offset_x + img_press_shift(scr_p->capture.is_press),
                        scr_p->capture.offset_y + img_press_shift(scr_p->capture.is_press),
                        scr_p->capture.img_id + img_press_shift(scr_p->capture.is_press));                
                }
                
                gdi_image_draw_id(
                    scr_p->ad_setting.offset_x + img_press_shift(scr_p->ad_setting.is_press),
                    scr_p->ad_setting.offset_y + img_press_shift(scr_p->ad_setting.is_press),
                    scr_p->ad_setting.img_id + img_press_shift(scr_p->ad_setting.is_press));

            }
            else
            {
                gdi_image_draw_id(
                    scr_p->capture.offset_x + img_press_shift(scr_p->capture.is_press),
                    scr_p->capture.offset_y + img_press_shift(scr_p->capture.is_press),
                    scr_p->capture.img_id + img_press_shift(scr_p->capture.is_press));
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            mmi_camco_osd_rec_direct_setting_struct *scr_p = &(mmi_camco_osd_p->rec_direct_setting_screen);

            gdi_image_draw_id(
                scr_p->back.offset_x + img_press_shift(scr_p->back.is_press), 
                scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                scr_p->back.img_id + img_press_shift(scr_p->back.is_press));

            if (mmi_camco_setting_app_switch_is_enable())
            {         
                gdi_image_draw_id(
                    scr_p->switch_mode_botton.offset_x,
                    scr_p->switch_mode_botton.offset_y,
                    scr_p->switch_mode_botton.img_id + img_press_shift(scr_p->switch_mode_botton.is_press));
                
                if (scr_p->switch_mode_top.is_press)
                {
                    gdi_image_draw_id(
                        scr_p->switch_mode_top.offset_x,
                        scr_p->switch_mode_top.offset_y,
                        scr_p->switch_mode_top.img_id - 2);
                }
                else
                {
                    gdi_image_draw_id(
                        scr_p->switch_mode_top.offset_x,
                        scr_p->switch_mode_top.offset_y,
                        scr_p->switch_mode_top.img_id - 1);
                }              
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->record.offset_x + img_press_shift(scr_p->record.is_press),
                    scr_p->record.offset_y + img_press_shift(scr_p->record.is_press),
                    scr_p->record.img_id + img_press_shift(scr_p->record.is_press));                
            }            
     
            gdi_image_draw_id(
                scr_p->ad_setting.offset_x + img_press_shift(scr_p->ad_setting.is_press),
                scr_p->ad_setting.offset_y + img_press_shift(scr_p->ad_setting.is_press),
                scr_p->ad_setting.img_id + img_press_shift(scr_p->ad_setting.is_press));

            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:      
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:              
        {
            mmi_camco_osd_storage_sel_struct *scr_p = &mmi_camco_osd_p->storage_select_screen;            

            gdi_image_draw_id(
                scr_p->back.offset_x + img_press_shift(scr_p->back.is_press), 
                scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                scr_p->back.img_id + img_press_shift(scr_p->back.is_press));

            break;
        }                       
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
                mmi_camco_osd_cam_direct_setting_struct *scr_p = &(mmi_camco_osd_p->cam_direct_setting_screen);

                gdi_image_draw_id(scr_p->back.offset_x, scr_p->back.offset_y, scr_p->back.img_id - 1);

            }
            else
            {
                mmi_camco_osd_advance_setting_struct *scr_p = &(mmi_camco_osd_p->advance_setting_screen);

                gdi_image_draw_id(
                    scr_p->back.offset_x + img_press_shift(scr_p->back.is_press), 
                    scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                    scr_p->back.img_id + img_press_shift(scr_p->back.is_press));
                
                gdi_image_draw_id(
                    scr_p->OK.offset_x + img_press_shift(scr_p->OK.is_press), 
                    scr_p->OK.offset_y + img_press_shift(scr_p->OK.is_press), 
                    scr_p->OK.img_id + img_press_shift(scr_p->OK.is_press));
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if (mmi_camco_osd_p->is_direct_setting)
            {
                mmi_camco_osd_rec_direct_setting_struct *scr_p = &(mmi_camco_osd_p->rec_direct_setting_screen);

                gdi_image_draw_id(scr_p->back.offset_x, scr_p->back.offset_y, scr_p->back.img_id - 1);

            }
            else
            {
                mmi_camco_osd_advance_setting_struct *scr_p = &(mmi_camco_osd_p->advance_setting_screen);

                gdi_image_draw_id(
                    scr_p->OK.offset_x + img_press_shift(scr_p->OK.is_press), 
                    scr_p->OK.offset_y + img_press_shift(scr_p->OK.is_press), 
                    scr_p->OK.img_id + img_press_shift(scr_p->OK.is_press));

                gdi_image_draw_id(
                    scr_p->back.offset_x + img_press_shift(scr_p->back.is_press), 
                    scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                    scr_p->back.img_id + img_press_shift(scr_p->back.is_press));
            }

            break;
        }
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_captured_struct *scr_p = &(mmi_camco_osd_p->captured_img_select_screen);

            gdi_image_draw_id(
                scr_p->back.offset_x + img_press_shift(scr_p->back.is_press), 
                scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                scr_p->back.img_id + img_press_shift(scr_p->back.is_press));

            break;
        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            mmi_camco_osd_forward_struct *scr_p = &(mmi_camco_osd_p->forward_screen);

            gdi_image_draw_id(scr_p->back.offset_x, scr_p->back.offset_y, scr_p->back.img_id - 1);

            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            if (mmi_camco_osd_p->stop_hint_mode != MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR &&
                mmi_camco_osd_p->stop_hint_mode != MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR &&
                mmi_camco_osd_p->stop_hint_mode != MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_ONLY)
            {
                mmi_camco_osd_captured_struct *scr_p = &(mmi_camco_osd_p->captured_screen);

                gdi_image_draw_id(
                     scr_p->back.offset_x + img_press_shift(scr_p->back.is_press),
                     scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                     scr_p->back.img_id + img_press_shift(scr_p->back.is_press));
            }
            else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
            {
                mmi_camco_osd_captured_struct *scr_p = &(mmi_camco_osd_p->captured_screen);

                gdi_image_draw_id(scr_p->back.offset_x, scr_p->back.offset_y, scr_p->back.img_id - 1);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {

            mmi_camco_osd_add_frame_struct *scr_p = &(mmi_camco_osd_p->add_frame);
            
            gdi_image_draw_id(
                 scr_p->back.offset_x + img_press_shift(scr_p->back.is_press),
                 scr_p->back.offset_y + img_press_shift(scr_p->back.is_press), 
                 scr_p->back.img_id + img_press_shift(scr_p->back.is_press));

            gdi_image_draw_id(
                 scr_p->ok.offset_x + img_press_shift(scr_p->ok.is_press),
                 scr_p->ok.offset_y + img_press_shift(scr_p->ok.is_press), 
                 scr_p->ok.img_id + img_press_shift(scr_p->ok.is_press));

            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            mmi_camco_osd_rec_screen_struct *scr_p = &(mmi_camco_osd_p->recording_screen);

            gdi_image_draw_id(
                scr_p->stop.offset_x + img_press_shift(scr_p->stop.is_press), 
                scr_p->stop.offset_y + img_press_shift(scr_p->stop.is_press), 
                scr_p->stop.img_id + img_press_shift(scr_p->stop.is_press));
        #ifdef __MMI_OP02_LEMEI__             
            if (mmi_camco_setting_app_switch_is_enable())
            {
        #endif    
            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
            {
                gdi_image_draw_id(
                    scr_p->pause.offset_x + img_press_shift(scr_p->start.is_press), 
                    scr_p->pause.offset_y + img_press_shift(scr_p->start.is_press), 
                    scr_p->pause.img_id + img_press_shift(scr_p->start.is_press));
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->start.offset_x + img_press_shift(scr_p->start.is_press), 
                    scr_p->start.offset_y + img_press_shift(scr_p->start.is_press), 
                    scr_p->start.img_id + img_press_shift(scr_p->start.is_press));                
            }
        #ifdef __MMI_OP02_LEMEI__             
            }
        #endif                
            break;

        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_panorama_shot_struct *scr_p = &(mmi_camco_osd_p->panorama_screen);

            gdi_image_draw_id(
                scr_p->OK.offset_x + img_press_shift(scr_p->OK.is_press), 
                scr_p->OK.offset_y + img_press_shift(scr_p->OK.is_press), 
                scr_p->OK.img_id + img_press_shift(scr_p->OK.is_press));

            gdi_image_draw_id(
                scr_p->cancel.offset_x + img_press_shift(scr_p->cancel.is_press), 
                scr_p->cancel.offset_y + img_press_shift(scr_p->cancel.is_press), 
                scr_p->cancel.img_id + img_press_shift(scr_p->cancel.is_press));

            break;            
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            mmi_camco_osd_panorama_shot_struct *scr_p = &(mmi_camco_osd_p->panorama_screen);

            gdi_image_draw_id(
                scr_p->OK.offset_x + img_press_shift(scr_p->OK.is_press), 
                scr_p->OK.offset_y + img_press_shift(scr_p->OK.is_press), 
                scr_p->OK.img_id + img_press_shift(scr_p->OK.is_press));

            gdi_image_draw_id(
                scr_p->capture.offset_x + img_press_shift(scr_p->capture.is_press), 
                scr_p->capture.offset_y + img_press_shift(scr_p->capture.is_press), 
                scr_p->capture.img_id + img_press_shift(scr_p->capture.is_press));

            gdi_image_draw_id(
                scr_p->cancel.offset_x + img_press_shift(scr_p->cancel.is_press), 
                scr_p->cancel.offset_y + img_press_shift(scr_p->cancel.is_press), 
                scr_p->cancel.img_id + img_press_shift(scr_p->cancel.is_press));

            break;
        }
        
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
            if(mmi_camco_osd_p->stop_hint_mode != MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR)
            {
                if(mmi_camco_osd_p->is_capturing)
                {
                    gdi_image_draw_id(
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.offset_x , 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.offset_y, 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.img_id+ img_press_shift(mmi_camco_osd_p->is_capturing));
                    gdi_image_draw_id(
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.offset_x, 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.offset_y, 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.img_id - 1);                
                }
                else
                {
                    gdi_image_draw_id(
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.offset_x, 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.offset_y, 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.img_id);
                    gdi_image_draw_id(
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.offset_x, 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.offset_y, 
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.img_id - 1);                  
                }                
            }
            break;            
        }
        
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_gen_storage_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_gen_storage_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx = 0;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    U8 drv;
    mmi_camco_osd_storage_sel_struct* scr_p = &mmi_camco_osd_p->storage_select_screen;
    mmi_camco_forward_option_skin_struct *option_skin_p = &(mmi_camco_osd_skin_p->forward_option);    
    U32 space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    scr_p->list_count = srv_fmgr_drivelist_count(drvlist);
            
    mmi_camco_osd_set_option_title(STR_GLOBAL_OPTIONS);
    
    for (idx = 0; idx < scr_p->list_count; idx++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        scr_p->storage_sel_list_enum[idx] = srv_fmgr_drv_get_type(drv); 
        scr_p->storage_sel_list[idx] = (U8*)get_string(srv_fmgr_drv_get_string(drv));       
        mmi_camco_osd_insert_option_item(idx, srv_fmgr_drv_get_string(drv));  

        if(scr_p->storage_sel_list_enum[idx] == SRV_FMGR_DRV_PHONE_TYPE)
            scr_p->item[idx].img_id = IMG_ID_CAMCO_STORAGE_SEL_PHONE;
        else
            scr_p->item[idx].img_id = IMG_ID_CAMCO_STORAGE_SEL_OTG;

        gdi_image_get_dimension_id(scr_p->item[idx].img_id, &scr_p->item[idx].width, &scr_p->item[idx].height);
        if(idx == 0)
            space = (scr_p->confirm_body.width - (scr_p->list_count * scr_p->item[0].width)) / (scr_p->list_count + 1);
        scr_p->item[idx].offset_y = option_skin_p->option_item.offset_y;
        scr_p->item[idx].offset_x = option_skin_p->option_item.offset_x = scr_p->confirm_body.offset_x + space * (idx + 1);        
    }     

    mmi_camco_osd_insert_option_done();

    
    
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_storage_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_storage_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_storage_sel_struct *scr_p = &(mmi_camco_osd_p->storage_select_screen);
    U8 i;
    S32 str_width, str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_draw_id(scr_p->confirm_body.offset_x, scr_p->confirm_body.offset_y, scr_p->confirm_body.img_id);
    for (i = 0; i < scr_p->list_count; i++)
    {
        if (scr_p->item[i].is_usable)
        {
            if (mmi_camco_osd_p->option_menulist.highlighted_idx == i)
            {
                gdi_image_draw_id(scr_p->item[i].offset_x, scr_p->item[i].offset_y, scr_p->item[i].img_id + 1);
            }
            else
            {
                gdi_image_draw_id(scr_p->item[i].offset_x, scr_p->item[i].offset_y, scr_p->item[i].img_id);
            }
        }
    }
    gui_measure_string(
        (UI_string_type) GetString(mmi_camco_osd_p->option_menulist.title_str_id),
        &str_width,
        &str_height);
    gui_move_text_cursor(
        scr_p->confirm_title.offset_x + ((scr_p->confirm_body.width - str_width) >> 1),
        scr_p->confirm_title.offset_y);
    gui_set_text_border_color(gui_color(0, 0, 0));
    gui_set_text_color(gui_color(255, 255, 255));
    gui_print_text((UI_string_type) GetString(mmi_camco_osd_p->option_menulist.title_str_id));

    gui_measure_string(
        (UI_string_type) GetString(mmi_camco_osd_p->option_menulist.item_list[mmi_camco_osd_p->option_menulist.highlighted_idx].str_id),
        &str_width,
        &str_height);
    gui_move_text_cursor(
        scr_p->confirm_sub_title.offset_x + ((scr_p->confirm_body.width - str_width) >> 1),
        scr_p->confirm_sub_title.offset_y);
    gui_set_text_border_color(gui_color(0, 0, 0));
    gui_set_text_color(gui_color(255, 255, 255));
    gui_print_text((UI_string_type)
                   GetString(mmi_camco_osd_p->option_menulist.
                             item_list[mmi_camco_osd_p->option_menulist.highlighted_idx].str_id));
    
}    


extern S32 mmi_camco_osd_get_selected_storage(void)
{
    mmi_camco_osd_storage_sel_struct *scr_p = &(mmi_camco_osd_p->storage_select_screen);
    U16 current_idx = mmi_camco_osd_get_option_hilite_idx();
    
    return scr_p->storage_sel_list_enum[current_idx];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_storage_sel_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_storage_sel_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->storage_select_screen.highlite_change_flag = MMI_FALSE;
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->storage_select_screen.back))
    {
        mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_TRUE;
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_STORAGE_SEL_BACK;
    }   
    else
    {
        for(i = 0; i < mmi_camco_osd_p->storage_select_screen.list_count ;i++)
        {
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->storage_select_screen.item[i]))
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_STORAGE_SEL_ITEM;
                if (mmi_camco_osd_p->option_menulist.highlighted_idx != i)
                {
                    mmi_camco_osd_p->storage_select_screen.highlite_change_flag = MMI_TRUE;
                }
                mmi_camco_osd_p->storage_select_screen.item[i].is_press = MMI_TRUE;
                mmi_camco_osd_p->option_menulist.highlighted_idx = i;
            }
        }        
    }        
    mmi_camco_osd_draw_osd();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_storage_sel_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_storage_sel_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_STORAGE_SEL_ITEM)
    {
        mmi_camco_osd_p->storage_select_screen.item[mmi_camco_osd_p->option_menulist.highlighted_idx].is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        if (!mmi_camco_osd_p->storage_select_screen.highlite_change_flag)
        {
            SEND_EVT(MMI_CAMCO_EVT_CHANGE_STORAGE, NULL);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_STORAGE_SEL_BACK)
    {
        mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_direct_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  touch_obj       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_direct_setting(mmi_camco_osd_touch_obj_enum touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        {
            mmi_camco_osd_cam_direct_setting_struct *scr_p = &(mmi_camco_osd_p->cam_direct_setting_screen);
            U8 i;
            S32 str_width, str_height;

            gdi_image_draw_id(
                scr_p->setting_wnd_body.offset_x,
                scr_p->setting_wnd_body.offset_y,
                scr_p->setting_wnd_body.img_id);            
                
            gui_measure_string((UI_string_type) GetString(mmi_camco_osd_p->active_tbl->setting_name), &str_width, &str_height);
            if (r2lMMIFlag)
            {            
            gui_move_text_cursor(
                    scr_p->setting_wnd_body.offset_x + scr_p->setting_wnd_body.width - ((scr_p->setting_wnd_body.width - str_width) >> 1),
                    scr_p->setting_title.offset_y);
            }
            else
            {
                gui_move_text_cursor(
                scr_p->setting_wnd_body.offset_x + ((scr_p->setting_wnd_body.width - str_width) >> 1),
                scr_p->setting_title.offset_y);
            }                
            gui_set_text_color(gui_color(255, 255, 255));
            gui_set_text_border_color(gui_color(0, 0, 0));
            gui_print_text((UI_string_type) GetString(mmi_camco_osd_p->active_tbl->setting_name));

            gui_measure_string(
                (UI_string_type) GetString(mmi_camco_osd_p->active_tbl->str_tbl[mmi_camco_osd_p->setting_menulist.highlighted_idx]),
                &str_width,
                &str_height);
            if (r2lMMIFlag)
            {            
            gui_move_text_cursor(
                    scr_p->setting_wnd_body.offset_x + scr_p->setting_wnd_body.width - ((scr_p->setting_wnd_body.width - str_width) >> 1),
                    scr_p->setting_sub_title.offset_y);
            }
            else
            {                
                gui_move_text_cursor(
                scr_p->setting_wnd_body.offset_x + ((scr_p->setting_wnd_body.width - str_width) >> 1),
                scr_p->setting_sub_title.offset_y);
            }                    
            gui_set_text_color(gui_color(255, 255, 255));
            gui_set_text_border_color(gui_color(0, 0, 0));
            gui_print_text((UI_string_type)GetString(mmi_camco_osd_p->active_tbl->str_tbl[mmi_camco_osd_p->setting_menulist.highlighted_idx]));

            for (i = 0; i < mmi_camco_osd_p->active_tbl->real_number; i++)
            {
                if (mmi_camco_osd_p->setting_menulist.highlighted_idx == i)
                {
                    gdi_image_draw_id(                                
                        mmi_camco_osd_p->active_setting_item[i].offset_x + 1,
                        mmi_camco_osd_p->active_setting_item[i].offset_y + 1,
                        mmi_camco_osd_p->active_setting_item[mmi_camco_osd_p->active_tbl->tbl[i]].img_id + 1);
                }
                else
                {
                    gdi_image_draw_id(
                        mmi_camco_osd_p->active_setting_item[i].offset_x,
                        mmi_camco_osd_p->active_setting_item[i].offset_y,
                        mmi_camco_osd_p->active_setting_item[mmi_camco_osd_p->active_tbl->tbl[i]].img_id);
                }
                if(mmi_camco_osd_p->setting_menulist.active_idx == i)
                {
                    gdi_image_draw_id(                                
                        mmi_camco_osd_p->active_setting_item[i].offset_x + 0.7 * mmi_camco_osd_p->active_setting_item[i].width,
                        mmi_camco_osd_p->active_setting_item[i].offset_y + 0.8 * mmi_camco_osd_p->active_setting_item[i].width,
                        IMG_ID_CAMCO_PICK);                
                }
                    
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            mmi_camco_osd_rec_direct_setting_struct *scr_p = &(mmi_camco_osd_p->rec_direct_setting_screen);
            U8 i;
            S32 str_width, str_height;

            gdi_image_draw_id(
                scr_p->setting_wnd_body.offset_x,
                scr_p->setting_wnd_body.offset_y,
                scr_p->setting_wnd_body.img_id);

            gui_measure_string((UI_string_type) GetString(mmi_camco_osd_p->active_tbl->setting_name), &str_width, &str_height);
            if (r2lMMIFlag)
            {            
            gui_move_text_cursor(
                    scr_p->setting_wnd_body.offset_x + scr_p->setting_wnd_body.width - ((scr_p->setting_wnd_body.width - str_width) >> 1),
                    scr_p->setting_title.offset_y);
            }
            else
            { 
                gui_move_text_cursor(
                scr_p->setting_wnd_body.offset_x + ((scr_p->setting_wnd_body.width - str_width) >> 1),
                scr_p->setting_title.offset_y);
            }                    
            gui_set_text_color(gui_color(255, 255, 255));
            gui_set_text_border_color(gui_color(0, 0, 0));
            gui_print_text((UI_string_type) GetString(mmi_camco_osd_p->active_tbl->setting_name));

            gui_measure_string(
                (UI_string_type) GetString(mmi_camco_osd_p->active_tbl->str_tbl[mmi_camco_osd_p->setting_menulist.highlighted_idx]),
                &str_width,
                &str_height);
            if (r2lMMIFlag)
            {            
            gui_move_text_cursor(
                    scr_p->setting_wnd_body.offset_x + scr_p->setting_wnd_body.width - ((scr_p->setting_wnd_body.width - str_width) >> 1),
                    scr_p->setting_sub_title.offset_y);
            }
            else
            {                 
                gui_move_text_cursor(
                scr_p->setting_wnd_body.offset_x + ((scr_p->setting_wnd_body.width - str_width) >> 1),
                scr_p->setting_sub_title.offset_y);
            }                    
            gui_set_text_color(gui_color(255, 255, 255));
            gui_set_text_border_color(gui_color(0, 0, 0));
            gui_print_text((UI_string_type)
                           GetString(mmi_camco_osd_p->active_tbl->str_tbl[mmi_camco_osd_p->setting_menulist.highlighted_idx]));

            for (i = 0; i < mmi_camco_osd_p->active_tbl->real_number; i++)
            {
                if (mmi_camco_osd_p->setting_menulist.highlighted_idx == i)
                {
                    gdi_image_draw_id(
                        mmi_camco_osd_p->active_setting_item[i].offset_x + 1,
                        mmi_camco_osd_p->active_setting_item[i].offset_y + 1,
                        mmi_camco_osd_p->active_setting_item[mmi_camco_osd_p->active_tbl->tbl[i]].img_id + 1);
                }
                else
                {
                    gdi_image_draw_id(
                        mmi_camco_osd_p->active_setting_item[i].offset_x,
                        mmi_camco_osd_p->active_setting_item[i].offset_y,
                        mmi_camco_osd_p->active_setting_item[mmi_camco_osd_p->active_tbl->tbl[i]].img_id);
                }
               if(mmi_camco_osd_p->setting_menulist.active_idx == i)
                {
                    gdi_image_draw_id(                                
                        mmi_camco_osd_p->active_setting_item[i].offset_x + 0.7 * mmi_camco_osd_p->active_setting_item[i].width,
                        mmi_camco_osd_p->active_setting_item[i].offset_y + 0.8 * mmi_camco_osd_p->active_setting_item[i].width,
                        IMG_ID_CAMCO_PICK);                
                }                
            } 

            break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_l1_scrolling_text_stop
 * DESCRIPTION
 *  This function handles scrolling text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_l1_scrolling_text_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->is_l1_scrolling)
    {
        gui_scrolling_text_stop(&mmi_camco_osd_p->l1_scrolling_current_hilite_setting_value);
        mmi_camco_osd_p->is_l1_scrolling = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_l1_scrolling_text_handle
 * DESCRIPTION
 *  This function handles scrolling text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_l1_scrolling_text_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_is_horz_UI())
    {
        mmi_camco_osd_advance_setting_struct *scr_p = &mmi_camco_osd_p->advance_setting_screen;
        U8 idx = mmi_camco_osd_p->scrolling_idx;

        /* Horizontal */
        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
        gdi_layer_lock_frame_buffer();

        /* to judge if need to redraw bg, because the FW will stay for a while and then scroll */
        /* if draw bg direct, there will be just bg no text for a while */
        if (mmi_camco_osd_p->l1_scrolling_current_hilite_setting_value.scroll_counter == 0)
        {
            if (idx < scr_p->Level1_setting_item_count - 1)
            {
                gdi_layer_set_clip(
                    scr_p->Level1_setting_wnd_value[idx].offset_x,
                    scr_p->Level1_setting_wnd_value[idx].offset_y,
                    scr_p->Level1_setting_wnd_icon[idx].offset_x - 2,
                    scr_p->Level1_setting_wnd_item[idx + 1].offset_y);
            }
            else
            {
                gdi_layer_set_clip(
                    scr_p->Level1_setting_wnd_value[idx].offset_x,
                    scr_p->Level1_setting_wnd_value[idx].offset_y,
                    scr_p->Level1_setting_wnd_icon[idx].offset_x - 2,
                    scr_p->Level1_setting_wnd_botton.offset_y - 2);
            }

            gdi_image_draw_id(
                scr_p->Level1_setting_wnd_item[idx].offset_x,
                scr_p->Level1_setting_wnd_item[idx].offset_y,
                scr_p->Level1_setting_wnd_item[idx].img_id);
            gdi_image_draw_id(
                scr_p->Level1_setting_wnd_item[idx].offset_x,
                scr_p->Level1_setting_wnd_item[idx].offset_y,
                scr_p->Level1_setting_wnd_hilite_img);

            gdi_layer_reset_clip();
        }
        gui_handle_scrolling_text(&mmi_camco_osd_p->l1_scrolling_current_hilite_setting_value);

        gdi_layer_unlock_frame_buffer();
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
        gdi_layer_toggle_double();

        mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

        gdi_layer_pop_and_restore_active();
        mmi_camco_osd_blt();

    }
    else
    {
        gui_set_font(&MMI_small_font);    
    
        /* Subcamera - Portrait */
        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
        //gdi_layer_toggle_double();
        gui_handle_scrolling_text(&mmi_camco_osd_p->l1_scrolling_current_hilite_setting_value);
        gdi_layer_pop_and_restore_active();

        gui_set_font(&MMI_default_font);    

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_l1_scrolling_text_redraw_bg
 * DESCRIPTION
 *  This function clear the rect. of the scrolling text .
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_l1_scrolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_advance_setting_struct *scr_p = &(mmi_camco_osd_p->advance_setting_screen);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_camco_osd_is_horz_UI())
    {
        /* it will be done before call gui_handle_scrolling_text */
        /* or the clip will be wrong because the function is call in gui_handle_scrolling_text */
    }
    else
    {
        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);

        gdi_image_draw_id(
            scr_p->Level1_setting_wnd_item[mmi_camco_osd_p->scrolling_idx].offset_x,
            scr_p->Level1_setting_wnd_item[mmi_camco_osd_p->scrolling_idx].offset_y,
            scr_p->Level1_setting_wnd_hilite_img);

        gdi_layer_pop_and_restore_active();

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_advance_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_advance_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    mmi_camco_osd_advance_setting_struct *scr_p = &(mmi_camco_osd_p->advance_setting_screen);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_l1_scrolling_text_stop();

    if(!mmi_camco_osd_is_horz_UI())    
    {
        gui_set_font(&MMI_small_font);        
    }
    /* ============================================================== */
    /*                                                       draw tab and titile                                                        */
    /* ============================================================== */
    if (MMI_CAMCO_SETTING_MAINLIST_PRIMARY == mmi_camco_setting_get_mainlist_type())
    {
        gdi_image_draw_id(scr_p->main_tab.offset_x, scr_p->main_tab.offset_y, scr_p->main_tab.img_id);
        gdi_image_draw_id(scr_p->misc_tab.offset_x, scr_p->misc_tab.offset_y, scr_p->misc_tab.img_id);
    }
    else
    {
        gdi_image_draw_id(scr_p->main_tab.offset_x, scr_p->main_tab.offset_y, scr_p->misc_tab.img_id);
        gdi_image_draw_id(scr_p->misc_tab.offset_x, scr_p->misc_tab.offset_y, scr_p->main_tab.img_id);
    }

    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING)
    {
        gui_measure_string(
            (UI_string_type) GetString(STR_ID_CAMCO_FTE_SETTING_TAB_CAMERA), 
            &str_width, 
            &str_height);        
    }        
    else
    {
        gui_measure_string(
            (UI_string_type) GetString(STR_ID_CAMCO_FTE_SETTING_TAB_VIDEO), 
            &str_width, 
            &str_height);        
    }                
    
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            scr_p->main_tab.offset_x + scr_p->main_tab.width - (scr_p->main_tab_title.offset_x - scr_p->main_tab.offset_x),
            scr_p->main_tab_title.offset_y);
    }
    else
    {
        gui_move_text_cursor(
            scr_p->main_tab.offset_x + ((scr_p->main_tab.width - str_width) >>1), 
            scr_p->main_tab_title.offset_y);
    }
    
    if (scr_p->menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        gui_set_text_color(gui_color(255, 255, 255));
    else
        gui_set_text_color(gui_color(128, 128, 128));
    gui_set_text_border_color(gui_color(0, 0, 0));
    
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING)
        gui_print_text((UI_string_type) GetString(STR_ID_CAMCO_FTE_SETTING_TAB_CAMERA));
    else
        gui_print_text((UI_string_type) GetString(STR_ID_CAMCO_FTE_SETTING_TAB_VIDEO));

    gui_measure_string(
        (UI_string_type) GetString(STR_ID_CAMCO_FTE_SETTING_TAB_MISC), 
        &str_width, 
        &str_height);   

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            scr_p->misc_tab.offset_x + scr_p->misc_tab.width - (scr_p->misc_tab_title.offset_x - scr_p->misc_tab.offset_x),
            scr_p->misc_tab_title.offset_y);
    }
    else
    {
        gui_move_text_cursor(
            scr_p->misc_tab.offset_x + ((scr_p->misc_tab.width - str_width) >>1), 
            scr_p->misc_tab_title.offset_y);
    }

    if (scr_p->menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        gui_set_text_color(gui_color(255, 255, 255));
    else
        gui_set_text_color(gui_color(128, 128, 128));
    gui_set_text_border_color(gui_color(0, 0, 0));
    gui_print_text((UI_string_type) GetString(STR_ID_CAMCO_FTE_SETTING_TAB_MISC));

    /* ============================================================== */
    /*                                                       draw Level 1 menu                                                       */
    /* ============================================================== */
    if (scr_p->menu_status >= MMI_CAMCO_OSD_MENU_LEVEL1)
    {
        U8 i;
        U16 scrolling_y;
        U16 scrolling_unit =
            (scr_p->Level1_scrolling_bar_real_region[1] -
             scr_p->Level1_scrolling_bar_real_region[0]) /
            mmi_camco_osd_p->iconlist.icon_count;
        S32 remain_bar_size =
            (scr_p->Level1_scrolling_bar_real_region[1] -
             scr_p->Level1_scrolling_bar_real_region[0]) -
            (scrolling_unit * mmi_camco_osd_p->iconlist.icon_count);
        S32 str_width, str_height;
        U16 icon_display_count;

        scr_p->Level1_scrolling_bar_ind_size = scrolling_unit * scr_p->Level1_setting_item_count;

        scr_p->Level1_scrolling_bar_ind_y =
            scr_p->Level1_scrolling_bar_real_region[0] +
            scrolling_unit * mmi_camco_osd_p->iconlist.first_disp_idx;

        scrolling_y = scr_p->Level1_scrolling_bar_ind_y;

        gdi_image_draw_id(
            scr_p->Level1_setting_wnd_top1.offset_x,
            scr_p->Level1_setting_wnd_top1.offset_y,
            scr_p->Level1_setting_wnd_top1.img_id);
        gdi_image_draw_id(
            scr_p->Level1_setting_wnd_top2.offset_x,
            scr_p->Level1_setting_wnd_top2.offset_y,
            scr_p->Level1_setting_wnd_top2.img_id);
        /* ============================================================== */
        /*                                                       draw scrolling bar                                                         */
        /* ============================================================== */        
        if (mmi_camco_osd_p->iconlist.icon_count > scr_p->Level1_setting_item_count)
        {
            gdi_image_draw_id(
                scr_p->Level1_scrolling_bar.offset_x,
                scr_p->Level1_scrolling_bar.offset_y,
                scr_p->Level1_scrolling_bar.img_id);
            if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE)
            {
                gdi_image_draw_id(
                    scr_p->Level1_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_top.img_id + 1);
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->Level1_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_top.img_id);
            }
            scrolling_y += scr_p->scrolling_bar_ind_top.height;
            if (scr_p->Level1_scrolling_bar_ind_size >
                scr_p->scrolling_bar_ind_top.height + scr_p->scrolling_bar_ind_bottom.height)
            {
                U16 acc_size = scr_p->scrolling_bar_ind_top.height + scr_p->scrolling_bar_ind_bottom.height;

                while (acc_size < scr_p->Level1_scrolling_bar_ind_size)
                {
                    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL ||
                        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE)
                    {
                        gdi_image_draw_id(
                            scr_p->Level1_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id + 1);
                    }
                    else
                    {
                        gdi_image_draw_id(
                            scr_p->Level1_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id);
                    }
                    acc_size += scr_p->scrolling_bar_ind_body.height;
                    scrolling_y += scr_p->scrolling_bar_ind_body.height;
                }

                while (remain_bar_size > 0)
                {
                    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL ||
                        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE)
                    {
                        gdi_image_draw_id(
                            scr_p->Level1_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id + 1);
                    }
                    else
                    {
                        gdi_image_draw_id(
                            scr_p->Level1_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id);
                    }
                    scrolling_y += scr_p->scrolling_bar_ind_body.height;
                    remain_bar_size -= scr_p->scrolling_bar_ind_body.height;
                }

            }
            if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE)
            {
                gdi_image_draw_id(
                    scr_p->Level1_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_bottom.img_id + 1);
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->Level1_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_bottom.img_id);
            }
            scr_p->Level1_scrolling_bar_ind.offset_y = scr_p->Level1_scrolling_bar_ind_y;
            scr_p->Level1_scrolling_bar_ind_region.offset_y = scr_p->Level1_scrolling_bar_ind.offset_y - 5;
            scr_p->Level1_scrolling_bar_ind_region.height = scr_p->Level1_scrolling_bar_ind_size + 10;
            scr_p->Level1_scrolling_bar_ind_region.is_usable = MMI_TRUE;
        }
        else
        {
            scr_p->Level1_scrolling_bar_ind_region.is_usable = MMI_FALSE;
        }
        /* ============================================================== */
        /*                                                       draw menu item                                                           */
        /* ============================================================== */                
        gdi_layer_set_clip(
            scr_p->Level1_setting_wnd_top1.offset_x,
            scr_p->Level1_setting_wnd_top1.offset_y + scr_p->Level1_setting_wnd_top1.height,
            scr_p->Level1_setting_wnd_botton.offset_x + scr_p->Level1_setting_wnd_botton.width,
            scr_p->Level1_setting_wnd_botton.offset_y);

        if (mmi_camco_osd_p->iconlist.icon_count > scr_p->Level1_setting_item_count)
            icon_display_count = scr_p->Level1_setting_item_count;
        else
            icon_display_count = mmi_camco_osd_p->iconlist.icon_count;

        for (i = 0; i < icon_display_count; i++)
        {
            if (mmi_camco_osd_p->iconlist.icon_count > scr_p->Level1_setting_item_count)
            {
                gdi_image_draw_id(
                    scr_p->Level1_setting_wnd_item[i].offset_x,
                    scr_p->Level1_setting_wnd_item[i].offset_y,
                    scr_p->Level1_setting_wnd_item[i].img_id);
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->Level1_setting_wnd_item_no_scroll[i].offset_x,
                    scr_p->Level1_setting_wnd_item_no_scroll[i].offset_y,
                    scr_p->Level1_setting_wnd_item_no_scroll[i].img_id);

            }

            if (mmi_camco_osd_p->iconlist.highlighted_idx == mmi_camco_osd_p->iconlist.first_disp_idx + i)
            {
                gui_set_text_color(gui_color(0, 0, 0));
                if (mmi_camco_osd_p->iconlist.icon_count > scr_p->Level1_setting_item_count)
                {
                    gdi_image_draw_id(
                        scr_p->Level1_setting_wnd_item[i].offset_x,
                        scr_p->Level1_setting_wnd_item[i].offset_y,
                        scr_p->Level1_setting_wnd_hilite_img);
                }
                else
                {
                    gdi_image_draw_id(
                        scr_p->Level1_setting_wnd_item_no_scroll[i].offset_x,
                        scr_p->Level1_setting_wnd_item_no_scroll[i].offset_y,
                        scr_p->Level1_setting_wnd_hilite_no_scroll_img);

                }
                mmi_camco_osd_p->last_l1_menu_hilite_str_id =
                    mmi_camco_osd_p->iconlist.icon_list[mmi_camco_osd_p->iconlist.first_disp_idx + i].str_id;
                mmi_camco_osd_p->scrolling_idx = i;
            }
            else
            {
                if (scr_p->menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
                    gui_set_text_color(gui_color(255, 255, 255));
                else
                    gui_set_text_color(gui_color(128, 128, 128));
            }
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(
                    ((scr_p->Level_setting_valuse_offset_x) - (scr_p->Level1_setting_wnd_attr[i].offset_x - scr_p->Level1_setting_wnd_item[i].offset_x)),
                    scr_p->Level1_setting_wnd_attr[i].offset_y);
            }
            else
            {
                gui_move_text_cursor(
                    scr_p->Level1_setting_wnd_attr[i].offset_x,
                    scr_p->Level1_setting_wnd_attr[i].offset_y);
            }
            gui_set_text_border_color(gui_color(0, 0, 0));

            gui_print_text((UI_string_type)
                           GetString(mmi_camco_osd_p->iconlist.icon_list[mmi_camco_osd_p->iconlist.first_disp_idx + i].
                                     str_id));

            if (mmi_camco_osd_p->iconlist.icon_list[mmi_camco_osd_p->iconlist.first_disp_idx + i].str_id !=
                STR_ID_CAMCO_DEFAULT)
            {
                if (mmi_camco_osd_p->iconlist.highlighted_idx == mmi_camco_osd_p->iconlist.first_disp_idx + i &&
                    (scr_p->menu_status == MMI_CAMCO_OSD_MENU_LEVEL1))
				{

                    gui_create_scrolling_text(
                        &mmi_camco_osd_p->l1_scrolling_current_hilite_setting_value,
                        scr_p->Level1_setting_wnd_value[i].offset_x,
                        scr_p->Level1_setting_wnd_value[i].offset_y,
                        scr_p->Level1_setting_wnd_icon[i].offset_x - scr_p->Level1_setting_wnd_value[i].offset_x - 2,
                        scr_p->Level1_setting_wnd_item[i].height,
                        (UI_string_type) GetString(mmi_camco_osd_p->iconlist.icon_list_cur_value[mmi_camco_osd_p->iconlist.first_disp_idx + i]),
                        mmi_camco_osd_l1_scrolling_text_handle,
                        mmi_camco_osd_l1_scrolling_text_redraw_bg,
                        gui_color(0, 0, 0),
                        gui_color(0, 0, 0));
                    mmi_camco_osd_p->is_l1_scrolling = MMI_TRUE;

                    /* no blt */
                    if (mmi_camco_osd_is_horz_UI())
                    {
                        gdi_layer_lock_frame_buffer();
                    }
                    gui_show_scrolling_text(&mmi_camco_osd_p->l1_scrolling_current_hilite_setting_value);
                    if (mmi_camco_osd_is_horz_UI())
                    {
                        gdi_layer_unlock_frame_buffer();
                    }

                }
                else
                {

                    gdi_layer_set_clip(
                        scr_p->Level1_setting_wnd_value[i].offset_x,
                        scr_p->Level1_setting_wnd_item[i].offset_y,
                        scr_p->Level1_setting_wnd_icon[i].offset_x + 1,
                        scr_p->Level1_setting_wnd_item[i].offset_y + scr_p->Level1_setting_wnd_item[i].height);
                    if (r2lMMIFlag)
                    {
                        gui_move_text_cursor(
                            ((scr_p->Level1_setting_wnd_item[i].offset_x + scr_p->Level1_setting_wnd_item[i].width) - (scr_p->Level1_setting_wnd_item[i].offset_x + scr_p->Level1_setting_wnd_item[i].width -scr_p->Level1_setting_wnd_icon[i].offset_x)-(scr_p->Level1_setting_wnd_value[i].offset_x - scr_p->Level_setting_valuse_offset_x)),
                            scr_p->Level1_setting_wnd_value[i].offset_y);

                    }
                    else
                    {
                        gui_move_text_cursor(
                            scr_p->Level1_setting_wnd_value[i].offset_x,
                            scr_p->Level1_setting_wnd_value[i].offset_y);
                    }

                    gui_set_text_border_color(gui_color(0, 0, 0));
                    gui_print_text((UI_string_type)
                                   GetString(mmi_camco_osd_p->iconlist.
                                             icon_list_cur_value[mmi_camco_osd_p->iconlist.first_disp_idx + i]));

                    gdi_layer_set_clip(
                        scr_p->Level1_setting_wnd_top1.offset_x,
                        scr_p->Level1_setting_wnd_top1.offset_y + scr_p->Level1_setting_wnd_top1.height,
                        scr_p->Level1_setting_wnd_botton.offset_x + scr_p->Level1_setting_wnd_botton.width,
                        scr_p->Level1_setting_wnd_botton.offset_y);
                }
            }
            if(mmi_camco_osd_is_horz_UI())
            {
                if (mmi_camco_osd_p->iconlist.icon_count > scr_p->Level1_setting_item_count)
                {
                    gdi_image_draw_id(
                        scr_p->Level1_setting_wnd_icon[i].offset_x,
                        scr_p->Level1_setting_wnd_icon[i].offset_y,
                        mmi_camco_osd_p->iconlist.icon_list_cur_value_img[mmi_camco_osd_p->iconlist.first_disp_idx + i]);
                }
                else
                {
                    gdi_image_draw_id(
                        scr_p->Level1_setting_wnd_icon[i].offset_x + scr_p->Level1_scrolling_bar.width,
                        scr_p->Level1_setting_wnd_icon[i].offset_y,
                        mmi_camco_osd_p->iconlist.icon_list_cur_value_img[mmi_camco_osd_p->iconlist.first_disp_idx + i]);
                }
            }
        }
        if (mmi_camco_osd_p->iconlist.icon_count < scr_p->Level1_setting_item_count)
        {
            for (i = mmi_camco_osd_p->iconlist.icon_count;
                 i < mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count; i++)
            {
                gdi_image_draw_id(
                    scr_p->Level1_setting_wnd_item_no_scroll[i].offset_x,
                    scr_p->Level1_setting_wnd_item_no_scroll[i].offset_y,
                    scr_p->Level1_setting_wnd_item_no_scroll[i].img_id);
            }
        }
        gdi_layer_reset_clip();
        gdi_image_draw_id(
            scr_p->Level1_setting_wnd_botton.offset_x,
            scr_p->Level1_setting_wnd_botton.offset_y - 1,
            scr_p->Level1_setting_wnd_botton.img_id);

    }

    /* ============================================================== */
    /* draw Level 2 menu                                              */
    /* ============================================================== */    
    if (scr_p->menu_status >= MMI_CAMCO_OSD_MENU_LEVEL2)
    {
        U8 i;
        U16 start_pos_y = 0;
        U16 scrolling_y;
        U16 scrolling_unit;
        S32 remain_bar_size;

        if (scr_p->Level2_setting_item_count > mmi_camco_osd_p->act_menulist_p->disp_item_count)
        {
            start_pos_y =
                scr_p->Level2_setting_wnd_botton.offset_y - (scr_p->Level2_setting_wnd_top.offset_y +
                                                             scr_p->Level2_setting_wnd_top.height) -
                mmi_camco_osd_p->act_menulist_p->disp_item_count * scr_p->Level2_setting_wnd_item[0].height;
        }

        gdi_layer_set_clip(
            scr_p->Level2_setting_wnd_top.offset_x,
            scr_p->Level2_setting_wnd_top.offset_y + start_pos_y,
            scr_p->Level2_setting_wnd_botton.offset_x + scr_p->Level2_setting_wnd_botton.width,
            scr_p->Level2_setting_wnd_botton.offset_y + scr_p->Level2_setting_wnd_botton.height);
        
        /* ============================================================== */
        /* draw scrolling bar                                             */
        /* ============================================================== */        
        if (mmi_camco_osd_p->setting_menulist.item_count > scr_p->Level2_setting_item_count)
        {
            scrolling_unit =
                (scr_p->Level2_scrolling_bar_real_region[1] -
                 scr_p->Level2_scrolling_bar_real_region[0]) /
                mmi_camco_osd_p->setting_menulist.item_count;

            remain_bar_size =
                (scr_p->Level2_scrolling_bar_real_region[1] -
                 scr_p->Level2_scrolling_bar_real_region[0]) -
                (scrolling_unit * mmi_camco_osd_p->setting_menulist.item_count);

            scr_p->Level2_scrolling_bar_ind_size = scrolling_unit * scr_p->Level2_setting_item_count;

            scr_p->Level2_scrolling_bar_ind_y =
                scr_p->Level2_scrolling_bar_real_region[0] +
                scrolling_unit * mmi_camco_osd_p->setting_menulist.first_disp_idx;

            scrolling_y = scr_p->Level2_scrolling_bar_ind_y;

            gdi_image_draw_id(
                scr_p->Level2_scrolling_bar.offset_x,
                scr_p->Level2_scrolling_bar.offset_y + start_pos_y,
                scr_p->Level2_scrolling_bar.img_id);
            if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE)
            {
                gdi_image_draw_id(
                    scr_p->Level2_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_top.img_id + 1);
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->Level2_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_top.img_id);
            }
            scrolling_y += scr_p->scrolling_bar_ind_top.height;
            if (scr_p->Level2_scrolling_bar_ind_size >
                scr_p->scrolling_bar_ind_top.height + scr_p->scrolling_bar_ind_bottom.height)
            {
                U16 acc_size = scr_p->scrolling_bar_ind_top.height + scr_p->scrolling_bar_ind_bottom.height;

                while (acc_size < scr_p->Level2_scrolling_bar_ind_size)
                {
                    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL ||
                        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE)
                    {
                        gdi_image_draw_id(
                            scr_p->Level2_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id + 1);
                    }
                    else
                    {
                        gdi_image_draw_id(
                            scr_p->Level2_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id);
                    }
                    acc_size += scr_p->scrolling_bar_ind_body.height;
                    scrolling_y += scr_p->scrolling_bar_ind_body.height;
                }
                while (remain_bar_size > 0)
                {
                    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL ||
                        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE)
                    {
                        gdi_image_draw_id(
                            scr_p->Level2_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id + 1);
                    }
                    else
                    {
                        gdi_image_draw_id(
                            scr_p->Level2_scrolling_bar_ind.offset_x,
                            scrolling_y,
                            scr_p->scrolling_bar_ind_body.img_id);
                    }
                    scrolling_y += scr_p->scrolling_bar_ind_body.height;
                    remain_bar_size -= scr_p->scrolling_bar_ind_body.height;
                }
            }
            if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE)
            {
                gdi_image_draw_id(
                    scr_p->Level2_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_bottom.img_id + 1);
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->Level2_scrolling_bar_ind.offset_x,
                    scrolling_y,
                    scr_p->scrolling_bar_ind_bottom.img_id);
            }
            scr_p->Level2_scrolling_bar_ind.offset_y = scr_p->Level2_scrolling_bar_ind_y;
            scr_p->Level2_scrolling_bar_ind_region.offset_y = scr_p->Level2_scrolling_bar_ind.offset_y - 5;
            scr_p->Level2_scrolling_bar_ind_region.height = scr_p->Level2_scrolling_bar_ind_size + 10;
            scr_p->Level2_scrolling_bar_ind_region.is_usable = MMI_TRUE;

        }
        else
        {
            scr_p->Level2_scrolling_bar_ind_region.is_usable = MMI_FALSE;
        }
        /* ============================================================== */
        /* draw menu item                                                 */
        /* ============================================================== */                        
        scr_p->menu_pos_y_shift = start_pos_y;
        gdi_image_draw_id(
            scr_p->Level2_setting_wnd_top.offset_x,
            scr_p->Level2_setting_wnd_top.offset_y + scr_p->menu_pos_y_shift,
            scr_p->Level2_setting_wnd_top.img_id);

        for (i = 0; i < mmi_camco_osd_p->act_menulist_p->disp_item_count; i++)
        {
            U16 idx = i + mmi_camco_osd_p->act_menulist_p->first_disp_idx;

            if (mmi_camco_osd_p->setting_menulist.item_count > scr_p->Level2_setting_item_count)
            {
                gdi_image_draw_id(
                    scr_p->Level2_setting_wnd_item[i].offset_x,
                    scr_p->Level2_setting_wnd_item[i].offset_y + start_pos_y,
                    scr_p->Level2_setting_wnd_item[i].img_id);
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->Level2_setting_wnd_item_no_scroll[i].offset_x,
                    scr_p->Level2_setting_wnd_item_no_scroll[i].offset_y + start_pos_y,
                    scr_p->Level2_setting_wnd_item_no_scroll[i].img_id);
            }

            if (mmi_camco_osd_p->act_menulist_p->highlighted_idx == idx)
            {
                gui_set_text_color(gui_color(0, 0, 0));
                if (mmi_camco_osd_p->setting_menulist.item_count > scr_p->Level2_setting_item_count)
                {
                    gdi_image_draw_id(
                        scr_p->Level2_setting_wnd_item[i].offset_x,
                        scr_p->Level2_setting_wnd_item[i].offset_y + start_pos_y,
                        scr_p->Level2_setting_wnd_hilite_img);
                }
                else
                {
                    gdi_image_draw_id(
                        scr_p->Level2_setting_wnd_item[i].offset_x,
                        scr_p->Level2_setting_wnd_item[i].offset_y + start_pos_y,
                        scr_p->Level2_setting_wnd_hilite_no_scroll_img);
                }
            }
            else
            {
                if (scr_p->menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
                    gui_set_text_color(gui_color(255, 255, 255));
                else
                    gui_set_text_color(gui_color(128, 128, 128));
            }

            if (mmi_camco_osd_p->act_menulist_p->active_idx == idx)
            {
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
             #endif
                {
                    gdi_image_draw_id(
                        scr_p->Level2_setting_wnd_check[i].offset_x,
                        scr_p->Level2_setting_wnd_check[i].offset_y + start_pos_y,
                        scr_p->Level2_setting_wnd_check[i].img_id);
                }

            }

            if (r2lMMIFlag)
            {
                gui_move_text_cursor(
                    scr_p->Level2_setting_wnd_item[i].offset_x + scr_p->Level2_setting_wnd_item[i].width -(scr_p->Level2_setting_wnd_item[i].offset_x + scr_p->Level2_setting_wnd_item[i].width -  scr_p->Level2_setting_wnd_icon[i].offset_x)- (scr_p->Level2_setting_wnd_value[i].offset_x - scr_p->Level2_setting_wnd_check[i].offset_x - scr_p->Level2_setting_wnd_check[i].width),
                    scr_p->Level2_setting_wnd_value[i].offset_y + start_pos_y);
            }
            else
            {
                gui_move_text_cursor(
                    scr_p->Level2_setting_wnd_value[i].offset_x,
                    scr_p->Level2_setting_wnd_value[i].offset_y + start_pos_y);
            }

            gui_set_text_border_color(gui_color(0, 0, 0));
            gui_print_text((UI_string_type) GetString(mmi_camco_osd_p->act_menulist_p->item_list[idx].str_id));

            if (mmi_camco_osd_p->act_menulist_p->item_list[idx].status_img_id != 0 && mmi_camco_osd_is_horz_UI())
            {
            #if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
                {
                    if (mmi_camco_osd_p->setting_menulist.item_count > scr_p->Level2_setting_item_count)
                    {
                        gdi_image_draw_id(
                            scr_p->Level2_setting_wnd_icon[i].offset_x,
                            scr_p->Level2_setting_wnd_icon[i].offset_y + start_pos_y,
                            mmi_camco_osd_p->act_menulist_p->item_list[idx].status_img_id);
                    }
                    else
                    {
                        gdi_image_draw_id(
                            scr_p->Level2_setting_wnd_icon[i].offset_x + scr_p->Level2_scrolling_bar.width,
                            scr_p->Level2_setting_wnd_icon[i].offset_y + start_pos_y,
                            mmi_camco_osd_p->act_menulist_p->item_list[idx].status_img_id);
                    }
                }
            }

        }
        gdi_image_draw_id(
            scr_p->Level2_setting_wnd_botton.offset_x,
            scr_p->Level2_setting_wnd_botton.offset_y,
            scr_p->Level2_setting_wnd_botton.img_id);
        gdi_layer_reset_clip();

    }
    if(!mmi_camco_osd_is_horz_UI())    
    {
        gui_set_font(&MMI_default_font);    
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_toolbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_toolbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_cam_direct_setting_struct *cam_dir_setting_p = &mmi_camco_osd_p->cam_direct_setting_screen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_camco_osd_p->osd_state)
    {

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            mmi_camco_osd_cam_direct_setting_struct *scr_p = &(mmi_camco_osd_p->cam_direct_setting_screen);

        #ifdef DUAL_CAMERA_SUPPORT            
            gdi_image_draw_id(
                mmi_camco_osd_p->sensor_switcher.offset_x + img_press_shift(mmi_camco_osd_p->sensor_switcher.is_press),
                mmi_camco_osd_p->sensor_switcher.offset_y + img_press_shift(mmi_camco_osd_p->sensor_switcher.is_press),
                mmi_camco_osd_p->sensor_switcher.img_id + img_press_shift(mmi_camco_osd_p->sensor_switcher.is_press));
        #endif
        
            gdi_image_draw_id(
                scr_p->scene_mode.offset_x + img_press_shift(scr_p->scene_mode.is_press),
                scr_p->scene_mode.offset_y + img_press_shift(scr_p->scene_mode.is_press),
                scr_p->scene_mode.img_id + img_press_shift(scr_p->scene_mode.is_press));
        #ifdef MMI_CAMCO_SUPPORT_FLASH
            if (mmi_camco_setting_flash_is_enable())
                gdi_image_draw_id(
                    scr_p->flash.offset_x + img_press_shift(scr_p->flash.is_press),
                    scr_p->flash.offset_y + img_press_shift(scr_p->flash.is_press),
                    scr_p->flash.img_id + img_press_shift(scr_p->flash.is_press));
            else
                gdi_image_draw_id(scr_p->flash.offset_x, scr_p->flash.offset_y, scr_p->flash.img_id - 1);
        #else /* MMI_CAMCO_SUPPORT_FLASH */ 
            if (mmi_camco_setting_selftime_is_enable())
                gdi_image_draw_id(
                    scr_p->flash.offset_x + img_press_shift(scr_p->flash.is_press),
                    scr_p->flash.offset_y + img_press_shift(scr_p->flash.is_press),
                    scr_p->flash.img_id + img_press_shift(scr_p->flash.is_press));
            else
                gdi_image_draw_id(scr_p->flash.offset_x, scr_p->flash.offset_y, scr_p->flash.img_id - 1);
        #endif /* MMI_CAMCO_SUPPORT_FLASH */ 
            if(mmi_camco_osd_p->is_show_zoom)
            {
                gdi_image_draw_id(
                    scr_p->zoom.offset_x,
                    scr_p->zoom.offset_y,
                    scr_p->zoom.img_id - 1);
            }
            else
            {        
                gdi_image_draw_id(
                    scr_p->zoom.offset_x + img_press_shift(scr_p->zoom.is_press),
                    scr_p->zoom.offset_y + img_press_shift(scr_p->zoom.is_press),
                    scr_p->zoom.img_id + img_press_shift(scr_p->zoom.is_press));
            }
            if(scr_p->capmode.is_usable)
            {                
                gdi_image_draw_id(
                    scr_p->capmode.offset_x + img_press_shift(scr_p->capmode.is_press),
                    scr_p->capmode.offset_y + img_press_shift(scr_p->capmode.is_press),
                    scr_p->capmode.img_id + img_press_shift(scr_p->capmode.is_press));
            }                    
            else
            {
                gdi_image_draw_id(
                    scr_p->capmode.offset_x,
                    scr_p->capmode.offset_y,
                    scr_p->capmode.img_id - 1);                
            }                
            if (mmi_camco_setting_imageviewer_is_enable() && mmi_camco_setting_app_switch_is_enable())
            {               
                gdi_image_draw_id(
                    scr_p->imgviewer.offset_x + img_press_shift(scr_p->imgviewer.is_press),
                    scr_p->imgviewer.offset_y + img_press_shift(scr_p->imgviewer.is_press),
                    scr_p->imgviewer.img_id + img_press_shift(scr_p->imgviewer.is_press));
            }
            else
            {               
                gdi_image_draw_id(
                    scr_p->imgviewer.offset_x,
                    scr_p->imgviewer.offset_y,
                    scr_p->imgviewer.img_id - 1);
            }                
            if(mmi_camco_osd_p->is_show_zoom)
            {
                U16 curr_value;
                U16 ind_center_pos_y, ind_center_pos_x;

                if (mmi_camco_osd_is_horz_UI())
                {  
                    gdi_image_draw_id(
                        scr_p->slider_zoom_top.offset_x,
                        scr_p->slider_zoom_top.offset_y,
                        scr_p->slider_zoom_top.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_zoom_botton.offset_x ,
                        scr_p->slider_zoom_botton.offset_y,
                        scr_p->slider_zoom_botton.img_id);

                    curr_value = mmi_camco_setting_get_camzoom_step();

                    ind_center_pos_y =
                        (1.0 - (((curr_value - mmi_camco_osd_p->setting_slider.min_value) * (1.0)) / (mmi_camco_osd_p->setting_slider.step_count - 1))) *
                        scr_p->slider_region.height;

                    scr_p->slider_location.offset_y = (ind_center_pos_y - (scr_p->slider_location.height >> 1) + scr_p->slider_region.offset_y);
                    scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;

                    gdi_layer_set_clip(
                        scr_p->slider_bar.offset_x,
                        scr_p->slider_location.offset_y + (scr_p->slider_location.height >> 1),
                        scr_p->slider_bar.offset_x + scr_p->slider_bar.width,
                        scr_p->slider_bar.offset_y + scr_p->slider_bar.height);

                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id + 1);

                    gdi_layer_reset_clip();
                    
                    gdi_image_draw_id(
                        scr_p->slider_location.offset_x,
                        scr_p->slider_location.offset_y,
                        scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));              
                }
                else
                {

                    gdi_image_draw_id(
                        scr_p->slider_zoom_top.offset_x,
                        scr_p->slider_zoom_top.offset_y,
                        scr_p->slider_zoom_botton.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_zoom_botton.offset_x ,
                        scr_p->slider_zoom_botton.offset_y,
                        scr_p->slider_zoom_top.img_id);
                    
                    curr_value = mmi_camco_setting_get_camzoom_step();
                
                    ind_center_pos_x =
                        ((((curr_value - mmi_camco_osd_p->setting_slider.min_value) * (1.0)) / (mmi_camco_osd_p->setting_slider.step_count - 1))) *
                        scr_p->slider_region.width;

                    scr_p->slider_location.offset_x = (ind_center_pos_x - (scr_p->slider_location.width>> 1) + scr_p->slider_region.offset_x);
                    scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;

                    gdi_layer_set_clip(
                        scr_p->slider_bar.offset_x,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_location.offset_x + (scr_p->slider_location.width>> 1),                        
                        scr_p->slider_bar.offset_y + scr_p->slider_bar.height);

                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id + 1);

                    gdi_layer_reset_clip();
                    
                    gdi_image_draw_id(
                        scr_p->slider_location.offset_x,
                        scr_p->slider_location.offset_y,
                        scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));                              
                }
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        {
            mmi_camco_osd_cam_direct_setting_struct *scr_p = &(mmi_camco_osd_p->cam_direct_setting_screen);

            gdi_image_draw_id(scr_p->scene_mode.offset_x, scr_p->scene_mode.offset_y, scr_p->scene_mode.img_id - 1);
            gdi_image_draw_id(scr_p->flash.offset_x, scr_p->flash.offset_y, scr_p->flash.img_id - 1);
            gdi_image_draw_id(scr_p->zoom.offset_x, scr_p->zoom.offset_y, scr_p->zoom.img_id - 1);
            gdi_image_draw_id(scr_p->capmode.offset_x, scr_p->capmode.offset_y, scr_p->capmode.img_id - 1);
            gdi_image_draw_id(scr_p->imgviewer.offset_x, scr_p->imgviewer.offset_y, scr_p->imgviewer.img_id - 1);

            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            mmi_camco_osd_rec_direct_setting_struct *scr_p = &(mmi_camco_osd_p->rec_direct_setting_screen);

        #ifdef DUAL_CAMERA_SUPPORT
            gdi_image_draw_id(
                mmi_camco_osd_p->sensor_switcher.offset_x + img_press_shift(mmi_camco_osd_p->sensor_switcher.is_press),
                mmi_camco_osd_p->sensor_switcher.offset_y + img_press_shift(mmi_camco_osd_p->sensor_switcher.is_press),
                mmi_camco_osd_p->sensor_switcher.img_id + img_press_shift(mmi_camco_osd_p->sensor_switcher.is_press));
        #endif

            gdi_image_draw_id(
                scr_p->scene_mode.offset_x + img_press_shift(scr_p->scene_mode.is_press),
                scr_p->scene_mode.offset_y + img_press_shift(scr_p->scene_mode.is_press),
                scr_p->scene_mode.img_id + img_press_shift(scr_p->scene_mode.is_press));
            if(mmi_camco_osd_p->is_show_zoom)
            {
                gdi_image_draw_id(
                    scr_p->zoom.offset_x,
                    scr_p->zoom.offset_y,
                    scr_p->zoom.img_id - 1);
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->zoom.offset_x + img_press_shift(scr_p->zoom.is_press),
                    scr_p->zoom.offset_y + img_press_shift(scr_p->zoom.is_press),
                    scr_p->zoom.img_id + img_press_shift(scr_p->zoom.is_press));            
            }
            if (mmi_camco_setting_app_switch_is_enable())
            {
                gdi_image_draw_id(
                    scr_p->allvideos.offset_x + img_press_shift(scr_p->allvideos.is_press),
                    scr_p->allvideos.offset_y + img_press_shift(scr_p->allvideos.is_press),
                    scr_p->allvideos.img_id + img_press_shift(scr_p->allvideos.is_press));
            }
            else
            {
                gdi_image_draw_id(
                    scr_p->allvideos.offset_x,
                    scr_p->allvideos.offset_y,
                    scr_p->allvideos.img_id - 1);            
            }
            if(mmi_camco_osd_p->is_show_zoom)
            {
                U16 curr_value;
                U16 ind_center_pos_y, ind_center_pos_x;

                if (mmi_camco_osd_is_horz_UI())
                {  

                    gdi_image_draw_id(
                        scr_p->slider_zoom_top.offset_x,
                        scr_p->slider_zoom_top.offset_y,
                        scr_p->slider_zoom_top.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_zoom_botton.offset_x ,
                        scr_p->slider_zoom_botton.offset_y,
                        scr_p->slider_zoom_botton.img_id);

                    curr_value = mmi_camco_setting_get_vdozoom_step();

                    ind_center_pos_y =
                        (1.0 - (((curr_value - mmi_camco_osd_p->setting_slider.min_value) * (1.0)) / (mmi_camco_osd_p->setting_slider.step_count - 1))) *
                        scr_p->slider_region.height;

                    scr_p->slider_location.offset_y = (ind_center_pos_y - (scr_p->slider_location.height >> 1) + scr_p->slider_region.offset_y);
                    scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;
                    
                    gdi_layer_set_clip(
                        scr_p->slider_bar.offset_x,
                        scr_p->slider_location.offset_y + (scr_p->slider_location.height >> 1),
                        scr_p->slider_bar.offset_x + scr_p->slider_bar.width,
                        scr_p->slider_bar.offset_y + scr_p->slider_bar.height);

                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id + 1);

                    gdi_layer_reset_clip();

                    gdi_image_draw_id(
                        scr_p->slider_location.offset_x,
                        scr_p->slider_location.offset_y,
                        scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));                   
                }
                else
                {

                    gdi_image_draw_id(
                        scr_p->slider_zoom_top.offset_x,
                        scr_p->slider_zoom_top.offset_y,
                        scr_p->slider_zoom_botton.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id);
                    gdi_image_draw_id(
                        scr_p->slider_zoom_botton.offset_x ,
                        scr_p->slider_zoom_botton.offset_y,
                        scr_p->slider_zoom_top.img_id);
                    
                    curr_value = mmi_camco_setting_get_vdozoom_step();
                
                    ind_center_pos_x =
                        ((((curr_value - mmi_camco_osd_p->setting_slider.min_value) * (1.0)) / (mmi_camco_osd_p->setting_slider.step_count - 1))) *
                        scr_p->slider_region.width;

                    scr_p->slider_location.offset_x = (ind_center_pos_x - (scr_p->slider_location.width>> 1) + scr_p->slider_region.offset_x);
                    scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;
                    
                    gdi_layer_set_clip(
                        scr_p->slider_bar.offset_x,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_location.offset_x + (scr_p->slider_location.width>> 1),                        
                        scr_p->slider_bar.offset_y + scr_p->slider_bar.height);

                    gdi_image_draw_id(
                        scr_p->slider_bar.offset_x ,
                        scr_p->slider_bar.offset_y,
                        scr_p->slider_bar.img_id + 1);

                    gdi_layer_reset_clip();

                    gdi_image_draw_id(
                        scr_p->slider_location.offset_x,
                        scr_p->slider_location.offset_y,
                        scr_p->slider_location.img_id + img_press_shift(scr_p->slider_location.is_press));                   
                }
            }        
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            mmi_camco_osd_rec_direct_setting_struct *scr_p = &(mmi_camco_osd_p->rec_direct_setting_screen);

            gdi_image_draw_id(scr_p->scene_mode.offset_x, scr_p->scene_mode.offset_y, scr_p->scene_mode.img_id - 1);
            gdi_image_draw_id(scr_p->zoom.offset_x, scr_p->zoom.offset_y, scr_p->zoom.img_id - 1);
            gdi_image_draw_id(scr_p->allvideos.offset_x, scr_p->allvideos.offset_y, scr_p->allvideos.img_id - 1);

            break;
        }
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_captured_struct *scr_p = &(mmi_camco_osd_p->captured_img_select_screen);
            mmi_camco_osd_touch_obj_struct *tool_bar = scr_p->tool_bar;

            if (tool_bar[0].is_usable)
            {
                gdi_image_draw_id(
                    tool_bar[0].offset_x + img_press_shift(tool_bar[0].is_press),
                    tool_bar[0].offset_y + img_press_shift(tool_bar[0].is_press),
                    tool_bar[0].img_id + img_press_shift(tool_bar[0].is_press));
            }
            else
            {
                gdi_image_draw_id(tool_bar[0].offset_x, tool_bar[0].offset_y, tool_bar[0].img_id - 1);
            }
            if(mmi_camco_osd_p->imgselect_cache.save_flag_p[mmi_camco_osd_p->imgselect_cache.highlighted_idx])
            {
                if (tool_bar[1].is_usable)
                {
                    gdi_image_draw_id(
                        tool_bar[1].offset_x + img_press_shift(tool_bar[1].is_press),
                        tool_bar[1].offset_y + img_press_shift(tool_bar[1].is_press),
                        tool_bar[1].img_id + img_press_shift(tool_bar[1].is_press));
                }
                else
                {
                    gdi_image_draw_id(tool_bar[1].offset_x, tool_bar[1].offset_y, tool_bar[1].img_id - 1);
                }
            }
            else
            {
                if (scr_p->save.is_usable)
                {
                    gdi_image_draw_id(
                        scr_p->save.offset_x + img_press_shift(scr_p->save.is_press),
                        scr_p->save.offset_y + img_press_shift(scr_p->save.is_press),
                        scr_p->save.img_id + img_press_shift(scr_p->save.is_press));
                }
                else
                {
                    gdi_image_draw_id(scr_p->save.offset_x, scr_p->save.offset_y, scr_p->save.img_id - 1);
                }

            }
            if (tool_bar[2].is_usable)
            {
                gdi_image_draw_id(
                    tool_bar[2].offset_x + img_press_shift(tool_bar[2].is_press),
                    tool_bar[2].offset_y + img_press_shift(tool_bar[2].is_press),
                    tool_bar[2].img_id + img_press_shift(tool_bar[2].is_press));
            }
            else
            {
                gdi_image_draw_id(tool_bar[2].offset_x, tool_bar[2].offset_y, tool_bar[2].img_id - 1);
            }

            break;

        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            mmi_camco_osd_forward_struct *scr_p = &(mmi_camco_osd_p->forward_screen);

            gdi_image_draw_id(scr_p->tool_bar[0].offset_x, scr_p->tool_bar[0].offset_y, scr_p->tool_bar[0].img_id - 1);
            gdi_image_draw_id(scr_p->tool_bar[1].offset_x, scr_p->tool_bar[1].offset_y, scr_p->tool_bar[1].img_id - 1);
            gdi_image_draw_id(scr_p->tool_bar[2].offset_x, scr_p->tool_bar[2].offset_y, scr_p->tool_bar[2].img_id - 1);

            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
            {
                mmi_camco_osd_captured_struct *scr_p = &(mmi_camco_osd_p->captured_screen);
                mmi_camco_osd_touch_obj_struct *tool_bar = scr_p->tool_bar;

                if (scr_p->tool_bar[0].is_usable)
                {
                    gdi_image_draw_id(
                        tool_bar[0].offset_x + img_press_shift(tool_bar[0].is_press),
                        tool_bar[0].offset_y + img_press_shift(tool_bar[0].is_press),
                        tool_bar[0].img_id + img_press_shift(tool_bar[0].is_press));
                }
                else
                {
                    gdi_image_draw_id(tool_bar[0].offset_x, tool_bar[0].offset_y, tool_bar[0].img_id - 1);
                }

                if (scr_p->tool_bar[1].is_usable)
                {
                    gdi_image_draw_id(
                        tool_bar[1].offset_x + img_press_shift(tool_bar[1].is_press),
                        tool_bar[1].offset_y + img_press_shift(tool_bar[1].is_press),
                        tool_bar[1].img_id + img_press_shift(tool_bar[1].is_press));
                }
                else
                {
                    gdi_image_draw_id(tool_bar[1].offset_x, tool_bar[1].offset_y, tool_bar[1].img_id - 1);
                }

                if (scr_p->tool_bar[2].is_usable)
                {
                    gdi_image_draw_id(
                        tool_bar[2].offset_x + img_press_shift(tool_bar[2].is_press),
                        tool_bar[2].offset_y + img_press_shift(tool_bar[2].is_press),
                        tool_bar[2].img_id + img_press_shift(tool_bar[2].is_press));
                }
                else
                {
                    gdi_image_draw_id(tool_bar[2].offset_x, tool_bar[2].offset_y, tool_bar[2].img_id - 1);
                }

            }
            else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
            {
                mmi_camco_osd_captured_struct *scr_p = &(mmi_camco_osd_p->captured_screen);
                mmi_camco_osd_touch_obj_struct *tool_bar = scr_p->tool_bar;
                gdi_image_draw_id(tool_bar[0].offset_x, tool_bar[0].offset_y, tool_bar[0].img_id - 1);
                gdi_image_draw_id(tool_bar[1].offset_x, tool_bar[1].offset_y, tool_bar[1].img_id - 1);
                gdi_image_draw_id(tool_bar[2].offset_x, tool_bar[2].offset_y, tool_bar[2].img_id - 1);
            }            
            break;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_forward_struct *scr_p = &(mmi_camco_osd_p->forward_screen);
    U8 i;
    S32 str_width, str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_draw_id(scr_p->confirm_body.offset_x, scr_p->confirm_body.offset_y, scr_p->confirm_body.img_id);
    for (i = 0; i < 3; i++)
    {
        if (scr_p->item[i].is_usable)
        {
            if (mmi_camco_osd_p->option_menulist.highlighted_idx == mmi_camco_osd_p->fw_option_idx_lookup_table[i])
            {
                gdi_image_draw_id(scr_p->item[i].offset_x + 1, scr_p->item[i].offset_y + 1, scr_p->item[i].img_id + 1);
            }
            else
            {
                gdi_image_draw_id(scr_p->item[i].offset_x, scr_p->item[i].offset_y, scr_p->item[i].img_id);
            }
        }
        else
        {
            gdi_image_draw_id(scr_p->item[i].offset_x, scr_p->item[i].offset_y, scr_p->item[i].img_id - 1);
        }
    }
    gui_measure_string(
        (UI_string_type) GetString(mmi_camco_osd_p->option_menulist.title_str_id),
        &str_width,
        &str_height);
    if (r2lMMIFlag)
    {        
        gui_move_text_cursor(
            scr_p->confirm_title.offset_x + scr_p->confirm_body.width - ((scr_p->confirm_body.width - str_width) >> 1),
            scr_p->confirm_title.offset_y);
    }
    else
    {
        gui_move_text_cursor(
            scr_p->confirm_title.offset_x + ((scr_p->confirm_body.width - str_width) >> 1),
            scr_p->confirm_title.offset_y);        
    }                    
    gui_set_text_border_color(gui_color(0, 0, 0));
    gui_set_text_color(gui_color(255, 255, 255));
    gui_print_text((UI_string_type) GetString(mmi_camco_osd_p->option_menulist.title_str_id));

    gui_measure_string(
        (UI_string_type) GetString(mmi_camco_osd_p->option_menulist.item_list[mmi_camco_osd_p->option_menulist.highlighted_idx].str_id),
        &str_width,
        &str_height);
    if (r2lMMIFlag)
    {                
        gui_move_text_cursor(
            scr_p->confirm_sub_title.offset_x + scr_p->confirm_body.width - ((scr_p->confirm_body.width - str_width) >> 1),
            scr_p->confirm_sub_title.offset_y);
    }
    else            
    {                
        gui_move_text_cursor(
            scr_p->confirm_sub_title.offset_x + ((scr_p->confirm_body.width - str_width) >> 1),
            scr_p->confirm_sub_title.offset_y);
    }        
    gui_set_text_border_color(gui_color(0, 0, 0));
    gui_set_text_color(gui_color(255, 255, 255));
    gui_print_text((UI_string_type)
                   GetString(mmi_camco_osd_p->option_menulist.
                             item_list[mmi_camco_osd_p->option_menulist.highlighted_idx].str_id));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_TMP_BUF_LEN (100)

    mmi_camco_osd_confirm_struct *confirm_p = &mmi_camco_osd_p->confirm_screen;
    CHAR  str_buf[MMI_CAMCO_OSD_TMP_BUF_LEN];
    S32 str_width = 0;
    S32 str_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_draw_id(
        confirm_p->confirm_body.offset_x,
        confirm_p->confirm_body.offset_y,
        confirm_p->confirm_body.img_id);

    gdi_image_draw_id(
        confirm_p->confirm_lsk.offset_x + img_press_shift(confirm_p->confirm_lsk.is_press),
        confirm_p->confirm_lsk.offset_y + img_press_shift(confirm_p->confirm_lsk.is_press),
        confirm_p->confirm_lsk.img_id + img_press_shift(confirm_p->confirm_lsk.is_press));

    gdi_image_draw_id(
        confirm_p->confirm_rsk.offset_x + img_press_shift(confirm_p->confirm_rsk.is_press),
        confirm_p->confirm_rsk.offset_y + img_press_shift(confirm_p->confirm_rsk.is_press),
        confirm_p->confirm_rsk.img_id + img_press_shift(confirm_p->confirm_rsk.is_press));

    /* gui_set_font(&MMI_medium_font); */

    if (mmi_camco_osd_p->center_hint.str_ptr != NULL)
    {
        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);

        memset(str_buf, 0, MMI_CAMCO_OSD_TMP_BUF_LEN);

        mmi_ucs2ncpy(str_buf, (CHAR *) mmi_camco_osd_p->center_hint.str_ptr, (MMI_CAMCO_OSD_TMP_BUF_LEN/2) - 1);

        gui_measure_string((UI_string_type) str_buf, &str_width, &str_height);
        if (str_width < confirm_p->confirm_body.width)
        {

            gui_move_text_cursor(mmi_camco_osd_p->center_hint.offset_x, confirm_p->confirm_title.offset_y);
            gui_print_bordered_text((UI_string_type) str_buf);

        }
        else
        {
            mmi_camco_osd_draw_multiline_confirm_hint(str_buf);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_swtich_to_camera
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_swtich_to_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_VIDEO)     
    {
        mmi_camco_osd_p->iconlist.highlighted_idx = 0;
        mmi_camco_switch_app();
        SEND_EVT(MMI_CAMCO_EVT_SWITCH_APP, NULL);    
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_pre_swtich_to_camera
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_pre_swtich_to_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_VIDEO)     
    {
        mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();  
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_swtich_to_recorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_swtich_to_recorder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_osd_p->iconlist.highlighted_idx = 0;
        mmi_camco_switch_app();
        SEND_EVT(MMI_CAMCO_EVT_SWITCH_APP, NULL);    
    }        

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_pre_swtich_to_recorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_pre_swtich_to_recorder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.is_press = MMI_TRUE;    
        mmi_camco_osd_draw_osd();  
    }        

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rsk_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rsk not registered */
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMG_SELECT_BACK;
            mmi_camco_osd_p->captured_img_select_screen.back.is_press = MMI_TRUE;
            /* draw osd */
            mmi_camco_osd_draw_osd();
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAPTURED_BACK;
                mmi_camco_osd_p->captured_screen.back.is_press = MMI_TRUE;
                mmi_camco_osd_draw_osd();
            }
            else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_HINT_BACK;
                mmi_camco_osd_p->captured_screen.back.is_press = MMI_TRUE;
                mmi_camco_osd_draw_osd();
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_CAPMODE, mmi_camco_get_last_capmode());            
            mmi_camco_osd_p->add_frame.back.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RSK;
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_BACK;
            mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_TRUE;
            /* draw osd */
            mmi_camco_osd_draw_osd();
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_BACK;
            mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_TRUE;
            /* draw osd */
            mmi_camco_osd_draw_osd();
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:      
        {
            mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            break;
        }            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:   
        {
            mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            break;
        }            
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_STOP;
            mmi_camco_osd_p->recording_screen.stop.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            break;
        }
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
        {
            /* draw osd */
            mmi_camco_osd_draw_osd();
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        {
            if (!mmi_camco_osd_p->is_direct_setting)
                //mmi_camco_osd_touch_cam_direct_setting_pen_down_hdlr(
                //    mmi_camco_osd_p->cam_direct_setting_screen.back.offset_x + 1,
                //    mmi_camco_osd_p->cam_direct_setting_screen.back.offset_y + 1);
            //else
                mmi_camco_osd_touch_cam_advance_setting_pen_down_hdlr(
                    mmi_camco_osd_p->advance_setting_screen.back.offset_x + 1,
                    mmi_camco_osd_p->advance_setting_screen.back.offset_y + 1);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if (!mmi_camco_osd_p->is_direct_setting)
                //mmi_camco_osd_touch_rec_direct_setting_pen_down_hdlr(
                //    mmi_camco_osd_p->rec_direct_setting_screen.back.offset_x + 1,
                //    mmi_camco_osd_p->rec_direct_setting_screen.back.offset_y + 1);
            //else
                mmi_camco_osd_touch_rec_advance_setting_pen_down_hdlr(
                    mmi_camco_osd_p->advance_setting_screen.back.offset_x + 1,
                    mmi_camco_osd_p->advance_setting_screen.back.offset_y + 1);
            mmi_camco_osd_draw_osd();
            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RSK;
            break;
        }
    #if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif    
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RSK;            
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            MMI_ASSERT(0);
            break;
        }

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rsk_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            if (mmi_camco_osd_p->captured_screen.back.is_press == MMI_TRUE)
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;                
                if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
                {

                    mmi_camco_osd_p->captured_screen.back.is_press = MMI_FALSE;
                    mmi_camco_osd_draw_osd();
                    SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
                {
                    mmi_camco_osd_p->captured_screen.back.is_press = MMI_FALSE;
                    mmi_camco_osd_draw_osd();
                    SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);

                }
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            if (mmi_camco_osd_p->cam_direct_setting_screen.back.is_press)
            {
                mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;                
                /* draw osd */
                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            if (mmi_camco_osd_p->rec_direct_setting_screen.back.is_press)
            {
                mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;                
                /* draw osd */
                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:      
        {
            if (mmi_camco_osd_p->storage_select_screen.back.is_press)
            {            
                mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_TRUE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);            
            }                
            break;
        }            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:   
        {
            if (mmi_camco_osd_p->storage_select_screen.back.is_press)
            {            
                mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_TRUE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);            
            }                
            break;
        }            
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            if (mmi_camco_osd_p->recording_screen.stop.is_press)
            {
                mmi_camco_osd_p->recording_screen.stop.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;                
                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
        {
            /* draw osd */
            mmi_camco_osd_draw_osd();

            SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            break;
        }
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            if (mmi_camco_osd_p->captured_img_select_screen.back.is_press)
            {
                mmi_camco_osd_p->captured_img_select_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;                
                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            if (mmi_camco_osd_p->add_frame.back.is_press)
            {
                mmi_camco_osd_p->add_frame.back.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_CAPMODE, mmi_camco_get_last_capmode());
                /* draw osd */
                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        {
            if (!mmi_camco_osd_p->is_direct_setting)
                //mmi_camco_osd_touch_cam_direct_setting_pen_up_hdlr(
                //    mmi_camco_osd_p->cam_direct_setting_screen.back.offset_x + 1,
                //    mmi_camco_osd_p->cam_direct_setting_screen.back.offset_y + 1);
            //else
                mmi_camco_osd_touch_cam_advance_setting_pen_up_hdlr(
                    mmi_camco_osd_p->advance_setting_screen.back.offset_x + 1,
                    mmi_camco_osd_p->advance_setting_screen.back.offset_y + 1);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if (!mmi_camco_osd_p->is_direct_setting)
                //mmi_camco_osd_touch_rec_direct_setting_pen_up_hdlr(
                //    mmi_camco_osd_p->rec_direct_setting_screen.back.offset_x + 1,
                //    mmi_camco_osd_p->rec_direct_setting_screen.back.offset_y + 1);
            //else
                mmi_camco_osd_touch_rec_advance_setting_pen_up_hdlr(
                    mmi_camco_osd_p->advance_setting_screen.back.offset_x + 1,
                    mmi_camco_osd_p->advance_setting_screen.back.offset_y + 1);
            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            if (mmi_camco_osd_p->panorama_screen.cancel.is_press)
            {
                mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }
            break;
        }
    #if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif    
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            if (mmi_camco_osd_p->panorama_screen.cancel.is_press)
            {
                mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_CAPMODE, mmi_camco_get_last_capmode());            
                mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }            
            break;
        }        
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_lsk_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_lsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk not registered */
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            if(!mmi_camco_osd_is_in_smile_dect_scrn())
            {
               mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_AD_SETTING;
                mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_press = MMI_TRUE;
                mmi_camco_osd_draw_osd();
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_AD_SETTING;
            mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            break;

        }
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_p->add_frame.ok.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {

            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_PAUSE_RESUME;
            mmi_camco_osd_p->recording_screen.start.is_press = MMI_TRUE;
            mmi_camco_osd_p->recording_screen.pause.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;
            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;
            break;
        }            
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;            
            break;
        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:      
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:           	
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_lsk_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_lsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            if (mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_press)
            {
                mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
                mmi_camco_osd_p->is_direct_setting = KAL_FALSE;                
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);

            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            if (mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_press)
            {
                mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
                mmi_camco_osd_p->is_direct_setting = KAL_FALSE;                
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            if (mmi_camco_osd_p->recording_screen.start.is_press)
            {
                mmi_camco_osd_p->recording_screen.start.is_press = MMI_FALSE;
                mmi_camco_osd_p->recording_screen.pause.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;

                /* lsk not registered */
                if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
                {
                    return;
                }

                /* draw osd */
                mmi_camco_osd_draw_osd();

                /* callback */
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            if (mmi_camco_osd_p->add_frame.ok.is_press)
            {
                mmi_camco_osd_p->add_frame.ok.is_press = MMI_FALSE;
                mmi_camco_osd_p->add_frame.is_picked = MMI_TRUE;
                if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
                {
                    return;
                }

                /* draw osd */
                mmi_camco_osd_draw_osd();

                /* callback */
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {

            if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
            {
                return;
            }

            /* draw osd */
            mmi_camco_osd_draw_osd();

            /* callback */
            SEND_EVT(MMI_CAMCO_EVT_OK, NULL);

            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {            
            if (mmi_camco_osd_p->panorama_screen.OK.is_press)
            {
                mmi_camco_osd_p->panorama.is_picked = MMI_TRUE;
                mmi_camco_setting_set_panorama_direction(mmi_camco_osd_p->panorama.highlighted_idx);
            
                mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }            
            break;
        }        
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            if (mmi_camco_osd_p->panorama_screen.OK.is_press)
            {
                mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();

                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
            {
                /* if choose restore default, back to preview directly */
                if (mmi_camco_osd_p->iconlist.icon_list[mmi_camco_osd_p->iconlist.highlighted_idx].str_id == STR_ID_CAMCO_DEFAULT)
                {

                    mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
                    break;
                }

                mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                    mmi_camco_osd_p->iconlist.highlighted_idx);            
            }
            else if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
            {
                mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                    mmi_camco_osd_p->setting_menulist.highlighted_idx);            
            }    
            mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;                 
            break;
        }    
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:      
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:           	        	
        {
            /* Do nothing */
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_csk_set_press
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_csk_set_press(MMI_BOOL is_press)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if(mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        if(mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW)
        {    		
            mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_press = is_press;

            if (mmi_camco_osd_is_in_smile_dect_scrn())
            {
                mmi_camco_osd_p->cam_direct_setting_screen.capture.is_press = is_press;
            }
        }
        else if(mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_PANORAMA_SHOT)
        { 
            mmi_camco_osd_p->panorama_screen.capture.is_press = is_press;            
        }        
        mmi_camco_osd_p->is_capturing = is_press;     
    }
    else
    {
        mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_press = is_press;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_csk_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_csk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk not registered */
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
            {
                return;
            }
            mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_press = MMI_TRUE;
            mmi_camco_osd_p->panorama_screen.capture.is_press = MMI_TRUE;            
            mmi_camco_osd_p->cam_direct_setting_screen.capture.is_press = MMI_TRUE;            
            mmi_camco_osd_p->is_capturing = MMI_TRUE;     
            mmi_camco_osd_draw_osd();

            /* callback */
            SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);

            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
            {
                return;
            }
            mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_press = MMI_TRUE;
            mmi_camco_osd_p->rec_direct_setting_screen.record.is_press = MMI_TRUE;                     
            mmi_camco_osd_draw_osd();

            /* callback */
            SEND_EVT(MMI_CAMCO_EVT_RECORD, NULL);

            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {

            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_PAUSE_RESUME;
            mmi_camco_osd_p->recording_screen.start.is_press = MMI_TRUE;
            mmi_camco_osd_p->recording_screen.pause.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
            break;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_csk_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_csk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk not registered */
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
            {
                return;
            }
            mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_press = MMI_FALSE;
            mmi_camco_osd_p->panorama_screen.capture.is_press = MMI_FALSE;  
            mmi_camco_osd_p->cam_direct_setting_screen.capture.is_press = MMI_FALSE;    
            mmi_camco_osd_draw_osd();

            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
            {
                return;
            }
            mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();

            break;
        }    	
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
            if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
            {
                return;
            }
            mmi_camco_osd_p->is_capturing = MMI_FALSE;   
            mmi_camco_osd_set_bg_black();
            mmi_camco_osd_draw_osd();

            SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);
            break;
        }
        case MMI_CAMCO_OSD_STATE_HIDE:
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            /* shall not have key event who osd hide */
            MMI_ASSERT(0);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:      
        {
            if (mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_press)
            {            
                mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CHANGE_STORAGE, NULL);            
            }                
            break;
        }            
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:   
        {
            if (mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_press)
            {            
                mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CHANGE_STORAGE, NULL);              
            }
            break;
        }            
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            if (mmi_camco_osd_p->recording_screen.start.is_press)
            {
                mmi_camco_osd_p->recording_screen.start.is_press = MMI_FALSE;
                mmi_camco_osd_p->recording_screen.pause.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;

                /* lsk not registered */
                if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
                {
                    return;
                }

                /* draw osd */
                mmi_camco_osd_draw_osd();

                /* callback */
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;
        }
            
        
        

    }
 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_center_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_center_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->center_hint.str_ptr = str_ptr;
    gui_measure_string((UI_string_type) mmi_camco_osd_p->center_hint.str_ptr, &str_width, &str_height);

    mmi_camco_osd_p->center_hint.offset_x = (mmi_camco_osd_p->osd_width - str_width) >> 1;
    if (r2lMMIFlag)
    {
        mmi_camco_osd_p->center_hint.offset_x =
            mmi_camco_osd_p->osd_width - mmi_camco_osd_p->center_hint.offset_x;
    }

    mmi_camco_osd_p->center_hint.offset_y = (mmi_camco_osd_p->osd_height - str_height) >> 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_center_processing_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_center_processing_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->center_hint.is_processing = MMI_TRUE;
    mmi_camco_osd_set_center_hint_str(str_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_corner_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_corner_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->corner_hint.str_ptr = str_ptr;
    gui_measure_string((UI_string_type) mmi_camco_osd_p->corner_hint.str_ptr, &str_width, &str_height);


    if (mmi_camco_osd_is_horz_UI())
    {
        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_HINT)
        {
            mmi_camco_osd_p->corner_hint.offset_x = mmi_camco_osd_p->cam_direct_setting_screen.scene_mode.width + 10;
            mmi_camco_osd_p->corner_hint.offset_y = mmi_camco_osd_skin_p->camera_preview.corner_hint.offset_y;
        }
        else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_HINT)
        {
            mmi_camco_osd_p->corner_hint.offset_x = mmi_camco_osd_p->rec_direct_setting_screen.scene_mode.width + 10;
            mmi_camco_osd_p->corner_hint.offset_y = mmi_camco_osd_skin_p->video_preview.corner_hint.offset_y;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_HINT)
        {
            mmi_camco_osd_p->corner_hint.offset_x = mmi_camco_osd_skin_p->camera_preview.corner_hint.offset_x;
            mmi_camco_osd_p->corner_hint.offset_y = mmi_camco_osd_skin_p->camera_preview.corner_hint.offset_y;
        }
        else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_HINT)
        {
            mmi_camco_osd_p->corner_hint.offset_x = mmi_camco_osd_skin_p->video_preview.corner_hint.offset_x;
            mmi_camco_osd_p->corner_hint.offset_y = mmi_camco_osd_skin_p->video_preview.corner_hint.offset_y;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    if (r2lMMIFlag)
    {
        mmi_camco_osd_p->corner_hint.offset_x += str_width;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_multiline_center_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_multiline_center_hint(CHAR * str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MULTILINE_AREA_OFFSET_WIDTH  (mmi_camco_osd_p->osd_width)
#define MULTILINE_AREA_OFFSET_HEIGHT (60)
#define MULTILINE_AREA_OFFSET_X      (0)
#define MULTILINE_AREA_OFFSET_Y      (mmi_camco_osd_p->osd_height/2 - MULTILINE_AREA_OFFSET_HEIGHT/2)

    S32 str_width = 0;
    S32 str_height = 0;
    S32 str_len = 0;
    S32 line_height;
    S32 layer_offset_x = 0;
    S32 layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    gdi_draw_solid_rect(
        MULTILINE_AREA_OFFSET_X,
        MULTILINE_AREA_OFFSET_Y,
        MULTILINE_AREA_OFFSET_X + MULTILINE_AREA_OFFSET_WIDTH - 1,
        MULTILINE_AREA_OFFSET_Y + MULTILINE_AREA_OFFSET_HEIGHT - 1,
        GDI_COLOR_TRANSPARENT);

    str_len = mmi_ucs2strlen((CHAR *) str_ptr);

    create_multiline_inputbox_set_buffer((UI_string_type) str_ptr, str_len, str_len, 0);
    MMI_multiline_inputbox.normal_text_color = mmi_camco_osd_p->text_color;
    MMI_multiline_inputbox.border_color = mmi_camco_osd_p->text_border_color;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_USE_BORDER_FONT;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

    MMI_multiline_inputbox.text_font = &MMI_medium_font;

    resize_multiline_inputbox(MULTILINE_AREA_OFFSET_WIDTH, MULTILINE_AREA_OFFSET_HEIGHT);
    move_multiline_inputbox(MULTILINE_AREA_OFFSET_X + layer_offset_x, MULTILINE_AREA_OFFSET_Y + layer_offset_y);

    /* vertical center alignment */
    show_multiline_inputbox_no_draw();
    line_height = get_multiline_inputbox_line_height();
    resize_multiline_inputbox(
        MULTILINE_AREA_OFFSET_WIDTH,
        (MMI_multiline_inputbox.n_lines * line_height) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y);
    move_multiline_inputbox(
        0,
        MULTILINE_AREA_OFFSET_Y + ((MULTILINE_AREA_OFFSET_HEIGHT - MMI_multiline_inputbox.height) >> 1));

    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_multiline_confirm_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_multiline_confirm_hint(CHAR * str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MULTILINE_CONFIRM_OFFSET_WIDTH  (mmi_camco_osd_p->confirm_screen.confirm_body.width)
#define MULTILINE_CONFIRM_OFFSET_HEIGHT (mmi_camco_osd_p->confirm_screen.confirm_lsk.offset_y - mmi_camco_osd_p->confirm_screen.confirm_body.offset_y)
#define MULTILINE_CONFIRM_OFFSET_X      (mmi_camco_osd_p->confirm_screen.confirm_body.offset_x)
#define MULTILINE_CONFIRM_OFFSET_Y      (mmi_camco_osd_p->confirm_screen.confirm_body.offset_y)

    S32 str_width = 0;
    S32 str_height = 0;
    S32 str_len = 0;
    S32 line_height;
    S32 layer_offset_x = 0;
    S32 layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

    str_len = mmi_ucs2strlen((CHAR *) str_ptr);

    create_multiline_inputbox_set_buffer((UI_string_type) str_ptr, str_len, str_len, 0);
    MMI_multiline_inputbox.normal_text_color = mmi_camco_osd_p->text_color;
    MMI_multiline_inputbox.border_color = mmi_camco_osd_p->text_border_color;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_USE_BORDER_FONT;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

    MMI_multiline_inputbox.text_font = &MMI_medium_font;

    resize_multiline_inputbox(MULTILINE_CONFIRM_OFFSET_WIDTH, MULTILINE_CONFIRM_OFFSET_HEIGHT);
    move_multiline_inputbox(MULTILINE_CONFIRM_OFFSET_X + layer_offset_x, MULTILINE_CONFIRM_OFFSET_Y + layer_offset_y);

    show_multiline_inputbox();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_hint_process_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_hint_process_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->center_hint.dot_count++;

    if (mmi_camco_osd_p->center_hint.dot_count > MMI_CAMCO_OSD_MAX_HINT_DOT_COUNT)
    {
        mmi_camco_osd_p->center_hint.dot_count = 0;
    }

    mmi_camco_osd_draw_osd();

    gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_osd_draw_hint_process_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_TMP_BUF_LEN (100)
#define MMI_CAMCO_OSD_CENTER_HINT_BORDER (0)

    S32 i;
    CHAR  str_buf[MMI_CAMCO_OSD_TMP_BUF_LEN];
    S32 str_width = 0;
    S32 str_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    if (mmi_camco_osd_p->center_hint.str_ptr != NULL)
    {
        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);

        memset(str_buf, 0, MMI_CAMCO_OSD_TMP_BUF_LEN);

        if (r2lMMIFlag)
        {
            for (i = 0; i < mmi_camco_osd_p->center_hint.dot_count; i++)
            {
                mmi_ucs2cat(str_buf, (CHAR *) (L"."));
            }

            mmi_ucs2ncat(
                str_buf,
                (CHAR *) mmi_camco_osd_p->center_hint.str_ptr,
                MMI_CAMCO_OSD_TMP_BUF_LEN - 1 - mmi_camco_osd_p->center_hint.dot_count);

        }
        else
        {
            mmi_ucs2ncpy(
                str_buf,
                (CHAR *) mmi_camco_osd_p->center_hint.str_ptr,
                MMI_CAMCO_OSD_TMP_BUF_LEN - 1 - mmi_camco_osd_p->center_hint.dot_count);

            for (i = 0; i < mmi_camco_osd_p->center_hint.dot_count; i++)
            {
                mmi_ucs2cat(str_buf, (CHAR *) (L"."));
            }
        }

        gui_measure_string((UI_string_type) str_buf, &str_width, &str_height);

        if (str_width < mmi_camco_osd_p->osd_width - 2 * MMI_CAMCO_OSD_CENTER_HINT_BORDER)
        {
            gui_move_text_cursor(mmi_camco_osd_p->center_hint.offset_x, mmi_camco_osd_p->center_hint.offset_y);

            gui_print_bordered_text((UI_string_type) str_buf);

        }
        else
        {
            mmi_camco_osd_draw_multiline_center_hint(str_buf);
        }

        if (mmi_camco_osd_p->center_hint.is_processing)
        {
            gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_osd_draw_hint_process_cyclic);
        }

    }

    if (mmi_camco_osd_p->corner_hint.str_ptr != NULL)
    {
        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);

        gui_move_text_cursor(mmi_camco_osd_p->corner_hint.offset_x, mmi_camco_osd_p->corner_hint.offset_y);

        gui_print_bordered_text((UI_string_type) mmi_camco_osd_p->corner_hint.str_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  focus_region        [IN]        
 *  type                [IN]        
 *  center_x            [IN]        
 *  center_y            [IN]        
 *  width               [IN]        
 *  height              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_focus(
        mmi_camco_osd_focus_region_enum focus_region,
        mmi_camco_osd_focus_type_enum type,
        S32 center_x,
        S32 center_y,
        S32 width,
        S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(focus_region < MMI_CAMCO_OSD_FOCUS_REGION_END);

    mmi_camco_osd_p->focus_region[focus_region].type = type;
    mmi_camco_osd_p->focus_region[focus_region].x1 = center_x - (width >> 1);
    mmi_camco_osd_p->focus_region[focus_region].x2 = center_x + (width >> 1);
    mmi_camco_osd_p->focus_region[focus_region].y1 = center_y - (height >> 1);
    mmi_camco_osd_p->focus_region[focus_region].y2 = center_y + (height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* focused green */
    mmi_camco_osd_p->focused_color = gdi_act_color_from_rgb(255, 0, 255, 0);
    mmi_camco_osd_p->focused_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* focusing white */
    mmi_camco_osd_p->focusing_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    mmi_camco_osd_p->focusing_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* focusing fail red */
    mmi_camco_osd_p->focusing_fail_color = gdi_act_color_from_rgb(255, 255, 0, 0);
    mmi_camco_osd_p->focusing_fail_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* 255 = no opacity, 0 = full opacity */
    mmi_camco_osd_p->focus_opacity = 200;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_focus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_focus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gdi_color rect_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    gdi_color border_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    S32 region_height = 0;
    S32 edge_pixel = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_OSD_FOCUS_REGION_END; i++)
    {
        if (mmi_camco_osd_p->focus_region[i].type != MMI_CAMCO_OSD_FOCUS_TYPE_NULL)
        {
            if (mmi_camco_osd_p->focus_region[i].type == MMI_CAMCO_OSD_FOCUS_TYPE_FOCUSED)
            {
                rect_color = mmi_camco_osd_p->focused_color;
                border_color = mmi_camco_osd_p->focused_border_color;
            }
            else if (mmi_camco_osd_p->focus_region[i].type == MMI_CAMCO_OSD_FOCUS_TYPE_FOCUSING)
            {
                rect_color = mmi_camco_osd_p->focusing_color;
                border_color = mmi_camco_osd_p->focusing_border_color;

            }
            else if (mmi_camco_osd_p->focus_region[i].type == MMI_CAMCO_OSD_FOCUS_TYPE_FOCUSING_FAIL)
            {
                rect_color = mmi_camco_osd_p->focusing_fail_color;
                border_color = mmi_camco_osd_p->focusing_fail_border_color;
            }
            else
            {
                MMI_ASSERT(0);
            }
            region_height = mmi_camco_osd_p->focus_region[i].y2 - mmi_camco_osd_p->focus_region[i].y1;
            edge_pixel = (MMI_CAMCO_OSD_FOCUSE_EDGE_RATIO * region_height) / 100;

            /* top-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->focus_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x1 + 2 + edge_pixel - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1 + edge_pixel + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1 + edge_pixel - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2 + edge_pixel - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                border_color);

            /* top-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 - 1 + (edge_pixel + 1),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y1,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1,
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y1 + 1 + (edge_pixel - 1),
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2,
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + 2 + (edge_pixel - 2),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y1 + edge_pixel + 1,
                border_color);

            /* bottom-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                mmi_camco_osd_p->focus_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y2,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                mmi_camco_osd_p->focus_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x1 + 2 + edge_pixel - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x1 + edge_pixel + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].x1,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].x1 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x1 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].x1 + 2,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                border_color);

            /* bottom-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].y2,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                mmi_camco_osd_p->focus_region[i].x2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->focus_region[i].x2,
                mmi_camco_osd_p->focus_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->focus_region[i].x2 - 1,
                mmi_camco_osd_p->focus_region[i].y2 - 1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2 - (edge_pixel - 2),
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - 2,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->focus_region[i].x2 - 2,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                mmi_camco_osd_p->focus_region[i].x2 + 1,
                mmi_camco_osd_p->focus_region[i].y2 - edge_pixel - 1,
                border_color);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_focus_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_focus_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->focus_hint.img_id = NULL;
    mmi_camco_osd_p->focus_hint.is_hint_show = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_center_focus_process_hint_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_center_focus_process_hint_img(MMI_ID_TYPE img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width;
    S32 img_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->focus_hint.is_processing = MMI_TRUE;
    gdi_image_get_dimension_id((U16) img_id, &img_width, &img_height);
    mmi_camco_osd_p->focus_hint.img_id = img_id;

    mmi_camco_osd_p->focus_hint.offset_x = (mmi_camco_osd_p->osd_width - img_width) >> 1;
    mmi_camco_osd_p->focus_hint.offset_y = (mmi_camco_osd_p->osd_height - img_height) >> 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_focus_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_focus_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_p->focus_hint.is_hint_show && mmi_camco_osd_p->focus_hint.img_id)
    {
        gdi_image_draw_id(
            mmi_camco_osd_p->focus_hint.offset_x,
            mmi_camco_osd_p->focus_hint.offset_y,
            (U16) (mmi_camco_osd_p->focus_hint.img_id));

        mmi_camco_osd_p->focus_hint.is_hint_show = MMI_TRUE;

    }
    else
    {
        mmi_camco_osd_clear_bg();
        mmi_camco_osd_p->focus_hint.is_hint_show = MMI_FALSE;

    }

    if (mmi_camco_osd_p->focus_hint.is_processing)
    {
        gui_start_timer(MMI_CAMCO_OSD_FOCUS_HINT_PROCESS_DUR, mmi_camco_osd_draw_focus_hint_process_cyclic);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_focus_hint_process_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_focus_hint_process_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_draw_osd();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_add_frame_highlighted_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
void mmi_camco_osd_set_add_frame_highlighted_idx(U16 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->add_frame.highlighted_idx = idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_add_frame_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_camco_osd_get_add_frame_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.highlighted_idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_overlay_frame_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
CHAR *mmi_camco_osd_get_overlay_frame_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.overlay_frame_layer_buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_overlay_frame_cap_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
CHAR *mmi_camco_osd_get_overlay_frame_cap_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.overlay_frame_layer_cap_buf_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_add_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_add_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    add_frame_p->frame_count = IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_COUNT - IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE - 1;

    gdi_image_get_dimension_id(IMG_ID_CAMCO_ARROW_LEFT, &image_width, &image_height);

    /* left arrow top-right corner */
    add_frame_p->la_touch.offset_x = mmi_camco_osd_skin_p->add_frame.left_arrow.offset_x;
    add_frame_p->la_touch.offset_y = mmi_camco_osd_skin_p->add_frame.left_arrow.offset_y;
    /* right arrow top-left corner */
    add_frame_p->ra_touch.offset_x = mmi_camco_osd_skin_p->add_frame.right_arrow.offset_x;
    add_frame_p->ra_touch.offset_y = mmi_camco_osd_skin_p->add_frame.right_arrow.offset_y;

    add_frame_p->la_touch.width = image_width;
    add_frame_p->la_touch.height = image_height;
    /* add_frame_p->la_touch.offset_x -= image_width; */

    add_frame_p->ra_touch.width = image_width;
    add_frame_p->ra_touch.height = image_height;

    add_frame_p->back.offset_x = setting_skin_p->back.offset_x;
    add_frame_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &add_frame_p->back.width, &add_frame_p->back.height);
    add_frame_p->back.img_id = IMG_ID_CAMCO_BACK_ICON;

    add_frame_p->ok.offset_x = setting_skin_p->advance_setting.offset_x;
    add_frame_p->ok.offset_y = setting_skin_p->advance_setting.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OK_ICON, &add_frame_p->ok.width, &add_frame_p->ok.height);
    add_frame_p->ok.img_id = IMG_ID_CAMCO_OK_ICON;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_color_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_add_frame_color_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    S32 image_width;
    S32 image_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    U16 image_idx;
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    mmi_camco_get_preview_region(
        &image_region_offset_x,
        &image_region_offset_y,
        &image_region_width,
        &image_region_height);

    image_idx = (U16) (IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE + mmi_camco_osd_p->add_frame.highlighted_idx + 1);

    result = gdi_image_get_dimension_id(image_idx, &image_width, &image_height);

    if (result >= 0)
    {
        if ((image_region_width >= image_width) && (image_region_height >= image_height))
        {
            gdi_image_draw_id(image_region_offset_x, image_region_offset_y, (U16) (image_idx));
        }
        else
        {
            gdi_image_util_fit_bbox(
                image_region_width,
                image_region_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_image_draw_resized_id(
                resized_offset_x + image_region_offset_x,
                resized_offset_y + image_region_offset_y,
                resized_width,
                resized_height,
                image_idx);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_color_idx_on_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  palette_size        [OUT]       
 *  palette_address     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_add_frame_color_idx_on_layer(U8 *palette_size, U32 **palette_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color *p_gdi_palette;
    U16 i;
    U32 Y, U, V;
    U32 R, G, B;
    U32 *p_overlay_palette;
    U16 image_idx;
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;
    GDI_RESULT result;
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_idx = (U16) (IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE + mmi_camco_osd_p->add_frame.highlighted_idx + 1);
    gdi_layer_push_and_set_active(add_frame_p->overlay_frame_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    mmi_camco_get_preview_region(
        &image_region_offset_x,
        &image_region_offset_y,
        &image_region_width,
        &image_region_height);

    gdi_layer_resize(image_region_width, image_region_height);

    result = gdi_image_get_dimension_id(image_idx, &image_width, &image_height);

    if (result < 0)
    {
        return;
    }

    if ((image_region_width >= image_width) && (image_region_height >= image_height))
    {
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));
    }
    else
    {
        gdi_image_draw_resized_id_with_transparent_color(
            0,
            0,
            image_region_width,
            image_region_height,
            (U16) (image_idx));
    }

    p_gdi_palette = gdi_layer_get_palette();

    add_frame_p->overlay_frame_palette_size = gdi_image_gif_get_palette_size();
    /*************** RGB to YUV format **************************************************
    *
    *     [MSDN RGB888 to YUV444 (16bits)]
    *
    *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
    *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
    *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
    *     
    *     These formulas produce 8-bit results using coefficients 
    *     that require no more than 8 bits of (unsigned) precision. 
    *     Intermediate results require up to 16 bits of precision.
    *
    ***************************************************************************************/
    p_overlay_palette = &add_frame_p->overlay_palette[0];
    for (i = 0; i < 256; i++)
    {
        R = (U32) ((U8) (*p_gdi_palette >> 16));
        G = (U32) ((U8) (*p_gdi_palette >> 8));
        B = (U32) ((U8) (*p_gdi_palette));

        Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
        U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
        V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

        (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
        p_overlay_palette++;
        p_gdi_palette++;
    }

    *palette_size = add_frame_p->overlay_frame_palette_size;
    *palette_address = &add_frame_p->overlay_palette[0];

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_color_idx_cap_on_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  palette_size        [OUT]       
 *  palette_address     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_add_frame_color_idx_cap_on_layer(U8 *palette_size, U32 **palette_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color *p_gdi_palette;
    U16 i;
    U32 Y, U, V;
    U32 R, G, B;
    U32 *p_overlay_palette;
    U16 image_idx;
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    GDI_RESULT result;
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_idx = (U16) (IMG_ID_CAMCO_ADD_FRAME_COLOR_IDX_BASE + mmi_camco_osd_p->add_frame.highlighted_idx + 1);
    gdi_layer_push_and_set_active(add_frame_p->overlay_frame_cap_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    gdi_layer_resize(MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH, MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT);

    result = gdi_image_get_dimension_id(image_idx, &image_width, &image_height);

    if (result < 0)
    {
        return;
    }

    if ((MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH >= image_width) &&
        (MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT >= image_height))
    {
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));
    }
    else
    {
        gdi_image_draw_resized_id_with_transparent_color(
            0,
            0,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
            (U16) (image_idx));
    }

    p_gdi_palette = gdi_layer_get_palette();

    add_frame_p->overlay_frame_palette_size = gdi_image_gif_get_palette_size();
    /*************** RGB to YUV format **************************************************
    *
    *     [MSDN RGB888 to YUV444 (16bits)]
    *
    *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
    *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
    *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
    *     
    *     These formulas produce 8-bit results using coefficients 
    *     that require no more than 8 bits of (unsigned) precision. 
    *     Intermediate results require up to 16 bits of precision.
    *
    ***************************************************************************************/
    p_overlay_palette = &add_frame_p->overlay_palette[0];
    for (i = 0; i < 256; i++)
    {
        R = (U32) ((U8) (*p_gdi_palette >> 16));
        G = (U32) ((U8) (*p_gdi_palette >> 8));
        B = (U32) ((U8) (*p_gdi_palette));

        Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
        U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
        V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

        (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
        p_overlay_palette++;
        p_gdi_palette++;
    }

    *palette_size = add_frame_p->overlay_frame_palette_size;
    *palette_address = &add_frame_p->overlay_palette[0];

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_add_frame_file_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_add_frame_file_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 la_offset_x;
    S32 ra_offset_x;
    S32 file_idx_offset_x;
    S32 file_idx_offset_y;
    S32 offset_y;
    S32 image_width;
    S32 image_height;
    S32 slash_img_width;
    S32 tens_place = 0;
    S32 units_place = 0;
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_FILE_NUM_INTERVAL (1)
#define MMI_CAMCO_OSD_FILE_SLASH_INTERVAL (3)

    la_offset_x = add_frame_p->la_touch.offset_x;
    ra_offset_x = add_frame_p->ra_touch.offset_x;

    file_idx_offset_x = mmi_camco_osd_skin_p->add_frame.file_index.offset_x;
    file_idx_offset_y = mmi_camco_osd_skin_p->add_frame.file_index.offset_y;

    offset_y = mmi_camco_osd_skin_p->add_frame.left_arrow.offset_y;

    /* draw lefe arrow */
    gdi_image_draw_id(
        la_offset_x + img_press_shift(add_frame_p->la_touch.is_press), 
        offset_y + img_press_shift(add_frame_p->la_touch.is_press), 
        (U16) IMG_ID_CAMCO_ARROW_LEFT);

    /* draw right arrow */
    gdi_image_draw_id(
        ra_offset_x + img_press_shift(add_frame_p->ra_touch.is_press), 
        offset_y + img_press_shift(add_frame_p->ra_touch.is_press), 
        (U16) IMG_ID_CAMCO_ARROW_RIGHT);

    /* draw "file index / file count" */
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OSD_TIMER_0, &image_width, &image_height);

    tens_place = (mmi_camco_osd_p->add_frame.highlighted_idx + 1) / 10;
    units_place = (mmi_camco_osd_p->add_frame.highlighted_idx + 1) % 10;

    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + tens_place));
    file_idx_offset_x += image_width + MMI_CAMCO_OSD_FILE_NUM_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + units_place));

    file_idx_offset_x += image_width + MMI_CAMCO_OSD_FILE_SLASH_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) IMG_ID_CAMCO_SLASH);

    gdi_image_get_dimension_id(IMG_ID_CAMCO_SLASH, &slash_img_width, &image_height);

    tens_place = mmi_camco_osd_p->add_frame.frame_count / 10;
    units_place = mmi_camco_osd_p->add_frame.frame_count % 10;

    file_idx_offset_x += slash_img_width + MMI_CAMCO_OSD_FILE_SLASH_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + tens_place));
    file_idx_offset_x += image_width + MMI_CAMCO_OSD_FILE_NUM_INTERVAL;
    gdi_image_draw_id(file_idx_offset_x, file_idx_offset_y, (U16) (IMG_ID_CAMCO_OSD_TIMER_0 + units_place));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_add_frame_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_is_add_frame_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->add_frame.is_picked;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_add_frame_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_add_frame_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->add_frame.is_picked = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_add_frame_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_add_frame_move_prev())
    {
        mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

        add_frame_p->highlighted_idx = add_frame_p->frame_count - 1;
    }

    mmi_camco_osd_draw_osd();
    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ADD_FRAME_MOVE_DUR, mmi_camco_osd_add_frame_prev_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_add_frame_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_add_frame_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_add_frame_move_next())
    {
        mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;

        add_frame_p->highlighted_idx = 0;
    }

    mmi_camco_osd_draw_osd();
    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ADD_FRAME_MOVE_DUR, mmi_camco_osd_add_frame_next_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_time_stamp_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_is_time_stamp_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->time_stamp.is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_time_stamp_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_time_stamp_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->time_stamp.is_enable = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_time_stamp_color_idx_on_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  palette_size        [OUT]       
 *  palette_address     [OUT]       
 *  overlay_width       [?]         
 *  overlay_height      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_time_stamp_color_idx_on_layer(
        U8 *palette_size,
        U32 **palette_address,
        S32 *overlay_width,
        S32 *overlay_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color *p_gdi_palette;
    U16 i;
    U32 Y, U, V;
    U32 R, G, B;
    U32 *p_overlay_palette;
    U16 image_idx = 0;
    U16 colon_image_idx = 0;
    mmi_camco_osd_time_stamp_struct *time_stamp_p = &mmi_camco_osd_p->time_stamp;
    mmi_camco_capsize_enum capsize;
    S32 layer_width = 0;
    S32 layer_height = 0;
    applib_time_struct time;
    S32 offset_x;
    S32 offset_y;
    S32 num_img_width;
    S32 num_img_height;
    S32 colon_img_width;
    S32 colon_img_height;
    gdi_color source_key = 0;
    U8 offset_x_from_right = 0;
    U8 offset_y_from_bottom = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_date_time(&time);

    capsize = mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPSIZE);

    if (capsize == MMI_CAMCO_CAPSIZE_WALLPAPER)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_COLON;
        layer_width = LCD_WIDTH;
        layer_height = LCD_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.wallpaper.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.wallpaper.offset_y_from_bottom;
    }
#if defined(HORIZONTAL_CAMERA)
    else if (capsize == MMI_CAMCO_CAPSIZE_HLCD)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_5_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_5_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.HLCD.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.HLCD.offset_y_from_bottom;
    }
#endif /* defined(HORIZONTAL_CAMERA) */ 
    else if (capsize == MMI_CAMCO_CAPSIZE_VGA || capsize == MMI_CAMCO_CAPSIZE_1MP || capsize == MMI_CAMCO_CAPSIZE_2MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_320X240_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_3_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_3_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.VGA_to_2M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.VGA_to_2M.offset_y_from_bottom;
    }
    else if (capsize == MMI_CAMCO_CAPSIZE_3MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_256X192_0; 
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_256X192_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_1_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_1_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.Three_M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.Three_M.offset_y_from_bottom;
    }
#ifdef __MMI_CAMCO_FEATURE_CAM_IMGSZIE_SUPPORT_4M__     
    else if (capsize == MMI_CAMCO_CAPSIZE_4MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_288X216_0; 
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_288X216_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_2_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_2_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.Four_M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.Four_M.offset_y_from_bottom;
    }
#endif
#ifdef __MMI_CAMCO_FEATURE_CAM_IMGSZIE_SUPPORT_5M__ 
    else if (capsize == MMI_CAMCO_CAPSIZE_5MP)
    {
        image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_324X243_0;
        colon_image_idx = (U16) IMG_ID_CAMCO_TIME_STAMP_COLOR_IDX_324X243_COLON;
        layer_width = MMI_CAMCO_TIME_STAMP_COLOR_IDX_4_WIDTH;
        layer_height = MMI_CAMCO_TIME_STAMP_COLOR_IDX_4_HEIGHT;
        offset_x_from_right = mmi_camco_osd_skin_p->time_stamp.Five_M.offset_x_from_right;
        offset_y_from_bottom = mmi_camco_osd_skin_p->time_stamp.Five_M.offset_y_from_bottom;
    }
#endif
    gdi_image_get_dimension_id(image_idx, &num_img_width, &num_img_height);
    gdi_image_get_dimension_id(colon_image_idx, &colon_img_width, &colon_img_height);

    offset_x = layer_width -
        (offset_x_from_right +
         12 * num_img_width +
         2 * mmi_camco_osd_skin_p->time_stamp.date_interval + mmi_camco_osd_skin_p->time_stamp.offset_to_time);

    offset_y = layer_height - offset_y_from_bottom;

    gdi_layer_push_and_set_active(time_stamp_p->overlay_frame_layer_h);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_resize(layer_width, layer_height);

    /* Get the source key of timestamp and fill the color to all layer */
    gdi_image_draw_id_with_transparent_color(0, 0, (U16) image_idx);
    source_key = gdi_image_bmp_get_transparent_index();
    memset(time_stamp_p->overlay_frame_layer_buf_p, source_key, (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);

    /* year */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear / 1000) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear / 100) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nYear) % 10));
    offset_x += num_img_width;

    offset_x += mmi_camco_osd_skin_p->time_stamp.date_interval;

    /* month */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMonth / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMonth) % 10));
    offset_x += num_img_width;

    offset_x += mmi_camco_osd_skin_p->time_stamp.date_interval;

    /* day */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nDay / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nDay) % 10));
    offset_x += num_img_width;

    offset_x += mmi_camco_osd_skin_p->time_stamp.offset_to_time;

    /* hour */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nHour / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nHour) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) colon_image_idx);
    offset_x += colon_img_width;

    /* Min */
    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMin / 10) % 10));
    offset_x += num_img_width;

    gdi_image_draw_id_with_transparent_color(offset_x, offset_y, (U16) (image_idx + (time.nMin) % 10));

    p_gdi_palette = gdi_layer_get_palette();

    time_stamp_p->overlay_frame_palette_size = gdi_image_bmp_get_palette_size();
    /*************** RGB to YUV format **************************************************
    *
    *     [MSDN RGB888 to YUV444 (16bits)]
    *
    *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
    *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
    *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
    *     
    *     These formulas produce 8-bit results using coefficients 
    *     that require no more than 8 bits of (unsigned) precision. 
    *     Intermediate results require up to 16 bits of precision.
    *
    ***************************************************************************************/
    p_overlay_palette = &time_stamp_p->overlay_palette[0];
    for (i = 0; i < 256; i++)
    {
        R = (U32) ((U8) (*p_gdi_palette >> 16));
        G = (U32) ((U8) (*p_gdi_palette >> 8));
        B = (U32) ((U8) (*p_gdi_palette));

        Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
        U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
        V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

        (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
        p_overlay_palette++;
        p_gdi_palette++;
    }

    *palette_size = time_stamp_p->overlay_frame_palette_size;
    *palette_address = &time_stamp_p->overlay_palette[0];
    *overlay_width = layer_width;
    *overlay_height = layer_height;

    gdi_layer_pop_and_restore_active();

}
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_facedetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_facedetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->facedetect.is_tracking = MMI_FALSE;
    /* focused green */
    mmi_camco_osd_p->facedetect.focused_color = gdi_act_color_from_rgb(255, 0, 255, 0);
    mmi_camco_osd_p->facedetect.focused_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* tracking white */
    mmi_camco_osd_p->facedetect.tracking_color = gdi_act_color_from_rgb(255, 240, 228, 15);
    mmi_camco_osd_p->facedetect.tracking_border_color = gdi_act_color_from_rgb(255, 240, 228, 15);

    /* 255 = no opacity, 0 = full opacity */
    mmi_camco_osd_p->facedetect.opacity = 200;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_clear_facedetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_clear_facedetect_region(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->facedetect.tracking_region, 0, sizeof(mmi_camco_osd_p->facedetect.tracking_region));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_facedetect_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_facedetect_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->facedetect.is_tracking = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_facedetect_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void     
 * RETURNS
 *  BOOL
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_get_facedetect_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->facedetect.is_tracking;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_facedetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  facedetect_region       [IN]        
 *  type                    [IN]        
 *  center_x                [IN]        
 *  center_y                [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_facedetect_region(
        U16 facedetect_region,
        mmi_camco_osd_facedetect_type_enum type,
        S32 center_x,
        S32 center_y,
        S32 width,
        S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(facedetect_region < MMI_CAMCO_SUPPORT_FACE_NUM);

    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].type = type;
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].x1 = center_x - (width >> 1);
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].x2 = center_x + (width >> 1);
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].y1 = center_y - (height >> 1);
    mmi_camco_osd_p->facedetect.tracking_region[facedetect_region].y2 = center_y + (height >> 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_facedetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_facedetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gdi_color rect_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    gdi_color border_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    S32 region_width = 0;
    S32 edge_pixel = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_SUPPORT_FACE_NUM; i++)
    {
        if (mmi_camco_osd_p->facedetect.tracking_region[i].type != MMI_CAMCO_OSD_FACEDETECT_TYPE_NULL)
        {
            if (mmi_camco_osd_p->facedetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED)
            {
                rect_color = mmi_camco_osd_p->facedetect.focused_color;
                border_color = mmi_camco_osd_p->facedetect.focused_border_color;
            }
            else if (mmi_camco_osd_p->facedetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_TRACKING)
            {
                rect_color = mmi_camco_osd_p->facedetect.tracking_color;
                border_color = mmi_camco_osd_p->facedetect.tracking_border_color;

            }
            else
            {
                MMI_ASSERT(0);
            }

            /* main face */
            if (mmi_camco_osd_is_in_smile_dect_scrn() && i == 0)
            {
                rect_color = mmi_camco_osd_p->facedetect.focused_color;
                border_color = mmi_camco_osd_p->facedetect.focused_color;
            }

            region_width =
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - mmi_camco_osd_p->facedetect.tracking_region[i].x1;
            edge_pixel = (MMI_CAMCO_OSD_FACE_EDGE_RATIO * region_width) / 100;

            /* top-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1 + edge_pixel + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1 + edge_pixel - 1,
                border_color);

            /* top-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 - 1 + (edge_pixel + 1),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y1 + 1 + (edge_pixel - 1),
                border_color);

            /* bottom-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].x1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);

            /* bottom-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->facedetect.tracking_region[i].x2,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->facedetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->facedetect.tracking_region[i].y2 - 1,
                border_color);
        }
    }

}

#ifdef __SMILE_SHUTTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_smiledetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_init_smiledetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->smiledetect.is_tracking = MMI_FALSE;
    /* focused green */
    mmi_camco_osd_p->smiledetect.focused_color = gdi_act_color_from_rgb(255, 255, 128, 0);
    mmi_camco_osd_p->smiledetect.focused_border_color = gdi_act_color_from_rgb(255, 0, 0, 0);

    /* tracking white */
    mmi_camco_osd_p->smiledetect.tracking_color = gdi_act_color_from_rgb(255, 255, 128, 15);
    mmi_camco_osd_p->smiledetect.tracking_border_color = gdi_act_color_from_rgb(255, 240, 128, 15);

    /* 255 = no opacity, 0 = full opacity */
    mmi_camco_osd_p->smiledetect.opacity = 200;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_smileshot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_smileshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width, height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 image_region_width;
    S32 image_region_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_get_preview_region(
        &image_region_offset_x,
        &image_region_offset_y,
        &image_region_width,
        &image_region_height);

    gdi_image_get_dimension_id(IMG_ID_CAMCO_CAPMODE_SMILE_SHOT_DET, &width, &height);
    gdi_image_draw_id(
        image_region_offset_x + (mmi_camco_osd_p->osd_width - image_region_offset_x - width) >> 1,
        image_region_offset_y,
        IMG_ID_CAMCO_CAPMODE_SMILE_SHOT_DET);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_smiledetect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_draw_smiledetect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gdi_color rect_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    gdi_color border_color = gdi_act_color_from_rgb(255, 255, 255, 255);
    S32 region_width = 0;
    S32 edge_pixel = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CAMCO_SUPPORT_FACE_NUM; i++)
    {
        if (mmi_camco_osd_p->smiledetect.tracking_region[i].type != MMI_CAMCO_OSD_FACEDETECT_TYPE_NULL)
        {
            if (mmi_camco_osd_p->smiledetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED)
            {
                rect_color = mmi_camco_osd_p->smiledetect.focused_color;
                border_color = mmi_camco_osd_p->smiledetect.focused_border_color;
            }
            else if (mmi_camco_osd_p->smiledetect.tracking_region[i].type == MMI_CAMCO_OSD_FACEDETECT_TYPE_TRACKING)
            {
                rect_color = mmi_camco_osd_p->smiledetect.tracking_color;
                border_color = mmi_camco_osd_p->smiledetect.tracking_border_color;

            }
            else
            {
                MMI_ASSERT(0);
            }

            region_width = mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - mmi_camco_osd_p->smiledetect.tracking_region[i].x1;
            edge_pixel = (MMI_CAMCO_OSD_FACE_EDGE_RATIO * region_width)/100;
            
            /* top-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1 + edge_pixel + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1 + edge_pixel - 1,
                border_color);

            /* top-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 - 1 + (edge_pixel + 1),
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + edge_pixel,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y1 + 1 + (edge_pixel - 1),
                border_color);

            /* bottom-left */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1 + edge_pixel + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1 + edge_pixel - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x1 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);

            /* bottom-right */
            /* H */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);

            /* V */
            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1 - (edge_pixel + 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 + 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 + 1,
                border_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - edge_pixel,
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2,
                rect_color);

            gdi_draw_line(
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1 - (edge_pixel - 1),
                mmi_camco_osd_p->smiledetect.tracking_region[i].x2 - 1,
                mmi_camco_osd_p->smiledetect.tracking_region[i].y2 - 1,
                border_color);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_clear_smiledetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_clear_smiledetect_region(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_camco_osd_p->smiledetect.tracking_region, 0, sizeof(mmi_camco_osd_p->smiledetect.tracking_region));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_smiledetect_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_smiledetect_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->smiledetect.is_tracking = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_zoom_ev_enable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enable       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_osd_set_zoom_ev_enable(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->smiledetect.is_zoom_ev_enable = is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_smiledetect_region
 * DESCRIPTION
 *  
 * PARAMETERS
 *  smiledetect_region      [IN]        
 *  type                    [IN]        
 *  center_x                [IN]        
 *  center_y                [IN]        
 *  width                   [IN]        
 *  height                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_smiledetect_region(
        U16 smiledetect_region,
        mmi_camco_osd_facedetect_type_enum type,
        S32 center_x,
        S32 center_y,
        S32 width,
        S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(smiledetect_region < MMI_CAMCO_SUPPORT_FACE_NUM);

    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].type = type;
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].x1 = center_x - (width >> 1);
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].x2 = center_x + (width >> 1);
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].y1 = center_y - (height >> 1);
    mmi_camco_osd_p->smiledetect.tracking_region[smiledetect_region].y2 = center_y + (height >> 1);

}

#endif /* __SMILE_SHUTTER_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_in_smile_dect_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_is_in_smile_dect_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMILE_SHUTTER_SUPPORT__    
    return (!mmi_camco_osd_p->smiledetect.is_zoom_ev_enable);
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_direct_setting_img_translate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_id     [IN]        
 * RETURNS
 *  MMI_ID_TYPE
 *****************************************************************************/
MMI_ID_TYPE mmi_camco_osd_direct_setting_img_translate(MMI_ID_TYPE str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(str_id)
    {
        case STR_ID_CAMCO_CAPMODE_NORMAL:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_NORMAL_ICON;
            break;
        }
        case STR_ID_CAMCO_CAPMODE_BEST_SHOT:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_BEST_ICON;
            break;
        }
        case STR_ID_CAMCO_CAPMODE_CONT_SHOT:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_CONT_ICON;
            break;
        }
        case STR_ID_CAMCO_CAPMODE_BURST_SHOT_SEL:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_BURSTSHOT_ICON;
            break;
        }
        case STR_ID_CAMCO_CAPMODE_EV_BRACKET_SEL:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_EVSHOT_ICON;
            break;
        }
        case STR_ID_CAMCO_CAPMODE_PANORAMA:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_PANORAMA_ICON;
            break;
        }
        case STR_ID_CAMCO_CAPMODE_ADD_FRAME:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_ADDFRAME_ICON;
            break;
        }
        case STR_ID_CAMCO_CAPMODE_SMILE_SHOT:
        {
            return IMG_ID_CAMCO_DIR_SETTING_CAPMODE_SMILESHOT_ICON;
            break;
        }
        case STR_ID_CAMCO_SCENEMODE_AUTO:
        {
            return IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON;
            break;
        }
        case STR_ID_CAMCO_SCENEMODE_PORTRAIT:
        {
            return IMG_ID_CAMCO_DIR_SETTING_SCN_PORTRAIT_ICON;
            break;
        }
        case STR_ID_CAMCO_SCENEMODE_LANDSCAPE:
        {
            return IMG_ID_CAMCO_DIR_SETTING_SCN_LANDSCAPE_ICON;
            break;
        }
        case STR_ID_CAMCO_SCENEMODE_NIGHT:
        {
            return IMG_ID_CAMCO_DIR_SETTING_SCN_NIGHT_ICON;
            break;
        }
        case STR_ID_CAMCO_SCENEMODE_SPORT:
        {
            return IMG_ID_CAMCO_DIR_SETTING_SCN_SPORT_ICON;
            break;
        }
        case STR_ID_CAMCO_SCENEMODE_DOCUMENT:
        {
            return IMG_ID_CAMCO_DIR_SETTING_SCN_DOC_ICON;
            break;
        }
        case STR_ID_CAMCO_SCENEMODE_ANTI_SHAKE:
        {
            return IMG_ID_CAMCO_DIR_SETTING_SCN_ANTI_ICON;
            break;
        } 
        case STR_ID_CAMCO_FLASH_AUTO:
        {
            return IMG_ID_CAMCO_DIR_SETTING_FLASH_AUTO_ICON;
            break;
        }
        case STR_ID_CAMCO_FLASH_FORCE_ON:
        {
            return IMG_ID_CAMCO_DIR_SETTING_FLASH_ON_ICON;
            break;
        }
        case STR_ID_CAMCO_FLASH_RED_EYE:
        {
            return IMG_ID_CAMCO_DIR_SETTING_FLASH_RED_EYE_ICON;
            break;
        }
        case STR_GLOBAL_OFF:
        {
        #ifndef MMI_CAMCO_SUPPORT_FLASH            
            return IMG_ID_CAMCO_DIR_SETTING_TIMER_NOLIMIT_ICON;        
        #else
            return IMG_ID_CAMCO_DIR_SETTING_FLASH_OFF_ICON;
        #endif
            break;
        }  
        case STR_ID_CAMCO_SELFTIMER_10S:
        {                    
            return IMG_ID_CAMCO_DIR_SETTING_TIMER_10S_ICON;
            break;
        }              
        case STR_ID_CAMCO_SELFTIMER_5S:
        {                    
            return IMG_ID_CAMCO_DIR_SETTING_TIMER_5S_ICON;
            break;
        }              
        default:
            return IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_blt_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_blt_layer(mmi_camco_osd_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        case MMI_CAMCO_OSD_STATE_FOCUSE:
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_HIDE:
            gdi_layer_set_blt_layer(0, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            /* register key event */
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            if (state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE)
            {
                gdi_layer_set_blt_layer(
                    mmi_camco_osd_p->base_layer_h,
                    mmi_camco_osd_p->video_recoding_osd.osd_layer_ev_zoom_area_h,
                    mmi_camco_osd_p->video_recoding_osd.osd_layer_rec_time_area_h,
                    mmi_camco_osd_p->video_recoding_osd.osd_layer_softkey_area_h);
            }
        #else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
        #endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->imageselect_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__

        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->panorama_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, 0, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT:
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, mmi_camco_osd_p->sublcd_osd_layer_h, 0, 0);

            break;
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

        case MMI_CAMCO_OSD_STATE_EXIT:
        {
            /* exit state */
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, 0, 0, 0);
            break;
        }

        default:
            MMI_ASSERT(0);

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_enter_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_enter_state(mmi_camco_osd_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    mmi_camco_osd_p->osd_state = state;

    /* reset all variables */
    mmi_camco_osd_p->center_hint.str_ptr = NULL;
    mmi_camco_osd_p->center_hint.is_processing = MMI_FALSE;
    mmi_camco_osd_p->center_hint.dot_count = 0;

    mmi_camco_osd_p->corner_hint.str_ptr = NULL;

    mmi_camco_osd_p->focus_hint.img_id = NULL;
    mmi_camco_osd_p->focus_hint.is_hint_show = MMI_FALSE;

    /* reset key handlers */
    ClearKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    ClearKeyHandler(KEY_CSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_CSK, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_camco_dummy_func, KEY_CSK, KEY_EVENT_REPEAT);

    /* State transition, stop zoom */
    mmi_camco_osd_stop_zoom();

    /* ===================================================================================== */
    /*                             clear all touch usable flag                               */
    /* ===================================================================================== */
    /* preview */
    mmi_camco_osd_p->cam_direct_setting_screen.scene_mode.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.flash.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.capture.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.back.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.capmode.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_location.is_press = MMI_FALSE;
    
    mmi_camco_osd_p->rec_direct_setting_screen.scene_mode.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.record.is_usable = MMI_FALSE;    
    mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.back.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_location.is_press = MMI_FALSE;
    
    mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.is_usable = MMI_FALSE;
    mmi_camco_osd_p->panorama_screen.capture.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.capture.is_usable = MMI_FALSE;
    mmi_camco_osd_p->is_show_zoom = MMI_FALSE;

    /* direct setting */
    for (i = 0; i < MMI_CAMCO_OSD_MAX_DIRECT_SETTING_COUNT; i++)
    {
        mmi_camco_osd_p->cam_direct_setting_screen.scn_setting_item[i].is_usable = MMI_FALSE;
        mmi_camco_osd_p->cam_direct_setting_screen.capmode_setting_item[i].is_usable = MMI_FALSE;
        mmi_camco_osd_p->cam_direct_setting_screen.flash_setting_item[i].is_usable = MMI_FALSE;
        mmi_camco_osd_p->rec_direct_setting_screen.scn_setting_item[i].is_usable = MMI_FALSE;
    }
    mmi_camco_osd_p->cam_direct_setting_screen.setting_wnd_body.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_location_region.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_zoom_botton.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_zoom_top.is_usable = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.zoom_region.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.setting_wnd_body.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_location_region.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_zoom_botton.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_zoom_top.is_usable = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.zoom_region.is_usable = MMI_FALSE;

    /* advance setting */
    for (i = 0; i < mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count; i++)
        mmi_camco_osd_p->advance_setting_screen.Level1_setting_wnd_item[i].is_usable = MMI_FALSE;

    for (i = 0; i < mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count; i++)
        mmi_camco_osd_p->advance_setting_screen.Level2_setting_wnd_item[i].is_usable = MMI_FALSE;

    mmi_camco_osd_p->advance_setting_screen.back.is_usable = MMI_FALSE;
    mmi_camco_osd_p->advance_setting_screen.OK.is_usable = MMI_FALSE;    
    mmi_camco_osd_p->ad_setting_menu_touch[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_touch[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_touch[2].is_usable = MMI_FALSE;

    mmi_camco_osd_p->ad_setting_menu_pre_touch[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[2].is_usable = MMI_FALSE;

    mmi_camco_osd_p->ad_setting_menu_next_touch[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_next_touch[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_next_touch[2].is_usable = MMI_FALSE;

    mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;

    mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_region.is_usable = MMI_FALSE;
    mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_region.is_usable = MMI_FALSE;
    /* img list */
    for (i = 0; i < mmi_camco_osd_p->captured_img_select_screen.img_list_count; i++)
    {
        mmi_camco_osd_p->captured_img_select_screen.image_list_touch[i].is_usable = MMI_FALSE;
    }
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.back.is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.save.is_usable = MMI_FALSE;

    mmi_camco_osd_p->captured_screen.tool_bar[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.tool_bar[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.tool_bar[2].is_usable = MMI_FALSE;

    mmi_camco_osd_p->forward_screen.item[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.item[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.item[2].is_usable = MMI_FALSE;

    /* confirm */
    mmi_camco_osd_p->confirm_screen.confirm_lsk.is_usable = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.confirm_rsk.is_usable = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.tool_bar[0].is_usable = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.tool_bar[1].is_usable = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.tool_bar[2].is_usable = MMI_FALSE;
    mmi_camco_osd_p->add_frame.la_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->add_frame.ra_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->add_frame.ok.is_usable = MMI_FALSE;
    mmi_camco_osd_p->add_frame.back.is_usable = MMI_FALSE;

    mmi_camco_osd_p->recording_screen.slider_location.is_usable = MMI_FALSE;
    mmi_camco_osd_p->recording_screen.slider_location_region.is_usable = MMI_FALSE;
    mmi_camco_osd_p->recording_screen.start.is_usable = MMI_FALSE;
    mmi_camco_osd_p->recording_screen.stop.is_usable = MMI_FALSE;

    mmi_camco_osd_p->forward_screen.back.is_usable = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.confirm_body.is_usable = MMI_FALSE;

    mmi_camco_osd_p->panorama_screen.OK.is_usable = MMI_FALSE;
    mmi_camco_osd_p->panorama_screen.cancel.is_usable = MMI_FALSE;
    
    mmi_camco_osd_p->storage_select_screen.back.is_usable = MMI_FALSE;
    
    /* pano select */
    mmi_camco_osd_p->panorama.ua_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->panorama.da_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->panorama.ra_touch.is_usable = MMI_FALSE;
    mmi_camco_osd_p->panorama.la_touch.is_usable = MMI_FALSE;    

#ifdef DUAL_CAMERA_SUPPORT
    mmi_camco_osd_p->sensor_switcher.is_usable = MMI_TRUE;    
#else
    mmi_camco_osd_p->sensor_switcher.is_usable = MMI_FALSE;    
#endif

    /* ===================================================================================== */
    /*                                           END                                         */
    /* ===================================================================================== */

    /* ===================================================================================== */
    /*                             clear all touch hilite                                    */
    /* ===================================================================================== */
    /* preview */
    mmi_camco_osd_p->cam_direct_setting_screen.scene_mode.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.flash.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.capture.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.capmode.is_press = MMI_FALSE;
    
    mmi_camco_osd_p->rec_direct_setting_screen.scene_mode.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.record.is_press = MMI_FALSE;    
    mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_press = MMI_FALSE;

    mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.is_press = MMI_FALSE; 
    mmi_camco_osd_p->panorama_screen.capture.is_press = MMI_FALSE;   
    mmi_camco_osd_p->cam_direct_setting_screen.capture.is_press = MMI_FALSE;    

    /* direct setting */
    for (i = 0; i < MMI_CAMCO_OSD_MAX_DIRECT_SETTING_COUNT; i++)
    {
        mmi_camco_osd_p->cam_direct_setting_screen.scn_setting_item[i].is_press = MMI_FALSE;
        mmi_camco_osd_p->cam_direct_setting_screen.capmode_setting_item[i].is_press = MMI_FALSE;
        mmi_camco_osd_p->cam_direct_setting_screen.flash_setting_item[i].is_press = MMI_FALSE;
        mmi_camco_osd_p->rec_direct_setting_screen.scn_setting_item[i].is_press = MMI_FALSE;
    }
    mmi_camco_osd_p->cam_direct_setting_screen.setting_wnd_body.is_press = MMI_FALSE;    
    mmi_camco_osd_p->cam_direct_setting_screen.slider_location_region.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_zoom_botton.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.slider_zoom_top.is_press = MMI_FALSE;
    mmi_camco_osd_p->cam_direct_setting_screen.zoom_region.is_press = MMI_FALSE;    
    mmi_camco_osd_p->rec_direct_setting_screen.setting_wnd_body.is_press = MMI_FALSE;    
    mmi_camco_osd_p->rec_direct_setting_screen.slider_location_region.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_zoom_botton.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.slider_zoom_top.is_press = MMI_FALSE;
    mmi_camco_osd_p->rec_direct_setting_screen.zoom_region.is_press = MMI_FALSE;    

    /* advance setting */
    for (i = 0; i < mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count; i++)
        mmi_camco_osd_p->advance_setting_screen.Level1_setting_wnd_item[i].is_press = MMI_FALSE;

    for (i = 0; i < mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count; i++)
        mmi_camco_osd_p->advance_setting_screen.Level2_setting_wnd_item[i].is_press = MMI_FALSE;

    mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_FALSE;
    mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_FALSE;    
    mmi_camco_osd_p->ad_setting_menu_touch[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_touch[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_touch[2].is_press = MMI_FALSE;

    mmi_camco_osd_p->ad_setting_menu_pre_touch[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[2].is_press = MMI_FALSE;

    mmi_camco_osd_p->ad_setting_menu_next_touch[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_next_touch[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->ad_setting_menu_next_touch[2].is_press = MMI_FALSE;

    mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_press = MMI_FALSE;

    mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_region.is_press = MMI_FALSE;
    mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_region.is_press = MMI_FALSE;
    /* img list */
    for (i = 0; i < mmi_camco_osd_p->captured_img_select_screen.img_list_count; i++)
    {
        mmi_camco_osd_p->captured_img_select_screen.image_list_touch[i].is_press = MMI_FALSE;
    }
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.back.is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_img_select_screen.save.is_press = MMI_FALSE;    

    mmi_camco_osd_p->captured_screen.tool_bar[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.tool_bar[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.tool_bar[2].is_press = MMI_FALSE;
    mmi_camco_osd_p->captured_screen.back.is_press = MMI_FALSE;

    mmi_camco_osd_p->forward_screen.item[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.item[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.item[2].is_press = MMI_FALSE;

    /* confirm */
    mmi_camco_osd_p->confirm_screen.confirm_lsk.is_press = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.confirm_rsk.is_press = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.tool_bar[0].is_press = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.tool_bar[1].is_press = MMI_FALSE;
    mmi_camco_osd_p->confirm_screen.tool_bar[2].is_press = MMI_FALSE;
    mmi_camco_osd_p->add_frame.la_touch.is_press = MMI_FALSE;
    mmi_camco_osd_p->add_frame.ra_touch.is_press = MMI_FALSE;
    mmi_camco_osd_p->add_frame.ok.is_press = MMI_FALSE;
    mmi_camco_osd_p->add_frame.back.is_press = MMI_FALSE;

    mmi_camco_osd_p->recording_screen.slider_location.is_press = MMI_FALSE;
    mmi_camco_osd_p->recording_screen.slider_location_region.is_press = MMI_FALSE;
    mmi_camco_osd_p->recording_screen.start.is_press = MMI_FALSE;
    mmi_camco_osd_p->recording_screen.stop.is_press = MMI_FALSE;

    mmi_camco_osd_p->forward_screen.back.is_press = MMI_FALSE;
    mmi_camco_osd_p->forward_screen.confirm_body.is_press = MMI_FALSE;    

    mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_FALSE;
    mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_FALSE;
    
    mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_FALSE;
    
    /* pano select */
    mmi_camco_osd_p->panorama.ua_touch.is_press = MMI_FALSE;
    mmi_camco_osd_p->panorama.da_touch.is_press = MMI_FALSE;
    mmi_camco_osd_p->panorama.ra_touch.is_press = MMI_FALSE;
    mmi_camco_osd_p->panorama.la_touch.is_press = MMI_FALSE;        

    mmi_camco_osd_p->sensor_switcher.is_press = MMI_FALSE;            
    /* ===================================================================================== */
    /*                                           END                                         */
    /* ===================================================================================== */
    if(mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_HINT )
        mmi_pen_reset();
    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;    
    mmi_camco_osd_p->imgselect_cache.is_cache_img_osd_redraw = MMI_TRUE;
    mmi_camco_osd_p->imgselect_cache.is_cache_highlight_osd_redraw = MMI_TRUE;

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
    mmi_camco_osd_imageselect_reset_environment();
#endif 
#ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
    mmi_camco_osd_panorama_shot_reset_environment();
#endif 

    if (mmi_camco_osd_is_horz_UI())
    {
        mmi_camco_osd_recording_reset_environment();
    }
#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    mmi_camco_osd_sublcd_stop_hint_reset_environment();
#endif 

#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif 
    /* stop timer */
    gui_cancel_timer(mmi_camco_osd_draw_hint_process_cyclic);
    gui_cancel_timer(mmi_camco_osd_draw_focus_hint_process_cyclic);
    gui_cancel_timer(mmi_camco_osd_iconlist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_iconlist_next_cyclic);
    gui_cancel_timer(mmi_camco_osd_menulist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_menulist_next_cyclic);
    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);
    gui_cancel_timer(mmi_camco_start_fast_zoom_in);
    gui_cancel_timer(mmi_camco_start_fast_zoom_out);
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__

#endif 
#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    gui_cancel_timer(mmi_camco_sublcd_osd_draw_hint_process_cyclic);
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
    gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
    gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    mmi_camco_osd_l1_scrolling_text_stop();

    if (mmi_camco_osd_is_horz_UI())
    {
        
    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT)
        {
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            gdi_layer_resize(SUBLCD_HEIGHT, SUBLCD_WIDTH);
            gdi_layer_pop_and_restore_active();
            mmi_camco_osd_p->is_horizontal = MMI_FALSE;
        }
        else
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */             
        {
            if (mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_RECORDING &&
                mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_PAUSE)
            {
                if (mmi_camco_osd_p->is_horizontal)
                {
                    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
                    gdi_layer_pop_and_restore_active();
                    mmi_camco_osd_p->is_horizontal = MMI_FALSE;
                }
            }
        }
    }

    /* reset opacity */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    gdi_layer_set_opacity(MMI_FALSE, 0);
    gdi_layer_pop_and_restore_active();

    switch (state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, 0, 0, 0);
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR ||
                mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
            {
                mmi_camco_osd_p->confirm_screen.confirm_lsk.is_usable = MMI_TRUE;
                mmi_camco_osd_p->confirm_screen.confirm_rsk.is_usable = MMI_TRUE;
            }
            else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
            {
                mmi_camco_osd_gen_option_menulist();
                mmi_camco_osd_p->confirm_screen.tool_bar[0].is_usable = MMI_TRUE;
                mmi_camco_osd_p->confirm_screen.tool_bar[1].is_usable = MMI_TRUE;
                mmi_camco_osd_p->confirm_screen.tool_bar[2].is_usable = MMI_TRUE;
                mmi_camco_osd_p->captured_screen.back.is_usable = MMI_TRUE;
                SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            }
            else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
            {
                mmi_camco_osd_p->captured_screen.back.is_usable = MMI_TRUE;
                SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            if (MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {
                mmi_camco_osd_gen_camera_status_icon();
            }
            else if (MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW == state)
            {
                mmi_camco_osd_gen_video_status_icon();
            }

            if (MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {            
                mmi_camco_osd_cam_direct_setting_struct *p = &mmi_camco_osd_p->cam_direct_setting_screen;
                
                mmi_camco_setting_gen_mainlist(mmi_camco_setting_get_mainlist_type());
                mmi_camco_setting_get_camzoom_info(
                    &mmi_camco_osd_p->setting_slider.max_value,
                    &mmi_camco_osd_p->setting_slider.min_value,
                    &mmi_camco_osd_p->setting_slider.one_step_value,
                    &mmi_camco_osd_p->setting_slider.step_count);
            }
            else if(MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW == state)
            {
                mmi_camco_osd_rec_direct_setting_struct *p = &mmi_camco_osd_p->rec_direct_setting_screen;
                
                mmi_camco_setting_gen_mainlist(mmi_camco_setting_get_mainlist_type());
                mmi_camco_setting_get_vdozoom_info(
                    &mmi_camco_osd_p->setting_slider.max_value,
                    &mmi_camco_osd_p->setting_slider.min_value,
                    &mmi_camco_osd_p->setting_slider.one_step_value,
                    &mmi_camco_osd_p->setting_slider.step_count);
            }

            /* set touch region */
            if (MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {
                if (!mmi_camco_osd_is_in_smile_dect_scrn())
                {
                    mmi_camco_osd_p->cam_direct_setting_screen.scene_mode.is_usable = MMI_TRUE;
                #ifdef MMI_CAMCO_SUPPORT_FLASH
                    if (mmi_camco_setting_flash_is_enable())
                        mmi_camco_osd_p->cam_direct_setting_screen.flash.is_usable = MMI_TRUE;
                #else /* MMI_CAMCO_SUPPORT_FLASH */ 
                    if (mmi_camco_setting_selftime_is_enable())
                        mmi_camco_osd_p->cam_direct_setting_screen.flash.is_usable = MMI_TRUE;
                #endif /* MMI_CAMCO_SUPPORT_FLASH */ 
                    if (mmi_camco_osd_p->is_show_zoom)
                    {                
                        mmi_camco_osd_p->cam_direct_setting_screen.slider_location_region.is_usable = MMI_TRUE;
                        mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_usable = MMI_TRUE;
                        mmi_camco_osd_p->cam_direct_setting_screen.zoom_region.is_usable = MMI_TRUE;                            
                    }
                    else
                    {
                        mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_usable = MMI_TRUE;
                    }
                    /* cpamode may be disable when ext calling */
                    if(mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_SETTING_CAP_ENABLED)
                        mmi_camco_osd_p->cam_direct_setting_screen.capmode.is_usable = MMI_TRUE;
                    mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_usable = MMI_TRUE;  
                    if (mmi_camco_setting_app_switch_is_enable())
                    {
                        mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_usable = MMI_TRUE;
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_usable = MMI_TRUE;                    
                        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.is_usable = MMI_TRUE;                      
                        mmi_camco_osd_p->cam_direct_setting_screen.capture.is_usable= MMI_TRUE;                           
                    }    
                    else
                    {
                        mmi_camco_osd_p->cam_direct_setting_screen.capture.is_usable= MMI_TRUE;                                               
                    }                     
                }
                else
                {
                    mmi_camco_osd_p->sensor_switcher.is_usable = MMI_FALSE;                  
                    mmi_camco_osd_p->cam_direct_setting_screen.capture.is_usable= MMI_TRUE;                           
                }
                mmi_camco_osd_p->cam_direct_setting_screen.back.is_usable = MMI_TRUE;
                mmi_camco_osd_p->forward_screen.tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON;
                mmi_camco_osd_p->captured_screen.tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON;
            }
            else
            {
                mmi_camco_osd_p->rec_direct_setting_screen.scene_mode.is_usable = MMI_TRUE;
                if (mmi_camco_osd_p->is_show_zoom)
                {                
                    mmi_camco_osd_p->rec_direct_setting_screen.slider_location_region.is_usable = MMI_TRUE;
                    mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_usable = MMI_TRUE;
                    mmi_camco_osd_p->rec_direct_setting_screen.zoom_region.is_usable = MMI_TRUE;                            
                }
                else
                {                
                    mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_usable = MMI_TRUE;
                }
                mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_usable = MMI_TRUE;
                mmi_camco_osd_p->rec_direct_setting_screen.back.is_usable = MMI_TRUE;
                if (mmi_camco_setting_app_switch_is_enable())
                {                
                    mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_usable = MMI_TRUE;
                    mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_usable = MMI_TRUE;            
                    mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top.is_usable = MMI_TRUE;                        
                }
                else
                {
                    mmi_camco_osd_p->rec_direct_setting_screen.record.is_usable = MMI_TRUE;                 
                }
                mmi_camco_osd_p->forward_screen.tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_PLY_ICON;
                mmi_camco_osd_p->captured_screen.tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_PLY_ICON;
            }
            if(!mmi_camco_osd_p->is_start_to_recording || MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {                
                SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);
            }    
            if (!mmi_camco_osd_is_in_smile_dect_scrn() && mmi_camco_setting_app_switch_is_enable() && (!mmi_camco_osd_p->is_start_to_recording || MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state))
            {
                if (mmi_camco_osd_is_horz_UI())
                {
                    SetKeyHandler(mmi_camco_osd_pre_swtich_to_camera, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);                
                    SetKeyHandler(mmi_camco_osd_swtich_to_camera, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_pre_swtich_to_recorder, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_swtich_to_recorder, KEY_LEFT_ARROW, KEY_EVENT_UP);
                }
                else
                {
                    SetKeyHandler(mmi_camco_osd_pre_swtich_to_camera, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);                
                    SetKeyHandler(mmi_camco_osd_swtich_to_camera, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                    SetKeyHandler(mmi_camco_osd_pre_swtich_to_recorder, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_camco_osd_swtich_to_recorder, KEY_LEFT_ARROW, KEY_EVENT_UP);
                }
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            if (MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW == state)
            {
                mmi_camco_osd_p->storage_select_screen.is_camera_storage_selection = MMI_TRUE;
            }
            else if (MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW == state)
            {
                mmi_camco_osd_p->storage_select_screen.is_camera_storage_selection = MMI_FALSE;
            }
            mmi_camco_osd_gen_option_menulist();
            mmi_camco_osd_gen_storage_selection();            

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);    
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);      
            
            mmi_camco_osd_p->storage_select_screen.back.is_usable = MMI_TRUE;
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            if (MMI_CAMCO_OSD_STATE_CAMERA_SETTING == state)
            {
                mmi_camco_osd_gen_camera_status_icon();
            }
            else if (MMI_CAMCO_OSD_STATE_VIDEO_SETTING == state)
            {
                mmi_camco_osd_gen_video_status_icon();
            }

            /* get setting content */
            if (mmi_camco_osd_p->is_direct_setting)
            {
                mmi_camco_setting_struct *setting_info;
                U8 idx, i;

                if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_SCN)
                {
                    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_SCN_ONLY);
                    mmi_camco_setting_get_setting_info(MMI_CAMCO_SETTING_VDOSCENEMODE, &setting_info);

                    mmi_camco_osd_p->rec_scn_setting_lookup_tbl.real_number = 0;
                    for (i = 0; i < MMI_CAMCO_VDOSCENEMODE_END; i++)
                    {
                        if (setting_info->item_cap[i] == MMI_CAMCO_SETTING_CAP_ENABLED)
                        {
                            mmi_camco_osd_p->rec_scn_setting_lookup_tbl.tbl[mmi_camco_osd_p->rec_scn_setting_lookup_tbl.real_number] = i;
                            mmi_camco_osd_p->rec_scn_setting_lookup_tbl.str_tbl[mmi_camco_osd_p->rec_scn_setting_lookup_tbl.real_number] = setting_info->item_str_id[i];
                            mmi_camco_osd_p->rec_direct_setting_screen.scn_setting_item[i].img_id = mmi_camco_osd_direct_setting_img_translate(setting_info->item_str_id[i]);
                            mmi_camco_osd_p->rec_scn_setting_lookup_tbl.real_number++;
                        }
                    }
                    mmi_camco_osd_p->rec_scn_setting_lookup_tbl.setting_name = setting_info->main_str_id;
                    mmi_camco_osd_p->active_tbl = &mmi_camco_osd_p->rec_scn_setting_lookup_tbl;
                    mmi_camco_osd_p->active_setting_item = mmi_camco_osd_p->rec_direct_setting_screen.scn_setting_item;
                }
                else if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_CAPMODE)
                {
                    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_CAPMODE_ONLY);
                    mmi_camco_setting_get_setting_info(MMI_CAMCO_SETTING_CAPMODE, &setting_info);
                    mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.real_number = 0;
                    for (i = 0; i < MMI_CAMCO_CAPMODE_END; i++)
                    {
                        if (setting_info->item_cap[i] == MMI_CAMCO_SETTING_CAP_ENABLED)
                        {
                            mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.tbl[mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.real_number] = i;
                            mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.str_tbl[mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.real_number] = setting_info->item_str_id[i];
                            mmi_camco_osd_p->cam_direct_setting_screen.capmode_setting_item[i].img_id = mmi_camco_osd_direct_setting_img_translate(setting_info->item_str_id[i]);
                            mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.real_number++;
                        }
                    }
                    mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.setting_name = setting_info->main_str_id;
                    mmi_camco_osd_p->active_tbl = &mmi_camco_osd_p->cam_capmode_setting_lookup_tbl;                        
                    mmi_camco_osd_p->active_setting_item = mmi_camco_osd_p->cam_direct_setting_screen.capmode_setting_item;                        
                }
                else if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SCN)
                {
                    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_SCN_ONLY);
                    mmi_camco_setting_get_setting_info(MMI_CAMCO_SETTING_CAMSCENEMODE, &setting_info);
                    mmi_camco_osd_p->cam_scn_setting_lookup_tbl.real_number = 0;
                    for (i = 0; i < MMI_CAMCO_CAMSCENEMODE_END; i++)
                    {
                        if (setting_info->item_cap[i] == MMI_CAMCO_SETTING_CAP_ENABLED)
                        {
                            mmi_camco_osd_p->cam_scn_setting_lookup_tbl.tbl[mmi_camco_osd_p->cam_scn_setting_lookup_tbl.real_number] = i;
                            mmi_camco_osd_p->cam_scn_setting_lookup_tbl.str_tbl[mmi_camco_osd_p->cam_scn_setting_lookup_tbl.real_number] = setting_info->item_str_id[i];
                            mmi_camco_osd_p->cam_direct_setting_screen.scn_setting_item[i].img_id = mmi_camco_osd_direct_setting_img_translate(setting_info->item_str_id[i]);                                
                            mmi_camco_osd_p->cam_scn_setting_lookup_tbl.real_number++;
                        }
                    }
                    mmi_camco_osd_p->cam_scn_setting_lookup_tbl.setting_name = setting_info->main_str_id;
                    mmi_camco_osd_p->active_tbl = &mmi_camco_osd_p->cam_scn_setting_lookup_tbl;                                                
                    mmi_camco_osd_p->active_setting_item = mmi_camco_osd_p->cam_direct_setting_screen.scn_setting_item;                          
                }
                else if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_FLASH)
                {
                    mmi_camco_osd_p->cam_flash_setting_lookup_tbl.real_number = 0;                    
                #ifdef MMI_CAMCO_SUPPORT_FLASH
                    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_FLASH_ONLY);
                    mmi_camco_setting_get_setting_info(MMI_CAMCO_SETTING_FLASH, &setting_info);
                    for (i = 0; i < MMI_CAMCO_FLASH_END; i++)                        
                #else /* MMI_CAMCO_SUPPORT_FLASH */ 
                    mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_TIMER_ONLY);
                    mmi_camco_setting_get_setting_info(MMI_CAMCO_SETTING_SELFTIMER, &setting_info);
                    for (i = 0; i < MMI_CAMCO_SELFTIMER_END; i++)                            
                #endif /* MMI_CAMCO_SUPPORT_FLASH */                             
                    {
                        if (setting_info->item_cap[i] == MMI_CAMCO_SETTING_CAP_ENABLED)
                        {
                            mmi_camco_osd_p->cam_flash_setting_lookup_tbl.tbl[mmi_camco_osd_p->cam_flash_setting_lookup_tbl.real_number] = i;
                            mmi_camco_osd_p->cam_flash_setting_lookup_tbl.str_tbl[mmi_camco_osd_p->cam_flash_setting_lookup_tbl.real_number] = setting_info->item_str_id[i];
                            mmi_camco_osd_p->cam_direct_setting_screen.flash_setting_item[i].img_id = mmi_camco_osd_direct_setting_img_translate(setting_info->item_str_id[i]);
                            mmi_camco_osd_p->cam_flash_setting_lookup_tbl.real_number++;
                        }
                    }
                    mmi_camco_osd_p->cam_flash_setting_lookup_tbl.setting_name = setting_info->main_str_id;
                    mmi_camco_osd_p->active_tbl = &mmi_camco_osd_p->cam_flash_setting_lookup_tbl;     
                    mmi_camco_osd_p->active_setting_item = mmi_camco_osd_p->cam_direct_setting_screen.flash_setting_item;                          
                }

                mmi_camco_setting_set_mainlist_idx(0);

                /* gen ui */
                mmi_camco_osd_gen_iconlist();
                mmi_camco_osd_gen_setting_menulist();
            }
            else
            {
                U32 cur_mainlist_setting = 0;

                mmi_camco_setting_gen_mainlist(mmi_camco_setting_get_mainlist_type());
                mmi_camco_setting_set_mainlist_idx(mmi_camco_osd_p->iconlist.highlighted_idx);

                /* gen ui */
                mmi_camco_osd_gen_iconlist();
                mmi_camco_osd_gen_setting_menulist();

                if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL ||
                    mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE)
                {
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                }
            #if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif    
            }

            /* set touch region */
            if (mmi_camco_osd_p->is_direct_setting)
            {
                if (MMI_CAMCO_OSD_STATE_CAMERA_SETTING == state)
                {
                    if (mmi_camco_osd_p->current_dir_setting_object != MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM)
                    {
                        U8 i;

                        if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SCN)
                        {
                            for (i = 0; i < mmi_camco_osd_p->cam_scn_setting_lookup_tbl.real_number; i++)
                                mmi_camco_osd_p->cam_direct_setting_screen.scn_setting_item[i].is_usable = MMI_TRUE;
                        }
                        else if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_CAPMODE)
                        {
                            for (i = 0; i < mmi_camco_osd_p->cam_capmode_setting_lookup_tbl.real_number; i++)
                                mmi_camco_osd_p->cam_direct_setting_screen.capmode_setting_item[i].is_usable = MMI_TRUE;
                        }
                        else if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_FLASH)
                        {
                        #ifdef MMI_CAMCO_SUPPORT_FLASH
                            for (i = 0; i < mmi_camco_osd_p->cam_flash_setting_lookup_tbl.real_number; i++)
                                mmi_camco_osd_p->cam_direct_setting_screen.flash_setting_item[i].is_usable = MMI_TRUE;
                        #else /* MMI_CAMCO_SUPPORT_FLASH */ 
                            for (i = 0; i < mmi_camco_osd_p->cam_flash_setting_lookup_tbl.real_number; i++)
                                mmi_camco_osd_p->cam_direct_setting_screen.flash_setting_item[i].is_usable = MMI_TRUE;
                        #endif /* MMI_CAMCO_SUPPORT_FLASH */ 
                        }
                        mmi_camco_osd_p->cam_direct_setting_screen.setting_wnd_body.is_usable = MMI_TRUE;

                    }
                    else
                    {
                        mmi_camco_osd_p->cam_direct_setting_screen.slider_location_region.is_usable = MMI_TRUE;
                        mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_usable = MMI_TRUE;
                        mmi_camco_osd_p->cam_direct_setting_screen.zoom_region.is_usable = MMI_TRUE;                            
                    }

                }
                else
                {
                    if (mmi_camco_osd_p->current_dir_setting_object != MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM)
                    {
                        U8 i;

                        if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_SCN)
                        {
                            for (i = 0; i < mmi_camco_osd_p->rec_scn_setting_lookup_tbl.real_number; i++)
                                mmi_camco_osd_p->rec_direct_setting_screen.scn_setting_item[i].is_usable = MMI_TRUE;
                        }
                        mmi_camco_osd_p->rec_direct_setting_screen.setting_wnd_body.is_usable = MMI_TRUE;                    

                    }
                    else
                    {
                        mmi_camco_osd_p->rec_direct_setting_screen.slider_location_region.is_usable = MMI_TRUE;
                        mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_usable = MMI_TRUE;
                        mmi_camco_osd_p->rec_direct_setting_screen.zoom_region.is_usable = MMI_TRUE;                             
                    }

                }
            }
            else
            {
                U8 i;

                mmi_camco_osd_p->advance_setting_screen.main_tab.is_usable = MMI_TRUE;
                mmi_camco_osd_p->advance_setting_screen.misc_tab.is_usable = MMI_TRUE;

                for (i = 0; i < mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count; i++)
                    mmi_camco_osd_p->advance_setting_screen.Level1_setting_wnd_item[i].is_usable = MMI_TRUE;

                for (i = 0; i < mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count; i++)
                    mmi_camco_osd_p->advance_setting_screen.Level2_setting_wnd_item[i].is_usable = MMI_TRUE;

                mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_region.is_usable = MMI_TRUE;
                mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_region.is_usable = MMI_TRUE;
                mmi_camco_osd_p->advance_setting_screen.back.is_usable = MMI_TRUE;
                mmi_camco_osd_p->advance_setting_screen.OK.is_usable = MMI_TRUE;                
                mmi_camco_osd_p->ad_setting_menu_touch[0].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_touch[1].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_touch[2].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_pre_touch[0].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_pre_touch[1].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_pre_touch[2].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_next_touch[0].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_next_touch[1].is_usable = MMI_TRUE;
                mmi_camco_osd_p->ad_setting_menu_next_touch[2].is_usable = MMI_TRUE;
                mmi_camco_osd_p->advance_setting_screen.menu_status = MMI_CAMCO_OSD_MENU_LEVEL1;

            }

            if (mmi_camco_osd_is_horz_UI())
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);

                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            }
            else
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);

                SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }             
            if(!mmi_camco_osd_p->is_direct_setting)
            {
                SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);        
                SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_usable = MMI_TRUE;
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);

            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            /* register key event */
            if (mmi_camco_osd_is_horz_UI())
            {
                mmi_camco_osd_recording_setup_environment();

                if (state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE)
                {
                    gdi_layer_set_blt_layer(
                        mmi_camco_osd_p->base_layer_h,
                        mmi_camco_osd_p->video_recoding_osd.osd_layer_ev_zoom_area_h,
                        mmi_camco_osd_p->video_recoding_osd.osd_layer_rec_time_area_h,
                        mmi_camco_osd_p->video_recoding_osd.osd_layer_softkey_area_h);
                }

            }
            else
            {
                gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            }

            mmi_camco_setting_get_vdozoom_info(
                &mmi_camco_osd_p->rec_slider.max_value,
                &mmi_camco_osd_p->rec_slider.min_value,
                &mmi_camco_osd_p->rec_slider.one_step_value,
                &mmi_camco_osd_p->rec_slider.step_count);
            mmi_camco_osd_p->recording_screen.slider_location_region.is_usable = MMI_TRUE;
            mmi_camco_osd_p->recording_screen.slider_region.is_usable = MMI_TRUE;
        #ifdef __MMI_OP02_LEMEI__             
            if (mmi_camco_setting_app_switch_is_enable())
            {
        #endif    
            mmi_camco_osd_p->recording_screen.start.is_usable = MMI_TRUE;
        #ifdef __MMI_OP02_LEMEI__                     
            }
        #endif
            mmi_camco_osd_p->recording_screen.stop.is_usable = MMI_TRUE;

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
        #ifdef __MMI_OP02_LEMEI__             
            if (mmi_camco_setting_app_switch_is_enable())
            {
        #endif            
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_csk_press_hdlr, KEY_CSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_csk_release_hdlr, KEY_CSK, KEY_EVENT_UP);
        #ifdef __MMI_OP02_LEMEI__                     
            }
        #endif            
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
            mmi_camco_osd_p->add_frame.la_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->add_frame.ra_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->add_frame.ok.is_usable = MMI_TRUE;
            mmi_camco_osd_p->add_frame.back.is_usable = MMI_TRUE;

            if (mmi_camco_osd_is_horz_UI())
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
            else
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            }
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            break;

        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_imageselect_setup_environment();

            gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->imageselect_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);

            mmi_camco_osd_gen_image_select();
            mmi_camco_osd_gen_option_menulist();

            if (mmi_camco_osd_p->captured_img_select_screen.img_list_count > 0)
            {
                U8 idx;

                for (idx = 0; idx < mmi_camco_osd_p->imgselect_cache.disp_cache_count; idx++)
                {
                    mmi_camco_osd_p->captured_img_select_screen.image_list_touch[idx + mmi_camco_osd_p->captured_img_select_screen.img_select_pos_shift].is_usable = MMI_TRUE;
                }
            }
            mmi_camco_osd_p->captured_img_select_screen.back.is_usable = MMI_TRUE;
            if(!mmi_camco_osd_p->imgselect_cache.save_flag_p[mmi_camco_osd_p->imgselect_cache.highlighted_idx])
            {
                mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_TRUE;
            }                        
            
            if (mmi_camco_osd_is_horz_UI())
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
            else
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            }

            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_gen_panorama_selection();
        
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
            SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
#else /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
            SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 
        
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
        
            mmi_camco_osd_p->panorama.ua_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->panorama.da_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->panorama.la_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->panorama.ra_touch.is_usable = MMI_TRUE;
            mmi_camco_osd_p->panorama_screen.OK.is_usable = MMI_TRUE;
            mmi_camco_osd_p->panorama_screen.cancel.is_usable = MMI_TRUE;            
            break;
        }

        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            mmi_camco_osd_panorama_shot_setup_environment();
            mmi_camco_osd_gen_panorama_shot();

            gdi_layer_set_blt_layer(
                mmi_camco_osd_p->base_layer_h,
                mmi_camco_osd_p->panorama_cache_layer_h,
                mmi_camco_osd_p->osd_layer_h,
                0);

            mmi_camco_osd_p->panorama_screen.OK.is_usable = MMI_TRUE;
            mmi_camco_osd_p->panorama_screen.cancel.is_usable = MMI_TRUE;
            mmi_camco_osd_p->panorama_screen.capture.is_usable = MMI_TRUE;
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_camco_osd_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            /* clear focus data */
            memset(mmi_camco_osd_p->focus_region, 0, sizeof(mmi_camco_osd_p->focus_region));

            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            /* set opacity */
            gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            gdi_layer_set_opacity(TRUE, mmi_camco_osd_p->focus_opacity);
            gdi_layer_pop_and_restore_active();

            break;
        }
        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        {
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            break;
        }
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, mmi_camco_osd_p->osd_layer_h, 0, 0);

            mmi_camco_osd_gen_option_menulist();

            mmi_camco_osd_p->forward_screen.confirm_body.is_usable= MMI_TRUE;    

            if (mmi_camco_osd_is_horz_UI())
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
            }
            else
            {
                SetKeyHandler(mmi_camco_osd_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_camco_osd_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_camco_osd_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            }
            break;

    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
            SetKeyHandler(mmi_camco_osd_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camco_osd_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);

            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, 0, 0, 0);
            break;

        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT:
        #ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF                
            mmi_camco_osd_sublcd_stop_hint_set_environment();
        #endif    
            gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
            gdi_layer_set_blt_layer(mmi_camco_osd_p->sublcd_base_layer_h, mmi_camco_osd_p->sublcd_osd_layer_h, 0, 0);

            break;
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
        case MMI_CAMCO_OSD_STATE_EXIT:
        {
            /* exit state */
            gdi_layer_set_blt_layer(mmi_camco_osd_p->base_layer_h, 0, 0, 0);
            break;
        }

        default:
            MMI_ASSERT(0);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_draw_osd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    S32 width = 0;
    S32 height = 0;
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_HIDE:
        {
            mmi_camco_osd_blt();
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR)
                {
                    mmi_camco_osd_draw_confirm();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();                
                    mmi_camco_osd_draw_confirm();
                }                                
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_ONLY)
                {
                    mmi_camco_osd_draw_hint();
                }

                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();

                if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
                {
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR)
                {             
                    mmi_camco_osd_draw_confirm();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();                
                    mmi_camco_osd_draw_confirm();
                }                                
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_ONLY)
                {
                    mmi_camco_osd_draw_hint();
                }

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_hint();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();

                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_hint();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
                {
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR)
                {            
                    mmi_camco_osd_draw_confirm();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();                
                    mmi_camco_osd_draw_confirm();
                }                      
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_ONLY)
                {
                    mmi_camco_osd_draw_hint();
                }

                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
                {
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();
                    mmi_camco_osd_draw_hint();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR)
                {             
                    mmi_camco_osd_draw_confirm();
                }
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_softkey();                
                    mmi_camco_osd_draw_confirm();
                }                
                else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_ONLY)
                {
                    mmi_camco_osd_draw_hint();
                }

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();

                if (mmi_camco_osd_p->facedetect.is_tracking)
                {
                    mmi_camco_osd_draw_facedetect();
                }

            #ifdef __SMILE_SHUTTER_SUPPORT__
                if (mmi_camco_osd_p->smiledetect.is_tracking)
                {
                    mmi_camco_osd_draw_smiledetect();
                }
                if (!mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
                {
                    mmi_camco_osd_draw_smileshot();
                }
            #endif /* __SMILE_SHUTTER_SUPPORT__ */ 

                if (!mmi_camco_osd_is_in_smile_dect_scrn())
                {
                    mmi_camco_osd_draw_status_icon();
                }

                if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_FLASH) == MMI_CAMCO_SETTING_CAP_ENABLED
                    && mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FLASH) != MMI_CAMCO_FLASH_OFF &&
                    mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_XENON)
                {
                    mmi_camco_osd_draw_xenon_flash();
                }

                if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_CAPMODE) == MMI_CAMCO_CAPMODE_PANORAMA)
                {
                    mmi_camco_osd_draw_panorama();
                }

                mmi_camco_osd_draw_softkey();

                if (!mmi_camco_osd_is_in_smile_dect_scrn())
                {
                    mmi_camco_osd_draw_toolbar();
                }

                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();

                if (mmi_camco_osd_p->facedetect.is_tracking)
                {
                    mmi_camco_osd_draw_facedetect();
                }

            #ifdef __SMILE_SHUTTER_SUPPORT__
                if (mmi_camco_osd_p->smiledetect.is_tracking)
                {
                    mmi_camco_osd_draw_smiledetect();
                }
                if (!mmi_camco_osd_p->smiledetect.is_zoom_ev_enable)
                {
                    mmi_camco_osd_draw_smileshot();
                }
            #endif /* __SMILE_SHUTTER_SUPPORT__ */ 

                if (!mmi_camco_osd_is_in_smile_dect_scrn())
                {
                    mmi_camco_osd_draw_status_icon();
                }

                if (mmi_camco_setting_get_setting_capability(MMI_CAMCO_SETTING_FLASH) == MMI_CAMCO_SETTING_CAP_ENABLED
                    && mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FLASH) != MMI_CAMCO_FLASH_OFF &&
                    mmi_camco_get_flash_type() == MMI_CAMCO_FLASH_TYPE_XENON)
                {
                    mmi_camco_osd_draw_xenon_flash();
                }

                mmi_camco_osd_draw_softkey();
                if (!mmi_camco_osd_is_in_smile_dect_scrn())
                {
                    mmi_camco_osd_draw_toolbar();
                }

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_status_icon();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_toolbar();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_status_icon();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_toolbar();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }
        
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_storage_selection();                
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_storage_selection();   
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;            
        }

        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                mmi_camco_osd_vdo_recording_osd_struct *video_recoding_osd_p = &mmi_camco_osd_p->video_recoding_osd;

                /* Zoom */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                width = video_recoding_osd_p->rotate_ev_zoom_area.x2 - video_recoding_osd_p->rotate_ev_zoom_area.x1 + 1;
                height =
                    video_recoding_osd_p->rotate_ev_zoom_area.y2 - video_recoding_osd_p->rotate_ev_zoom_area.y1 + 1;

                gdi_layer_resize(width, height);
                mmi_camco_osd_clear_bg();
                mmi_camco_draw_reduce_video_slider();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_ev_zoom_area_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    video_recoding_osd_p->osd_layer_ev_zoom_area_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                /* Softkey */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                width = video_recoding_osd_p->rotate_softkey_area.x2 - video_recoding_osd_p->rotate_softkey_area.x1 + 1;
                height =
                    video_recoding_osd_p->rotate_softkey_area.y2 - video_recoding_osd_p->rotate_softkey_area.y1 + 1;

                gdi_layer_resize(width, height);
                /* mmi_camco_osd_draw_reduced_recoding_softkey(); */
                mmi_camco_osd_draw_reduce_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_softkey_area_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    video_recoding_osd_p->osd_layer_softkey_area_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                /* Record time */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                width =
                    video_recoding_osd_p->rotate_rec_time_area.x2 - video_recoding_osd_p->rotate_rec_time_area.x1 + 1;
                height =
                    video_recoding_osd_p->rotate_rec_time_area.y2 - video_recoding_osd_p->rotate_rec_time_area.y1 + 1;

                gdi_layer_resize(width, height);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_reduced_record_time(mmi_camco_get_record_time());

            #ifdef __MMI_OP02_LEMEI__    
                if (mmi_camco_setting_app_switch_is_enable())
                {
                    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                    {
                        mmi_camco_osd_draw_reduced_progress(mmi_camco_get_record_progress_ratio());
                    }            
                }
            #else
                if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                {
                    mmi_camco_osd_draw_reduced_progress(mmi_camco_get_record_progress_ratio());
                }
            #endif
            
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_rec_time_area_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    video_recoding_osd_p->osd_layer_rec_time_area_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                if (mmi_camco_osd_p->is_blt)
                {
                    mmi_camco_osd_blt();
                }
            }
            else
            {
                /* Subcamera - Portait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_draw_video_slider();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_record_time(mmi_camco_get_record_time());

            #ifdef __MMI_OP02_LEMEI__    
                if (mmi_camco_setting_app_switch_is_enable())
                {
                    if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                    {
                        mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
                    }            
                }
            #else
                if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_LIMIT) > MMI_CAMCO_LIMIT_NO_LIMIT)
                {
                    mmi_camco_osd_draw_progress(mmi_camco_get_record_progress_ratio());
                }
            #endif

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->is_direct_setting == KAL_TRUE)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_direct_setting(mmi_camco_osd_p->touch_obj);
                }
                else
                {
                    mmi_camco_osd_draw_advance_setting();
                }
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
                #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->is_direct_setting == KAL_TRUE)
                {
                    mmi_camco_osd_draw_toolbar();
                    mmi_camco_osd_draw_direct_setting(mmi_camco_osd_p->touch_obj);
                }
                else
                {
                    mmi_camco_osd_draw_advance_setting();
                }
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_add_frame_color_idx();
                mmi_camco_osd_draw_add_frame_file_index();
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_add_frame_color_idx();
                mmi_camco_osd_draw_add_frame_file_index();
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SAVING:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->add_frame.is_picked)
                {
                    mmi_camco_osd_draw_add_frame_color_idx();
                }
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                if (mmi_camco_osd_p->add_frame.is_picked)
                {
                    mmi_camco_osd_draw_add_frame_color_idx();
                }
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                S32 width, height;

                /*===============================================================*/
                /* draw osd */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_toolbar();
                mmi_camco_osd_draw_softkey();
                mmi_camco_osd_draw_image_select_osd();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);

                gdi_layer_toggle_double();
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                /* draw cache layer */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                gdi_layer_get_dimension(&width, &height);
                gdi_layer_resize(
                    mmi_camco_osd_p->imgselect_cache.cache_layer_height,
                    mmi_camco_osd_p->imgselect_cache.cache_layer_width);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_image_select_cache(mmi_camco_osd_p->osd_layer_draw_buf_p);
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->imageselect_cache_layer_h);
                gdi_layer_lock_frame_buffer();
                mmi_camco_osd_rotate_for_hw_rotate(
                    mmi_camco_osd_p->osd_layer_draw_h,
                    mmi_camco_osd_p->imageselect_cache_layer_h);
                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                gdi_layer_resize(width, height);
                gdi_layer_pop_and_restore_active();

                /* draw base layer */
                mmi_camco_osd_draw_image_select_hilite();

                mmi_camco_osd_blt();
            }
            else
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
                gdi_layer_toggle_double();
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();

                mmi_camco_osd_draw_toolbar();
                mmi_camco_osd_draw_image_select();
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 

    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            if(mmi_camco_osd_is_horz_UI())
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_panorama_selection();
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();
            
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ 
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();
            
                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);
            
                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();
            
                mmi_camco_osd_blt();
            }
            else
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__ 
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();
            
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_panorama_selection();
                mmi_camco_osd_draw_softkey();
            
                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();
            
                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            if(mmi_camco_osd_is_horz_UI())
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_panorama_shot();
                mmi_camco_osd_draw_softkey();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_panorama_shot();
                mmi_camco_osd_draw_softkey();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 

        case MMI_CAMCO_OSD_STATE_FOCUSE:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_FOCUSE_HINT:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus_hint();
                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            else
            {
                /* Subcamera - Portrait */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_clear_bg();
                mmi_camco_osd_draw_focus_hint();

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();

                mmi_camco_osd_blt();
            }
            break;
        }

        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            if (mmi_camco_osd_is_horz_UI())
            {
                /* Horizontal */
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
            
                mmi_camco_osd_clear_bg();
                
                mmi_camco_osd_draw_toolbar();
                mmi_camco_osd_draw_option();
                mmi_camco_osd_draw_softkey();

                gdi_layer_pop_and_restore_active();

                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();

                mmi_camco_osd_rotate_for_hw_rotate(mmi_camco_osd_p->osd_layer_draw_h, mmi_camco_osd_p->osd_layer_h);

                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();
                
                mmi_camco_osd_blt();                
            }
            else
            {
                gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
            #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
                gdi_layer_toggle_double();
            #endif
                gdi_layer_lock_frame_buffer();
                
                mmi_camco_osd_clear_bg();
                
                mmi_camco_osd_draw_toolbar();
                mmi_camco_osd_draw_option();
                mmi_camco_osd_draw_softkey();
                
                gdi_layer_unlock_frame_buffer();
                gdi_layer_pop_and_restore_active();
                
                mmi_camco_osd_blt();

            }
            break;
        }

    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_PREVIEW:
            break;

        case MMI_CAMCO_OSD_STATE_SUBLCD_CAMERA_STOP_HINT:
        {
            gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
            mmi_camco_osd_clear_bg();
            mmi_camco_sublcd_osd_draw_hint();
            gdi_layer_pop_and_restore_active();

            mmi_camco_osd_sublcd_blt();
            break;
        }
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

        default:
            MMI_ASSERT(0);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer_h     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_base_layer(gdi_handle layer_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->base_layer_h = layer_h;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_cam_direct_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_cam_direct_setting(void)
{
 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_cam_direct_setting_struct *setting_p = &mmi_camco_osd_p->cam_direct_setting_screen;
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_p->sensor_switcher.offset_x = mmi_camco_osd_skin_p->sensor_switcher.offset_x;
    mmi_camco_osd_p->sensor_switcher.offset_y = mmi_camco_osd_skin_p->sensor_switcher.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_SENSOR_SWITCHER_ICON, &mmi_camco_osd_p->sensor_switcher.width, &mmi_camco_osd_p->sensor_switcher.height);
    mmi_camco_osd_p->sensor_switcher.img_id = IMG_ID_CAMCO_SENSOR_SWITCHER_ICON;

    setting_p->zoom.offset_x = setting_skin_p->zoom.offset_x;
    setting_p->zoom.offset_y = setting_skin_p->zoom.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_ZOOM_ICON, &setting_p->zoom.width, &setting_p->zoom.height);
    setting_p->zoom.img_id = IMG_ID_CAMCO_PREVIEW_ZOOM_ICON;

    setting_p->flash.offset_x = setting_skin_p->flash.offset_x;
    setting_p->flash.offset_y = setting_skin_p->flash.offset_y;
#ifdef MMI_CAMCO_SUPPORT_FLASH
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_FLASH_ICON, &setting_p->flash.width, &setting_p->flash.height);
    setting_p->flash.img_id = IMG_ID_CAMCO_PREVIEW_FLASH_ICON;
#else /* MMI_CAMCO_SUPPORT_FLASH */ 
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_TIMER_ICON, &setting_p->flash.width, &setting_p->flash.height);
    setting_p->flash.img_id = IMG_ID_CAMCO_PREVIEW_TIMER_ICON;
#endif /* MMI_CAMCO_SUPPORT_FLASH */ 

    setting_p->scene_mode.offset_x = setting_skin_p->scenemode.offset_x;
    setting_p->scene_mode.offset_y = setting_skin_p->scenemode.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_PREVIEW_SCN_ICON,
        &setting_p->scene_mode.width,
        &setting_p->scene_mode.height);
    setting_p->scene_mode.img_id = IMG_ID_CAMCO_PREVIEW_SCN_ICON;

    setting_p->capmode.offset_x = setting_skin_p->capturemode.offset_x;
    setting_p->capmode.offset_y = setting_skin_p->capturemode.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_CAPMODE_ICON, &setting_p->capmode.width, &setting_p->capmode.height);
    setting_p->capmode.img_id = IMG_ID_CAMCO_PREVIEW_CAPMODE_ICON;

    setting_p->imgviewer.offset_x = setting_skin_p->imgviewer.offset_x;
    setting_p->imgviewer.offset_y = setting_skin_p->imgviewer.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_PREVIEW_VIEW_ICON,
        &setting_p->imgviewer.width,
        &setting_p->imgviewer.height);
    setting_p->imgviewer.img_id = IMG_ID_CAMCO_PREVIEW_VIEW_ICON;

    setting_p->back.offset_x = setting_skin_p->back.offset_x;
    setting_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &setting_p->back.width, &setting_p->back.height);
    setting_p->back.img_id = IMG_ID_CAMCO_BACK_ICON;

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->capture.offset_x = setting_skin_p->back.offset_x;
        gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_CAM_CAP_ICON, &setting_p->capture.width, &setting_p->capture.height);    
        setting_p->capture.offset_y = (mmi_camco_osd_p->osd_height - setting_p->capture.height)>>1;
        setting_p->capture.img_id = IMG_ID_CAMCO_PREVIEW_CAM_CAP_ICON;
    }
    else
    {
        setting_p->capture.offset_y = setting_skin_p->back.offset_y - 20;
        gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_CAM_CAP_ICON, &setting_p->capture.width, &setting_p->capture.height);    
        setting_p->capture.offset_x = (mmi_camco_osd_p->osd_width- setting_p->capture.width)>>1;
        setting_p->capture.img_id = IMG_ID_CAMCO_PREVIEW_CAM_CAP_ICON;
    }
    
    setting_p->ad_setting.offset_x = setting_skin_p->advance_setting.offset_x;
    setting_p->ad_setting.offset_y = setting_skin_p->advance_setting.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_PREVIEW_SETTING_ICON,
        &setting_p->ad_setting.width,
        &setting_p->ad_setting.height);
    setting_p->ad_setting.img_id = IMG_ID_CAMCO_PREVIEW_SETTING_ICON;

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->switch_mode_top.offset_x = setting_skin_p->switch_mode_top.offset_x;
        setting_p->switch_mode_top.offset_y = setting_skin_p->switch_mode_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_ICON,
            &setting_p->switch_mode_top.width,
            &setting_p->switch_mode_top.height);
        setting_p->switch_mode_top.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_ICON;

        setting_p->switch_mode_botton.offset_x = setting_skin_p->switch_mode_botton.offset_x;
        setting_p->switch_mode_botton.offset_y = setting_skin_p->switch_mode_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_ICON,
            &setting_p->switch_mode_botton.width,
            &setting_p->switch_mode_botton.height);
        setting_p->switch_mode_botton.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_ICON;
    }
    else
    {
        setting_p->switch_mode_top.offset_x = setting_skin_p->switch_mode_top.offset_x;
        setting_p->switch_mode_top.offset_y = setting_skin_p->switch_mode_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_V_ICON,
            &setting_p->switch_mode_top.width,
            &setting_p->switch_mode_top.height);
        setting_p->switch_mode_top.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_V_ICON;

        setting_p->switch_mode_botton.offset_x = setting_skin_p->switch_mode_botton.offset_x;
        setting_p->switch_mode_botton.offset_y = setting_skin_p->switch_mode_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_V_ICON,
            &setting_p->switch_mode_botton.width,
            &setting_p->switch_mode_botton.height);
        setting_p->switch_mode_botton.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_V_ICON;
    }
    
    setting_p->setting_title.offset_x = setting_skin_p->direct_setting_menu_title.offset_x;
    setting_p->setting_title.offset_y = setting_skin_p->direct_setting_menu_title.offset_y;

    setting_p->setting_sub_title.offset_x = setting_skin_p->direct_setting_menu_sub_title2.offset_x;
    setting_p->setting_sub_title.offset_y = setting_skin_p->direct_setting_menu_sub_title2.offset_y;

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->setting_wnd_body.offset_x = setting_skin_p->direct_setting_menu_body.offset_x;
        setting_p->setting_wnd_body.offset_y = setting_skin_p->direct_setting_menu_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_ICON,
            &setting_p->setting_wnd_body.width,
            &setting_p->setting_wnd_body.height);
        setting_p->setting_wnd_body.img_id = IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_ICON;
    }
    else
    {
        setting_p->setting_wnd_body.offset_x = setting_skin_p->direct_setting_menu_body.offset_x;
        setting_p->setting_wnd_body.offset_y = setting_skin_p->direct_setting_menu_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_V_ICON,
            &setting_p->setting_wnd_body.width,
            &setting_p->setting_wnd_body.height);
        setting_p->setting_wnd_body.img_id = IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_V_ICON;
    }
    
    for(i=0; i < MMI_CAMCO_OSD_MAX_DIRECT_SETTING_COUNT; i++)
    {
        setting_p->scn_setting_item[i].offset_x =  setting_skin_p->direct_setting_menu_item[i].offset_x;
        setting_p->scn_setting_item[i].offset_y =  setting_skin_p->direct_setting_menu_item[i].offset_y;        
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON,
            &setting_p->scn_setting_item[i].width,
            &setting_p->scn_setting_item[i].height);
        setting_p->scn_setting_item[i].img_id = IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON;

        setting_p->flash_setting_item[i].offset_x =  setting_skin_p->direct_setting_menu_item[i].offset_x;
        setting_p->flash_setting_item[i].offset_y =  setting_skin_p->direct_setting_menu_item[i].offset_y;        
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON,
            &setting_p->flash_setting_item[i].width,
            &setting_p->flash_setting_item[i].height);
        setting_p->flash_setting_item[i].img_id = IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON;

        setting_p->capmode_setting_item[i].offset_x =  setting_skin_p->direct_setting_menu_item[i].offset_x;
        setting_p->capmode_setting_item[i].offset_y =  setting_skin_p->direct_setting_menu_item[i].offset_y;        
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON,
            &setting_p->capmode_setting_item[i].width,
            &setting_p->capmode_setting_item[i].height);
        setting_p->capmode_setting_item[i].img_id = IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON;
        
    }            

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->slider_zoom_top.offset_x = setting_skin_p->direct_setting_slider_top.offset_x;
        setting_p->slider_zoom_top.offset_y = setting_skin_p->direct_setting_slider_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON,
            &setting_p->slider_zoom_top.width,
            &setting_p->slider_zoom_top.height);
        setting_p->slider_zoom_top.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON;

        setting_p->slider_bar.offset_x = setting_skin_p->direct_setting_slider_bar.offset_x;
        setting_p->slider_bar.offset_y = setting_skin_p->direct_setting_slider_bar.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON,
            &setting_p->slider_bar.width,
            &setting_p->slider_bar.height);
        setting_p->slider_bar.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON;

        setting_p->slider_zoom_botton.offset_x = setting_skin_p->direct_setting_slider_botton.offset_x;
        setting_p->slider_zoom_botton.offset_y = setting_skin_p->direct_setting_slider_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON,
            &setting_p->slider_zoom_botton.width,
            &setting_p->slider_zoom_botton.height);
        setting_p->slider_zoom_botton.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON;
    }
    else
    {
        setting_p->slider_zoom_top.offset_x = setting_skin_p->direct_setting_slider_top.offset_x;
        setting_p->slider_zoom_top.offset_y = setting_skin_p->direct_setting_slider_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON,
            &setting_p->slider_zoom_top.width,
            &setting_p->slider_zoom_top.height);
        setting_p->slider_zoom_top.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON;

        setting_p->slider_bar.offset_x = setting_skin_p->direct_setting_slider_bar.offset_x;
        setting_p->slider_bar.offset_y = setting_skin_p->direct_setting_slider_bar.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON,
            &setting_p->slider_bar.width,
            &setting_p->slider_bar.height);
        setting_p->slider_bar.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON;

        setting_p->slider_zoom_botton.offset_x = setting_skin_p->direct_setting_slider_botton.offset_x;
        setting_p->slider_zoom_botton.offset_y = setting_skin_p->direct_setting_slider_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON,
            &setting_p->slider_zoom_botton.width,
            &setting_p->slider_zoom_botton.height);
        setting_p->slider_zoom_botton.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON;    
    }
    
    setting_p->slider_location.offset_x = setting_skin_p->direct_setting_slider_location.offset_x;
    setting_p->slider_location.offset_y = setting_skin_p->direct_setting_slider_location.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON,
        &setting_p->slider_location.width,
        &setting_p->slider_location.height);
    setting_p->slider_location.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON;
 
    setting_p->zoom_region.offset_x = setting_p->slider_zoom_top.offset_x;
    setting_p->zoom_region.offset_y = setting_p->slider_zoom_top.offset_y;
    setting_p->zoom_region.width = setting_p->slider_zoom_botton.offset_x + setting_p->slider_zoom_botton.width - setting_p->slider_zoom_top.offset_x;
    setting_p->zoom_region.height = setting_p->slider_zoom_botton.offset_y + setting_p->slider_zoom_botton.height - setting_p->slider_zoom_top.offset_y;

    setting_p->slider_location_region.offset_x = setting_p->slider_location.offset_x - 10;
    setting_p->slider_location_region.offset_y = setting_p->slider_location.offset_y - 5;
    setting_p->slider_location_region.width = setting_p->slider_location.width + 20;
    setting_p->slider_location_region.height = setting_p->slider_location.height + 10;

    setting_p->slider_region.offset_x = setting_p->slider_bar.offset_x + (setting_p->slider_location.width>> 1);;
    setting_p->slider_region.offset_y = setting_p->slider_bar.offset_y + (setting_p->slider_location.height >> 1); /* + (setting_p->slider_location.height >>1); */
    setting_p->slider_region.width = setting_p->slider_bar.width - setting_p->slider_location.width;
    setting_p->slider_region.height = setting_p->slider_bar.height - setting_p->slider_location.height;

    mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_rec_direct_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_rec_direct_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_rec_direct_setting_struct *setting_p = &mmi_camco_osd_p->rec_direct_setting_screen;
    mmi_camco_video_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->video_direct_setting);
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_p->zoom.offset_x = setting_skin_p->zoom.offset_x;
    setting_p->zoom.offset_y = setting_skin_p->zoom.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_ZOOM_ICON, &setting_p->zoom.width, &setting_p->zoom.height);
    setting_p->zoom.img_id = IMG_ID_CAMCO_PREVIEW_ZOOM_ICON;
    
    setting_p->scene_mode.offset_x = setting_skin_p->scenemode.offset_x;
    setting_p->scene_mode.offset_y = setting_skin_p->scenemode.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_PREVIEW_SCN_ICON,
        &setting_p->scene_mode.width,
        &setting_p->scene_mode.height);
    setting_p->scene_mode.img_id = IMG_ID_CAMCO_PREVIEW_SCN_ICON;

    setting_p->allvideos.offset_x = setting_skin_p->allvideos.offset_x;
    setting_p->allvideos.offset_y = setting_skin_p->allvideos.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_ALLVIDEO_ICON, &setting_p->allvideos.width, &setting_p->allvideos.height);
    setting_p->allvideos.img_id = IMG_ID_CAMCO_PREVIEW_ALLVIDEO_ICON;
    
    setting_p->back.offset_x = setting_skin_p->back.offset_x;
    setting_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &setting_p->back.width, &setting_p->back.height);
    setting_p->back.img_id = IMG_ID_CAMCO_BACK_ICON;

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->record.offset_x = setting_skin_p->back.offset_x;
        gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_VID_REC_ICON, &setting_p->record.width, &setting_p->record.height);    
        setting_p->record.offset_y = (mmi_camco_osd_p->osd_height - setting_p->record.height)>>1;
        setting_p->record.img_id = IMG_ID_CAMCO_PREVIEW_VID_REC_ICON;
    }
    else
    {
        setting_p->record.offset_y = setting_skin_p->back.offset_y - 20;
        gdi_image_get_dimension_id(IMG_ID_CAMCO_PREVIEW_VID_REC_ICON, &setting_p->record.width, &setting_p->record.height);    
        setting_p->record.offset_x = (mmi_camco_osd_p->osd_width- setting_p->record.width)>>1;
        setting_p->record.img_id = IMG_ID_CAMCO_PREVIEW_VID_REC_ICON;
    }

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->switch_mode_top.offset_x = setting_skin_p->switch_mode_top.offset_x;
        setting_p->switch_mode_top.offset_y = setting_skin_p->switch_mode_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_ICON,
            &setting_p->switch_mode_top.width,
            &setting_p->switch_mode_top.height);
        setting_p->switch_mode_top.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_ICON;

        setting_p->switch_mode_botton.offset_x = setting_skin_p->switch_mode_botton.offset_x;
        setting_p->switch_mode_botton.offset_y = setting_skin_p->switch_mode_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_ICON,
            &setting_p->switch_mode_botton.width,
            &setting_p->switch_mode_botton.height);
        setting_p->switch_mode_botton.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_ICON;
    }
    else
    {
        setting_p->switch_mode_top.offset_x = setting_skin_p->switch_mode_top.offset_x;
        setting_p->switch_mode_top.offset_y = setting_skin_p->switch_mode_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_V_ICON,
            &setting_p->switch_mode_top.width,
            &setting_p->switch_mode_top.height);
        setting_p->switch_mode_top.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_CAM_UP_V_ICON;

        setting_p->switch_mode_botton.offset_x = setting_skin_p->switch_mode_botton.offset_x;
        setting_p->switch_mode_botton.offset_y = setting_skin_p->switch_mode_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_V_ICON,
            &setting_p->switch_mode_botton.width,
            &setting_p->switch_mode_botton.height);
        setting_p->switch_mode_botton.img_id = IMG_ID_CAMCO_PREVIEW_SWITCH_REC_UP_V_ICON;
    }
    
    setting_p->ad_setting.offset_x = setting_skin_p->advance_setting.offset_x;
    setting_p->ad_setting.offset_y = setting_skin_p->advance_setting.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_PREVIEW_SETTING_ICON,
        &setting_p->ad_setting.width,
        &setting_p->ad_setting.height);
    setting_p->ad_setting.img_id = IMG_ID_CAMCO_PREVIEW_SETTING_ICON;

    setting_p->setting_title.offset_x = setting_skin_p->direct_setting_menu_title.offset_x;
    setting_p->setting_title.offset_y = setting_skin_p->direct_setting_menu_title.offset_y;

    setting_p->setting_sub_title.offset_x = setting_skin_p->direct_setting_menu_sub_title2.offset_x;
    setting_p->setting_sub_title.offset_y = setting_skin_p->direct_setting_menu_sub_title2.offset_y;

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->setting_wnd_body.offset_x = setting_skin_p->direct_setting_menu_body.offset_x;
        setting_p->setting_wnd_body.offset_y = setting_skin_p->direct_setting_menu_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_ICON,
            &setting_p->setting_wnd_body.width,
            &setting_p->setting_wnd_body.height);
        setting_p->setting_wnd_body.img_id = IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_ICON;
    }
    else
    {
        setting_p->setting_wnd_body.offset_x = setting_skin_p->direct_setting_menu_body.offset_x;
        setting_p->setting_wnd_body.offset_y = setting_skin_p->direct_setting_menu_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_V_ICON,
            &setting_p->setting_wnd_body.width,
            &setting_p->setting_wnd_body.height);
        setting_p->setting_wnd_body.img_id = IMG_ID_CAMCO_DIR_SETTING_WND_DOUBLE_V_ICON;
    }
    
    for(i=0; i < MMI_CAMCO_OSD_MAX_DIRECT_SETTING_COUNT; i++)
    {
        setting_p->scn_setting_item[i].offset_x =  setting_skin_p->direct_setting_menu_item[i].offset_x;
        setting_p->scn_setting_item[i].offset_y =  setting_skin_p->direct_setting_menu_item[i].offset_y;        
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON,
            &setting_p->scn_setting_item[i].width,
            &setting_p->scn_setting_item[i].height);
        setting_p->scn_setting_item[i].img_id = IMG_ID_CAMCO_DIR_SETTING_SCN_NONE_ICON;

    }    

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->slider_zoom_top.offset_x = setting_skin_p->direct_setting_slider_top.offset_x;
        setting_p->slider_zoom_top.offset_y = setting_skin_p->direct_setting_slider_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON,
            &setting_p->slider_zoom_top.width,
            &setting_p->slider_zoom_top.height);
        setting_p->slider_zoom_top.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON;

        setting_p->slider_bar.offset_x = setting_skin_p->direct_setting_slider_bar.offset_x;
        setting_p->slider_bar.offset_y = setting_skin_p->direct_setting_slider_bar.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON,
            &setting_p->slider_bar.width,
            &setting_p->slider_bar.height);
        setting_p->slider_bar.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON;

        setting_p->slider_zoom_botton.offset_x = setting_skin_p->direct_setting_slider_botton.offset_x;
        setting_p->slider_zoom_botton.offset_y = setting_skin_p->direct_setting_slider_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON,
            &setting_p->slider_zoom_botton.width,
            &setting_p->slider_zoom_botton.height);
        setting_p->slider_zoom_botton.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON;
    }
    else
    {
        setting_p->slider_zoom_top.offset_x = setting_skin_p->direct_setting_slider_top.offset_x;
        setting_p->slider_zoom_top.offset_y = setting_skin_p->direct_setting_slider_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON,
            &setting_p->slider_zoom_top.width,
            &setting_p->slider_zoom_top.height);
        setting_p->slider_zoom_top.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON;
        
        setting_p->slider_bar.offset_x = setting_skin_p->direct_setting_slider_bar.offset_x;
        setting_p->slider_bar.offset_y = setting_skin_p->direct_setting_slider_bar.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON,
            &setting_p->slider_bar.width,
            &setting_p->slider_bar.height);
        setting_p->slider_bar.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON;
        
        setting_p->slider_zoom_botton.offset_x = setting_skin_p->direct_setting_slider_botton.offset_x;
        setting_p->slider_zoom_botton.offset_y = setting_skin_p->direct_setting_slider_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON,
            &setting_p->slider_zoom_botton.width,
            &setting_p->slider_zoom_botton.height);
        setting_p->slider_zoom_botton.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON;
    
    }
    setting_p->zoom_region.offset_x = setting_p->slider_zoom_top.offset_x;
    setting_p->zoom_region.offset_y = setting_p->slider_zoom_top.offset_y;
    setting_p->zoom_region.width = setting_p->slider_zoom_botton.offset_x + setting_p->slider_zoom_botton.width - setting_p->slider_zoom_top.offset_x;
    setting_p->zoom_region.height = setting_p->slider_zoom_botton.offset_y + setting_p->slider_zoom_botton.height - setting_p->slider_zoom_top.offset_y;

    setting_p->slider_location.offset_x = setting_skin_p->direct_setting_slider_location.offset_x;
    setting_p->slider_location.offset_y = setting_skin_p->direct_setting_slider_location.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON,
        &setting_p->slider_location.width,
        &setting_p->slider_location.height);
    setting_p->slider_location.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON;

    setting_p->slider_location_region.offset_x = setting_p->slider_location.offset_x - 10;
    setting_p->slider_location_region.offset_y = setting_p->slider_location.offset_y - 5;
    setting_p->slider_location_region.width = setting_p->slider_location.width + 20;
    setting_p->slider_location_region.height = setting_p->slider_location.height + 10;

    setting_p->slider_region.offset_x = setting_p->slider_bar.offset_x  + (setting_p->slider_location.width>> 1);
    setting_p->slider_region.offset_y = setting_p->slider_bar.offset_y + (setting_p->slider_location.height >> 1); /* + (setting_p->slider_location.height >>1); */
    setting_p->slider_region.width = setting_p->slider_bar.width - setting_p->slider_location.width;
    setting_p->slider_region.height = setting_p->slider_bar.height - setting_p->slider_location.height;

    mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_advance_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_advance_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_advance_setting_struct *setting_p = &mmi_camco_osd_p->advance_setting_screen;
    mmi_camco_advance_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->advance_setting);
    CHAR  i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting_p->main_tab.offset_x = setting_skin_p->main_setting_tab.offset_x;
    setting_p->main_tab.offset_y = setting_skin_p->main_setting_tab.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_L1_MENU_MAIN_TAB_ICON,
        &setting_p->main_tab.width,
        &setting_p->main_tab.height);
    setting_p->main_tab.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_MAIN_TAB_ICON;

    setting_p->misc_tab.offset_x = setting_skin_p->misc_setting_tab.offset_x;
    setting_p->misc_tab.offset_y = setting_skin_p->misc_setting_tab.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_L1_MENU_MISC_TAB_ICON,
        &setting_p->misc_tab.width,
        &setting_p->misc_tab.height);
    setting_p->misc_tab.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_MISC_TAB_ICON;

    setting_p->main_tab_title.offset_x = setting_skin_p->main_tab_titie.offset_x;
    setting_p->main_tab_title.offset_y = setting_skin_p->main_tab_titie.offset_y;

    setting_p->misc_tab_title.offset_x = setting_skin_p->misc_tab_titie.offset_x;
    setting_p->misc_tab_title.offset_y = setting_skin_p->misc_tab_titie.offset_y;

    setting_p->Level_setting_valuse_offset_x = setting_skin_p->Level_setting_valuse_offset_x;

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->Level1_setting_wnd_top1.offset_x = setting_skin_p->Level1_setting_wnd_top1.offset_x;
        setting_p->Level1_setting_wnd_top1.offset_y = setting_skin_p->Level1_setting_wnd_top1.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP1_ICON,
            &setting_p->Level1_setting_wnd_top1.width,
            &setting_p->Level1_setting_wnd_top1.height);
        setting_p->Level1_setting_wnd_top1.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP1_ICON;

        setting_p->Level1_setting_wnd_top2.offset_x = setting_skin_p->Level1_setting_wnd_top2.offset_x;
        setting_p->Level1_setting_wnd_top2.offset_y = setting_skin_p->Level1_setting_wnd_top2.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP2_ICON,
            &setting_p->Level1_setting_wnd_top2.width,
            &setting_p->Level1_setting_wnd_top2.height);
        setting_p->Level1_setting_wnd_top2.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP2_ICON;

        setting_p->Level1_setting_wnd_botton.offset_x = setting_skin_p->Level1_setting_wnd_botton.offset_x;
        setting_p->Level1_setting_wnd_botton.offset_y = setting_skin_p->Level1_setting_wnd_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_BOTTOM_ICON,
            &setting_p->Level1_setting_wnd_botton.width,
            &setting_p->Level1_setting_wnd_botton.height);
        setting_p->Level1_setting_wnd_botton.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_BOTTOM_ICON;

        setting_p->Level1_setting_wnd_item[0].offset_x = setting_skin_p->Level1_setting_wnd_item.offset_x;
        setting_p->Level1_setting_wnd_item[0].offset_y = setting_skin_p->Level1_setting_wnd_item.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_ICON,
            &setting_p->Level1_setting_wnd_item[0].width,
            &setting_p->Level1_setting_wnd_item[0].height);
        setting_p->Level1_setting_wnd_item[0].img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_ICON;

        setting_p->Level1_setting_item_count = setting_skin_p->Level1_setting_item_count;

        for (i = 1; i < setting_skin_p->Level1_setting_item_count; i++)
        {
            setting_p->Level1_setting_wnd_item[i].offset_x = setting_skin_p->Level1_setting_wnd_item.offset_x;
            setting_p->Level1_setting_wnd_item[i].offset_y =
                setting_p->Level1_setting_wnd_item[i - 1].offset_y + setting_p->Level1_setting_wnd_item[i - 1].height;
            gdi_image_get_dimension_id(
                IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_ICON,
                &setting_p->Level1_setting_wnd_item[i].width,
                &setting_p->Level1_setting_wnd_item[i].height);
            setting_p->Level1_setting_wnd_item[i].img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_ICON;
        }

        for (i = 0; i < setting_skin_p->Level1_setting_item_count; i++)
        {
            setting_p->Level1_setting_wnd_item_no_scroll[i].offset_x = setting_p->Level1_setting_wnd_item[i].offset_x;
            setting_p->Level1_setting_wnd_item_no_scroll[i].offset_y = setting_p->Level1_setting_wnd_item[i].offset_y;
            setting_p->Level1_setting_wnd_item_no_scroll[i].width = setting_p->Level1_setting_wnd_item[i].width;
            setting_p->Level1_setting_wnd_item_no_scroll[i].height = setting_p->Level1_setting_wnd_item[i].height;
            setting_p->Level1_setting_wnd_item_no_scroll[i].img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_NO_SCROLL_ICON;
        }
        
        setting_p->Level1_setting_wnd_botton.offset_x = setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].offset_x;
        setting_p->Level1_setting_wnd_botton.offset_y = setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].offset_y + setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].height;
    }
    else
    {
        setting_p->Level1_setting_wnd_top1.offset_x = setting_skin_p->Level1_setting_wnd_top1.offset_x;
        setting_p->Level1_setting_wnd_top1.offset_y = setting_skin_p->Level1_setting_wnd_top1.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP1_V_ICON,
            &setting_p->Level1_setting_wnd_top1.width,
            &setting_p->Level1_setting_wnd_top1.height);
        setting_p->Level1_setting_wnd_top1.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP1_V_ICON;

        setting_p->Level1_setting_wnd_top2.offset_x = setting_skin_p->Level1_setting_wnd_top2.offset_x;
        setting_p->Level1_setting_wnd_top2.offset_y = setting_skin_p->Level1_setting_wnd_top2.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP2_V_ICON,
            &setting_p->Level1_setting_wnd_top2.width,
            &setting_p->Level1_setting_wnd_top2.height);
        setting_p->Level1_setting_wnd_top2.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_TOP2_V_ICON;

        setting_p->Level1_setting_wnd_botton.offset_x = setting_skin_p->Level1_setting_wnd_botton.offset_x;
        setting_p->Level1_setting_wnd_botton.offset_y = setting_skin_p->Level1_setting_wnd_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_BOTTOM_V_ICON,
            &setting_p->Level1_setting_wnd_botton.width,
            &setting_p->Level1_setting_wnd_botton.height);
        setting_p->Level1_setting_wnd_botton.img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_BOTTOM_V_ICON;

        setting_p->Level1_setting_wnd_item[0].offset_x = setting_skin_p->Level1_setting_wnd_item.offset_x;
        setting_p->Level1_setting_wnd_item[0].offset_y = setting_skin_p->Level1_setting_wnd_item.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_V_ICON,
            &setting_p->Level1_setting_wnd_item[0].width,
            &setting_p->Level1_setting_wnd_item[0].height);
        setting_p->Level1_setting_wnd_item[0].img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_V_ICON;

        setting_p->Level1_setting_item_count = setting_skin_p->Level1_setting_item_count;

        for (i = 1; i < setting_skin_p->Level1_setting_item_count; i++)
        {
            setting_p->Level1_setting_wnd_item[i].offset_x = setting_skin_p->Level1_setting_wnd_item.offset_x;
            setting_p->Level1_setting_wnd_item[i].offset_y =
                setting_p->Level1_setting_wnd_item[i - 1].offset_y + setting_p->Level1_setting_wnd_item[i - 1].height;
            gdi_image_get_dimension_id(
                IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_V_ICON,
                &setting_p->Level1_setting_wnd_item[i].width,
                &setting_p->Level1_setting_wnd_item[i].height);
            setting_p->Level1_setting_wnd_item[i].img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_V_ICON;
        }

        for (i = 0; i < setting_skin_p->Level1_setting_item_count; i++)
        {
            setting_p->Level1_setting_wnd_item_no_scroll[i].offset_x = setting_p->Level1_setting_wnd_item[i].offset_x;
            setting_p->Level1_setting_wnd_item_no_scroll[i].offset_y = setting_p->Level1_setting_wnd_item[i].offset_y;
            setting_p->Level1_setting_wnd_item_no_scroll[i].width = setting_p->Level1_setting_wnd_item[i].width;
            setting_p->Level1_setting_wnd_item_no_scroll[i].height = setting_p->Level1_setting_wnd_item[i].height;
            setting_p->Level1_setting_wnd_item_no_scroll[i].img_id = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_BG_NO_SCROLL_V_ICON;
        }
        
        setting_p->Level1_setting_wnd_botton.offset_x = setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].offset_x;
        setting_p->Level1_setting_wnd_botton.offset_y = setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].offset_y + setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].height;    
    }
    
    setting_p->Level1_setting_wnd_attr[0].offset_x = setting_skin_p->Level1_setting_wnd_attr.offset_x;
    setting_p->Level1_setting_wnd_attr[0].offset_y = setting_skin_p->Level1_setting_wnd_attr.offset_y;

    for (i = 1; i < setting_skin_p->Level1_setting_item_count; i++)
    {
        setting_p->Level1_setting_wnd_attr[i].offset_x = setting_skin_p->Level1_setting_wnd_attr.offset_x;
        setting_p->Level1_setting_wnd_attr[i].offset_y =
            setting_p->Level1_setting_wnd_attr[i - 1].offset_y + setting_p->Level1_setting_wnd_item[0].height;
    }

    setting_p->Level1_setting_wnd_value[0].offset_x = setting_skin_p->Level1_setting_wnd_value.offset_x;
    setting_p->Level1_setting_wnd_value[0].offset_y = setting_skin_p->Level1_setting_wnd_value.offset_y;

    for (i = 1; i < setting_skin_p->Level1_setting_item_count; i++)
    {
        setting_p->Level1_setting_wnd_value[i].offset_x = setting_skin_p->Level1_setting_wnd_value.offset_x;
        setting_p->Level1_setting_wnd_value[i].offset_y =
            setting_p->Level1_setting_wnd_value[i - 1].offset_y + setting_p->Level1_setting_wnd_item[0].height;
    }

    setting_p->Level1_setting_wnd_icon[0].offset_x = setting_skin_p->Level1_setting_wnd_icon.offset_x;
    setting_p->Level1_setting_wnd_icon[0].offset_y = setting_skin_p->Level1_setting_wnd_icon.offset_y;

    for (i = 1; i < setting_skin_p->Level1_setting_item_count; i++)
    {
        setting_p->Level1_setting_wnd_icon[i].offset_x = setting_skin_p->Level1_setting_wnd_icon.offset_x;
        setting_p->Level1_setting_wnd_icon[i].offset_y =
            setting_p->Level1_setting_wnd_icon[i - 1].offset_y + setting_p->Level1_setting_wnd_item[0].height;
    }

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->Level1_setting_wnd_hilite_img = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_HILITE_ICON;
        setting_p->Level1_setting_wnd_hilite_no_scroll_img = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_HILITE_NO_SCROLL_ICON;
    }
    else
    {
        setting_p->Level1_setting_wnd_hilite_img = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_HILITE_V_ICON;
        setting_p->Level1_setting_wnd_hilite_no_scroll_img = IMG_ID_CAMCO_AD_SETTING_L1_MENU_ITEM_HILITE_NO_SCROLL_V_ICON;    
    }
    
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_TOP_ICON,
        &setting_p->scrolling_bar_ind_top.width,
        &setting_p->scrolling_bar_ind_top.height);
    setting_p->scrolling_bar_ind_top.img_id = IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_TOP_ICON;

    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_BODY_ICON,
        &setting_p->scrolling_bar_ind_body.width,
        &setting_p->scrolling_bar_ind_body.height);
    setting_p->scrolling_bar_ind_body.img_id = IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_BODY_ICON;

    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_BOTTOM_ICON,
        &setting_p->scrolling_bar_ind_bottom.width,
        &setting_p->scrolling_bar_ind_bottom.height);
    setting_p->scrolling_bar_ind_bottom.img_id = IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_BOTTOM_ICON;

    setting_p->Level1_scrolling_bar.offset_x = setting_skin_p->Level1_setting_wnd_scrolling_bar.offset_x;
    setting_p->Level1_scrolling_bar.offset_y = setting_skin_p->Level1_setting_wnd_scrolling_bar.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_ICON,
        &setting_p->Level1_scrolling_bar.width,
        &setting_p->Level1_scrolling_bar.height);
    setting_p->Level1_scrolling_bar.img_id = IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_ICON;

    setting_p->Level1_scrolling_bar_ind.offset_x = setting_skin_p->Level1_setting_wnd_scrolling_ind.offset_x;
    setting_p->Level1_scrolling_bar_ind.offset_y = setting_skin_p->Level1_setting_wnd_scrolling_ind.offset_y;

    setting_p->Level1_scrolling_bar_ind_region.offset_x = setting_p->Level1_scrolling_bar_ind.offset_x - 5;
    setting_p->Level1_scrolling_bar_ind_region.offset_y = setting_p->Level1_scrolling_bar_ind.offset_y - 5;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_BODY_ICON,
        &setting_p->Level1_scrolling_bar_ind_region.width,
        &setting_p->Level1_scrolling_bar_ind_region.height);
    setting_p->Level1_scrolling_bar_ind_region.width += 15;

    setting_p->Level1_scrolling_bar_real_region[0] = setting_skin_p->Level1_setting_wnd_scrolling_region[0];
    setting_p->Level1_scrolling_bar_real_region[1] = setting_skin_p->Level1_setting_wnd_scrolling_region[1];

    setting_p->Level1_scrolling_bar_region.offset_x = setting_p->Level1_scrolling_bar.offset_x - 15;
    setting_p->Level1_scrolling_bar_region.offset_y = 0;
    setting_p->Level1_scrolling_bar_region.width = setting_p->Level1_scrolling_bar.width + 30;
    setting_p->Level1_scrolling_bar_region.height = mmi_camco_osd_p->osd_height;

    mmi_camco_osd_p->ad_setting_menu_touch[0].offset_x = setting_p->Level1_setting_wnd_item[1].offset_x;
    mmi_camco_osd_p->ad_setting_menu_touch[0].offset_y = setting_p->Level1_setting_wnd_item[1].offset_y;
    mmi_camco_osd_p->ad_setting_menu_touch[0].width = setting_p->Level1_setting_wnd_item[1].width;
    mmi_camco_osd_p->ad_setting_menu_touch[0].height =
        setting_p->Level1_setting_wnd_item[0].height * (setting_skin_p->Level1_setting_item_count - 2);

    mmi_camco_osd_p->ad_setting_menu_pre_touch[0].offset_x = setting_p->Level1_setting_wnd_item[0].offset_x;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[0].offset_y = 0;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[0].width = setting_p->Level1_setting_wnd_item[0].width;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[0].height = setting_p->Level1_setting_wnd_item[1].offset_y;

    mmi_camco_osd_p->ad_setting_menu_next_touch[0].offset_x = setting_p->Level1_setting_wnd_item[0].offset_x;
    mmi_camco_osd_p->ad_setting_menu_next_touch[0].offset_y =
        setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].offset_y;
    mmi_camco_osd_p->ad_setting_menu_next_touch[0].width = setting_p->Level1_setting_wnd_item[0].width;
    mmi_camco_osd_p->ad_setting_menu_next_touch[0].height =
        mmi_camco_osd_p->osd_height - setting_p->Level1_setting_wnd_item[setting_skin_p->Level1_setting_item_count - 1].offset_y;

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->Level2_setting_wnd_top.offset_x = setting_skin_p->Level2_setting_wnd_top.offset_x;
        setting_p->Level2_setting_wnd_top.offset_y = setting_skin_p->Level2_setting_wnd_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L2_MENU_TOP_ICON,
            &setting_p->Level2_setting_wnd_top.width,
            &setting_p->Level2_setting_wnd_top.height);
        setting_p->Level2_setting_wnd_top.img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_TOP_ICON;

        setting_p->Level2_setting_wnd_botton.offset_x = setting_skin_p->Level2_setting_wnd_botton.offset_x;
        setting_p->Level2_setting_wnd_botton.offset_y = setting_skin_p->Level2_setting_wnd_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L2_MENU_BOTTOM_ICON,
            &setting_p->Level2_setting_wnd_botton.width,
            &setting_p->Level2_setting_wnd_botton.height);
        setting_p->Level2_setting_wnd_botton.img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_BOTTOM_ICON;

        setting_p->Level2_setting_wnd_item[0].offset_x = setting_skin_p->Level2_setting_wnd_item.offset_x;
        setting_p->Level2_setting_wnd_item[0].offset_y = setting_skin_p->Level2_setting_wnd_item.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_ICON,
            &setting_p->Level2_setting_wnd_item[0].width,
            &setting_p->Level2_setting_wnd_item[0].height);
        setting_p->Level2_setting_wnd_item[0].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_ICON;

        setting_p->Level2_setting_item_count = setting_skin_p->Level2_setting_item_count;

        for (i = 1; i < setting_skin_p->Level2_setting_item_count; i++)
        {
            setting_p->Level2_setting_wnd_item[i].offset_x = setting_skin_p->Level2_setting_wnd_item.offset_x;
            setting_p->Level2_setting_wnd_item[i].offset_y =
                setting_p->Level2_setting_wnd_item[i - 1].offset_y + setting_p->Level2_setting_wnd_item[i - 1].height;
            gdi_image_get_dimension_id(
                IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_ICON,
                &setting_p->Level2_setting_wnd_item[i].width,
                &setting_p->Level2_setting_wnd_item[i].height);
            setting_p->Level2_setting_wnd_item[i].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_ICON;
        }

        for (i = 0; i < setting_skin_p->Level2_setting_item_count; i++)
        {
            setting_p->Level2_setting_wnd_item_no_scroll[i].offset_x = setting_p->Level2_setting_wnd_item[i].offset_x;
            setting_p->Level2_setting_wnd_item_no_scroll[i].offset_y = setting_p->Level2_setting_wnd_item[i].offset_y;
            setting_p->Level2_setting_wnd_item_no_scroll[i].width = setting_p->Level2_setting_wnd_item[i].width;
            setting_p->Level2_setting_wnd_item_no_scroll[i].height = setting_p->Level2_setting_wnd_item[i].height;
            setting_p->Level2_setting_wnd_item_no_scroll[i].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_NO_SCROLL_ICON;
        }        
    }
    else
    {
        setting_p->Level2_setting_wnd_top.offset_x = setting_skin_p->Level2_setting_wnd_top.offset_x;
        setting_p->Level2_setting_wnd_top.offset_y = setting_skin_p->Level2_setting_wnd_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L2_MENU_TOP_V_ICON,
            &setting_p->Level2_setting_wnd_top.width,
            &setting_p->Level2_setting_wnd_top.height);
        setting_p->Level2_setting_wnd_top.img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_TOP_V_ICON;

        setting_p->Level2_setting_wnd_botton.offset_x = setting_skin_p->Level2_setting_wnd_botton.offset_x;
        setting_p->Level2_setting_wnd_botton.offset_y = setting_skin_p->Level2_setting_wnd_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L2_MENU_BOTTOM_V_ICON,
            &setting_p->Level2_setting_wnd_botton.width,
            &setting_p->Level2_setting_wnd_botton.height);
        setting_p->Level2_setting_wnd_botton.img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_BOTTOM_V_ICON;

        setting_p->Level2_setting_wnd_item[0].offset_x = setting_skin_p->Level2_setting_wnd_item.offset_x;
        setting_p->Level2_setting_wnd_item[0].offset_y = setting_skin_p->Level2_setting_wnd_item.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_V_ICON,
            &setting_p->Level2_setting_wnd_item[0].width,
            &setting_p->Level2_setting_wnd_item[0].height);
        setting_p->Level2_setting_wnd_item[0].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_V_ICON;

        setting_p->Level2_setting_item_count = setting_skin_p->Level2_setting_item_count;

        for (i = 1; i < setting_skin_p->Level2_setting_item_count; i++)
        {
            setting_p->Level2_setting_wnd_item[i].offset_x = setting_skin_p->Level2_setting_wnd_item.offset_x;
            setting_p->Level2_setting_wnd_item[i].offset_y =
                setting_p->Level2_setting_wnd_item[i - 1].offset_y + setting_p->Level2_setting_wnd_item[i - 1].height;
            gdi_image_get_dimension_id(
                IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_V_ICON,
                &setting_p->Level2_setting_wnd_item[i].width,
                &setting_p->Level2_setting_wnd_item[i].height);
            setting_p->Level2_setting_wnd_item[i].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_V_ICON;
        }    
        
        for (i = 0; i < setting_skin_p->Level2_setting_item_count; i++)
        {
            setting_p->Level2_setting_wnd_item_no_scroll[i].offset_x = setting_p->Level2_setting_wnd_item[i].offset_x;
            setting_p->Level2_setting_wnd_item_no_scroll[i].offset_y = setting_p->Level2_setting_wnd_item[i].offset_y;
            setting_p->Level2_setting_wnd_item_no_scroll[i].width = setting_p->Level2_setting_wnd_item[i].width;
            setting_p->Level2_setting_wnd_item_no_scroll[i].height = setting_p->Level2_setting_wnd_item[i].height;
            setting_p->Level2_setting_wnd_item_no_scroll[i].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_BG_NO_SCROLL_V_ICON;
        }
    }

    setting_p->Level2_setting_wnd_botton.offset_x = setting_p->Level2_setting_wnd_item[setting_skin_p->Level2_setting_item_count - 1].offset_x;
    setting_p->Level2_setting_wnd_botton.offset_y = setting_p->Level2_setting_wnd_item[setting_skin_p->Level2_setting_item_count - 1].offset_y + setting_p->Level2_setting_wnd_item[setting_skin_p->Level2_setting_item_count - 1].height;

    setting_p->Level2_setting_wnd_value[0].offset_x = setting_skin_p->Level2_setting_wnd_value.offset_x;
    setting_p->Level2_setting_wnd_value[0].offset_y = setting_skin_p->Level2_setting_wnd_value.offset_y;

    for (i = 1; i < setting_skin_p->Level2_setting_item_count; i++)
    {
        setting_p->Level2_setting_wnd_value[i].offset_x = setting_skin_p->Level2_setting_wnd_value.offset_x;
        setting_p->Level2_setting_wnd_value[i].offset_y =
            setting_p->Level2_setting_wnd_value[i - 1].offset_y + setting_p->Level2_setting_wnd_item[0].height;
    }

    setting_p->Level2_setting_wnd_check[0].offset_x = setting_skin_p->Level2_setting_wnd_check.offset_x;
    setting_p->Level2_setting_wnd_check[0].offset_y = setting_skin_p->Level2_setting_wnd_check.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_L2_MENU_SELECTED_ICON,
        &setting_p->Level2_setting_wnd_check[0].width,
        &setting_p->Level2_setting_wnd_check[0].height);
    setting_p->Level2_setting_wnd_check[0].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_SELECTED_ICON;

    for (i = 1; i < setting_skin_p->Level2_setting_item_count; i++)
    {
        setting_p->Level2_setting_wnd_check[i].offset_x = setting_skin_p->Level2_setting_wnd_check.offset_x;
        setting_p->Level2_setting_wnd_check[i].offset_y =
            setting_p->Level2_setting_wnd_check[i - 1].offset_y + setting_p->Level2_setting_wnd_item[0].height;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_AD_SETTING_L2_MENU_SELECTED_ICON,
            &setting_p->Level2_setting_wnd_check[i].width,
            &setting_p->Level2_setting_wnd_check[i].height);
        setting_p->Level2_setting_wnd_check[i].img_id = IMG_ID_CAMCO_AD_SETTING_L2_MENU_SELECTED_ICON;
    }

    setting_p->Level2_setting_wnd_icon[0].offset_x = setting_skin_p->Level2_setting_wnd_icon.offset_x;
    setting_p->Level2_setting_wnd_icon[0].offset_y = setting_skin_p->Level2_setting_wnd_icon.offset_y;

    setting_p->Level2_scrolling_bar.offset_x = setting_skin_p->Level2_setting_wnd_scrolling_bar.offset_x;
    setting_p->Level2_scrolling_bar.offset_y = setting_skin_p->Level2_setting_wnd_scrolling_bar.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_ICON,
        &setting_p->Level2_scrolling_bar.width,
        &setting_p->Level2_scrolling_bar.height);
    setting_p->Level2_scrolling_bar.img_id = IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_ICON;

    setting_p->Level2_scrolling_bar_ind.offset_x = setting_skin_p->Level2_setting_wnd_scrolling_ind.offset_x;
    setting_p->Level2_scrolling_bar_ind.offset_y = setting_skin_p->Level2_setting_wnd_scrolling_ind.offset_y;

    setting_p->Level2_scrolling_bar_ind_region.offset_x = setting_p->Level2_scrolling_bar_ind.offset_x - 5;
    setting_p->Level2_scrolling_bar_ind_region.offset_y = setting_p->Level2_scrolling_bar_ind.offset_y - 5;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_AD_SETTING_MENU_SCROLLING_BAR_IND_BODY_ICON,
        &setting_p->Level2_scrolling_bar_ind_region.width,
        &setting_p->Level2_scrolling_bar_ind_region.height);
    setting_p->Level2_scrolling_bar_ind_region.width += 15;

    setting_p->Level2_scrolling_bar_real_region[0] = setting_skin_p->Level2_setting_wnd_scrolling_region[0];
    setting_p->Level2_scrolling_bar_real_region[1] = setting_skin_p->Level2_setting_wnd_scrolling_region[1];

    setting_p->Level2_scrolling_bar_region.offset_x = setting_p->Level2_scrolling_bar.offset_x - 15;
    setting_p->Level2_scrolling_bar_region.offset_y = 0; 
    setting_p->Level2_scrolling_bar_region.width = setting_p->Level2_scrolling_bar.width + 30;
    setting_p->Level2_scrolling_bar_region.height = mmi_camco_osd_p->osd_height; 

    for (i = 1; i < setting_skin_p->Level2_setting_item_count; i++)
    {
        setting_p->Level2_setting_wnd_icon[i].offset_x = setting_skin_p->Level2_setting_wnd_icon.offset_x;
        setting_p->Level2_setting_wnd_icon[i].offset_y =
            setting_p->Level2_setting_wnd_icon[i - 1].offset_y + setting_p->Level2_setting_wnd_item[0].height;
    }

    if (mmi_camco_osd_is_horz_UI())
    {
        setting_p->Level2_setting_wnd_hilite_img = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_HILITE_ICON;
        setting_p->Level2_setting_wnd_hilite_no_scroll_img = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_HILITE_NO_SCROLL_ICON;
    }
    else
    {
        setting_p->Level2_setting_wnd_hilite_img = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_HILITE_V_ICON;
        setting_p->Level2_setting_wnd_hilite_no_scroll_img = IMG_ID_CAMCO_AD_SETTING_L2_MENU_ITEM_HILITE_NO_SCROLL_V_ICON;
    }
    
    mmi_camco_osd_p->ad_setting_menu_touch[1].offset_x = setting_p->Level2_setting_wnd_item[1].offset_x;
    mmi_camco_osd_p->ad_setting_menu_touch[1].offset_y = setting_p->Level2_setting_wnd_item[1].offset_y;
    mmi_camco_osd_p->ad_setting_menu_touch[1].width = setting_p->Level2_setting_wnd_item[1].width;
    mmi_camco_osd_p->ad_setting_menu_touch[1].height =
        setting_p->Level2_setting_wnd_item[1].height * (setting_skin_p->Level2_setting_item_count - 2);

    mmi_camco_osd_p->ad_setting_menu_pre_touch[1].offset_x = setting_p->Level2_setting_wnd_item[0].offset_x;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[1].offset_y =
        setting_p->Level2_setting_wnd_item[0].offset_y - setting_p->Level2_setting_wnd_item[0].height;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[1].width = setting_p->Level2_setting_wnd_item[0].width;
    mmi_camco_osd_p->ad_setting_menu_pre_touch[1].height = setting_p->Level2_setting_wnd_item[0].height * 2;

    mmi_camco_osd_p->ad_setting_menu_next_touch[1].offset_x =
        setting_p->Level2_setting_wnd_item[setting_skin_p->Level2_setting_item_count - 1].offset_x;
    mmi_camco_osd_p->ad_setting_menu_next_touch[1].offset_y =
        setting_p->Level2_setting_wnd_item[setting_skin_p->Level2_setting_item_count - 1].offset_y;
    mmi_camco_osd_p->ad_setting_menu_next_touch[1].width =
        setting_p->Level2_setting_wnd_item[setting_skin_p->Level2_setting_item_count - 1].width;
    mmi_camco_osd_p->ad_setting_menu_next_touch[1].height =
        mmi_camco_osd_p->osd_height - setting_p->Level2_setting_wnd_item[setting_skin_p->Level2_setting_item_count - 1].offset_y;

    setting_p->menu_status = MMI_CAMCO_OSD_MENU_CLOSE;

    mmi_camco_osd_p->setting_menulist.max_disp_item_count = setting_p->Level2_setting_item_count;
    mmi_camco_osd_p->iconlist.disp_icon_count = setting_p->Level1_setting_item_count;

    setting_p->back.offset_x = setting_skin_p->back.offset_x;
    setting_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_AD_SETTING_BACK_ICON, &setting_p->back.width, &setting_p->back.height);
    setting_p->back.img_id = IMG_ID_CAMCO_AD_SETTING_BACK_ICON;

    setting_p->OK.offset_x = mmi_camco_osd_skin_p->camera_direct_setting.advance_setting .offset_x;
    setting_p->OK.offset_y = mmi_camco_osd_skin_p->camera_direct_setting.advance_setting.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_OK_ICON, &setting_p->OK.width, &setting_p->OK.height);
    setting_p->OK.img_id = IMG_ID_CAMCO_OK_ICON;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_confirm_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_confirm_struct *confirm_p = &mmi_camco_osd_p->confirm_screen;
    mmi_camco_confirm_skin_struct *confirm_skin_p = &(mmi_camco_osd_skin_p->confirm);
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    confirm_p->confirm_title.offset_x = confirm_skin_p->option_wnd_title.offset_x;
    confirm_p->confirm_title.offset_y = confirm_skin_p->option_wnd_title.offset_y;

    confirm_p->confirm_sub_title.offset_x = confirm_skin_p->option_wnd_content.offset_x;
    confirm_p->confirm_sub_title.offset_y = confirm_skin_p->option_wnd_content.offset_y;

    if (mmi_camco_osd_is_horz_UI())
    {
        confirm_p->confirm_body.offset_x = confirm_skin_p->option_wnd_body.offset_x;
        confirm_p->confirm_body.offset_y = confirm_skin_p->option_wnd_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_CONFIRM_BG_ICON,
            &confirm_p->confirm_body.width,
            &confirm_p->confirm_body.height);
        confirm_p->confirm_body.img_id = IMG_ID_CAMCO_CONFIRM_BG_ICON;
        confirm_p->confirm_body.offset_x = (mmi_camco_osd_p->osd_width - confirm_p->confirm_body.width) >> 1;
    }
    else
    {
        confirm_p->confirm_body.offset_x = confirm_skin_p->option_wnd_body.offset_x;
        confirm_p->confirm_body.offset_y = confirm_skin_p->option_wnd_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_CONFIRM_BG_V_ICON,
            &confirm_p->confirm_body.width,
            &confirm_p->confirm_body.height);
        confirm_p->confirm_body.img_id = IMG_ID_CAMCO_CONFIRM_BG_V_ICON;
        confirm_p->confirm_body.offset_x = (mmi_camco_osd_p->osd_width - confirm_p->confirm_body.width) >> 1;    
    }
    
    confirm_p->confirm_lsk.offset_x = confirm_skin_p->option_left_softkey.offset_x;
    confirm_p->confirm_lsk.offset_y = confirm_skin_p->option_left_softkey.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CONFIRM_OK_ICON,
        &confirm_p->confirm_lsk.width,
        &confirm_p->confirm_lsk.height);
    confirm_p->confirm_lsk.img_id = IMG_ID_CAMCO_CONFIRM_OK_ICON;

    confirm_p->confirm_rsk.offset_x = confirm_skin_p->option_right_softkey.offset_x;
    confirm_p->confirm_rsk.offset_y = confirm_skin_p->option_right_softkey.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CONFIRM_CANCEL_ICON,
        &confirm_p->confirm_rsk.width,
        &confirm_p->confirm_rsk.height);
    confirm_p->confirm_rsk.img_id = IMG_ID_CAMCO_CONFIRM_CANCEL_ICON;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_storage_sel_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_storage_sel_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_storage_sel_struct *option_p = &mmi_camco_osd_p->storage_select_screen;
    mmi_camco_forward_option_skin_struct *option_skin_p = &(mmi_camco_osd_skin_p->forward_option);
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);
    U8 space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_p->confirm_title.offset_x = option_skin_p->option_wnd_title.offset_x;
    option_p->confirm_title.offset_y = option_skin_p->option_wnd_title.offset_y;

    option_p->confirm_sub_title.offset_x = option_skin_p->option_wnd_sub_title.offset_x;
    option_p->confirm_sub_title.offset_y = option_skin_p->option_wnd_sub_title.offset_y;

    option_p->confirm_body.offset_x = option_skin_p->option_wnd_body.offset_x;
    option_p->confirm_body.offset_y = option_skin_p->option_wnd_body.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_DIR_SETTING_WND_SINGLE_ICON,
        &option_p->confirm_body.width,
        &option_p->confirm_body.height);
    option_p->confirm_body.img_id = IMG_ID_CAMCO_DIR_SETTING_WND_SINGLE_ICON;
   
    option_p->back.offset_x = setting_skin_p->back.offset_x;
    option_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &option_p->back.width, &option_p->back.height);
    option_p->back.img_id = IMG_ID_CAMCO_BACK_ICON;


}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_forward_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_forward_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_forward_struct *option_p = &mmi_camco_osd_p->forward_screen;
    mmi_camco_forward_option_skin_struct *option_skin_p = &(mmi_camco_osd_skin_p->forward_option);
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);
    U8 space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_p->confirm_title.offset_x = option_skin_p->option_wnd_title.offset_x;
    option_p->confirm_title.offset_y = option_skin_p->option_wnd_title.offset_y;

    option_p->confirm_sub_title.offset_x = option_skin_p->option_wnd_sub_title.offset_x;
    option_p->confirm_sub_title.offset_y = option_skin_p->option_wnd_sub_title.offset_y;

    if (mmi_camco_osd_is_horz_UI())
    {
        option_p->confirm_body.offset_x = option_skin_p->option_wnd_body.offset_x;
        option_p->confirm_body.offset_y = option_skin_p->option_wnd_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_WND_SINGLE_ICON,
            &option_p->confirm_body.width,
            &option_p->confirm_body.height);
        option_p->confirm_body.img_id = IMG_ID_CAMCO_DIR_SETTING_WND_SINGLE_ICON;
    }
    else
    {
        option_p->confirm_body.offset_x = option_skin_p->option_wnd_body.offset_x;
        option_p->confirm_body.offset_y = option_skin_p->option_wnd_body.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_WND_SINGLE_V_ICON,
            &option_p->confirm_body.width,
            &option_p->confirm_body.height);
        option_p->confirm_body.img_id = IMG_ID_CAMCO_DIR_SETTING_WND_SINGLE_V_ICON;    
    }
    
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAPTURED_FW_OPTION_BT_ICON,
        &option_p->item[0].width,
        &option_p->item[0].height);
    option_p->item[0].img_id = IMG_ID_CAMCO_CAPTURED_FW_OPTION_BT_ICON;
    option_p->item[0].offset_y = option_skin_p->option_item.offset_y;
    space = (option_p->confirm_body.width - (3 * option_p->item[0].width)) >> 2;
    option_p->item[0].offset_x = option_skin_p->option_item.offset_x = option_p->confirm_body.offset_x + space;

    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAPTURED_FW_OPTION_MMS_ICON,
        &option_p->item[1].width,
        &option_p->item[1].height);
    option_p->item[1].img_id = IMG_ID_CAMCO_CAPTURED_FW_OPTION_MMS_ICON;
    option_p->item[1].offset_y = option_skin_p->option_item.offset_y;
    option_p->item[1].offset_x = option_skin_p->option_item.offset_x =
        option_p->confirm_body.offset_x + space * 2 + option_p->item[1].width;

    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAPTURED_FW_OPTION_EMAIL_ICON,
        &option_p->item[2].width,
        &option_p->item[2].height);
    option_p->item[2].img_id = IMG_ID_CAMCO_CAPTURED_FW_OPTION_EMAIL_ICON;
    option_p->item[2].offset_y = option_skin_p->option_item.offset_y;
    option_p->item[2].offset_x = option_skin_p->option_item.offset_x =
        option_p->confirm_body.offset_x + space * 3 + option_p->item[2].width * 2;

    if (mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        option_p->tool_bar[0].offset_x = option_skin_p->toolbar[0].offset_x;
        option_p->tool_bar[0].offset_y = option_skin_p->toolbar[0].offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON,
            &option_p->tool_bar[0].width,
            &option_p->tool_bar[0].height);
        option_p->tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON;

    }
    else
    {
        option_p->tool_bar[0].offset_x = option_skin_p->toolbar[0].offset_x;
        option_p->tool_bar[0].offset_y = option_skin_p->toolbar[0].offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_CAM_CAPTURED_OPTION_PLY_ICON,
            &option_p->tool_bar[0].width,
            &option_p->tool_bar[0].height);
        option_p->tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_PLY_ICON;
    }

    option_p->tool_bar[1].offset_x = option_skin_p->toolbar[1].offset_x;
    option_p->tool_bar[1].offset_y = option_skin_p->toolbar[1].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_DEL_ICON,
        &option_p->tool_bar[1].width,
        &option_p->tool_bar[1].height);
    option_p->tool_bar[1].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_DEL_ICON;

    option_p->tool_bar[2].offset_x = option_skin_p->toolbar[2].offset_x;
    option_p->tool_bar[2].offset_y = option_skin_p->toolbar[2].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_FW_ICON,
        &option_p->tool_bar[2].width,
        &option_p->tool_bar[2].height);
    option_p->tool_bar[2].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_FW_ICON;

    option_p->back.offset_x = setting_skin_p->back.offset_x;
    option_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &option_p->back.width, &option_p->back.height);
    option_p->back.img_id = IMG_ID_CAMCO_BACK_ICON;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_captured_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_captured_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_captured_struct *cap_scr_p = &mmi_camco_osd_p->captured_screen;
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);
    mmi_camco_captured_skin_struct *cap_skin_p = &(mmi_camco_osd_skin_p->captured);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        cap_scr_p->tool_bar[0].offset_x = cap_skin_p->toolbar[0].offset_x;
        cap_scr_p->tool_bar[0].offset_y = cap_skin_p->toolbar[0].offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON,
            &cap_scr_p->tool_bar[0].width,
            &cap_scr_p->tool_bar[0].height);
        cap_scr_p->tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON;
    }
    else
    {
        cap_scr_p->tool_bar[0].offset_x = cap_skin_p->toolbar[0].offset_x;
        cap_scr_p->tool_bar[0].offset_y = cap_skin_p->toolbar[0].offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_CAM_CAPTURED_OPTION_PLY_ICON,
            &cap_scr_p->tool_bar[0].width,
            &cap_scr_p->tool_bar[0].height);
        cap_scr_p->tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_PLY_ICON;
    }

    cap_scr_p->tool_bar[1].offset_x = cap_skin_p->toolbar[1].offset_x;
    cap_scr_p->tool_bar[1].offset_y = cap_skin_p->toolbar[1].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_DEL_ICON,
        &cap_scr_p->tool_bar[1].width,
        &cap_scr_p->tool_bar[1].height);
    cap_scr_p->tool_bar[1].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_DEL_ICON;

    cap_scr_p->tool_bar[2].offset_x = cap_skin_p->toolbar[2].offset_x;
    cap_scr_p->tool_bar[2].offset_y = cap_skin_p->toolbar[2].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_FW_ICON,
        &cap_scr_p->tool_bar[2].width,
        &cap_scr_p->tool_bar[2].height);
    cap_scr_p->tool_bar[2].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_FW_ICON;

    cap_scr_p->back.offset_x = setting_skin_p->back.offset_x;
    cap_scr_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &cap_scr_p->back.width, &cap_scr_p->back.height);
    cap_scr_p->back.img_id = IMG_ID_CAMCO_BACK_ICON;

    cap_scr_p->is_img_select = KAL_FALSE;

}

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_captured_img_select_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_captured_img_select_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_captured_struct *cap_scr_p = &mmi_camco_osd_p->captured_img_select_screen;
    mmi_camco_camera_preview_setting_skin_struct *setting_skin_p = &(mmi_camco_osd_skin_p->camera_direct_setting);
    mmi_camco_multi_select_cache_skin_struct *cap_skin_p = &(mmi_camco_osd_skin_p->multiselect_cache);
    U8 i;
    U8 sizeofimg;
    U8 space = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cap_scr_p->tool_bar[0].offset_x = cap_skin_p->toolbar[0].offset_x;
    cap_scr_p->tool_bar[0].offset_y = cap_skin_p->toolbar[0].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON,
        &cap_scr_p->tool_bar[0].width,
        &cap_scr_p->tool_bar[0].height);
    cap_scr_p->tool_bar[0].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_VIEW_ICON;

    cap_scr_p->tool_bar[1].offset_x = cap_skin_p->toolbar[1].offset_x;
    cap_scr_p->tool_bar[1].offset_y = cap_skin_p->toolbar[1].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_DEL_ICON,
        &cap_scr_p->tool_bar[1].width,
        &cap_scr_p->tool_bar[1].height);
    cap_scr_p->tool_bar[1].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_DEL_ICON;
    
    cap_scr_p->save.offset_x = cap_skin_p->toolbar[1].offset_x;
    cap_scr_p->save.offset_y = cap_skin_p->toolbar[1].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_SAVE_ICON,
        &cap_scr_p->save.width,
        &cap_scr_p->save.height);
    cap_scr_p->save.img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_SAVE_ICON;

    cap_scr_p->tool_bar[2].offset_x = cap_skin_p->toolbar[2].offset_x;
    cap_scr_p->tool_bar[2].offset_y = cap_skin_p->toolbar[2].offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_CAM_CAPTURED_OPTION_FW_ICON,
        &cap_scr_p->tool_bar[2].width,
        &cap_scr_p->tool_bar[2].height);
    cap_scr_p->tool_bar[2].img_id = IMG_ID_CAMCO_CAM_CAPTURED_OPTION_FW_ICON;

    cap_scr_p->is_img_select = KAL_FALSE;

    cap_scr_p->img_list_count = cap_skin_p->display_count;
    ASSERT(cap_scr_p->img_list_count <= 5);

    for (i = 0; i < cap_scr_p->img_list_count; i++)
    {
        cap_scr_p->image_frame_list[i].width = mmi_camco_osd_skin_p->multiselect_cache.img_w;
        cap_scr_p->image_frame_list[i].height= mmi_camco_osd_skin_p->multiselect_cache.img_h;
        cap_scr_p->image_frame_list[i].img_id = IMG_ID_CAMCO_CAM_IMG_LIST_ITEM_ICON;

        cap_scr_p->image_frame_list[i].offset_x =
            cap_skin_p->img_frame.offset_x + (cap_scr_p->image_frame_list[i].width * i);
        cap_scr_p->image_frame_list[i].offset_y = MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH;

        cap_scr_p->image_list[i].offset_x =
            cap_scr_p->image_frame_list[i].offset_x + cap_skin_p->img_list_offset.offset_x;
        cap_scr_p->image_list[i].offset_y =
            cap_scr_p->image_frame_list[i].offset_y + cap_skin_p->img_list_offset.offset_y;
        cap_scr_p->image_list[i].height = mmi_camco_osd_skin_p->multiselect_cache.img_h;
        cap_scr_p->image_list[i].width = mmi_camco_osd_skin_p->multiselect_cache.img_w;

        cap_scr_p->image_list_touch[i].offset_x = cap_scr_p->image_list[i].offset_x;
        if(mmi_camco_osd_is_horz_UI())
        {
            cap_scr_p->image_list_touch[i].offset_y =
                cap_scr_p->image_list[i].offset_y + (mmi_camco_osd_p->osd_height - cap_scr_p->image_frame_list[i].height -
                                                     2 * MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH);
        }
        else
        {
            cap_scr_p->image_list_touch[i].offset_y = mmi_camco_osd_skin_p->multiselect_cache.img_frame.offset_y + MMI_CAMCO_OSD_IMGSEL_CACHE_LAYER_EXTEND_LENGTH;
        }
        
        
    
        cap_scr_p->image_list_touch[i].width = cap_scr_p->image_list[i].width;
        cap_scr_p->image_list_touch[i].height = cap_scr_p->image_list[i].height;
    }

    cap_scr_p->hilite_picture.offset_x = cap_skin_p->hilite_img_pos.offset_x;
    cap_scr_p->hilite_picture.offset_y = cap_skin_p->hilite_img_pos.offset_y;
    cap_scr_p->hilite_picture.width = cap_skin_p->hilite_img_w;
    cap_scr_p->hilite_picture.height = cap_skin_p->hilite_img_h;

    cap_scr_p->back.offset_x = setting_skin_p->back.offset_x;
    cap_scr_p->back.offset_y = setting_skin_p->back.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_BACK_ICON, &cap_scr_p->back.width, &cap_scr_p->back.height);
    cap_scr_p->back.img_id = IMG_ID_CAMCO_BACK_ICON;

}
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init_recording_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init_recording_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_rec_screen_struct *rec_scr_p = &mmi_camco_osd_p->recording_screen;
    mmi_camco_video_recording_skin_struct *rec_skin_p = &(mmi_camco_osd_skin_p->recording_screen);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rec_scr_p->pause.offset_x = rec_skin_p->pause_resume.offset_x;
    rec_scr_p->pause.offset_y = rec_skin_p->pause_resume.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_REC_PAUSE_ICON, &rec_scr_p->pause.width, &rec_scr_p->pause.height);
    rec_scr_p->pause.img_id = IMG_ID_CAMCO_REC_PAUSE_ICON;

    rec_scr_p->resume.offset_x = rec_skin_p->pause_resume.offset_x;
    rec_scr_p->resume.offset_y = rec_skin_p->pause_resume.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_REC_PLAY_ICON, &rec_scr_p->resume.width, &rec_scr_p->resume.height);
    rec_scr_p->resume.img_id = IMG_ID_CAMCO_REC_PLAY_ICON;

    rec_scr_p->start.offset_x = rec_skin_p->pause_resume.offset_x;
    rec_scr_p->start.offset_y = rec_skin_p->pause_resume.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_REC_PLAY_ICON, &rec_scr_p->start.width, &rec_scr_p->start.height);
    rec_scr_p->start.img_id = IMG_ID_CAMCO_REC_PLAY_ICON;

    rec_scr_p->stop.offset_x = rec_skin_p->start_stop.offset_x;
    rec_scr_p->stop.offset_y = rec_skin_p->start_stop.offset_y;
    gdi_image_get_dimension_id(IMG_ID_CAMCO_REC_STOP_ICON, &rec_scr_p->stop.width, &rec_scr_p->stop.height);
    rec_scr_p->stop.img_id = IMG_ID_CAMCO_REC_STOP_ICON;

    if (mmi_camco_osd_is_horz_UI())
    {
        rec_scr_p->slider_zoom_top.offset_x = rec_skin_p->slider_top.offset_x;
        rec_scr_p->slider_zoom_top.offset_y = rec_skin_p->slider_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON,
            &rec_scr_p->slider_zoom_top.width,
            &rec_scr_p->slider_zoom_top.height);
        rec_scr_p->slider_zoom_top.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_ICON;

        rec_scr_p->slider_bar.offset_x = rec_skin_p->slider_bar.offset_x;
        rec_scr_p->slider_bar.offset_y = rec_skin_p->slider_bar.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON,
            &rec_scr_p->slider_bar.width,
            &rec_scr_p->slider_bar.height);
        rec_scr_p->slider_bar.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_ICON;


        rec_scr_p->slider_zoom_botton.offset_x = rec_skin_p->slider_botton.offset_x;
        rec_scr_p->slider_zoom_botton.offset_y = rec_skin_p->slider_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON,
            &rec_scr_p->slider_zoom_botton.width,
            &rec_scr_p->slider_zoom_botton.height);
        rec_scr_p->slider_zoom_botton.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_ICON;
    }
    else
    {
        rec_scr_p->slider_zoom_top.offset_x = rec_skin_p->slider_top.offset_x;
        rec_scr_p->slider_zoom_top.offset_y = rec_skin_p->slider_top.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON,
            &rec_scr_p->slider_zoom_top.width,
            &rec_scr_p->slider_zoom_top.height);
        rec_scr_p->slider_zoom_top.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_INC_V_ICON;

        rec_scr_p->slider_bar.offset_x = rec_skin_p->slider_bar.offset_x;
        rec_scr_p->slider_bar.offset_y = rec_skin_p->slider_bar.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON,
            &rec_scr_p->slider_bar.width,
            &rec_scr_p->slider_bar.height);
        rec_scr_p->slider_bar.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_BAR_V_ICON;


        rec_scr_p->slider_zoom_botton.offset_x = rec_skin_p->slider_botton.offset_x;
        rec_scr_p->slider_zoom_botton.offset_y = rec_skin_p->slider_botton.offset_y;
        gdi_image_get_dimension_id(
            IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON,
            &rec_scr_p->slider_zoom_botton.width,
            &rec_scr_p->slider_zoom_botton.height);
        rec_scr_p->slider_zoom_botton.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_ZOOM_DEC_V_ICON;
    }     
    
    rec_scr_p->slider_location.offset_x = rec_skin_p->slider_location.offset_x;
    rec_scr_p->slider_location.offset_y = rec_skin_p->slider_location.offset_y;
    gdi_image_get_dimension_id(
        IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON,
        &rec_scr_p->slider_location.width,
        &rec_scr_p->slider_location.height);
    rec_scr_p->slider_location.img_id = IMG_ID_CAMCO_DIR_SETTING_SLIDER_IND_ICON;

    rec_scr_p->slider_location_region.offset_x = rec_scr_p->slider_location.offset_x - 10;
    rec_scr_p->slider_location_region.offset_y = rec_scr_p->slider_location.offset_y - 5;
    rec_scr_p->slider_location_region.width = rec_scr_p->slider_location.width + 20;
    rec_scr_p->slider_location_region.height = rec_scr_p->slider_location.height + 10;

    rec_scr_p->slider_region.offset_x = rec_scr_p->slider_bar.offset_x + (rec_scr_p->slider_location.width>> 1);
    rec_scr_p->slider_region.offset_y = rec_scr_p->slider_bar.offset_y + (rec_scr_p->slider_location.height >> 1);
    rec_scr_p->slider_region.width = rec_scr_p->slider_bar.width - rec_scr_p->slider_location.width;
    rec_scr_p->slider_region.height = rec_scr_p->slider_bar.height - rec_scr_p->slider_location.height;

    mmi_camco_osd_p->rec_slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;
    rec_scr_p->slider_switch_is_zoom = MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef DUAL_CAMERA_SUPPORT
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        mmi_camco_osd_skin_p = &mmi_camco_main_skin_cntx;
    }
    else
    {
        mmi_camco_osd_skin_p = &mmi_camco_sub_skin_cntx;
    }
#endif /* DUAL_CAMERA_SUPPORT */ 

    if (mmi_camco_osd_is_horz_UI())
    {
        mmi_camco_osd_p->osd_width = UI_device_height;
        mmi_camco_osd_p->osd_height = UI_device_width;
    }
    else
    {
        mmi_camco_osd_p->osd_width = UI_device_width;
        mmi_camco_osd_p->osd_height = UI_device_height;
    }

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
#ifdef HORIZONTAL_CAMERA
    mmi_camco_osd_p->sublcd_osd_width = SUBLCD_HEIGHT;
    mmi_camco_osd_p->sublcd_osd_height = SUBLCD_WIDTH;
#else /* HORIZONTAL_CAMERA */ 
    mmi_camco_osd_p->sublcd_osd_width = SUBLCD_WIDTH;
    mmi_camco_osd_p->sublcd_osd_height = SUBLCD_HEIGHT;
#endif /* HORIZONTAL_CAMERA */ 
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

    mmi_camco_osd_p->text_color = gui_color(255, 255, 255);
    mmi_camco_osd_p->text_border_color = gui_color(0, 0, 0);

    mmi_camco_osd_p->is_horizontal = MMI_FALSE;
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    mmi_camco_osd_p->is_blt = MMI_TRUE;
#endif 

    mmi_camco_osd_init_cam_direct_setting();
    mmi_camco_osd_init_rec_direct_setting();
    
    mmi_camco_osd_init_storage_sel_screen();

    mmi_camco_osd_init_advance_setting();
    mmi_camco_osd_init_confirm_screen();
    mmi_camco_osd_init_forward_screen();
    mmi_camco_osd_init_captured_screen();
#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
    mmi_camco_osd_init_captured_img_select_screen();
#endif 
    mmi_camco_osd_init_recording_screen();

    mmi_camco_osd_init_video_progress();

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    mmi_camco_osd_init_add_frame();
#endif 

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
    mmi_camco_osd_init_image_select();
#endif 

    mmi_camco_osd_init_focus();
    mmi_camco_osd_init_focus_hint();

    mmi_camco_osd_init_xenon_flash();

    mmi_camco_osd_init_facedetect();

#ifdef __SMILE_SHUTTER_SUPPORT__
    mmi_camco_osd_init_smiledetect();
#endif 

#ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
    mmi_camco_osd_init_panorama();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_is_init_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_camco_osd_set_init_mem(void* ptr)
{
    mmi_camco_osd_p->osd_layer_draw_buf_ori_p = (CHAR *)ptr;   		
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  osd_layer_buf_p     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_setup_environment(void *osd_layer_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* allocate resource */
    /* shall move to camcoder memory */
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    mmi_camco_osd_time_stamp_struct *time_stamp_p = &mmi_camco_osd_p->time_stamp;
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
    S32 blt_osd_width = 0;
    S32 blt_osd_height = 0;
    CHAR * align_osd_layer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(osd_layer_buf_p != NULL);
    mmi_camco_osd_p->osd_layer_buf_p = (CHAR *) osd_layer_buf_p;

#if defined(HORIZONTAL_CAMERA) && !defined(MMI_CAMCO_OSD_ROTATE_LCD_270_SELF)
    blt_osd_width = mmi_camco_osd_p->osd_width;
    blt_osd_height = mmi_camco_osd_p->osd_height;
#else /* defined(HORIZONTAL_CAMERA) && !defined(MMI_CAMCO_OSD_ROTATE_LCD_270_SELF) */ 
    blt_osd_width = LCD_WIDTH;
    blt_osd_height = LCD_HEIGHT;
#endif /* defined(HORIZONTAL_CAMERA) && !defined(MMI_CAMCO_OSD_ROTATE_LCD_270_SELF) */ 

#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    align_osd_layer_p = (CHAR *)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) + 1) <<5);
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        blt_osd_width,
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_toggle_double();
    gdi_layer_copy_double();
    gdi_layer_pop_and_restore_active();
#else

    align_osd_layer_p = (CHAR *)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) + 1) <<5);
    gdi_layer_create_using_outside_memory(
        0, 
        0, 
        blt_osd_width, 
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE / 2);
           
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#endif


#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    align_osd_layer_p = (CHAR *)(((((U32)mmi_camco_osd_p->osd_layer_draw_buf_ori_p) >>5) + 1) <<5);    
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {

        gdi_layer_create_using_outside_memory(
            0,
            0,
            mmi_camco_osd_p->osd_width, 
            mmi_camco_osd_p->osd_height, 
            &mmi_camco_osd_p->osd_layer_draw_h,
            (U8*) align_osd_layer_p,
            (UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT * MMI_CAMCO_OSD_BYTE_PER_PIXEL));    

        gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
        gdi_layer_get_buffer_ptr(&mmi_camco_osd_p->osd_layer_draw_buf_p);

        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    mmi_camco_osd_p->sublcd_osd_layer_buf_p = mmi_camco_osd_p->osd_layer_buf_p + MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE + 64;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
    
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        mmi_camco_osd_p->sublcd_osd_width,
        mmi_camco_osd_p->sublcd_osd_height,
        &mmi_camco_osd_p->sublcd_osd_layer_h,
        (U8*) mmi_camco_osd_p->sublcd_osd_layer_buf_p,
        MMI_CAMCO_SUBLCD_OSD_LAYER_DB_BUF_SIZE);

    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
        
#else
    
    gdi_layer_create_using_outside_memory(
        0, 
        0, 
        mmi_camco_osd_p->sublcd_osd_width, 
        mmi_camco_osd_p->sublcd_osd_height, 
        &mmi_camco_osd_p->sublcd_osd_layer_h, 
        (U8*)mmi_camco_osd_p->sublcd_osd_layer_buf_p, 
        MMI_CAMCO_SUBLCD_OSD_LAYER_DB_BUF_SIZE / 2);
    
    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();    
    
#endif

#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    add_frame_p->overlay_frame_layer_buf_p = mmi_frm_scrmem_alloc_framebuffer(CAMCO_OVERLAY_FRAME_BUFFER_SIZE);
    ASSERT(add_frame_p->overlay_frame_layer_buf_p != NULL);

    /*
     * avoid hw issue :It is a hardware issue. 
     * * When the overlay frame buffer address is 16bytes alignment and the enlarge times is 2.
     * * It will cause the result. Please Vincent help to avoid such case. 
     */
    if ((((kal_uint32) add_frame_p->overlay_frame_layer_buf_p) & 0x0f) == 0)
    {
        add_frame_p->overlay_frame_layer_buf_p += 4;
        add_frame_p->is_buf_p_shift = MMI_TRUE;
    }
    else
    {
        add_frame_p->is_buf_p_shift = MMI_FALSE;
    }
    /* end of avoid hw issue */
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_8,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &add_frame_p->overlay_frame_layer_h,
        (PU8) add_frame_p->overlay_frame_layer_buf_p,
        (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE) - 4);

    gdi_layer_push_and_set_active(add_frame_p->overlay_frame_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    time_stamp_p->overlay_frame_layer_buf_p = add_frame_p->overlay_frame_layer_buf_p;
    time_stamp_p->overlay_frame_layer_h = add_frame_p->overlay_frame_layer_h;

    if (MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH != MMI_CAMCO_ADD_FRAME_COLOR_IDX_WIDTH ||
        mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_SUB)
    {
        add_frame_p->overlay_frame_layer_cap_buf_p =
            add_frame_p->overlay_frame_layer_buf_p + MMI_CAMCO_ADD_FRAME_BUFFER_SIZE;
        if ((((kal_uint32) add_frame_p->overlay_frame_layer_cap_buf_p) & 0x0f) == 0)
        {
            add_frame_p->overlay_frame_layer_cap_buf_p += 4;
        }
        gdi_layer_create_cf_using_outside_memory(
            GDI_COLOR_FORMAT_8,
            0,
            0,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH,
            MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_HEIGHT,
            &add_frame_p->overlay_frame_cap_layer_h,
            (PU8) add_frame_p->overlay_frame_layer_cap_buf_p,
            (S32) (MMI_CAMCO_OVERLAY_COLOR_IDX_BUFFER_SIZE - MMI_CAMCO_ADD_FRAME_BUFFER_SIZE) - 4);

        gdi_layer_push_and_set_active(add_frame_p->overlay_frame_cap_layer_h);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

#if defined(__MMI_TOUCH_SCREEN__)
    /* register pen event */
    wgui_register_pen_down_handler(mmi_camco_osd_touch_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_camco_osd_touch_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_camco_osd_touch_pen_move_hdlr);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ /* __MMI_TOUCH_SCREEN_ */

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    mmi_camco_osd_p->video_recoding_osd.is_init = MMI_FALSE;
#endif 
    mmi_camco_osd_p->panorama.is_init = MMI_FALSE;

    gui_set_font(&MMI_medium_font);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    mmi_camco_osd_add_frame_struct *add_frame_p = &mmi_camco_osd_p->add_frame;
    mmi_camco_osd_time_stamp_struct *time_stamp_p = &mmi_camco_osd_p->time_stamp;
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free resource */
    MMI_ASSERT(mmi_camco_osd_p->osd_layer_h != GDI_NULL_HANDLE);

    gdi_layer_free(mmi_camco_osd_p->osd_layer_h);
    mmi_camco_osd_p->osd_layer_h = GDI_NULL_HANDLE;

    mmi_camco_osd_p->osd_layer_buf_p = NULL;

#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
    if (mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
    {
        gdi_layer_free(mmi_camco_osd_p->osd_layer_draw_h);
        mmi_camco_osd_p->osd_layer_draw_h = GDI_NULL_HANDLE;
    }
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
    gdi_layer_free(mmi_camco_osd_p->sublcd_osd_layer_h);
    mmi_camco_osd_p->sublcd_osd_layer_h = GDI_NULL_HANDLE;
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    if (add_frame_p->overlay_frame_layer_buf_p != NULL)
    {
        if (add_frame_p->is_buf_p_shift)
        {
            add_frame_p->overlay_frame_layer_buf_p -= 4;
        }
        mmi_frm_scrmem_free((void*)add_frame_p->overlay_frame_layer_buf_p);
        add_frame_p->overlay_frame_layer_buf_p = NULL;
        time_stamp_p->overlay_frame_layer_buf_p = NULL;
    }

    gdi_layer_free(add_frame_p->overlay_frame_layer_h);
    add_frame_p->overlay_frame_layer_h = GDI_NULL_HANDLE;
    time_stamp_p->overlay_frame_layer_h = add_frame_p->overlay_frame_layer_h;

    if (MMI_CAMCO_ADD_FRAME_COLOR_IDX_CAPTURE_WIDTH != MMI_CAMCO_ADD_FRAME_COLOR_IDX_WIDTH ||
        mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_SUB)
    {
        gdi_layer_free(add_frame_p->overlay_frame_cap_layer_h);
        add_frame_p->overlay_frame_cap_layer_h = GDI_NULL_HANDLE;
    }
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 



}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_recording_setup_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MMI_CAMCO_OSD_ROTATE_LCD_270_SELF
static void mmi_camco_osd_recording_setup_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_rect_struct *ev_zoom_area_p = &mmi_camco_osd_p->video_recoding_osd.ev_zoom_area;
    gdi_rect_struct *rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rec_time_area;
    gdi_rect_struct *softkey_area_p = &mmi_camco_osd_p->video_recoding_osd.softkey_area;
    gdi_rect_struct *rotate_ev_zoom_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_ev_zoom_area;
    gdi_rect_struct *rotate_rec_time_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_rec_time_area;
    gdi_rect_struct *rotate_softkey_area_p = &mmi_camco_osd_p->video_recoding_osd.rotate_softkey_area;
    mmi_camco_osd_video_progress_struct *progress_p = &mmi_camco_osd_p->video_progress;
    mmi_camco_osd_vdo_recording_osd_struct *video_recoding_osd_p = &mmi_camco_osd_p->video_recoding_osd;
    S32 osd_width = 0;
    S32 osd_height = 0;
    PU8 active_ptr = NULL;
    CHAR * align_osd_layer_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_REDUCE_AREA_EXTEND (4)
    if (video_recoding_osd_p->is_init)
    {
        return;
    }
    /*
     * Because one of the double buffer is updated by driver. Therefore, we need using another
     * to divide to three layer. Otherwise, the preview image will have noise during the period 
     * of dividing OSD layer. Because at the same time, driver keep updating.
     */
    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    #ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__   
    gdi_layer_toggle_double();
    #endif
    gdi_layer_lock_frame_buffer();

    mmi_camco_osd_clear_bg();
    gdi_layer_get_buffer_ptr(&active_ptr);

    gdi_layer_unlock_frame_buffer();
    gdi_layer_pop_and_restore_active();

    gdi_layer_free(mmi_camco_osd_p->osd_layer_h);

    rotate_ev_zoom_area_p->x1 = 0;
    rotate_ev_zoom_area_p->y1 = 0;
    rotate_ev_zoom_area_p->x2 = MMI_CAMCO_OSD_RECORDING_EV_ZOOM_AREA_WIDTH - 1;
    rotate_ev_zoom_area_p->y2 = MMI_CAMCO_OSD_RECORDING_EV_ZOOM_AREA_HEIGHT - 1;

    ev_zoom_area_p->x1 = LCD_WIDTH - rotate_ev_zoom_area_p->y2 - 1;
    ev_zoom_area_p->y1 = rotate_ev_zoom_area_p->x1;
    ev_zoom_area_p->x2 = LCD_WIDTH - rotate_ev_zoom_area_p->y1 - 1;
    ev_zoom_area_p->y2 = rotate_ev_zoom_area_p->x2;

    rotate_rec_time_area_p->x1 = rotate_ev_zoom_area_p->x2 + 3;
    rotate_rec_time_area_p->y1 = progress_p->time_offset_y - MMI_CAMCO_OSD_REDUCE_AREA_EXTEND;
    rotate_rec_time_area_p->x2 = rotate_rec_time_area_p->x1 + MMI_CAMCO_OSD_RECORDING_REC_TIME_AREA_WIDTH - 1;
    rotate_rec_time_area_p->y2 = rotate_rec_time_area_p->y1 + MMI_CAMCO_OSD_RECORDING_REC_TIME_AREA_HEIGHT - 1;

    rec_time_area_p->x1 = LCD_WIDTH - rotate_rec_time_area_p->y2 - 1;
    rec_time_area_p->y1 = rotate_rec_time_area_p->x1;
    rec_time_area_p->x2 = LCD_WIDTH - rotate_rec_time_area_p->y1 - 1;
    rec_time_area_p->y2 = rotate_rec_time_area_p->x2;

    rotate_softkey_area_p->x1 = LCD_HEIGHT - MMI_CAMCO_OSD_RECORDING_SWKEY_AREA_WIDTH;
    rotate_softkey_area_p->y1 = 0;
    rotate_softkey_area_p->x2 = LCD_HEIGHT - 1;
    rotate_softkey_area_p->y2 = LCD_WIDTH - 1;

    softkey_area_p->x1 = LCD_WIDTH - rotate_softkey_area_p->y2 - 1;
    softkey_area_p->y1 = rotate_softkey_area_p->x1;
    softkey_area_p->x2 = LCD_WIDTH - rotate_softkey_area_p->y1 - 1;
    softkey_area_p->y2 = rotate_softkey_area_p->x2;

    video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p = (CHAR *) active_ptr;

    video_recoding_osd_p->osd_layer_rec_time_area_buf_p =
        video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p + MMI_CAMCO_OSD_LAYER_EV_ZOOM_AREA_DB_BUF_SIZE + 64;

    video_recoding_osd_p->osd_layer_softkey_area_buf_p =
        video_recoding_osd_p->osd_layer_rec_time_area_buf_p + MMI_CAMCO_OSD_LAYER_REC_TIME_AREA_DB_BUF_SIZE + 64;

    osd_width = ev_zoom_area_p->x2 - ev_zoom_area_p->x1 + 1;
    osd_height = ev_zoom_area_p->y2 - ev_zoom_area_p->y1 + 1;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__    
    align_osd_layer_p = (CHAR *)(((((U32)video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_double_using_outside_memory(
        ev_zoom_area_p->x1,
        ev_zoom_area_p->y1,
        osd_width,
        osd_height,
        &video_recoding_osd_p->osd_layer_ev_zoom_area_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_EV_ZOOM_AREA_DB_BUF_SIZE);

#else
    align_osd_layer_p = (CHAR *)(((((U32)video_recoding_osd_p->osd_layer_ev_zoom_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_using_outside_memory(
        ev_zoom_area_p->x1, 
        ev_zoom_area_p->y1, 
        osd_width, 
        osd_height,
        &video_recoding_osd_p->osd_layer_ev_zoom_area_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_EV_ZOOM_AREA_DB_BUF_SIZE);

#endif

    gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_ev_zoom_area_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    osd_width = rec_time_area_p->x2 - rec_time_area_p->x1 + 1;
    osd_height = rec_time_area_p->y2 - rec_time_area_p->y1 + 1;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__    

    align_osd_layer_p = (CHAR *)(((((U32)video_recoding_osd_p->osd_layer_rec_time_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_double_using_outside_memory(
        rec_time_area_p->x1,
        rec_time_area_p->y1,
        osd_width,
        osd_height,
        &video_recoding_osd_p->osd_layer_rec_time_area_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_REC_TIME_AREA_DB_BUF_SIZE);
  
#else
    align_osd_layer_p = (CHAR *)(((((U32)video_recoding_osd_p->osd_layer_rec_time_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_using_outside_memory(
        rec_time_area_p->x1, 
        rec_time_area_p->y1, 
        osd_width, 
        osd_height,
        &video_recoding_osd_p->osd_layer_rec_time_area_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_REC_TIME_AREA_DB_BUF_SIZE);   
#endif

    gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_rec_time_area_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    osd_width = softkey_area_p->x2 - softkey_area_p->x1 + 1;
    osd_height = softkey_area_p->y2 - softkey_area_p->y1 + 1;
#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__      
    align_osd_layer_p = (CHAR *)(((((U32)video_recoding_osd_p->osd_layer_softkey_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_double_using_outside_memory(
        softkey_area_p->x1,
        softkey_area_p->y1,
        osd_width,
        osd_height,
        &video_recoding_osd_p->osd_layer_softkey_area_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_SWKEY_AREA_AREA_DB_BUF_SIZE);     
#else
    align_osd_layer_p = (CHAR *)(((((U32)video_recoding_osd_p->osd_layer_softkey_area_buf_p) >>5) +1) <<5);

    gdi_layer_create_using_outside_memory(
        softkey_area_p->x1, 
        softkey_area_p->y1, 
        osd_width, 
        osd_height,
        &video_recoding_osd_p->osd_layer_softkey_area_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_SWKEY_AREA_AREA_DB_BUF_SIZE);     
#endif

    gdi_layer_push_and_set_active(video_recoding_osd_p->osd_layer_softkey_area_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    video_recoding_osd_p->is_init = MMI_TRUE;

    /*
     * Because entering OSD recoding state, OSD has to be reduced from FULL LCD to three small OSD
     * for improving performance. However, before set blt layer osd content need to be drawed
     * in advance. Otherwise, the part of the preview layer overlaying the three layer will
     * became empty suddenly. Because at that time, three layer all are transparent.
     */
    mmi_camco_osd_p->is_blt = MMI_FALSE;
    mmi_camco_osd_draw_osd();
    mmi_camco_osd_p->is_blt = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_recording_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_recording_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_vdo_recording_osd_struct *video_recoding_osd_p = &mmi_camco_osd_p->video_recoding_osd;
    S32 blt_osd_width = 0;
    S32 blt_osd_height = 0;
    CHAR * align_osd_layer_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!video_recoding_osd_p->is_init)
    {
        return;
    }
    else if (video_recoding_osd_p->is_init &&
             (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_RECORDING ||
              mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_PAUSE))
    {
        return;
    }

    gdi_layer_free(video_recoding_osd_p->osd_layer_ev_zoom_area_h);
    gdi_layer_free(video_recoding_osd_p->osd_layer_rec_time_area_h);
    gdi_layer_free(video_recoding_osd_p->osd_layer_softkey_area_h);

    blt_osd_width = LCD_WIDTH;
    blt_osd_height = LCD_HEIGHT;

#ifndef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__       
    align_osd_layer_p = (CHAR *)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) +1) <<5);
    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        blt_osd_width,
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h,
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE);
#else
    align_osd_layer_p = (CHAR *)(((((U32)mmi_camco_osd_p->osd_layer_buf_p) >>5) +1) <<5);
    gdi_layer_create_using_outside_memory(
        0, 
        0, 
        blt_osd_width, 
        blt_osd_height,
        &mmi_camco_osd_p->osd_layer_h, 
        (U8*) align_osd_layer_p,
        MMI_CAMCO_OSD_LAYER_DB_BUF_SIZE/2);
#endif

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_h);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(mmi_camco_osd_p->osd_layer_draw_h);
    gdi_layer_resize(mmi_camco_osd_p->osd_width, mmi_camco_osd_p->osd_height);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    video_recoding_osd_p->is_init = MMI_FALSE;
}
#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_sublcd_stop_hint_set_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_sublcd_stop_hint_set_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate lcd */
#ifdef HORIZONTAL_CAMERA
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_lcd_set_rotate_by_layer(TRUE);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* HORIZONTAL_CAMERA */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_sublcd_stop_hint_reset_environment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_sublcd_stop_hint_reset_environment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate lcd */
#ifdef HORIZONTAL_CAMERA
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_osd_layer_h);
    gdi_lcd_set_rotate_by_layer(FALSE);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    gdi_layer_pop_and_restore_active();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* HORIZONTAL_CAMERA */ 
}
#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
#endif /* MMI_CAMCO_OSD_ROTATE_LCD_270_SELF */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_hint_set_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_hint_set_mode(mmi_cameco_osd_stop_hint_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate lcd */
    mmi_camco_osd_p->stop_hint_mode = mode;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_menulist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_menulist_move_prev())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_prev();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            /* option menu sensitivity should be lower */
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }
        gui_start_timer(duration, mmi_camco_osd_menulist_prev_cyclic);
    }
    else
    {
        mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

        menulist_p->highlighted_idx = menulist_p->item_count - 1;
        menulist_p->first_disp_idx = menulist_p->highlighted_idx - (menulist_p->disp_item_count - 1);

        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_prev();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU)
        {
            mmi_camco_set_option_menulist_highlight_idx(menulist_p->highlighted_idx);

            /* option menu sensitivity should be lower */
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_menulist_prev_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
    {
        mmi_camco_reset_preview_terminate_timer();
    }
#endif /* __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_menulist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_menulist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_menulist_move_next())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_next();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_menulist_next_cyclic);
    }
    else
    {
        mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

        menulist_p->highlighted_idx = 0;
        menulist_p->first_disp_idx = 0;

        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            mmi_camco_setting_itemlist_move_next();
            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU)
        {
            mmi_camco_set_option_menulist_highlight_idx(menulist_p->highlighted_idx);

            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_menulist_next_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
        mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
    {
        mmi_camco_reset_preview_terminate_timer();
    }
#endif /* __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_iconlist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_iconlist_move_prev())
    {
        mmi_camco_setting_mainlist_move_prev();
    }
    else
    {
        mmi_camco_setting_set_mainlist_idx(iconlist_p->icon_count - 1);
        mmi_camco_osd_gen_iconlist();
    }

    mmi_camco_osd_gen_setting_menulist();
    mmi_camco_osd_draw_osd();

    mmi_camco_setting_restore_hilite_mod();
    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_iconlist_prev_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_iconlist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_iconlist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_iconlist_move_next())
    {
        mmi_camco_setting_mainlist_move_next();
    }
    else
    {
        mmi_camco_setting_set_mainlist_idx(0);
        mmi_camco_osd_gen_iconlist();
    }

    mmi_camco_osd_gen_setting_menulist();
    mmi_camco_osd_draw_osd();

    mmi_camco_setting_restore_hilite_mod();
    gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

    gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_iconlist_next_cyclic);

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_captured_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_multishot        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_captured_mode(MMI_BOOL is_multishot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->is_multishot = is_multishot;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_get_captured_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_get_captured_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_camco_osd_p->is_multishot;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_rec_time_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  updated     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_rec_time_update(MMI_BOOL updated)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_camco_osd_p->is_updare_rec_time < 10)
        mmi_camco_osd_p->is_updare_rec_time += 4;  /* = updated; */
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_iconlist_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_touch_iconlist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (iconlist_p->highlighted_idx < iconlist_p->icon_count - 1)
    {

        if (iconlist_p->highlighted_idx == iconlist_p->icon_count - 2)
        {
            iconlist_p->highlighted_idx++;
            if (iconlist_p->first_disp_idx == iconlist_p->icon_count - iconlist_p->disp_icon_count - 1)
                iconlist_p->first_disp_idx++;
            return MMI_TRUE;
        }
        if (iconlist_p->highlighted_idx == iconlist_p->first_disp_idx + iconlist_p->disp_icon_count - 1)
        {
            iconlist_p->first_disp_idx++;
            return MMI_TRUE;
        }
        else if (iconlist_p->highlighted_idx == iconlist_p->first_disp_idx + iconlist_p->disp_icon_count - 2)
        {
            iconlist_p->highlighted_idx++;
            iconlist_p->first_disp_idx++;
            return MMI_TRUE;
        }
        else
        {
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_iconlist_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_touch_iconlist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iconlist_p->highlighted_idx > 0)
    {

        if (iconlist_p->highlighted_idx == 1)
        {
            iconlist_p->highlighted_idx--;
            if (iconlist_p->first_disp_idx == 1)
                iconlist_p->first_disp_idx--;
            return MMI_TRUE;
        }
        if (iconlist_p->highlighted_idx == iconlist_p->first_disp_idx)
        {
            iconlist_p->first_disp_idx--;
            return MMI_TRUE;
        }
        else if (iconlist_p->highlighted_idx == iconlist_p->first_disp_idx + 1)
        {
            iconlist_p->highlighted_idx--;
            iconlist_p->first_disp_idx--;
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_menulist_move_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_touch_menulist_move_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->highlighted_idx < menulist_p->item_count - 1)
    {

        if (menulist_p->highlighted_idx == menulist_p->item_count - 2)
        {
            menulist_p->highlighted_idx++;
            if (menulist_p->first_disp_idx == menulist_p->item_count - menulist_p->disp_item_count - 1)
                menulist_p->first_disp_idx++;
            return MMI_TRUE;
        }
        if (menulist_p->highlighted_idx == menulist_p->first_disp_idx + menulist_p->disp_item_count - 1)
        {
            menulist_p->first_disp_idx++;
            return MMI_TRUE;
        }
        else if (menulist_p->highlighted_idx == menulist_p->first_disp_idx + menulist_p->disp_item_count - 2)
        {
            menulist_p->highlighted_idx++;
            menulist_p->first_disp_idx++;
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_menulist_move_prev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_camco_osd_touch_menulist_move_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menulist_p->highlighted_idx > 0)
    {

        if (menulist_p->highlighted_idx == 1)
        {
            menulist_p->highlighted_idx--;
            if (menulist_p->first_disp_idx == 1)
                menulist_p->first_disp_idx--;
            return MMI_TRUE;
        }
        if (menulist_p->highlighted_idx == menulist_p->first_disp_idx)
        {
            menulist_p->first_disp_idx--;
            return MMI_TRUE;
        }
        else if (menulist_p->highlighted_idx == menulist_p->first_disp_idx + 1)
        {
            menulist_p->highlighted_idx--;
            menulist_p->first_disp_idx--;
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_menulist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_menulist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
    S32 pre_hilite = mmi_camco_osd_p->act_menulist_p->highlighted_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_menulist_move_prev())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            if (pre_hilite != mmi_camco_osd_p->act_menulist_p->highlighted_idx)
            {
                mmi_camco_setting_itemlist_move_prev();
                gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);
            }
            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_touch_menulist_prev_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_menulist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_menulist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
    S32 pre_hilite = mmi_camco_osd_p->act_menulist_p->highlighted_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_menulist_move_next())
    {
        mmi_camco_osd_draw_osd();

        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
            mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
        {
            if (pre_hilite != mmi_camco_osd_p->act_menulist_p->highlighted_idx)
            {
                mmi_camco_setting_itemlist_move_next();
                gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);
            }
            duration = MMI_CAMCO_OSD_TOUCH_MENULIST_MOVE_DUR;
        }
        else
        {
            duration = MMI_CAMCO_OSD_TOUCH_OPTION_MENU_MOVE_DUR;
        }

        gui_start_timer(duration, mmi_camco_osd_touch_menulist_next_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_iconlist_prev_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_iconlist_prev_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_iconlist_move_prev())
    {
        mmi_camco_setting_mainlist_move_prev();
        mmi_camco_osd_gen_setting_menulist();
        mmi_camco_osd_draw_osd();

        mmi_camco_setting_restore_hilite_mod();
        gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_touch_iconlist_prev_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_iconlist_next_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_iconlist_next_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_iconlist_move_next())
    {
        mmi_camco_setting_mainlist_move_next();
        mmi_camco_osd_gen_setting_menulist();
        mmi_camco_osd_draw_osd();

        mmi_camco_setting_restore_hilite_mod();
        gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

        gui_start_timer(MMI_CAMCO_OSD_TOUCH_ICONLIST_MOVE_DUR, mmi_camco_osd_touch_iconlist_next_cyclic);
    }

#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    mmi_camco_reset_preview_terminate_timer();
#endif 
}


static void mmi_camco_contshot_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_camco_osd_p->is_capturing)
   {
        mmi_camco_osd_p->is_capturing = MMI_FALSE;
        SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);
    }     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_preview_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_camco_osd_touch_cam_preview_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->sensor_switcher) && !mmi_camco_osd_p->is_show_zoom)
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SENSOR_SWITCHER;
        mmi_camco_osd_p->sensor_switcher.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }    
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.scene_mode))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SCN;
        mmi_camco_osd_p->cam_direct_setting_screen.scene_mode.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.flash))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_FLASH;
        mmi_camco_osd_p->cam_direct_setting_screen.flash.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }    
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.zoom))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM;
        mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.capmode))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_CAPMODE;
        mmi_camco_osd_p->cam_direct_setting_screen.capmode.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.ad_setting))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_AD_SETTING;
        mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.back))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_PREVIEW_BACK;
        mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.imgviewer))
    {
        if (mmi_camco_setting_imageviewer_is_enable())
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_IMGVIEWER;
            mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }

    }
    else if(mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top))
    {
        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_press = MMI_TRUE;    
        mmi_camco_osd_draw_osd();              
        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_press = MMI_FALSE;            
        mmi_camco_osd_p->is_capturing = MMI_TRUE;
        SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);    
    }        
    else if(mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_REC_SWTICH;
        mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.is_press = MMI_TRUE;    
        mmi_camco_osd_draw_osd();            
    }         
    else if(mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.capture) && (!mmi_camco_setting_app_switch_is_enable() || mmi_camco_osd_is_in_smile_dect_scrn()))
    {
        mmi_camco_osd_p->cam_direct_setting_screen.capture.is_press = MMI_TRUE;    
        mmi_camco_osd_draw_osd();              
        mmi_camco_osd_p->cam_direct_setting_screen.capture.is_press = MMI_FALSE;            
        SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);    
    }    
    else if(mmi_camco_osd_p->is_show_zoom) 
    {
        mmi_camco_osd_touch_obj_struct *region =  &mmi_camco_osd_p->cam_direct_setting_screen.slider_region;

        if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.slider_location_region))
        {

            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER;
            mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_PRESS;
            if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
            {
                mmi_camco_cam_face_detect_stop();
            }
            mmi_camco_osd_p->cam_direct_setting_screen.slider_location.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_touch_slider_normalize(&y ,region->offset_y , region->offset_y + region->height, (mmi_camco_osd_p->cam_direct_setting_screen.slider_location.height))  &&
                   mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.slider_region))
        {
            double ratio = (((1.0) * (y - mmi_camco_osd_p->cam_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->cam_direct_setting_screen.slider_region.height);
            double rel_pos_y;                    
            U16 zoom_value;
            U16 curr_value = mmi_camco_setting_get_camzoom_step();

            if (mmi_camco_osd_is_horz_UI())
            {  
                ratio = (((1.0) * (y - mmi_camco_osd_p->cam_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->cam_direct_setting_screen.slider_region.height);
            }
            else
            {
                ratio = (((1.0) * (x - mmi_camco_osd_p->cam_direct_setting_screen.slider_region.offset_x)) / mmi_camco_osd_p->cam_direct_setting_screen.slider_region.width);
            }            
            
            if(ratio > 1)
                ratio = 1;

            if (mmi_camco_osd_is_horz_UI())
            {              
                rel_pos_y = (1 - ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);
            }
            else
            {
                rel_pos_y = (ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);            
            }
            zoom_value = mmi_camco_round(rel_pos_y);

            if (curr_value - zoom_value > 50 || zoom_value - curr_value > 50)
                return;
            
            if (zoom_value > mmi_camco_setting_get_camzoom_maxstep())
                zoom_value = mmi_camco_setting_get_camzoom_maxstep();
            
            if (zoom_value < mmi_camco_setting_get_camzoom_minstep())
                zoom_value = mmi_camco_setting_get_camzoom_minstep();
            
            mmi_camco_setting_set_camzoom_step(zoom_value);
            mdi_camera_update_para_zoom(zoom_value);
            
            mmi_camco_setting_set_camzoom_value(mmi_camco_update_zoom_factor());

            /* let user can move ind after touch some place to change zomm value */
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER;
            mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_PRESS;
            if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
            {
                mmi_camco_cam_face_detect_stop();
            }
            mmi_camco_osd_p->cam_direct_setting_screen.slider_location.is_press = MMI_TRUE;            
            mmi_camco_osd_draw_osd();

        }
        else if(!mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.zoom_region))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM_BACK;        
        }
    }        

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_rec_set_recording_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_camco_rec_set_recording_start(kal_bool start_recording)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->is_start_to_recording = start_recording;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_preview_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_camco_osd_touch_rec_preview_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_camco_osd_p->is_start_to_recording)
        return;

    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->sensor_switcher) && !mmi_camco_osd_p->is_show_zoom)
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SENSOR_SWITCHER;
        mmi_camco_osd_p->sensor_switcher.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }          
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.scene_mode))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_SCN;
        mmi_camco_osd_p->rec_direct_setting_screen.scene_mode.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.zoom))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM;
        mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.ad_setting))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_AD_SETTING;
        mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.back))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_PREVIEW_BACK;
        mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.allvideos))
    {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ALLVIDEOS;
            mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
    }
    else if(mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton))
    {
        mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_press = MMI_TRUE;    
        mmi_camco_osd_draw_osd();             
        mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_botton.is_press = MMI_FALSE;            
        SEND_EVT(MMI_CAMCO_EVT_RECORD, NULL);    
    }      
    else if(mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_CAM_SWTICH;
        mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top.is_press = MMI_TRUE;    
        mmi_camco_osd_draw_osd();               
    }   
    else if(mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.record) && !mmi_camco_setting_app_switch_is_enable())
    {
        mmi_camco_osd_p->rec_direct_setting_screen.record.is_press = MMI_TRUE;    
        mmi_camco_osd_draw_osd();              
        mmi_camco_osd_p->rec_direct_setting_screen.record.is_press = MMI_FALSE;            
        SEND_EVT(MMI_CAMCO_EVT_RECORD, NULL);    
    }        
    else if(mmi_camco_osd_p->is_show_zoom)
    {
        mmi_camco_osd_touch_obj_struct *region =  &mmi_camco_osd_p->rec_direct_setting_screen.slider_region;

        if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.slider_location_region))
        {

            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER;
            mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_PRESS;
            mmi_camco_osd_p->rec_direct_setting_screen.slider_location.is_press = MMI_TRUE;            
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_touch_slider_normalize(&y ,region->offset_y , region->offset_y + region->height, (mmi_camco_osd_p->rec_direct_setting_screen.slider_location.height))  &&
                   mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.slider_region))
        {
            double ratio = (((1.0) * (y - mmi_camco_osd_p->rec_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->rec_direct_setting_screen.slider_region.height);
            double rel_pos_y;                    
            U16 zoom_value;
            U16 curr_value = mmi_camco_setting_get_vdozoom_step();

            if (mmi_camco_osd_is_horz_UI())
            {  
                ratio = (((1.0) * (y - mmi_camco_osd_p->rec_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->rec_direct_setting_screen.slider_region.height);
            }
            else
            {
                ratio = (((1.0) * (x - mmi_camco_osd_p->rec_direct_setting_screen.slider_region.offset_x)) / mmi_camco_osd_p->rec_direct_setting_screen.slider_region.width);
            }  
            
            if(ratio > 1)
                ratio = 1;

            if (mmi_camco_osd_is_horz_UI())
            {             
                rel_pos_y = (1 - ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);
            }
            else
            {             
                rel_pos_y = (ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);
            }                
            zoom_value = mmi_camco_round(rel_pos_y);

            if (curr_value - zoom_value > 50 || zoom_value - curr_value > 50)
                return;
            
            if (zoom_value > mmi_camco_setting_get_vdozoom_maxstep())
                zoom_value = mmi_camco_setting_get_vdozoom_maxstep();
            
            if (zoom_value < mmi_camco_setting_get_vdozoom_minstep())
                zoom_value = mmi_camco_setting_get_vdozoom_minstep();
            
            mmi_camco_setting_set_vdozoom_step(zoom_value);
            mdi_video_rec_update_para_zoom(zoom_value);
            mmi_camco_setting_set_camzoom_value(mmi_camco_update_zoom_factor());

            /* let user can move ind after touch some place to change zomm value */
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER;
            mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_PRESS;
            mmi_camco_osd_p->rec_direct_setting_screen.slider_location.is_press = MMI_TRUE;              
            mmi_camco_osd_draw_osd();            

        }
        else if(!mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.zoom_region))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM_BACK;
        }        
    }        

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_translate_idx_to_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_camco_osd_touch_obj_enum mmi_camco_osd_touch_translate_idx_to_object(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING)
    {
        switch (idx)
        {
            case 0:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM1;
            case 1:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM2;
            case 2:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM3;
            case 3:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM4;
            case 4:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM5;
            case 5:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM6;
            case 6:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM7;
            case 7:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM8;
            case 8:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM9;
            case 9:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM10;
            case 10:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM11;
            case 11:
                return MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM12;
            default:
                ASSERT(0);                                
        }
    }
    else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
    {
        switch (idx)
        {
            case 0:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM1;
            case 1:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM2;
            case 2:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM3;
            case 3:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM4;
            case 4:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM5;
            case 5:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM6;
            case 6:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM7;
            case 7:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM8;
            case 8:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM9;
            case 9:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM10;
            case 10:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM11;
            case 11:
                return MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM12;       
            default:
                ASSERT(0);

        }

    }
    else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_OPTION_MENU)
    {
        switch (idx)
        {             
            case 0:
                return MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_BT;
            case 1:
                return MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_MMS;
            case 2:
                return MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_EMAIL;      
            default:
                ASSERT(0);
        }

    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_translate_object_to_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_camco_osd_touch_translate_object_to_idx(mmi_camco_osd_touch_obj_enum obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING)
    {

        switch (obj)
        {
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM1:
                return 0;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM2:
                return 1;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM3:
                return 2;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM4:
                return 3;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM5:
                return 4;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM6:
                return 5;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM7:
                return 6;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM8:
                return 7;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM9:
                return 8;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM10:
                return 9;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM11:
                return 10;
            case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM12:
                return 11;                

        }
    }
    else
    {
        switch (obj)
        {
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM1:
                return 0;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM2:
                return 1;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM3:
                return 2;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM4:
                return 3;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM5:
                return 4;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM6:
                return 5;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM7:
                return 6;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM8:
                return 7;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM9:
                return 8;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM10:
                return 9;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM11:
                return 10;
            case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM12:
                return 11;                

        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_translate_object_to_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_camco_osd_touch_translate_object_to_setting(mmi_camco_osd_touch_obj_enum obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (obj)
    {
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SCN:
            return MMI_CAMCO_SETTING_CAMSCENEMODE;
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_SCN:
            return MMI_CAMCO_SETTING_VDOSCENEMODE;
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_FLASH:
    #ifdef MMI_CAMCO_SUPPORT_FLASH
            return MMI_CAMCO_SETTING_FLASH;
    #else 
            return MMI_CAMCO_SETTING_SELFTIMER;
    #endif 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_advance_setting_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_advance_setting_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->advance_setting_screen.back))
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK;
            mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK;
            mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->advance_setting_screen.OK))
    {   
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_OK;
            mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_OK;
            mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }

    }
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
    {
        S16 idx;

        idx = mmi_camco_osd_get_menulist_idx_from_pos(x, y);

        if (idx >= 0 && idx < mmi_camco_osd_p->setting_menulist.disp_item_count)
        {
            mmi_camco_osd_p->previous_pos_y = y;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2;

            if ((idx + mmi_camco_osd_p->setting_menulist.first_disp_idx) !=
                mmi_camco_osd_p->setting_menulist.highlighted_idx)
            {
                mmi_camco_osd_p->setting_menulist.highlighted_idx =
                    idx + mmi_camco_osd_p->setting_menulist.first_disp_idx;
                mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->setting_menulist.highlighted_idx);
                mmi_camco_setting_item_hilite_hdlr();
            }

            mmi_camco_osd_draw_osd();            
            mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;            
        }
        else
        {
            if (mmi_camco_osd_touch_hit_test
                (x, y, &mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_ind_region))
            {
                U8 scrolling_unit =
                    (mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[1] -
                     mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[0]) /
                    mmi_camco_osd_p->setting_menulist.item_count;
                U32 new_idx =
                    (y - mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[0]) / scrolling_unit;
                mmi_camco_osd_p->scroll_previous_pos_y = y;
                mmi_camco_osd_p->scroll_pen_down_diff_idx = mmi_camco_osd_p->setting_menulist.first_disp_idx - new_idx;                
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL;
                mmi_camco_osd_draw_osd();
            }
        }

    }
    else if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.main_tab))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_MAIN_TAB;
    #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
        mmi_camco_reset_preview_terminate_timer();
    #endif         
    }
    else if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.misc_tab))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_MISC_TAB;
    #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
        mmi_camco_reset_preview_terminate_timer();
    #endif         
    }
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
    {
        S16 idx;

        idx = mmi_camco_osd_get_iconlist_idx_from_pos(x, y);
        if (idx >= 0)
        {
            mmi_camco_osd_p->previous_pos_y = y;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1;

            if ((idx + mmi_camco_osd_p->iconlist.first_disp_idx) != mmi_camco_osd_p->iconlist.highlighted_idx)
            {
                mmi_camco_osd_p->iconlist.highlighted_idx = idx + mmi_camco_osd_p->iconlist.first_disp_idx;
                mmi_camco_setting_set_mainlist_idx(idx + mmi_camco_osd_p->iconlist.first_disp_idx);

            }
                
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->iconlist.highlight_change_flag = MMI_FALSE;
            mmi_camco_osd_p->last_l1_menu_hilite_str_id =
                mmi_camco_osd_p->iconlist.icon_list[idx + mmi_camco_osd_p->iconlist.first_disp_idx].str_id;

        }
        else
        {
            if (mmi_camco_osd_touch_hit_test
                (x, y, &mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_ind_region))
            {
                U8 scrolling_unit =
                    (mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[1] -
                     mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[0]) /
                    mmi_camco_osd_p->iconlist.icon_count;
                U32 new_idx =
                    (y - mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[0]) / scrolling_unit;
                mmi_camco_osd_p->scroll_previous_pos_y = y;
                mmi_camco_osd_p->scroll_pen_down_diff_idx = mmi_camco_osd_p->iconlist.first_disp_idx - new_idx;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL;
                mmi_camco_osd_draw_osd();
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_direct_setting_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_direct_setting_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.setting_wnd_body) )
    {
        /* touch out of popup window mean back */        
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_BACK;
        mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if ((mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SCN) ||
               (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_FLASH) ||
               (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_CAPMODE)               
             )
    {
        U8 i;

        for (i = 0; i < mmi_camco_osd_p->active_tbl->real_number; i++)
        {
            if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->active_setting_item[i]))
            {
                mmi_camco_osd_p->touch_obj = mmi_camco_osd_touch_translate_idx_to_object(i);
                mmi_camco_osd_p->setting_menulist.highlighted_idx = i;
                mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;
                break;
            }
        }
        if (i != mmi_camco_osd_p->setting_menulist.item_count)
            mmi_camco_osd_draw_osd();

    }  

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_setting_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_setting_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->is_direct_setting == KAL_TRUE)
    {
        mmi_camco_osd_touch_cam_direct_setting_pen_down_hdlr(x, y);
    }
    else
    {
        mmi_camco_osd_touch_cam_advance_setting_pen_down_hdlr(x, y);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_advance_setting_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_advance_setting_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->advance_setting_screen.back))
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK;
            mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK;
            mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }

    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->advance_setting_screen.OK))
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_OK;
            mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_OK;
            mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_TRUE;
            gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
            mmi_camco_osd_draw_osd();
        }

    }
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
    {
        S16 idx;

        idx = mmi_camco_osd_get_menulist_idx_from_pos(x, y);

        if (idx >= 0 && idx < mmi_camco_osd_p->setting_menulist.disp_item_count)
        {
            mmi_camco_osd_p->previous_pos_y = y;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2;

            if ((idx + mmi_camco_osd_p->setting_menulist.first_disp_idx) !=
                mmi_camco_osd_p->setting_menulist.highlighted_idx)
            {
                mmi_camco_osd_p->setting_menulist.highlighted_idx =
                    idx + mmi_camco_osd_p->setting_menulist.first_disp_idx;
                mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->setting_menulist.highlighted_idx);
                mmi_camco_setting_item_hilite_hdlr();
            }

            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;            
        }
        else
        {
            if (mmi_camco_osd_touch_hit_test
                (x, y, &mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_ind_region))
            {
                U8 scrolling_unit =
                    (mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[1] -
                     mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[0]) /
                    mmi_camco_osd_p->setting_menulist.item_count;
                U32 new_idx =
                    (y - mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[0]) / scrolling_unit;
                mmi_camco_osd_p->scroll_previous_pos_y = y;
                mmi_camco_osd_p->scroll_pen_down_diff_idx = mmi_camco_osd_p->setting_menulist.first_disp_idx - new_idx;                
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL;
                mmi_camco_osd_draw_osd();
            }
        }

    }
    else if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.main_tab))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_MAIN_TAB;
    #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
        mmi_camco_reset_preview_terminate_timer();
    #endif         
    }
    else if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.misc_tab))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_MISC_TAB;
    #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
        mmi_camco_reset_preview_terminate_timer();
    #endif         
    }
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
    {
        S16 idx;

        idx = mmi_camco_osd_get_iconlist_idx_from_pos(x, y);
        if (idx >= 0)
        {
            mmi_camco_osd_p->previous_pos_y = y;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1;

            if ((idx + mmi_camco_osd_p->iconlist.first_disp_idx) != mmi_camco_osd_p->iconlist.highlighted_idx)
            {
                mmi_camco_osd_p->iconlist.highlighted_idx = idx + mmi_camco_osd_p->iconlist.first_disp_idx;
                mmi_camco_setting_set_mainlist_idx(idx + mmi_camco_osd_p->iconlist.first_disp_idx);
            }

            mmi_camco_osd_draw_osd();            
            mmi_camco_osd_p->iconlist.highlight_change_flag = MMI_FALSE;
            mmi_camco_osd_p->last_l1_menu_hilite_str_id =
                mmi_camco_osd_p->iconlist.icon_list[idx + mmi_camco_osd_p->iconlist.first_disp_idx].str_id;

        }
        else
        {
            if (mmi_camco_osd_touch_hit_test
                (x, y, &mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_ind_region))
            {
                U8 scrolling_unit =
                    (mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[1] -
                     mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[0]) /
                    mmi_camco_osd_p->iconlist.icon_count;
                U32 new_idx =
                    (y - mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[0]) / scrolling_unit;
                mmi_camco_osd_p->scroll_previous_pos_y = y;
                mmi_camco_osd_p->scroll_pen_down_diff_idx = mmi_camco_osd_p->iconlist.first_disp_idx - new_idx;            
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL;
                mmi_camco_osd_draw_osd();
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_direct_setting_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_direct_setting_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.setting_wnd_body))
    {
        /* touch out of popup window mean back */
        
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_BACK;
        mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_p->current_dir_setting_object == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_SCN)
    {
        U8 i;

        for (i = 0; i < mmi_camco_osd_p->active_tbl->real_number; i++)
        {
            if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->active_setting_item[i]))
            {
                mmi_camco_osd_p->touch_obj = mmi_camco_osd_touch_translate_idx_to_object(i);
                mmi_camco_osd_p->setting_menulist.highlighted_idx = i;
                mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;
                break;
            }
        }
        if (i != mmi_camco_osd_p->setting_menulist.item_count)
            mmi_camco_osd_draw_osd();

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_setting_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_setting_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->is_direct_setting == KAL_TRUE)
    {
        mmi_camco_osd_touch_rec_direct_setting_pen_down_hdlr(x, y);
    }
    else
    {
        mmi_camco_osd_touch_rec_advance_setting_pen_down_hdlr(x, y);
    }

}

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_img_select_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_img_select_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->captured_img_select_screen.back))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMG_SELECT_BACK;
        mmi_camco_osd_p->captured_img_select_screen.back.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else
    {
        for (idx = 0; idx < mmi_camco_osd_p->captured_img_select_screen.img_list_count; idx++)
        {
            if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->captured_img_select_screen.image_list_touch[idx + mmi_camco_osd_p->captured_img_select_screen.img_select_pos_shift]))
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMG_SELECT_IMG;
                mmi_camco_osd_p->imgselect_cache.highlighted_idx = idx;

                if(!mmi_camco_osd_p->imgselect_cache.save_flag_p[idx])
                {
                    mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
                    mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
                    mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
                    mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_TRUE;                    
                }
                else
                {
                    mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_usable = MMI_FALSE;
                    mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_usable = MMI_FALSE;
                    mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_usable = MMI_FALSE;
                    mmi_camco_osd_p->captured_img_select_screen.save.is_usable= MMI_FALSE;
                    SEND_EVT(MMI_CAMCO_EVT_OK, NULL);                
                }
                mmi_camco_updata_key_handler();
                mmi_camco_osd_draw_osd();                                        
                return;
            }
        }
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_img_select_screen.tool_bar[0]))
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_press = MMI_TRUE;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_AP;
            mmi_camco_osd_draw_osd();

        }
        else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_img_select_screen.tool_bar[1]))
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_press = MMI_TRUE;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_DELETE;
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_img_select_screen.save))
        {
            mmi_camco_osd_p->captured_img_select_screen.save.is_press = MMI_TRUE;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_SAVE;
            mmi_camco_osd_draw_osd();
        }        

        else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_img_select_screen.tool_bar[2]))
        {
            mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_press = MMI_TRUE;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_FORWARD;
            mmi_camco_osd_draw_osd();
        }
        mmi_camco_osd_draw_osd();

    }
}
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_option_menu_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_option_menu_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->forward_screen.item[0]))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_BT;
        mmi_camco_osd_set_fw_hilite_idx(mmi_camco_osd_p->fw_option_idx_lookup_table[0]);
        mmi_camco_osd_p->forward_screen.highlite_change_flag = MMI_FALSE;
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->forward_screen.item[1]))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_MMS;
        mmi_camco_osd_set_fw_hilite_idx(mmi_camco_osd_p->fw_option_idx_lookup_table[1]);
        mmi_camco_osd_p->forward_screen.highlite_change_flag = MMI_FALSE;        
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->forward_screen.item[2]))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_EMAIL;
        mmi_camco_osd_set_fw_hilite_idx(mmi_camco_osd_p->fw_option_idx_lookup_table[2]);
        mmi_camco_osd_p->forward_screen.highlite_change_flag = MMI_FALSE;        
    }
    else if (!mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->forward_screen.confirm_body))
    {
        mmi_camco_osd_p->forward_screen.back.is_press = MMI_TRUE;
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_BACK;
    }
    mmi_camco_osd_draw_osd();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_hint_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_hint_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_screen.back))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAPTURED_BACK;
            mmi_camco_osd_p->captured_screen.back.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_screen.tool_bar[0]))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_AP;
            mmi_camco_osd_p->captured_screen.tool_bar[0].is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_screen.tool_bar[1]))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_DELETE;
            mmi_camco_osd_p->captured_screen.tool_bar[1].is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_screen.tool_bar[2]))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_FORWARD;
            mmi_camco_osd_p->captured_screen.tool_bar[2].is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
    }
    else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR ||
               mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->confirm_screen.confirm_lsk))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CONFIRM_YES;
            mmi_camco_osd_p->confirm_screen.confirm_lsk.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
        else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->confirm_screen.confirm_rsk))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_CONFIRM_NO;
            mmi_camco_osd_p->confirm_screen.confirm_rsk.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();

        }
    }
    else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->captured_screen.back))
        {
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_HINT_BACK;
            mmi_camco_osd_p->captured_screen.back.is_press = MMI_TRUE;
            mmi_camco_osd_draw_osd();
        }
    }
}

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_add_frame_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_add_frame_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->add_frame.la_touch))
    {
        gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);

        mmi_camco_osd_p->add_frame.la_touch.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ADD_FRAME_LA;

        mmi_camco_osd_add_frame_prev_cyclic();
    }
    else if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->add_frame.ra_touch))
    {
        gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);

        mmi_camco_osd_p->add_frame.ra_touch.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_ADD_FRAME_RA;

        mmi_camco_osd_add_frame_next_cyclic();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->add_frame.back))
    {
        mmi_camco_osd_p->add_frame.back.is_press = MMI_TRUE;
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RSK;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->add_frame.ok))
    {
        mmi_camco_osd_p->add_frame.ok.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;
    }
}
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_recording_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_recording_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_touch_obj_struct *region =  &mmi_camco_osd_p->recording_screen.slider_region;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->recording_screen.stop))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_STOP;
        mmi_camco_osd_p->recording_screen.stop.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->recording_screen.start))
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_PAUSE_RESUME;
        mmi_camco_osd_p->recording_screen.start.is_press = MMI_TRUE;
        mmi_camco_osd_p->recording_screen.pause.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->recording_screen.slider_location_region))
    {

        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND;
        mmi_camco_osd_p->recording_screen.slider_location.is_press = MMI_TRUE;        
        mmi_camco_osd_p->rec_slider.slider_state = MMI_CAMCO_OSD_SLIDER_PRESS;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_slider_normalize(&y ,region->offset_y , region->offset_y + region->height, (mmi_camco_osd_p->recording_screen.slider_location.height))  &&
               mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->recording_screen.slider_region))

    {

        double ratio = (((1.0) * (y - mmi_camco_osd_p->recording_screen.slider_region.offset_y)) / mmi_camco_osd_p->recording_screen.slider_region.height);
        double rel_pos_y;                    
        U16 zoom_value;
        U16 curr_value = mmi_camco_setting_get_vdozoom_step();

        if (mmi_camco_osd_is_horz_UI())
        {  
            ratio = (((1.0) * (y - mmi_camco_osd_p->recording_screen.slider_region.offset_y)) / mmi_camco_osd_p->recording_screen.slider_region.height);
        }
        else
        {
            ratio = (((1.0) * (x - mmi_camco_osd_p->recording_screen.slider_region.offset_x)) / mmi_camco_osd_p->recording_screen.slider_region.width);
        }          
        
        if(ratio > 1)
            ratio = 1;

        if (mmi_camco_osd_is_horz_UI())
        {          
            rel_pos_y = (1 - ratio) * (mmi_camco_osd_p->rec_slider.step_count - 1) + (mmi_camco_osd_p->rec_slider.min_value);
        }
        else
        {          
            rel_pos_y = (ratio) * (mmi_camco_osd_p->rec_slider.step_count - 1) + (mmi_camco_osd_p->rec_slider.min_value);
        }            
        zoom_value = mmi_camco_round(rel_pos_y);
        
        if (curr_value - zoom_value > 50 || zoom_value - curr_value > 50)
            return;
        
        if (zoom_value > mmi_camco_setting_get_vdozoom_maxstep())
            zoom_value = mmi_camco_setting_get_vdozoom_maxstep();
        
        if (zoom_value < mmi_camco_setting_get_vdozoom_minstep())
            zoom_value = mmi_camco_setting_get_vdozoom_minstep();
        
        mmi_camco_setting_set_vdozoom_step(zoom_value);
        mdi_video_rec_update_para_zoom(zoom_value);
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND;        
        mmi_camco_osd_p->recording_screen.slider_location.is_press = MMI_TRUE;           
        mmi_camco_setting_set_vdozoom_value(mmi_camco_update_zoom_factor());
        
        mmi_camco_osd_draw_osd();

    }

}


#ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_panorama_shot_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_panorama_shot_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.OK))
    {
        mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_TRUE;
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.cancel))
    {
        mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RSK;
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.capture))
    {
        mmi_camco_osd_p->panorama_screen.capture.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_panorama_select_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_panorama_select_pen_down_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.OK))
    {
        mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_TRUE;
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_LSK;
        mmi_camco_osd_draw_osd();
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.cancel))
    {
        mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RSK;
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.ua_touch))
    {
        mmi_camco_osd_panorama_direct_up_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_PANORAMA_UA;
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.da_touch))
    {
        mmi_camco_osd_panorama_direct_down_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_PANORAMA_DA;   
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.la_touch))
    {
        mmi_camco_osd_panorama_direct_left_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_PANORAMA_LA;
    }
    else if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.ra_touch))
    {
        mmi_camco_osd_panorama_direct_right_press();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_PANORAMA_RA;      
    }    
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_app_enum act_app = mmi_camco_setting_get_active_app();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    if (mmi_camco_osd_is_horz_UI())
    {
        mmi_camco_osd_rotate_270_coordinate(&pos.x, &pos.y);
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            mmi_camco_osd_touch_cam_preview_pen_down_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            mmi_camco_osd_touch_rec_preview_pen_down_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:
        {
            mmi_camco_osd_touch_storage_sel_pen_down_hdlr(pos.x, pos.y);
            break;            
        }   
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        {
            mmi_camco_osd_touch_cam_setting_pen_down_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            mmi_camco_osd_touch_rec_setting_pen_down_hdlr(pos.x, pos.y);
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_touch_img_select_pen_down_hdlr(pos.x, pos.y);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            mmi_camco_osd_touch_option_menu_pen_down_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {

            mmi_camco_osd_touch_hint_pen_down_hdlr(pos.x, pos.y);

            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
        {
            mmi_camco_osd_touch_cam_add_frame_pen_down_hdlr(pos.x, pos.y);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        {
            mmi_camco_osd_touch_rec_recording_pen_down_hdlr(pos.x, pos.y);
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__        
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            mmi_camco_osd_touch_panorama_shot_pen_down_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_touch_panorama_select_pen_down_hdlr(pos.x, pos.y);
            break;
        }        
    #endif
    }
#ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
    if(mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_NONE)
    {
        mmi_camco_reset_preview_terminate_timer();
    }
#endif     
    if(mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_NONE)
    {
        if(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_PAUSE &&
           mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_RECORDING)
        {
            gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_enter_setting_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_enter_setting_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_camco_osd_cntx.evt_hdlr == NULL)
    {
        return;
    }

    /* draw osd */
    mmi_camco_osd_draw_osd();

    /* callback */
    SEND_EVT(MMI_CAMCO_EVT_OK, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_preview_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_camco_osd_touch_cam_preview_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->current_dir_setting_object = mmi_camco_osd_p->touch_obj;

    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SENSOR_SWITCHER)
    {    
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->sensor_switcher))
        {
            mmi_camco_osd_p->sensor_switcher.is_press = MMI_FALSE;        
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            mmi_camco_osd_draw_osd();      
            if(mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
                mmi_camco_switch_sub_camera();            
            else
                mmi_camco_switch_main_camera();                            
            SEND_EVT(MMI_CAMCO_EVT_SWITCH_SENSOR, NULL);            
        } 
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SCN)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.scene_mode))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.scene_mode.is_press = MMI_FALSE;
            mmi_camco_osd_p->is_direct_setting = KAL_TRUE;
            mmi_camco_osd_touch_enter_setting_hdlr();
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_FLASH)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.flash))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.flash.is_press = MMI_FALSE;
            mmi_camco_osd_p->is_direct_setting = KAL_TRUE;
            mmi_camco_osd_touch_enter_setting_hdlr();
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.zoom))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_press = MMI_FALSE;
            mmi_camco_osd_p->is_show_zoom = KAL_TRUE;            
            mmi_camco_osd_p->cam_direct_setting_screen.slider_location_region.is_usable = MMI_TRUE;
            mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_usable = MMI_TRUE;
            mmi_camco_osd_p->cam_direct_setting_screen.zoom_region.is_usable = MMI_TRUE;                            
            mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_usable = MMI_FALSE;            
            mmi_camco_osd_p->current_dir_setting_object = MMI_CAMCO_OSD_TOUCH_NONE;            
            mmi_camco_osd_draw_osd();            

        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_CAPMODE)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.capmode))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.capmode.is_press = MMI_FALSE;
            mmi_camco_osd_p->is_direct_setting = KAL_TRUE;
            mmi_camco_osd_touch_enter_setting_hdlr();
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_AD_SETTING)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.ad_setting))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
            mmi_camco_osd_p->is_direct_setting = KAL_FALSE;
            mmi_camco_osd_touch_enter_setting_hdlr();
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_PREVIEW_BACK)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.back))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_IMGVIEWER)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.imgviewer))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_press = MMI_FALSE;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            mmi_camco_osd_draw_osd();
            mmi_camco_switch_to_imgviewer();
            SEND_EVT(MMI_CAMCO_EVT_ENTER_IMGVIEWER, NULL);

        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_REC_SWTICH)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton))
        {
            mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.is_press = MMI_FALSE;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            mmi_camco_osd_p->iconlist.highlighted_idx = 0;  
            mmi_camco_osd_draw_osd();               
            mmi_camco_switch_app();            
            SEND_EVT(MMI_CAMCO_EVT_SWITCH_APP, NULL);
        }
    }   
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER ||
             mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER_MOVE)
    {
        if (mmi_camco_osd_p->is_show_zoom)
        {
            U16 zoom_value;
            mmi_camco_osd_cam_direct_setting_struct *scr_p = &mmi_camco_osd_p->cam_direct_setting_screen;

            zoom_value = mmi_camco_setting_get_camzoom_step();
            if (mmi_camco_osd_is_horz_UI())
            {             
                scr_p->slider_location.offset_y = (S32)
                    (scr_p->slider_bar.offset_y + scr_p->slider_region.height *  (1.0 - 
                     (((zoom_value - mmi_camco_osd_p->setting_slider.min_value) * 1.0) / (mmi_camco_osd_p->setting_slider.step_count - 1))));
                scr_p->slider_location.offset_y -= (scr_p->slider_location.height >>1);
                scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;
            }
            else
            {
                scr_p->slider_location.offset_x = (S32)
                    (scr_p->slider_bar.offset_x + scr_p->slider_region.width*  ( 
                     (((zoom_value - mmi_camco_osd_p->setting_slider.min_value) * 1.0) / (mmi_camco_osd_p->setting_slider.step_count - 1))));
                scr_p->slider_location.offset_x -= (scr_p->slider_location.width>>1);
                scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;            
            }
            
            mmi_camco_setting_set_camzoom_step(zoom_value);
            mdi_camera_update_para_zoom(zoom_value);
            mmi_camco_setting_set_camzoom_value(mmi_camco_update_zoom_factor());
            
            mmi_camco_osd_p->cam_direct_setting_screen.slider_location.is_press = MMI_FALSE;
            mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;        

            if (mmi_camco_setting_get_setting_value(MMI_CAMCO_SETTING_FACEDETECT) == MMI_CAMCO_FACEDETECT_ON)
            {
                mmi_camco_cam_face_detect_start();
            }               
            mmi_camco_osd_draw_osd();
        }            
    } 
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM_BACK)
    {
        mmi_camco_osd_p->is_show_zoom = MMI_FALSE;              
        mmi_camco_osd_p->cam_direct_setting_screen.slider_location_region.is_usable = MMI_FALSE;
        mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_usable = MMI_FALSE;
        mmi_camco_osd_p->cam_direct_setting_screen.zoom_region.is_usable = MMI_FALSE;                            
        mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_usable = MMI_TRUE;
        mmi_camco_osd_draw_osd();        
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_preview_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_camco_osd_touch_rec_preview_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->current_dir_setting_object = mmi_camco_osd_p->touch_obj;

    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SENSOR_SWITCHER)
    {    
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->sensor_switcher))
        {
            mmi_camco_osd_p->sensor_switcher.is_press = MMI_FALSE;        
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            mmi_camco_osd_draw_osd();      
            if(mmi_camco_setting_get_active_cam() == MMI_CAMCO_SETTING_CAM_MAIN)
                mmi_camco_switch_sub_camera();            
            else
                mmi_camco_switch_main_camera();                            
            SEND_EVT(MMI_CAMCO_EVT_SWITCH_SENSOR, NULL);            
        } 
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_SCN)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.scene_mode))
        {
            mmi_camco_osd_p->rec_direct_setting_screen.scene_mode.is_press = MMI_FALSE;
            mmi_camco_osd_p->is_direct_setting = KAL_TRUE;
            mmi_camco_osd_touch_enter_setting_hdlr();
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.zoom))
        {
            mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_press = MMI_FALSE;
            mmi_camco_osd_p->current_dir_setting_object = MMI_CAMCO_OSD_TOUCH_NONE;            
            mmi_camco_osd_p->is_show_zoom = MMI_TRUE;            
            mmi_camco_osd_p->rec_direct_setting_screen.slider_location_region.is_usable = MMI_TRUE;
            mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_usable = MMI_TRUE;
            mmi_camco_osd_p->rec_direct_setting_screen.zoom_region.is_usable = MMI_TRUE;                            
            mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_usable = MMI_FALSE;               
            mmi_camco_osd_draw_osd();


        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_AD_SETTING)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.ad_setting))
        {
            mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
            mmi_camco_osd_p->is_direct_setting = KAL_FALSE;
            mmi_camco_osd_touch_enter_setting_hdlr();
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_PREVIEW_BACK)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.back))
        {
            mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ALLVIDEOS)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.allvideos))
        {
            mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            mmi_camco_switch_to_vdoply();
            SEND_EVT(MMI_CAMCO_EVT_ENTER_VDOPLER, NULL);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_CAM_SWTICH)
    {
        if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top))
        {
            mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top.is_press = MMI_FALSE;
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            mmi_camco_osd_p->iconlist.highlighted_idx = 0;            
            mmi_camco_osd_draw_osd();               
            mmi_camco_switch_app();            
            SEND_EVT(MMI_CAMCO_EVT_SWITCH_APP, NULL);
        }
    }   
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER ||
             mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER_MOVE)
    {
        if (mmi_camco_osd_p->is_show_zoom)
        {
            U16 zoom_value;
            mmi_camco_osd_rec_direct_setting_struct *scr_p = &mmi_camco_osd_p->rec_direct_setting_screen;

            zoom_value = mmi_camco_setting_get_vdozoom_step();
            if (mmi_camco_osd_is_horz_UI())
            {              
                scr_p->slider_location.offset_y = (S32)
                    (scr_p->slider_bar.offset_y + scr_p->slider_region.height *  (1.0 - 
                     (((zoom_value - mmi_camco_osd_p->setting_slider.min_value) * 1.0) / (mmi_camco_osd_p->setting_slider.step_count - 1))));
                scr_p->slider_location.offset_y -= (scr_p->slider_location.height >>1);
                scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;
            }
            else
            {              
                scr_p->slider_location.offset_x = (S32)
                    (scr_p->slider_bar.offset_x + scr_p->slider_region.width*  ( 
                     (((zoom_value - mmi_camco_osd_p->setting_slider.min_value) * 1.0) / (mmi_camco_osd_p->setting_slider.step_count - 1))));
                scr_p->slider_location.offset_x -= (scr_p->slider_location.width>>1);
                scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;
            }                
            mmi_camco_setting_set_vdozoom_step(zoom_value);
            mdi_video_rec_update_para_zoom(zoom_value);
            mmi_camco_setting_set_vdozoom_value(mmi_camco_update_zoom_factor());

            mmi_camco_osd_p->rec_direct_setting_screen.slider_location.is_press = MMI_FALSE;
            mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;                   
            mmi_camco_osd_draw_osd();
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM_BACK)
    {
        mmi_camco_osd_p->is_show_zoom = MMI_FALSE;
        mmi_camco_osd_p->rec_direct_setting_screen.slider_location_region.is_usable = MMI_FALSE;
        mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_usable = MMI_FALSE;
        mmi_camco_osd_p->rec_direct_setting_screen.zoom_region.is_usable = MMI_FALSE;                            
        mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_usable = MMI_TRUE;            
        mmi_camco_osd_draw_osd();        
    }    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_setting_menu_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enter        [IN]        
 *  idx             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_setting_menu_pen_up_hdlr(mmi_cameco_osd_advance_setting_action_enum is_enter, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_enter == MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER)
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {

            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);

            mmi_camco_setting_restore_hilite_mod();
            mmi_camco_setting_set_mainlist_idx(idx);

            mmi_camco_osd_gen_setting_menulist();

            mmi_camco_osd_p->advance_setting_screen.menu_status = MMI_CAMCO_OSD_MENU_LEVEL2;
        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_setting_item_selected_hdlr();

            if (mmi_camco_setting_is_facedetect_on() && mmi_camco_setting_get_active_app() == MMI_CAMCO_SETTING_APP_CAMERA)
            {
                mmi_camco_update_effect(MMI_CAMCO_EFFECT_NORMAL);
            }

            mmi_camco_setting_gen_mainlist(mmi_camco_setting_get_mainlist_type());
            mmi_camco_setting_set_mainlist_idx(mmi_camco_osd_p->iconlist.highlighted_idx);

            if ((mmi_camco_setting_get_mainlist_count() - mmi_camco_osd_p->iconlist.highlighted_idx) < mmi_camco_osd_p->iconlist.disp_icon_count)
            {
                mmi_camco_osd_p->iconlist.first_disp_idx = mmi_camco_setting_get_mainlist_count() - mmi_camco_osd_p->iconlist.disp_icon_count;

                if (mmi_camco_osd_p->iconlist.first_disp_idx < 0)
                {
                    mmi_camco_osd_p->iconlist.first_disp_idx = 0;
                }
            }
            else
            {
                mmi_camco_osd_p->iconlist.first_disp_idx = mmi_camco_osd_p->iconlist.highlighted_idx;
            }

            mmi_camco_osd_update_iconlist();
            mmi_camco_osd_gen_setting_menulist();

             mmi_camco_osd_p->advance_setting_screen.menu_status = MMI_CAMCO_OSD_MENU_LEVEL1;
        }
    }
    else if (is_enter == MMI_CAMCO_OSD_AD_SETTING_ACTION_TRAVERSAL)
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            mmi_camco_setting_restore_hilite_mod();
            mmi_camco_setting_set_mainlist_idx(idx);
            mmi_camco_osd_gen_setting_menulist();
        }
    }
    else
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_setting_restore_hilite_mod();
            mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->act_menulist_p->active_idx);            
            mmi_camco_osd_p->advance_setting_screen.menu_status = MMI_CAMCO_OSD_MENU_LEVEL1;
        }
    }

    mmi_camco_osd_draw_osd();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_setting_excute_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  execute     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_setting_excute_hdlr(MMI_BOOL execute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_draw_osd();

    if (!execute)
    {
        mmi_camco_setting_restore_hilite_mod();
        SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
    }
    else
    {
        /* call item select handler - do action */
        /* this function will modify type and index, call after getting those value */
        if (mmi_camco_osd_p->current_dir_setting_object != MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM &&
            mmi_camco_osd_p->current_dir_setting_object != MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM)
        {
            mmi_camco_setting_item_selected_hdlr();
        }
        /* if current hilite is restore default, no action when back  */
        if (mmi_camco_osd_p->last_l1_menu_hilite_str_id == STR_ID_CAMCO_DEFAULT &&
            mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK)
        {
            mmi_camco_reset_restore_default_setting(0);
        }

        SEND_EVT(MMI_CAMCO_EVT_OK, NULL);

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_advance_setting_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_advance_setting_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_NONE ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE)
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
        mmi_camco_osd_draw_osd();
        return;
    }
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK)
    {
        mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_FALSE;
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            if (mmi_camco_if_need_restart_preview())
                mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
            else
                mmi_camco_osd_touch_setting_excute_hdlr(MMI_FALSE);
        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_touch_setting_menu_pen_up_hdlr(MMI_CAMCO_OSD_AD_SETTING_ACTION_BACK, -1);
        }

    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_OK)
    {
        if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            /* if choose restore default, back to preview directly */
            if (mmi_camco_osd_p->iconlist.icon_list[mmi_camco_osd_p->iconlist.highlighted_idx].str_id == STR_ID_CAMCO_DEFAULT)
            {
                mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
                return;
            }

            mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                mmi_camco_osd_p->iconlist.highlighted_idx);            
        }
        else if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                mmi_camco_osd_p->setting_menulist.highlighted_idx);            
        }    
        mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;        
    }
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
    {

        S16 idx;

        idx = mmi_camco_osd_get_menulist_idx_from_pos(x, y);
        if (idx >= 0 && idx < mmi_camco_osd_p->setting_menulist.disp_item_count)
        {

            if (mmi_camco_osd_p->setting_menulist.highlight_change_flag ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_MOVE)
            {

                mmi_camco_osd_p->setting_menulist.highlighted_idx =
                    idx + mmi_camco_osd_p->setting_menulist.first_disp_idx;
                mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->setting_menulist.highlighted_idx);
                mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_TRAVERSAL,
                    mmi_camco_osd_p->setting_menulist.highlighted_idx);

            }
            else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_NEXT ||
                     mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_PREV)
            {
                gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
            }
            else
            {
                mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                    mmi_camco_osd_p->setting_menulist.highlighted_idx);
            }
        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_NEXT ||
                 mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_PREV)
        {
            gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_MAIN_TAB)
    {
        if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.main_tab))
        {
            mmi_camco_setting_mainlist_type_enum type;
            U16 count;

            type = mmi_camco_setting_get_mainlist_type();

            if (type != MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
            {
                mmi_camco_setting_restore_hilite_mod();
                gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);
                count = mmi_camco_setting_get_mainlist_count();
                MMI_ASSERT(count != 0);

                mmi_camco_setting_set_mainlist_idx(0);

                mmi_camco_osd_gen_iconlist();
                mmi_camco_osd_gen_setting_menulist();

                mmi_camco_osd_draw_osd();
            }
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_MISC_TAB)
    {
        if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.misc_tab))
        {
            mmi_camco_setting_mainlist_type_enum type;
            U16 count;

            type = mmi_camco_setting_get_mainlist_type();

            if (type != MMI_CAMCO_SETTING_MAINLIST_SECONDARY)
            {
                mmi_camco_setting_restore_hilite_mod();
                gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_SECONDARY);
                count = mmi_camco_setting_get_mainlist_count();
                MMI_ASSERT(count != 0);

                mmi_camco_setting_set_mainlist_idx(0);

                mmi_camco_osd_gen_iconlist();
                mmi_camco_osd_gen_setting_menulist();

                mmi_camco_osd_draw_osd();
            }
        }
    }
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
    {
        S16 idx;

        idx = mmi_camco_osd_get_iconlist_idx_from_pos(x, y);

        if (idx >= 0)
        {

            if (mmi_camco_osd_p->iconlist.highlight_change_flag ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_MOVE)
            {

                mmi_camco_osd_p->iconlist.highlighted_idx = idx + mmi_camco_osd_p->iconlist.first_disp_idx;
                mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_TRAVERSAL,
                    mmi_camco_osd_p->iconlist.highlighted_idx);
            }
            else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_NEXT ||
                     mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_PREV)
            {
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            }
            else if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_NONE)
            {
                /* if choose restore default, back to preview directly */
                if (mmi_camco_osd_p->iconlist.icon_list[idx + mmi_camco_osd_p->iconlist.first_disp_idx].str_id == STR_ID_CAMCO_DEFAULT &&
                    mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK)
                {

                    mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
                    return;
                }
                else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK)
                {
                    return;
                }

                mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                    mmi_camco_osd_p->iconlist.highlighted_idx);
            }
        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_NEXT ||
                 mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_PREV)
        {
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_direct_setting_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_direct_setting_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_BACK)
    {
        mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_FALSE;
        mmi_camco_osd_touch_setting_excute_hdlr(MMI_FALSE);
    }
    else if (mmi_camco_osd_p->touch_obj >= MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM1 &&
             mmi_camco_osd_p->touch_obj <= MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM12)
    {
        U8 idx = mmi_camco_osd_touch_translate_object_to_idx(mmi_camco_osd_p->touch_obj);

        if (mmi_camco_osd_p->setting_menulist.highlight_change_flag || !mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->active_setting_item[idx]))
        {
            mmi_camco_osd_p->setting_menulist.highlighted_idx = idx;
        }
        else
        {
            mmi_camco_setting_set_itemlist_idx(idx);
            //mmi_camco_setting_item_selected_hdlr();
            mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
        }
        mmi_camco_osd_draw_osd();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_setting_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_setting_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->is_direct_setting == KAL_TRUE)
    {
        mmi_camco_osd_touch_cam_direct_setting_pen_up_hdlr(x, y);
    }
    else
    {
        mmi_camco_osd_touch_cam_advance_setting_pen_up_hdlr(x, y);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_setting_menu_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_enter        [IN]        
 *  idx             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_setting_menu_pen_up_hdlr(mmi_cameco_osd_advance_setting_action_enum is_enter, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_enter == MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER)
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {

            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);

            mmi_camco_setting_restore_hilite_mod();
            mmi_camco_setting_set_mainlist_idx(idx);

            mmi_camco_osd_gen_setting_menulist();

            mmi_camco_osd_p->advance_setting_screen.menu_status = MMI_CAMCO_OSD_MENU_LEVEL2;
        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_setting_item_selected_hdlr();

            mmi_camco_setting_gen_mainlist(mmi_camco_setting_get_mainlist_type());
            mmi_camco_setting_set_mainlist_idx(mmi_camco_osd_p->iconlist.highlighted_idx);

            if ((mmi_camco_setting_get_mainlist_count() - mmi_camco_osd_p->iconlist.highlighted_idx) < mmi_camco_osd_p->iconlist.disp_icon_count)
            {
                mmi_camco_osd_p->iconlist.first_disp_idx = mmi_camco_setting_get_mainlist_count() - mmi_camco_osd_p->iconlist.disp_icon_count;

                if (mmi_camco_osd_p->iconlist.first_disp_idx < 0)
                {
                    mmi_camco_osd_p->iconlist.first_disp_idx = 0;
                }
            }
            else
            {
                mmi_camco_osd_p->iconlist.first_disp_idx = mmi_camco_osd_p->iconlist.highlighted_idx;
            }

            mmi_camco_osd_update_iconlist();
            mmi_camco_osd_gen_setting_menulist();

            mmi_camco_osd_p->advance_setting_screen.menu_status = MMI_CAMCO_OSD_MENU_LEVEL1;

        }

    }
    else if (is_enter == MMI_CAMCO_OSD_AD_SETTING_ACTION_TRAVERSAL)
    {
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            mmi_camco_setting_restore_hilite_mod();
            mmi_camco_setting_set_mainlist_idx(idx);

            mmi_camco_osd_gen_setting_menulist();

        }
    }
    else
    {

        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_setting_restore_hilite_mod();
            mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->act_menulist_p->active_idx);              
            mmi_camco_osd_p->advance_setting_screen.menu_status = MMI_CAMCO_OSD_MENU_LEVEL1;
        }
    }

    mmi_camco_osd_draw_osd();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_advance_setting_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_advance_setting_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_NONE ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL ||
        mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE)
    {
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
        mmi_camco_osd_draw_osd();
        return;
    }
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK)
    {
        mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_FALSE;
        if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {

            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK;
            if (mmi_camco_if_need_restart_preview())
                mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
            else
                mmi_camco_osd_touch_setting_excute_hdlr(MMI_FALSE);

        }
        else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_touch_rec_setting_menu_pen_up_hdlr(MMI_CAMCO_OSD_AD_SETTING_ACTION_BACK, -1);
        }

    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_OK)
    {
        if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
        {
            /* if choose restore default, back to preview directly */
            if (mmi_camco_osd_p->iconlist.icon_list[mmi_camco_osd_p->iconlist.highlighted_idx].str_id == STR_ID_CAMCO_DEFAULT)
            {
                mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
                return;
            }

            mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                mmi_camco_osd_p->iconlist.highlighted_idx);            
        }
        else if(mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
        {
            mmi_camco_osd_touch_setting_menu_pen_up_hdlr(
                MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                mmi_camco_osd_p->setting_menulist.highlighted_idx);            
        }    
        mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;        
    }    
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL2)
    {

        S16 idx;

        idx = mmi_camco_osd_get_menulist_idx_from_pos(x, y);
        if (idx >= 0 && idx < mmi_camco_osd_p->setting_menulist.disp_item_count)
        {

            if (mmi_camco_osd_p->setting_menulist.highlight_change_flag ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_MOVE)
            {

                mmi_camco_osd_p->setting_menulist.highlighted_idx =
                    idx + mmi_camco_osd_p->setting_menulist.first_disp_idx;
                mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->setting_menulist.highlighted_idx);
                mmi_camco_osd_touch_rec_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_TRAVERSAL,
                    mmi_camco_osd_p->setting_menulist.highlighted_idx);

            }
            else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_NEXT ||
                     mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_PREV)
            {
                gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
            }
            else
            {
                mmi_camco_osd_touch_rec_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                    mmi_camco_osd_p->setting_menulist.highlighted_idx);
            }
        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_NEXT ||
                 mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_PREV)
        {
            gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_MAIN_TAB)
    {
        if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.main_tab))
        {
            mmi_camco_setting_mainlist_type_enum type;
            U16 count;

            type = mmi_camco_setting_get_mainlist_type();

            if (type != MMI_CAMCO_SETTING_MAINLIST_PRIMARY)
            {
                mmi_camco_setting_restore_hilite_mod();
                gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_PRIMARY);
                count = mmi_camco_setting_get_mainlist_count();
                MMI_ASSERT(count != 0);

                mmi_camco_setting_set_mainlist_idx(0);

                mmi_camco_osd_gen_iconlist();
                mmi_camco_osd_gen_setting_menulist();

                mmi_camco_osd_draw_osd();
            }
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_MISC_TAB)
    {
        if (mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->advance_setting_screen.misc_tab))
        {
            mmi_camco_setting_mainlist_type_enum type;
            U16 count;

            type = mmi_camco_setting_get_mainlist_type();

            if (type != MMI_CAMCO_SETTING_MAINLIST_SECONDARY)
            {
                mmi_camco_setting_restore_hilite_mod();
                gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                mmi_camco_setting_gen_mainlist(MMI_CAMCO_SETTING_MAINLIST_SECONDARY);
                count = mmi_camco_setting_get_mainlist_count();
                MMI_ASSERT(count != 0);

                mmi_camco_setting_set_mainlist_idx(0);

                mmi_camco_osd_gen_iconlist();
                mmi_camco_osd_gen_setting_menulist();

                mmi_camco_osd_draw_osd();
            }
        }
    }
    else if (mmi_camco_osd_p->advance_setting_screen.menu_status == MMI_CAMCO_OSD_MENU_LEVEL1)
    {
        S16 idx;

        idx = mmi_camco_osd_get_iconlist_idx_from_pos(x, y);

        if (idx >= 0)
        {

            if (mmi_camco_osd_p->iconlist.highlight_change_flag ||
                mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_MOVE)
            {

                mmi_camco_osd_p->iconlist.highlighted_idx = idx + mmi_camco_osd_p->iconlist.first_disp_idx;
                mmi_camco_osd_touch_rec_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_TRAVERSAL,
                    mmi_camco_osd_p->iconlist.highlighted_idx);
            }
            else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_NEXT ||
                     mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_PREV)
            {
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
            }
            else if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_NONE)
            {
                /* if choose restore default, back to preview directly */
                if (mmi_camco_osd_p->iconlist.icon_list[idx + mmi_camco_osd_p->iconlist.first_disp_idx].str_id == STR_ID_CAMCO_DEFAULT && 
                    mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK)
                {

                    mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
                    return;
                }
                else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK)
                {
                    return;
                }

                mmi_camco_osd_touch_rec_setting_menu_pen_up_hdlr(
                    MMI_CAMCO_OSD_AD_SETTING_ACTION_ENTER,
                    mmi_camco_osd_p->iconlist.highlighted_idx);
            }
        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_NEXT ||
                 mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_PREV)
        {
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
            gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_direct_setting_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_direct_setting_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_BACK)
    {
        mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_FALSE;
        mmi_camco_osd_touch_setting_excute_hdlr(MMI_FALSE);
    }
    else if (mmi_camco_osd_p->touch_obj >= MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM1 &&
             mmi_camco_osd_p->touch_obj <= MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM12)
    {
        U8 idx = mmi_camco_osd_touch_translate_object_to_idx(mmi_camco_osd_p->touch_obj);

        if (mmi_camco_osd_p->setting_menulist.highlight_change_flag || !mmi_camco_osd_touch_hit_test(x, y, &mmi_camco_osd_p->active_setting_item[idx]))
        {
            mmi_camco_osd_p->setting_menulist.highlighted_idx = idx;
        }
        else
        {
            mmi_camco_setting_set_itemlist_idx(idx);
            //mmi_camco_setting_item_selected_hdlr();
            mmi_camco_osd_touch_setting_excute_hdlr(MMI_TRUE);
        }
        mmi_camco_osd_draw_osd();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_setting_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_setting_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->is_direct_setting == KAL_TRUE)
    {
        mmi_camco_osd_touch_rec_direct_setting_pen_up_hdlr(x, y);
    }
    else
    {
        mmi_camco_osd_touch_rec_advance_setting_pen_up_hdlr(x, y);
    }
}

#ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_img_select_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_img_select_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_IMG_SELECT_IMG)
    {
        /* do nothing */
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_AP)
    {
        mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_press = MMI_FALSE;
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_FALSE;
        SEND_EVT(MMI_CAMCO_EVT_IMG_SELECT_ENTER_IMGVIEWER, NULL);
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_DELETE)
    {
        mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_press = MMI_FALSE;
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_FALSE;
        SEND_EVT(MMI_CAMCO_EVT_IMG_SELECT_DEL, NULL);

    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_SAVE)
    {
        mmi_camco_osd_p->captured_img_select_screen.save.is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
        SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
    }    
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_FORWARD)
    {
        mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_press = MMI_FALSE;
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_FALSE;
        SEND_EVT(MMI_CAMCO_EVT_IMG_SELECT_FORWARD, NULL);

    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_IMG_SELECT_BACK)
    {
        mmi_camco_osd_p->captured_img_select_screen.back.is_press = MMI_FALSE;
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_TRUE;
        mmi_camco_osd_draw_osd();
        mmi_camco_osd_p->captured_img_select_screen.is_bypass_update_img_list = MMI_FALSE;
        SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
    }

}
#endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_option_menu_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_option_menu_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_BT)
    {
        if (!mmi_camco_osd_p->forward_screen.highlite_change_flag && mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->forward_screen.item[0]))
        {
            SEND_EVT(MMI_CAMCO_EVT_OPTION_BT, NULL);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_MMS)
    {
        if (!mmi_camco_osd_p->forward_screen.highlite_change_flag && mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->forward_screen.item[1]))
        {
            SEND_EVT(MMI_CAMCO_EVT_OPTION_MMS, NULL);
        }

    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_EMAIL)
    {
        if (!mmi_camco_osd_p->forward_screen.highlite_change_flag && mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->forward_screen.item[2]))
        {
            SEND_EVT(MMI_CAMCO_EVT_OPTION_EMAIL, NULL);
        }
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_BACK)
    {
        mmi_camco_osd_p->forward_screen.back.is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        SEND_EVT(MMI_CAMCO_EVT_OPTION_BACK, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_hint_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_hint_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITH_BAR)
    {
        if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAPTURED_BACK)
        {
            mmi_camco_osd_p->captured_screen.back.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);

        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_AP)
        {
            mmi_camco_osd_p->captured_screen.tool_bar[0].is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_HINT)
            {
                SEND_EVT(MMI_CAMCO_EVT_CAPTURED_IMGVIEWER, NULL);
            }
            else
            {
                SEND_EVT(MMI_CAMCO_EVT_RECORDED_VDOPLYER, NULL);
            }

        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_DELETE)
        {
            mmi_camco_osd_p->captured_screen.tool_bar[1].is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_HINT)
            {
                SEND_EVT(MMI_CAMCO_EVT_CAPTURED_DEL, NULL);
            }
            else
            {
                SEND_EVT(MMI_CAMCO_EVT_RECORDED_DEL, NULL);
            }
        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_FORWARD)
        {
            mmi_camco_osd_p->captured_screen.tool_bar[2].is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_HINT)
            {
                SEND_EVT(MMI_CAMCO_EVT_CAPTURED_FORWARD, NULL);
            }
            else
            {
                SEND_EVT(MMI_CAMCO_EVT_RECORDED_FORWARD, NULL);
            }
        }
    }
    else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITHOUT_BAR ||
               mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_CONFIRM_WITH_BAR)
    {
        if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CONFIRM_YES)
        {
            mmi_camco_osd_p->confirm_screen.confirm_lsk.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            SEND_EVT(MMI_CAMCO_EVT_CONFIRM_YES, NULL);
        }
        else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_CONFIRM_NO)
        {
            mmi_camco_osd_p->confirm_screen.confirm_rsk.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            SEND_EVT(MMI_CAMCO_EVT_CONFIRM_NO, NULL);

        }
    }
    else if (mmi_camco_osd_p->stop_hint_mode == MMI_CAMCO_OSD_STOP_HINT_MODE_HINT_WITHOUT_BAR)
    {
        if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_HINT_BACK)
        {
            mmi_camco_osd_p->captured_screen.back.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
        }
    }

}

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_cam_add_frame_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_cam_add_frame_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->touch_obj)
    {

        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_RA:
            gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
            mmi_camco_osd_p->add_frame.ra_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            break;

        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_LA:
            gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
            mmi_camco_osd_p->add_frame.la_touch.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            break;
        case MMI_CAMCO_OSD_TOUCH_LSK:
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->add_frame.ok))
            {
                mmi_camco_osd_p->add_frame.ok.is_press = MMI_FALSE;
                mmi_camco_osd_p->add_frame.is_picked = MMI_TRUE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_RSK:
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->add_frame.back))
            {
                mmi_camco_osd_p->add_frame.back.is_press = MMI_FALSE;

                mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_CAPMODE, mmi_camco_get_last_capmode());
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);

            }
            break;
    }
}
#endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_rec_recording_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_rec_recording_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_RECORDING_STOP)
    {

        mmi_camco_osd_p->recording_screen.stop.is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_RECORDING_PAUSE_RESUME)
    {
        mmi_camco_osd_p->recording_screen.start.is_press = MMI_FALSE;
        mmi_camco_osd_p->recording_screen.pause.is_press = MMI_FALSE;
        mmi_camco_osd_draw_osd();
        SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
    }
    else if (mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND ||
             mmi_camco_osd_p->touch_obj == MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND_MOVE)
    {

        {

            U16 zoom_value;
            mmi_camco_osd_rec_screen_struct *scr_p = &mmi_camco_osd_p->recording_screen;

            zoom_value = mmi_camco_setting_get_vdozoom_step();
            if (mmi_camco_osd_is_horz_UI())
            {              
                scr_p->slider_location.offset_y = (S32)
                    (scr_p->slider_bar.offset_y + scr_p->slider_region.height *  (1.0 - 
                     (((zoom_value - mmi_camco_osd_p->rec_slider.min_value) * 1.0) / (mmi_camco_osd_p->rec_slider.step_count - 1))));
                scr_p->slider_location.offset_y -= (scr_p->slider_location.height >>1);
                scr_p->slider_location_region.offset_y = scr_p->slider_location.offset_y - 5;
            }
            else
            {              
                scr_p->slider_location.offset_x = (S32)
                    (scr_p->slider_bar.offset_x + scr_p->slider_region.width*  ( 
                     (((zoom_value - mmi_camco_osd_p->rec_slider.min_value) * 1.0) / (mmi_camco_osd_p->rec_slider.step_count - 1))));
                scr_p->slider_location.offset_x -= (scr_p->slider_location.width>>1);
                scr_p->slider_location_region.offset_x = scr_p->slider_location.offset_x - 10;
            }
            mmi_camco_setting_set_vdozoom_step(zoom_value);
            mdi_camera_update_para_zoom(zoom_value);
            mmi_camco_setting_set_vdozoom_value(mmi_camco_update_zoom_factor());
            mmi_camco_osd_p->recording_screen.slider_location.is_press = MMI_FALSE;   
            mmi_camco_osd_p->rec_slider.slider_state = MMI_CAMCO_OSD_SLIDER_RELEASE;

            mmi_camco_osd_draw_osd();
        }
    }

}

#ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_panorama_shot_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_panorama_shot_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->touch_obj)
    {

        case MMI_CAMCO_OSD_TOUCH_LSK:
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.OK))
            {
                mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_RSK:
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.cancel))
            {
                mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_panorama_select_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_touch_panorama_select_pen_up_hdlr(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_osd_p->touch_obj)
    {    
        case MMI_CAMCO_OSD_TOUCH_LSK:
        {
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.OK))
            {
                mmi_camco_osd_p->panorama.is_picked = MMI_TRUE;
                mmi_camco_setting_set_panorama_direction(mmi_camco_osd_p->panorama.highlighted_idx);                
                mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_OK, NULL);
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_RSK:
        {
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama_screen.cancel))
            {
                mmi_camco_setting_set_current_setting_value(MMI_CAMCO_SETTING_CAPMODE, mmi_camco_get_last_capmode());                        
                mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CANCEL, NULL);
            }    
        }            
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_UA:
        {
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.ua_touch))
            {
                mmi_camco_osd_panorama_direct_up_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_DA:
        {
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.da_touch))
            {
                mmi_camco_osd_panorama_direct_down_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_LA:
        {
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.la_touch))
            {
                mmi_camco_osd_panorama_direct_left_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_RA:
        {
            if (mmi_camco_osd_touch_hit_test_ext(x, y, &mmi_camco_osd_p->panorama.ra_touch))
            {
                mmi_camco_osd_panorama_direct_right_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }    
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_app_enum act_app = mmi_camco_setting_get_active_app();
    mmi_camco_osd_touch_obj_enum prev_touch_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    if (mmi_camco_osd_is_horz_UI())
    {
        mmi_camco_osd_rotate_270_coordinate(&pos.x, &pos.y);
    }

    switch (mmi_camco_osd_p->osd_state)
    {
        case MMI_CAMCO_OSD_STATE_CAMERA_PREVIEW:
        {
            mmi_camco_osd_touch_cam_preview_pen_up_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_PREVIEW:
        {
            mmi_camco_osd_touch_rec_preview_pen_up_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_STORAGE_SELECTION:
        case MMI_CAMCO_OSD_STATE_VIDEO_STORAGE_SELECTION:
        {
            mmi_camco_osd_touch_storage_sel_pen_up_hdlr(pos.x, pos.y);
            break;            
        }   
        case MMI_CAMCO_OSD_STATE_CAMERA_SETTING:
        {
            mmi_camco_osd_touch_cam_setting_pen_up_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_VIDEO_SETTING:
        {
            mmi_camco_osd_touch_rec_setting_pen_up_hdlr(pos.x, pos.y);
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__
        case MMI_CAMCO_OSD_STATE_IMAGE_SELECTION:
        {
            mmi_camco_osd_touch_img_select_pen_up_hdlr(pos.x, pos.y);
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_IMAGE_SELECT__ */ 
        case MMI_CAMCO_OSD_STATE_OPTION_MENU:
        {
            mmi_camco_osd_touch_option_menu_pen_up_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_CAMERA_HINT:
        case MMI_CAMCO_OSD_STATE_VIDEO_HINT:
        {

            mmi_camco_osd_touch_hint_pen_up_hdlr(pos.x, pos.y);
            if(mmi_camco_osd_p->is_capturing)
            {
                mmi_camco_osd_p->is_capturing = MMI_FALSE;       
            }

            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION:
            mmi_camco_osd_touch_cam_add_frame_pen_up_hdlr(pos.x, pos.y);
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
        case MMI_CAMCO_OSD_STATE_VIDEO_PAUSE:
        case MMI_CAMCO_OSD_STATE_VIDEO_RECORDING:
        {
            mmi_camco_osd_touch_rec_recording_pen_up_hdlr(pos.x, pos.y);
            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_STATE_PANORAMA_SHOT:
        {
            mmi_camco_osd_touch_panorama_shot_pen_up_hdlr(pos.x, pos.y);
            break;
        }
        case MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION:
        {
            mmi_camco_osd_touch_panorama_select_pen_up_hdlr(pos.x, pos.y);
            break;
        }        
    #endif    
        case MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT:
        {

            if(mmi_camco_osd_p->is_capturing)
            {
                mmi_camco_osd_p->is_capturing = MMI_FALSE;
                mmi_camco_osd_set_bg_black();
                mmi_camco_osd_draw_osd();
                SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);
            }    
            break;            
        }
        
    }

    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_touch_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_app_enum act_app = mmi_camco_setting_get_active_app();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_EXIT);

    if (mmi_camco_osd_is_horz_UI())
    {
        mmi_camco_osd_rotate_270_coordinate(&pos.x, &pos.y);
    }

    switch (mmi_camco_osd_p->touch_obj)
    {

        case MMI_CAMCO_OSD_TOUCH_LSK:
        {
            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION)
            {
                if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->add_frame.ok))
                {
                    mmi_camco_osd_p->add_frame.ok.is_press = MMI_FALSE;
                    mmi_camco_osd_draw_osd();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                }
            }
            else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_PANORAMA_SHOT ||
                       mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION)
            {
                if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->panorama_screen.OK))
                {
                    mmi_camco_osd_p->panorama_screen.OK.is_press = MMI_FALSE;
                    mmi_camco_osd_draw_osd();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                }
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_RSK:
        {
            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_ADD_FRAME_SELECTION)
            {
                if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->add_frame.back))
                {
                    mmi_camco_osd_p->add_frame.back.is_press = MMI_FALSE;
                    mmi_camco_osd_draw_osd();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                }
            }
            else if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_PANORAMA_SHOT ||
                       mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_PANORAMA_SELECTION)
            {
                if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->panorama_screen.cancel))
                {
                    mmi_camco_osd_p->panorama_screen.cancel.is_press = MMI_FALSE;
                    mmi_camco_osd_draw_osd();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                }
            }
            break;
        }
        if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->storage_select_screen.back))
        {
            mmi_camco_osd_p->storage_select_screen.back.is_press = MMI_FALSE;
            mmi_camco_osd_draw_osd();
            mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            break;            
        }    
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_MOVE:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_PREV:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_NEXT:
        {
            mmi_camco_osd_iconlist_struct *iconlist_p = &mmi_camco_osd_p->iconlist;
            MMI_BOOL is_up = (mmi_camco_osd_p->previous_pos_y > pos.y) ? (MMI_TRUE) : (MMI_FALSE);

            mmi_camco_osd_p->previous_pos_y = pos.y;

            if ((mmi_camco_osd_p->iconlist.icon_count <=
                 mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count) ||
                mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_touch[0]))
            {
                S16 idx;

                gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);

                idx = mmi_camco_osd_get_iconlist_idx_from_pos(pos.x, pos.y);

                if (idx >= 0)
                {
                    if ((idx + mmi_camco_osd_p->iconlist.first_disp_idx) != iconlist_p->highlighted_idx)
                    {
                        mmi_camco_setting_restore_hilite_mod();
                        gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                        mmi_camco_setting_set_mainlist_idx((idx + mmi_camco_osd_p->iconlist.first_disp_idx));

                        /* gen menulist again */
                        mmi_camco_osd_gen_setting_menulist();

                        iconlist_p->highlighted_idx = (idx + mmi_camco_osd_p->iconlist.first_disp_idx);
                        mmi_camco_osd_draw_osd();
                        mmi_camco_osd_p->iconlist.highlight_change_flag = MMI_TRUE;                        
                    #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
                        mmi_camco_reset_preview_terminate_timer();
                    #endif 
                        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_MOVE;                    
                    }

                }
            }
            else if (mmi_camco_osd_p->iconlist.icon_count >
                     mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count &&
                     mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_pre_touch[0]) && is_up)
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_PREV)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
                    mmi_camco_osd_p->iconlist.highlight_change_flag = MMI_FALSE;

                    mmi_camco_osd_touch_iconlist_prev_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_PREV;
                }
            }
            else if (mmi_camco_osd_p->iconlist.icon_count >
                     mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count &&
                     mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_next_touch[0]) && !is_up)
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_NEXT)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
                    mmi_camco_osd_p->iconlist.highlight_change_flag = MMI_FALSE;

                    mmi_camco_osd_touch_iconlist_next_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_NEXT;
                }
            }
            else if((mmi_camco_osd_p->iconlist.icon_count > mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count &&
                     mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_next_touch[0])) ||
                    (mmi_camco_osd_p->iconlist.icon_count > mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count &&
                     mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_pre_touch[0]))
                   )
            {
                /* wrong dir but not move out */
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_MOVE; 

            }
            else
            {
                /* moved out */
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_iconlist_next_cyclic);
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;

            }
            break;
        }

        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_MOVE:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_PREV:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_NEXT:
        {
            MMI_BOOL update_setting = MMI_FALSE;
            mmi_camco_osd_menulist_struct *menulist_p = mmi_camco_osd_p->act_menulist_p;
            MMI_BOOL is_up = (mmi_camco_osd_p->previous_pos_y > pos.y) ? (MMI_TRUE) : (MMI_FALSE);

            mmi_camco_osd_p->previous_pos_y = pos.y;

            if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_SETTING ||
                mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_VIDEO_SETTING)
            {
                update_setting = MMI_TRUE;
            }

            if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_touch[1]))
            {
                S16 idx;

                gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);

                idx = mmi_camco_osd_get_menulist_idx_from_pos(pos.x, pos.y);
                if (idx >= 0)
                {
                    if ((idx + menulist_p->first_disp_idx) != menulist_p->highlighted_idx)
                    {
                        gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);                    
                        
                        if (update_setting)
                        {
                            mmi_camco_setting_set_itemlist_idx(idx + menulist_p->first_disp_idx);
                            mmi_camco_setting_item_hilite_hdlr();
                        }

                        menulist_p->highlighted_idx = (idx + menulist_p->first_disp_idx);

                        mmi_camco_osd_draw_osd();
                        mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_TRUE;
                    #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
                        mmi_camco_reset_preview_terminate_timer();
                    #endif 
                        mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_MOVE;                    
                    }

                }
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_pre_touch[1]) && is_up)
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_PREV)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
                    mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;

                    mmi_camco_osd_touch_menulist_prev_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_PREV;
                }
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_next_touch[1]) && !is_up)
            {
                if (mmi_camco_osd_p->touch_obj != MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_NEXT)
                {
                    gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
                    mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;

                    mmi_camco_osd_touch_menulist_next_cyclic();
                    mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_NEXT;
                }
            }
            else if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_next_touch[1]) ||
                     mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->ad_setting_menu_pre_touch[1]))
            {
                /* wrong dir but not move out */
            }
            else
            {
                /* moved out */
                gui_cancel_timer(mmi_camco_osd_touch_menulist_prev_cyclic);
                gui_cancel_timer(mmi_camco_osd_touch_menulist_next_cyclic);
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L3:
        {
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE:
        {
            if (mmi_camco_osd_touch_hit_test_ext
                (pos.x, pos.y, &mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_region))
            {
                U8 scrolling_unit =
                    (mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[1] -
                     mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[0]) /
                    mmi_camco_osd_p->iconlist.icon_count;
                S32 new_idx = (pos.y - mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[0]) / scrolling_unit;
                MMI_BOOL is_up = (mmi_camco_osd_p->scroll_previous_pos_y > pos.y) ? (MMI_TRUE) : (MMI_FALSE);

                mmi_camco_osd_p->scroll_previous_pos_y = pos.y;

                new_idx = new_idx + mmi_camco_osd_p->scroll_pen_down_diff_idx;
                if (new_idx < 0)
                {
                    new_idx = 0;
                    mmi_camco_osd_p->scroll_pen_down_diff_idx = 0;
                }                    

                if (new_idx >
                    mmi_camco_osd_p->iconlist.icon_count -
                    mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count)
                {
                    new_idx =
                        mmi_camco_osd_p->iconlist.icon_count -
                        mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count;
                    mmi_camco_osd_p->scroll_pen_down_diff_idx = 1 - mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count;
                }

                if (new_idx != mmi_camco_osd_p->iconlist.first_disp_idx)
                {
                    if (new_idx > mmi_camco_osd_p->iconlist.first_disp_idx && !is_up)
                    {
                        mmi_camco_osd_p->iconlist.first_disp_idx = new_idx;

                        if (mmi_camco_osd_p->iconlist.highlighted_idx < mmi_camco_osd_p->iconlist.first_disp_idx)
                        {
                            /* highlight changed */
                            mmi_camco_osd_p->iconlist.highlighted_idx = mmi_camco_osd_p->iconlist.first_disp_idx;

                            mmi_camco_osd_draw_osd();

                            mmi_camco_setting_set_mainlist_idx(mmi_camco_osd_p->iconlist.highlighted_idx);

                            /* gen menulist again */
                            mmi_camco_osd_gen_setting_menulist();

                            gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                        }
                        else
                        {
                            mmi_camco_osd_draw_osd();
                        }
                    }
                    else if (new_idx < mmi_camco_osd_p->iconlist.first_disp_idx && is_up)
                    {
                        /* move prev */
                        mmi_camco_osd_p->iconlist.first_disp_idx = new_idx;

                        if (mmi_camco_osd_p->iconlist.highlighted_idx >=
                            mmi_camco_osd_p->iconlist.first_disp_idx +
                            mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count)
                        {
                            /* highlight changed */
                            mmi_camco_osd_p->iconlist.highlighted_idx =
                                mmi_camco_osd_p->iconlist.first_disp_idx +
                                mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count - 1;

                            mmi_camco_osd_draw_osd();

                            mmi_camco_setting_set_mainlist_idx(mmi_camco_osd_p->iconlist.highlighted_idx);

                            /* gen menulist again */
                            mmi_camco_osd_gen_setting_menulist();

                            gui_cancel_timer(mmi_camco_setting_item_hilite_hdlr);

                        }
                        else
                        {
                            mmi_camco_osd_draw_osd();
                        }

                    }
                }

                mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_ind_y =
                    mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_real_region[0] +
                    scrolling_unit * mmi_camco_osd_p->iconlist.first_disp_idx;

                mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_ind.offset_y =
                    mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_ind_y;
                mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_ind_region.offset_y =
                    mmi_camco_osd_p->advance_setting_screen.Level1_scrolling_bar_ind.offset_y - 5;

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L1_SCROLL_MOVE;

            #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
                mmi_camco_reset_preview_terminate_timer();
            #endif 
            }
            else
            {
                /* mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE; */
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL:
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE:
        {
            if (mmi_camco_osd_touch_hit_test_ext
                (pos.x, pos.y, &mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_region))
            {
                U8 scrolling_unit =
                    (mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[1] -
                     mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[0]) /
                    mmi_camco_osd_p->setting_menulist.item_count;
                S32 new_idx = (pos.y - mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[0]) / scrolling_unit;
                MMI_BOOL is_up = (mmi_camco_osd_p->scroll_previous_pos_y > pos.y) ? (MMI_TRUE) : (MMI_FALSE);

                mmi_camco_osd_p->scroll_previous_pos_y = pos.y;
                new_idx = new_idx + mmi_camco_osd_p->scroll_pen_down_diff_idx;
                if (new_idx < 0)
                {
                    new_idx = 0;
                    mmi_camco_osd_p->scroll_pen_down_diff_idx = 0;
                }
                if (new_idx >
                    mmi_camco_osd_p->setting_menulist.item_count -
                    mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count)
                {
                    new_idx =
                        mmi_camco_osd_p->setting_menulist.item_count -
                        mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count;
                    mmi_camco_osd_p->scroll_pen_down_diff_idx = 1 - mmi_camco_osd_p->advance_setting_screen.Level2_setting_item_count;
                }

                if (new_idx != mmi_camco_osd_p->setting_menulist.first_disp_idx)
                {
                    if (new_idx > mmi_camco_osd_p->setting_menulist.first_disp_idx && !is_up)
                    {
                        mmi_camco_osd_p->setting_menulist.first_disp_idx = new_idx;

                        if (mmi_camco_osd_p->setting_menulist.highlighted_idx <
                            mmi_camco_osd_p->setting_menulist.first_disp_idx)
                        {
                            /* highlight changed */
                            mmi_camco_osd_p->setting_menulist.highlighted_idx =
                                mmi_camco_osd_p->setting_menulist.first_disp_idx;

                            mmi_camco_osd_draw_osd();

                            mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->setting_menulist.highlighted_idx);
                            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

                        }
                        else
                        {
                            mmi_camco_osd_draw_osd();
                        }
                    }
                    else if (new_idx < mmi_camco_osd_p->setting_menulist.first_disp_idx && is_up)
                    {
                        /* move prev */
                        mmi_camco_osd_p->setting_menulist.first_disp_idx = new_idx;

                        if (mmi_camco_osd_p->setting_menulist.highlighted_idx >=
                            mmi_camco_osd_p->setting_menulist.first_disp_idx +
                            mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count)
                        {
                            /* highlight changed */
                            mmi_camco_osd_p->setting_menulist.highlighted_idx =
                                mmi_camco_osd_p->setting_menulist.first_disp_idx +
                                mmi_camco_osd_p->advance_setting_screen.Level1_setting_item_count - 1;

                            mmi_camco_osd_draw_osd();

                            mmi_camco_setting_set_itemlist_idx(mmi_camco_osd_p->setting_menulist.highlighted_idx);
                            gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_setting_item_hilite_hdlr);

                        }
                        else
                        {
                            mmi_camco_osd_draw_osd();
                        }

                    }
                }

                mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_ind_y =
                    mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_real_region[0] +
                    scrolling_unit * mmi_camco_osd_p->setting_menulist.first_disp_idx;

                mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_ind.offset_y =
                    mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_ind_y;
                mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_ind_region.offset_y =
                    mmi_camco_osd_p->advance_setting_screen.Level2_scrolling_bar_ind.offset_y - 5;

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_AD_SETTING_L2_SCROLL_MOVE;
            #ifdef __MMI_CAMCO_FEATURE_PREVIEW_WATCHDOG_TIMEOUT__
                mmi_camco_reset_preview_terminate_timer();
            #endif 
            }
            else
            {
                /* mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE; */
            }
            break;

        }
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_OK:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->advance_setting_screen.OK))
            {
                mmi_camco_osd_p->advance_setting_screen.OK.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();                
            }            
            break;
        }                    
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_CAM_SWTICH:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top))
            {
                mmi_camco_osd_p->rec_direct_setting_screen.switch_mode_top.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();                
            }            
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_REC_SWTICH:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_botton.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();                                
            }            
            break;
        }                 
        /*
        case MMI_CAMCO_OSD_TOUCH_IMG_SELECT_IMG:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->captured_img_select_screen.image_list_touch[mmi_camco_osd_p->captured_img_select_screen.img_list_hilite_idx + mmi_camco_osd_p->captured_img_select_screen.img_select_pos_shift]))
            {
                mmi_camco_osd_p->captured_img_select_screen.img_list_hilite_idx = mmi_camco_osd_p->captured_img_select_screen.img_list_pre_hilite_idx;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        */
        case MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER:
        /*    
        {
            if (mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_usable)
            {
                mmi_camco_osd_cam_direct_setting_struct *scr_p = &mmi_camco_osd_p->cam_direct_setting_screen;

                if (pos.y > scr_p->slider_region.offset_y + scr_p->slider_region.height)
                    scr_p->slider_target_value = scr_p->slider_region.offset_y + scr_p->slider_region.height + 1;
                else
                    scr_p->slider_target_value = pos.y;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER_MOVE;
                gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_osd_slider_update_cyclic);
            }
            else if (mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_usable)
            {
                mmi_camco_osd_rec_direct_setting_struct *scr_p = &mmi_camco_osd_p->rec_direct_setting_screen;

                if (pos.y > scr_p->slider_region.offset_y + scr_p->slider_region.height)
                    scr_p->slider_target_value = scr_p->slider_region.offset_y + scr_p->slider_region.height + 1;
                else
                    scr_p->slider_target_value = pos.y;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER_MOVE;
                gui_start_timer(MMI_CAMCO_OSD_HIITE_HDLR_DELAY_DUR, mmi_camco_osd_slider_update_cyclic);
            }

            break;
        }
        */
        case MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER_MOVE:
        {

            if (mmi_camco_osd_p->cam_direct_setting_screen.slider_region.is_usable)
            {
                double ratio = (((1.0) * (pos.y - mmi_camco_osd_p->cam_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->cam_direct_setting_screen.slider_region.height);
                double rel_pos_y;                    
                U16 zoom_value;
                U16 curr_value = mmi_camco_setting_get_camzoom_step();

                if (mmi_camco_osd_is_horz_UI())
                {  
                    ratio = (((1.0) * (pos.y - mmi_camco_osd_p->cam_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->cam_direct_setting_screen.slider_region.height);                
                }
                else
                {
                    ratio = (((1.0) * (pos.x - mmi_camco_osd_p->cam_direct_setting_screen.slider_region.offset_x)) / mmi_camco_osd_p->cam_direct_setting_screen.slider_region.width);                
                }
                
                if(ratio > 1)
                    ratio = 1;

                if (mmi_camco_osd_is_horz_UI())
                {                  
                    rel_pos_y = (1 - ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);
                }
                else
                {                  
                    rel_pos_y = (ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);
                }                    
                zoom_value = mmi_camco_round(rel_pos_y);

                if (curr_value - zoom_value > 50 || zoom_value - curr_value > 50)
                    break;

                if (zoom_value > mmi_camco_setting_get_camzoom_maxstep())
                    zoom_value = mmi_camco_setting_get_camzoom_maxstep();

                if (zoom_value < mmi_camco_setting_get_camzoom_minstep())
                    zoom_value = mmi_camco_setting_get_camzoom_minstep();

                mmi_camco_setting_set_camzoom_step(zoom_value);
                mdi_camera_update_para_zoom(zoom_value);

                mmi_camco_setting_set_camzoom_value(mmi_camco_update_zoom_factor());

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER_MOVE;
                mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_MOVE;
                mmi_camco_osd_draw_osd();
                    
            }
            else if (mmi_camco_osd_p->rec_direct_setting_screen.slider_region.is_usable)
            {
                double ratio = (((1.0) * (pos.y - mmi_camco_osd_p->rec_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->rec_direct_setting_screen.slider_region.height);
                double rel_pos_y;                    
                U16 zoom_value;
                U16 curr_value = mmi_camco_setting_get_vdozoom_step();

                if (mmi_camco_osd_is_horz_UI())
                {  
                    ratio = (((1.0) * (pos.y - mmi_camco_osd_p->rec_direct_setting_screen.slider_region.offset_y)) / mmi_camco_osd_p->rec_direct_setting_screen.slider_region.height);
                }
                else
                {
                    ratio = (((1.0) * (pos.x - mmi_camco_osd_p->rec_direct_setting_screen.slider_region.offset_x)) / mmi_camco_osd_p->rec_direct_setting_screen.slider_region.width);
                }

                if(ratio > 1)
                    ratio = 1;

                if (mmi_camco_osd_is_horz_UI())
                {                 
                    rel_pos_y = (1 - ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);
                }
                else
                {                 
                    rel_pos_y = (ratio) * (mmi_camco_osd_p->setting_slider.step_count - 1) + (mmi_camco_osd_p->setting_slider.min_value);
                }                    
                zoom_value = mmi_camco_round(rel_pos_y);

                if (curr_value - zoom_value > 50 || zoom_value - curr_value > 50)
                    break;

                if (zoom_value > mmi_camco_setting_get_vdozoom_maxstep())
                    zoom_value = mmi_camco_setting_get_vdozoom_maxstep();

                if (zoom_value < mmi_camco_setting_get_vdozoom_minstep())
                    zoom_value = mmi_camco_setting_get_vdozoom_minstep();

                mmi_camco_setting_set_vdozoom_step(zoom_value);
                mdi_video_rec_update_para_zoom(zoom_value);
                mmi_camco_setting_set_camzoom_value(mmi_camco_update_zoom_factor());

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_DIR_SETTING_SLIDER_MOVE;
                mmi_camco_osd_p->setting_slider.slider_state = MMI_CAMCO_OSD_SLIDER_MOVE;
                mmi_camco_osd_draw_osd();                
            }

            break;
        }
        case MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND:
        case MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND_MOVE:
        {

            if ((mmi_camco_osd_p->osd_state != MMI_CAMCO_OSD_STATE_VIDEO_RECORDING || mmi_camco_osd_p->is_updare_rec_time >= 1 ) && mmi_camco_osd_p->recording_screen.slider_region.is_usable /*mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->recording_screen.slider_region)*/)
            {

                double ratio = (((1.0) * (pos.y - mmi_camco_osd_p->recording_screen.slider_region.offset_y)) / mmi_camco_osd_p->recording_screen.slider_region.height);
                double rel_pos_y;                    
                U16 zoom_value;
                U16 curr_value = mmi_camco_setting_get_vdozoom_step();

                if (mmi_camco_osd_is_horz_UI())
                {  
                    ratio = (((1.0) * (pos.y - mmi_camco_osd_p->recording_screen.slider_region.offset_y)) / mmi_camco_osd_p->recording_screen.slider_region.height);
                }
                else
                {
                    ratio = (((1.0) * (pos.x - mmi_camco_osd_p->recording_screen.slider_region.offset_x)) / mmi_camco_osd_p->recording_screen.slider_region.width);
                }

                if(ratio > 1)
                    ratio = 1;

                if (mmi_camco_osd_is_horz_UI())
                {                 
                    rel_pos_y = (1 - ratio) * (mmi_camco_osd_p->rec_slider.step_count - 1) + (mmi_camco_osd_p->rec_slider.min_value);
                }
                else
                {                 
                    rel_pos_y = (ratio) * (mmi_camco_osd_p->rec_slider.step_count - 1) + (mmi_camco_osd_p->rec_slider.min_value);
                }                    
                zoom_value = mmi_camco_round(rel_pos_y);
                
                if (curr_value - zoom_value > 50 || zoom_value - curr_value > 50)
                    break;

                if (zoom_value > mmi_camco_setting_get_vdozoom_maxstep())
                    zoom_value = mmi_camco_setting_get_vdozoom_maxstep();

                if (zoom_value < mmi_camco_setting_get_vdozoom_minstep())
                    zoom_value = mmi_camco_setting_get_vdozoom_minstep();

                mmi_camco_setting_set_vdozoom_step(zoom_value);
                mdi_video_rec_update_para_zoom(zoom_value);

                mmi_camco_setting_set_vdozoom_value(mmi_camco_update_zoom_factor());

                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_RECORDING_ZOOM_IND_MOVE;
                mmi_camco_osd_p->rec_slider.slider_state = MMI_CAMCO_OSD_SLIDER_MOVE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->is_updare_rec_time --;
            }

            break;
        }
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_LA:
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->add_frame.la_touch))
            {
                gui_cancel_timer(mmi_camco_osd_add_frame_prev_cyclic);
                mmi_camco_osd_p->add_frame.la_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;

        case MMI_CAMCO_OSD_TOUCH_ADD_FRAME_RA:
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->add_frame.ra_touch))
            {
                gui_cancel_timer(mmi_camco_osd_add_frame_next_cyclic);
                mmi_camco_osd_p->add_frame.ra_touch.is_press = MMI_FALSE;

                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
    #ifdef __MMI_CAMCO_FEATURE_OSD_PANORAMA__
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_UA:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->panorama.ua_touch))
            {
                mmi_camco_osd_panorama_direct_up_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_DA:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->panorama.da_touch))
            {
                mmi_camco_osd_panorama_direct_down_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_LA:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->panorama.la_touch))
            {
                mmi_camco_osd_panorama_direct_left_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_PANORAMA_RA:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->panorama.ra_touch))
            {
                mmi_camco_osd_panorama_direct_right_release();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
    #endif /* __MMI_CAMCO_FEATURE_OSD_PANORAMA__ */ 
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SENSOR_SWITCHER:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->sensor_switcher))
            {
                mmi_camco_osd_p->sensor_switcher.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }    
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_SCN:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.scene_mode))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.scene_mode.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_FLASH:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.flash))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.flash.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.zoom))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.zoom.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_CAPMODE:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.capmode))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.capmode.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_AD_SETTING:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.ad_setting))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_BACK:         
        {
            if(mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.setting_wnd_body))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_PREVIEW_BACK:            
        {
            if(!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.back))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }        
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ZOOM_BACK:
        {
            if(mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.zoom_region) )
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }            
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_IMGVIEWER:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.imgviewer))
            {
                mmi_camco_osd_p->cam_direct_setting_screen.imgviewer.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM1:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM2:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM3:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM4:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM5:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM6:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM7:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM8:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM9:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM10:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM11:
        case MMI_CAMCO_OSD_TOUCH_CAM_DIR_SETTING_ITEM12:            
        {
            /*
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, mmi_camco_osd_p->cam_current_dir_setting_item))
            {
                mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            */
            U8 i;

            for (i = 0; i < mmi_camco_osd_p->active_tbl->real_number; i++)
            {
                if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->active_setting_item[i]))
                {
                    mmi_camco_osd_p->touch_obj = mmi_camco_osd_touch_translate_idx_to_object(i);
                    if (i != mmi_camco_osd_p->setting_menulist.highlighted_idx)
                    {
                        mmi_camco_osd_p->setting_menulist.highlighted_idx = i;
                        mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_TRUE;
                    }
                    mmi_camco_osd_p->touch_obj = mmi_camco_osd_touch_translate_idx_to_object(i);                    
                    break;
                }
            }
            if (i != mmi_camco_osd_p->setting_menulist.item_count)
                mmi_camco_osd_draw_osd();          
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_SCN:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.scene_mode))
            {
                mmi_camco_osd_p->rec_direct_setting_screen.scene_mode.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.zoom))
            {
                mmi_camco_osd_p->rec_direct_setting_screen.zoom.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_AD_SETTING:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.ad_setting))
            {
                mmi_camco_osd_p->rec_direct_setting_screen.ad_setting.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_BACK:       
        {
            if(mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.setting_wnd_body))
            {
                mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_PREVIEW_BACK:            
        {
            if(!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.back))
            {
                mmi_camco_osd_p->rec_direct_setting_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }        
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ZOOM_BACK:
        {
            if(mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.zoom_region) )
            {
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }        
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ALLVIDEOS:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->rec_direct_setting_screen.allvideos))
            {
                mmi_camco_osd_p->rec_direct_setting_screen.allvideos.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }

        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM1:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM2:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM3:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM4:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM5:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM6:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM7:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM8:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM9:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM10:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM11:
        case MMI_CAMCO_OSD_TOUCH_REC_DIR_SETTING_ITEM12:            
        {
            /*
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, mmi_camco_osd_p->rec_current_dir_setting_item))
            {
                mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            */
            U8 i;
            for (i = 0; i < mmi_camco_osd_p->active_tbl->real_number; i++)
            {
                if (mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->active_setting_item[i]))
                {
                    mmi_camco_osd_p->touch_obj = mmi_camco_osd_touch_translate_idx_to_object(i);
                    if (i != mmi_camco_osd_p->setting_menulist.highlighted_idx)
                    {
                        mmi_camco_osd_p->setting_menulist.highlighted_idx = i;
                        mmi_camco_osd_p->setting_menulist.highlight_change_flag = MMI_TRUE;
                    }
                    mmi_camco_osd_p->touch_obj = mmi_camco_osd_touch_translate_idx_to_object(i);
                    break;
                }
            }
            if (i != mmi_camco_osd_p->setting_menulist.item_count)
                mmi_camco_osd_draw_osd();            
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_AD_SETTING_BACK:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->advance_setting_screen.back))
            {
                mmi_camco_osd_p->advance_setting_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMG_SELECT_BACK:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_img_select_screen.back))
            {
                mmi_camco_osd_p->captured_img_select_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_AP:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_img_select_screen.tool_bar[0]))
            {
                mmi_camco_osd_p->captured_img_select_screen.tool_bar[0].is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_DELETE:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_img_select_screen.save))
            {
                mmi_camco_osd_p->captured_img_select_screen.tool_bar[1].is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_SAVE:
        {
            if (!mmi_camco_osd_touch_hit_test(pos.x, pos.y, &mmi_camco_osd_p->captured_img_select_screen.save))
            {
                mmi_camco_osd_p->captured_img_select_screen.save.is_press = MMI_FALSE;
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
                mmi_camco_osd_draw_osd();                
            }            
            break;
        }         
        case MMI_CAMCO_OSD_TOUCH_IMG_SELECT_TOOL_BAR_ITEM_FORWARD:
        {
            if (!mmi_camco_osd_touch_hit_test_ext
                (pos.x, pos.y, &mmi_camco_osd_p->captured_img_select_screen.tool_bar[2]))
            {
                mmi_camco_osd_p->captured_img_select_screen.tool_bar[2].is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAPTURED_BACK:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_screen.back))
            {
                mmi_camco_osd_p->captured_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_AP:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_screen.tool_bar[0]))
            {
                mmi_camco_osd_p->captured_screen.tool_bar[0].is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_DELETE:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_screen.tool_bar[1]))
            {
                mmi_camco_osd_p->captured_screen.tool_bar[1].is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CAPTURED_TOOL_BAR_ITEM_FORWARD:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_screen.tool_bar[2]))
            {
                mmi_camco_osd_p->captured_screen.tool_bar[2].is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_BT:
        case MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_MMS:            
        case MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_EMAIL:            
        {
            U8 i;
            for(i=0; i < 3; i++)
            {
                if (mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->forward_screen.item[i]))
                {
                    if(mmi_camco_osd_p->fw_option_idx_lookup_table[i] != mmi_camco_osd_p->option_menulist.highlighted_idx)
                    {
                        mmi_camco_osd_set_fw_hilite_idx(mmi_camco_osd_p->fw_option_idx_lookup_table[i]);
                        mmi_camco_osd_p->forward_screen.highlite_change_flag = MMI_TRUE;                                
                    }   
                    mmi_camco_osd_p->touch_obj = mmi_camco_osd_touch_translate_idx_to_object(i);                        
                    break;    
                }            
            }
            if(i < 3)
            {
                mmi_camco_osd_draw_osd();            
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_FORWARD_OPTION_BACK:
        {
            if (mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->forward_screen.confirm_body))
            {
                mmi_camco_osd_p->forward_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CONFIRM_YES:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->confirm_screen.confirm_lsk))
            {
                mmi_camco_osd_p->confirm_screen.confirm_lsk.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_CONFIRM_NO:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->confirm_screen.confirm_rsk))
            {
                mmi_camco_osd_p->confirm_screen.confirm_rsk.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_RECORDING_STOP:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->recording_screen.stop))
            {
                mmi_camco_osd_p->recording_screen.stop.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_RECORDING_PAUSE_RESUME:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->recording_screen.start))
            {
                mmi_camco_osd_p->recording_screen.start.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }
        case MMI_CAMCO_OSD_TOUCH_HINT_BACK:
        {
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->captured_screen.back))
            {
                mmi_camco_osd_p->captured_screen.back.is_press = MMI_FALSE;
                mmi_camco_osd_draw_osd();
                mmi_camco_osd_p->touch_obj = MMI_CAMCO_OSD_TOUCH_NONE;
            }
            break;
        }

    }
    if(mmi_camco_osd_p->is_capturing)
    {    	
        if (mmi_camco_osd_p->osd_state == MMI_CAMCO_OSD_STATE_CAMERA_CONTSHOT)
        {        	
            if (!mmi_camco_osd_touch_hit_test_ext(pos.x, pos.y, &mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top))
            {            	        
                mmi_camco_osd_p->cam_direct_setting_screen.switch_mode_top.is_press = MMI_FALSE;
                mmi_camco_osd_p->is_capturing = MMI_FALSE;                
                SEND_EVT(MMI_CAMCO_EVT_CAPTURE, NULL);                                    
            }      
        }    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_hit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_x           [IN]        
 *  pos_y           [IN]        
 *  touch_obj       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_camco_osd_touch_hit_test(S32 pos_x, S32 pos_y, mmi_camco_osd_touch_obj_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_TOUCH_EXTEND_RANGE 5

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!touch_obj->is_usable)
    {
        return MMI_FALSE;
    }

    if (touch_obj->width <= 0 || touch_obj->height <= 0)
    {
        return MMI_FALSE;
    }

    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_not_hit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_x           [IN]        
 *  pos_y           [IN]        
 *  touch_obj       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_camco_osd_touch_not_hit_test(S32 pos_x, S32 pos_y, mmi_camco_osd_touch_obj_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_TOUCH_EXTEND_RANGE 5

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!touch_obj->is_usable)
    {
        return MMI_TRUE;
    }

    if (touch_obj->width <= 0 || touch_obj->height <= 0)
    {
        return MMI_TRUE;
    }

    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_touch_hit_test_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos_x           [IN]        
 *  pos_y           [IN]        
 *  touch_obj       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_camco_osd_touch_hit_test_ext(S32 pos_x, S32 pos_y, mmi_camco_osd_touch_obj_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_OSD_TOUCH_EXTEND_RANGE 5

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!touch_obj->is_usable)
    {
        return MMI_FALSE;
    }

    if (touch_obj->width <= 0 || touch_obj->height <= 0)
    {
        return MMI_FALSE;
    }

    if ((pos_x >= touch_obj->offset_x - MMI_CAMCO_OSD_TOUCH_EXTEND_RANGE) &&
        (pos_x < touch_obj->offset_x + touch_obj->width + MMI_CAMCO_OSD_TOUCH_EXTEND_RANGE) &&
        (pos_y >= touch_obj->offset_y - MMI_CAMCO_OSD_TOUCH_EXTEND_RANGE) &&
        (pos_y < touch_obj->offset_y + touch_obj->height + MMI_CAMCO_OSD_TOUCH_EXTEND_RANGE))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_sublcd_blt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_camco_osd_sublcd_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt_previous(0, 0, mmi_camco_osd_p->sublcd_osd_width - 1, mmi_camco_osd_p->sublcd_osd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_sublcd_bg_black
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_sublcd_bg_black(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(mmi_camco_osd_p->sublcd_base_layer_h);
    gdi_layer_resize(SUBLCD_WIDTH, SUBLCD_HEIGHT);
    gdi_layer_set_position(0, 0);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_osd_set_sublcd_base_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  layer_h     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_osd_set_sublcd_base_layer(gdi_handle layer_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_base_layer_h = layer_h;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_set_center_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sublcd_osd_set_center_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_center_hint.str_ptr = str_ptr;
    gui_measure_string((UI_string_type) mmi_camco_osd_p->sublcd_center_hint.str_ptr, &str_width, &str_height);

    mmi_camco_osd_p->sublcd_center_hint.offset_x = (mmi_camco_osd_p->sublcd_osd_width - str_width) >> 1;
    mmi_camco_osd_p->sublcd_center_hint.offset_y = (mmi_camco_osd_p->sublcd_osd_height - str_height) >> 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_set_center_processing_hint_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sublcd_osd_set_center_processing_hint_str(CHAR *str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_center_hint.is_processing = MMI_TRUE;
    mmi_camco_sublcd_osd_set_center_hint_str(str_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_draw_hint_process_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sublcd_osd_draw_hint_process_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_osd_p->sublcd_center_hint.dot_count++;

    if (mmi_camco_osd_p->sublcd_center_hint.dot_count > MMI_CAMCO_OSD_MAX_HINT_DOT_COUNT)
    {
        mmi_camco_osd_p->sublcd_center_hint.dot_count = 0;
    }

    mmi_camco_osd_draw_osd();

    gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_sublcd_osd_draw_hint_process_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sublcd_osd_draw_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sublcd_osd_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MMI_CAMCO_SUBLCD_OSD_TMP_BUF_LEN (80)

    S32 i;
    CHAR  str_buf[MMI_CAMCO_SUBLCD_OSD_TMP_BUF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(&MMI_medium_font);

    if (mmi_camco_osd_p->sublcd_center_hint.str_ptr != NULL)
    {
        gui_set_text_color(mmi_camco_osd_p->text_color);
        gui_set_text_border_color(mmi_camco_osd_p->text_border_color);

        memset(str_buf, 0, MMI_CAMCO_SUBLCD_OSD_TMP_BUF_LEN);

        mmi_ucs2cpy(str_buf, (CHAR *) mmi_camco_osd_p->sublcd_center_hint.str_ptr);

        for (i = 0; i < mmi_camco_osd_p->sublcd_center_hint.dot_count; i++)
        {
            mmi_ucs2cat(str_buf, (CHAR *) (L"."));
        }

        gui_move_text_cursor(
            mmi_camco_osd_p->sublcd_center_hint.offset_x,
            mmi_camco_osd_p->sublcd_center_hint.offset_y);

        gui_print_bordered_text((UI_string_type) str_buf);

        if (mmi_camco_osd_p->sublcd_center_hint.is_processing)
        {
            gui_start_timer(MMI_CAMCO_OSD_HINT_PROCESS_DUR, mmi_camco_sublcd_osd_draw_hint_process_cyclic);
        }

    }

}

#endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 

#endif /* __MMI_CAMCO_FTE__ */ 

#endif /* __MMI_CAMCORDER__ */ 

#endif /* MMI_CAMCOFTEOSD_C */ /* MMI_CAMCOOSD_C */

