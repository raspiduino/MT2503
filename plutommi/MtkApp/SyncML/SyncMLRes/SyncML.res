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
 *   syncml.res
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
 *   Jinchuan Gou mtk80241
 *
 *******************************************************************************/

#include "mmi_features.h"
#include "CustResDef.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_SYNCML"

#ifdef __SYNCML_SUPPORT__

#if defined(__MMI_APP_MANAGER_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__)

	package_name = "native.mtk.syncmlremote"
	name = "STR_ID_SYNC_MENU"
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON 	
	img = "IMG_SYNC_REMOTE_ICON_FOR_COSMOS_ID"
#endif
	hidden_in_mainmenu = "false"
	launch = "mmi_syncml_launch"

#endif/*__MMI_APP_MANAGER_SUPPORT__*/

#endif  /*__SYNCML_SUPPORT__ */
>

#ifdef __SYNCML_SUPPORT__

    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
    <!--sync menu string-->
    <STRING id = "STR_ID_SYNC_APP"/> 
    <STRING id = "STR_ID_SYNC_MENU"/>  

    <STRING id = "STR_ID_SYNC_MENU_SHORT_FORM"/>
    <STRING id = "STR_ID_SYNC_NOW"/>
    <STRING id = "STR_ID_SYNC_SETTINGS"/>
    <STRING id = "STR_ID_SYNC_PROFILE_NAME"/>
    <STRING id = "STR_ID_SYNC_DATABASE_SETTING"/>
    
    <STRING id = "STR_ID_SYNC_PROFILE_ID1"/>      
    <STRING id = "STR_ID_SYNC_PROFILE_ID2"/>      
    <STRING id = "STR_ID_SYNC_PROFILE_ID3"/>  

    <!-- register app_id for three sync account -->
    <STRING id = "STR_ID_SYNC_APP_ID1"/>    
    <STRING id = "STR_ID_SYNC_APP_ID2"/>  
    <STRING id = "STR_ID_SYNC_APP_ID3"/>
    
    <STRING id = "STR_ID_SYNC_APPLICATIONS"/> 
    <STRING id = "STR_ID_SYNC_SETTING_CONFLICT"/>
    <STRING id = "STR_ID_SYNC_ACCOUNT_EDIT"/>
    <STRING id = "STR_ID_SYNC_NO_SERVER_ADDR"/>
    <STRING id = "STR_ID_SYNC_EDIT_SERVER_ADDR_QUREY"/>
    <STRING id = "STR_ID_SYNC_EDIT_DATA_ACCOUNT_QUREY"/>
    
    <STRING id = "STR_ID_SYNC_PROFILE"/>
    <STRING id = "STR_ID_SYNC_NO_CONTACT_ADDR"/>
    <STRING id = "STR_ID_SYNC_EDIT_CONTACT_ADDR_QUREY"/>
    <STRING id = "STR_ID_SYNC_NO_CAL_ADDR"/>
    <STRING id = "STR_ID_SYNC_EDIT_CAL_ADDR_QUREY"/>
    <STRING id = "STR_ID_SYNC_NO_TASK_ADDR"/>
    <STRING id = "STR_ID_SYNC_EDIT_TASK_ADDR_QUREY"/>
    <STRING id = "STR_ID_SYNC_NO_NOTE_ADDR"/>
    <STRING id = "STR_ID_SYNC_EDIT_NOTE_ADDR_QUREY"/>
    <STRING id = "STR_ID_SYNC_NO_BKM_ADDR"/>
    <STRING id = "STR_ID_SYNC_EDIT_BKM_ADDR_QUREY"/>
    <STRING id = "STR_ID_SYNC_NO_EAMIL_ADDR"/>
    <STRING id = "STR_ID_SYNC_EDIT_EAMIL_ADDR_QUREY"/>
    
    <STRING id = "STR_ID_SYNC_ADDED"/>
    <STRING id = "STR_ID_SYNC_DELETED"/>
    <STRING id = "STR_ID_SYNC_REPLACED"/>
    <STRING id = "STR_ID_SYNC_MOVED"/>
    <STRING id = "STR_ID_SYNC_ERROR"/>

    <STRING id = "STR_ID_SYNC_PROGRESS"/>
    <STRING id = "STR_ID_SYNC_NO_PROFILE"/>
    <STRING id = "STR_ID_SYNC_EDIT_QUREY"/>
    <STRING id = "STR_ID_SYNC_NO_APPLICATION"/>     
    <STRING id = "STR_ID_SYNC_EDIT_APP_TO_SYNC_QUREY"/>

    <STRING id = "STR_ID_SYNC_REGULARITY"/>
    <STRING id = "STR_ID_SYNC_PROFILE_SERVER"/> 
    <STRING id = "STR_ID_SYNC_PROFILE_CONNECTION_TYPE"/> 
    <STRING id = "STR_ID_SYNC_PROFILE_CONNECTION"/>

	<!--Notice: Order is fixed, compile option is mandatory-->
    <STRING id = "STR_ID_SYNC_REGULARITY_NONE"/>   
