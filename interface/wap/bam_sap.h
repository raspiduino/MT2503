#ifndef _BAM_SAP_H
#define _BAM_SAP_H

// #ifdef __OBIGO_Q05A__
#ifdef __BUILD_DOM__
/* 
    <GROUP Messages>
    Message set */
typedef enum {
#endif
    MSG_ID_WAP_BAM_READY_IND,                         /* An indication to notify the application that BAM is ready. No additional information is carried 
	                                                     in this primitive.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_ready_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ,               /* A request to create an instance of Browser Engine.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_create_instance_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF,               /* A response to the instance creation request.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_create_instance_cnf_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ,               /* A request to delete the BROWSER ENGINE instance with the given instance id

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_delete_instance_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF,               /* A response to the instance deletion request.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_delete_instance_cnf_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_RESIZE_WINDOW_REQ,                 /* A request to resize the screen the Browser Engine instance uses. No message is sent as response 
	                                                     to this request.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_resize_window_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_LOAD_URL_REQ,                      /* A request to load a document using the specified URL.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_load_url_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_LOAD_DATA_REQ,                     /* A request to load a document in the main window, using the supplied file path.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_load_data_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ,           /* A request to activate a DO-element selected by the user. The DO-element is one of the elements 
	                                                     sent in the message MSG_ID_WAP_BAM_DO_ELEMENTS_IND.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_activate_do_element_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_MOVE_REQ,                          /* A request to navigate in the document history.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_move_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_RELOAD_REQ,                        /* A request to reload the current document.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_reload_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_STOP_REQ,                          /* A request to stop the current transaction.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_stop_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ,             /* A request to control the set of elements that are selectable while viewing a page. These 
	                                                     elements are then when selected reported by Browser Engine in the signal 
	                                                     MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_navigation_change_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SAVE_PAGE_REQ,                     /* A request to save the current page offline. 
                                                         The main page as well as all embedded resources is saved offline, and this includes all 
                                                         documents in embedded windows (frames). The parameter ¡§label¡¨ indicates the label under which 
                                                         the page is saved. If some page is already stored under this label, it is an error unless the 
                                                         parameter ¡§overwrite¡¨ is TRUE. Once the save operation is complete, the BAM sends the signal 
                                                         MSG_ID_WAP_BAM_SAVE_PAGE_CNF. If an error occurred, it is indicated in this signal.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_save_page_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SAVE_PAGE_CNF,                     /* A response to the save-page request. If the request message is 
	                                                     MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ, the peer buffer is the information of the specified saved 
	                                                     page; otherwise, the peer buffer must be ignored.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_save_page_cnf_struct
	                                                     Peer Buffer: wap_bam_saved_page_struct */
    MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ,                /* A request to get the information of a previously saved page.
	                                                     The parameter index specifies the saved page. Once the operation is complete, the BAM sends the 
	                                                     information by using the signal MSG_ID_WAP_BAM_SAVE_PAGE_CNF. If an error occurred, it is 
	                                                     indicated in this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_saved_page_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ,               /* A request to load a previously saved page.
                                                         The parameter index specifies the page to load. Once the load operation is complete, the BAM 
                                                         sends the signal MSG_ID_WAP_BAM_SAVE_PAGE_CNF. If an error occurred, it is indicated in this 
                                                         signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_load_saved_page_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ,             /* A request to delete a previously saved page.
                                                         The parameter ¡§index¡¨ specifies the page to delete. Once the delete operation is complete, the 
                                                         BAM sends the signal MSG_ID_WAP_BAM_SAVE_PAGE_CNF. If an error occurred, it is indicated in 
                                                         this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

                                                         Direction: APP -> BAM
                                                         Local parameter: wap_bam_delete_saved_page_req_struct
                                                         Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ,        /* A request to delete all previously saved pages.
                                                         Once the delete operation is complete, the BAM sends the signal MSG_ID_WAP_BAM_SAVE_PAGE_CNF. 
                                                         If an error occurred, it is indicated in this signal.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_delete_all_saved_pages_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ,             /* A request to rename a previously saved page.
                                                         The parameter index specifies the page to rename, and new_label is the new name. Once the 
                                                         rename operation is complete, the BAM sends the signal MSG_ID_WAP_BAM_SAVE_PAGE_CNF. If an 
                                                         error occurred, it is indicated in this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_rename_saved_page_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_REQ,    /* This message is used as the initial step of getting the list of saved pages.
                                                         As a response, the BAM sends the signal MSG_ID_WAP_BAM_GET_SAVED_PAGES_START_CNF. If an error 
                                                         occurred, it is indicated in this signal.
                                                         To get the titles of some specified saved pages, the application need to send 
                                                         MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ to BAM. There will be a reply message 
                                                         MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF that holds the titles of the saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_saved_pages_list_start_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_CNF,    /* A response to the request of retrieving the number of saved pages.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_get_saved_pages_list_start_cnf_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ, /* A request to retrieve the titles of some saved page from the given index. The index starts from 
	                                                     0, and it should be less than the number of the saved pages.
                                                         As a response, the BAM sends the message MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF. If 
                                                         an error occurred, it is indicated in this signal.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_saved_pages_list_continue_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF, /* A response to the request of retrieving the titles of some saved page. The first title in the
                                                         peer buffer will be the title of the specified saved page with the given index in the message
                                                         MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ.
                                                         The error_code is the result of the save-page request. If any error occurs, the data in the
                                                         peer buffer must be ignored.
                                                         
                                                         Direction: BAM -> APP
                                                         Local parameter: wap_bam_get_saved_pages_list_continue_cnf_struct
                                                         Peer buffer: MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF_peer_buffer */
    MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_END_REQ,      /* A request to notify the BAM of the end of getting the list of all saved pages. No signal is 
	                                                     sent as response to this message.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_saved_pages_list_end_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_REQ,      /* A request to get the number of all resources currently used.
                                                         The message can be used by an application to get the number of the resources that Browser 
                                                         Engine is currently using in its windows. There will be a reply message 
                                                         MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_CNF that holds the number of resources.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_resources_list_start_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_CNF,      /* A response to the request of getting the number of resources that are currently used.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_get_resources_list_start_cnf_struct */
    MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_REQ,   /* A request to get one of the using resources with the given index. The index starts from 0, and 
	                                                     it should be less than the number of the resources that Browser Engine is currently using.
                                                         There will be a reply message MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF that holds the 
                                                         information of the specified resource.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_resources_list_continue_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF,   /* A response to the request of getting the titles and types of some specified resources. The
                                                         first type and title in the peer buffer will be the type and title of the specified resource
                                                         with the given index in the message MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_REQ.
                                                         The error_code is the result of the request to get specified resource. If any error occurs, the
                                                         data in the peer buffer must be ignored.
                                                         
                                                         Direction: BAM -> APP
                                                         Local parameter: wap_bam_get_resources_list_continue_cnf_struct
                                                         Peer buffer: MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF_peer_buffer */
    MSG_ID_WAP_BAM_GET_RESOURCES_LIST_END_REQ,        /* A request to notify the BAM of the end of getting the list of resources. No signal is sent as 
	                                                     response to this message.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_resources_list_end_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RESOURCE_REQ,                  /* A request to get the information of a specified resource.
                                                         The parameter index specifies the resource. Once the operation is complete, the BAM sends the 
                                                         information by using the signal MSG_ID_WAP_BAM_GET_RESOURCE_CNF. If an error occurred, it is 
                                                         indicated in this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_GET_RESOURCE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_resource_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RESOURCE_CNF,                  /* A response to the request of getting the information of specified resource.
                                                         The error_code is the result of the request to get specified resource. If any error occurs, the 
                                                         data in the peer buffer must be ignored.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_get_resource_cnf_struct
	                                                     Peer Buffer: wap_bam_resource_item_struct */
    MSG_ID_WAP_BAM_ACTIVATE_RESOURCE_REQ,             /* A request to make Browser Engine activate the resource which is identified by "index". The 
	                                                     reaction of the activation is determined by Browser Engine and currently is configured to save 
	                                                     the specified page resource to local storage.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_ACTIVATE_RESOURCE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_activate_resource_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_NAVIGATE_TO_HOTSPOT_REQ,           /* A request to trigger a hotspot navigation (if applicable) either in direction BAM_NEXT_HOTSPOT 
	                                                     or BAM_PREV_HOTSPOT.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_navigate_to_hotspot_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_STATUS_IND,                        /* An indication to notify the application of the current status.
                                                         Used by BAM to report the current status of Browser Engine, for instance to tell that a new 
                                                         transaction has started or ended, or to tell that some object is being requested in within the 
                                                         current transaction.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_status_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_ERROR_IND,                         /* An indication to notify the application of an error.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_error_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_DOCUMENT_INFO_IND,                 /* An indication that is sent when a new document has been loaded.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_document_info_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_DO_ELEMENTS_IND,                   /* This indication is sent as the last action in rendering a WML-card.
                                                         The array "elements" is the set of DO-elements to be listed by the application in such a way 
                                                         that the user may select from them to perform the action associated with a DO-element. When the 
                                                         user selects one of these DO-elements, this is signaled to BAM using the message 
                                                         MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ. If there are no DO-elements to display, the data in the 
                                                         peer buffer must be ignored.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_do_elements_ind_struct 
	                                                     Peer Buffer: wap_bam_do_elements_struct */
    MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND,               /* This indication is sent when an element is focused.
                                                         When a document is loaded into the Browser Engine and the end user is navigating the page, 
                                                         various elements in the document will be focused. Each time an element is focused this signal 
                                                         is sent providing some data about the focused element. A typical feature that can be supported 
                                                         using this information is "save as".

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_element_focused_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SET_SEC_CLASS_IND,                 /* This indication is used to return the currently used security class when the user tries to 
	                                                     download insecure content.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_set_sec_class_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_REQ,          /* A request to change a single setting to a given value.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_change_setting_value_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_IND,          /* An indication to update a single setting value to the application.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_change_setting_value_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SET_PROFILE_REQ,                   /* A request to apply the whole browser settings into the browser core engine.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_set_profile_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SET_PROFILE_CNF,                   /* A response to the request of applying the whole browser settings into the browser core engine.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_set_profile_cnf_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ,   /* This message is used as the initial step of getting the list of web pages recently accessed.
                                                         The message can be used by the application to get a list of the recent-page items the Browser 
                                                         Engine recently accessed. There will be a reply message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CNF 
                                                         that holds the number of recent-page items. The sort_option parameter holds one of the 
                                                         BAM_RECENT_PAGE_SORT_OPTION_ options.
                                                         To get the titles of some specified recent-page items, the application need to send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_CONTINUE_REQ to BAM. There will be a reply message 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_CONTINUE_CNF that holds the titles of the specified recent-page 
                                                         items.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_recent_pages_list_start_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_CNF,   /* A response to the request of getting the list of web pages that are recently accessed.
                                                         The error_code is the result of the request to get the number of recent-page items. If any 
                                                         error occurs, the value of num_item must be ignored.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_get_recent_pages_list_start_cnf_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ,/* This message is used as the continuous step of getting the list of recent pages recently 
	                                                     accessed.
                                                         The message can be used by the application to get the data of a specified recent-page item 
                                                         after getting the number of recent-page items in the reply message 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CNF. The index parameter starts from 0 and should be less 
                                                         than the number of the recent-page items.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_recent_pages_list_continue_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF,/* A response to the request of getting the titles of some specified recent-page items.
                                                         The error_code is the result of the request to get the specified recent-page item. If any error
                                                         occurs, the data in the peer buffer must be ignored.
                                                         
                                                         Direction: BAM -> APP
                                                         Local parameter: wap_bam_get_recent_pages_list_continue_cnf_struct
                                                         Peer buffer: MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF_peer_buffer */
    MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_END_REQ,     /* A request to notify the BAM of the end of getting the list of all recent-page items. No signal 
	                                                     is sent as response to this message.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_recent_pages_list_end_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ,               /* A request to get a recent page with a given index.
                                                         The parameter index specifies the page to get. Once the requested operation is complete, the 
                                                         BAM sends the information of the specified page in signal MSG_ID_WAP_BAM_RECENT_PAGE_CNF. If an 
                                                         error occurred, it is indicated in this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_get_recent_page_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ,              /* A request to load a recent page with a given index.
                                                         The parameter index specifies the page to load. Once the load operation is complete, the BAM 
                                                         sends the signal MSG_ID_WAP_BAM_RECENT_PAGE_CNF. If an error occurred, it is indicated in this 
                                                         signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_load_recent_page_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ,            /* A request to delete a recent-page item.
                                                         The parameter index specifies the recent-page item to delete. Once the delete operation is 
                                                         complete, the BAM sends the signal MSG_ID_WAP_BAM_RECENT_PAGE_CNF. If an error occurred, it is 
                                                         indicated in this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_delete_recent_page_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ,       /* A request to delete all recent pages.
                                                         Once the delete operation is complete, the BAM sends the signal MSG_ID_WAP_BAM_RECENT_PAGE_CNF. 
                                                         If an error occurred, it is indicated in this signal.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_delete_all_recent_pages_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_RECENT_PAGE_CNF,                   /* A response to the recent-page request. If the requested operation is not 
	                                                     MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ, the data in the peer buffer must be ignored.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_recent_page_cnf_struct
	                                                     Peer Buffer: wap_bam_recent_page_struct */
    MSG_ID_WAP_BAM_WTAI_TEL_IND,                      /* An indication that is used to to request the application to make a phone call or send DTMF.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_wtai_tel_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_WTAI_TEL_RSP,                      /* A response that is used to to return the result of the requested telephony operation.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_wtai_tel_rsp_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_WTAI_PB_IND,                       /* An indication that is used to request the application to add a new phone-book entry.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_wtai_pb_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_WTAI_PB_RSP,                       /* A response that is used to return the result of adding the new phone-book entry.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_wtai_pb_rsp_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_URI_REQUEST_IND,                   /* An indication that is used to request the application to handle any URI request that is not one 
	                                                     of the three Browser Engine supported built-in types, which including ¡§http¡¨, ¡§https¡¨, and ¡§file¡¨.
                                                         For example, it has chance to process URI request with ¡§sms¡¨ scheme, ¡§smsto¡¨ scheme, ¡§mms¡¨ 
                                                         scheme, ¡§mmsto¡¨ scheme, ¡§rtsp¡¨ scheme, ¡§mailto¡¨ scheme, ¡§tel¡¨ scheme, etc.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_uri_request_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_URI_REQUEST_RSP,                   /* A response that is used to return the result of handling the URI request.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_uri_request_rsp_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_BEARER_INFO_IND,                   /* An indication that is used to notify the application of the bearer status has changed.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_bearer_info_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_REGISTER_KEYPAD_HANDLER_REQ,       /* A request to make BAM/OWL register suitable keypad events and event handlers. No message is 
	                                                     sent as response to this request.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_register_keypad_handler_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_HANDLE_PEN_EVENT_REQ,              /* A request to make BAM/OWL handle the given keypad event. No message is sent as response to this 
	                                                     request.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_handle_pen_event_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SUSPEND_OWL_RENDERING_REQ,         /* A request to make BAM/OWL suspend the page rendering. No message is sent as response to this 
	                                                     request.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_suspend_owl_rendering_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_RESUME_OWL_RENDERING_REQ,          /* A request to make BAM/OWL resume the page rendering. No message is sent as response to this 
	                                                     request.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_resume_owl_rendering_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_NOTIFY_SCREEN_INFO_REQ,            /* A request to notify BAM/OWL of the current category screen information, including layer handle 
	                                                     used and what area to draw. No message is sent as response to this request.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_notify_screen_info_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND,              /* An indication that is used to notify BrowserAPP of waiting for user action, e.g. a cofirm 
	                                                     dialog. After user action is completed, BrowserAPP should send MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP 
	                                                     to notify BAM of the user action.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_wait_user_action_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP,              /* A response message of MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND that is used to notify BAM of the 
	                                                     user action.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_wait_user_action_rsp_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_OBJECT_ACTION_REQ,                 /* This message is used to request the corresponding action for the currently focused page object.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_object_action_req_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_IND,              /* An indication that is used to to request the application to show the authentication dialog.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_show_auth_dialog_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP,              /* An response that is used to to return the result of the user authentication.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_show_auth_dialog_rsp_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SELECT_FILE_IND,                   /* An indication that is used to to request the application for file selection.

	                                                     Direction: BAM -> APP
	                                                     Local parameter: wap_bam_select_file_ind_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_SELECT_FILE_RSP,                   /* A response that is used to to return the result for file selection.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_select_file_rsp_struct
	                                                     Peer buffer: None */
    MSG_ID_WAP_BAM_NOTIFY_APP_IND,                    /* An indication that is used to notify application to do something according to type.
    
                                                         Direction: BAM -> APP
                                                         Local parameter: wap_bam_notify_app_ind_struct
                                                         Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_N_SAVED_PAGE_REQ,             /* A request to delete some of previously saved page.
                                                         The parameter ¡§index¡¨ specifies the page to delete. Once the delete operation is complete, the 
                                                         BAM sends the signal MSG_ID_WAP_BAM_SAVE_PAGE_CNF. If an error occurred, it is indicated in 
                                                         this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_DELETE_N_SAVED_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

                                                         Direction: APP -> BAM
                                                         Local parameter: wap_bam_delete_n_saved_page_req_struct
                                                         Peer buffer: None */
    MSG_ID_WAP_BAM_DELETE_N_RECENT_PAGE_REQ,            /* A request to delete some of recent-page item.
                                                         The parameter index specifies the recent-page item to delete. Once the delete operation is 
                                                         complete, the BAM sends the signal MSG_ID_WAP_BAM_RECENT_PAGE_CNF. If an error occurred, it is 
                                                         indicated in this signal.
                                                         NOTE: Before sending MSG_ID_WAP_BAM_DELETE_N_RECENT_PAGE_REQ, browser application should send 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ and 
                                                         MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ in advance to get the list of saved pages.

	                                                     Direction: APP -> BAM
	                                                     Local parameter: wap_bam_delete_n_recent_page_req_struct
	                                                     Peer buffer: None */

    MSG_ID_WAP_BAM_WMLS_CREATE_DIALOGUE_REQ,             /*A req to notify application to do something according to type
														 
														 Direction: BAM -> APP
														 Local Parameter: WAP_BAM_WMLS_CREATE_DIALOGUE_REQ_STRUCT
														 Peer Buffer: None */

    MSG_ID_WAP_BAM_WMLS_CREATE_DIALOGUE_RSP,             /*A response to notify service to do something according to type
														 
														 Direction: APP -> BAM
														 Local Parameter: WAP_BAM_WMLS_CREATE_DIALOGUE_REQ_STRUCT
														 Peer Buffer: None */


   MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_REQ,          /*A req by app to close bearer connection to clear previous socket connection information.

														  Dirtection: APP-> BAM
														  Local Parameter: WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_REQ_STRUCT
														  Peer Buffer: None  */

   MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_RSP,          /*A response to app application request to close bearer connection to clear previous socket connection information.

														  Dirtection: APP-> BAM
														  Local Parameter: WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_RSP_STRUCT
														  Peer Buffer: None */

   MSG_ID_WAP_BAM_BEARER_OPEN_IND,                        /*A indication to application by service to open bearer Connection.

														  Dirtection: BAM->APP
														  Local Parameter: WAP_BAM_BEARER_OPEN_IND_STRUCT
														  Peer Buffer: None */
   
   MSG_ID_WAP_BAM_BEARER_OPEN_RSP,                        /*A response by application to for corresponding request for opening bearer..

														  Dirtection: APP-> BAM
														  Local Parameter: WAP_BAM_BEARER_OPEN_RSP_STRUCT
														  Peer Buffer: None */

#ifdef __BUILD_DOM__
} msg_id_wap_bam_enum;
#endif
// #endif

#endif	/* End of _BAM_SAP_H */
