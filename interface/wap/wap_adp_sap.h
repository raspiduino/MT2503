#ifndef _WAP_ADP_SAP_H
#define _WAP_ADP_SAP_H
#ifdef __BUILD_DOM__
/* Messages provided by WAPADP */
typedef enum {
#endif

    
    MSG_ID_WAP_BROWSER_POWEROFF_REQ, /* Used mainly by shutdown app to request the termination of whole WAP framework
                
                                        Direction: MMI -> WAP
                                        Local paramter: None
                                        Peer buffer: None
                                     */
    
    MSG_ID_WAP_BROWSER_POWEROFF_RSP, /* Response to MSG_ID_WAP_BROWSER_POWEROFF_REQ when the termination process is complete
                        
                                        Direction: WAP -> MMI
                                        Local paramter: None
                                        Peer buffer: None
                                     */

    
    MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ, /* Request WAP to perform required process for restoring factory setting before handset restarts
                        
                                               Direction: MMI -> WAP
                                               Local paramter: None
                                               Peer buffer: None
                                            */

    
    MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF,	/* Response to MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ when required process is complete
                        
                                               Direction: WAP -> MMI
                                               Local paramter: None
                                               Peer buffer: None
                                            */

    
    MSG_ID_WAP_READY_IND, /* Used by WPS task to notify interested task that WAP is ready to serve incoming requests
    
                             Direction: WAP -> Other task
                             Local paramter: None
                             Peer buffer: None
                          */

    /* DOM-NOT_FOR_SDK-BEGIN */
    /* Used internally to indicate that unrecoverable error has happened and framework might need to restart */
    MSG_ID_WAP_INTERNAL_ERROR_IND,
    /* DOM-NOT_FOR_SDK-END */

    
    MSG_ID_WAP_MMI_BROWSER_TERMINATION_IND, /* To notify SAT application that browser has terminated, mandatory if __SAT__ is defined.

                                               Direction: WAP -> MMI
                                               Local paramter: wap_mmi_browser_termination_ind_struct
                                               Peer buffer: None
                                            */

    /* DOM-NOT_FOR_SDK-BEGIN */
    /* For Q03C Only, to obtain the information of push inbox */
    MSG_ID_WAP_MMI_NMGR_PUSH_INFO_REQ, 

    /* For Q03C Only, response to MSG_ID_WAP_MMI_NMGR_PUSH_INFO_RSP */
    MSG_ID_WAP_MMI_NMGR_PUSH_INFO_RSP, /* Q03C Only */    

    /* For Q03C Only, to request browser to be closed */
    MSG_ID_WAP_BROWSER_SHUTDOWN_REQ,

    /* For Q03C Only, to deliver key event to WAP framework */
    MSG_ID_WAP_MMI_KEY_INDICATION,

    /* For Q03C Only, to notify WAP framework the status of bearer */
    MSG_ID_WAP_BEARER_STATUS_IND,

    /* For Q03C Only, to notify WAP framework the status of SIM card, required for WAP startup */
    MSG_ID_WAP_SIM_INFO_NOTIFY_IND,

    /* For Q03C Only, indicate WAP/MMS that memory card has been plugged out */
    MSG_ID_WAP_MEM_CARD_PLUG_OUT,
    /* MSG_ID_WAP_MMI_READY_IND, */ /* Obsolete */
    /* MSG_ID_WAP_MMI_JAVA_INTALL_REQ, */ /* Obsolete */
    /* DOM-NOT_FOR_SDK-END */

    MSG_ID_WAP_CONTINUE_PROCESS_IND,
	/*
	 * This signal is used internally by WAP to break out
	 * to give chance to MMI to execute, as WAP has taken lot of time.
	 * each WAP module using this signal should write its own handler for the same.
	 * OTHER APPS DO NOT USE THIS SIGNAL
	 */
    
#ifdef __BUILD_DOM__
} wap_adp_sap_enum;
#endif
#endif  /* _WAP_ADP_SAP_H */
