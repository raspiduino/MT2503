#if defined(__BT_GATTC_PROFILE__) || defined(__BT_GATTS_PROFILE__) 
#include "bcm_GattSrv.h"
/****************************************************************************
* function define
****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  gatt_send_msg
 * DESCRIPTION
 *  send message between two modules
 * PARAMETERS
 *  src_id              [IN]        
 *  dst_id              [IN]        
 *  sap_id              [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void gatt_send_msg(module_type src_id,
                   module_type dst_id,
                   U16 sap_id,
                   U16 msg_id,
                   void *local_param_ptr)
{
    ilm_struct *ilm_ptr = allocate_ilm(src_id);

    ilm_ptr->src_mod_id = src_id;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = (sap_type)sap_id;
    ilm_ptr->msg_id = (msg_type)msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*)local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*)NULL;

    msg_send_ext_queue(ilm_ptr);
}
U16 convert_array_to_uuid16(ATT_UUID uu)
{
	U16 uuid = 0;
	
	if(uu.uuid.len == 2)
	{
		uuid = ((U16)uu.uuid.uuid[1]) << 8 | uu.uuid.uuid[0];
	}
	else if(uu.uuid.len == 16)
	{
		uuid = ((U16)uu.uuid.uuid[13]) << 8 | uu.uuid.uuid[12];
	}
	return uuid;
}

void convert_uuid16_to_array(U16 uuid16, ATT_UUID *uu)
{
	uu->uuid.len = 2;
	uu->uuid.uuid[1] = (U8)((uuid16&0xFF00)>>8);
	uu->uuid.uuid[0] = (U8)(uuid16&0x00FF);
}

/*****************************************************************************
 * FUNCTION
 *  _InsertTailList
 * DESCRIPTION
 *  Insert an entry at the tail of the list specified by head.
 * PARAMETERS
 *  head        [OUT]
 *  entry       [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void _mmi_InsertTailList(ListEntry *head, ListEntry *entry)
{
    entry->Flink = head;
    entry->Blink = head->Blink;
    head->Blink->Flink = entry;
    head->Blink = entry;
    Assert(mmi_IsNodeConnected(entry));

}


/*****************************************************************************
 * FUNCTION
 *  InsertTailList
 * DESCRIPTION
 *
 * PARAMETERS
 *  head        [OUT]
 *  entry       [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_InsertTailList(ListEntry *head, ListEntry *entry)
{
    Assert(mmi_IsListCircular(head));
    _mmi_InsertTailList(head, entry);
    Assert(mmi_IsListCircular(head));
}


/*****************************************************************************
 * FUNCTION
 *  _InsertHeadList
 * DESCRIPTION
 *  Insert an entry at the head of the list specified by head.
 * PARAMETERS
 *  head        [OUT]
 *  entry       [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void _mmi_InsertHeadList(ListEntry *head, ListEntry *entry)
{
    entry->Flink = head->Flink;
    entry->Blink = head;
    head->Flink->Blink = entry;
    head->Flink = entry;
    Assert(mmi_IsNodeConnected(entry));

}


/*****************************************************************************
 * FUNCTION
 *  _RemoveHeadList
 * DESCRIPTION
 *  Remove the first entry on the list specified by head.
 * PARAMETERS
 *  head        [OUT]
 * RETURNS
 *
 *****************************************************************************/
ListEntry *_mmi_RemoveHeadList(ListEntry *head)
{
    ListEntry *first;

    first = head->Flink;
    first->Flink->Blink = head;
    head->Flink = first->Flink;
    Assert(mmi_IsListCircular(head));
    return (first);

}


/*****************************************************************************
 * FUNCTION
 *  RemoveHeadList
 * DESCRIPTION
 *
 * PARAMETERS
 *  head        [OUT]
 * RETURNS
 *
 *****************************************************************************/
ListEntry *mmi_RemoveHeadList(ListEntry *head)
{
    Assert(mmi_IsListCircular(head));
    return (_mmi_RemoveHeadList(head));
}


/*****************************************************************************
 * FUNCTION
 *  RemoveEntryList
 * DESCRIPTION
 *  Remove the given entry from the list.
 * PARAMETERS
 *  entry       [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_RemoveEntryList(ListEntry *entry)
{
    Assert(mmi_IsListCircular(entry));
    entry->Blink->Flink = entry->Flink;
    entry->Flink->Blink = entry->Blink;
    Assert(mmi_IsListCircular(entry->Blink));
    mmi_InitializeListEntry(entry);

}


/*****************************************************************************
 * FUNCTION
 *  IsNodeOnList
 * DESCRIPTION
 *  Determine if an entry is on the list specified by head.
 * PARAMETERS
 *  head        [OUT]
 *  node        [OUT]
 * RETURNS
 *  TRUE - the entry is on the list.
 *  FALSE - the entry is not on the list.
 *****************************************************************************/
