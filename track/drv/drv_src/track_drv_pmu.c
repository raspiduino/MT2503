/******************************************************************************
 * track_drv_pmu.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        PMU 模块: 充电与电池状态处理 ，休眠等
 *
 * modification history
 * --------------------
 * v1.0   2012-07-20,  chengjun create this file
 *
 ******************************************************************************/


/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "drvsignals.h"
#include "dcl.h"
#include "dcl_adc.h"
#include "Track_cust.h"

#include "track_drv_pmu.h"
#include "track_os_timer.h"
#include "track_os_ell.h"

/*****************************************************************************
* Typedef  Enum                         枚举定义
*****************************************************************************/

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
static kal_uint8 track_drv_sleep_status = 0xFF;
static U32 volt_from_obd = 0;

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#if defined (__EXT_VBAT_ADC__)
static kal_int32  adc_external_batter = 0;

//ADC4 测量结果按比例扩大计算出实际值
//不同外电的版本，硬件不同的分压电路，该值也不同
#if defined(__NT13V__) || defined(__NT17__)
#define EXTERNAL_BATTER_EXPAND  41
#elif defined(__NF2319__)||defined (__NF2318__)
#define EXTERNAL_BATTER_EXPAND  (31.3)
#else
#define EXTERNAL_BATTER_EXPAND  11
#endif

//二极管压降进行补偿
#if defined(__NF2318__)
#define EXTERNAL_OFFSET_VOLTAGE  700000
#else
#define EXTERNAL_OFFSET_VOLTAGE  0
#endif

#endif /* __EXT_VBAT_ADC__ */

//借用(Vtemp <2.3 ) 判断有电池
#define BATTER_EXIST_VOLTAGE        2.3



/*****************************************************************************
* Local variable                        局部变量
*****************************************************************************/
static DCL_HANDLE  adc_low_vbat_measure = DCL_HANDLE_INVALID;
static kal_int32 drv_batter_voltage = 0; // 10^(-6) uint uV
static chr_way_enum bmt_charge_in = NO_CHR;
static U32 g_Period = 0;
static U8 g_EvaluateCount = 0;
static U8 g_ext_vbat_a_quick_detection = 0;
/****************************************************************************
* Global Variable                       全局变量
*****************************************************************************/
//charge_measure_struct charge_measure = {0};
//charge_adc_count_struct charge_adc_count = {0};

/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/
extern const kal_uint8 ADC_LOW_VBAT;

/*****************************************************************************
 *  Global Functions    - Extern        引用外部函数
 *****************************************************************************/
extern kal_int32 track_drv_get_external_voltage_status(void);

/*****************************************************************************
 *  Local Functions                     本地函数
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
kal_uint8 track_drv_bmt_get_charging_status(void)
{
    return (kal_uint8)bmt_charge_in;
}

kal_uint32 track_drv_bmt_get_vol(void)
{
    kal_uint32 cur_vol = 0;
    charge_measure_struct charge_measure = {0};

    if(track_drv_bmt_get_charging_status())
    {
        track_bmt_get_ADC_result(&charge_measure);
        cur_vol = (kal_uint32)(charge_measure.bmt_vBat * 1000000);
    }
    else
    {
        cur_vol = drv_batter_voltage;
    }
    LOGD(L_DRV, L_V5, "@@@charge:%d,cur_vol:%d", track_drv_bmt_get_charging_status(), cur_vol);
    return cur_vol;
}
/******************************************************************************
 *  Function    -  track_drv_bmt_charging_result
 *
 *  Purpose     -  打印充电电池状态值
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 28-07-2012,  chengjun  written
 * v1.1  , 28-07-2013,  cml       written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_bmt_charging_result(char *bmt)
{
#if defined(__EXT_VBAT_ADC__)    

#if defined (__MCU_BJ8M601A_NT13V__)     
    kal_int32 external_voltage = track_drv_get_external_voltage_form_gsm();
#else
    kal_int32 external_voltage = track_drv_get_external_voltage_status();
#endif

    if(external_voltage < 0) 
    {
        external_voltage = 0;
    }
#endif  

    if(bmt == NULL)
    {
        return;
    }
    if(track_drv_bmt_get_charging_status())
    {
        charge_measure_struct charge_measure = {0};
        track_bmt_get_ADC_result(&charge_measure);
        LOGD(L_DRV, L_V6, "{vBat:%f,iChr:%f,vChr:%f}", charge_measure.bmt_vBat, charge_measure.bmt_iChr ,  charge_measure.bmt_vChr);

#if !defined(__EXT_VBAT_ADC__)
        snprintf(bmt, 90, "charge in %d, vBat=%4.2fV,iChr=%4.2fA,vChr=%4.2fV", track_drv_bmt_get_charging_status(), charge_measure.bmt_vBat, charge_measure.bmt_iChr, charge_measure.bmt_vChr);
#else
        {
            float external_batter;
            if(track_drv_bmt_get_charging_status())
            {
                if(external_voltage == 0)
                {
                    snprintf(bmt, 90, "charge in %d, vBat=%4.2fV, iChr=%4.2fA, vChr=%4.2fV, Vext=0V", track_drv_bmt_get_charging_status(),
                             charge_measure.bmt_vBat, charge_measure.bmt_iChr, charge_measure.bmt_vChr);
                }
                else if(external_voltage > 0)
                {
                    external_batter = (float)external_voltage / 1000000.0;
                    snprintf(bmt, 90, "charge in %d, vBat=%4.2fV, iChr=%4.2fA, vChr=%4.2fV,Vext=%0.2fV", track_drv_bmt_get_charging_status(),
                             charge_measure.bmt_vBat, charge_measure.bmt_iChr, charge_measure.bmt_vChr, external_batter);
                }
                else
                {
                    snprintf(bmt, 90, "charge in %d, vBat=%4.2fV, iChr=%4.2fA, vChr=%4.2fV", track_drv_bmt_get_charging_status(),
                             charge_measure.bmt_vBat, charge_measure.bmt_iChr, charge_measure.bmt_vChr);
                }
            }
        }
#endif /* __EXT_VBAT_ADC__ */
    }
