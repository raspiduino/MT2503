/******************************************************************************
 * track_interrupt.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *       端口模块 : 中断，GPIO(油电、马达)，SIM卡
 *
 * modification history
 * --------------------
 * v1.0   2012-07-24,  chengjun create this file
 *
 ******************************************************************************/

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_drv_eint_gpio.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "sim_public_enum.h"
#include "track_drv.h"
#include "dcl_pmu_common_sw.h"
#include "track_os_ell.h"
#include "Track_cust.h"
/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define PMU_VIBR_1300_MV  0
#define PMU_VIBR_1500_MV  0x10
#define PMU_VIBR_1800_MV  0x20
#define PMU_VIBR_2500_MV  0x30
#define PMU_VIBR_2800_MV  0x40
#define PMU_VIBR_3000_MV  0x50
#define PMU_VIBR_3300_MV  0x60
/*定义马达输出电压，配置寄存器*/

/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/


/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/

/*****************************************************************************
* Golbal variable				全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/
extern nvram_realtime_struct    G_realtime_data;

/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
extern kal_uint8 track_cust_status_acc(void);
extern char track_GPIO_ReadIO(kal_uint16 port);
/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/

static void track_eint_C_registration(void);
static void track_eint_resp_C_high(void);
static void track_eint_resp_C_low(void);

static void track_eint_trigger_response(U8 eint, U8 level);
#if (EINT_D_NO != GPIO_EINT_NO_USE)
static void track_eint_resp_D_high(void);
static void track_eint_resp_D_low(void);
static void track_eint_D_registration(void);
#endif

#if (EINT_E_NO != GPIO_EINT_NO_USE)
static void track_eint_resp_E_high(void);
static void track_eint_resp_E_low(void);
static void track_eint_E_registration(void);
#endif


/******************************************************************************
 *  Function    -  track_drv_set_LDO
 *
 *  Purpose     -  GPS开启VCAMD供电
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 23-01-2013,  WJ  written
  * v2.0  , 20150515,  wq  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_set_LDO(kal_bool ON, PMU_LDO_BUCK_LIST_ENUM ldo, PMU_VOLTAGE_ENUM ldo_volt)
{
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN pmu_ldo_voltage_en;
    PMU_CTRL_LDO_BUCK_SET_EN pmu_ldo_en;
    DCL_HANDLE ctp_pmu_handle;

    LOGD(L_DRV, L_V5, "ON/OFF:%d, ldo:%d, volt:%d", ON, ldo, ldo_volt);
    if(ctp_pmu_handle == DCL_HANDLE_NONE)
    {
        ctp_pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    }
    if(ON && (ldo_volt != 0))
    {
        pmu_ldo_voltage_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
        pmu_ldo_voltage_en.voltage = (PMU_VOLTAGE_ENUM)ldo_volt;
        DclPMU_Control(ctp_pmu_handle, LDO_BUCK_SET_VOLTAGE_EN, (DCL_CTRL_DATA_T *)& pmu_ldo_voltage_en);
    }
    else if(ON && (ldo_volt == 0))
    {
        pmu_ldo_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
        pmu_ldo_en.enable = KAL_TRUE;
        DclPMU_Control(ctp_pmu_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_ldo_en);
    }
    else
    {
        pmu_ldo_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
        pmu_ldo_en.enable = KAL_FALSE;
        DclPMU_Control(ctp_pmu_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_ldo_en);
    }
}
void track_drv_Set_VMC(kal_bool flag, kal_uint32 volt_status)
{

    DCL_HANDLE handle;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN val1;
    PMU_CTRL_LDO_BUCK_SET_ON_SEL val2;
    PMU_CTRL_LDO_BUCK_SET_EN val;
    DCL_STATUS status;
    kal_uint32 volt = 0;

    if(volt_status == 0)
    {
        volt = 0;//0V
    }
    else if(volt_status == 1)
    {
        volt = 1800000;//1.8V
    }
    else if(volt_status == 2)
    {
        volt = 2800000;//2.8V
    }
    else if(volt_status == 3)
    {
        volt = 3000000;//3.0V
    }
    else
    {
        volt = 3300000;//3.3V
    }

    LOGD(L_DRV, L_V5, "@track_drv_Set_VMC@");
    //设置电压
    val1.mod = VMC;
    val1.voltage = volt;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    status = DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *) & val1);
    LOGD(L_DRV, L_V5, "status 1=%d", status);
    //VMC控制口开关
    val2.onSel = 1;
    val2.mod = VMC;
    DclPMU_Control(handle, LDO_BUCK_SET_ON_SEL, (DCL_CTRL_DATA_T *)&val2);

    //举例：打开VMC
    val.enable = flag;
    val.mod = VMC;
    status = DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *) & val);
    LOGD(L_DRV, L_V5, "status 2=%d", status);

    DclPMU_Close(handle);
}

#if (EINT_A_NO != GPIO_EINT_NO_USE)
/*对于中断口初始状态注册 :
推荐使用GPIO_ReadIO，但部分GPIO 读入结果与实际不符，
因此通过定时器主动反向注册第二次*/

