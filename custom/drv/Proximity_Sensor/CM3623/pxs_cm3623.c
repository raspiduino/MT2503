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
 *   pxs_cm3623.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   CM3623 proximity sensor driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__PXS_CM3623__)
#include "kal_release.h"
#include "dcl.h"
#include "pxs_cm3623.h"
#include "pxs_custom.h"

//#define PXS_KAL_PROMPT_DEBUG


CM3623_REG_VAL_STRUCT cm3623_reg_val[CM3623_REG_NUM];

static kal_uint16 cm3623_sens_level_num = 0;
static kal_uint16 *p_cm3623_sens_level_table = NULL;

PXS_CONFIG_T HPXSConfig;

// CM3623 driver
DCL_BOOL cm3623_pxs_enable_flag;

// PXS threshold;
kal_uint16 pxs_threshold;

static void _cm3623_ctrl_pxs_intr_enable_reg(DCL_BOOL enable)
{
	if (DCL_TRUE == enable)
	{
		cm3623_reg_val[PS_CMD].val |= (INT_PS_MASK);
	}
	else
	{
		cm3623_reg_val[PS_CMD].val &= ~(INT_PS_MASK);
	}
}

static void _cm3623_ctrl_pxs_enable_reg(DCL_BOOL enable)
{
	if (DCL_TRUE == enable)
	{
		cm3623_reg_val[PS_CMD].val &= ~(SD_PS_MASK);
	}
	else
	{
		cm3623_reg_val[PS_CMD].val |= (SD_PS_MASK);
	}
}

static kal_uint8 _cm3623_get_intr_addr(void)
{
	kal_bool ret;

	ret = cm3623_reg_read(cm3623_reg_val[ARA].reg, &(cm3623_reg_val[ARA].val));
	if (KAL_TRUE == ret)
	{
		return cm3623_reg_val[ARA].val;
	}
	else
	{
		return INVALID_INTR_ADDR;  // Indicate NO INTR addr
	}
}

static void _cm3623_ack_intr(void)
{
	while (INVALID_INTR_ADDR != _cm3623_get_intr_addr())
	{
		;
	}
}


// Internal used, when App wants to configure new pamameters,
// it's better to disable CM3623 before apply new setting
// So, we disable current functionality and apply new setting
// If the functions are enabled before, after apply new setting
// we should enable the functions again
static DCL_STATUS _cm3623_pxs_enable(DCL_BOOL enable, DCL_BOOL notify)
{
	kal_bool ret;

	if (enable)
	{
		// Enable PXS function because PXS function is turned on before

		// Set INTR register
		_cm3623_ctrl_pxs_intr_enable_reg(notify);

		// Set PXS enable register
		_cm3623_ctrl_pxs_enable_reg(DCL_TRUE);
	}
	else
	{
		// Set INTR register
		_cm3623_ctrl_pxs_intr_enable_reg(DCL_FALSE);

		// Set PXS enable register
		_cm3623_ctrl_pxs_enable_reg(DCL_FALSE);
	}


	// Ack INTR
	_cm3623_ack_intr();

	ret = cm3623_reg_write(cm3623_reg_val[PS_CMD].reg, cm3623_reg_val[PS_CMD].val);
	if (KAL_FALSE == ret)
	{
		return STATUS_FAIL;
	}
	return STATUS_OK;
}


static void cm3623_delay(kal_uint32 delay)
{
	// Currently not implemented
	;
}


static DCL_STATUS cm3623_get_pxs_raw_data(PXS_CTRL_RAW_DATA_T *pRawData)
{
	kal_bool ret;

	//ASSERT(DCL_TRUE == cm3623_pxs_enable_flag);
	//if (DCL_TRUE != cm3623_pxs_enable_flag)
	//{
	//	ASSERT(0); // PXS is NOT enabled
	//}
	if (DCL_TRUE != cm3623_pxs_enable_flag)
	{
		return STATUS_FAIL;
	}

	// Get raw data from sensor
	ret = cm3623_reg_read(cm3623_reg_val[PS_DATA].reg, &(cm3623_reg_val[PS_DATA].val));
	if (ret == KAL_FALSE)
	{
		return STATUS_FAIL;
	}

	pRawData->u2Data = (DCL_UINT16)cm3623_reg_val[PS_DATA].val;


	return STATUS_OK;
}