#if defined(__EXT_VBAT_ADC__)
    else if(external_voltage > 0)
    {
        snprintf(bmt, 90, "no charge:vBat=%4.2fV,Vext=%0.2fV", (float)track_drv_get_batter_voltage() / 1000000.0, (float)external_voltage / 1000000.0);
    }
#endif
    else
    {
        snprintf(bmt, 90, "no charge:vBat=%4.2fV", (float)track_drv_get_batter_voltage() / 1000000.0);
    }
}


/******************************************************************************
 *  Function    -  track_drv_charge_batter_status_msg_send
 *
 *  Purpose     -  充电和电池状态消息拦截发送
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 23-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_charge_batter_status_msg_send(module_type src_mod_id, kal_uint8 battery_status, kal_uint8 battery_level, kal_uint32 volt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    charbat_status_struct *myMsgPtr = NULL;

    myMsgPtr = (charbat_status_struct*) construct_local_para(sizeof(charbat_status_struct), TD_CTRL);
    myMsgPtr->status = battery_status ;
    myMsgPtr->level = battery_level ;
    myMsgPtr->volt = volt;

    ilm_ptr = (ilm_struct *)allocate_ilm(src_mod_id);
    ilm_ptr->src_mod_id = src_mod_id;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = INVALID_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_CHARBAT_BMT_STATUS;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);
}


/******************************************************************************
 *  Function    -  track_drv_charge_batter_status
 *
 *  Purpose     -  充电和电池状态改变处理接口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 23-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_charge_batter_status(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    charbat_status_struct *localBuff_p = (charbat_status_struct*) msg;
    pmic_status_enum status;
    battery_level_enum level;
    kal_uint32 volt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    
    status = localBuff_p->status;
    level = localBuff_p->level;
    volt = localBuff_p->volt;
    
    //LOGD(L_DRV, L_V5, "==========================================================");
	LOGD(L_DRV, L_V9, "=====在这里打个日志==,status:%d,====,level:%d,===volt:%d=============",status,level,volt);
	//LOGD(L_DRV, L_V5, "==========================================================");

    if(status == PMIC_VBAT_STATUS)
    {
        drv_batter_voltage = volt;
    }
    else if(status == PMIC_CHARGER_IN)// || status == PMIC_USB_CHARGER_IN
    {
    	tr_stop_timer(TRACK_CUST_CHARGEIN_POWERON_OVERTIME_TIME_ID);
        bmt_charge_in = AC_CHR;
        track_bmt_vol_reset_setatus();
    }
    else if(status == PMIC_CHARGER_OUT)//  || status == PMIC_USB_CHARGER_OUT
    {
        bmt_charge_in = NO_CHR;
        track_bmt_vol_reset_setatus();
    }
    else if(status == PMIC_USB_CHARGER_IN)
    {
        bmt_charge_in = USB_CHR;
        track_bmt_vol_reset_setatus();
    }
    else if(status == PMIC_USB_CHARGER_OUT)
    {
        bmt_charge_in = NO_CHR;
        track_bmt_vol_reset_setatus();
    }
    else if(status == PMIC_USB_NO_CHARGER_IN)
    {
        bmt_charge_in = NON_STD_CHR;
        track_bmt_vol_reset_setatus();
    }
    else if(status == PMIC_USB_NO_CHARGER_OUT)
    {
        bmt_charge_in = NO_CHR;
        track_bmt_vol_reset_setatus();
    }
    track_drv_charger_bmt_status(status, level, volt);
}

kal_bool track_drv_charget_usb_status(void)
{
    return USB_CHR == bmt_charge_in;
}

/******************************************************************************
 *  Function    -  track_drv_get_batter_voltage
 *
 *  Purpose     -  读取电池电压
 *
 *  Description -  /1000000 (V)
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 14-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int32 track_drv_get_batter_voltage(void)
{
    return drv_batter_voltage;
}

/******************************************************************************
 *  Function    -  track_drv_sleep_enable
 *
 *  Purpose     -  禁止/允许休眠
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 28-07-2012,  chengjun  written
 * v1.1  , 20140106,  wangqi  add a test case
 * ----------------------------------------
 ******************************************************************************/