// A
/******************************************************************************
 *  Function    -  track_eint_A_hisr
 *
 *  Purpose     -  中断A 响应函数
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-01-2013,  chengjun  written
 * v1.1  , 16-05-2013,  cml       written
 * ----------------------------------------
 ******************************************************************************/
static void track_eint_A_hisr(void)
{
    kal_bool eint_A_status;
    EINT_Mask(EINT_A_NO);
    if(GPIO_ReadIO(EINT_A_GPIO))
    {
        track_eint_trigger_response(EINT_A_NO, LEVEL_HIGH);
        eint_A_status = LEVEL_LOW;
    }
    else
    {
        track_eint_trigger_response(EINT_A_NO, LEVEL_LOW);
        eint_A_status = LEVEL_HIGH;
    }
    EINT_SW_Debounce_Modify(EINT_A_NO, EINT_SW_DEBOUNCE_TIME);
    EINT_Set_Polarity(EINT_A_NO, eint_A_status);
    EINT_UnMask(EINT_A_NO);
}

/******************************************************************************
 *  Function    -  track_eint_A_registration
 *
 *  Purpose     -  中断A 初始化
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-01-2013,  chengjun  written
 * v1.1  , 16-05-2013,  cml       written
 * ----------------------------------------
 ******************************************************************************/
static void track_eint_A_registration(void)
{
    if(EINT_A_NO == GPIO_EINT_NO_USE)
    {
        return;
    }
    EINT_Mask(EINT_A_NO);
    GPIO_InitIO(0, EINT_A_GPIO);
    LOGD(L_DRV, L_V4, "EINTA %d, GPIO:%d, M:%d, %d", EINT_A_NO, EINT_A_GPIO, EINT_A_EINT_MODE, kal_get_active_module_id());
    GPIO_ModeSetup(EINT_A_GPIO, EINT_A_EINT_MODE);
    EINT_SW_Debounce_Modify(EINT_A_NO, EINT_SW_DEBOUNCE_TIME);
    EINT_Set_Sensitivity(EINT_A_NO, EINT_SENSITIVE_MODE);
    if(GPIO_ReadIO(EINT_A_GPIO))
    {
        track_eint_trigger_response(EINT_A_NO, LEVEL_HIGH);
        EINT_Registration(EINT_A_NO, KAL_TRUE, LEVEL_LOW, track_eint_A_hisr, KAL_TRUE);
    }
    else
    {
        track_eint_trigger_response(EINT_A_NO, LEVEL_LOW);
        EINT_Registration(EINT_A_NO, KAL_TRUE, LEVEL_HIGH, track_eint_A_hisr, KAL_TRUE);
    }
    EINT_UnMask(EINT_A_NO);
}
#endif

#if (EINT_B_NO != GPIO_EINT_NO_USE)
// B
/******************************************************************************
 *  Function    -  track_eint_B_hisr
 *
 *  Purpose     -  中断B 响应函数
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-01-2013,  chengjun  written
 * v1.1  , 16-05-2013,  cml       written
 * ----------------------------------------
 ******************************************************************************/
static void track_eint_B_hisr(void)
{
    kal_bool eint_A_status;

    EINT_Mask(EINT_B_NO);
    if(GPIO_ReadIO(EINT_B_GPIO))
    {
        track_eint_trigger_response(EINT_B_NO, LEVEL_HIGH);
        eint_A_status = LEVEL_LOW;
    }
    else
    {
        track_eint_trigger_response(EINT_B_NO, LEVEL_LOW);
        eint_A_status = LEVEL_HIGH;
    }

    EINT_SW_Debounce_Modify(EINT_B_NO, EINT_SW_DEBOUNCE_TIME);

    EINT_Set_Polarity(EINT_B_NO, eint_A_status);

    EINT_UnMask(EINT_B_NO);
}

