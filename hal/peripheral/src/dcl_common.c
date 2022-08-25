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
 *   dcl_common.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Implementation file of DCL (Driver Common Layer).
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


#include "dcl.h"
#include "drv_trc.h"
#include "drv_comm.h"
#include "kal_public_api.h"
#include "dcl_common_config.h"

 
#define DEV_GROUP_START_BIT 8
#define DEV_GROUP_MASK 0xFF
 //used to clear the bits of handle used by DCL
#define DCL_HANDLE_CLEAR_MASK 0xFF00FFFF
#define DCL_HANDLE_INDEX_FILTER 0xFF0000
#define DCL_HANDLE_INDEX_START_BIT 16

#define ATTACHED_MOD MOD_MMI

//global variable for this file
static DCL_INT32 dcl_device_num = (sizeof(Devices)/sizeof(DCL_DEVICE_T));
static DCL_CALLBACK mre_callback;
typedef DCL_UINT8 (*MSGHandler) (void *local_buf,module_type src_mod, ilm_struct* ilm );

#if !defined(EMPTY_MMI)
extern DCL_INT32 vm_pmng_get_app_handle();
extern void mmi_frm_set_protocol_event_handler(DCL_UINT16 eventID, MSGHandler funcPtr, DCL_BOOL isMultiHandler);
#endif
//extern void mre_callback(void* param, DCL_EVENT event,DCL_HANDLE handle);
//At present, the only callback to save is mre's callback.



static DCL_STATUS DCL_DummyFunction(DCL_HANDLE  device_handle){
	return STATUS_UNSUPPORTED;
}

DEV_Operations dummy_device = {
	(DCL_HANDLE (*)(DCL_DEV, DCL_FLAGS))DCL_DummyFunction,
	(DCL_STATUS (*)(DCL_HANDLE, DCL_BUFF *, DCL_BUFF_LEN, DCL_BUFF_LEN *, DCL_OPTIONS))DCL_DummyFunction,
	(DCL_STATUS (*)(DCL_HANDLE, DCL_BUFF *, DCL_BUFF_LEN, DCL_BUFF_LEN *, DCL_OPTIONS))DCL_DummyFunction,
	(DCL_STATUS (*)(DCL_HANDLE, DCL_CTRL_CMD, void *))DCL_DummyFunction,
	(DCL_STATUS (*)(DCL_HANDLE, DCL_EVENT, DCL_CALLBACK, void *,DCL_USER_ID))DCL_DummyFunction,
	(DCL_STATUS (*)(DCL_HANDLE, void *))DCL_DummyFunction,
	DCL_DummyFunction
};
//////////////////////////////////////////////////////////////////////////////
//internal used functions
//////////////////////////////////////////////////////////////////////////////
//the parameter handle is used to save the value of handle.
static DCL_STATUS RecordUserHandle(DCL_INT32* user_handle){
	task_indx_type task_index;
	task_index = kal_get_current_task_index();
	*user_handle = task_index;	
#if !defined(EMPTY_MMI)
	if(INDX_MMI==task_index){//make sure MRE
		*user_handle=vm_pmng_get_app_handle();
	}
#endif
	//pHandle = vm_pmng_get_app_handle();
	return STATUS_OK;
}

static DCL_STATUS	CheckIndexRange(DCL_INT32 dev_index){
	if (dev_index<0 || dev_index>=dcl_device_num){
		drv_trace1(TRACE_GROUP_1,DCL_COMMON_INVALID_DEV_INDEX,dev_index);
		return STATUS_FAIL;
	}
	return STATUS_OK;
}
//check the pointer is null or not;
//GOTO: check the pointer is in execution region or not;
static DCL_STATUS CheckFunctionPointer(void* pointer){
	DCL_STATUS status=STATUS_OK;
	if (NULL==pointer){
		drv_trace1(TRACE_GROUP_1,DCL_COMMON_INVALID_POINTER,(DCL_UINT32)pointer);
		status = STATUS_FAIL;
	}
	return status;
}