static DCL_STATUS cm3623_pxs_EM_read(PXS_CTRL_EM_PARAM_T *pEMParam)
{
	DCL_UINT32 val;

	// Translate EM parameters to sensor specific parameters

	// Fill PollingPeriod
	pEMParam->u4PollingPeriod = CM3623_EM_POLLING_PERIOD;

	// Fill P1
	val = 0;
	val |= (DCL_UINT32)(cm3623_reg_val[PS_CMD].reg << 24);
	val |= (DCL_UINT32)(cm3623_reg_val[PS_CMD].val << 16);
	val |= 0x0000FFFF;
	pEMParam->u4P1 = val;
	
	// Fill P2
	val = 0;
	val |= (DCL_UINT32)(cm3623_reg_val[PS_THD].reg << 24);
	val |= (DCL_UINT32)(cm3623_reg_val[PS_THD].val << 16);
	val |= 0x0000FFFF;
	pEMParam->u4P2 = val;
	
	// Fill P3
	//cm3623_reg_read(cm3623_reg_val[PS_DATA].reg, &(cm3623_reg_val[PS_DATA].val));
	//val = 0;
	//val |= (DCL_UINT32) (cm3623_reg_val[PS_DATA].reg << 16);
	//val |= (DCL_UINT32) (cm3623_reg_val[PS_DATA].val << 0);
	//pEMParam->u4P3 = val;
	val |= 0xFFFFFFFF;
	pEMParam->u4P3 = val;

	// Fill P4
	val |= 0xFFFFFFFF;
	pEMParam->u4P4 = val;

	// Fill P5
	val |= 0xFFFFFFFF;
	pEMParam->u4P5 = val;
	
	// Fill P6
	val |= 0xFFFFFFFF;
	pEMParam->u4P6 = val;
	
	// Fill P7
	val |= 0xFFFFFFFF;
	pEMParam->u4P7 = val;
	
	// Fill P8
	val |= 0xFFFFFFFF;
	pEMParam->u4P8 = val;
	

	return STATUS_OK;
}

kal_bool _cm3623_pxs_EM_write(DCL_UINT32 param)
{
	DCL_UINT8 reg;
	DCL_UINT8 val;
	//DCL_UINT32 param = P;
	DCL_UINT32 i;
	kal_bool ret = KAL_TRUE;

	do
	{
		reg = (DCL_UINT8)((param & 0x0000FF00) >> 8);
		val = (DCL_UINT8)(param & 0x000000FF);

		if (reg != 0xFF)
		{
			for (i=0;i<CM3623_REG_NUM;i++)
			{
				if (cm3623_reg_val[i].reg == reg)
				{
					cm3623_reg_val[i].val = val;
					_cm3623_ack_intr();
					if (KAL_TRUE != cm3623_reg_write(cm3623_reg_val[i].reg, cm3623_reg_val[i].val))
					{
						ret = KAL_FALSE;
					}
				}
			}
		}
		param = param >> 16;
	}while (param != 0);
}

