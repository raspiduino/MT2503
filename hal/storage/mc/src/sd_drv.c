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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ms_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Adaption driver of file system for SD card
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef DRV_MSDC_OFF
//RHR ADD
#include "kal_public_defs.h"
//#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
//RHR REMOVE
/*
#include "kal_release.h"
#include "kal_non_specific_general_types.h"
#include "app_buff_alloc.h"
#include "fat_fs.h"
#if defined(__MSDC_MS__)
#include "ms_def.h"
#endif
#include "init.h"
*/
//RHR
#include "kal_trace.h"
#include "kal_general_types.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "drv_comm.h"
#include "drv_features.h"
#include "drvpdn.h"
#include "stack_config.h"
#include "SST_sla.h"
#if !defined(__UBL__) || defined(__CARD_DOWNLOAD__) 
#include "msdc_reg_adap.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "intrCtrl.h"
#include "msdc_lsd.h"
#include "Drv_trc.h"
#if defined(__AUDIO_DSP_LOWPOWER__)
#include "audlp_exp.h"
#endif

#include "cache_sw.h"

//! EMB
#include "init.h"
#include "page.h"

#ifdef DCL_MSDC_INTERFACE
#include "dcl.h"
#endif


#define MAX_CLUSTERS (0x0FFF6 - 2)
#define MSDC_MEDIA_DESCRIPTOR		0xF8
#define SD_MAX_RETRY	2

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
kal_semid dualMsdcArb;
#endif

#ifdef DRV_MSDC_HW_CONTENTION
kal_semid dclMsdcArb;
typedef struct{
	kal_uint32	callerRetAddr;
	kal_uint32	ownerThdId;
} SD_ARB_DBG;
static SD_ARB_DBG	sdArbDbg;
#endif



extern kal_bool INT_USBBoot(void);

#ifdef __DRV_MSDC_ENHANCE_FORMAT_BY_ERASE__
kal_bool useEraseOnFormat = KAL_TRUE;
#else
kal_bool useEraseOnFormat = KAL_FALSE;
#endif



#define DEMP_LOCK(addr, size)
#define DEMP_UNLOCK(addr, size)

#if defined(DCL_MSDC_INTERFACE)


/*
	2008/12/16
	sd driver was protected under file system, and now we have to share the resource with CAS CMD and SDIO
	we have implemented new architecture by DCL ways, but DCL haven't been QC and 
	maybe dangerous to enable it in 08B. We adopt SIM driver's method to import new control interface without the 
	change of file system.
*/

int  MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);

#ifdef DRV_MSDC_HW_CONTENTION
void SD_setArbRetAddr(kal_uint32 retAddr)
{
	sdArbDbg.callerRetAddr = retAddr;
}

void SD_setArbThdId(kal_uint32 ThdId)
{
	sdArbDbg.ownerThdId = ThdId;
}
#endif


int  ReadSectors_NEW(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer)
{
	int status;
    
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
sd_select_enum sel;
#endif    
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

#ifdef DRV_MSDC_HW_CONTENTION
	kal_uint32 retAddr;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */

	if(NULL == dclMsdcArb)
		ASSERT(0);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here before calling ReadSectors*/
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}

#endif//DRV_MSDC_HW_CONTENTION

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
			kal_take_sem(dualMsdcArb, 1);
	}
#endif//DRV_MSDC_HW_CONTENTION

   #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
   {
      sel = SD_EXT;
   }
	else
   {
      sel = SD_T_CARD_2;
   }
	get_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
  #else
	get_MSDC_lock(&gSD->mSDdrv_lock);
  #endif

	/*switch related control*/
#ifdef DRV_MSDC_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
#endif
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_Switch_SDIO(SD_EXT);
#endif

	status = ReadSectors(DriveData, Sector, Sectors, Buffer);

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    free_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
#else
	free_MSDC_lock(&gSD->mSDdrv_lock);
#endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
		kal_give_sem(dualMsdcArb);
	}
#endif
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
	return status;

}

#if defined(__UBL__)
#pragma arm section code = "EXT_BOOTLOADER_CODE", rwdata = "EXT_BOOTLOADER_RW", zidata = "EXT_BOOTLOADER_ZI"
#endif

static int  WriteSectors_NEW(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer)
{
	int status;
 	#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
   	#endif    
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

#ifdef DRV_MSDC_HW_CONTENTION
	kal_uint32 retAddr;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */

	if(NULL == dclMsdcArb)
		ASSERT(0);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here before calling WriteSectors*/
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}
#endif//DRV_MSDC_HW_CONTENTION
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
		{
			kal_take_sem(dualMsdcArb, 1);
                }
#endif	
	/*switch related control*/
#ifdef DRV_MSDC_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
#endif
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_Switch_SDIO(SD_EXT);
#endif



   #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
   {
      sel = SD_EXT;
   }
	else
   {
      sel = SD_T_CARD_2;
   }
	get_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
  #else
	get_MSDC_lock(&gSD->mSDdrv_lock);
  #endif

	/*switch related control*/
#ifdef DRV_MSDC_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
#endif
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_Switch_SDIO(SD_EXT);
#endif


	status = WriteSectors(DriveData, Sector, Sectors, Buffer);

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
  free_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
#else
	free_MSDC_lock(&gSD->mSDdrv_lock);
#endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
		{
			kal_give_sem(dualMsdcArb);
		}
#endif
#ifdef DRV_MSDC_HW_CONTENTION
	if(kal_query_systemInit()== KAL_FALSE){
		/*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
		SD_setArbThdId(NULL);		
		kal_give_sem(dclMsdcArb);
	}
#endif
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
	return status;

}

#if defined(__UBL__)
#pragma arm section code, rwdata, zidata
#endif

int  MountDevice_NEW(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags)
{
	int status;
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    sd_select_enum sel;
#endif 

#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

#ifdef DRV_MSDC_HW_CONTENTION
	kal_uint32 retAddr;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */

	if(NULL == dclMsdcArb)
		dclMsdcArb = kal_create_sem("MSDC lock", 1);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here before calling MountDevice*/
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}
#endif//DRV_MSDC_HW_CONTENTION
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
		{
			kal_take_sem(dualMsdcArb, 1);
	         }
#endif

 #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
          if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
         {
            sel = SD_EXT;
         }
          else
         {
            sel = SD_T_CARD_2;
         }
		  init_MSDC_lock(&gSD_blk[0].mSDdrv_lock, "SD_DRV_LOCK");
    get_MSDC_lock(&gSD_blk[0].mSDdrv_lock);	    
