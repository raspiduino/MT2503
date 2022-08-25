/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ktest_fsm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  fsm test case header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* MARCO
*
*
*****************************************************************************/
 
#define TT_ENTRY_SIZE  sizeof(tTranslateTableEntry)
#define MSG_ID_Ktest_process1_1 0        
#define MSG_ID_Ktest_process1_2 1       
#define MSG_ID_Ktest_process1_3 2      
                                
#define MSG_ID_Ktest_process2_1 0   
#define MSG_ID_Ktest_process2_2 1  
#define MSG_ID_Ktest_process2_3 2 
                                
#define MSG_ID_Ktest_process3_1 0
#define MSG_ID_Ktest_process3_2 1
#define MSG_ID_Ktest_process3_3 2
                                
#define MOD_process1  0
#define MOD_process2  1   
#define MOD_process3  2    
#define get_rand      fsm_rand(0,3)

#define check_result(a)      if(Bing_result[a].current_state != \
                                    Bing_result[a].except_state)\
                                            ASSERT(0);
#define GPT_TICKSPERSEC 100
#define MAGIC           0X20100330
#define save            2
#define change          0

/****************************************************************************
* type define
*
*
*****************************************************************************/
typedef enum
{
   process1_instacne1,
   process1_instacne2,
   process1_instacne3,
   NUM_INSTANCE_process1 = 4
} ktest_process1_instance ;

typedef enum
{
   process2_instacne1,
   process2_instacne2,
   process2_instacne3,
   NUM_INSTANCE_process2 = 4
} ktest_process2_instance ;

typedef enum
{
   process3_instacne1,
   process3_instacne2,
   process3_instacne3,
   NUM_INSTANCE_process3 = 4
} ktest_process3_instance ;

typedef enum
{
   process1_event1,
   process1_event2,
   process1_event3,
   NUM_EVENTS_process1
} ktest_process1_event ;

typedef enum
{
   process2_event1,
   process2_event2,
   process2_event3,
   NUM_EVENTS_process2
} ktest_process2_event ;

typedef enum
{
   process3_event1,
   process3_event2,
   process3_event3,
   NUM_EVENTS_process3
} ktest_process3_event ;

typedef enum
{
   process1_state1,
   process1_state2,
   process1_state3,
   NUM_STATES_process1
} ktest_process1_state ;

typedef enum
{
   process2_state1,
   process2_state2,
   process2_state3,
   NUM_STATES_process2
} ktest_process2_state ;

typedef enum
{
   process3_state1,
   process3_state2,
   process3_state3,
   NUM_STATES_process3
} ktest_process3_state ;


typedef enum
{
   process_1,
   process_2,
   process_3,
   ktest_NUM_SERVICES
} ktest_Services ;

typedef enum
{
   process1_entry_1,
   process1_entry_2,
   process1_entry_3
} ktest_test_entry1 ;
typedef enum
{
   process2_entry_1,
   process2_entry_2,
   process2_entry_3
} ktest_test_entry2;
typedef enum
{
   process3_entry_1,
   process3_entry_2,
   process3_entry_3
} ktest_test_entry3 ;

typedef struct
{
   kal_uint8 now_event;
   kal_uint8 prev_event;
   kal_uint8 prev_state;
   kal_uint8 current_state;
   kal_uint8 except_state;   
   kal_uint8 actual_state;
} ktest_result;

typedef enum
{
   event_1,
   event_2,
   event_3
} ktest_test_event ;

typedef enum
{
   instance1,
   instance2,
   instance3
} ktest_test_instance;


typedef void (*gpt_timer_handler)(void *);

/* function declare**********************************************/


kal_bool process1_addtrans (ilm_struct *ptMessage,                 //message to translate
                   kal_uint32 *pU32Event,                 //returned event array
                   kal_uint32 *pInstanceIndex,            //service table index array
                   kal_uint32 *pU32TableIndex) ;          //instance index array
kal_bool process2_addtrans (ilm_struct *ptMessage,                 //message to translate
                   kal_uint32 *pU32Event,                 //returned event array
                   kal_uint32 *pInstanceIndex,            //service table index array
                   kal_uint32 *pU32TableIndex) ;          //instance index array
kal_bool process3_addtrans (ilm_struct *ptMessage,                 //message to translate
                   kal_uint32 *pU32Event,                 //returned event array
                   kal_uint32 *pInstanceIndex,            //service table index array
                   kal_uint32 *pU32TableIndex) ;          //instance index array
mSM_TRANSLATE_MSG_FN(ktest_TranslateMsg) ;
mSM_TRANSITION_FN(Ktest_FSM_tansition);
mSM_TRANSITION_FN(Ktest_FSM_saved);
kal_uint32 fSM_GetFreeInstance(tComponentInfo *ptCompInfo, kal_uint32 processID);
/* tbale PROTOTYPES **********************************************/