static DCL_STATUS cm3623_pxs_EM_write(PXS_CTRL_EM_PARAM_T *pEMParam)
{
	kal_bool ret = KAL_TRUE;


	if (DCL_TRUE != cm3623_pxs_enable_flag)
	{
		return STATUS_FAIL;
	}

	// Translate EM parameters to sensor specific parameters

	// Parse P1
	if (KAL_TRUE != _cm3623_pxs_EM_write(pEMParam->u4P1))
	{
		ret = KAL_FALSE;
	}
	// Parse P2
	if (KAL_TRUE != _cm3623_pxs_EM_write(pEMParam->u4P2))
	{
		ret = KAL_FALSE;
	}
	// Parse P3
	if (KAL_TRUE != _cm3623_pxs_EM_write(pEMParam->u4P3))
	{
		ret = KAL_FALSE;
	}
	// Parse P4
	if (KAL_TRUE != _cm3623_pxs_EM_write(pEMParam->u4P4))
	{
		ret = KAL_FALSE;
	}


	if (KAL_TRUE == ret)
	{
		return STATUS_OK;
	}

	return STATUS_FAIL;
}

static DCL_STATUS cm3623_pxs_get_adv_algo_windowing(PXS_CTRL_GET_ADV_ALGO_WINDOWING_T *pAdvAlgoWindowing)
{
	return STATUS_UNSUPPORTED;
}

static DCL_STATUS cm3623_pxs_get_adv_algo_threshold(PXS_CTRL_GET_ADV_ALGO_THRESHOLD_T *pAdvAlgoThreshold)
{
	return STATUS_UNSUPPORTED;
}

static DCL_STATUS cm3623_enable(PXS_CTRL_ENABLE_T *pEnable)
{
	DCL_STATUS ret;

	if (cm3623_pxs_enable_flag == pEnable->fgEnable)
	{
		return STATUS_OK;
	}

	if (DCL_TRUE == pEnable->fgEnable)
	{
		//ASSERT(DCL_FALSE == cm3623_pxs_enable_flag);
		//if (cm3623_pxs_enable_flag)
		//{
		//	ASSERT(0); // Not allow enable twice
		//}

		ret = _cm3623_pxs_enable(DCL_TRUE, HPXSConfig.fgNotify);
		if (STATUS_OK != ret)
		{
			return STATUS_FAIL;
		}

		// Enable PXS function
		cm3623_pxs_enable_flag = pEnable->fgEnable;

		if (HPXSConfig.fgNotify)
		{
			EINT_UnMask(CM3623_EINT);
		}

	}
	else
	{
		//ASSERT(DCL_TRUE == cm3623_pxs_enable_flag);

		if (HPXSConfig.fgNotify)
		{
			EINT_Mask(CM3623_EINT);
		}

		ret = _cm3623_pxs_enable(DCL_FALSE, HPXSConfig.fgNotify);
		if (STATUS_OK != ret)
		{
			return STATUS_FAIL;
		}

		// Disable PXS function
		cm3623_pxs_enable_flag = pEnable->fgEnable;

	}

	return STATUS_OK;
}

