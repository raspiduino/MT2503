/******************************************************************************
 * track_drv_key.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        modem 工程自定义键盘处理
 *
 * modification history
 * --------------------
 * v1.0   2012-12-29,  chengjun create this file
 *
 ******************************************************************************/

#if defined (__KEYPAD_MOD__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_drv_key.h"
#include "track_OS_ELL.h"

/*****************************************************************************
 *  Define					宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
*****************************************************************************/
static keypad_handle_struct keypad_buff = {0};

/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static keypad_code_map_struct keypad_code_map[KEYPAD_CUSTOM_MAP_MAX] =
{
    {DEVICE_KEY_SOS ,   KEY_SOS,  0},
    {DEVICE_KEY_TR1 ,   KEY_TR1,  0},
    {DEVICE_KEY_TR2 ,   KEY_TR2,  0},
    {DEVICE_KEY_FUN ,   KEY_FUN,  0}, 
    {DEVICE_KEY_POWER , KEY_POWER,0}, 
};
//自定义增加按键，需在此扩展

static FuncPtr Keypad_FuncPtrs[MAX_QWERTY_KEYS][MAX_KEY_TYPE]={0};

/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
*****************************************************************************/
/******************************************************************************
 *  Function    -  track_get_mmi_key_code
 * 
 *  Purpose     -  转换出mmi 层的keycode
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 29-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_uint8 track_get_mmi_key_code(kal_uint8 drv_key, kal_uint8 * index)
{
    kal_uint8 i;
    for(i=0;i<KEYPAD_CUSTOM_MAP_MAX;i++)
    {
        /*只有keypad_code_map 定义的才允许执行       --    chengjun  2013-01-24*/
        if (drv_key == keypad_code_map[i].device_key_code)
        {
            * index = i;
            return keypad_code_map[i].mmi_key_code;
        }
    }
    * index = 0xFF;
    return 0xFF;
    //DEVICE_KEY_POWER 被屏蔽不处理，return 0xFF 
}


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
/******************************************************************************
 *  Function    -  track_drv_push_key_to_buff
 *
 *  Purpose     -  保存按键事件
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_push_key_to_buff(kbd_event event, kal_uint8 key)
{
    keypad_buff.keyCode = key;
    keypad_buff.keyType = event;
}

/******************************************************************************
 *  Function    -  track_drv_send_keypad_event
 *
 *  Purpose     -  发送按键事件，通知MMI
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_send_keypad_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    keypad_msg_struct *keypad_msg = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    keypad_msg = (keypad_msg_struct*) construct_local_para(sizeof(keypad_msg_struct), TD_CTRL);

    keypad_msg->key.keyCode = keypad_buff.keyCode;
    keypad_msg->key.keyType = keypad_buff.keyType;

    LOGD(L_DRV, L_V6, "key msg (%d,%d)",keypad_buff.keyCode,keypad_buff.keyType);

    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_DRVKBD);
    ilm_ptr->src_mod_id = MOD_DRVKBD;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = DRIVER_PS_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_KEYPAD_EVENT;
    ilm_ptr->local_para_ptr = (local_para_struct*) keypad_msg;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);
}

/******************************************************************************
 *  Function    -  track_drv_keypad_event_handle
 *
 *  Purpose     -  按键事件响应
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-12-2012,  chengjun  written
 * v1.1  , 9-8-2013,  wangqi  
 * ----------------------------------------
 ******************************************************************************/
void track_drv_keypad_event_handle(void *msg)
{
    keypad_msg_struct* key_info = (keypad_msg_struct*)msg;
    kal_uint8 keyCode, keyType, keyIndex = 0xFF;
    
    keyType =key_info->key.keyType;
    keyCode = track_get_mmi_key_code(key_info->key.keyCode , &keyIndex);
    LOGD(L_DRV, L_V4, "key %d,%d", keyCode, keyType);

    if(kbd_onekey_longpress == keyType && keyIndex < KEYPAD_CUSTOM_MAP_MAX)
    {
        if(keypad_code_map[keyIndex].longpress)
        {
            LOGD(L_DRV, L_V6, "重复按键key handle (%d,%d)", keyCode, keyType);
            return;
        }
        keypad_code_map[keyIndex].longpress = KAL_TRUE;
    }
    if(kbd_onekey_release == keyType && keyIndex < KEYPAD_CUSTOM_MAP_MAX)
    {
        if( keypad_code_map[keyIndex].longpress)
        {
            keypad_code_map[keyIndex].longpress = KAL_FALSE;
        }
        else
        {
            if((keyCode != 0xFF) && (keyType < MAX_KEY_TYPE))
            {
                LOGD(L_DRV, L_V5, "key handle (%d,%d)", keyCode, KEY_SHORT_PRESS);
                if(Keypad_FuncPtrs[keyCode][KEY_SHORT_PRESS] != NULL)
                {
                    Keypad_FuncPtrs[keyCode][KEY_SHORT_PRESS]();
                }
                else
                {
                    LOGD(L_DRV, L_V6, "key handle FuncPtrs is NULL!");
                }
            }
        }
    }
    //152 主动拉低powerkey 开机的事件过滤
    
    if( (keyCode!=0xFF)&&(keyType<MAX_KEY_TYPE) )
    {
         LOGD(L_DRV, L_V5, "2key handle (%d,%d)", keyCode, keyType);
        if(Keypad_FuncPtrs[keyCode][keyType]!=NULL)
        {
            Keypad_FuncPtrs[keyCode][keyType]();
        }
        else
        {
            LOGD(L_DRV, L_V6, "2key handle FuncPtrs is NULL! (%d,%d)", keyCode, keyType);
        }
    }
}

/******************************************************************************
 *  Function    -  track_drv_set_key_handler
 * 
 *  Purpose     -  按键注册接口
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 29-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_set_key_handler(FuncPtr funcPtr,U16 keyCode,U16 keyType)
{
    Keypad_FuncPtrs[keyCode][keyType]=funcPtr;
}

#endif /* __KEYPAD_MOD__ */