kal_int8 track_drv_sleep_enable(sleep_mod_enum mod , BOOL enable)
{
    static kal_uint8 track_l1_handler = 0xFF;   //(  0-31 )系统最多支持32  个句柄
    static kal_int8 pre_en = -1;
    kal_int8 flag;
    LOGD(L_DRV, L_V2, "mod:%d, %d", mod, enable);
    if(mod >= SLEEP_MOD_ALL)
    {
        if(track_l1_handler != 0xFF)
        {
            if(enable == 1)
            {
                L1SM_SleepEnable(track_l1_handler);       /*允许休眠*/
                LOGC(L_DRV, L_V5, "test sleep enable");
            }
            else
            {
                L1SM_SleepDisable(track_l1_handler);      /*禁止休眠*/
                LOGC(L_DRV, L_V5, "test sleep disable");
            }
        }
        return -1;
    }
    if(enable)
    {
        track_drv_sleep_status = track_drv_sleep_status | (1 << mod);
    }
    else
    {
        track_drv_sleep_status = track_drv_sleep_status & (~(1 << mod));
    }

    LOGD(L_DRV, L_V5, "mod=%d,enable=%d,sleep_status=%02X", mod, enable, track_drv_sleep_status);

    if(track_drv_sleep_status == 0xFF)
    {
        flag = 1;
        if(pre_en == 1)
        {
            return -2;  //  已经允许休眠
        }
    }
    else
    {
        flag = 0;
        if(pre_en == 0)
        {
            return -3;  //  已经禁止休眠
        }
    }

    if(track_l1_handler == 0xFF)
    {
        track_l1_handler = L1SM_GetHandle();
    }

    if(flag == 1)
    {
        L1SM_SleepEnable(track_l1_handler);
        LOGC(L_DRV, L_V5, "sleep enable");
        if(G_realtime_data.netLogControl & 8)
        {
            cust_packet_log(8, 4, 0, 0, 0, 0, 0);
        }
    }
    else
    {
        L1SM_SleepDisable(track_l1_handler);
        LOGC(L_DRV, L_V5, "sleep disable");
        if(G_realtime_data.netLogControl & 8)
        {
            cust_packet_log(8, 5, 0, 0, 0, 0, 0);
        }
    }

    pre_en = flag;
    return flag;
}