/******************************************************************************
 *  Function    -  track_eint_B_registration
 *
 *  Purpose     -  中断B 初始化
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_eint_B_registration(void)
{
    if(EINT_B_NO == GPIO_EINT_NO_USE)
    {
        return;
    }
    EINT_Mask(EINT_B_NO);
    LOGD(L_DRV, L_V6, "EINTB %d, GPIO:%d, M:%d, %d", EINT_B_NO, EINT_B_GPIO, EINT_B_EINT_MODE, kal_get_active_module_id());
    GPIO_ModeSetup(EINT_B_GPIO, EINT_B_EINT_MODE);

    EINT_SW_Debounce_Modify(EINT_B_NO, EINT_SW_DEBOUNCE_TIME);
    EINT_Set_Sensitivity(EINT_B_NO, EINT_SENSITIVE_MODE);
    if(GPIO_ReadIO(EINT_B_GPIO))
    {
        track_eint_trigger_response(EINT_B_NO, LEVEL_HIGH);
        EINT_Registration(EINT_B_NO, KAL_TRUE, LEVEL_LOW, track_eint_B_hisr, KAL_TRUE);
    }
    else
    {
        track_eint_trigger_response(EINT_B_NO, LEVEL_LOW);
        EINT_Registration(EINT_B_NO, KAL_TRUE, LEVEL_HIGH, track_eint_B_hisr, KAL_TRUE);
    }
    EINT_UnMask(EINT_B_NO);
}
#endif

#if (EINT_C_NO != GPIO_EINT_NO_USE)
// C
/******************************************************************************
 *  Function    -  track_eint_C_registration
 *
 *  Purpose     -  中断C 初始化
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_eint_C_registration(void)
{
    LOGD(L_DRV, L_V6, "EINTC %d, eint:%d, mode:%d", kal_get_active_module_id(), EINT_C_NO, EINT_C_EINT_MODE);

    if(EINT_C_NO == GPIO_EINT_NO_USE)
    {
        return;
    }
    EINT_Mask(EINT_C_NO);
    GPIO_ModeSetup(EINT_C_GPIO, EINT_C_EINT_MODE);
    EINT_SW_Debounce_Modify(EINT_C_NO, EINT_SW_DEBOUNCE_TIME);
    EINT_Set_Sensitivity(EINT_C_NO, EINT_SENSITIVE_MODE);
    if(GPIO_ReadIO(EINT_C_GPIO))
    {
        EINT_Registration(EINT_C_NO, KAL_TRUE, LEVEL_LOW, track_eint_resp_C_low, KAL_TRUE);
    }
    else
    {
        EINT_Registration(EINT_C_NO, KAL_TRUE, LEVEL_HIGH, track_eint_resp_C_high, KAL_TRUE);
    }
    EINT_UnMask(EINT_C_NO);

}


static void track_eint_resp_C_high(void)
{
    EINT_Mask(EINT_C_NO);
    track_eint_trigger_response(EINT_C_NO, LEVEL_HIGH);
    EINT_Registration(EINT_C_NO, KAL_TRUE, LEVEL_LOW, track_eint_resp_C_low, KAL_FALSE);
    EINT_UnMask(EINT_C_NO);
}
static void track_eint_resp_C_low(void)
{
    EINT_Mask(EINT_C_NO);
    track_eint_trigger_response(EINT_C_NO, LEVEL_LOW);
    EINT_Registration(EINT_C_NO, KAL_TRUE, LEVEL_HIGH, track_eint_resp_C_high, KAL_FALSE);
    EINT_UnMask(EINT_C_NO);
}
#endif

#if (EINT_E_NO != GPIO_EINT_NO_USE)


static void track_eint_resp_E_high(void)
{
    EINT_Mask(EINT_E_NO);
    track_eint_trigger_response(EINT_E_NO, LEVEL_HIGH);
    EINT_Registration(EINT_E_NO, KAL_TRUE, LEVEL_LOW, track_eint_resp_E_low, KAL_FALSE);
    EINT_UnMask(EINT_E_NO);
}

static void track_eint_resp_E_low(void)
{
    EINT_Mask(EINT_E_NO);
    track_eint_trigger_response(EINT_E_NO, LEVEL_LOW);
    EINT_Registration(EINT_E_NO, KAL_TRUE, LEVEL_HIGH, track_eint_resp_E_high, KAL_FALSE);
    EINT_UnMask(EINT_E_NO);
}


static void track_eint_E_registration(void)
{
    LOGD(L_DRV, L_V6, "EINTE %d, GPIO:%d, M:%d, %d", EINT_E_NO, EINT_E_GPIO, EINT_E_EINT_MODE, kal_get_active_module_id());

    if(EINT_E_NO == GPIO_EINT_NO_USE)
    {
        return;
    }

    EINT_Mask(EINT_E_NO);
    GPIO_ModeSetup(EINT_E_GPIO, EINT_E_EINT_MODE);
    EINT_SW_Debounce_Modify(EINT_E_NO, EINT_SW_DEBOUNCE_TIME);
    EINT_Set_Sensitivity(EINT_E_NO, EINT_SENSITIVE_MODE);

    EINT_Registration(EINT_E_NO, KAL_TRUE, LEVEL_LOW, track_eint_resp_E_low, KAL_TRUE);
    
    EINT_UnMask(EINT_E_NO);
}

#endif


#if (EINT_D_NO != GPIO_EINT_NO_USE)
static void track_eint_D_registration(void)
{
    LOGD(L_DRV, L_V6, "EINTD %d, GPIO:%d, M:%d, %d", EINT_D_NO, EINT_D_GPIO, EINT_D_EINT_MODE, kal_get_active_module_id());

    if(EINT_D_NO == GPIO_EINT_NO_USE)
    {
        return;
    }

    EINT_Mask(EINT_D_NO);
    GPIO_ModeSetup(EINT_D_GPIO, EINT_D_EINT_MODE);
    EINT_SW_Debounce_Modify(EINT_D_NO, EINT_SW_DEBOUNCE_TIME);
    EINT_Set_Sensitivity(EINT_D_NO, EINT_SENSITIVE_MODE);

    if(track_GPIO_ReadIO(EINT_D_GPIO))
    {
        EINT_Registration(EINT_D_NO, KAL_TRUE, LEVEL_LOW, track_eint_resp_D_low, KAL_TRUE);
    }
    else
    {
        EINT_Registration(EINT_D_NO, KAL_TRUE, LEVEL_HIGH, track_eint_resp_D_high, KAL_TRUE);
    }
    EINT_UnMask(EINT_D_NO);
}

static void track_eint_resp_D_high(void)
{
    EINT_Mask(EINT_D_NO);
    track_eint_trigger_response(EINT_D_NO, LEVEL_HIGH);
    EINT_Registration(EINT_D_NO, KAL_TRUE, LEVEL_LOW, track_eint_resp_D_low, KAL_FALSE);
    EINT_UnMask(EINT_D_NO);
}

static void track_eint_resp_D_low(void)
{
    EINT_Mask(EINT_D_NO);
    track_eint_trigger_response(EINT_D_NO, LEVEL_LOW);
    EINT_Registration(EINT_D_NO, KAL_TRUE, LEVEL_HIGH, track_eint_resp_D_high, KAL_FALSE);
    EINT_UnMask(EINT_D_NO);
}

#endif


/******************************************************************************
 *  Function    -  track_eint_trigger_response
 *
 *  Purpose     -  中断触发
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_eint_trigger_response(U8 eint, U8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    eint_status_struct *myMsgPtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (eint_status_struct*) construct_local_para(sizeof(eint_status_struct), TD_CTRL);
    myMsgPtr->eint = eint;
    myMsgPtr->level = level;

    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_DRV_HISR);
    /*注意:所有中断即使在MOD_MMI注册，track_drv_eint_trigger_msg()
    其响应函数是在MOD_DRV_HISR --  chengjun  2013-05-16*/
    ilm_ptr->src_mod_id = MOD_DRV_HISR;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = INVALID_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_EINT_TRIGGER_STATUS;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);
}
/******************************************************************************
 *  Function    -  track_project_eint_init_registration
 *
 *  Purpose     -  project文件，调用track_eint_trigger_response
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-12-7,  cjj  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_eint_init_registration(U8 eint, U8 level)
{
    track_eint_trigger_response(eint,level);
}
#if 1
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
#endif

/******************************************************************************
 *  Function    -  track_drv_eint_init_registration
 *
 *  Purpose     -  注册需要使用的中断口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 26-07-2012,  chengjun  written
 * v1.1  , 16-05-2013,  cml       written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_eint_init_registration(void)
{
#if (EINT_A_NO != GPIO_EINT_NO_USE)
    {
        track_eint_A_registration();
    }
#endif

#if (EINT_B_NO != GPIO_EINT_NO_USE)
    {
        track_eint_B_registration();
    }
#endif

#if (EINT_C_NO != GPIO_EINT_NO_USE)
    {
        track_eint_C_registration();
    }
#endif

#if (EINT_D_NO != GPIO_EINT_NO_USE)
    {
        track_eint_D_registration();
    }
#endif

#if (EINT_E_NO != GPIO_EINT_NO_USE)
    {
        track_eint_E_registration();
    }
#endif


}

/******************************************************************************
 *  Function    -  track_drv_eint_trigger_msg
 *
 *  Purpose     -  中断消息处理
 *
 *  Description -  中断触发发消息处理，不直接调用
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_eint_trigger_msg(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    eint_status_struct *localBuff_p = (eint_status_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOGD(L_DRV, L_V5, "Eint%d , Level=%d", localBuff_p->eint, localBuff_p->level);

#if defined (__TEST_PCBA__)
    track_drv_test_pcba_eint_status_updata(localBuff_p->eint, localBuff_p->level);
#endif /* __TEST_PCBA__ */

    track_drv_eint_trigger_response(localBuff_p->eint, localBuff_p->level);
}
/******************************************************************************
 *  Function    -  track_set_GPIO21_CUR
 *  Purpose     -  设置GPIO输出口电流
 *  0xA0020810  GPIO_DRV1
 *  GPIO20          KROW1       [7:6]
 *  GPIO21          KROW0       [9:8]
 *  00                  4ma
 *  01                  8ma
 *  10                  12ma
 *  11                  16ma
 * modification history
 * ----------------------------------------
 * v1.0  , 20150911,  wangqi  written
 * ----------------------------------------
 ******************************************************************************/