BOOL mmi_IsNodeOnList(ListEntry *head, ListEntry *node)
{
    ListEntry *tmpNode;

    Assert(mmi_IsListCircular(head));
    tmpNode = mmi_GetHeadList(head);

    while (tmpNode != head)
    {
        if (tmpNode == node)
        {
            return (TRUE);
        }

        tmpNode = tmpNode->Flink;
    }
    return (FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  MoveList
 * DESCRIPTION
 *  Moves a list to a new list head.  The source list is left empty.
 * PARAMETERS
 *  dest        [OUT]
 *  src         [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_MoveList(ListEntry *dest, ListEntry *src)
{
    Assert(mmi_IsListCircular(src));
    if (mmi_IsListEmpty(src))
    {
        mmi_InitializeListHead(dest);
    }
    else
    {
        dest->Flink = src->Flink;
        dest->Blink = src->Blink;
        src->Flink->Blink = dest;
        src->Blink->Flink = dest;
        mmi_InitializeListHead(src);
    }
}

/*****************************************************************************
 * FUNCTION
 *  InsertList
 * DESCRIPTION
 *  Insert a list to another list.  The source list is left empty.
 * PARAMETERS
 *  dest        [OUT]
 *  src         [OUT]
 *  front       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_InsertList(ListEntry *dest, ListEntry *src, U8 front)
{
    Assert(mmi_IsListCircular(src));
    Assert(mmi_IsListCircular(dest));
    if (!mmi_IsListEmpty(src))
    {

    }
    else
    {
        if (front)
        {
            dest->Flink->Blink = src->Blink;
            src->Blink->Flink = dest->Flink;
            dest->Flink = src->Flink;
            src->Flink->Blink = dest;
        }
        else
        {

            dest->Blink->Flink = src->Flink;
            src->Flink->Blink = dest->Blink;
            dest->Blink = src->Blink;
            src->Blink->Flink = dest;
        }
        mmi_InitializeListHead(src);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsListCircular
 * DESCRIPTION
 *  Determine if the list is circular. This is only used for
 *  debugging purposes.
 * PARAMETERS
 *  list        [IN]
 * RETURNS
 *  TRUE - the list is circular
 *  FALSE - the list is not circular.
 *****************************************************************************/
BOOL mmi_IsListCircular(ListEntry *list)
{

    ListEntry *tmp = list;

    if (!mmi_IsNodeConnected(list))
    {
        return (FALSE);
    }

    for (tmp = tmp->Flink; tmp != list; tmp = tmp->Flink)
    {
        if (!mmi_IsNodeConnected(tmp))
        {
            return (FALSE);
        }
    }
    return (TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  InitializeListHead
 * DESCRIPTION
 *
 * PARAMETERS
 *  list        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_InitializeListHead(ListEntry *list)
{
    list->Flink = list;
    list->Blink = list;
}


/*****************************************************************************
 * FUNCTION
 *  InitializeListEntry
 * DESCRIPTION
 *
 * PARAMETERS
 *  list        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_InitializeListEntry(ListEntry *list)
{
    list->Flink = 0;
    list->Blink = 0;
}


/*****************************************************************************
 * FUNCTION
 *  IsListEmpty
 * DESCRIPTION
 *
 * PARAMETERS
 *  list        [IN]
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_IsListEmpty(ListEntry *list)
{
    return ((list)->Flink == (list));
}

#ifdef MMI_SRV_CONN_STATE_IND
#include "BLESrvGprot.h"
//#include "MMI_conn_app_trc.h"
//#include "MMI_trc_Int.h"
#include"bcmadp.h"
#include "bcm_trc.h"
gatt_conn_state_ind_struct g_GattConnStateInd[MAX_LE_DEV_NUM];
#define SRV_GATT_TRACE_GROUP    MMI_CONN_TRC_G7_BT

static BOOL gatt_conn_state_get_device(BD_ADDR *dev_addr, U8 flag, U8 *u1DevNum)
{
    BOOL fgResult = TRUE;
    U8 iDevice = 0;
    U8 init_addr[BD_ADDR_SIZE];

    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_GET_DEV_FLAG, flag);
    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_DEV_ADDR, dev_addr->addr[0], dev_addr->addr[1], 
        dev_addr->addr[2], dev_addr->addr[3], dev_addr->addr[4], dev_addr->addr[5]);
    for (iDevice = 0; iDevice < MAX_LE_DEV_NUM; iDevice ++)
    {
        MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_DEV_ADDR, g_GattConnStateInd[iDevice].dev_addr.addr[0], g_GattConnStateInd[iDevice].dev_addr.addr[1], 
            g_GattConnStateInd[iDevice].dev_addr.addr[2], g_GattConnStateInd[iDevice].dev_addr.addr[3],
            g_GattConnStateInd[iDevice].dev_addr.addr[4], g_GattConnStateInd[iDevice].dev_addr.addr[5]);
        MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_GET_DEV_IND_FLAG, g_GattConnStateInd[iDevice].is_ind_cm_conn, g_GattConnStateInd[iDevice].is_ind_cm_disconn,
            g_GattConnStateInd[iDevice].is_update_name);
    }
    
    if (flag == GET_DEVICE_EXIST) 
    {
        /*
        * find a exist device
        */
        for (iDevice = 0; iDevice < MAX_LE_DEV_NUM; iDevice ++)
        {    
            if (!memcmp((U8 *)g_GattConnStateInd[iDevice].dev_addr.addr, (U8 *)dev_addr->addr, BD_ADDR_SIZE)) //compare address
            {
                MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_FIND_EXIST_DEV, iDevice);
                *u1DevNum = iDevice;
                break;
            }
        }
    }
    else if (flag == GET_DEVICE_VALID)
    {
        /*
        * find a valid device
        */
        for (iDevice = 0; iDevice < MAX_LE_DEV_NUM; iDevice ++)
        {
            memset(init_addr, 0, sizeof(init_addr));
            if (!memcmp((U8 *)g_GattConnStateInd[iDevice].dev_addr.addr, (U8 *)init_addr, BD_ADDR_SIZE)) //compare address
            {
                MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_FIND_VALID_DEV, iDevice);
                memset((U8 *)&g_GattConnStateInd[iDevice], 0, sizeof(gatt_conn_state_ind_struct)); //clear
                *u1DevNum = iDevice;
                break;
            }
            else
            {
                if (g_GattConnStateInd[iDevice].is_ind_cm_disconn == TRUE) //in disconnect state?
                {
                    memset((U8 *)&g_GattConnStateInd[iDevice], 0, sizeof(gatt_conn_state_ind_struct)); //clear
                    *u1DevNum = iDevice;
                    break;
                }
            }
        }
    }
    
    if (iDevice >= MAX_LE_DEV_NUM) //can't find the exist device
    {
        fgResult = FALSE;
    }
    
    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_GET_DEV_RESULT, fgResult, iDevice);
    
    return fgResult;
}

