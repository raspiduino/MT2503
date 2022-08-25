/******************************************************************************
 * track_lbs_data.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        获取基站信息
 *
 * modification history
 * --------------------
 * v1.0   2012-07-27,  chengjun create this file
 *
 ******************************************************************************/

#if defined (__LBS_DATA__)

/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_drv_lbs_data.h"
#include "track_os_timer.h"
#include "stack_ltlcom.h"
#include "nbr_public_struct.h"
#include "track_os_ell.h"

/*****************************************************************************
* Typedef  Enum                         枚举定义
*****************************************************************************/

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define  CUST_NBR_CELL_INFO
//开启后是拦截L4C信息，关闭后按先前的模式，向L4C发消息请求数据

/*****************************************************************************
* Local variable                        局部变量
*****************************************************************************/
static LBS_Multi_Cell_Data_Struct      Current_Multi_Cell_Info; //多基站数据
static LBS_Multi_Cell_Data_Struct      Last_Multi_Cell_Info; //缓存多基站数据

/****************************************************************************
* Global Variable                       全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions    - Extern        引用外部函数
 *****************************************************************************/

/*****************************************************************************
 *  Local Functions                     本地函数
 *****************************************************************************/

static void track_send_cell_infor_req(kal_bool flag)
{
    ilm_struct *ilm_ptr;
    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->sap_id = MMI_L4C_SAP;

    if(flag)
    {
        ilm_ptr->msg_id = MSG_ID_L4C_NBR_CELL_INFO_REG_REQ;//start
    }
    else
    {
        ilm_ptr->msg_id = MSG_ID_L4C_NBR_CELL_INFO_DEREG_REQ;//stop
    }

    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);
}

/******************************************************************************
 *  Function    -  tarck_lbs_celll_info_start
 *
 *  Purpose     -  请求获取邻近小区
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void tarck_lbs_celll_info_start()
{
    track_send_cell_infor_req(KAL_TRUE);
}

/******************************************************************************
 *  Function    -  tarck_lbs_celll_info_stop
 *
 *  Purpose     -  暂停小区信息上报
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void tarck_lbs_celll_info_stop()
{
    Last_Multi_Cell_Info.status = FALSE;
    track_send_cell_infor_req(KAL_FALSE);
}


/******************************************************************************
 *  Function    -  tracki_multi_cell_info_buff
 *
 *  Purpose     -  保存基站信息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void tracki_multi_cell_info_buff(void)
{
    memset(&Last_Multi_Cell_Info, 0,  sizeof(LBS_Multi_Cell_Data_Struct));
    memcpy(&Last_Multi_Cell_Info, &Current_Multi_Cell_Info, sizeof(LBS_Multi_Cell_Data_Struct));
}


#if defined (__LBS_DATA_DEBUG__)

/******************************************************************************
 *  Function    -  track_print_lbs_data_debug
 *
 *  Purpose     -  多基站信息输出
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-02-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_print_lbs_data_debug(LBS_Multi_Cell_Data_Struct Cell_Info)
{
    char str[200];

    memset(str, 0, sizeof(str));
    snprintf(str, 199, "MCC=%d,MNC=%02d,TA=%d,LAC=%d;Main[%2d,%d];Near {[%2d,%d] [%2d,%d] [%2d,%d] [%2d,%d] [%2d,%d] [%2d,%d]}#",
             Cell_Info.MainCell_Info.mcc, Cell_Info.MainCell_Info.mnc,
             Cell_Info.ta,Cell_Info.MainCell_Info.lac,
             Cell_Info.MainCell_Info.cell_id, Cell_Info.MainCell_Info.rxlev,
             Cell_Info.NbrCell_Info[0].cell_id, Cell_Info.NbrCell_Info[0].rxlev,
             Cell_Info.NbrCell_Info[1].cell_id, Cell_Info.NbrCell_Info[1].rxlev,
             Cell_Info.NbrCell_Info[2].cell_id, Cell_Info.NbrCell_Info[2].rxlev,
             Cell_Info.NbrCell_Info[3].cell_id, Cell_Info.NbrCell_Info[3].rxlev,
             Cell_Info.NbrCell_Info[4].cell_id, Cell_Info.NbrCell_Info[4].rxlev,
             Cell_Info.NbrCell_Info[5].cell_id, Cell_Info.NbrCell_Info[5].rxlev);

    LOGC(L_DRV, L_V7, "%s", str);
}

#endif /* __LBS_DATA_DEBUG__ */