#define SFI_ReadReg32(addr)         *((volatile unsigned int *)(addr))
#define SFI_WriteReg32(addr, data)  *((volatile unsigned int *)(addr)) = (unsigned int)(data)
void track_set_GPIO21_CUR(kal_uint8 level)
{
    unsigned int drv1_value = *((volatile unsigned int *)(0xA0020810));
    if(level == 4)
    {
        //修改GPIO21的输出电流   1111 1100  1111 1111    9 8
        SFI_WriteReg32(0xA0020810, (SFI_ReadReg32(0xA0020810)&(0xFFFFFCFF)));  // driving 4mA
    }
    else if(level == 16)
    {
        SFI_WriteReg32(0xA0020810, (SFI_ReadReg32(0xA0020810) | 0x00000300)); // driving 16mA
    }
    //LOGS("GPIO21 [9:8]:(drv1_value:%x,%x)", drv1_value, *((volatile unsigned int *)(0xA0020810)));

}
void track_set_GPIO20_CUR(kal_uint8 level)
{
    unsigned int drv1_value = *((volatile unsigned int *)(0xA0020810));

    if(level == 4)
    {
        //修改GPIO20 KROW1的输出电流   1111 1111 0011 1111   7  6
        SFI_WriteReg32(0xA0020810, (SFI_ReadReg32(0xA0020810)&(0xFFFFFF3F))); //SLT driving 4mA
    }
    else if(level == 16)
    {
        SFI_WriteReg32(0xA0020810, (SFI_ReadReg32(0xA0020810) | 0x000000C0)); // driving 16mA
    }
    //LOGS("GPIO20 [7:6]:(drv1_value:%x,%x)", drv1_value, *((volatile unsigned int *)(0xA0020810)));

}