static void cm3623_eint_hisr(void)
{

	PXS_CTRL_RAW_DATA_T raw_data;
	kal_uint8 intr_addr;
	kal_bool pxs_intr = KAL_FALSE;
	kal_bool als_intr = KAL_FALSE;

	#if defined(PXS_KAL_PROMPT_DEBUG)
	kal_prompt_trace(MOD_BMT,"cm3623_eint_hisr");
	#endif // #if defined(PXS_KAL_PROMPT_DEBUG)

	// Get INTR source
	do
	{
		intr_addr = _cm3623_get_intr_addr();
		switch (intr_addr)
		{
			case PS_CMD_ADDR:
				pxs_intr = KAL_TRUE;
				#if defined(PXS_KAL_PROMPT_DEBUG)
				kal_prompt_trace(MOD_BMT,"cm3623 PXS intr");
				#endif // #if defined(PXS_KAL_PROMPT_DEBUG)
			break;
			case ALS_CMD_ADDR:
				als_intr = KAL_TRUE;
				#if defined(PXS_KAL_PROMPT_DEBUG)
				kal_prompt_trace(MOD_BMT,"cm3623 ALS intr");
				#endif // #if defined(PXS_KAL_PROMPT_DEBUG)
			break;
			default:
				#if defined(PXS_KAL_PROMPT_DEBUG)
				kal_prompt_trace(MOD_BMT,"cm3623 unknown intr addr: %x", intr_addr);
				#endif // #if defined(PXS_KAL_PROMPT_DEBUG)
			break;
		}

		//intr_addr = _cm3623_get_intr_addr();
	}while (intr_addr != INVALID_INTR_ADDR);

	// Handle PXS intr
	if (pxs_intr)
	{
		//ASSERT(HPXSConfig.fgNotify);
		if (DCL_TRUE == HPXSConfig.fgNotify)
		{
			ASSERT(HPXSConfig.NotifyCallback);

			ASSERT(STATUS_OK == cm3623_get_pxs_raw_data(&raw_data));

			if ((kal_uint8)raw_data.u2Data >= pxs_threshold)
			{
				HPXSConfig.NotifyCallback(DCL_TRUE);
				#if defined(PXS_KAL_PROMPT_DEBUG)
				kal_prompt_trace(MOD_BMT,"cm3623_pxs_eint_hisr, %d, %d", 1, raw_data.u2Data);
				#endif // #if defined(PXS_KAL_PROMPT_DEBUG)
			}
			else
			{
				HPXSConfig.NotifyCallback(DCL_FALSE);
				#if defined(PXS_KAL_PROMPT_DEBUG)
				kal_prompt_trace(MOD_BMT,"cm3623_pxs_eint_hisr, %d, %d", 0, raw_data.u2Data);
				#endif // #if defined(PXS_KAL_PROMPT_DEBUG)
			}
		}
		pxs_intr = KAL_FALSE;
	}
	if (als_intr)
	{

		als_intr = KAL_FALSE;
	}


	EINT_UnMask(CM3623_EINT);
}

static DCL_STATUS cm3623_pxs_modify_config(PXS_CTRL_CONFIG_T *pPXSConfig)
{
	DCL_STATUS ret = STATUS_OK;

// Always call back to DCL_PXS layer, in H/W level, don't need to implement this CMD
/*
	// Disable PXS first
	ret = _cm3623_pxs_enable(DCL_FALSE, HPXSConfig.fgNotify);

	HPXSConfig.fgNotify = pPXSConfig->fgNotify;
	HPXSConfig.NotifyCallback = pPXSConfig->NotifyCallback;

	if (cm3623_pxs_enable_flag)
	{
		// Disable PXS first
		ret = _cm3623_pxs_enable(DCL_TRUE, HPXSConfig.fgNotify);
	}
*/
	return ret;

}

static DCL_STATUS cm3623_set_sensitivity_level(PXS_CTRL_SET_SENSITIVITY_LEVEL_T *pPXSSensitivityLevel)
{
	kal_bool ret = KAL_TRUE;
	kal_uint16 level = pPXSSensitivityLevel->u2Level;
	ASSERT(level<cm3623_sens_level_num);
	pxs_threshold = p_cm3623_sens_level_table[level];


	if (DCL_TRUE == cm3623_pxs_enable_flag)
	{
		// Disable PXS first
		_cm3623_pxs_enable(DCL_FALSE, HPXSConfig.fgNotify);
	}

	// Set PXS data threshold value
	cm3623_reg_val[PS_THD].val = pxs_threshold;
	ret = cm3623_reg_write(cm3623_reg_val[PS_THD].reg, cm3623_reg_val[PS_THD].val);
	if (KAL_FALSE == ret)
	{
		return STATUS_FAIL;
	}

	if (DCL_TRUE == cm3623_pxs_enable_flag)
	{
		// Enable PXS first
		_cm3623_pxs_enable(DCL_TRUE, HPXSConfig.fgNotify);
	}

}