#ifdef __MMI_SYNCML_VF_DATA_CHANGE_SYNC__
    <STRING id = "STR_ID_SYNC_REGULARITY_DATA"/>  
#endif 
    <STRING id = "STR_ID_SYNC_REGULARITY_POWERON"/>
    <STRING id = "STR_ID_SYNC_REGULARITY_DAY"/>    
    <STRING id = "STR_ID_SYNC_REGULARITY_WEEK"/>   
    <STRING id = "STR_ID_SYNC_REGULARITY_MONTH"/>  
	<!--End-->

    <STRING id = "STR_ID_SYNC_BEARER"/>            
    <STRING id = "STR_ID_SYNC_BEARER_USB"/>        
    <STRING id = "STR_ID_SYNC_BEARER_BT"/>         
    <STRING id = "STR_ID_SYNC_BEARER_IRDA"/>       
    
    <STRING id = "STR_ID_SYNC_ALARM_EXPIRED_QUERY"/>
    <STRING id = "STR_ID_SYNC_POWER_ON_QUERY"/>     
    <STRING id = "STR_ID_SYNC_DATA_CHANGED_QUERY"/> 

#if defined(__MMI_SYNCML_REFRESH_SYNC_SUPPORT__) || defined(__MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__)
    <STRING id = "STR_ID_SYNC_TYPE"/> 
    <STRING id = "STR_ID_SYNC_SAS"/> 
	<!--Notice: Order is fixed-->	
    <STRING id = "STR_ID_SYNC_TWOWAY"/>            
    <STRING id = "STR_ID_SYNC_BACKUP"/>            
    <STRING id = "STR_ID_SYNC_RESTORE"/>           
    <STRING id = "STR_ID_SYNC_EXPORT"/>            
    <STRING id = "STR_ID_SYNC_IMPORT"/>   
#endif /* __MMI_SYNCML_REFRESH_SYNC_SUPPORT__ */

    <STRING id = "STR_ID_SYNC_BACKUP_WARNING"/>    
    <STRING id = "STR_ID_SYNC_RESTORE_WARNING"/>    

	<!--Notice: Order is fixed, compile option is mandatory-->
    <STRING id = "STR_ID_SYNC_APP_PHB"/>           
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    <STRING id = "STR_ID_SYNC_APP_CAL"/>           
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    <STRING id = "STR_ID_SYNC_APP_TASK"/>          
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    <STRING id = "STR_ID_SYNC_APP_NOTE"/>         
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
    <STRING id = "STR_ID_SYNC_APP_BKM"/>   
#endif 
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
	<STRING id = "STR_ID_SYNC_APP_EMIAL"/>   