#else
		init_MSDC_lock(&gSD->mSDdrv_lock, "SD_DRV_LOCK");
		get_MSDC_lock(&gSD->mSDdrv_lock);
#endif	

	/*switch related control*/
#ifdef DRV_MSDC_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
#endif
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_Switch_SDIO(SD_EXT);
#endif

	status = MountDevice(DriveData, DeviceNumber, DeviceType, Flags);

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
        free_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
#else
        free_MSDC_lock(&gSD->mSDdrv_lock);
#endif
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
		{
			kal_give_sem(dualMsdcArb);
		}
#endif

#ifdef DRV_MSDC_HW_CONTENTION
	if(kal_query_systemInit()== KAL_FALSE){
		/*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
		SD_setArbThdId(NULL);		
		kal_give_sem(dclMsdcArb);
	}
#endif
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
	return status;

}

static int  DiscardSectors(void * DriveData, kal_uint32 Sector, UINT Sectors)
{
   return FS_NO_ERROR;
}

/*-----------------------------------*/
extern void MSDC_TimeOutHandler(void *parameter);
int  ReadSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer)
{
	kal_uint8 retry = 0;
	kal_uint32 time1, time2;
	DCL_STATUS dclStatus = 0;
	SD_CTRL_READ_T data;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	DCL_BOOL isCardExist = KAL_FALSE;
	DCL_BOOL isCardInited = KAL_FALSE;
	DCL_BOOL isFFRunning = KAL_FALSE;
    kal_int32 Status;

	#if !defined(__UBL__)
	DCL_HANDLE gpt_block_time=0;
	SGPT_CTRL_START_T start;
	#endif
  
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif
	isFFRunning |=0;
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
   {
		sel = SD_EXT;
	}
	else
   {
		sel = SD_T_CARD_2;
	}

   if(sel==SD_EXT)
	{
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return FS_MSDC_READ_SECTOR_ERROR;	
   }
   else
   {
      #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return FS_MSDC_READ_SECTOR_ERROR;
      #else
         ASSERT(0);
      #endif
   }
	prSwitch.u4TargetInterface=sel;
	DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
   #else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
   if(dclHandle == DCL_HANDLE_INVALID)
      return FS_MSDC_READ_SECTOR_ERROR;
#endif

    do {
        
	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
	if (!isCardExist)
	{		
		DclSD_Close(dclHandle);
		return FS_MSDC_MOUNT_ERROR;
	}
	
	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_INITED, (DCL_CTRL_DATA_T*)&isCardInited);
	drv_trace8(TRACE_GROUP_6, MSDC_INFORM_READSECTOR_ENTRY, (kal_uint32)DriveData, Sector, Sectors, (kal_uint32)Buffer, 
		(kal_uint32)kal_get_current_thread_ID(), MSDC_Reg32(MSDC_CFG), isCardExist, isCardInited);
	
#ifdef	__DRV_MSDC_FAST_FORMAT__
	/*since there is no readSectors command enclosed in fast format, this flag should be always flase when we do readSectors*/
	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_FAST_FORMAT_RUNNING, (DCL_CTRL_DATA_T*)&isFFRunning);
	if (KAL_TRUE == isFFRunning)
		ASSERT(0);
#endif

    Status = FS_NO_ERROR;
	time1 |=0;
	time1 = drv_get_current_time();
	drv_trace4(TRACE_GROUP_6, MSDC_INFORM_READSECTOR_START, time1, retry, gSD->sd_r, MSDC_Reg32(MSDC_IOCON));

	data.bufferAddr = Buffer;
	data.u4Sector = Sector;
	data.u4Sectors = Sectors;
        // open gpt timer first for performance problems.
	#if !defined(__UBL__) && !defined(__FUE__)
	gpt_block_time=DclSGPT_Open(DCL_GPT_CB,0);
	start.u2Tick=300+Sectors;
	start.pfCallback=MSDC_TimeOutHandler;
	start.vPara=NULL;
	DclSGPT_Control(gpt_block_time,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
	#endif
	dclStatus = DclSD_Control(dclHandle, SD_CTRL_CMD_READ, (DCL_CTRL_DATA_T*)&data);
	#if !defined(__UBL__) && !defined(__FUE__)
	DclSGPT_Control(gpt_block_time,SGPT_CMD_STOP,0);
	DclSGPT_Close(&gpt_block_time);
	#endif


	time2 = drv_get_current_time();
	drv_trace4(TRACE_GROUP_6, MSDC_INFORM_READSECTOR_END, dclStatus, time2,
		(kal_uint32)kal_get_current_thread_ID(), (double)(Sectors*32768*5)/((time2-time1)*10));


	if(dclStatus != STATUS_OK )
	{		
		gSD->sd_r++;
		if(kal_query_systemInit()== KAL_TRUE)
		{
			/*12/26, Blue remove this to enable read retry in booting up*/
			#if defined(MSDC_TRACE_LEVEL3)
			MSDC_add_dbg_msg(msdc_dbg_event_SD_read_fail_systemInit, dclStatus, gSD->sd_r);
			#endif
			//MSDC_PDNControl(KAL_TRUE);
			//return FS_MSDC_READ_SECTOR_ERROR;
		}

        if (dclStatus == STATUS_ERROR_TIMEOUT ||
            dclStatus == STATUS_ERROR_WRONG_STATE) {

            if (retry >= 1) {
                Status = FS_MSDC_READ_SECTOR_ERROR;
                break;
            }
            
            retry++;
            
            kal_print("[MSDC]: Error recover(read cmd timeout)");
            //gMSDC_Handle->mIsInitialized = KAL_FALSE;
            DclSD_Control(dclHandle, SD_CTRL_CMD_GO_IDLE, NULL);
            
            if (DclSD_Control(dclHandle, SD_CTRL_CMD_INIT, NULL) != STATUS_OK) {
                Status = FS_MSDC_READ_SECTOR_ERROR;
                break;
            }
        }
        else {

            kal_print("[MSDC]: Error recover(read crc or gpt timeout error)");
            
            {
                //
                // The following flow has three points:
                // 1. Slow down clock.
                // 2. Switch to 1-bit.
                // 3. All methods failed, we have no idea and let it go.
                //
#ifdef	DRV_MSDC_CLK_SEARCH			          
                if((gMSDC_Handle->msdc_clkTuneUpperBund - 50) >= 12000) {
                    gMSDC_Handle->msdc_clkTuneUpperBund = gMSDC_Handle->msdc_clkTuneUpperBund - 50;
                }
                else 
#endif                

#ifdef MSDC_SD_BITS4_BUS
                if (gMSDC_Handle->trySingleLine != KAL_TRUE) {
                    gMSDC_Handle->trySingleLine = KAL_TRUE;
                }
                else 
#endif                
                {
                    Status = FS_MSDC_READ_SECTOR_ERROR;
                    break;
                }

                //gMSDC_Handle->mIsInitialized = KAL_FALSE;
                DclSD_Control(dclHandle, SD_CTRL_CMD_GO_IDLE, NULL);
                
                if (DclSD_Control(dclHandle, SD_CTRL_CMD_INIT, NULL) != STATUS_OK) {               
                //if (SD_Initialize() != NO_ERROR) {
                    Status = FS_MSDC_READ_SECTOR_ERROR;
                    break;
                }
                
            }        
        }        
	} // end of if error
    
    } while(dclStatus != STATUS_OK);
	