static DCL_STATUS cm3623_init(void)
{
	kal_bool ret;
	kal_uint8 i;
	kal_bool intr_debounce = KAL_FALSE;
	// Init CM3623 release control structures
	cm3623_reg_val[ALS_CMD].reg = ALS_CMD_ADDR;
	cm3623_reg_val[ALS_CMD].val = 0;
	cm3623_reg_val[ALS_DATA_MSB].reg = ALS_DATA_MSB_ADDR;
	cm3623_reg_val[ALS_DATA_MSB].val = 0;
	cm3623_reg_val[ALS_DATA_LSB].reg = ALS_DATA_LSB_ADDR;
	cm3623_reg_val[ALS_DATA_LSB].val = 0;
	cm3623_reg_val[PS_CMD].reg = PS_CMD_ADDR;
	cm3623_reg_val[PS_CMD].val = 0;
	cm3623_reg_val[PS_DATA].reg = PS_DATA_ADDR;
	cm3623_reg_val[PS_DATA].val = 0;
	cm3623_reg_val[PS_THD].reg = PS_THD_ADDR;
	cm3623_reg_val[PS_THD].val = 0;
	cm3623_reg_val[INIT].reg = PS_INIT_ADDR;
	cm3623_reg_val[INIT].val = 0;
	cm3623_reg_val[ARA].reg = ARA_ADDR;
	cm3623_reg_val[ARA].val = 0;

	// Get customized information
	if (KAL_FALSE == pxs_custom_hw_cmd_handler(PXS_HW_CMD_GET_SENSITIVITY_LEVEL_NUM, (void *)(&cm3623_sens_level_num)))
	{
		ASSERT(0);  // At least should contain 1 level
	}

	if (KAL_FALSE == pxs_custom_hw_cmd_handler(PXS_HW_CMD_GET_SENSITIVITY_TABLE, (void *)(&p_cm3623_sens_level_table)))
	{
		ASSERT(0);
	}
	// Make sure the pointer is assigned
	ASSERT(p_cm3623_sens_level_table);

	// Get PXS threshold
	pxs_threshold = p_cm3623_sens_level_table[0];

	// Init driver control structures
	cm3623_pxs_enable_flag = DCL_FALSE;
	HPXSConfig.fgNotify = DCL_FALSE;
	HPXSConfig.NotifyCallback = NULL;


	// Power on device
	{
		kal_bool param = KAL_TRUE;
		if (KAL_FALSE == pxs_custom_hw_cmd_handler(PXS_HW_CMD_POWER_ENABLE, (void *)&param))
		{
			ASSERT(0);
		}
	}
	cm3623_delay(CM3623_POWER_ON_DELAY);

	// Init communication interface
	if (KAL_FALSE == cm3623_comm_init())
	{
		return STATUS_FAIL;
	}


	// Clear unexpected INTR (CM3623 specific init step)
	// The INTR may caused by two different event (ALS or PXS), better to clear twice
	_cm3623_ack_intr();

	// Init PXS
	//cm3623_reg_val[PS_CMD].val = (SD_PS_MASK | INT_PS_MASK);
	cm3623_reg_val[PS_CMD].val = (SD_PS_MASK);
	ret = cm3623_reg_write(cm3623_reg_val[PS_CMD].reg, cm3623_reg_val[PS_CMD].val);
	if (KAL_FALSE == ret)
	{
		return STATUS_FAIL;
	}

	// Find and init sensor
	cm3623_reg_val[INIT].val = 0x10;
	ret = cm3623_reg_write(cm3623_reg_val[INIT].reg, cm3623_reg_val[INIT].val);
	if (KAL_FALSE == ret)
	{
		return STATUS_FAIL;
	}

	// Init ALS/PXS function
	  // Init ALS
	cm3623_reg_val[ALS_CMD].val = 0x01;  // Shut down ALS
	ret = cm3623_reg_write(cm3623_reg_val[ALS_CMD].reg, cm3623_reg_val[ALS_CMD].val);
	if (KAL_FALSE == ret)
	{
		return STATUS_FAIL;
	}

	  // Set PXS data threshold value
	cm3623_reg_val[PS_THD].val = pxs_threshold;
	ret = cm3623_reg_write(cm3623_reg_val[PS_THD].reg, cm3623_reg_val[PS_THD].val);
	if (KAL_FALSE == ret)
	{
		return STATUS_FAIL;
	}


	// Register interrupt if necessary
	EINT_Mask(CM3623_EINT);
	if (CM3623_EINT_DEBOUNCE > 0)
	{
		intr_debounce = KAL_TRUE;
		/*lint -e64*/
		EINT_SW_Debounce_Modify(CM3623_EINT, CM3623_EINT_DEBOUNCE);
		/*lint +e64*/
	}
	EINT_Set_Sensitivity(CM3623_EINT, CM3623_INTR_SENE_TYPE);
	/*lint -e64*/
	EINT_Registration(CM3623_EINT,intr_debounce,CM3623_INTR_ACTIVE_LEVEL,cm3623_eint_hisr, KAL_FALSE);
	/*lint +e64*/


	return STATUS_OK;

}