void gatt_conn_state_handle(gatt_conn_state msg)
{
    U8 u1DevNum = INVALID_DEVICE_NUM;
    BOOL fgResult = TRUE;
    BOOL is_ind_cm = FALSE;
    
    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_ENTER, msg.is_conn, msg.is_ind, msg.result, msg.LastInd);

    if (msg.is_conn) //connect
    {
        fgResult = gatt_conn_state_get_device(&msg.dev_addr, GET_DEVICE_EXIST, &u1DevNum);
        
        MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_CONN, fgResult, u1DevNum);

        if (!fgResult) //not find exist device
        {
            fgResult = gatt_conn_state_get_device(&msg.dev_addr, GET_DEVICE_VALID, &u1DevNum); //get a valid device
            
            MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_CONN, fgResult, u1DevNum);

            if (!fgResult) //not find valid pos?
            {
                return;
            }
        }

        if (u1DevNum < MAX_LE_DEV_NUM) //check valid scope
        {
            //clear disconnect related state
            g_GattConnStateInd[u1DevNum].is_ind_cm_disconn = FALSE; //clear disconnect ind state

            is_ind_cm = g_GattConnStateInd[u1DevNum].is_ind_cm_conn;
            if (!is_ind_cm) //save to list and indicate to CM
            {
                memcpy((U8 *)g_GattConnStateInd[u1DevNum].dev_addr.addr, (U8 *)msg.dev_addr.addr, BD_ADDR_SIZE);
                is_ind_cm = g_GattConnStateInd[u1DevNum].is_ind_cm_conn = TRUE;
            }
            else
            {
                MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_INDICATED);
                return;
            }
        }
        else //invalid
        {
            return;
        }
    }
    else //disconnect, not indicate to CM until all profiles are disconnected
    {
        if (!msg.LastInd) //not last disconnect ind
        {
            return;
        }
        
        fgResult = gatt_conn_state_get_device(&msg.dev_addr, GET_DEVICE_EXIST, &u1DevNum);
        
        MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_CONN, fgResult, u1DevNum);
        
        if (!fgResult) //not find exist device, indicate connect fail.
        {
            is_ind_cm = TRUE; //indicate always
            msg.is_ind = FALSE; //Initial
            msg.is_conn = TRUE; //Connect
            msg.result = FALSE; //Fail
        }
        else //find exist device
        {
            if (u1DevNum < MAX_LE_DEV_NUM) //check valid scope
            {
                //clear connect related state
                g_GattConnStateInd[u1DevNum].is_ind_cm_conn = FALSE; //clear connect ind state
                g_GattConnStateInd[u1DevNum].is_update_name = FALSE; //clear update name state

                is_ind_cm = g_GattConnStateInd[u1DevNum].is_ind_cm_disconn;
                if (!is_ind_cm) //save to list and indicate to CM
                {
                    is_ind_cm = g_GattConnStateInd[u1DevNum].is_ind_cm_disconn = TRUE;
                }
                else
                {
                    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_INDICATED);
                    return;
                }
            }
            else //invalid
            {
                return;
            }
        }
    }

    //indicate CM
    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_IND2CM, is_ind_cm);
    if (is_ind_cm)
    {      
        srv_le_cm_gatt_dev_info_struct cm_msg;
        srv_bt_cm_bt_addr dev_addr;

        memset(&cm_msg, 0, sizeof(srv_le_cm_gatt_dev_info_struct)); //init
 
        //device address
        dev_addr.lap = (msg.dev_addr.addr[2]<<16) | (msg.dev_addr.addr[1]<<8) | msg.dev_addr.addr[0];
        dev_addr.uap = msg.dev_addr.addr[3];
        dev_addr.nap = (msg.dev_addr.addr[5]<<8) | msg.dev_addr.addr[4];
        cm_msg.dev_addr = (srv_bt_cm_bt_addr *)&dev_addr;

        //copy device address to device name
        kal_sprintf(cm_msg.name, "%02x:%02x:%02x:%02x:%02x:%02x",
                    msg.dev_addr.addr[5], msg.dev_addr.addr[4],msg.dev_addr.addr[3],
                    msg.dev_addr.addr[2], msg.dev_addr.addr[1],msg.dev_addr.addr[0]);

        MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_CONN_STATE_NAME, cm_msg.name);
    
        //others
        cm_msg.is_ind = msg.is_ind;
        cm_msg.result = msg.result;
        cm_msg.is_conn = msg.is_conn;
        cm_msg.reason = msg.reason;

        srv_ble_cm_gatt_cnf(&cm_msg);
    }
}

