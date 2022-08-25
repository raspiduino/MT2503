/******************************************************************************
 * track_at_call.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        
 *
 * modification history
 * --------------------
 * v1.0   2012-09-07,  wangqi create this file
 *
 ******************************************************************************/
 #ifndef TR_CA_H
 #define TR_CA_H
#include "ps_public_struct.h"

typedef enum {
  TR_CALL_UNKNOW     = 0 ,
  TR_CALL_ECPI,
  TR_CALL_SETUP,            //+ECPI: 1,0,0,0,1,0,"66855",129//SET UP
  TR_CALL_RING,
  TR_CALL_DAILING,
  TR_CALL_CONNECT,      //+ECPI: 1,6,0,1,0,0,"66855",129 //接通,CSMCC_CALL_CONNECTED_MSG
  TR_CALL_MT_BUSY,      //ECPI: 1,1,0,0//
                                        //,,In band tone assigned,TCH assigned
  TR_CALL_NULL_NO,      //+ECPI: 1,1,1,1呼出号码为空
  
  TR_CALL_DISCONNECT,   //+ECPI: 1,1,0,1 //通话成功 挂断//来电未接听对方挂断
                                        //,CSMCC_DISCONNECT_MSG,No in band tone,TCH assigned
#if 1 //暂时不用
  TR_CALL_UN_CON_DIS,   //+ECPI: 1,1,0,0//通话不成功挂断//拒接来电
                                        //,,No in band tone,No TCH assigned
 
  TR_CALL_MT_IN_DIS,    //+ECPI: 1,134,,,,,"",,""
                                        //对方呼叫挂断134 CSMCC_STATE_CHANGE_MO_DISCONNECTING
#endif
  TR_CALL_ERROR,
  TR_CALL_AT_DAIL_OK,
  TR_CALL_MAX
}track_call_state_enum;

typedef enum
{
    CALL_SETUP_ATA,
    CALL_SETUP_LRSP,
    SETUP_MAX
}call_ata_setup_lrsp_enum;

typedef enum
{
    CALL_MO_OK = TR_CALL_MAX,//13
    CALL_MO_BUSY,
    CALL_MO_SIMERROR,
    CALL_MO_NUMBERERROR,
    CALL_MO_ATUNRSP,
    CALL_MO_UNKNOWERROR,
    CALL_MO_SMS_BUSY,
    CALL_MO_NORSP,
    CALL_GETNUMBERERROR,
    cMAX
}call_result_enum;

typedef enum
{
    CALL_FREE,
    CALL_MT_IN,
    CALL_MO_OUT,
    ctMAX
}call_type_enum;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16   type;
    kal_uint16   status;
} call_state_struct;

extern void track_call_state_notice_mmi(kal_uint16 type,kal_uint16 status);
extern char* track_get_incomming_call_number(void); 
extern kal_uint16 track_get_call_state(void);
extern kal_bool track_is_in_call(void);
extern kal_bool track_is_calling(void);
extern void track_make_call(char * number);

extern void track_l4c_sendmsg_call_ring_ind(l4c_number_struct* number, kal_uint8 call_type, kal_uint8 call_id);
extern void track_l4c_sendmsg_call_disc_release_lind(kal_uint8 action, kal_uint8 call_id, kal_uint16 cause, kal_uint8 call_type, kal_uint8 diag);

 #endif /*TR_CA_H*/