// DclHPXS_XXX interface
DCL_STATUS DclHPXS_Initialize(void)
{
	return cm3623_init();
}

DCL_HANDLE DclHPXS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	PXS_CONFIG_T *pPXSConfig;

	ASSERT(configure);
	pPXSConfig = (PXS_CONFIG_T *)(configure);

	HPXSConfig.fgNotify = pPXSConfig->fgNotify;
	HPXSConfig.NotifyCallback = pPXSConfig->NotifyCallback;

}

DCL_STATUS DclHPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	ASSERT(data);
	switch (cmd)
	{
		case PXS_CMD_ENABLE:
		{
			return cm3623_enable((PXS_CTRL_ENABLE_T *)((data)));
		}
		break;
		case PXS_CMD_EM_READ:
		{
			return cm3623_pxs_EM_read((PXS_CTRL_EM_PARAM_T *)((data)));
		}
		break;
		case PXS_CMD_EM_WRITE:
		{
			return cm3623_pxs_EM_write((PXS_CTRL_EM_PARAM_T *)((data)));
		}
		break;
		case PXS_CMD_GET_RAW_DATA:
		{
			return cm3623_get_pxs_raw_data((PXS_CTRL_RAW_DATA_T *)((data)));
		}
		break;
		case PXS_CMD_GET_ADV_ALGO_WINDOWING:
		{
			return cm3623_pxs_get_adv_algo_windowing((PXS_CTRL_GET_ADV_ALGO_WINDOWING_T *)((data)));
		}
		break;
		case PXS_CMD_GET_ADV_ALGO_THRESHOLD:
		{
			return cm3623_pxs_get_adv_algo_threshold((PXS_CTRL_GET_ADV_ALGO_THRESHOLD_T *)((data)));
		}
		break;
		case PXS_CMD_MODIFY_CONFIG:
		{
			return cm3623_pxs_modify_config((PXS_CTRL_CONFIG_T *)((data)));
		}
		break;
		case PXS_CMD_GET_SENSITIVITY_LEVEL_NUM:
		{
			PXS_CTRL_GET_SENSITIVITY_LEVEL_NUM_T *prPXSSensitivityLevelNum;
			prPXSSensitivityLevelNum = (PXS_CTRL_GET_SENSITIVITY_LEVEL_NUM_T*) data;
			prPXSSensitivityLevelNum->u2LevelNum = cm3623_sens_level_num;
		}
		break;
		case PXS_CMD_SET_SENSITIVITY_LEVEL:
		{
			return cm3623_set_sensitivity_level((PXS_CTRL_SET_SENSITIVITY_LEVEL_T*) (data));
		}
		break;
		default:
			//ASSERT(0);
			return STATUS_INVALID_CMD;
		break;
	}

	// return STATUS_OK;
}

DCL_STATUS DclHPXS_Close(DCL_HANDLE handle)
{
	return STATUS_UNSUPPORTED;
}




#endif // #if defined(__PXS_CM3623__)