#endif
	<!--End-->
	
    <STRING id = "STR_ID_SYNC_SERVER_ADDRESS"/>    
    <STRING id = "STR_ID_SYNC_DATABASE_ADDRESS_1"/>
    <STRING id = "STR_ID_SYNC_DATABASE_ADDRESS"/> 

    <STRING id = "STR_ID_SYNC_HINT_PHB_ONLY"/>     
    <STRING id = "STR_ID_SYNC_HINT_TDL_ONLY"/>     
    <STRING id = "STR_ID_SYNC_HINT_CAL_ONLY"/>     
    <STRING id = "STR_ID_SYNC_HINT_TASK_ONLY"/>
    <STRING id = "STR_ID_SYNC_HINT_PHB_TDL_ONLY"/>
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
    <STRING id = "STR_ID_SYNC_HINT_BKM_ONLY"/>     
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
    <STRING id = "STR_ID_SYNC_PROXY_USAGE"/>       
    <STRING id = "STR_ID_SYNC_PROXY_SERVER"/>      
    <STRING id = "STR_ID_SYNC_PROXY_PORT"/>        
    <STRING id = "STR_ID_SYNC_PHB_BUSY"/>          
    <STRING id = "STR_ID_SYNC_INCOMPLETE_PROFILE"/>
    <STRING id = "STR_ID_SYNC_APP_SETTING_UNMATCHABLE"/>
    <STRING id = "STR_ID_SYNC_MINIMIZE"/>           
    <STRING id = "STR_ID_SYNC_ABORT_SYNC_QUERY"/>   
    <STRING id = "STR_ID_SYNC_PLEASE_WAIT"/>        
    <STRING id = "STR_ID_SYNC_WAP_NOT_READY"/>      
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
    <STRING id = "STR_ID_SYNC_EMAIL_BUSY"/>         
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    <!--Syncing progress string-->
    <STRING id = "STR_ID_SYNC_INVALID_CREDENTIAL"/> 
    <STRING id = "STR_ID_SYNC_MISSING_CREDENTIAL"/> 
    <STRING id = "STR_ID_SYNC_PAYMENT_REQUIRED"/>   
    <STRING id = "STR_ID_SYNC_DONE"/>               
    <STRING id = "STR_ID_SYNC_FAIL"/>               
    <STRING id = "STR_ID_SYNC_LOCALDB_FULL"/>       
    <STRING id = "STR_ID_SYNC_CODE_FORBIDDEN"/>     
    <STRING id = "STR_ID_SYNC_INCOMPLETE_CMD"/>     
    <STRING id = "STR_ID_SYNC_SVR_DEVICE_FULL"/>    
    <STRING id = "STR_ID_SYNC_SERVICE_UNAVAILABLE"/>
    <STRING id = "STR_ID_SYNC_DATASTORE_FAIL"/>     
    <STRING id = "STR_ID_SYNC_SVR_FAIL"/>           
    <STRING id = "STR_ID_SYNC_ERR_OCCUR"/>          
    <STRING id = "STR_ID_SYNC_PROTOCOL_UNSUPPORT"/>         
    <STRING id = "STR_ID_SYNC_DEFAULT_FAIL"/>                
    <STRING id = "STR_ID_SYNC_CANCELLED"/>   

	<!--Notice: Order is fixed, compile option is mandatory-->
    <STRING id = "STR_ID_PROGRESS_LINK_ESTABLISHED"/>           
    <STRING id = "STR_ID_PROGRESS_LINK_DISCONNECTED"/>          
    <STRING id = "STR_ID_PROGRESS_RX_FAILED"/>                  
    <STRING id = "STR_ID_PROGRESS_TX_FAILED"/>                  
    <STRING id = "STR_ID_PROGRESS_LINK_REDIRECTED"/>            
    <STRING id = "STR_ID_PROGRESS_SESSION_DONE"/>               

    <STRING id = "STR_ID_PROGRESS_CONTACT_DATASTORE_SENDING"/>  
    <STRING id = "STR_ID_PROGRESS_CONTACT_DATASTORE_RECEIVED"/> 
    <STRING id = "STR_ID_PROGRESS_CONTACT_DATASTORE_DONE"/>     
    <STRING id = "STR_ID_PROGRESS_CONTACT_DATASTORE_FAILED"/>   
    <STRING id = "STR_ID_PROGRESS_CONTACT_DATASTORE_UPDATING"/>
    
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_SENDING"/>     
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_RECEIVED"/>    
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_DONE"/>        
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_FAILED"/>      
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_UPDATING"/>    
#else /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ only for generate a string id, save resource*/
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_SENDING_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_RECEIVED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_DONE_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_FAILED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_CAL_DATASTORE_UPDATING_DUMMY"/>
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_SENDING"/>    
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_RECEIVED"/>   
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_DONE"/>       
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_FAILED"/>     
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_UPDATING"/>   
#else /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_SENDING_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_RECEIVED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_DONE_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_FAILED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_TASK_DATASTORE_UPDATING_DUMMY"/>
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_SENDING"/>    
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_RECEIVED"/>   
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_DONE"/>       
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_FAILED"/>     
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_UPDATING"/>   
#else /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_SENDING_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_RECEIVED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_DONE_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_FAILED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_NOTE_DATASTORE_UPDATING_DUMMY"/>
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_SENDING"/> 
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_UPDATING"/>
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_FAILED"/>  
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_DONE"/>    
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_RECEIVED"/>
#else /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_SENDING_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_UPDATING_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_FAILED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_DONE_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_BOOKMARK_DATASTORE_RECEIVED_DUMMY"/>
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_SENDING"/>   
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_RECEIVED"/>  
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_DONE"/>      
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_FAILED"/>    
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_UPDATING"/>  
#else /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_SENDING_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_RECEIVED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_DONE_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_FAILED_DUMMY"/>
    <STRING id = "STR_ID_PROGRESS_EMAIL_DATASTORE_UPDATING_DUMMY"/>
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
	  <!--End-->

    <STRING id = "STR_ID_SYNC_REPORT"/>         
    <STRING id = "STR_ID_SYNC_REPORT_CON_OK"/>  
    <STRING id = "STR_ID_SYNC_REPORT_CON_NG"/>  
    <STRING id = "STR_ID_SYNC_REPORT_CON_CK"/>  
    <STRING id = "STR_ID_SYNC_REPORT_CON_NO"/>  

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    <STRING id = "STR_ID_SYNC_REPORT_CAL_NO"/>  
    <STRING id = "STR_ID_SYNC_REPORT_CAL_CK"/>  
    <STRING id = "STR_ID_SYNC_REPORT_CAL_NG"/>  
    <STRING id = "STR_ID_SYNC_REPORT_CAL_OK"/>  
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    <STRING id = "STR_ID_SYNC_REPORT_TASK_OK"/>   
    <STRING id = "STR_ID_SYNC_REPORT_TASK_NO"/>   
    <STRING id = "STR_ID_SYNC_REPORT_TASK_NG"/>   
    <STRING id = "STR_ID_SYNC_REPORT_TASK_CK"/>   
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    <STRING id = "STR_ID_SYNC_REPORT_NOTE_OK"/>   
    <STRING id = "STR_ID_SYNC_REPORT_NOTE_NO"/>   
    <STRING id = "STR_ID_SYNC_REPORT_NOTE_NG"/>   
    <STRING id = "STR_ID_SYNC_REPORT_NOTE_CK"/>   
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
    <STRING id = "STR_ID_SYNC_REPORT_BKM_NO"/>    
    <STRING id = "STR_ID_SYNC_REPORT_BKM_CK"/>    
    <STRING id = "STR_ID_SYNC_REPORT_BKM_NG"/>    
    <STRING id = "STR_ID_SYNC_REPORT_BKM_OK"/>    
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
    <STRING id = "STR_ID_SYNC_REPORT_EMAIL_OK"/>  
    <STRING id = "STR_ID_SYNC_REPORT_EMAIL_NG"/>  
    <STRING id = "STR_ID_SYNC_REPORT_EMAIL_CK"/>  