/******************************************************************************
 *  Function    -  track_drv_check_sleep_status
 *
 *  Purpose     -  查询驱动休眠状态
 *
 *  Description -  8bite
 *                        bite 位为0表示该模块禁止休眠，有一位为0即表示没有休眠
 *                        return 0xFF 表示现在全部进入休眠
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 13-03-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_drv_check_sleep_status(void)
{
    return track_drv_sleep_status;
}

void track_drv_mcu_and_gsm_sleep(void * op)
{
    kal_uint32 level = (kal_uint32)op;

    LOGD(L_APP, L_V5, "MCU唤醒GSM两秒后FF休眠 %X", level);
    if(track_is_timer_run(TRACK_DRV_MCU_WAKEUP_GSM_TIMER_ID))
    {
        tr_stop_timer(TRACK_DRV_MCU_WAKEUP_GSM_TIMER_ID);
    }

    if(1 == level)//wakeup
    {
        track_drv_sleep_enable(SLEEP_EXT_UART_MOD, KAL_FALSE);
        track_start_timer(TRACK_DRV_MCU_WAKEUP_GSM_TIMER_ID, 2 * 1000, track_drv_mcu_and_gsm_sleep, (void*)0xff);
    }
    else if(0 != level)
    {
        track_drv_sleep_enable(SLEEP_EXT_UART_MOD, KAL_TRUE);
    }
}


#if defined (__EXT_VBAT_ADC__)

/******************************************************************************
 *  Function    -  track_add_adc_vbat_measure
 *
 *  Purpose     -  ADC4 测量外部供电电压
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 14-11-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static DCL_HANDLE track_add_adc_vbat_measure(U32 u4Period, U8 u1EvaluateCount)
{
    ADC_CTRL_CREATE_OBJECT_T  adc_create;
    ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;
    DCL_STATUS adc_status;

    ilm_struct *ilm_ptr;
    bmt_adc_add_item_req_struct *adc_item = NULL;

    if(adc_low_vbat_measure != DCL_HANDLE_INVALID)
    {
        return;
    }
    adc_low_vbat_measure = DclSADC_Open(DCL_ADC, FLAGS_NONE);

    //adc_ch.u2AdcName = DCL_TRACK_ADC_LOW_VBAT_CHANNEL;
    //adc_status = DclSADC_Control(adc_low_vbat_measure, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);

    adc_create.u4Period = u4Period * KAL_TICKS_100_MSEC;                // Measurement period (Uint is in Tick)
    adc_create.u4Sapid = NULL;                                              // Sap id
    adc_create.u1OwnerId = MOD_MMI;                                  // Indicate the module to for ADC driver to notify the result
    adc_create.u1AdcChannel = 4;//adc_ch.u1AdcPhyCh;               // To be measured physical ADC channel
    adc_create.u1EvaluateCount = u1EvaluateCount;     // Measurement count
    adc_create.fgSendPrimitive = KAL_TRUE;                            // Whether to send message to owner module or NOT

    adc_status = DclSADC_Control(adc_low_vbat_measure, ADC_CMD_CREATE_OBJECT, (DCL_CTRL_DATA_T *)&adc_create);

    /* send to the BMT task to register the callback message */
    adc_item = (bmt_adc_add_item_req_struct *)construct_local_para(sizeof(bmt_adc_add_item_req_struct), TD_CTRL);
    adc_item->adc_handle = adc_low_vbat_measure;
    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_BMT;
    ilm_ptr->msg_id = MSG_ID_BMT_ADC_ADD_ITEM_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct *)adc_item;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);
    LOGD(L_DRV, L_V6, "adc_low_vbat_measure:%d", adc_low_vbat_measure);
}

/******************************************************************************
 *  Function    -  track_drv_ext_vbat_measure_modify_parameters2
 *
 *  Purpose     -  修改ADC4 低电测量的间隔
 *
 *  Description -  ADC4 每 period *100毫秒测量一次，测量count 后向MMI 发送结果
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_ext_vbat_measure_modify_parameters2(U32 period, U8 count)
{
    ilm_struct *ilm_ptr;
    bmt_adc_modify_parameters_req_struct *adc_item = NULL;
    if(adc_low_vbat_measure == DCL_HANDLE_INVALID)
    {
        LOGD(L_DRV, L_V6, "ERROR : adc_low_vbat_measure == DCL_HANDLE_INVALID");
        return;
    }
    if(period == g_Period && count == g_EvaluateCount)
    {
        LOGD(L_DRV, L_V6, "ERROR :no change! period:%d, count:%d", period, count);
        return;
    }
    g_Period = period;
    g_EvaluateCount = count;
    LOGD(L_DRV, L_V6, "period:%d, count:%d", period, count);
    adc_item = (bmt_adc_modify_parameters_req_struct *)construct_local_para(sizeof(bmt_adc_modify_parameters_req_struct), TD_CTRL);
    adc_item->adc_handle = adc_low_vbat_measure;
    adc_item->period = KAL_TICKS_100_MSEC * period;
    adc_item->evaluate_count = count;

    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_BMT;
    ilm_ptr->msg_id = MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct *)adc_item;
    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}

/******************************************************************************
 *  Function    -  track_drv_ext_vbat_measure_modify_parameters
 *
 *  Purpose     -  外电电压检测间隔最好固定在下面这个函数统一更改
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 06-08-2016,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_ext_vbat_measure_modify_parameters()
{
    U32 tick = OTA_kal_get_systicks();
    kal_uint8 period;
    kal_uint8 count;

    /* 工厂测试模式下 */
    if(track_is_testmode())
    {
        track_drv_ext_vbat_measure_modify_parameters2(5, 4);
    }
    else if(g_ext_vbat_a_quick_detection == 1)
    {
        track_drv_ext_vbat_measure_modify_parameters2(1, 5);
    }
    else
    {
#if defined(__EXT_VBAT_Protection__)
        track_drv_ext_vbat_measure_modify_parameters2(10, 1);
#else
        track_drv_ext_vbat_measure_modify_parameters2(5, 4);
#endif /* __EXT_VBAT_Protection__ */
    }
}