#if defined(__WRITE_THROUGH_CACHEABLE__) && !defined(__UBL__)
/* under construction !*/
#endif

	DclSD_Close(dclHandle);
	//return FS_NO_ERROR;
	return Status;
}

/*-----------------------------------*/

#if defined(__UBL__)
#pragma arm section code = "EXT_BOOTLOADER_CODE", rwdata = "EXT_BOOTLOADER_RW", zidata = "EXT_BOOTLOADER_ZI"
#endif
int WriteSectors(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer)
{
	//SDC_CMD_STATUS status;
	kal_uint8 retry = 0;
	//kal_uint32 adrs;
	kal_uint32 time1, time2;
	DCL_STATUS dclStatus = 0;
	SD_CTRL_READ_T data;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	//kal_uint32 timeout_count = 0;
	DCL_BOOL isCardExist = DCL_FALSE;
	DCL_BOOL isCardInited = KAL_FALSE;
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif

    DEMP_LOCK(Buffer, DCL_SECTOR_SIZE * Sectors);
    
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
   {
		sel = SD_EXT;
   }
	else
   {
		sel = SD_T_CARD_2;
	}

   if(sel==SD_EXT)
	{
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return FS_MSDC_WRITE_SECTOR_ERROR;	
   }
   else
   {
      #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return FS_MSDC_WRITE_SECTOR_ERROR;
      #else
         ASSERT(0);
      #endif
   }
	prSwitch.u4TargetInterface=sel;  
	DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
   #else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
   if(dclHandle == DCL_HANDLE_INVALID)
      return FS_MSDC_WRITE_SECTOR_ERROR;
#endif

	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_INITED, (DCL_CTRL_DATA_T*)&isCardInited);
	drv_trace8(TRACE_GROUP_6, MSDC_INFORM_WRITESECTOR_ENTRY, (kal_uint32)DriveData, Sector, Sectors, (kal_uint32)Buffer, 
		(kal_uint32)kal_get_current_thread_ID(), MSDC_Reg32(MSDC_CFG), isCardExist, isCardInited);

if(!isCardExist)
{
    DclSD_Control(dclHandle, SD_CTRL_CMD_POLL_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
    if(!isCardExist)
    {
        DclSD_Close(dclHandle);
        return FS_MSDC_MOUNT_ERROR;
    }
}
	
	gMSDC_Handle->timeout_count = 0;	
start:
	retry++;
	time1 |=0;
	time1 = drv_get_current_time();
	drv_trace4(TRACE_GROUP_6, MSDC_INFORM_WRITESECTOR_START, time1, retry, gSD->sd_w, 0);

	MSDC_SLA_Start_Logging("SDW");

	data.bufferAddr = Buffer;
	data.u4Sector = Sector;
	data.u4Sectors = Sectors;
	dclStatus = DclSD_Control(dclHandle, SD_CTRL_CMD_WRITE, (DCL_CTRL_DATA_T*)&data);
	//if (dclStatus == STATUS_ERROR_WRONG_STATE)
	//{
	//	DclSD_Close(dclHandle);
	//   DEMP_UNLOCK(Buffer, DCL_SECTOR_SIZE * Sectors);
	//	return FS_MSDC_WRITE_SECTOR_ERROR;
	//}
			
	MSDC_SLA_Stop_Logging("SDW");
	time2 |=0;
	time2 = drv_get_current_time();
	drv_trace4(TRACE_GROUP_6, MSDC_INFORM_WRITESECTOR_END, dclStatus, time2,
		(kal_uint32)kal_get_current_thread_ID(), (double)(Sectors*32768*5)/((time2-time1)*10));


	if(dclStatus != STATUS_OK)
	{
		gSD->sd_w++;
		if(kal_query_systemInit()== KAL_TRUE)
		{
			DclSD_Close(dclHandle);
		    DEMP_UNLOCK(Buffer, DCL_SECTOR_SIZE * Sectors);
			return FS_MSDC_WRITE_SECTOR_ERROR;
		}
		//dbg_print("write retry:%d,status:%d,total %d\r\n",retry,status,sd_w);
		if( (dclStatus == STATUS_ERROR_TIMEOUT) || (dclStatus==STATUS_ERROR_CRCERROR) )  //Light 111029
			gMSDC_Handle->timeout_count++;
		if(gMSDC_Handle->timeout_count > 0 && gMSDC_Handle->timeout_count <3  && gMSDC_Handle->mIsPresent == KAL_TRUE) //Light 111029
		{
			kal_print("[MSDC]:SD re-mount (write fail)");
			DclSD_Control(dclHandle, SD_CTRL_CMD_GO_IDLE, NULL);
		//guilin remove	retry = 0;
#ifdef	DRV_MSDC_CLK_SEARCH			
			if(12000 <= (gMSDC_Handle->msdc_clkTuneUpperBund - 50)){//we only allow 12M as lowest CLK
				gMSDC_Handle->msdc_clkTuneUpperBund = gMSDC_Handle->msdc_clkTuneUpperBund - 50;
			}
#endif			
			if(DclSD_Control(dclHandle, SD_CTRL_CMD_INIT, NULL) != STATUS_OK)
			{
				DclSD_Close(dclHandle);
			    DEMP_UNLOCK(Buffer, DCL_SECTOR_SIZE * Sectors);
				return FS_MSDC_WRITE_SECTOR_ERROR;
			}
		}		
		if(retry >= SD_MAX_RETRY)
		{
			DclSD_Close(dclHandle);
		    DEMP_UNLOCK(Buffer, DCL_SECTOR_SIZE * Sectors);
			return FS_MSDC_WRITE_SECTOR_ERROR;
		}
		else
		{
			// kal_prompt_trace(MOD_AUD,"CRC write Error retry %d",retry);
			goto start;			
		}
	}

	DclSD_Close(dclHandle);
    DEMP_UNLOCK(Buffer, DCL_SECTOR_SIZE * Sectors);
	return FS_NO_ERROR;
}