const tTranslateTableEntry aprocess1_TranslateTable_ADR[] =
{
    { MSG_ID_Ktest_process1_1,        0,         process1_addtrans},
    { MSG_ID_Ktest_process1_2,        1,         process1_addtrans},
    { MSG_ID_Ktest_process1_3,        2,         process1_addtrans},


};

const tTranslateTableEntry aprocess2_TranslateTable_ADR[] =
{
    { MSG_ID_Ktest_process2_1,        0,         process2_addtrans},
    { MSG_ID_Ktest_process2_2,        1,         process2_addtrans},
    { MSG_ID_Ktest_process2_3,        2,         process2_addtrans},


};
const tTranslateTableEntry aprocess3_TranslateTable_ADR[] =
{
    { MSG_ID_Ktest_process3_1,        0,        process3_addtrans},
    { MSG_ID_Ktest_process3_2,        1,        process3_addtrans},
    { MSG_ID_Ktest_process3_3,        2,        process3_addtrans},


};


/* N_HandoverOrdReconfig state event transitions */
const tEventEntry aprocess1_state1tbl[] =
{
   { Ktest_FSM_tansition }, 
   { eSM_IgnoreEvent },
   { Ktest_FSM_saved }, 
   
} ;

const tEventEntry aprocess1_state2tbl[] =
{
	{ Ktest_FSM_tansition }, 
	{ eSM_IgnoreEvent },
	{ Ktest_FSM_saved }, 
} ;

const tEventEntry aprocess1_state3tbl[] =
{
   { Ktest_FSM_tansition }, 
   { eSM_IgnoreEvent },
   { Ktest_FSM_saved },  
} ;

const tEventEntry aprocess2_state1tbl[] =
{
	{ Ktest_FSM_tansition }, 
	{ eSM_IgnoreEvent },
	{ Ktest_FSM_saved },	
} ;

const tEventEntry aprocess2_state2tbl[] =
{
	{ Ktest_FSM_tansition }, 
	{ eSM_IgnoreEvent },
	{ Ktest_FSM_saved },	
 
} ;
const tEventEntry aprocess2_state3tbl[] =
{
	{ Ktest_FSM_tansition }, 
	{ eSM_IgnoreEvent },
	{ Ktest_FSM_saved },	 
} ;

const tEventEntry aprocess3_state1tbl[] =
{
	{ Ktest_FSM_tansition }, 
	{ eSM_IgnoreEvent },
	{ Ktest_FSM_saved },	 
} ;
const tEventEntry aprocess3_state2tbl[] =
{
	{ Ktest_FSM_tansition }, 
	{ eSM_IgnoreEvent },
	{ Ktest_FSM_saved },	
} ;
const tEventEntry aprocess3_state3tbl[] =
{
	{ Ktest_FSM_tansition }, 
	{ eSM_IgnoreEvent },
	{ Ktest_FSM_saved },	
} ;




const tTableEntry aprocess1_StateTable[] =
{
   { aprocess1_state1tbl},
   { aprocess1_state2tbl},
   { aprocess1_state3tbl},
} ;

const tTableEntry aprocess2_StateTable[] =
{
   { aprocess2_state1tbl},
   { aprocess2_state2tbl},
   { aprocess2_state3tbl},
} ;

const tTableEntry aprocess3_StateTable[] =
{
   { aprocess3_state1tbl},
   { aprocess3_state2tbl},
   { aprocess3_state3tbl},
} ;


static const  kal_uint16 KtestMaxInstances_test_case_one[] =
{
   /* process_1 */     1,
   /* guard value */	MAX_INSTANCE_INITIALISED
};


static const  kal_uint16 KtestMaxInstances_test[] =
{
   /* process_1 */     1,
                       2,
                       33,
   /* guard value */	MAX_INSTANCE_INITIALISED
};

static const  kal_uint16 KtestMaxInstances_test_for_getfreeinstance[] =
{
   /* process_1 */     1,
                       2,
                       3,
   /* guard value */	MAX_INSTANCE_INITIALISED
};

static const  kal_uint16 KtestMaxInstances[] =
{
   /* process_1 */    3,
   /* process_2 */    3,
   /* process_3 */    3,
   /* guard value */	MAX_INSTANCE_INITIALISED
};

/* Global variable **********************************************/


static tStateMachine       stateMachine ;
static tComponentInfo      compInfo ;
static tSM_ProcEntryFnPtr  KtestEntryFn[ktest_NUM_SERVICES] ;
static tComponentControl   ptCC;
static struct tContext     ktestContext;
ktest_test_entry1  process1_entry;
ktest_test_entry2  process2_entry;
ktest_test_entry3  process3_entry;
static ktest_result Bing_result[ktest_NUM_SERVICES];
char process1_newinstance[] = "process one add a new instance";
char process2_newinstance[] = "process two add a new instance";
char process3_newinstance[] = "process three add a new instance";
kal_uint32 event_count[ktest_NUM_SERVICES] = {0};