void track_drv_ext_vbat_a_quick_detection(void)
{
    g_ext_vbat_a_quick_detection = 1;
    track_drv_ext_vbat_measure_modify_parameters();
}

/******************************************************************************
 *  Function    -  track_drv_ext_vbat_measure_req
 *
 *  Purpose     -  外部ADC 测量
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 14-11-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_ext_vbat_measure_req(U32 Period, U8 EvaluateCount)
{
    g_Period = Period;
    g_EvaluateCount = EvaluateCount;
    track_add_adc_vbat_measure(Period, EvaluateCount);
}

void track_drv_ext_vbat_check_acc(kal_int32 volt)
{
    static kal_int32 cnt = 0, last_tick = 0, last_volt = 0, tick = 0;
    static kal_int8  status = 0;
    kal_uint8 acc_log_buffer[25] = {0};
    extern nvram_realtime_struct G_realtime_data;

    if(G_realtime_data.netLogControl & 512)
    {
        if(tick == 0)
        {
            tick = kal_get_systicks();
        }
        else if(kal_get_systicks() - tick > 2000)
        {
            sprintf(acc_log_buffer, "ACC=%d,VOLT=%d", status, volt);
            cust_packet_log_data(8, (kal_uint8 *)acc_log_buffer, strlen((char *)acc_log_buffer));
            tick = kal_get_systicks();
        }
    }

    if(volt > G_parameter.vbat_check_acc.acc_h_thresholdvbat * 100000)
    {
        LOGD(L_DRV, L_V6, "ACC 1, cnt=%d, status=%d, volt=%d,%d", cnt, status, volt, G_parameter.vbat_check_acc.acc_h_thresholdvbat * 100000);
        if(cnt > 2 && status == 0)
        {
            if(track_is_timer_run(TRACK_CUST_ACC_INIT_OVERTIME_ID))
            {
                tr_stop_timer(TRACK_CUST_ACC_INIT_OVERTIME_ID);
            }
            status = 1;
            acc_status_change((void*)1);
            if(G_realtime_data.netLogControl & 64)
            {
                sprintf(acc_log_buffer, "ACC ON VOLT:%d", volt);
                cust_packet_log_data(8, (kal_uint8 *)acc_log_buffer, strlen((char *)acc_log_buffer));
            }
        }
        else if(cnt <= 2 && status == 0)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
    }
    else if(volt < G_parameter.vbat_check_acc.acc_l_threshold_vbat * 100000)
    {
        LOGD(L_DRV, L_V6, "ACC 0, cnt=%d, status=%d, volt=%d,%d", cnt, status, volt, G_parameter.vbat_check_acc.acc_l_threshold_vbat * 100000);
        if(cnt > 2 && status == 1)
        {
            if(track_is_timer_run(TRACK_CUST_ACC_INIT_OVERTIME_ID))
            {
                tr_stop_timer(TRACK_CUST_ACC_INIT_OVERTIME_ID);
            }

            status = 0;
            acc_status_change((void*)0);
            if(G_realtime_data.netLogControl & 64)
            {
                sprintf(acc_log_buffer, "ACC OFF VOLT:%d", volt);
                cust_packet_log_data(8, (kal_uint8 *)acc_log_buffer, strlen((char *)acc_log_buffer));
            }
        }
        else if(cnt <= 2 && status == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
    }
}

/******************************************************************************
 *  Function    -  track_drv_ext_vbat_measure_reslut
 *
 *  Purpose     -  外部ADC 检测结果
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 19-11-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_ext_vbat_measure_reslut(void *msg)
{
    static int count = 0;
    int volt;
    kal_uint32 volt2;
    bmt_adc_measure_done_conf_struct *result = (bmt_adc_measure_done_conf_struct *)msg;

    if(result->volt < 0)//用于在拔除外电情况下,检测到的偏差值计算
    {
        adc_external_batter = 0;
    }
    else
    {
        adc_external_batter = result->volt;
    }
    volt = track_drv_get_external_voltage_status();//此处应该加上ADC补偿值
    LOGD(L_DRV, L_V6, "ADC4=%d, volt:%d;result->volt=%d", adc_external_batter, volt, result->volt);
    volt2 = volt;

#if defined (__NT13V__)
    //if(volt2<20000000)//20v以下取单片机上报的结果
    //{
    //    LOGD(L_DRV, L_V5, "采用单片机结果");
    //}
    //else
    {
        track_cust_chargestatus_vbtstatus_check(PMIC_VBAT_STATUS, 99, volt2);
    }
#else
    track_cust_chargestatus_vbtstatus_check(PMIC_VBAT_STATUS, 99, volt2);
#endif /* __NT13V__ */

    track_drv_external_batter_measure_done(volt);
    if(count < 10)
    {
        count++;
        if(count == 10)
        {
            track_os_intoTaskMsgQueue(track_drv_ext_vbat_measure_modify_parameters);
        }
    }
    else if(g_ext_vbat_a_quick_detection == 1)
    {
        g_ext_vbat_a_quick_detection = 0;
        track_os_intoTaskMsgQueue(track_drv_ext_vbat_measure_modify_parameters);
    }
}