#if defined(__UBL__)
#pragma arm section code, rwdata, zidata
#endif

#if !defined(__FUE__) && !defined(__UBL__)
void SD_SelfFormat(void)
{
    
    FS_PartitionRecord Par;
    //static kal_uint8 p[512];

    kal_mem_set((void*)&Par, 0, sizeof Par);
    if(0x20000000000ULL > gSD->mCSD.capacity){
    	Par.Sectors = (kal_uint32)(gSD->mCSD.capacity/512);
    }
    else{
    	ASSERT(0);
    }
 
        FS_CreateMasterBootRecord(MSDC_Sector, &Par);
 
        WriteSectors(gMSDC_Handle, 0, 1, MSDC_Sector);
 
    Par = ((FS_MasterBootRecord *)MSDC_Sector)->PTable[0];
    FS_CreateBootSector((void*)MSDC_Sector, &Par, 0xF8, 0, FS_FMT_SINGLE_FAT );
    WriteSectors(gMSDC_Handle, Par.RelativeSector, 1, MSDC_Sector);
 /*  End of SelfFormat */

}
#endif//__UBL__

/*-----------------------------------*/
int  MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags)
{	
	kal_uint8 retry = 0;
	DCL_STATUS dclStatus = 0;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	DCL_BOOL isCardExist = DCL_FALSE;
	DCL_BOOL isCardInited = KAL_FALSE;
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)	
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
   {
		sel = SD_EXT;
   }
	else
	{
		sel = SD_T_CARD_2;
	}
   if(sel==SD_EXT)
	{
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return FS_MSDC_MOUNT_ERROR;	
   }
   else
   {
      #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         return FS_MSDC_MOUNT_ERROR;
      #else
         ASSERT(0);
      #endif
   }
	prSwitch.u4TargetInterface=sel; 
	DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
   #else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
   if(dclHandle == DCL_HANDLE_INVALID)
      return FS_MSDC_MOUNT_ERROR;
#endif

	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_INITED, (DCL_CTRL_DATA_T*)&isCardInited);
	if(isCardInited)
	{
		DclSD_Close(dclHandle);
		return DCL_SECTOR_SIZE;
	}
	gMSDC_Handle->is_init_timeout = KAL_FALSE;		

	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
	if(!isCardExist)
	{		
		//dbg_print("not present \r\n");
		
		#if defined(_NAND_FLASH_BOOTING_)
		// add the following code for solving plug in or out the SD card during 
		// NFB loading process. The card detection interruptwill disapperared 		 
		// while interrupt controller is masked.

		DclSD_Control(dclHandle, SD_CTRL_CMD_POLL_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);

		#endif // _NAND_FLASH_BOOTING_
		
		if (!isCardExist)
		{
			DclSD_Close(dclHandle);
			return FS_MSDC_MOUNT_ERROR;
		}
	}
start:

	dclStatus = DclSD_Control(dclHandle, SD_CTRL_CMD_INIT, NULL);
	if (dclStatus != STATUS_OK)
		goto err_exit;

	//if(SD_MountDevice(DeviceType) != FS_NO_ERROR)
		//return FS_MSDC_MOUNT_ERROR;

	//dbg_print("Mount success! \r\n");

	DclSD_Close(dclHandle);

	init_MSDC_lock(&gSD->mSDdrv_lock, "SD_DRV_LOCK");
	
	return DCL_SECTOR_SIZE;
   
err_exit:
	if(retry++ <= SD_MAX_RETRY && gMSDC_Handle->is_init_timeout == KAL_FALSE && ERR_CMDOK_DATREADFAIL != dclStatus)
	{
		//dbg_print("SD MountDevice failed! retry: %d \r\n",retry);
		goto start;
	}

	/*these cards do not support hot plug and we should set it not present now*/
	#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)

	if(INT_USBBoot() == KAL_TRUE && current_card == SD_T_CARD_2)
	{
		isCardExist = KAL_FALSE;
		DclSD_Control(dclHandle, SD_CTRL_CMD_SET_CLEAR_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
	}
	#endif //__SIM_PLUS__ or DRV_MSDC_DUAL_TCARD_BY_SWITCH

	DclSD_Close(dclHandle);
	gMSDC_Handle->mIsPresent=KAL_FALSE;
	return FS_MSDC_MOUNT_ERROR;
	
}


/*-----------------------------------*/
static int  MediaChanged(void * DriveData)
{
	//DCL_STATUS dclStatus = 0;
	kal_bool everPlugOut = KAL_FALSE;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	kal_bool isCardExist = (kal_bool)DCL_FALSE;
	DCL_BOOL isCardInited = KAL_FALSE;
        int status;
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
 if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
			kal_take_sem(dualMsdcArb, 1);			
	}
 #endif

   #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
   {
		sel = SD_EXT;
   }
	else
   {
      sel = SD_T_CARD_2;

   }

  if(sel==SD_EXT)
	{
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         {
            #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 	
	         if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
            {
               kal_give_sem(dualMsdcArb);
            }
            #endif
         return FS_MSDC_READ_SECTOR_ERROR;	
         }
   }
   else
   {
      #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
      if (dclHandle == DCL_HANDLE_INVALID)
         {
            #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 	
	         if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
            {
               kal_give_sem(dualMsdcArb);
            }
            #endif            
            return FS_MSDC_READ_SECTOR_ERROR;
         }
      #else
		ASSERT(0);
      #endif
   }	  
   
   	prSwitch.u4TargetInterface=sel; 	  
	DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
   #else
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
   if(dclHandle == DCL_HANDLE_INVALID)
      return FS_MSDC_READ_SECTOR_ERROR; //safe for normal case