void track_set_GPIO29_CUR(kal_uint8 level)
{
    unsigned int drv1_value = *((volatile unsigned int *)(0xA0020810));

    if(level == 4)
    {
        //修改GPIO29 CMMCLK的输出电流   1100 1111 1111 1111   13  12
        SFI_WriteReg32(0xA0020810, (SFI_ReadReg32(0xA0020810)&(0xFFFFCFFF))); //SLT driving 4mA
    }
    else if(level == 16)
    {
        SFI_WriteReg32(0xA0020810, (SFI_ReadReg32(0xA0020810) | 0x00003000)); // driving 16mA
    }
    //LOGS("GPIO29 [13:12]:(drv1_value:%x,%x)", drv1_value, *((volatile unsigned int *)(0xA0020810)));

}

/******************************************************************************
 *  Function    -  track_set_uvlo
 * 
 *  Purpose     -  设置欠压保护，重启后失效
 * 
 *  Description -  MT6260:0xa700a28[1:0]
                    定义如下：
                        [1:0]
                        0:2.9V(default)
                        1:2.75V
                        2:2.6V
                        3:2.5V  
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2018-02-23,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_set_uvlo(kal_uint8 level)
{
    unsigned int drv1_value = *((volatile unsigned int *)(0xA0700A28));
    if(level<=3)
    {
        SFI_WriteReg32(0xA0700A28, ((SFI_ReadReg32(0xA0700A28)&(0xFFFFFFFC)) | level));
    }
}


/******************************************************************************
 *  Function    -  track_drv_gpio_init
 *
 *  Purpose     -  GPIO 初始化
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 01-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_gpio_init(void)
{
    LOGD(L_DRV, L_V5, "");

    if(0xff != CUT_OIL_ELE_GPIO)
    {
        GPIO_ModeSetup(CUT_OIL_ELE_GPIO, 0);
        GPIO_InitIO(1, CUT_OIL_ELE_GPIO);
    }

    track_project_gpio_init();

#if defined (__CUST_RS485__)
    track_drv_rs485_gpio_init();
#endif

}

kal_uint8  track_drv_gpio_out1(kal_int8 state)
{
    kal_uint8 rece;
    LOGD(L_DRV, L_V5, "rece=%d,state=%d", rece, state);
    rece = GPIO_ReadIO(CUST_OUT1_GPIO);
    if(state == 0 || state == 1)
    {
        if(rece != state)
        {
            int i;
            GPIO_WriteIO(state, CUST_OUT1_GPIO);
            rece = GPIO_ReadIO(CUST_OUT1_GPIO);
        }
    }
    return rece;
}
/*2503平台GPIO3 需要更换读取函数wangqi20160409*/
/*GPIO回读接口升级  --    chengjun  2016-07-13*/
char track_GPIO_ReadIO(kal_uint16 port)
{
    char rece = 0;

#if 1
    rece = OTA_GPIO_ReturnDout(port);
#else
    if(3 == port)
    {
        rece = OTA_GPIO_ReturnDout(port);
    }
    else
    {
        rece = GPIO_ReadIO(port);
    }
#endif
    return rece;
}
/******************************************************************************
 *  Function    -  track_drv_gpio_cut_oil_elec
 *
 *  Purpose     -  控制断油电
 *
 *  Description - state [in] 1 = 断油电/0 = 恢复  其它值查询返回当前的状态
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 01-08-2012,  chengjun  written
 * v1.1  , 05-10-2013,  cml       written
 * ----------------------------------------
 ******************************************************************************/