#endif  /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

    <STRING id = "STR_ID_SYNC_REPORT_SERVER"/>    
    <STRING id = "STR_ID_SYNC_REPORT_CLIENT"/>    
    <STRING id = "STR_ID_SYNC_REPORT_NO_SYNC_TATA"/> 
    <STRING id = "STR_ID_SYNC_INVALID_DATA_ACCOUNT"/>        

    <STRING id = "STR_ID_SYNC_PROFILE_DEACTIVATED"/>
    <STRING id = "STR_ID_SYNC_NO_PROF_REPLACE"/>  
    
    <STRING id = "STR_ID_SYNC_CONN_TYPE"/> 
    <STRING id = "STR_ID_SYNC_CONN_INTERNET"/> 
    <STRING id = "STR_ID_SYNC_CONN_BT"/>         
	<STRING id = "STR_ID_SYNC_CONN_BT_BUSY"/>        
    <STRING id = "STR_ID_SYNC_INVALID_PORT_INPUT"/>    
    <STRING id = "STR_ID_SYNC_INVALID_IP_INPUT"/>      
    <STRING id = "STR_ID_SYNC_INVALID_SERVER_INPUT"/>  
    <STRING id = "STR_ID_SYNC_APP_SYNC_UNAVAILABLE"/>    

    <STRING id = "STR_ID_SYNCML_COLON"/>            
    <STRING id = "STR_ID_SYNCML_QUETION_MARK"/>     
    <STRING id = "STR_ID_SYNC_COMMA"/>

    <STRING id = "STR_ID_SYNC_RESET_LOG_ASK"/>      
    <STRING id = "STR_ID_SYNC_SYNC_LOG"/>           