/******************************************************************************
 *  Function    -  track_drv_get_external_batter
 *
 *  Description - /1000000
 *
 *
 *  0 = 获取外电测量ADC原始值
 *
 *  1.充电时，电瓶电压<1.6V    表示外接电瓶低电
 *
 *  2. 充电断开时，电瓶电压1~1.6V 表示外接电瓶不足以充电
 *
 *  3. 充电断开时，电瓶电压<0.3V 表示外接电瓶断开
 *
 *
 * 1 = 获取外接电池电压
*    过小/ 过大不一定准确，可参考 track_drv_get_external_voltage_status
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 05-03-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int32 track_drv_get_external_batter(kal_uint8 flag)
{
    return (adc_external_batter * EXTERNAL_BATTER_EXPAND + EXTERNAL_OFFSET_VOLTAGE) + G_parameter.adc4_offset;
}

/******************************************************************************
 *  Function    -  track_drv_view_ext_batter
 *
 *  Purpose     -  外电接入电压显示
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_drv_view_ext_batter(void)
{
    char result[200] = {0};
    float external_batter;

#if defined (__MCU_BJ8M601A_NT13V__)     
    kal_int32 external_voltage = track_drv_get_external_voltage_form_gsm();
#else
    kal_int32 external_voltage = track_drv_get_external_voltage_status();
#endif

    if(bmt_charge_in)
    {
        track_drv_bmt_charging_result(result);
        if(external_voltage == -1)
        {
            snprintf(result + strlen(result), 99, ", Vext=%d(Out of range)", track_drv_get_external_batter(0));
        }
        else if(external_voltage > 0)
        {
            external_batter = (float)external_voltage / 1000000.0;
            snprintf(result + strlen(result), 99, ", Vext=%d(%0.2fV)", track_drv_get_external_batter(0), external_batter);
        }
    }
    else
    {
        if(external_voltage == -1)
        {
            snprintf(result + strlen(result), 99, "no charge, Vbat=%d, Vext=%d(Out of range)",
                     track_drv_get_batter_voltage(),
                     track_drv_get_external_batter(0));
        }
        else if(external_voltage > 0)
        {
            external_batter = (float)external_voltage / 1000000.0;
            sprintf(result, "no charge, Vbat=%d, Vext=%d(%0.2fV)",
                    track_drv_get_batter_voltage(),
                    track_drv_get_external_batter(0),
                    external_batter);
        }
        else
        {
            sprintf(result, "no charge, Vbat=%d, Vext=%d",
                    track_drv_get_batter_voltage(),
                    track_drv_get_external_batter(0));
        }
    }

    LOGS("%s", result);
}

#if defined (__MCU_BJ8M601A_NT13V__)
static kal_uint32 mcu_external_battery_voltage=0;
void track_drv_set_mcu_external_voltage(kal_uint32 volt)
{
    mcu_external_battery_voltage=volt;
}

kal_uint32 track_drv_get_external_voltage_from_mcu(void)
{
    return mcu_external_battery_voltage;
}

kal_int32 track_drv_get_external_voltage_form_gsm(void)
{
    return (adc_external_batter * EXTERNAL_BATTER_EXPAND + EXTERNAL_OFFSET_VOLTAGE) + G_parameter.adc4_offset;
}

#endif /* __MCU_BJ8M601A_NT13V__ */