static DCL_STATUS SearchEvent_ID(msg_type msg_id, DCL_EVENT* event_id, DCL_INT32* dev_index ){
	DCL_INT32 i,j,pair_num;
	DCL_EVENT_MSG_PAIR* ev_msg_pairs;
	*event_id=EVENT_NULL;
	for(i=0;i<dcl_device_num;++i){
		pair_num=Devices[i].event_msg_map->count;
		if(0!=pair_num){
			ev_msg_pairs = Devices[i].event_msg_map->event_msg_pairs;
			for(j=0;j<pair_num;++j){
				if(msg_id==ev_msg_pairs[j].msg_id){
					*event_id = ev_msg_pairs[j].event_id;
					*dev_index = i;
					goto FOR_END;
				}
			}
		}
	}
FOR_END:
	drv_trace4(TRACE_GROUP_1,DCL_COMMON_SEARCH_EVENT_ID_RESULT,*dev_index,*event_id, msg_id,0);
	if(EVENT_NULL==*event_id){//EVENT_NULL
		return STATUS_FAIL;
	}else{
		return STATUS_OK;
	}
}
//MMI framework defined this function's prototype
static DCL_UINT8 DCL_MSGHandler (void *local_buf,module_type src_mod, ilm_struct* ilm ){
	msg_type msg_id;
	DCL_EVENT event_id;
	DCL_INT32 dev_index;
	DCL_HANDLE dev_handle;
	DCL_CB_ILM_DATA ilm_data;
	msg_id = ilm->msg_id;
	drv_trace4(TRACE_GROUP_2, DCL_COMMON_MSG_HANDLER ,src_mod,msg_id,(DCL_UINT32)ilm,0);
	if(STATUS_OK != SearchEvent_ID(msg_id,&event_id,&dev_index)){
		ASSERT(0);
	}else{
		if(STATUS_OK!=CheckFunctionPointer((void*)(Devices[dev_index].dev_utility->DCL_DrvQueryHandleWithMSG))){		
			EXT_ASSERT(0,0,0,0);//
		}
		Devices[dev_index].dev_utility->DCL_DrvQueryHandleWithMSG(msg_id,ilm,&dev_handle);	
		
		drv_trace2(TRACE_GROUP_2, DCL_COMMON_GOT_HANDLE_WITH_MSG,dev_index,dev_handle);
		
		dev_handle |= (dev_index<<DCL_HANDLE_INDEX_START_BIT);	
		
		
		ilm_data.local_para_ptr = (void*)ilm->local_para_ptr;
		ilm_data.peer_buff_ptr = (void*)ilm->peer_buff_ptr;
		mre_callback(&ilm_data,event_id,dev_handle);
		drv_trace1(TRACE_GROUP_2,DCL_COMMON_MSG_PROCESS_END,0);
		// unregister message handler? 
		//Should not unregister as there may be more than one user need the message. 
		//mmi_frm_clear_protocol_event_handler(msg_id, DCL_MSGHandler);//isMultiHandler
	}
	//must return 0 as this message maybe for other users. If not, MMI framework will not call other handler.
	return STATUS_OK;
}

#if !defined(EMPTY_MMI)
//This only for MRE to handle callback, as they can't receive message.
static DCL_STATUS RegisterCallbackForEvToMSG(
	DCL_INT32       dev_index,
	DCL_HANDLE		internal_handle,
	DCL_EVENT		event_id,
	DCL_CALLBACK	callback,
	void*			parameter){
	
	DCL_INT32 j,pair_num;
	DCL_EVENT_MSG_PAIR* ev_msg_pairs;
	msg_type msg_id=(msg_type)0;
	DCL_STATUS status=STATUS_OK;
	
	//search message id
	pair_num=Devices[dev_index].event_msg_map->count;
	if(0!=pair_num){
		ev_msg_pairs = Devices[dev_index].event_msg_map->event_msg_pairs;
		for(j=0;j<pair_num;++j){
			if(event_id==ev_msg_pairs[j].event_id){
				msg_id = ev_msg_pairs[j].msg_id;
				break;
			}
		}
	}
	drv_trace2(TRACE_GROUP_1,DCL_COMMON_SEARCH_MSG_ID_RESULT,event_id, msg_id);
	if(0!=msg_id){//it's message at driver
		//register multitimes will be no effect, same as register one time.
		//register to MMI default to be for multi user.
		mmi_frm_set_protocol_event_handler(msg_id, DCL_MSGHandler,DCL_TRUE);
		mre_callback = callback;
	}else{
		status = STATUS_INVALID_EVENT;
	}
	return status;
}
#endif
//////////////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////////////
// Initialize the common DCL. 
//It check the array is correct or not.
DCL_INT32 DCL_Common_Initialize(void){
	DCL_INT32 i;	
	for(i=0;i<dcl_device_num;i++){
		if ( NULL==Devices[i].dev_operations){
			drv_trace1(TRACE_GROUP_1,DCL_COMMON_DEV_DRV_NOT_REGISTER,i);
			ASSERT(0);
		}
		if(i<(dcl_device_num-1)){//check if the order of the device
			if (( Devices[i].start_number > Devices[i].end_number) ||
				( Devices[i].end_number > Devices[i+1].start_number)){
				drv_trace1(TRACE_GROUP_1,DCL_COMMON_DEV_INDEX_WRONG,i);
				ASSERT(0);
			}			
		}		
	}
	return 0;
}



///////////////////////////////////////////////////////////////////////////////////////////
//implementation for dcl interface.
///////////////////////////////////////////////////////////////////////////////////////////