#ifdef __MMI_SYNCML_CCA_SUPPORT__
    <STRING id = "STR_ID_SYNC_REPLACE_CONFIRM"/>      
    <STRING id = "STR_ID_SYNC_ERROR_PROFILE_IN_USE"/> 
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
    <STRING id = "STR_ID_SYNC_SAS_NOTIFICATION"/>    
    <STRING id = "STR_ID_SYNC_SAS_CONTEXT_1"/>       
    <STRING id = "STR_ID_SYNC_SAS_CONTEXT_2"/>       
    <STRING id = "STR_ID_SYNC_SAS_PROCESSING"/>      
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    <STRING id = "STR_ID_SYNC_APP_SYNC_SETTING_PROMPT"/> 
#endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */

#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
    <STRING id = "STR_ID_SYNC_DEV_CONN_ACCEPT_ASK"/> 
    <STRING id = "STR_ID_SYNC_DEV_CONN_ACCEPT_ASK_UPPER"/> 
    <STRING id = "STR_ID_SYNC_DEV_SYNC_ACCEPT_ASK"/>
    <STRING id = "STR_ID_SYNC_DEV_SYNC_ACCEPT_ASK_UPPER"/>
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) */

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    <STRING id = "STR_ID_SYNC_DEV_MAIN"/>
    <STRING id = "STR_ID_SYNC_DEV_SYNC"/>
    <STRING id = "STR_ID_SYNC_DEV_PHONES"/>
    <STRING id = "STR_ID_SYNC_DEV_LOCAL"/>
    <STRING id = "STR_ID_SYNC_DEV_REMOTE"/>
    <STRING id = "STR_ID_SYNC_DEV_FORBIDE"/>
    <STRING id = "STR_ID_SYNC_DEV_INVALID"/>
    <STRING id = "STR_ID_SYNC_PHONE_LIST_FULL"/>
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

    <STRING id = "STR_ID_SYNC_END"/>
    <!--End String Resource Area-->
    <!--End String Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Image Resource Area-->
	<!--Image Resource Area-->
    <IMAGE id = "IMG_ID_SYNC_MENU">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SyncML\\\\SML_Sync.bmp"</IMAGE>
    
#if defined(__MMI_APP_MANAGER_SUPPORT__) && !defined(__MMI_OP01_SYNCML_SETTING__)    
#if defined(__MMI_VUI_LAUNCHER__) || defined(__MMI_MAINMENU_SPREAD_SUPPORT__) //MM_ICON 	
	<IMAGE id="IMG_SYNC_REMOTE_ICON_FOR_COSMOS_ID"> CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Sync.png"</IMAGE>
#endif  
#endif
    
#ifdef __MMI_MAINLCD_128X128__    
    <IMAGE id = "IMG_ID_SYNC_NOW">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SyncML\\\\Synchronzing.gif"</IMAGE>
#else
    <IMAGE id = "IMG_ID_SYNC_NOW">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SyncML\\\\Synchronzing"</IMAGE>