void gatt_update_remote_device_name(U8 *dev_name, BD_ADDR *dev_addr)
{
    BOOL fgResult = TRUE;
    BOOL is_update_name = FALSE;
    U8 u1DevNum = INVALID_DEVICE_NUM;
    srv_bt_cm_bt_addr cm_dev_addr;

    if (!dev_name)
    {
        MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_UPDATE_NAME_ERR1);
        return;
    }
    
    if (!dev_addr)
    {
        MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_UPDATE_NAME_ERR2);
        return;
    }
    
    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_UPDATE_NAME_STR, dev_name);
    MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_DEV_ADDR, dev_addr->addr[0], dev_addr->addr[1], dev_addr->addr[2],
        dev_addr->addr[3], dev_addr->addr[4], dev_addr->addr[5]);

    //get exist
    fgResult = gatt_conn_state_get_device(dev_addr, GET_DEVICE_EXIST, &u1DevNum);
    if (fgResult) //find
    {
        is_update_name = g_GattConnStateInd[u1DevNum].is_update_name;
        if (!is_update_name)
        {
            cm_dev_addr.lap = (dev_addr->addr[2]<<16) | (dev_addr->addr[1]<<8) | dev_addr->addr[0];
            cm_dev_addr.uap = dev_addr->addr[3];
            cm_dev_addr.nap = (dev_addr->addr[5]<<8) | dev_addr->addr[4];
            
            srv_ble_cm_update_conn_dev_name(dev_name, &cm_dev_addr);

            g_GattConnStateInd[u1DevNum].is_update_name = TRUE; //set flag
        }
        else
        {
            MMI_TRACE(SRV_GATT_TRACE_GROUP, TRC_SRV_GATT_UPDATE_NAME_UPDATED);
            return;
        }
    }
}

void gatt_conn_clear_state(BD_ADDR *bd_addr)
{
    U8 u1DevNum = INVALID_DEVICE_NUM;
    BOOL fgResult = TRUE;

    fgResult = gatt_conn_state_get_device(bd_addr, GET_DEVICE_EXIST, &u1DevNum);
    if (fgResult) //find exist device
    {
        if (u1DevNum < MAX_LE_DEV_NUM) //check valid scope
        {
            if (g_GattConnStateInd[u1DevNum].is_ind_cm_disconn == TRUE) //in disconnect state
            {
                memset((U8 *)&g_GattConnStateInd[u1DevNum], 0, sizeof(gatt_conn_state_ind_struct)); //clear
            }
        }
    }
}

#endif //MMI_SRV_CONN_STATE_IND

#endif