#if 1 //this function  for search strategy for open.
DCL_HANDLE DCL_Open(DCL_DEV dev, DCL_FLAGS flags){
	DCL_INT32 dev_index;
	DCL_HANDLE handle=DCL_HANDLE_INVALID;
	
	drv_trace2(TRACE_GROUP_1, DCL_COMMON_OPEN,dev,flags);
	for(dev_index=0;dev_index<dcl_device_num;dev_index++){
		if ((Devices[dev_index].start_number <= dev) && (dev< Devices[dev_index].end_number)){
			if(STATUS_OK==CheckFunctionPointer((void*)(Devices[dev_index].dev_operations->DCL_DrvOpen))){
				handle = Devices[dev_index].dev_operations->DCL_DrvOpen(dev,flags);				
			}
			break;
		}		
	}
	RecordUserHandle(&(Devices[dev_index].user_handle));
	//There are several reason to use this if statement:
	//1. the bits 16~27 should not be used by driver.
	//2. if the open function of device driver returned error code, these bits must be non-zero(error code are negative numbers which are 0~ -65535)
	if ((0x0 != (handle & DCL_HANDLE_INDEX_FILTER))||(DCL_HANDLE_NONE==handle)){
		drv_trace2(TRACE_GROUP_1,DCL_COMMON_OPEN_INVALID_INTERAL_HANDLE,dev_index,handle);
		handle = DCL_HANDLE_INVALID;
	}else{
		handle |= (dev_index<<DCL_HANDLE_INDEX_START_BIT);
	}

	drv_trace2(TRACE_GROUP_2,DCL_COMMON_OPEN_RETURNED_HANDLE,dev_index,handle);
	
	return handle;
	
}

#else
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
#endif

DCL_STATUS DCL_Control (
	DCL_HANDLE       	device_handle,
	DCL_CTRL_CMD       cmd, 
    void*   arg){

	DCL_INT32 dev_index;
	DCL_HANDLE internal_handle;
	drv_trace4(TRACE_GROUP_2,DCL_COMMON_CONTROL,device_handle,cmd,(DCL_INT32)arg,0);
	dev_index = (device_handle & DCL_HANDLE_INDEX_FILTER)>>DCL_HANDLE_INDEX_START_BIT;//GetDeviceIndex(device_handle);
	if(STATUS_OK!=CheckIndexRange(dev_index)){		
		return STATUS_INVALID_DCL_HANDLE;
	}
	
	if(STATUS_OK!=CheckFunctionPointer((void*)(Devices[dev_index].dev_operations->DCL_DrvControl))){
		return STATUS_UNSUPPORTED;
	}
	RecordUserHandle(&(Devices[dev_index].user_handle));
	internal_handle = device_handle & DCL_HANDLE_CLEAR_MASK;
	return (Devices[dev_index].dev_operations->DCL_DrvControl(internal_handle,cmd,arg));	
}

DCL_STATUS DCL_Close(DCL_HANDLE      device_handle){
	DCL_INT32 dev_index;
	DCL_HANDLE internal_handle;

	dev_index = (device_handle & DCL_HANDLE_INDEX_FILTER)>>DCL_HANDLE_INDEX_START_BIT;//GetDeviceIndex(device_handle);
	drv_trace1(TRACE_GROUP_1,DCL_COMMON_CLOSE,device_handle);
	if(STATUS_OK!=CheckIndexRange(dev_index)){
		return STATUS_INVALID_DCL_HANDLE;
	}

	if(STATUS_OK!=CheckFunctionPointer((void*)(Devices[dev_index].dev_operations->DCL_DrvClose))){
		return STATUS_UNSUPPORTED;
	}

	Devices[dev_index].user_handle = 0;
	internal_handle = device_handle & DCL_HANDLE_CLEAR_MASK;
	return (Devices[dev_index].dev_operations->DCL_DrvClose(internal_handle));	
}


DCL_STATUS DCL_RegisterCallback(
	DCL_HANDLE		device_handle,
	DCL_EVENT		event_id,
	DCL_CALLBACK	callback,
	void*			parameter,
	DCL_USER_ID  	user_id){
	
	DCL_INT32 dev_index;
	DCL_HANDLE internal_handle;
	DCL_STATUS status=STATUS_OK;

	
	dev_index = (device_handle & DCL_HANDLE_INDEX_FILTER)>>DCL_HANDLE_INDEX_START_BIT;//GetDeviceIndex(device_handle);
	drv_trace4(TRACE_GROUP_1,DCL_COMMON_REGISTER_CALLBACK,device_handle,event_id,(DCL_INT32)callback,(DCL_INT32)parameter);

	if(STATUS_OK!=CheckIndexRange(dev_index)){
		return STATUS_INVALID_DCL_HANDLE;
	}	
	RecordUserHandle(&(Devices[dev_index].user_handle));
	internal_handle = device_handle & DCL_HANDLE_CLEAR_MASK;
#if !defined(EMPTY_MMI)
	if(DCL_USER_MRE==user_id){//only for MRE
		status = RegisterCallbackForEvToMSG(dev_index,internal_handle,event_id,callback,parameter);
	}
#endif
	//always call the register function of dirver, event it is a message for driver.
	//the reason is some driver need the user_id to determine use the callback or the message.
	if(STATUS_OK!=CheckFunctionPointer((void*)(Devices[dev_index].dev_operations->DCL_DrvRegisterCallback))){
		if((DCL_USER_MRE!=user_id) ){
			status = STATUS_UNSUPPORTED;
		}
	}else{
		status=Devices[dev_index].dev_operations->DCL_DrvRegisterCallback(internal_handle,event_id,callback,parameter,user_id);
	}	
	return status;
}
	