#endif
	
	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);

	MSDC_turnOnVMC(isCardExist);


	if(isCardExist)
	{
		DclSD_Control(dclHandle, SD_CTRL_CMD_IS_INITED, (DCL_CTRL_DATA_T*)&isCardInited);
		if(isCardInited)
		{
			DclSD_Control(dclHandle, SD_CTRL_CMD_RESET_EVER_PLUGOUT, NULL);

			//DclSD_Close(dclHandle);
   	   	status=FS_NO_ERROR;
   		goto Error;
		}
		else
		{

			/*current state is present not mount, we have to check whether it plug out before*/
			DclSD_Control(dclHandle, SD_CTRL_CMD_QUERY_EVER_PLUGOUT, (DCL_CTRL_DATA_T*)&everPlugOut);
			if(KAL_TRUE == everPlugOut){
				/*send FMT a new message, and return plug out*/
				DclSD_Control(dclHandle, SD_CTRL_CMD_RESET_EVER_PLUGOUT, NULL);
	#if !defined(FMT_NOT_PRESENT)
				MSDC_SendCardInd(MOD_FMT, SD_EXT, MSG_ID_MSDC_CARD_DETECT_IND);
	#endif
				//DclSD_Close(dclHandle);
				status=FS_MSDC_NOT_PRESENT;
				goto Error;
			}
			DclSD_Control(dclHandle, SD_CTRL_CMD_RESET_EVER_PLUGOUT, NULL);

			//DclSD_Close(dclHandle);
			status=FS_MSDC_PRESNET_NOT_READY;
			goto Error;
		}
	}
	DclSD_Control(dclHandle, SD_CTRL_CMD_RESET_EVER_PLUGOUT, NULL);

		status=FS_MSDC_NOT_PRESENT;
Error:	
	DclSD_Close(dclHandle);
   #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
		{
			kal_give_sem(dualMsdcArb);
		}
   #endif
	return status;
}

/*-----------------------------------*/
static int GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
	DCL_BOOL isCardExist = DCL_FALSE;
	DCL_BOOL isCardInited = KAL_FALSE;
	int status = FS_NO_ERROR;
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
	SD_CTRL_ANALOG_SWITCH_T prSwitch;
#endif

    #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
		kal_take_sem(dualMsdcArb, 1);			
    }	    	 
    #endif
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
   {
		sel = SD_EXT;
   }
	else
   {
      sel = SD_T_CARD_2;
   }
    get_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
   if(sel==SD_EXT)
	{
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
        if (dclHandle == DCL_HANDLE_INVALID) {
            status = FS_MSDC_READ_SECTOR_ERROR;	
            goto err_exit;
        }
    }
	else
   {
      #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
      dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
        if (dclHandle == DCL_HANDLE_INVALID) {
            status = FS_MSDC_READ_SECTOR_ERROR;
            goto err_exit;
        }
      #else
         ASSERT(0);
      #endif
   }
	  
	prSwitch.u4TargetInterface=sel; 	   
	DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&prSwitch);
	  
   #else
   get_MSDC_lock(&gSD->mSDdrv_lock);
   dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
    if(dclHandle == DCL_HANDLE_INVALID) {
        status = FS_MSDC_READ_SECTOR_ERROR;
        goto err_exit;
    }
#endif

	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);
	DclSD_Control(dclHandle, SD_CTRL_CMD_IS_INITED, (DCL_CTRL_DATA_T*)&isCardInited);
	if(isCardExist && isCardInited){
		kal_mem_set((void*)DiskGeometry, 0, sizeof * DiskGeometry);
		if(0x20000000000ULL > gSD->mCSD.capacity){
			DiskGeometry->Sectors = (kal_uint32)(gSD->mCSD.capacity/512);
   		}
	   	else{
	   	    DclSD_Close(dclHandle);
	   	    status = FS_MSDC_NOT_PRESENT;
	   	    goto err_exit;
   		}
	   	// 0xF8 is the standard value for fixed media, 0xF0 is for removable media.
	   	// The important point is whatever value is put in here must also be put in the first
	   	// byte of he FAT[0].
		*MediaDescriptor = MSDC_MEDIA_DESCRIPTOR;
		if(gSD->mWPEnabled) {
		    DclSD_Close(dclHandle);
			status = FS_WRITE_PROTECTION;		
			goto err_exit;
		}
		DclSD_Close(dclHandle);		
        status = FS_NO_ERROR;	
	}
	else{
DclSD_Close(dclHandle);
		status = FS_MSDC_NOT_PRESENT;
	}
err_exit:	
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
        free_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
#else
        free_MSDC_lock(&gSD->mSDdrv_lock);
#endif
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
		kal_give_sem(dualMsdcArb);
	}    	
#endif
    
    return status;	
}

int SD_GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor)
{
    return GetDiskGeometry(DriveData, DiskGeometry, MediaDescriptor);
}

/*-----------------------------------*/
#ifdef  __TST_WRITE_TO_FILE__
	extern void MSDC_ErrorRecordingReset(void);
#endif
static int  ShutDown(void * DriveData)
{
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
#endif

#ifdef  __TST_WRITE_TO_FILE__
	/*error recording: write error log to memory card here*/
   if(KAL_TRUE == INT_QueryExceptionStatus())
	MSDC_ErrorRecordingReset();
#endif
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_UNLOCK(AUDMA_ID_MSDC);
#endif
   return FS_NO_ERROR;
}

#if defined(__UBL__)
#pragma arm section code = "EXT_BOOTLOADER_CODE", rwdata = "EXT_BOOTLOADER_RW", zidata = "EXT_BOOTLOADER_ZI"
#endif

kal_bool SD_canUseErase()
{
	if (KAL_TRUE == useEraseOnFormat && 0 == gSD->mSCR.dat_after_erase){
	    if (MMC_CARD == gMSDC_Handle->mMSDC_type
	        || MMC40_CARD == gMSDC_Handle->mMSDC_type
	        || MMC42_CARD == gMSDC_Handle->mMSDC_type
	        || MMC_CARD_SIMPLUS == gMSDC_Handle->mMSDC_type) {
	        return KAL_FALSE;
	    }
	    else {
		    kal_print("enhanced format");
		    return KAL_TRUE;
		}
	}
	else{
		return KAL_FALSE;
	}
}

#if defined(__UBL__)
#pragma arm section code, rwdata, zidata
#endif

/*******************************************
 * File System <--> Device Driver Interface
 * High Level Format
 *
 * Sample Code
 ******************************************/
#include <fs_type.h>
//#include <rtfiles.h>
#include "fs_gprot.h"

/* FIXME */
//kal_uint8 SectorBuffer[512];

#if defined(__UBL__)
#pragma arm section code = "EXT_BOOTLOADER_CODE", rwdata = "EXT_BOOTLOADER_RW", zidata = "EXT_BOOTLOADER_ZI"
#endif