/******************************************************************************
 *  Function    -  track_drv_get_external_voltage_status
 *
 *  Purpose     -  获取外电状态
 *
 *  Description -
 *              Vext=1617000(9.33V)
 * modification history
 * ----------------------------------------
 * v1.0  , 05-03-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int32 track_drv_get_external_voltage_status(void)
{
#if defined(__EXT_VBAT_ADC__)
#if defined(__GT240__)
    return volt_from_obd;
#endif /* __GT240__ */

#if defined (__MCU_BJ8M601A_NT13V__)
    //20V以下的以单片机为准，20V以上以GSM为准
    if(mcu_external_battery_voltage<20000000)
    {
        return mcu_external_battery_voltage;
    }
    else
    {
        return (adc_external_batter * EXTERNAL_BATTER_EXPAND + EXTERNAL_OFFSET_VOLTAGE) + G_parameter.adc4_offset;
    }
#else
    return (adc_external_batter * EXTERNAL_BATTER_EXPAND + EXTERNAL_OFFSET_VOLTAGE) + G_parameter.adc4_offset;
#endif /* __MCU_BJ8M601A_NT13V__ */

#if 0
    if(adc_external_batter < 300000)
    {
        return 0;
    }
    else if(adc_external_batter >= 2800000)   //外电可能过ADC量程(2.8v) 外部电压不能超15.9
    {
        return -1;
    }
    else
    {
        return (adc_external_batter * EXTERNAL_BATTER_EXPAND + EXTERNAL_OFFSET_VOLTAGE) + G_parameter.adc4_offset;
    }
#endif

#else
    return 0;
#endif /* __EXT_VBAT_ADC__ */
}

