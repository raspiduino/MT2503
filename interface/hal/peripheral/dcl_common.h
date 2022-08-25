/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_common.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer).
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_COMMON_H__
#define __DCL_COMMON_H__
//this file only for DCL common layer user
 typedef enum{
	 DCL_USER_GENERAL,
	 DCL_USER_MRE,
	 DCL_USER_DRV_GENERAL = 0x100
 }DCL_USER_ID;
//this enum used to replace the module_type enum at the MRE APP level.
//module_type is 16 bit at present, but if it changed in the future or the compiler changed(treat the enum as 32bits always), 
//there will be error. So use another enum to simulate it.
typedef enum{
	MODULE_START = 0,
	MODULE_END = 0x1FF//make sure this enum will be at least 16bit.
}DCL_MODULE_TYPE;
//this enum used to hold the data transfer from ilm
typedef struct{
   void *local_para_ptr; /* local_para pointer */
   void  *peer_buff_ptr;  /* peer_buff pointer */
}DCL_CB_ILM_DATA;
 /*******************************************************************************
 * DCL_CALLBACK
 *******************************************************************************/
typedef void (*DCL_CALLBACK)(void* param, DCL_EVENT event,DCL_HANDLE handle);
/*******************************************************************************
* API:
*******************************************************************************/
DCL_HANDLE DCL_Open(DCL_DEV dev, DCL_FLAGS flags);
DCL_STATUS DCL_Control (
	DCL_HANDLE       	device_handle,
	DCL_CTRL_CMD       cmd, 
    void*   arg);

DCL_STATUS DCL_Close(DCL_HANDLE      device_handle);

DCL_STATUS DCL_RegisterCallback(
	DCL_HANDLE		device_handle,
	DCL_EVENT		event,
	DCL_CALLBACK	callback,
	void*			user_data,
	DCL_USER_ID  	user_id); 
	
DCL_STATUS DCL_Query(
	DCL_HANDLE     device_handle,
	void*   		handle_status);
		 
DCL_STATUS  DCL_Read(
	DCL_HANDLE   	device_handle, 
	DCL_BUFF*       buf, 
	DCL_BUFF_LEN 	read_len, 
	DCL_BUFF_LEN *	returned_len,
	DCL_OPTIONS 	options);
	
DCL_STATUS  DCL_Write(
	DCL_HANDLE 		device_handle, 
	DCL_BUFF* 		buf, 
	DCL_BUFF_LEN 	write_len, 
	DCL_BUFF_LEN* 	written_len,
	DCL_OPTIONS 	options);

DCL_MODULE_TYPE DCL_GetDestinationID(DCL_USER_ID user_id);



/*******************************************************************************
* DCL structure for device drivers
*******************************************************************************/
typedef struct {
	
DCL_HANDLE (*DCL_DrvOpen)(DCL_DEV  device_number,  DCL_FLAGS   flags);

DCL_STATUS  (*DCL_DrvRead)(
	DCL_HANDLE   	device_handle, 
	DCL_BUFF*       buffer, 
	DCL_BUFF_LEN 	read_len, 
	DCL_BUFF_LEN *	returned_len,
	DCL_OPTIONS 		option);

DCL_STATUS  (*DCL_DrvWrite)(
	DCL_HANDLE 		device_handle, 
	DCL_BUFF* 		buf, 
	DCL_BUFF_LEN 	write_len, 
	DCL_BUFF_LEN* 	written_len,
	DCL_OPTIONS 	option) ;

DCL_STATUS (*DCL_DrvControl) (
	DCL_HANDLE         device_handle,
	DCL_CTRL_CMD       cmd, 
    void*   		   arg);

DCL_STATUS (*DCL_DrvRegisterCallback)(
	DCL_HANDLE		device_handle,
	DCL_EVENT		event,
	DCL_CALLBACK	callback,
	void*		    user_data,
	DCL_USER_ID  	user_id); 


DCL_STATUS (*DCL_DrvQuery)(
	DCL_HANDLE     device_handle,
	void*   		handle_status);

DCL_STATUS (*DCL_DrvClose)(DCL_HANDLE        device_handle);


}DEV_Operations;

typedef struct{

DCL_STATUS (*DCL_DrvQueryHandleWithMSG)(
	msg_type  		msg_id,	
	ilm_struct*		ilm,
	DCL_HANDLE*   	dev_handle);

}DEV_Utility;

typedef struct {
	DCL_EVENT event_id;
	msg_type  msg_id;
}DCL_EVENT_MSG_PAIR;

typedef struct {
	DCL_INT32 count;
	DCL_EVENT_MSG_PAIR*  event_msg_pairs;
}DCL_EVENT_MSG_MAP;




typedef struct{
	DCL_INT32 user_handle;
	DCL_UINT16 start_number;
	DCL_UINT16 end_number;
	DEV_Operations* dev_operations;
	DEV_Utility* dev_utility;
	DCL_EVENT_MSG_MAP* event_msg_map;
}DCL_DEVICE_T;


#endif  /* __DCL_COMMON_H__ */