extern int SDCreateBootSector(void * BootSector, kal_uint32 Sectors, FS_PartitionRecord *Partition);
extern int SDCreateMasterBootRecord(void * MasterBootRecord, kal_uint32 Sectors);

int highlevelformat(void * DriveData, UINT BaseSectorNumber)
{
    int FATType;
    int RootDirSectors;  
    int InfoSector;
    int	i;
    kal_uint32 x, y;
    kal_uint32 FATSectors, Written;
    kal_uint32 FatCount, StartOfFAT;   
//    kal_uint32 status;
    kal_uint32 boot_sector_offset = BaseSectorNumber;
//#if defined(__COOL_FORMAT__)
  	#if !defined(LOW_COST_SUPPORT)
	kal_uint32 total_sectors;
	FS_MasterBootRecord *mbr;
    FS_BootRecord *bs;   
#endif
    FS_BootRecord *PBR;
    kal_uint8 MediaDescriptor;
    int Result = FS_NO_ERROR;
    

    DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
    
    #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    sd_select_enum sel;
    #endif 

    #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
    if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
    {
        kal_take_sem(dualMsdcArb, 1);
    }
    #endif	
    
    #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    if((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
    {
        sel = SD_EXT;
    }
    else
    {
        sel = SD_T_CARD_2;
    }
    
    get_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
    
    #else    
    get_MSDC_lock(&gSD->mSDdrv_lock);
    #endif
    
    do {
        
       // #if __COOL_FORMAT__
	   #if !defined(LOW_COST_SUPPORT)
        mbr = (FS_MasterBootRecord *)MSDC_Sector;
        bs = (FS_BootRecord *)msdc_uncachedBuf;
        
        total_sectors = gSD->mCSD.capacity/512;

//        status = SD_FlushSectors(0, total_sectors);
//        if (status != NO_ERROR)
//            break;
            
        //
        // 1. Create MBR.
        //
        boot_sector_offset = SDCreateMasterBootRecord(mbr, total_sectors);

        if (boot_sector_offset > 0) { 
                
            //
            // 2. Write MBR.
            //
            Result = WriteSectors(&MSDC_Blk[0], 0, 1, (void *)mbr);
            if (Result != STATUS_OK) {
                break;
            }

            //
            // 3. Create boot sector.
            //
            if (SDCreateBootSector(bs, total_sectors, &mbr->PTable[0]) > 0) {

                // 
                // 4. Write boot sector to boot_sector_offset
                //
                Result = WriteSectors(&MSDC_Blk[0], boot_sector_offset, 1, bs); 
                if (Result != STATUS_OK) {
                    break;
                }
                
            }
            else {
                Result = FS_INVALID_FILE_SYSTEM;
                break;
            }
        }
        else {
            Result = FS_INVALID_FILE_SYSTEM;        
            break;
        }
        #endif
        
        //
        // 5. Finally, perform high level format. 
        //    According to SD spec, 2G~32G card's start address is 0x2000
        //
        
        /* HLF - 1 - Read the PBR sector */
        ///* FIXME */ DrvDirect.ReadSector(SectorBuffer     /* Buffer */ ,
        //                                 BaseSectorNumber /* Sector Number */);
        Result = ReadSectors(DriveData, boot_sector_offset, 1, MSDC_Sector);  
        if (Result != STATUS_OK)
            break;
        
        //PBR = (FS_BootRecord*)&MSDC_Sector;
        PBR = (FS_BootRecord*)MSDC_Sector;
        
        /* HLF - 2 - Setup PBR sector content and attributes */
        {
        if (PBR->BP.SectorsOnDisk != 0)
            PBR->BP.TotalSectors = PBR->BP.SectorsOnDisk;
        
        if (PBR->Signature != 0xAA55 ||
            //PBR->BP.TotalSectors > Par.Partition.Sectors ||
            PBR->BP.TotalSectors > (gSD->mCSD.capacity/512) ||
            PBR->BP.BytesPerSector != 512 ||
            PBR->BP.SectorsPerCluster == 0 ||
            PBR->BP.ReservedSectors == 0 ||
            PBR->BP.NumberOfFATs == 0)
        {
            Result = FS_INVALID_FILE_SYSTEM;  
            break; 
        }
        
        FATSectors     = (PBR->BP.SectorsPerFAT) ? PBR->BP.SectorsPerFAT : PBR->BP.E._32.SectorsPerFAT;
        RootDirSectors = (PBR->BP.DirEntries * 32 + (PBR->BP.BytesPerSector - 1)) / PBR->BP.BytesPerSector;
        
        Written        = PBR->BP.TotalSectors
                        - PBR->BP.ReservedSectors
                        - PBR->BP.NumberOfFATs * FATSectors
                        - RootDirSectors;
        Written = Written / PBR->BP.SectorsPerCluster;
        
        if (Written <= 0xFF4L)            FATType = 12;
        else if (Written <= 0xFFF4L)      FATType = 16;
        else if (Written <= 0xFFFFFF4L)   FATType = 32;
        else {
            Result = FS_INVALID_FILE_SYSTEM;  
            break; 
        }
        Written = 0;
        
        if (FATType == 32)
        {
            RootDirSectors = PBR->BP.SectorsPerCluster;
            
            if (PBR->BP.E._32.RootDirCluster != 2)
            {
                PBR->BP.E._32.RootDirCluster = 2;

                //above seek and write seems mean write to specific sector
                Result = WriteSectors(DriveData, boot_sector_offset, 1, (void *)PBR);
                if (Result != STATUS_OK)
                    break;
            
                Result = WriteSectors(DriveData, boot_sector_offset + PBR->BP.E._32.BackupBootSector , 1, (void *)PBR);            
                if (Result != STATUS_OK)
                    break;
            }
        }
        
        
        FatCount       = PBR->BP.NumberOfFATs;
        StartOfFAT     = PBR->BP.ReservedSectors;
        InfoSector     = PBR->BP.E._32.FSInfoSector;
        }
        
        /*we get MediaDescriptor for step 6 usage, since we will clear MSDC_Sector*/
        MediaDescriptor = PBR->BP.MediaDescriptor;
        /*we need MSDC_Sector to be 512-byte-0 now*/
        kal_mem_set(MSDC_Sector, 0, 512);
        
        /* HLF - 3 - Formating cont, FAT32 reserved sector write down */                
        if ((FATType == 32) && (InfoSector > 0) && (InfoSector < StartOfFAT))
        {
            /* FIXME */ 
            //DrvDirect.ZeroSector( BaseSectorNumber + InfoSector /* Start Sector Number */ ,
            //                      1                             /* Zero Sector Count   */ );
            Result = WriteSectors(DriveData, boot_sector_offset + InfoSector, 1, MSDC_Sector);
            if (Result != STATUS_OK)
                break;
        }
        
        
        if (KAL_TRUE == SD_canUseErase()) {

            DCL_STATUS dclStatus = 0;
            SD_CTRL_FLUSH_T flush;
            
            dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
            if (dclHandle == DCL_HANDLE_INVALID)
                ASSERT(0);
            
            flush.startSector = boot_sector_offset + StartOfFAT;
            flush.sectorNum = (FATSectors * FatCount) + RootDirSectors;
            
            dclStatus = DclSD_Control(dclHandle, SD_CTRL_CMD_FLUSH, (DCL_CTRL_DATA_T*)&flush);
            if (STATUS_OK != dclStatus)
                ASSERT(0);
            
            DclSD_Close(dclHandle);
        }
        else {
            /*	start and cloase API are only called in this section of this function, we don't called these API in other places
            file system should help protect the single task accessing, so driver should be able to protect the integrity of this start-close pair
            */
            dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
            if (dclHandle == DCL_HANDLE_INVALID)
                ASSERT(0);
            
            DclSD_Control(dclHandle, SD_CTRL_CMD_FAST_FORMAT_START, NULL);
            DclSD_Close(dclHandle);            
            
            /* HLF - 4 - Formating cont, start, FAT Table write down , remember FAT begin sector */
            {
            /* FIXME */ 
            //DrvDirect.ZeroSector( BaseSectorNumber + StartOfFAT /* Start Sector Number */ ,
            //                      FATSectors * FatCount         /* Zero Sector Count   */ );
            #if defined(__DRV_MSDC_FAST_FORMAT__)
            
            Result = WriteSectors(DriveData, boot_sector_offset + StartOfFAT, FATSectors * FatCount , MSDC_Sector);
            
            if (Result != STATUS_OK) {
                dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
                if (dclHandle == DCL_HANDLE_INVALID)
                    ASSERT(0);
                    
                DclSD_Control(dclHandle, SD_CTRL_CMD_FAST_FORMAT_STOP, NULL);
                DclSD_Close(dclHandle);
                goto highlevelformat_exit;
            }
            #else
            for (i = 0; i < FATSectors * FatCount; i++) {
                
                Result = WriteSectors(DriveData, boot_sector_offset + StartOfFAT + i, 1 , MSDC_Sector);
                
                if (Result != STATUS_OK) {
                    
                    dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
                    if (dclHandle == DCL_HANDLE_INVALID)
                        ASSERT(0);
                    
                    DclSD_Control(dclHandle, SD_CTRL_CMD_FAST_FORMAT_STOP, NULL);
                    DclSD_Close(dclHandle);
                    goto highlevelformat_exit;
                }
            }
            #endif
        }
        
        /* HLF - 5 - Formating cont, Root directory write down */
        {
        
        x = StartOfFAT + FATSectors * FatCount;
        /* FIXME */ 
        //DrvDirect.ZeroSector( BaseSectorNumber + x          /* Start Sector Number */ ,
        //                      RootDirSectors                /* Zero Sector Count   */ );
        #if defined(__DRV_MSDC_FAST_FORMAT__)
        
        Result = WriteSectors(DriveData, boot_sector_offset + x, RootDirSectors , MSDC_Sector);
        
        if (Result != STATUS_OK) {
            
            dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
            
            if (dclHandle == DCL_HANDLE_INVALID)
                ASSERT(0);
            
            DclSD_Control(dclHandle, SD_CTRL_CMD_FAST_FORMAT_STOP, NULL);
            DclSD_Close(dclHandle);
            goto highlevelformat_exit;
        }
        #else
        for (i = 0; i < RootDirSectors; i++) {
            
            Result = WriteSectors(DriveData, boot_sector_offset + x + i, 1 , MSDC_Sector);
            
            if (0 > Result) {
                dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
                
                if (dclHandle == DCL_HANDLE_INVALID)
                    ASSERT(0);
                
                DclSD_Control(dclHandle, SD_CTRL_CMD_FAST_FORMAT_STOP, NULL);
                DclSD_Close(dclHandle);
                goto highlevelformat_exit;
            }
        }
        #endif
        }
        
        dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);        
        if (dclHandle == DCL_HANDLE_INVALID)
            ASSERT(0);
            
        DclSD_Control(dclHandle, SD_CTRL_CMD_FAST_FORMAT_STOP, NULL);
        DclSD_Close(dclHandle);
        }
        
        /* HLF - 6 - Formating final, 1st FAT sector must be rewritten */
        {
        kal_uint16 * FPtr16;
        kal_uint8 * FPtr8;
        switch (FATType)
        {
            case 32:
            //kal_uint32 * FPtr = (void*) ScratchSector;
            MSDC_Sector[2] = 0x0FFFFFFF; // this is for the root dir
            MSDC_Sector[1] = 0x0FFFFFFF;
            //break;
            case 16:
            FPtr16 = (void*)MSDC_Sector;
            FPtr16[1] = 0xFFFF;
            //break;
            case 12:
            FPtr8 = (void *)MSDC_Sector;
            /* FIXME */ FPtr8[2] = 0xFF;
            /* FIXME */ FPtr8[1] = 0xFF;
            /* FIXME */ FPtr8[0] = MediaDescriptor;
            break;
            default:
            ASSERT(0);
            break;
        }
        for (i = 0, y = StartOfFAT;
        i < FatCount;
        i++  , y+= FATSectors)
        {
        ///* FIXME */ DrvDirect.WriteSector(SectorBuffer     /* Buffer */ ,
        //                              BaseSectorNumber + y /* Sector Number */);
            Result = WriteSectors(DriveData, boot_sector_offset + y, 1 , MSDC_Sector);
        }
        }
   
    } while (0);