#endif

    <IMAGE id = "IMG_ID_SYNC_SETTINGS">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Services\\\\SyncML\\\\SML_SyncSet.bmp"</IMAGE>

    <IMAGE id = "IMG_ID_SYNC_SYNC_LOG">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_VIEWLOG.bmp"</IMAGE>

    <IMAGE id = "IMG_ID_SYNC_CONTACT">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_PHONEBOOK.bmp"</IMAGE>
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__	
    <IMAGE id = "IMG_ID_SYNC_CALENDAR">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_CALENDAR.bmp"</IMAGE>
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    <IMAGE id = "IMG_ID_SYNC_TASK">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_TODOLIST.bmp"</IMAGE>
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    <IMAGE id = "IMG_ID_SYNC_NOTE">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_NOTES.bmp"</IMAGE>
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
    <IMAGE id = "IMG_ID_SYNC_BOOKMARK">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_BOOKMARK.bmp"</IMAGE>
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ 
    <IMAGE id = "IMG_ID_SYNC_EMAIL">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\SyncML\\\\SML_EMAIL.bmp"</IMAGE>
#endif 
    <IMAGE id = "IMG_ID_SYNC_SERVER">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\DataAccount\\\\SV_TYPE.bmp"</IMAGE>
    <IMAGE id = "IMG_ID_SYNC_USERNAME">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\DataAccount\\\\SV_NAME.bmp"</IMAGE>
    <IMAGE id = "IMG_ID_SYNC_PASSWORD">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\DataAccount\\\\SV_PASS.bmp"</IMAGE>

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    <IMAGE id = "IMG_ID_SYNC_DEV_MENU">CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\SERVICES\\\\PhoneSync\\\\PS_MAIN.bmp"</IMAGE>
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
    <SCREEN id = "SCR_ID_SYNC_NOW"/>         
    <SCREEN id = "SCR_ID_SYNC_ABORT"/>
    <SCREEN id = "SCR_ID_SYNC_ALARM_QUERY"/>
    <SCREEN id = "SCR_ID_SYNC_DELETE_ALL"/>
    <SCREEN id = "SCR_ID_SYNC_REPORT"/>
    <SCREEN id = "SCR_ID_SYNC_SAS_NOTIFICATION"/>
    <SCREEN id = "SCR_ID_SYNC_OTA_PROFILE_INSTALL"/>
    <SCREEN id = "SCR_ID_SYNC_OTA_PROFILE_REPLACE"/>
    <SCREEN id = "SCR_ID_SYNC_ACCOUNT_VIEW_LOG"/>           

	<SCREEN id = "SCR_ID_SYNC_DEV_SYNC_CONFIRM"/>
	<SCREEN id = "SCR_ID_SYNC_DEV_PHONES_LIST"/>
	<SCREEN id = "SCR_ID_SYNC_DEV_PHONES_DELETE"/>
	<SCREEN id = "SCR_ID_SYNC_DEV_PHONES_DELETE_ALL"/>

	<!--Screen Group Id-->
	<SCREEN id = "GRP_ID_SYNC_MAIN"/>	
	<SCREEN id = "GRP_ID_SYNC_EDIT"/>
	<SCREEN id = "GRP_ID_SYNC_PRE_CHECK"/>
    <SCREEN id = "GRP_ID_SYNC_START"/>
    <SCREEN id = "GRP_ID_SYNC_FINISH"/>
    <SCREEN id = "GRP_ID_SYNC_REGULARY"/>   
    <SCREEN id = "GRP_ID_SYNC_BT_SYNC_REQ"/>
    <SCREEN id = "GRP_ID_SYNC_SAS_REQ"/>
    <SCREEN id = "GRP_ID_SYNC_OTAP_INSTALL"/>
    <SCREEN id = "GRP_ID_SYNC_APP_SYNC"/>     
    <SCREEN id = "GRP_ID_SYNC_DEV_MAIN"/>
    <SCREEN id = "GRP_ID_PIM_SYNC"/>
    <SCREEN id = "GRP_ID_PIM_SETTING"/> 
	<!--End Screen Resource Area-->
	<!--End Screen Resource Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


	<!--------------------------------------------------------------------------------------------------------------------->
	<!--Menu Item Area-->
	<!--Menu Item Area-->