kal_int8 track_drv_gpio_cut_oil_elec(kal_int8 state)
{
    char rece;

    if(CUT_OIL_ELE_GPIO == GPIO_EINT_NO_USE)
    {
        return -1;
    }

    rece = track_GPIO_ReadIO(CUT_OIL_ELE_GPIO);

    if(state == 0 || state == 1)
    {
        if(rece != state)
        {
            int i;
            for(i = 0; i < 3; i++)
            {
                // 最多重复设置3次，防止设置失败。
                GPIO_WriteIO(state, CUT_OIL_ELE_GPIO);
                rece = track_GPIO_ReadIO(CUT_OIL_ELE_GPIO);
                if(rece == state)
                {
                    return rece;
                }
            }
            if(rece != state)
            {
                return -1;
            }
        }
    }
    return rece;
}
kal_int8 track_drv_gpio_set(kal_int8 state, kal_int8 port)
{
    char rece;
    rece = track_GPIO_ReadIO(port);
    LOGD(L_DRV, L_V5, "port%d=%d -> %d", port, rece, state);
    if(state == 0 || state == 1)
    {
        if(rece != state)
        {
            int i;
            for(i = 0; i < 3; i++)
            {
                // 最多重复设置3次，防止设置失败。
                GPIO_WriteIO(state, port);
                rece = track_GPIO_ReadIO(port);
                if(rece == state) return rece;
            }
            if(rece != state)
            {
                LOGS("Can not option GPIO:%d", port);
                return -1;
            }
        }
    }
    return rece;
}

void track_drv_set_gpio_low(void* port)
{
    kal_uint8 pr = (kal_uint8)port;
    track_drv_gpio_set(0, pr);
    LOGD(L_DRV, L_V5, "外电GPIO%d拉低", pr);
}

