/*******************************************************************************
 *
 * Filename:
 * ---------
 *	Btdrv_common.c
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

//define wrapper for 6261 brother chip
#if  defined(MT2501) || defined(MT2502)
#ifndef MT6261
#define MT6261   1
#endif
#endif
     
#if  defined(__BTMODULE_MT2501__) || defined(__BTMODULE_MT2502__)
#ifndef __BTMODULE_MT6261__
#define __BTMODULE_MT6261__   1
#endif
#endif
//define finish


#include "btdrv_types.h"
#include "btdrv_common.h"
#include "nvram_common_defs.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Combination chip support
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if (defined (__BTMODULE_MT6612__) && defined (__BTMODULE_MT6622__) && defined(__BTMODULE_MT6626__))
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6612_22_26;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6612_22_26;
    void (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6612_22_26;
#elif (defined (__BTMODULE_MT6612__) && defined (__BTMODULE_MT6622__))
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6612_22;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6612_22;
    void (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6612_22;
#elif (defined (__BTMODULE_MT6612__) && defined(__BTMODULE_MT6626__))
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6612_26;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6612_26;
    void (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6612_26;
#elif (defined (__BTMODULE_MT6622__) && defined(__BTMODULE_MT6626__))
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6622_26;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6622_26;
    void (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6622_26;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Single chip support
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#elif defined (__BTMODULE_MT6601__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6601;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6601;
    void (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6601;
#elif defined (__BTMODULE_MT6611__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6611;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6611;
    void (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6611;
#elif defined (__BTMODULE_MT6236__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6236;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6236;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6236;
#elif defined (__BTMODULE_MT6255__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6255;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6255;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6255;
#elif defined (__BTMODULE_MT6256__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6256;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6256;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6256;
#elif defined (__BTMODULE_MT6276__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6276;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6276;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6276;
#elif defined (__BTMODULE_MT6250__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6250;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6250;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6250;
#elif defined (__BTMODULE_MT6260__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6260;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6260;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6260;
#elif defined (__BTMODULE_MT6261__)
#ifdef __TINY_SYS__
    BtStatus (*GORM_Set_BT_Boot_Mode)(U8 btBootMode) = GORM_Set_BT_Boot_Mode_MT6261;
#endif
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6261;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6261;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6261;    
#elif defined (__BTMODULE_MT6612__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6612;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6612;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6612;
#elif defined (__BTMODULE_MT6622__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6622;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6622;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6622;
#elif defined (__BTMODULE_MT6626__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6626;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6626;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6626;
#elif defined (__BTMODULE_MT6616__)
    BtStatus (*GORM_Init)(void) = GORM_Init_MT6616;
    BtStatus (*GORM_Shutdown)(void) = GORM_Shutdown_MT6616;
    void  (*GORM_InitEventHandler)(U8 Event,HciCallbackParms * Parms) = GORM_InitEventHandler_MT6616;
#else
    #error "MTK BT Chip not supported"
#endif

#if (defined (__BTMODULE_MT6616__) && (!defined (__MT6616_NO_STP__)))
    kal_uint8 g_MT6616_NO_STP = 0;
#else
    kal_uint8 g_MT6616_NO_STP = 1; //default
#endif
/////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////
//For patch optimize
/////////////////////////////////////////////////////////////////////////////////////////////
#if (defined (__BTMODULE_MT6612__) && defined (__BTMODULE_MT6622__) && defined(__BTMODULE_MT6626__))
sHciScriptElement* Get_MT6612_22_26_Init_Script()
{
    extern sHciScriptElement  mt6612_22_26_init_script[1];
    return mt6612_22_26_init_script;
}
#else
sHciScriptElement* Get_MT6612_22_26_Init_Script()
{
    return NULL;
}
#endif

#if (defined (__BTMODULE_MT6612__) && defined (__BTMODULE_MT6622__))
sHciScriptElement* Get_MT6612_22_Init_Script()
{
    extern sHciScriptElement  mt6612_22_init_script[1];
    return mt6612_22_init_script;
}
#else
sHciScriptElement* Get_MT6612_22_Init_Script()
{
    return NULL;
}
#endif

#if (defined (__BTMODULE_MT6612__) && defined(__BTMODULE_MT6626__))
sHciScriptElement* Get_MT6612_26_Init_Script()
{
    extern sHciScriptElement  mt6612_26_init_script[1];
    return mt6612_26_init_script;
}
#else
sHciScriptElement* Get_MT6612_26_Init_Script()
{
    return NULL;
}
#endif

#if (defined (__BTMODULE_MT6622__) && defined(__BTMODULE_MT6626__))
sHciScriptElement* Get_MT6622_26_Init_Script()
{
    extern sHciScriptElement  mt6622_26_init_script[1];
    return mt6622_26_init_script;
}
#else
sHciScriptElement* Get_MT6622_26_Init_Script()
{
    return NULL;
}
#endif

#if defined (__BTMODULE_MT6601__)
sHciScriptElement* Get_MT6601_Init_Script()
{
    extern sHciScriptElement mt6601_init_script[1];
    return mt6601_init_script;
}

sHciScriptElement* Get_MT6601_E3_Script()
{
    extern sHciScriptElement mt6601_e3_script[1];
    return mt6601_e3_script;
}

sHciScriptElement* Get_MT6601_E5_Script()
{
    extern sHciScriptElement mt6601_e5_script[1];
    return mt6601_e5_script;
}

t_version_info* Get_MT6601_Str_gorm_version(void)
{
    extern t_version_info MT6601_Str_gorm_version[1];
    return MT6601_Str_gorm_version;
}
#else
sHciScriptElement* Get_MT6601_Init_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6601_E3_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6601_E5_Script()
{
    return NULL;
}

t_version_info* Get_MT6601_Str_gorm_version(void)
{
    return NULL;
}
#endif

#if ((!defined(__BTMODULE_MT6601__)) && (!defined(__BTMODULE_MT6612__)) && (!defined(__BTMODULE_MT6622__)) && (!defined(__BTMODULE_MT6626__)))
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_CH;
    return BT_CUSTOM_PTA_WIFI_CH;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_HB;
    return BT_CUSTOM_PTA_WIFI_HB;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING()
{
    extern kal_uint8 BT_CUSTOM_PTA_SETTING[10];
    return BT_CUSTOM_PTA_SETTING;
}
#else
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH()
{
    return 0;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB()
{
    return 0;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING()
{
    return NULL;
}
#endif

#if defined (__BTMODULE_MT6611__)
sHciScriptElement* Get_MT6611_Init_Script()
{
    extern sHciScriptElement  mt6611_init_script[1];
    return mt6611_init_script;
}

sHciScriptElement* Get_MT6611_No_Patch_Script()
{
    extern sHciScriptElement  mt6611_no_patch_script[1];
    return mt6611_no_patch_script;
}

sHciScriptElement* Get_MT6611_E2_Script()
{
    extern sHciScriptElement  mt6611_e2_script[1];
    return mt6611_e2_script;
}

sHciScriptElement* Get_MT6611B_E3_Script()
{
    extern sHciScriptElement  mt6611b_e3_script[1];
    return mt6611b_e3_script;
}

sHciScriptElement* Get_MT6611A_Script()
{
    extern sHciScriptElement  mt6611a_script[1];
    return mt6611a_script;
}

sHciScriptElement* Get_MT6611B_E1_Script()
{
    extern sHciScriptElement  mt6611b_e1_script[1];
    return mt6611b_e1_script;
}

t_version_info* Get_MT6611_Str_gorm_version(void)
{
    extern t_version_info MT6611_Str_gorm_version[1];
    return MT6611_Str_gorm_version;
}
#else
sHciScriptElement* Get_MT6611_Init_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6611_No_Patch_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6611_E2_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6611B_E3_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6611A_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6611B_E1_Script()
{
    return NULL;
}

t_version_info* Get_MT6611_Str_gorm_version(void)
{
    return NULL;
}
#endif

#if defined (__BTMODULE_MT6612__)
sHciScriptElement* Get_MT6612_Init_Script()
{
    extern sHciScriptElement  mt6612_init_script[1];
    return mt6612_init_script;
}

sHciScriptElement* Get_MT6612_No_Patch_Script()
{
    extern sHciScriptElement  mt6612_no_patch_script[1];
    return mt6612_no_patch_script;
}

sHciScriptElement* Get_MT6612_E2_Script()
{
    extern sHciScriptElement  mt6612_e2_script[1];
    return mt6612_e2_script;
}

t_version_info* Get_MT6612_Str_gorm_version(void)
{
    extern t_version_info MT6612_Str_gorm_version[1];
    return MT6612_Str_gorm_version;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6612()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_CH_6612;
    return BT_CUSTOM_PTA_WIFI_CH_6612;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6612()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_HB_6612;
    return BT_CUSTOM_PTA_WIFI_HB_6612;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6612()
{
    extern kal_uint8 BT_CUSTOM_PTA_SETTING_6612[10];
    return BT_CUSTOM_PTA_SETTING_6612;
}
#else
sHciScriptElement* Get_MT6612_Init_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6612_No_Patch_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6612_E2_Script()
{
    return NULL;
}

t_version_info* Get_MT6612_Str_gorm_version(void)
{
    return NULL;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6612()
{
    return 0;
}
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6612()
{
    return 0;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6612()
{
    return NULL;
}
#endif

#if defined (__BTMODULE_MT6622__)
sHciScriptElement* Get_MT6622_Init_Script()
{
    extern sHciScriptElement mt6622_init_script[1];
    return mt6622_init_script;
}

sHciScriptElement* Get_MT6622_No_Patch_Script()
{
    extern sHciScriptElement  mt6622_no_patch_script[1];
    return mt6622_no_patch_script;
}

sHciScriptElement* Get_MT6622_E1_Script()
{
    extern sHciScriptElement  mt6622_e1_script[1];
    return mt6622_e1_script;
}

sHciScriptElement* Get_MT6622_E2_Script()
{
    extern sHciScriptElement  mt6622_e2_script[1];
    return mt6622_e2_script;
}

sHciScriptElement* Get_MT6622_EO_Script()
{
    extern sHciScriptElement  mt6622_eo_script[1];
    return mt6622_eo_script;
}

t_version_info* Get_MT6622_Str_gorm_version(void)
{
    extern t_version_info MT6622_Str_gorm_version[1];
    return MT6622_Str_gorm_version;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6622()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_CH_6622;
    return BT_CUSTOM_PTA_WIFI_CH_6622;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6622()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_HB_6622;
    return BT_CUSTOM_PTA_WIFI_HB_6622;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6622()
{
    extern kal_uint8 BT_CUSTOM_PTA_SETTING_6622[10];
    return BT_CUSTOM_PTA_SETTING_6622;
}
#else
sHciScriptElement* Get_MT6622_Init_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6622_No_Patch_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6622_E1_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6622_E2_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6622_EO_Script()
{
    return NULL;
}

t_version_info* Get_MT6622_Str_gorm_version(void)
{
    return NULL;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6622()
{
    return 0;
}
kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6622()
{
    return 0;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6622()
{
    return NULL;
}
#endif

#if defined (__BTMODULE_MT6626__)
sHciScriptElement* Get_MT6626_Init_Script()
{
    extern sHciScriptElement  mt6626_init_script[1];
    return mt6626_init_script;
}

sHciScriptElement* Get_MT6626_No_Patch_Script()
{
    extern sHciScriptElement  mt6626_no_patch_script[1] ;
    return mt6626_no_patch_script;
}

sHciScriptElement* Get_MT6626_E1_Script()
{
    extern sHciScriptElement  mt6626_e1_script[1];
    return mt6626_e1_script;
}

sHciScriptElement* Get_MT6626_EO_Script()
{
    extern sHciScriptElement  mt6626_eo_script[1];
    return mt6626_eo_script;
}

t_version_info* Get_MT6626_Str_gorm_version(void)
{
    extern t_version_info MT6626_Str_gorm_version[1];
    return MT6626_Str_gorm_version;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6626()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_CH_6626;
    return BT_CUSTOM_PTA_WIFI_CH_6626;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6626()
{
    extern kal_uint8 BT_CUSTOM_PTA_WIFI_HB_6626;
    return BT_CUSTOM_PTA_WIFI_HB_6626;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6626()
{
    extern kal_uint8 BT_CUSTOM_PTA_SETTING_6626[10];
    return BT_CUSTOM_PTA_SETTING_6626;
}
#else
sHciScriptElement* Get_MT6626_Init_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6626_No_Patch_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6626_E1_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6626_EO_Script()
{
    return NULL;
}

t_version_info* Get_MT6626_Str_gorm_version(void)
{
    return NULL;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_CH_6626()
{
    return 0;
}

kal_uint8 Get_BT_CUSTOM_PTA_WIFI_HB_6626()
{
    return 0;
}

kal_uint8* Get_BT_CUSTOM_PTA_SETTING_6626()
{
    return NULL;
}
#endif

#if defined (__BTMODULE_MT6616__)
sHciScriptElement* Get_MT6616_Init_Script()
{
    extern sHciScriptElement  mt6616_init_script[1];
    return mt6616_init_script;
}

sHciScriptElement* Get_MT6616_No_Patch_Script()
{
    extern sHciScriptElement  mt6616_no_patch_script[1];
    return mt6616_no_patch_script;
}

sHciScriptElement* Get_MT6616_E1_Script()
{
    extern sHciScriptElement  mt6616_e1_script[1];
    return mt6616_e1_script;
}

sHciScriptElement* Get_MT6616_E2_Script()
{
    extern sHciScriptElement  mt6616_e2_script[1];
    return mt6616_e2_script;
}

t_version_info* Get_MT6616_Str_gorm_version(void)
{
    extern t_version_info MT6616_Str_gorm_version[1];
    return MT6616_Str_gorm_version;
}
#else
sHciScriptElement* Get_MT6616_Init_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6616_No_Patch_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6616_E1_Script()
{
    return NULL;
}

sHciScriptElement* Get_MT6616_E2_Script()
{
    return NULL;
}

t_version_info* Get_MT6616_Str_gorm_version(void)
{
    return NULL;
}
#endif
/////////////////////////////////////////////////////////////////////////////////////////////

#if defined(__BTMODULE_MT6626__)
kal_uint8 BtRadio_Power_Handler_Force_Reset(kal_uint8 sys)
{
    extern kal_uint8 BtRadio_Power_Handler_Force_Reset_MT6626(kal_uint8 sys);
    return BtRadio_Power_Handler_Force_Reset_MT6626(sys);
}
#else
kal_uint8 BtRadio_Power_Handler_Force_Reset(kal_uint8 sys)
{
    return 1;
}
#endif

/////////////////////////////////////////////////////////////////////////////////////////////
//For build error resolved
/////////////////////////////////////////////////////////////////////////////////////////////
#if defined (__BT_AUTO_DETECT_SUPPORT__)
    kal_uint16 g_NVRAM_BT_AUTO_DETECT_LID = NVRAM_EF_BT_AUTO_DETECT_SETTING_LID;
    kal_uint32 g_NVRAM_BT_AUTO_DETECT_SIZE = NVRAM_EF_BT_AUTO_DETECT_SETTING_SIZE;
#else
    kal_uint16 g_NVRAM_BT_AUTO_DETECT_LID = 0;
    kal_uint32 g_NVRAM_BT_AUTO_DETECT_SIZE = 0;
#endif

#if (defined (__WMT_SUPPORT__) && defined (__BT_AUTO_DETECT_SUPPORT__))
#else
    kal_bool g_wmt_power_on_init_start = KAL_FALSE;
    kal_bool g_wmt_power_on_init_end = KAL_FALSE;
#endif

#if (!defined (__BTMODULE_MT6616__))
    kal_uint8* wmt_patch_data = NULL;
    int wmt_patch_size = 0;
    kal_bool  g_wmt_reinit_status = KAL_FALSE;
    kal_bool wmt_ext_power_on_hdlr(kal_uint8 type)
    {
        return KAL_TRUE;
    }

    kal_bool wmt_ext_power_off_hdlr(kal_uint8 type)
    {
        return KAL_TRUE;
    }
#endif

/////////////////////////////////////////////////////////////////////////////////////////////




