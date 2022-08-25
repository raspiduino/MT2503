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
 *    mm_power_ctrl.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Header file for mm_power_ctrl
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MM_POWER_CTRL_H__
#define __MM_POWER_CTRL_H__

#include "kal_public_api.h"

#include "mmsys_pwrmgr.h"
#include "kal_general_types.h"

/******************************************************************************
 * API functions
 *****************************************************************************/
/**
 * Turn off MM module clock. And turn off MM SUBSYS for saving power if no 
 * other MM modules are still turned on.
 * 
 * @param module  The definition of clock gating bit for the module to be 
 *                turned off. For MT6268, please refer to drvpdn_oldpdnarch.h. 
 *                To turn on JPEG on MT6268, please use MMCG_CON0_JPEG. 
 *                For MT6236, please refer to pdn_hw_mt6236_series.h. To turn 
 *                on JPEG on MT6236, please use MMSYS_CG_CON_JPG.
 * 
 * @remark Please try prevent to call this function in ISR level...and 
 *         please do not use i-bit to protect this function.
 */
extern void mm_disable_power(kal_uint32 module);

/**
 * Turn on MM module clock. And turn on MM SUBSYS for saving power if no 
 * other MM modules are still turned on.
 * 
 * @param module  The definition of clock gating bit for the module to be 
 *                turned off. For MT6268, please refer to drvpdn_oldpdnarch.h. 
 *                To turn on JPEG on MT6268, please use MMCG_CON0_JPEG. 
 *                For MT6236, please refer to pdn_hw_mt6236_series.h. To turn 
 *                on JPEG on MT6236, please use MMSYS_CG_CON_JPG.
 * 
 * @remark Please try prevent to call this function in ISR level...and 
 *         please do not use i-bit to protect this function.
 */
extern void mm_enable_power(kal_uint32 module);

/**
 * Turn off MM module clock. MM SUBSYS is not turned off even there is no 
 * other MM module is on.
 * 
 * @param module  The definition of clock gating bit for the module to be 
 *                turned off. For MT6268, please refer to drvpdn_oldpdnarch.h. 
 *                To turn on JPEG on MT6268, please use MMCG_CON0_JPEG. 
 *                For MT6236, please refer to pdn_hw_mt6236_series.h. To turn 
 *                on JPEG on MT6236, please use MMSYS_CG_CON_JPG.
 * 
 * @remark  Please try prevent to call this function in ISR level...and 
 *          please do not use i-bit to protect this function. Please try to 
 *          pair with mm_enable_clock. If no special requirements to lock 
 *          MM SUBSYS power on/off, please use mm_disable_power instead.
 */
extern void mm_disable_clock(kal_uint32 module);

/**
 * Turn on MM module clock. MM SUBSYS is not turned on with this function 
 * even MM SUBSYS is in off state.
 * 
 * @param module  The definition of clock gating bit for the module to be 
 *                turned off. For MT6268, please refer to drvpdn_oldpdnarch.h. 
 *                To turn on JPEG on MT6268, please use MMCG_CON0_JPEG. 
 *                For MT6236, please refer to pdn_hw_mt6236_series.h. To turn 
 *                on JPEG on MT6236, please use MMSYS_CG_CON_JPG.
 * 
 * @remark  Please try prevent to call this function in ISR level...and 
 *          please do not use i-bit to protect this function. If no special 
 *          requirements to lock MM SUBSYS power on/off, please use 
 *          mm_enable_power instead.
 */
extern void mm_enable_clock(kal_uint32 module);

extern kal_bool mm_query_clock_status(kal_uint32 module);

#endif  /* __MM_POWER_CTRL_H__ */