#ifdef __MMI_OP12_MENU_12MATRIX__  /* Vodafone */
    <MENU id = "MENU_ID_SYNCML_MAIN" parent="MAIN_MENU_EXTRA_MENUID" type = "APP_MAIN" str = "STR_ID_SYNC_MENU" img = "IMG_ID_SYNC_MENU" highlight = "mmi_syncml_highlight_sync_main_menu" group = "MAIN_MENU_EXTRA_MENUID">
#else           
    <MENU id = "MENU_ID_SYNCML_MAIN" parent="MAIN_MENU_ORGANIZER_MENUID" type = "APP_MAIN" str = "STR_ID_SYNC_MENU" img = "IMG_ID_SYNC_MENU" highlight = "mmi_syncml_highlight_sync_main_menu" group = "MAIN_MENU_ORGANIZER_MENUID">
#endif 
    </MENU>
    
    <MENU id = "MENU_ID_SYNCML_ACCOUNT_OPTION" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_SYNC" str = "STR_ID_SYNC_NOW" img = "IMG_ID_SYNC_MENU"/>
        <MENUITEM_ID>MENU_ID_SYNCML_ACCOUNT_EDIT</MENUITEM_ID>
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_VIEW_LOG" str = "STR_ID_SYNC_SYNC_LOG" img = "IMG_ID_SYNC_SYNC_LOG"/>
#ifdef __MMI_OP01_SYNCML_SETTING__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_ACTIVATE" str = "STR_GLOBAL_ACTIVATE" img = "IMG_GLOBAL_L2"/>
#endif
    </MENU>
    
    <!--account_edit_menu-->
#ifdef __MMI_OP01_SYNCML_SETTING__
    <MENU id = "MENU_ID_SYNCML_ACCOUNT_EDIT" type = "APP_SUB" str = "STR_ID_SYNC_ACCOUNT_EDIT" img = "IMG_GLOBAL_L1">
#else
    <MENU id = "MENU_ID_SYNCML_ACCOUNT_EDIT" type = "APP_SUB" str = "STR_ID_SYNC_ACCOUNT_EDIT" img = "IMG_ID_SYNC_SETTINGS">
#endif
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_NAME" str = "STR_ID_SYNC_PROFILE_NAME"/>
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_TRANSPORT_TYPE" str = "STR_ID_SYNC_PROFILE_CONNECTION_TYPE"/>
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_SERVER_SETTINGS" str = "STR_ID_SYNC_PROFILE_SERVER"/>
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_APP_TO_SYNC" str = "STR_ID_SYNC_APPLICATIONS"/>
        <MENUITEM_ID>MENU_ID_SYNCML_ACCOUNT_EDIT_DB_SETTINGS</MENUITEM_ID>        
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_CONN_SETTINGS" str = "STR_GLOBAL_DATA_ACCOUNT"/>
#ifdef __MMI_SYNCML_REFRESH_SYNC_SUPPORT__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_SYNC_TYPE" str = "STR_ID_SYNC_TYPE"/>
#endif
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_REGULAR_SYNC" str = "STR_ID_SYNC_REGULARITY"/>
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_SAS" str = "STR_ID_SYNC_SAS_NOTIFICATION"/>
#endif
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_REPORT" str = "STR_ID_SYNC_REPORT"/>
    </MENU>

    <!--account_db_settings-->
    <MENU id = "MENU_ID_SYNCML_ACCOUNT_EDIT_DB_SETTINGS" type = "APP_SUB" str = "STR_ID_SYNC_DATABASE_SETTING">
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CONTACT" str = "STR_ID_SYNC_APP_PHB" img = "IMG_ID_SYNC_CONTACT"/>
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_DB_CALENDAR" str = "STR_ID_SYNC_APP_CAL" img = "IMG_ID_SYNC_CALENDAR"/>
#endif
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_DB_TASK" str = "STR_ID_SYNC_APP_TASK" img = "IMG_ID_SYNC_TASK"/>
#endif
#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_DB_NOTE" str = "STR_ID_SYNC_APP_NOTE" img = "IMG_ID_SYNC_NOTE"/>
#endif
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_DB_EMAIL" str = "STR_GLOBAL_EMAIL" img = "IMG_ID_SYNC_EMAIL"/>
#endif
#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
        <MENUITEM id = "MENU_ID_SYNCML_ACCOUNT_EDIT_DB_BOOKMARK" str = "STR_ID_SYNC_APP_BKM" img = "IMG_ID_SYNC_BOOKMARK"/>