/******************************************************************************
 *  Function    -  track_drv_gpio_disconnect_ext_power
 *
 *  Purpose     -  外电导通控制
 *
 *  Description -  state
 *                 1         断开外电
 *                 0         导通外电
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 26-08-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_drv_gpio_disconnect_ext_power(kal_int8 state)
{
#if defined(__EXT_VBAT_ADC__)
    char rece;
    if(0xFF == EXT_POWER_GPIO)
    {
        LOGD(L_DRV, L_V6, "无IO控制");
        return;
    }

    //rece = GPIO_ReadIO(EXT_POWER_GPIO);
    rece = OTA_GPIO_ReturnDout(EXT_POWER_GPIO);


    if(state == 0 || state == 1)
    {
        if(rece != state)
        {
            int i;
            for(i = 0; i < 3; i++)
            {
                // 最多重复设置3次，防止设置失败。
                GPIO_WriteIO(state, EXT_POWER_GPIO);

                //rece = GPIO_ReadIO(EXT_POWER_GPIO);
                rece = OTA_GPIO_ReturnDout(EXT_POWER_GPIO);

                if(rece == state)
                {
                    LOGD(L_DRV, L_V5, "return state=%d==race=%d", state, rece);
#if defined(__MT200__)
                    LOGD(L_DRV, L_V5, "state=%d", state);
                    if(1 == state)
                    {
                        track_start_timer(TRACK_CUST_EXT_POWER_GPIO_LOW_TIMER_ID, 1000, track_drv_set_gpio_low, (void*)EXT_POWER_GPIO); // 脉冲
                    }
#endif
                    return rece;
                }
            }
            if(rece != state)
            {
                LOGS("!外电控制口执行动作不成功!current:%d", rece);
                return -1;
            }
        }
    }
    return rece;
#else
    return -1;
#endif /* __EXT_VBAT_ADC__ */
}

/******************************************************************************
 *  Function    -  track_drv_set_vibr
 *
 *  Purpose     -  震动马达(默认输出3.3V)
 *
 *  Description -  enable [in]
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 01-03-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_set_vibr(kal_bool enable)
{

    DCL_HANDLE handle;
    PMU_CTRL_LDO_BUCK_SET_EN val;
    static kal_bool first = KAL_TRUE;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE pmuCtrlVoltage;

    LOGD(L_APP, 1, "");
    if(first)
    {
        first = KAL_FALSE;
        PMU_DRV_SetData16(0xA07001B0, 0x70, /*PMU_VIBR_3300_MV*/PMU_VIBR_3000_MV);//WangQi
    }

    val.enable = enable;
    val.mod = VIBR;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
    pmuCtrlVoltage.voltage = PMU_VOLT_03_000000_V;
    pmuCtrlVoltage.mod = VIBR;
    DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&pmuCtrlVoltage);
    DclPMU_Close(handle);

    /*
    DCL_HANDLE handle;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE pmuCtrlVoltage;
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    pmuCtrlVoltage.voltage=PMU_VOLT_03_000000_V;
    pmuCtrlVoltage.mod=VIBR;
    DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&pmuCtrlVoltage);
    DclPMU_Close(handle);*/
}