highlevelformat_exit: 
    #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    free_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
    #else
	free_MSDC_lock(&gSD->mSDdrv_lock);
    #endif

    #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
    if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
		kal_give_sem(dualMsdcArb);
	}
    #endif

   /* HLF - 7 - The END */
   return Result;
}

#if defined(__UBL__)
#pragma arm section code, rwdata, zidata
#endif

int SD_IOCtrl(void * DriveData, UINT CtrlAction, void * CtrlData)
{
	FS_DeviceInfo *info;
	kal_bool on;
	DCL_HANDLE dclHandle = DCL_HANDLE_NONE;
//	DCL_STATUS dclStatus = 0;
	DCL_BOOL isCardExist = DCL_FALSE;
//	DCL_BOOL isCardInited = DCL_FALSE;
	int status = FS_NO_ERROR;
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	sd_select_enum sel;
#endif
	
    #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH) 
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
		kal_take_sem(dualMsdcArb, 1);			
    }
    #endif

#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)	
    	if ((MSDC_HANDLE *)DriveData == &MSDC_Blk[0])
    	{
    		sel = SD_EXT;
    	}
    	else
    	{
    		sel = SD_T_CARD_2;
    	}
        init_MSDC_lock(&gSD_blk[0].mSDdrv_lock, "SD_DRV_LOCK");//guilin++
        get_MSDC_lock(&gSD_blk[0].mSDdrv_lock);	
        
       if(sel==SD_EXT)
    	{
		dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
          if (dclHandle == DCL_HANDLE_INVALID) {
            status = FS_INVALID_OPERATION;
             goto err_exit;
            }
       }
       else
       {
          #if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
          dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_SIMPLUS|DCL_SD_FLAGS_USAGE_CMD);
          if (dclHandle == DCL_HANDLE_INVALID) {
            status = FS_INVALID_OPERATION;            
             goto err_exit;             
            }
          #else
             ASSERT(0);
          #endif
       }
    	DclSD_Control(dclHandle, SD_CTRL_CMD_ANALOG_SWITCH, (DCL_CTRL_DATA_T*)&sel);