DCL_STATUS DCL_Query(
	DCL_HANDLE     device_handle,
	void*   		handle_status){
	
	DCL_INT32 dev_index;
	DCL_HANDLE internal_handle;
	
	dev_index = (device_handle & DCL_HANDLE_INDEX_FILTER)>>DCL_HANDLE_INDEX_START_BIT;//GetDeviceIndex(device_handle);
	drv_trace2(TRACE_GROUP_1,DCL_COMMON_QUERY,device_handle,(DCL_INT32)handle_status);


	if(STATUS_OK!=CheckIndexRange(dev_index)){
		return STATUS_INVALID_DCL_HANDLE;
	}

	if(STATUS_OK!=CheckFunctionPointer((void*)(Devices[dev_index].dev_operations->DCL_DrvQuery))){
		return STATUS_UNSUPPORTED;
	}
	RecordUserHandle(&(Devices[dev_index].user_handle));
	internal_handle = device_handle & DCL_HANDLE_CLEAR_MASK;
	return (Devices[dev_index].dev_operations->DCL_DrvQuery(internal_handle,handle_status));	
}
		 
DCL_STATUS  DCL_Read(
	DCL_HANDLE   	device_handle, 
	DCL_BUFF*       buf, 
	DCL_BUFF_LEN 	read_len, 
	DCL_BUFF_LEN *	returned_len,
	DCL_OPTIONS 	options){
	
	DCL_INT32 dev_index;
	DCL_HANDLE internal_handle;
	
	dev_index = (device_handle & DCL_HANDLE_INDEX_FILTER)>>DCL_HANDLE_INDEX_START_BIT;//GetDeviceIndex(device_handle);
	drv_trace8(TRACE_GROUP_6,DCL_COMMON_READ,device_handle,(DCL_INT32)buf,read_len,(DCL_INT32)returned_len,options,0,0,0);

	if(STATUS_OK!=CheckIndexRange(dev_index)){
		return STATUS_INVALID_DCL_HANDLE;
	}

	if(STATUS_OK!=CheckFunctionPointer((void*)(Devices[dev_index].dev_operations->DCL_DrvRead))){
		return STATUS_UNSUPPORTED;
	}
	RecordUserHandle(&(Devices[dev_index].user_handle));
	internal_handle = device_handle & DCL_HANDLE_CLEAR_MASK;
	return (Devices[dev_index].dev_operations->DCL_DrvRead(internal_handle,buf,read_len,returned_len,options));	

}
	
DCL_STATUS  DCL_Write(
	DCL_HANDLE 		device_handle, 
	DCL_BUFF* 		buf, 
	DCL_BUFF_LEN 	write_len, 
	DCL_BUFF_LEN* 	written_len,
	DCL_OPTIONS 	options){
	
	DCL_INT32 dev_index;
	DCL_HANDLE internal_handle;
	
	dev_index = (device_handle & DCL_HANDLE_INDEX_FILTER)>>DCL_HANDLE_INDEX_START_BIT;//GetDeviceIndex(device_handle);
	drv_trace8(TRACE_GROUP_6,DCL_COMMON_WRITE,device_handle,(DCL_INT32)buf,write_len,(DCL_INT32)written_len,options,0,0,0);
	if(STATUS_OK!=CheckIndexRange(dev_index)){
		return STATUS_INVALID_DCL_HANDLE;
	}

	if(STATUS_OK!=CheckFunctionPointer((void*)(Devices[dev_index].dev_operations->DCL_DrvWrite))){
		return STATUS_UNSUPPORTED;
	}
	RecordUserHandle(&(Devices[dev_index].user_handle));
	internal_handle = device_handle & DCL_HANDLE_CLEAR_MASK;
	return (Devices[dev_index].dev_operations->DCL_DrvWrite(internal_handle,buf,write_len,written_len,options)); 

}

DCL_MODULE_TYPE DCL_GetDestinationID(DCL_USER_ID user_id){
	
	//Return the attached mod id for receive message.
	return (DCL_MODULE_TYPE)ATTACHED_MOD;
}






