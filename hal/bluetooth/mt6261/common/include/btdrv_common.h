/*******************************************************************************
 *
 * Filename:
 * ---------
 *	Btdrv_common.h
 *
 * Project:
 * --------
 *   MAUI MTK Bluetooth Chip
 *
 * Description:
 * ------------
 *   This file contains functions export to customer for chip selection
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
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

#ifndef BTDRV_COMMON_H
#define BTDRV_COMMON_H

#include "btdrv_types.h"

typedef XaStatus BtStatus;
typedef  BtStatus (*sHciCmdFunc)( void );
typedef  BtStatus (*sHciEvtFunc)( HciEvent * );

typedef  struct {
   sHciCmdFunc command_func;
   sHciEvtFunc event_handler;
} sHciScriptElement;

#ifdef __TINY_SYS__
/*
typedef enum {
    BT_BOOT_FROM_NORMAL,
    BT_BOOT_FROM_HIBERNATION,
    BT_BOOT_FROM_OTHER
}eBtBootMode;
*/
/* 0: Normal Bootup, 1: Hibernation Switch BootUp */
extern BtStatus GORM_Set_BT_Boot_Mode_MT6261(U8 btBootMode);
#endif


extern BtStatus GORM_Init_MT6601(void);
extern BtStatus GORM_Init_MT6611(void);
extern BtStatus GORM_Init_MT6612(void);
extern BtStatus GORM_Init_MT6616(void);
extern BtStatus GORM_Init_MT6622(void);
extern BtStatus GORM_Init_MT6626(void);
extern BtStatus GORM_Init_MT6236(void);
extern BtStatus GORM_Init_MT6255(void);
extern BtStatus GORM_Init_MT6256(void);
extern BtStatus GORM_Init_MT6276(void);
extern BtStatus GORM_Init_MT6250(void);
extern BtStatus GORM_Init_MT6260(void);
extern BtStatus GORM_Init_MT6261(void);
extern BtStatus GORM_Init_MT6612_22_26(void);
extern BtStatus GORM_Init_MT6612_22(void);
extern BtStatus GORM_Init_MT6612_26(void);
extern BtStatus GORM_Init_MT6622_26(void);


extern BtStatus GORM_Shutdown_MT6601(void);
extern BtStatus GORM_Shutdown_MT6611(void);
extern BtStatus GORM_Shutdown_MT6612(void);
extern BtStatus GORM_Shutdown_MT6616(void);
extern BtStatus GORM_Shutdown_MT6622(void);
extern BtStatus GORM_Shutdown_MT6626(void);
extern BtStatus GORM_Shutdown_MT6236(void);
extern BtStatus GORM_Shutdown_MT6255(void);
extern BtStatus GORM_Shutdown_MT6256(void);
extern BtStatus GORM_Shutdown_MT6276(void);
extern BtStatus GORM_Shutdown_MT6250(void);
extern BtStatus GORM_Shutdown_MT6260(void);
extern BtStatus GORM_Shutdown_MT6261(void);
extern BtStatus GORM_Shutdown_MT6612_22_26(void);
extern BtStatus GORM_Shutdown_MT6612_22(void);
extern BtStatus GORM_Shutdown_MT6612_26(void);
extern BtStatus GORM_Shutdown_MT6622_26(void);


extern void GORM_InitEventHandler_MT6601(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6611(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6612(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6616(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6622(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6626(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6236(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6255(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6256(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6276(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6250(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6260(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6261(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6612_22_26(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6612_22(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6612_26(U8 Event, HciCallbackParms *Parms);
extern void GORM_InitEventHandler_MT6622_26(U8 Event, HciCallbackParms *Parms);


extern BtStatus (*GORM_Init)(void);
extern BtStatus (*GORM_Shutdown)(void);
extern void (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms);


sHciScriptElement* Get_MT6601_Init_Script(void);
sHciScriptElement* Get_MT6601_E3_Script(void);
sHciScriptElement* Get_MT6601_E5_Script(void);
t_version_info* Get_MT6601_Str_gorm_version(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB(void);
kal_uint8* Get_BT_CUSTOM_PTA_SETTING(void);


sHciScriptElement* Get_MT6611_Init_Script(void);
sHciScriptElement* Get_MT6611_No_Patch_Script(void);
sHciScriptElement* Get_MT6611_E2_Script(void);
sHciScriptElement* Get_MT6611B_E3_Script(void);
sHciScriptElement* Get_MT6611A_Script(void);
sHciScriptElement* Get_MT6611B_E1_Script(void);
t_version_info* Get_MT6611_Str_gorm_version(void);

sHciScriptElement* Get_MT6612_Init_Script(void);
sHciScriptElement* Get_MT6612_No_Patch_Script(void);
sHciScriptElement* Get_MT6612_E2_Script(void);
t_version_info* Get_MT6612_Str_gorm_version(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6612(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6612(void);
kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6612(void);


sHciScriptElement* Get_MT6622_Init_Script(void);
sHciScriptElement* Get_MT6622_No_Patch_Script(void);
sHciScriptElement* Get_MT6622_E1_Script(void);
sHciScriptElement* Get_MT6622_E2_Script(void);
sHciScriptElement* Get_MT6622_EO_Script(void);
t_version_info* Get_MT6622_Str_gorm_version(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6622(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6622(void);
kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6622(void);


sHciScriptElement* Get_MT6626_Init_Script(void);
sHciScriptElement* Get_MT6626_No_Patch_Script(void);
sHciScriptElement* Get_MT6626_E1_Script(void);
sHciScriptElement* Get_MT6626_EO_Script(void);
t_version_info* Get_MT6626_Str_gorm_version(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6626(void);
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6626(void);
kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6626(void);


sHciScriptElement* Get_MT6616_Init_Script(void);
sHciScriptElement* Get_MT6616_No_Patch_Script(void);
sHciScriptElement* Get_MT6616_E1_Script(void);
sHciScriptElement* Get_MT6616_E2_Script(void);
t_version_info* Get_MT6616_Str_gorm_version(void);

sHciScriptElement* Get_MT6612_22_26_Init_Script(void);
sHciScriptElement* Get_MT6612_22_Init_Script(void);
sHciScriptElement* Get_MT6612_26_Init_Script(void);
sHciScriptElement* Get_MT6622_26_Init_Script(void);

extern kal_uint8 g_MT6616_NO_STP;
extern kal_uint16 g_NVRAM_BT_AUTO_DETECT_LID;
extern kal_uint32 g_NVRAM_BT_AUTO_DETECT_SIZE;

kal_uint8 BtRadio_Power_Handler_Force_Reset(kal_uint8 sys);

#endif

