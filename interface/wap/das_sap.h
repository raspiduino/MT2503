#ifndef _DAS_SAP_H
#define _DAS_SAP_H

#ifdef __BUILD_DOM__
/* The messages provided by SRV_DAS_SAP */
typedef enum{
#endif

    MSG_ID_WAP_MMI_FILE_DL_IND, /**************************************************************************
                                  * This message is sent when user is invoking a WAP download by entering a
                                  * URL or clicking on a hyperlink which links to a file object that is not
                                  * process by WAP task itself. MMI should respond with desired saving
                                  * location or cause if the operation is cancelled by user.
                                  * 
                                  * Direction: WAP --> MMI
                                  * Local Parameter: wap_mmi_file_dl_ind_struct
                                  * Peer Buffer: wap_mmi_file_dl_var_struct
                                  **************************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_RES, /************************************************************
                                  * This message is the response to file download indication.
                                  * 
                                  * Direction: MMI --> WAP
                                  * Local Parameter: wap_mmi_file_dl_res_struct
                                  ************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND, /*********************************************************************
                                           * This message is used to indicate the status of downloading objects
                                           * 
                                           * Direction: WAP --> MMI
                                           * Local Parameter: wap_mmi_file_dl_progress_ind_struct
                                           *********************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES, /************************************************************************
                                           * This message is used to indicate that the
                                           * MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND has been received. Download agent
                                           * has to send this message when MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND has
                                           * been received in order to have the succeeding indications.
                                           * 
                                           * Direction: MMI --> WAP
                                           * Local Parameter: wap_mmi_file_dl_progress_res_struct
                                           ************************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_STOP_REQ, /*******************************************************************
                                       * This message is used to request WAP to stop the current download
                                       * progress by session id.
                                       * 
                                       * Direction: MMI --> WAP
                                       * Local Parameter: wap_mmi_file_dl_stop_req_struct
                                       *******************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_STOP_RSP, /********************************************************************
                                       * This message is the response to the stop request sent by MMI. The
                                       * status should be WAP_DL_STATUS_CANCELLED.
                                       * 
                                       * Direction: WAP --> MMI
                                       * Local Parameter: wap_mmi_file_dl_stop_rsp_struct
                                       ********************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_CANCEL_PREFETCH_REQ, /*************************************************************************
                                                  * This message is used to request WAP to cancel the download progress in
                                                  * prefetching phase for progressive download.
                                                  * 
                                                  * Direction: MMI --> WAP
                                                  * Local Parameter: wap_mmi_file_dl_cancel_prefetch_req_struct
                                                  *************************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_CANCEL_PREFETCH_RSP, /******************************************************************
                                                  * This message is the response to the cancel request sent by MMI.
                                                  * 
                                                  * Direction: WAP --> MMI
                                                  * Local Parameter: wap_mmi_file_dl_cancel_prefetch_rsp_struct
                                                  ******************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_PREFETCH_ABORTED_IND,/*****************************************************************
                                                  * This message is used to indicate that the download progress in
                                                  * prefetching phase for progressive download is aborted by DAS.
                                                  * 
                                                  * Direction: WAP --> MMI
                                                  * Local Parameter: wap_mmi_file_dl_prefetch_aborted_ind_struct
                                                  *****************************************************************/
    MSG_ID_WAP_MMI_FILE_DL_NW_SWITCH_IND, /*****************************************************************
                                            * This message is used to indicate that the downloading network is switched 
                                            * from one bearer to another. And all download need to be switch on new 
                                            * network. DAS need to send this indication to MMI when it receive bearer 
                                            * switch notification from CBM. Network switch type can be obtained from 
                                            * CBM data provided with switch event.
                                            * 
                                            * Direction: WAP --> MMI
                                            * Local Parameter: wap_mmi_file_dl_nw_switch_ind_struct
                                            *****************************************************************/
#ifdef __BUILD_DOM__ 
}sap_das_sap_h_enum;
#endif

#endif  /* _DAS_SAP_H */