/******************************************************************************
 *  Function    -  track_drv_multi_cell_info_decode
 *
 *  Purpose     -  多基站信息解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_multi_cell_info_decode(void *info)
{
    int valid_cell;
    int i;

    l4c_nbr_cell_info_ind_struct *nbr_cell_info = (l4c_nbr_cell_info_ind_struct *)info;

    if(nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_cell_num > 6)
    {
        valid_cell = 6;
    }
    else
    {
        valid_cell = nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_cell_num;
    }

    if(nbr_cell_info->is_nbr_info_valid)
    {

        if(nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.ci != 0) //主小区ID 为0  过滤
        {
            memset((void *)&Current_Multi_Cell_Info, 0, sizeof(LBS_Multi_Cell_Data_Struct));

            Current_Multi_Cell_Info.MainCell_Info.mcc = nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.mcc;
            Current_Multi_Cell_Info.MainCell_Info.mnc = nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.mnc;
            Current_Multi_Cell_Info.MainCell_Info.lac = nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.lac;
            Current_Multi_Cell_Info.MainCell_Info.cell_id = nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.gci.ci;
            Current_Multi_Cell_Info.MainCell_Info.rxlev =
                nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_meas_rslt.nbr_cells[nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.serv_info.nbr_meas_rslt_index].rxlev;

            for(i = 0; i < valid_cell; i++)
            {
                Current_Multi_Cell_Info.NbrCell_Info[i].mcc =
                    nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_cell_info[i].gci.mcc;
                Current_Multi_Cell_Info.NbrCell_Info[i].mnc =
                    nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_cell_info[i].gci.mnc;
                Current_Multi_Cell_Info.NbrCell_Info[i].lac =
                    nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_cell_info[i].gci.lac;
                Current_Multi_Cell_Info.NbrCell_Info[i].cell_id =
                    nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_cell_info[i].gci.ci;
                Current_Multi_Cell_Info.NbrCell_Info[i].rxlev =
                    nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_meas_rslt.nbr_cells[nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.nbr_cell_info[i].nbr_meas_rslt_index].rxlev;
            }

            Current_Multi_Cell_Info.ta = nbr_cell_info->ps_nbr_cell_info_union.gas_nbr_cell_info.ta;
            Current_Multi_Cell_Info.valid_cel_num = valid_cell;

            Current_Multi_Cell_Info.status = TRUE;
            tracki_multi_cell_info_buff();
        }
    }

#if  defined __LBS_DATA_DEBUG__
    track_print_lbs_data_debug(Current_Multi_Cell_Info);
#endif /* __LBS_DATA_DEBUG__ */

}