#endif
    </MENU>
    

#ifdef __MMI_SYNCML_DEVICE_SYNC__

#ifdef __MMI_OP12_MENU_12MATRIX__
    <MENU id = "MENU_ID_SYNCML_DEV_MAIN" parent="MAIN_MENU_EXTRA_MENUID" type = "APP_MAIN" str = "STR_ID_SYNC_DEV_MAIN" img = "IMG_ID_SYNC_DEV_MENU" highlight = "mmi_syncml_device_highlight_phonesync" group = "MAIN_MENU_EXTRA_MENUID">
#else           
    <MENU id = "MENU_ID_SYNCML_DEV_MAIN" parent="MAIN_MENU_ORGANIZER_MENUID" type = "APP_MAIN" str = "STR_ID_SYNC_DEV_MAIN" img = "IMG_ID_SYNC_DEV_MENU" highlight = "mmi_syncml_device_highlight_phonesync" group = "MAIN_MENU_ORGANIZER_MENUID">
#endif 
        <MENUITEM id = "MENU_ID_SYNCML_DEV_SYNC" str = "STR_ID_SYNC_DEV_SYNC" img = "IMG_GLOBAL_L1"/>
        <MENUITEM id = "MENU_ID_SYNCML_DEV_APP_TO_SYNC" str = "STR_ID_SYNC_APPLICATIONS" img = "IMG_GLOBAL_L2"/>
        <MENUITEM id = "MENU_ID_SYNCML_DEV_PHONES" str = "STR_ID_SYNC_DEV_PHONES" img = "IMG_GLOBAL_L3"/>
    </MENU>

    <MENU id = "MENU_ID_SYNCML_DEV_PHONES_OPTION" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_SYNCML_DEV_PHONES_OPTION_SYNC" str = "STR_ID_SYNC_DEV_SYNC"/>
        <MENUITEM id = "MENU_ID_SYNCML_DEV_PHONES_OPTION_RENAME" str = "STR_GLOBAL_RENAME"/>
        <MENUITEM id = "MENU_ID_SYNCML_DEV_PHONES_OPTION_VIEWLOG" str = "STR_ID_SYNC_SYNC_LOG"/>
        <MENUITEM id = "MENU_ID_SYNCML_DEV_PHONES_OPTION_DELETE" str = "STR_GLOBAL_DELETE"/>
        <MENUITEM id = "MENU_ID_SYNCML_DEV_PHONES_OPTION_DELETE_ALL" str = "STR_GLOBAL_DELETE_ALL"/>
    </MENU>  
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

	<!--End Menu Item Area-->
	<!--End Menu Item Area-->
	<!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->
	<RECEIVER id="EVT_ID_PHB_ADD_CONTACT" proc="mmi_syncml_phb_addition_notification"/>
	<RECEIVER id="EVT_ID_PHB_UPD_CONTACT" proc="mmi_syncml_phb_modification_notification"/>
	<RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="mmi_syncml_phb_deletion_notification"/>
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__	
	<RECEIVER id="EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING" proc="mmi_syncml_scrn_evt_handler"/>
#endif	
#if defined(__MMI_SYNCML_VF_DATA_CHANGE_SYNC__)
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_syncml_shutdown_callback"/>
#endif

    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_syncml_rmdr_notify"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="mmi_syncml_accnt_evt_handlr"/>
	<RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="mmi_syncml_accnt_evt_handlr"/>
   
    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Timer ID Area-->
    <!--Timer ID Area-->
    
	<TIMER id="SYNCML_POWER_ON_SYNC_TIMER"/>
	<TIMER id="SYNCML_DATA_CHANGE_DELAY_TIMER"/>  
    
	<!--Timer ID Area-->
    <!--Timer ID Area-->	
    <!--------------------------------------------------------------------------------------------------------------------->
		
#endif  /*__SYNCML_SUPPORT__ */

</APP>



