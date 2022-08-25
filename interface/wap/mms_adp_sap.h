#ifndef _MMS_ADP_SAP_H
#define _MMS_ADP_SAP_H

#ifdef __BUILD_DOM__
/*These following service primitives exported by MMS adaptation module.*/
//<GROUP Message>
typedef enum {
#endif  
    MSG_ID_MMS_ENTER_USB_MODE_REQ,/*After mms_on_enter_usb_mode() is invoked, the function shall send this primitive to task of MMS solution.

                                    Direction: MMI -> MMS
                                    Local paramter: none
                                    Peer buffer: None
                                  */
    MSG_ID_MMS_ENTER_USB_MODE_RSP,/*After MMS solution already do needful before user enter USB mode, it shall send this priimtive to MOD_MMI. Otherwise, user is not allowed to enter USB mode (Mass storage).

                                    Direction: MMS -> MMI
                                    Local paramter: none
                                    Peer buffer: None
                                  */
    MSG_ID_MMS_EXIT_USB_MODE_REQ,/*After mms_on_exit_usb_mode() is invoked, the function shall send this primitive to task of MMS solution.

                                   Direction: MMI -> MMS
                                   Local paramter: none
                                   Peer buffer: None
                                 */
    MSG_ID_MMS_EXIT_USB_MODE_RSP,/*After MMS solution already do needful before user exits USB mode, it shall send this priimtive to MOD_MMI. Otherwise, user is not allowed to exit USB mode (Mass storage).

                                   Direction: MMS -> MMI
                                   Local paramter: none
                                   Peer buffer: None
                                 */
    MSG_ID_MMS_POWEROFF_REQ,/* When phone is powered off, MOD_MMI will send this primitive to MMS solution. Then MMS solution can start to deinitalize itself.
    
                               Direction: MMI -> MMS
                               Local paramter: none
                               Peer buffer: None
                             */
    MSG_ID_MMS_POWEROFF_RSP,/* After MMS solution deinitalizes itself, it shall send this primitive to MOD_MMI. Then MOD_MMI will go to terminate next applications.
    
                               Direction: MMS -> MMI
                               Local paramter: none
                               Peer buffer: None
                             */                                                             
    MSG_ID_MMS_TARGET_DATA_IND,/* This primitive is used to carry some information including roaming status, owner number, plmn number to MMS solution. Example, when mms_owner_number_indication_callback() is invoked by MMI sim application. This fucntion shall send MSG_ID_MMS_TARGET_DATA_IND with owner numbder to the task of MMS solution.
    
                               Direction: MMI -> MMS
                               Local paramter: mms_target_data_ind_struct
                               Peer buffer: It depends on data_type of mms_target_data_ind_struct. 
                               							It can be the following structures.
                                            mms_target_data_roaming_status_struct, 
                                            mms_target_data_owner_number_struct, 
                                            mms_target_data_plmn_number_struct,
                                            mms_target_data_mms_version_struct,
                                            mms_target_data_user_agent_struct.
                             */
    MSG_ID_MMI_MMS_CARD_PLUG_IN_IND,
    MSG_ID_MMI_MMS_CARD_PLUG_IN_RES,

    MSG_ID_MMI_MMS_CARD_PLUG_OUT_IND,
    MSG_ID_MMI_MMS_CARD_PLUG_OUT_RES,

    MSG_ID_MMS_FMT_FILE_MOVE_PROCESSING_IND,    
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* Q03C MMS V02 only */
    MSG_ID_MMS_MULTI_OBJECT_INSERT_REQ,
    MSG_ID_MMS_MULTI_OBJECT_INSERT_RSP,
    MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_IND,
    MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_RES,
    MSG_ID_MMS_SIM_INFO_NOTIFY_IND,
    /* MMA internal signal */
    MSG_ID_MMI_MMS_SYNC_DELETE_IND, /* MMS sync API, called for Delete mms from MMI Task, shall send this primitive to MMS Task for doing the MMS Specific operation.

                                                                           Direction: MMI -> MMS
                                                                           Local paramter: message ID of the Deleted mms
                                                                           Peer buffer: None
                                                                         */
    MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_REQ, /* MMI Task send this primitive to MMS Task for creating another copy of mms in ARCHIVE folder
                                                                           Direction: MMI -> MMS
                                                                           Local paramter: wap_mma_cpy_msg_to_archive_folder_req_struct
                                                                           Peer buffer: None
                                                                         */
    MSG_ID_MMI_MMS_CPY_TO_ARCHIVE_RSP, /* MMS Task send this primitive to MMI Task for the response of copy to ARCHIVE folder operation
                                                                           Direction: MMS -> MMI
                                                                           Local paramter: wap_mma_cpy_msg_to_archive_folder_rsp_struct
                                                                           Peer buffer: None
                                                                         */
    /* DOM-NOT_FOR_SDK-END */
#ifdef __BUILD_DOM__
}mmsadp_sap_enum ; 
#endif

#endif /*_MMS_ADP_SAP_H*/
