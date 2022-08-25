/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_cmmb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  CMMB Function header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#if defined(__CMMB_SUPPORT__)

#ifndef _FT_FNC_CMMB_H_
#define _FT_FNC_CMMB_H_
#include "app_ltlcom.h"
#define CMMB_BUFFER_SIZE_FROM_MED 524288    //512*1024
//#define FT_BUFFER_SIZE_FROM_MED_FOR_CMMB   3145728   //3*1024*1024
//#define FT_CMMB_DATA_FRAME_SIZE 1800

/*
enum FT_CMMB_STORE_METHOD
{
	  FT_CMMB_STORE_NONE = 0,
	  FT_CMMB_STORE_IN_FAT,
	  FT_CMMB_STORE_IN_MEMORY
};
*/
/*
enum FT_CMMB_SEL_SERVICE_CMD_TYPE
{
   FT_CMMB_SEL_SERVICE_STORE_IN_FAT =0,
   FT_CMMB_SEL_SERVICE_NO_STORE,
   FT_CMMB_SEL_SERVICE_STORE_IN_MEMORY,
   FT_CMMB_SEL_SERVICE_READ_FROM_MEMORY
};
*/
/*
enum FT_CMMB_SEL_SERVICE_CNF_TYPE
{
	FT_CMMB_SEL_SERVICE_ALL = 0, // including select service only, store in FAT/ borrowed MED memory
	FT_CMMB_STORE_IN_FAT_FAIL,
	FT_CMMB_STORE_IN_MED_MEMORY_FAIL,
	FT_CMMB_GET_DATA_FROM_MED_MEMORY
};
*/
/*
enum FT_CMMB_SEL_SERVICE_RESULT_TYPE
{
	FT_CMMB_SEL_SERVICE_SUCCESS = 0,
	FT_CMMB_FAT_DISK_IS_FULL,
	FT_CMMB_FAT_OTHER_ERROR,
	FT_CMMB_MED_MEMORY_NOT_EXIST,
	FT_CMMB_MED_MEMORY_NOT_ENOUGH,
	FT_CMMB_MED_MEMORY_READ_FAIL,
	FT_CMMB_ENSEMBLE_NOT_EXIST,
	FT_CMMB_SERVICE_NOT_EXIST,
	FT_CMMB_SUB_CHANNEL_NOT_EXIST,
	FT_CMMB_DEMO_STATE_ERROR,
	FT_CMMB_BAND_NOT_EXIST,
	FT_CMMB_FREQ_NOT_EXIST,
	FT_CMMB_UNKNOW_ERROR_RESULT	
		
};

*/
void FT_CMMB_Operation(ilm_struct *ptrMsg);
void FT_CMMB_SEND_CNF_BACK(ilm_struct *ptrMsg);


#endif 
 
#endif //#if defined(__CMMB_SUPPORT__)
 
