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
 *   SyncMLDevice.res
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource XML file
 *
 * Author:
 * -------
 *   Feng mtk81063
 *
 *******************************************************************************/

#include "mmi_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_SYNCML"

#ifdef __SYNCML_SUPPORT__

#if defined(__MMI_APP_MANAGER_SUPPORT__)

#ifdef __MMI_SYNCML_DEVICE_SYNC__
	package_name = "native.mtk.syncmldevice"
	name = "@OID:STR_ID_SYNC_DEV_MAIN"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON 		
	img = "IMG_SYNC_DEVICE_ICON_FOR_COSMOS_ID"
#endif	
	hidden_in_mainmenu = "false"
	launch = "mmi_syncml_device_sync_launch"
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#endif/*__MMI_APP_MANAGER_SUPPORT__*/

#endif  /*__SYNCML_SUPPORT__ */
>

#ifdef __SYNCML_SUPPORT__

    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

    <!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Image Resource Area-->
#if defined(__MMI_APP_MANAGER_SUPPORT__)	
    #if defined(__MMI_SYNCML_DEVICE_SYNC__)
    #if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON 	
    <IMAGE id="IMG_SYNC_DEVICE_ICON_FOR_COSMOS_ID"> CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\sync_device.png"</IMAGE>
    #endif    
    #endif
#endif
  <!--End Image Resource Area-->
	<!--End Image Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Audio Resource Area-->
	<!--Audio Resource Area-->
	<!--End Audio Resource Area-->
	<!--End Audio Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Media Resource Area-->
	<!--Media Resource Area-->
	<!--End Media Resource Area-->
	<!--End Media Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Screen ID Area-->
	<!--Screen ID Area-->
    
	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->

	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->

    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    
#endif  /*__SYNCML_SUPPORT__ */

</APP>