/******************************************************************************
 *  Function    -  track_drv_get_lbs_data
 *
 *  Purpose     -  外部获取多基站信息的接口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
LBS_Multi_Cell_Data_Struct * track_drv_get_lbs_data(void)
{
    return &Last_Multi_Cell_Info;
}

/******************************************************************************
 *  Function    -  track_drv_convert_rxlev_to_rssi
 *
 *  Purpose     -  基站信号等级逆转换为信号强度
 *
 *  Description - 信号强度为负数
 -------------------------------------------------------------------------------
        1、AT+CSQ 获取的等级(  不支持)
 -------------------------------------------------------------------------------
0 -             x <-111     8 -97≦ x <-95            16 -81≦ x <-79                  24 -65≦ x <-63
1 -111≦ x <-109      9 -95≦ x <-93            17 -79≦ x <-77                  25 -63≦ x <-61
2 -109≦ x <-107    10 -93≦ x <-91             18 -77≦ x <-75                 26 -61≦ x <-59
3 -107≦ x <-105    11 -91≦ x <-89             19 -75≦ x <-73                 27 -59≦ x <-57
4 -105≦ x <-103    12 -89≦ x <-87             20 -73≦ x <-71                 28 -57≦ x <-55
5 -103≦ x <-101    13 -87≦ x <-85             21 -71≦ x <-69                 29 -55≦ x <-53
6 -101≦ x <-99      14 -85≦ x <-83             22 -69≦ x <-67                 30 -53≦ x <-51
7 -99≦ x <-97        15 -83≦ x <-81             23 -67≦ x <-65                 31 -51≦ x

*  rssi=(rxlev<<1)-112;
* rxlev=24 对应[-65,-63)  ,  取(-64)=2*24-112
 -------------------------------------------------------------------------------
        2、通过消息获取小区信息的等级
 -------------------------------------------------------------------------------
     if (meas_ptr->serv_cell_rla_struct.rla_value < (-110 * 4))
    {
        nbr_meas_info_ptr->nbr_cells[index].rxlev = 0;
    }
    else if (meas_ptr->serv_cell_rla_struct.rla_value > (-48 * 4))
    {
        nbr_meas_info_ptr->nbr_cells[index].rxlev = 63;
    }
    else
    {
        nbr_meas_info_ptr->nbr_cells[index].rxlev =
            meas_ptr->serv_cell_rla_struct.rla_value/4 + 110;
    }

    rxlev 是获取到的数值, rla_value/4 是信号强度
------------------------------------------------------------------------------------
------------------------------------------------------------------------------------
 * modification history
 * ----------------------------------------
 * v1.0  , 08-03-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int16 track_drv_convert_rxlev_to_rssi(kal_int16 rxlev)
{
    kal_int16 rssi;

    if(rxlev <= 0)
    {
        rssi = -110;
    }
    else if(rxlev >= 63)
    {
        rssi = -48;
    }
    else
    {
        rssi = rxlev - 110;
    }

    return rssi;
}

/******************************************************************************
 *  Function    -  track_drv_get_service_cell_level
 *
 *  Purpose     -  获取服务小区信号等级
 *
 *  Description -  GSM 信号强度
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_drv_get_service_cell_level(void)
{
    if(Last_Multi_Cell_Info.status)
    {
        return Last_Multi_Cell_Info.MainCell_Info.rxlev;
    }
    else
    {
        return 0xFF;
    }
}


/******************************************************************************
 *  Function    -  track_drv_lbs_info_switch
 *
 *  Purpose     -  获取基站信息开关
 *
 *  Description - 不插卡也可以获取正确信息
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_int8 track_drv_lbs_info_switch(U8 status)
{
    static U8 pre_status = 0xFF;

    if(status == pre_status)
    {
        return -1;//已经执行了
    }
    else if(status == 1)
    {
        tarck_lbs_celll_info_start();
        pre_status = status;
        return 1;
    }
    else if(status == 0)
    {
        tarck_lbs_celll_info_stop();
        pre_status = status;
        return 0;
    }
    else
    {
        return -2;
    }
}

/******************************************************************************
 *  Function    -  track_drv_get_network_info
 *
 *  Purpose     -  开始获取基站信息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_get_network_info(void)
{
#if defined (CUST_NBR_CELL_INFO)
    //nc
    /*拦截系统固定输出,不需要发送请求，但也不能停止  -- chengjun  2013-05-07*/
#else
    track_drv_lbs_info_switch(1);
#endif /* CUST_NBR_CELL_INFO */
    
}

void track_drv_set_lte_lbs_data(LBS_Multi_Cell_Data_Struct lbs)
{
    memset(&Last_Multi_Cell_Info, 0,  sizeof(LBS_Multi_Cell_Data_Struct));
    memset(&Current_Multi_Cell_Info, 0,  sizeof(LBS_Multi_Cell_Data_Struct));
    memcpy(&Current_Multi_Cell_Info, &lbs, sizeof(LBS_Multi_Cell_Data_Struct));
    memcpy(&Last_Multi_Cell_Info, &Current_Multi_Cell_Info, sizeof(LBS_Multi_Cell_Data_Struct));
}
#endif /* __LBS_DATA__ */