#else	
        init_MSDC_lock(&gSD->mSDdrv_lock, "SD_DRV_LOCK");//guilin++
        get_MSDC_lock(&gSD->mSDdrv_lock);
		dclHandle = DclSD_Open(DCL_SD, DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_USAGE_CMD);
		if (dclHandle == DCL_HANDLE_INVALID) {
            status = FS_INVALID_OPERATION;		    
             goto err_exit;			
            }
#endif			


	switch (CtrlAction)
	{
	case FS_IOCTRL_QUERY_CARD_INFO:
		info = CtrlData;
		/*
			1. If memory card is inserted, set flag FS_DEVICE_FLAG_PRESENT   in   info->DeviceInfo.Card.Flag
			2. If memory card is NOT inserted, clear flag FS_DEVICE_FLAG_PRESENT   in   info->DeviceInfo.Card.Flag
		*/
		DclSD_Control(dclHandle, SD_CTRL_CMD_IS_EXISTENCE, (DCL_CTRL_DATA_T*)&isCardExist);

		if (isCardExist){
			info->DeviceInfo.Card.Flag |= FS_DEVICE_FLAG_PRESENT;
			info->DeviceInfo.Card.PSN = gSD->mCID.psn;
		    //
		    // bus_width = 5, -> 4bit
		    // bus_width = 1, -> 1bit
		    //
		    #if defined(MSDC_SD_BITS4_BUS)
		    info->DeviceInfo.Card.SerialMode = KAL_FALSE;
		    #else
		    info->DeviceInfo.Card.SerialMode = KAL_TRUE;
		    #endif
		}
		else{
			info->DeviceInfo.Card.Flag &= ~FS_DEVICE_FLAG_PRESENT;
			info->DeviceInfo.Card.PSN = 0;
			info->DeviceInfo.Card.SerialMode = KAL_TRUE;
		}
#if defined(MT6260)
//we can decide whether to do deferredMount base on mount speed of 1/4bit line bus 
			info->DeviceInfo.Card.DeferredMount = KAL_TRUE;
		#else
		info->DeviceInfo.Card.DeferredMount = info->DeviceInfo.Card.SerialMode;
#endif		
		break;
			
	case FS_IOCTRL_CONTROL_DEV_POWER:
	    on = *(kal_bool*)CtrlData;

	    if(gMSDC_Handle->msdc_custom_handle.PowerCtrl)
		    gMSDC_Handle->msdc_custom_handle.PowerCtrl(on);
	    break;

	default:
        status = FS_UNSUPPORTED_DRIVER_FUNCTION;          
         goto err_exit;         
		//ASSERT(0);
		//break;
	}

err_exit:	
	DclSD_Close(dclHandle);
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
    free_MSDC_lock(&gSD_blk[0].mSDdrv_lock);
#else
    free_MSDC_lock(&gSD->mSDdrv_lock);
#endif
#if defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)   
	
	if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()))
	{
		kal_give_sem(dualMsdcArb);
	}
#endif
    
    return status;	    
}

#endif//defined(DCL_MSDC_INTERFACE)

FS_Driver FS_SdDrv = {
   MountDevice_NEW,
   ShutDown,
   ReadSectors_NEW,
   WriteSectors_NEW,
   MediaChanged,
   DiscardSectors,
   GetDiskGeometry,
   NULL,
   NULL,
   NULL,
   NULL,
   highlevelformat,
   NULL,
   MSDC_GetCardStatus,
   NULL,
   NULL,
   NULL,
   SD_IOCtrl//ioctrl
};



#endif//!defined(__UBL__) || defined(__CARD_DOWNLOAD__) 

#else //DRV_MSDC_OFF
#include "kal_release.h"
//RHR ADD
#include "kal_public_defs.h"
#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
//RHR REMOVE
/*
#include "app_buff_alloc.h"
#include "fat_fs.h"
*/
//RHR
/*following is dummy API*/


static int  MountDevice_NEW(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags){}
static int  ShutDown(void * DriveData){}
static int  ReadSectors_NEW(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer){}
static int  WriteSectors_NEW(void * DriveData, kal_uint32 Sector, UINT Sectors, void * Buffer){}
static int  MediaChanged(void * DriveData){}
static int  DiscardSectors(void * DriveData, kal_uint32 Sector, UINT Sectors){}
static int  GetDiskGeometry(void * DriveData, FS_PartitionRecord * DiskGeometry, BYTE * MediaDescriptor){}
int highlevelformat(void * DriveData, UINT BaseSectorNumber){}
extern int MSDC_GetCardStatus(void * DriveData, int AckType);

FS_Driver FS_SdDrv = {
   MountDevice_NEW,
   ShutDown,
   ReadSectors_NEW,
   WriteSectors_NEW,
   MediaChanged,
   DiscardSectors,
   GetDiskGeometry,
   NULL,
   NULL,
   NULL,
   NULL,
   highlevelformat,
   NULL,
   MSDC_GetCardStatus   
};
#endif //DRV_MSDC_OFF
