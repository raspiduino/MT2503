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
 *  j2me_sap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
    /********************************************************
    * Java Application manager related Messages
    *********************************************************/ 
    /* Get MIDlet Suite */
    MSG_ID_MMI_JAVA_MIDS_GETLIST_REQ = MSG_ID_J2ME_CODE_BEGIN, 
    MSG_ID_MMI_JAVA_MIDS_GETLIST_CNF,
    /* Get MIDlet List */
    MSG_ID_MMI_JAVA_MID_GETLIST_REQ, 
    MSG_ID_MMI_JAVA_MID_GETLIST_CNF,
    /* Get MIDlet Suite information */
    MSG_ID_MMI_JAVA_MIDS_GETINFO_REQ,
    MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF,
    /* Get MIDlet Suite settings */
    MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ,
    MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF, 
    /* Get MIDlet Suite push settings */
    MSG_ID_MMI_JAVA_PUSH_GET_SETTING_REQ, 
    MSG_ID_MMI_JAVA_PUSH_GET_SETTING_CNF, 
    /* Set MIDlet Suite settings */
    MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ,
    MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF,
    /* Update MIDlet Suite */
    MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ,
    MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF,
    /* Remove MIDlet Suite */
    MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ, 
    MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND, 
    MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES,
    MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF,
    /* Package MIDlet Message */
    MSG_ID_MMI_JAVA_MIDS_PACKAGE_REQ,
    MSG_ID_MMI_JAVA_MIDS_PACKAGE_CNF,
    /* Restore factory Mode */
    MSG_ID_MMI_JAVA_RESTORE_FACTORY_MODE_REQ,
    MSG_ID_MMI_JAVA_RESTORE_FACTORY_MODE_CNF,
    /* RESET MIDS SETTING */
    MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_REQ,
    MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_CNF,   
    MSG_ID_MMI_JAVA_SET_DOMAIN_STATUS_REQ,
    MSG_ID_MMI_JAVA_SET_DOMAIN_STATUS_CNF,    
    MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_REQ,
    MSG_ID_MMI_JAVA_GET_DOMAIN_STATUS_CNF,
    /* security doamin setting */
    MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_REQ,
    MSG_ID_MMI_JAVA_GET_DOMAIN_LIST_CNF,
    MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_REQ, 
    MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_CNF,
    MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_REQ,
    MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_CNF,
    MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_REQ,
    MSG_ID_MMI_JAVA_RESET_DEFAULT_DOMAIN_CNF,
    /* Set Java mode to execute */
    MSG_ID_MMI_JAVA_SET_MODE_REQ, 
    MSG_ID_MMI_JAVA_SET_MODE_CNF,
    MSG_ID_MMI_JAVA_TCK_RESULT_IND,
    /*HOME SCREEN*/
    MSG_ID_MMI_JAVA_MIDS_GET_HOME_SCREEN_ITEM_REQ,    
    MSG_ID_MMI_JAVA_NOTIFY_POST_START_REQ,
    MSG_ID_MMI_JAVA_NOTIFY_POST_END_REQ,    
    MSG_ID_MMI_JAVA_MIDS_GET_MIDS_ID_BY_STORAGE_REQ,  
    MSG_ID_MMI_JAVA_MIDS_GET_MIDS_ID_BY_STORAGE_CNF,
    /* java auto verifciation */
    MSG_ID_TST_MMI_JAVA_CMD_REQ,
    MSG_ID_MMI_L4C_JAVA_CMD_RSP,
    MSG_ID_MMI_JAVA_CMD_QUERY_REQ,
    MSG_ID_JAVA_MMI_CMD_QUERY_RSP,
    MSG_ID_MMI_L4C_OTA_STATUS_IND,
    /* MIDlet Start/Stop notification */
    MSG_ID_MMI_JAVA_MID_START_REQ, 
    MSG_ID_MMI_JAVA_MID_START_CNF, 
    MSG_ID_MMI_JAVA_MID_STOP_IND,
    MSG_ID_MMI_JAVA_MID_STOP_RES,
    /* get user permission */
    MSG_ID_MMI_JAVA_GET_PERMISSION_IND, 
   	MSG_ID_MMI_JAVA_GET_PERMISSION_CNF,
   	/*plug in T-card gen java file*/
	MSG_ID_MMI_JAVA_PLUG_IN_OUT_TCARD_IND,
    /* J2ME state change indication to MMI*/
    MSG_ID_MMI_JAVA_PAUSE_IND,
    MSG_ID_MMI_JAVA_RESUME_IND,
    MSG_ID_MMI_JAVA_TERMINATE_IND,
    MSG_ID_MMI_JAVA_TERMINATING_IND,
    MSG_ID_MMI_JAVA_TERMINATE_NOTIFY_IND,
    MSG_ID_MMI_JAVA_SHUTDOWN_ALL_IND,
    /* JAM communicate with JVM */
    MSG_ID_JAM_JVM_MID_START_REQ,
    MSG_ID_JAM_JVM_MID_START_CNF,
    MSG_ID_JAM_JVM_MID_STOP_REQ,
    MSG_ID_JAM_JVM_MID_STOP_CNF,
    MSG_ID_JAM_JVM_SHUTDOWN_ALL_IND,
    MSG_ID_JAM_JVM_TCK_START_REQ,
    MSG_ID_JAM_JVM_TCK_START_CNF,
    MSG_ID_JAM_JVM_TCK_STOP_REQ,
    MSG_ID_JAM_JVM_TCK_STOP_CNF,
    MSG_ID_JAM_JVM_GENERAL_ASSIST_REQ,
    MSG_ID_JAM_JVM_GENERAL_ASSIST_CNF,
    /********************************************************
    * install related Messages
    *********************************************************/
    /* dm install need*/
    MSG_ID_MMI_JAVA_MIDS_PRE_INSTALL_IND,
    MSG_ID_MMI_JAVA_MIDS_PRE_INSTALL_RES,
    MSG_ID_MMI_JAVA_MIDS_REMOVE_IND,
    MSG_ID_MMI_JAVA_MIDS_REMOVE_RES,
    /* push install*/
    MSG_ID_MMI_JAVA_PUSH_INSTALL_IND,
    /* normal install reqest*/
    MSG_ID_MMI_JAVA_INSTALL_MIDS_REQ,  
    /* update install progress bar*/
    MSG_ID_MMI_JAVA_INSTALL_PROGRESS_IND,
    /* Get user install confirm*/
    MSG_ID_MMI_JAVA_INSTALL_CONFIRM_IND,
    MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES,  
     /* Get install drv indication*/
    MSG_ID_MMI_JAVA_GET_INSTALL_DRV_IND,
    MSG_ID_MMI_JAVA_GET_INSTALL_DRV_RES,
    /*get install category */
    MSG_ID_MMI_JAVA_GET_INSTALL_CATEGORY_IND,
    MSG_ID_MMI_JAVA_GET_INSTALL_CATEGORY_RES,
    /* download JAR start*/
    MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_IND,
    MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_RES,
    /* get authentication while OTA download jar*/
    MSG_ID_MMI_JAVA_GET_AUTH_IND,
    MSG_ID_MMI_JAVA_GET_AUTH_RES,
    /*download percenage indication*/
    MSG_ID_MMI_JAVA_SHOW_PERCENTAGE_IND,
    /* Get rms keep or not*/
    MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_IND,
    MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_RES, 
    /*start/stop show waiting right screen*/
    MSG_ID_MMI_JAVA_WAITING_RIGHT_START_REQ,
    MSG_ID_MMI_JAVA_WAITING_RIGHT_END_REQ,
    /* Response for instll request to indication install finished */
    MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF,
    /* CT898 case*/
    MSG_ID_MMI_JAVA_DELETE_MENU_ABORT_REQ,
    MSG_ID_MMI_JAVA_DELETE_MENU_ABORT_CNF,
    /*I dont know this pairs*/
    MSG_ID_JAVA_WAP_GET_FILE_AND_SAVE_REQ,
    MSG_ID_JAVA_WAP_GET_FILE_AND_SAVE_CNF, 
   /********************************************************
    * misc. messsage
    *********************************************************/
    /*Dataaccount setting*/
    MSG_ID_JAVA_WAP_POST_DATA_REQ, 
    MSG_ID_JAVA_WAP_POST_DATA_CNF,
    MSG_ID_JAVA_WAP_DATA_ACCOUNT_IND, 
    /* ABORT */
    MSG_ID_MMI_JAVA_ABORT_REQ, 
    MSG_ID_MMI_JAVA_ABORT_CNF, 
    MSG_ID_JAVA_WAP_ABORT_CNF, 
    MSG_ID_MMI_WAP_ABORT_REQ,
    MSG_ID_MMI_JAVA_ASM_ABORT_REQ,    
    /* get user confirm */
    MSG_ID_MMI_JAVA_GET_CONFIRM_IND,
    MSG_ID_MMI_JAVA_GET_CONFIRM_RES,
    /* Get IMSI & LAI */
    MSG_ID_MMI_JAVA_GET_IMSI_IND,   /* JAVA -> MMI */
    MSG_ID_MMI_JAVA_GET_IMSI_RES,   /* MMI-> JAVA */
    MSG_ID_MMI_JAVA_GET_LAI_RES,
    /* PUSH & TimeAlarm */
    MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND, 
    MSG_ID_JAVA_JAVA_MID_START_REQ,
    MSG_ID_RESEND_TIMEALARM_PUSH_REQ,
    MSG_ID_MMI_JAVA_TIMEALARM_PUSH_RES,
    /* MMA*/
    MSG_ID_JAVA_MMA_EVENT_CALLBACK, 
    /* keypad*/
    MSG_ID_JAVA_KEYPAD_NOTIFY_IND,
    /* CMCC PHB */
    MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ,
    MSG_ID_MMI_PHB_JAVA_SET_ENTRY_RSP,
    MSG_ID_MMI_PHB_JAVA_GET_ENTRY_REQ,
    MSG_ID_MMI_PHB_JAVA_GET_ENTRY_RSP, 
    MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_REQ, 
    MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_RSP,
    MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_REQ,
    MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_RSP,
    MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ,
    MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_RSP,
    MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_REQ,
    MSG_ID_MMI_EVTDB_JAVA_SET_ENTRY_RSP,
    MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_REQ,
    MSG_ID_MMI_EVTDB_JAVA_GET_ENTRY_RSP,
    /* SMS */
    MSG_ID_JAVA_JAVA_ENQUEUE_SMS_REQ,
    /*Network profile*/
    MSG_ID_MMI_JAVA_MIDS_GET_NETWORK_PROFILE_REQ,   
    MSG_ID_MMI_JAVA_MIDS_PUT_NETWORK_PROFILE_REQ,
    MSG_ID_MMI_JAVA_MIDS_GET_NETWORK_PROFILE_CNF,   
    MSG_ID_MMI_JAVA_MIDS_PUT_NETWORK_PROFILE_CNF,
    MSG_ID_MMI_JAVA_MIDS_HS_NP_DELETE_NOTIFY_CNF,    
    MSG_ID_MMI_JAVA_CONNECT_BT_VIA_SCO_REQ, /* JAVA -> MMI */
	/* JSR179 AGPS */
    MSG_ID_MMI_JAVA_SET_AGPS_REQ,
    MSG_ID_MMI_JAVA_SET_AGPS_RSP,
    /**************************************************************************
     * JAM nw
     **************************************************************************/
    MSG_ID_MMI_JAVA_NW_GET_GLOBAL_SETTING_REQ,
    MSG_ID_MMI_JAVA_NW_GET_GLOBAL_SETTING_RSP,
    MSG_ID_MMI_JAVA_NW_SET_GLOBAL_SETTING_REQ,
    MSG_ID_MMI_JAVA_NW_SET_GLOBAL_SETTING_RSP,
        
    MSG_ID_MMI_JAVA_NW_GET_LOCAL_SETTING_REQ,
    MSG_ID_MMI_JAVA_NW_GET_LOCAL_SETTING_RSP,    
    MSG_ID_MMI_JAVA_NW_SET_LOCAL_SETTING_REQ,
    MSG_ID_MMI_JAVA_NW_SET_LOCAL_SETTING_RSP,                    
    
    MSG_ID_MMI_JAVA_NW_GET_PROFILE_REQ,    
    MSG_ID_MMI_JAVA_NW_GET_PROFILE_RSP,    
    MSG_ID_MMI_JAVA_NW_SET_PROFILE_REQ,    
    MSG_ID_MMI_JAVA_NW_SET_PROFILE_RSP,          
    
    MSG_ID_MMI_JAVA_NW_ALWAYS_ASK_IND,
    MSG_ID_MMI_JAVA_NW_ALWAYS_ASK_CNF,        
    MSG_ID_MMI_JAVA_NW_BEARER_FALLBACK_IND,
    MSG_ID_MMI_JAVA_NW_BEARER_FALLBACK_CNF,
    
    MSG_ID_MMI_JAVA_NW_UPDATE_DTCNT_IND,
    MSG_ID_MMI_JAVA_NW_UPDATE_DTCNT_CNF,
    MSG_ID_MMI_JAVA_NW_DELETE_DTCNT_IND,
    MSG_ID_MMI_JAVA_NW_DELETE_DTCNT_CNF,
    MSG_ID_MMI_JAVA_NW_UPDATE_SETTING_REQ,    
    MSG_ID_MMI_JAVA_NW_UPDATE_SETTING_RSP,       
    MSG_ID_MMI_JAVA_NW_UPDATE_PROFILE_RSP,
    MSG_ID_MMI_JAVA_NW_UPDATE_CONN_TYPE_REQ,    
    MSG_ID_MMI_JAVA_NW_UPDATE_CONN_TYPE_RSP,       
    
    MSG_ID_MMI_JAVA_PR_MAKE_CALL_REQ,  
    
    MSG_ID_MMI_JAVA_MIDS_GETLIST_DETECT_REQ,
    MSG_ID_MMI_JAVA_MIDS_GETLIST_DETECT_RSP,

    MSG_ID_MMI_JAVA_GET_RUNNING_MIDS_LIST_REQ,
    MSG_ID_MMI_JAVA_GET_RUNNING_MIDS_LIST_CNF,

    MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_REQ,
    MSG_ID_MMI_JAVA_CHECK_PUSH_MIDS_RUNNING_RSP,

    MSG_ID_MMI_JAVA_NW_INSTALL_IND,
    MSG_ID_MMI_JAVA_NW_INSTALL_CNF,

    MSG_ID_MMI_JAVA_NW_USABLE_REQ,

    MSG_ID_MMI_JAVA_SET_AUDIO_VOLUME_REQ,
    
    MSG_ID_MMI_JAVA_GET_APPMGR_INFO_REQ,
/* EM Java Performance begin*/
    MSG_ID_MMI_EM_JAVA_PERFORMANCE_TEST_REQ,
    MSG_ID_MMI_EM_JAVA_PERFORMANCE_TEST_IND,
    MSG_ID_MMI_EM_JAVA_PERFORMANCE_TEST_FAILED,
/*EM Java Performance end*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* if 0 */
