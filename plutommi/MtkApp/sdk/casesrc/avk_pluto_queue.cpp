extern "C"
{
#include "mmi_frm_queue_gprot.h"
}

AVK_CASE(AVK_PLUTO_QUEUE_CASE_001,AVK_PLUTO_QUEUE)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYQUEUE message_sent, message_rec;
    U8 rec_res;
    MMI_BOOL success = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message_sent.src_mod_id = MOD_MMI;
    message_sent.dest_mod_id = MOD_MMI;
    message_sent.sap_id = (sap_type)100;
    message_sent.msg_id = (msg_type)1000;
    message_sent.local_para_ptr = NULL;
    message_sent.peer_buff_ptr = NULL;

    rec_res = 1;
    while (0 != rec_res)
    {
        rec_res = OslReadCircularQ(&message_rec); 
    }
    
    AVK_LOG_EX(OslWriteCircularQ(&message_sent));
    
    rec_res = OslReadCircularQ(&message_rec);
    
    AVK_LOG_FUN(OslReadCircularQ, (rec_res == 1) && (message_rec.msg_id == 1000));

    
    AVK_LOG_NORMAL(mmi_msg_send_ext_queue(&message_rec));
}