/******************************************************************************
 *  Function    -  track_drv_get_sim_type
 *
 *  Purpose     -  查询SIM 卡状态/类型
 *
 *  Description -
 *
 *      return : 0=无卡/1=有普通SIM 卡/ 2=有测试卡/-1=未初始化/-2=异常/
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 28-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int8 track_drv_get_sim_type(void)
{
    sim_card_status_enum status;
    kal_int8 sim = 0;

    status = check_sim_card_status();
    if(status == SIM_CARD_NOT_INSERTED)
    {
        sim = 0;
    }
    else if(status == NORMAL_SIM_PRESENCE)
    {
        sim = 1;
    }
    else if(status == TEST_SIM_PRESENCE)
    {
        sim = 2;
    }
    else if(status == SIM_NOT_READY)
    {
        sim = -1;
    }
    else
    {
        sim = -2;
    }

    LOGD(L_DRV, L_V6, "sim=%d,%d", sim, status);
    return sim;

}


/******************************************************************************
 *  Function    -  track_remind_sim_for_factory
 *
 *  Purpose     -  为工厂测试提示SIM 卡状态
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 30-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_remind_sim_for_factory(kal_int8 sim)
{
    char str[20] = {0};
    if(sim == 0)
    {
        sprintf(str, "No SIM");
    }
    else if(sim == 1)
    {
        sprintf(str, "SIM OK");
    }
    else if(sim == 2)
    {
        sprintf(str, "Test card");
    }
    else
    {
        sprintf(str, "SIM error");
    }
    LOGS("%s", str);
}

/******************************************************************************
 *  Function    -  track_drv_query_sim_type
 *
 *  Purpose     -  读SIM 卡类型
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 23-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_query_sim_type(void)
{
    static kal_uint8 count = 0;
    kal_int8 sim_type;

    sim_type = track_drv_get_sim_type();
    track_remind_sim_for_factory(sim_type);
    track_drv_remind_sim_type(sim_type);

    if(sim_type <= 0)
    {
        count++;
        if(count < 3)
        {
            LOGD(L_DRV, L_V5, "%d,%d", sim_type, count);
            tr_start_timer(TRACK_QUERY_SIM_TYPE_TIMER_ID, 5000, track_drv_query_sim_type);
        }
    }
}


/******************************************************************************
 *  Function    -  track_drv_set_vcama
 *  Purpose     -  GPS开启VCAMA供电
 *  Description -
 * modification history
 * ----------------------------------------
 * v1.0  , 20150303,    written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_set_vcama(kal_bool ON,/* kal_uint32 ldo,*/ kal_uint32 ldo_volt)
{
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN pmu_ldo_voltage_en;
    PMU_CTRL_LDO_BUCK_SET_EN pmu_ldo_en;
    DCL_HANDLE ctp_pmu_handle;

    LOGD(L_DRV, L_V7, "ON/OFF:%d, volt:%d", ON, ldo_volt);

    if(ctp_pmu_handle == DCL_HANDLE_NONE)
    {
        ctp_pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    }
    if(ON && (ldo_volt != 0))
    {
        pmu_ldo_voltage_en.mod = (PMU_LDO_BUCK_LIST_ENUM)VCAMA;
        pmu_ldo_voltage_en.voltage = (PMU_VOLTAGE_ENUM)ldo_volt;
        DclPMU_Control(ctp_pmu_handle, LDO_BUCK_SET_VOLTAGE_EN, (DCL_CTRL_DATA_T *)& pmu_ldo_voltage_en);
    }
    else if(ON && (ldo_volt == 0))
    {
        pmu_ldo_en.mod = (PMU_LDO_BUCK_LIST_ENUM)VCAMA;
        pmu_ldo_en.enable = KAL_TRUE;
        DclPMU_Control(ctp_pmu_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_ldo_en);
    }
    else
    {
        pmu_ldo_en.mod = (PMU_LDO_BUCK_LIST_ENUM)VCAMA;
        pmu_ldo_en.enable = KAL_FALSE;
        DclPMU_Control(ctp_pmu_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_ldo_en);
    }
}

kal_int8 track_drv_oli_cut_pwm(void* run_time)
{
    static kal_uint32 count = 1;

    count = (kal_uint32)run_time;
    LOGD(L_DRV, L_V4, "count=%d", count);
    if(count == 1)
    {
        GPIO_WriteIO(1, CUT_OIL_ELE_GPIO);
        if(GPIO_ReadIO(CUT_OIL_ELE_GPIO) == 1)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        count --;
        if(GPIO_ReadIO(CUT_OIL_ELE_GPIO) == 0)
        {
            LOGD(L_DRV, L_V5, "继电器 H - %d", count);
            GPIO_WriteIO(1, CUT_OIL_ELE_GPIO);
        }
        else
        {
            LOGD(L_DRV, L_V5, "继电器 L - %d", count);
            GPIO_WriteIO(0, CUT_OIL_ELE_GPIO);
        }
        track_start_timer(TRACK_DRV_OIL_CUT_PULSE_TIMER_ID, 1000, track_drv_oli_cut_pwm, (void *)count);
        return count;
    }
}

#if (BUZZER_GPIO != GPIO_EINT_NO_USE)
/*蜂鸣器工作一段时间       --    chengjun  2017-10-13*/
static void track_drv_buzzer_sound_off(void)
{
    GPIO_WriteIO(0, BUZZER_GPIO);
}

void track_drv_buzzer_sound_on(kal_uint8 sec)
{
    static kal_uint8 first=1;

    if(first==1)
    {
        first=0;

        GPIO_ModeSetup(BUZZER_GPIO, 0);
        GPIO_InitIO(1, BUZZER_GPIO);
    }

    GPIO_WriteIO(1, BUZZER_GPIO);

    tr_start_timer(TRACK_DRV_BUZZER_SOUND_TIMER_ID, sec*1000, track_drv_buzzer_sound_off);
}
#endif