kal_bool track_drv_ext_disconnect(void)
{
    if(adc_external_batter * EXTERNAL_BATTER_EXPAND < 6000000)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

/******************************************************************************
 *  Function    -  track_drv_get_external_voltage_change
 *
 *  Purpose     -  获取外电电压值(整型)
 *
 *  Description -
 * modification history
 * ----------------------------------------
 * v1.0  , 05-16-2015,  chengjiajun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint16 track_drv_get_external_voltage_change(void)
{
    double volt;    
    kal_int32 voltage = track_drv_get_external_voltage_status();
    volt = (DOUBLE)voltage / 10000.00;
    //LOGS("volt:%4.2f",volt);
    voltage = (int)volt;
    //     LOGS("voltage:%d",voltage);

    return voltage;
}

/******************************************************************************
 *  Function    -  track_drv_external_cut_status
 *
 *  Purpose     - 目前MT200飞行模式主动断开IC电源口(此为软件层面的断开)，
 *          此时还能检测到外电值的，此时拔掉外电，要能检测到并触发断电报警。
 *          此函数用于判断，外电是否在物理层面上断开了
 *          目前仅供MT200使用    
 *  Description -
 *              true 断开了
 *              false 没断
 * modification history
 * ----------------------------------------
 * v1.0  , 03-13-2017,  chengjiajun  written
 * ----------------------------------------
 ******************************************************************************/
 kal_bool track_drv_external_cut_status(void)
{
    if(adc_external_batter < 15000)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}
 
#else
kal_int32 track_drv_get_external_voltage_status(void)
{
    return 0;
}
#endif /* __EXT_VBAT_ADC__ */
void track_drv_set_volt_from_obd(U32 v)
{
    volt_from_obd = v;
}
/******************************************************************************
 *  Function    -  track_drv_eadc_data_decode
 *
 *  Purpose     -  解析EADC结果，辅助判断外电补救断电报警异常问题
 *
 *  Description -   vChr<2v 为断外电
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-07-24,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_eadc_data_decode(kal_uint8* data, kal_uint16 len)
{
    char temp[128] = {0};
    char  *adc[5];
    kal_int16 part;
    char *p = NULL;
    double vBat, iChr, vChr;
    static kal_uint8 cnt = 0, max;
    if(track_cust_status_charger() == 1)
    {
        cnt = 0;
        track_at_vs_send("AT+EADC=0\r\n");
        return;
    }

    if(G_parameter.power_fails_alarm.delay_time_off > 10)
    {
        max = 10;
    }
    else
    {
        cnt = 0;
        track_at_vs_send("AT+EADC=0\r\n");
        return;
    }
    if(cnt < max)
    {
        cnt++;
    }
    else
    {
        cnt = 0;
        track_at_vs_send("AT+EADC=0\r\n");
        return;
    }
    if(G_realtime_data.netLogControl & 8)
        cust_packet_log_data(8, data, len);
    if(len >= 128)
    {
        return;
    }

    p = strstr(data, "+EADC: "); //注意最后有个空格
    if(p == NULL)
    {
        return;
    }

    strncpy(temp, p + strlen("+EADC: "), sizeof(temp) - 1);

    part = track_fun_str_analyse(temp, adc, 5, NULL, "\r\n", ',');

    if(part != 5)
    {
        LOGD(L_DRV, L_V5, "EADC part!=5");
        return;
    }

    vBat = atof(adc[0]);
    iChr = atof(adc[3]);
    vChr = atof(adc[4]);

    if(vChr > 1 && cnt > 5)
    {
        if(track_cust_status_charger() == 0)
        {
            LOGD(L_DRV, L_V4, "不做断电报警");
            track_stop_timer(TRACK_CUST_MODULE_ALARM_POWER_FAILS_TIMER_ID);
        }
    }

    LOGD(L_DRV, L_V4, "cnt=%d,vBat=%f,iChr=%f,vChr=%f", cnt, vBat, iChr, vChr);

}

#if defined (__NF2319__)||defined (__NF2318__)
void track_drv_enable_vsim2_power_domain(void)
{
    DCL_HANDLE lcd_reset_hnd;
    PMU_CTRL_LDO_BUCK_SET_EN ldoSetEn;
    PMU_CTRL_LDO_BUCK_SET_VSIM2_GPLDO_EN ldo_vsim_gpldo_en;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
    DCL_HANDLE handle;
    
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    val.voltage = PMU_VOLT_01_800000_V;
    val.mod = VSIM2;
    DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);

    ldo_vsim_gpldo_en.enable = DCL_TRUE;
    ldo_vsim_gpldo_en.mod = VSIM2;
    DclPMU_Control(handle, LDO_BUCK_SET_VSIM2_GPLDO_EN, (DCL_CTRL_DATA_T *)&ldo_vsim_gpldo_en);

    ldoSetEn.mod = VSIM2;
    ldoSetEn.enable = DCL_TRUE;
    DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&ldoSetEn);

    DclPMU_Close(handle);
}

#endif
void track_cust_is_chargein_poweron(void* arg)
{
	U8 par = (U8)arg;
	U32 PowerOn_Type = mmi_Get_PowerOn_Type();
	//poweron_type 得不到 ，那么用电量值
    kal_int32 external_voltage = track_drv_get_external_voltage_status();
	kal_int32 external_batter = 0;
    LOGD(L_DRV, L_V4, "par=%d,%d,%d", par,PowerOn_Type,external_voltage);
	
	if(par == 0)
	{
		//if(external_voltage >= 5000000)
		//{
		//	external_batter = external_voltage / 1000000;
		//}
		LOGD(L_DRV, L_V4, "external_batter=%d,%d,%d",external_batter,bmt_charge_in,PowerOn_Type);
		if(external_voltage > 5000000 && bmt_charge_in != AC_CHR && bmt_charge_in != USB_CHR)//(external_batter > 10 && bmt_charge_in != AC_CHR && bmt_charge_in != USB_CHR)
		{
			bmt_charge_in = AC_CHR;
        	track_bmt_vol_reset_setatus();
			track_drv_charger_bmt_status(1, 5, external_voltage);//随便传一个电压值
		}
	}
}

