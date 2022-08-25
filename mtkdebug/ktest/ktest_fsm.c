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
 *   ktest_fsm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  fsm test case
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* this file is valid only when __KTEST__ has been defined */
#ifdef __KTEST__
 
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "Sm_event.h"
#include "sm_instance.h"
#include "sm_type.h"
#include "sm_statemachine.h"
#include "As_common.h"
#include "ktest_common.h"
#include "ktest_interface.h"
#include "ktest_fsm.h"

/* PRIVATE FUNCTION DEFINITIONS *********************************************/
/*
#define mSM_TRANSITION_FN(x)                                         \
                  kal_bool x(ilm_struct*      tReceivedMsg,          \
                             kal_uint32       U32InterpretedEvent,   \
                             kal_uint32*      pU32State,             \
                             struct tContext* ptContext,             \
                             kal_bool*        pSaved,                \
                             kal_bool*        pReleaseMsg,           \
                             kal_bool         isSavedEvent)
*/
/*XXX Fsm use this symbol which only defined in full load*/
#if defined( __MAUI_BASIC__ )
void tst_sys_trace( kal_uint8 *ptr )
{
}
#endif

static int fsm_rand( int lower, int upper )
{
	int range = upper - lower;

	if( range <= 0 )
	{
		return lower;
	}

	return lower + rand() % range;
}

/******************************************************************************
* Function:    entry function
*
* Parameters:  None
*
* Returns:     None
*
* Description:
******************************************************************************/
mSM_TRANSITION_FN( Ktest_FSM_tansition )
{
    ASSERT( tReceivedMsg!=NULL );
    ASSERT( pU32State!=NULL );
    ASSERT( pSaved!=NULL );
    ASSERT( pReleaseMsg!=NULL );

    *pU32State = (*pU32State + 1) % 3; // translation state
    Bing_result[tReceivedMsg->dest_mod_id].current_state = *pU32State;

    return KAL_TRUE;
}

mSM_TRANSITION_FN( Ktest_FSM_saved )
{
    ASSERT( tReceivedMsg != NULL );
    ASSERT( pU32State != NULL );
    ASSERT( pSaved != NULL );
    ASSERT( pReleaseMsg != NULL );

    if( isSavedEvent == KAL_TRUE ) // translation state
    {
        return KAL_FALSE;
    }
    else
    {
        *pSaved = KAL_TRUE;
        return KAL_TRUE;
    }
}

mSM_ENTRY_FN( Entry_process1 )
{
    switch( process1_entry )
   	{
	    case process1_entry_1:
   	        eSM_AddInstance( pContext,process_1,&process1_newinstance,\
                                sizeof( process1_newinstance ) );
			break;
        case process1_entry_2:
			break;
   	}
    return KAL_TRUE;
}

mSM_ENTRY_FN( Entry_process2 )
{
	switch( process2_entry )
	{
	    case process2_entry_1:
			 eSM_AddInstance( pContext,process_2,&process2_newinstance, \
                                 sizeof( process1_newinstance ) );
			 break;
	    case process2_entry_2:
			 break;
	}

    return KAL_TRUE;
}

mSM_ENTRY_FN( Entry_process3 )
{
	switch( process3_entry )
	{
	    case process3_entry_1:
			 eSM_AddInstance( pContext, process_3, &process3_newinstance,\
                                     sizeof( process1_newinstance ) );
			 break;
	    case process3_entry_2:
			 break;
	}

    return KAL_TRUE;
}

/******************************************************************************
* Function:    addtitional translation function
*
* Parameters:  None
*
* Returns:     None
*
* Description:
******************************************************************************/
kal_bool process1_addtrans ( ilm_struct *ptMessage,      //message to translate
                             kal_uint32 *pU32Event,      //returned event array
                             kal_uint32 *pU32TableIndex, //service table index array
                             kal_uint32 *pInstanceIndex)
{
    ktest_test_event event;

    ASSERT( ptMessage != NULL ) ;
    ASSERT( pU32Event != NULL ) ;
    ASSERT( pInstanceIndex != NULL ) ;
    ASSERT( pU32TableIndex != NULL ) ;

    *pInstanceIndex = 0;
    *pU32TableIndex = 0;
    event = ptMessage->msg_id;
    *pU32Event = event;
    switch( event )
    {
        case event_1:
               Bing_result[process_1].prev_event =  Bing_result[process_1].now_event;
               Bing_result[process_1].now_event =  event;
               Bing_result[process_1].prev_state=  Bing_result[process_1].current_state;
               Bing_result[process_1].except_state = \
                                                 (Bing_result[process_1].current_state\
                                                   + 1) % NUM_STATES_process1;
               break;

        case event_2:
               Bing_result[process_1].prev_event =  Bing_result[process_1].now_event;
               Bing_result[process_1].now_event =  event;
               Bing_result[process_1].prev_state=  Bing_result[process_1].current_state;
               Bing_result[process_1].except_state = Bing_result[process_1].current_state;
               break;

        case event_3:
               Bing_result[process_1].prev_event =  Bing_result[process_1].now_event;
               Bing_result[process_1].now_event =  event;
               Bing_result[process_1].prev_state=  Bing_result[process_1].current_state;
               Bing_result[process_1].except_state = Bing_result[process_1].current_state;
               break;

        default:
               ASSERT( KAL_FALSE );
               break;
    }

    return KAL_TRUE;
}

kal_bool process2_addtrans( ilm_struct *ptMessage,        //message to translate
                   kal_uint32 *pU32Event,                 //returned event array
                   kal_uint32 *pU32TableIndex,            //service table index array
                   kal_uint32 *pInstanceIndex )
{
    ktest_test_event event;

    ASSERT( ptMessage != NULL );
    ASSERT( pU32Event != NULL );
    ASSERT( pInstanceIndex != NULL );
    ASSERT( pU32TableIndex != NULL );

    *pInstanceIndex = 0;
    *pU32TableIndex = 1;
    event = ptMessage->msg_id;
    *pU32Event = event;
    switch( event )
    {
        case event_1:
               Bing_result[process_2].prev_event = Bing_result[process_2].now_event;
               Bing_result[process_2].now_event = event;
               Bing_result[process_2].prev_state= Bing_result[process_2].current_state;
               Bing_result[process_2].except_state = \
                                                 (Bing_result[process_2].current_state\
                                                   + 1) % NUM_STATES_process2;
               break;

        case event_2:
               Bing_result[process_2].prev_event = Bing_result[process_2].now_event;
               Bing_result[process_2].now_event = event;
               Bing_result[process_2].prev_state= Bing_result[process_2].current_state;
               Bing_result[process_2].except_state = Bing_result[process_2].current_state;
               break;

        case event_3:
               Bing_result[process_2].prev_event = Bing_result[process_2].now_event;
               Bing_result[process_2].now_event = event;
               Bing_result[process_2].prev_state = Bing_result[process_2].current_state;
               Bing_result[process_2].except_state = Bing_result[process_2].current_state;
               break;

        default:
               ASSERT( KAL_FALSE );
               break;
    }

    return KAL_TRUE;
}

kal_bool process3_addtrans( ilm_struct *ptMessage,        //message to translate
                   kal_uint32 *pU32Event,                 //returned event array
                   kal_uint32 *pU32TableIndex,            //service table index array
                   kal_uint32 *pInstanceIndex )
{
    ktest_test_event event;

    ASSERT( ptMessage != NULL );
    ASSERT( pU32Event != NULL );
    ASSERT( pInstanceIndex != NULL );
    ASSERT( pU32TableIndex != NULL );

    *pInstanceIndex = 0;
    *pU32TableIndex = 2;
    event = ptMessage->msg_id;
    *pU32Event = event;
    switch( event )
    {
        case event_1:
               Bing_result[process_3].prev_event = Bing_result[process_3].now_event;
               Bing_result[process_3].now_event = event;
               Bing_result[process_3].prev_state = Bing_result[process_3].current_state;
               Bing_result[process_3].except_state = \
                                                 (Bing_result[process_3].current_state\
                                                   + 1) % NUM_STATES_process3;
               break;

        case event_2:
               Bing_result[process_3].prev_event = Bing_result[process_3].now_event;
               Bing_result[process_3].now_event = event;
               Bing_result[process_3].prev_state = Bing_result[process_3].current_state;
               Bing_result[process_3].except_state = Bing_result[process_3].current_state;
               break;

        case event_3:
               Bing_result[process_3].prev_event = Bing_result[process_3].now_event;
               Bing_result[process_3].now_event = event;
               Bing_result[process_3].prev_state = Bing_result[process_3].current_state;
               Bing_result[process_3].except_state = Bing_result[process_3].current_state;
               break;

        default:
               ASSERT( KAL_FALSE );
               break;
    }

    return KAL_TRUE;
}

kal_bool ktest_fsm_eventlookup_case( ilm_struct *ptMessage, //message to translate
                   kal_uint32 *pU32Event,                   //returned event array
                   kal_uint32 *pInstanceIndex,              //service table index array
                   kal_uint32 *pU32TableIndex )
{
    if( ptMessage ->msg_id == MSG_ID_Ktest_process1_3 )
    {
        *pU32Event = MAGIC;
        *pInstanceIndex = MAGIC;
        *pU32TableIndex = MAGIC;
    }

    return KAL_TRUE;
}

/******************************************************************************
* Function:    translation function
*
* Parameters:  None
*
* Returns:     None
*
* Description:
******************************************************************************/
mSM_TRANSLATE_MSG_FN( ktest_TranslateMsg )
{
    kal_bool retcode = KAL_TRUE;

	ASSERT( ptContext != NULL );
	ASSERT( ptReceivedMsg != NULL );
	ASSERT( pU32InterpretedEvent != NULL );
	ASSERT( pU32TableIndex != NULL );

	/* call the translation function. */
    switch( ptReceivedMsg->dest_mod_id )
    {
	    case MOD_process1:
	         retcode = eSM_EventLookup( (tTranslateTableEntry*) aprocess1_TranslateTable_ADR,
								   sizeof( aprocess1_TranslateTable_ADR ) / TT_ENTRY_SIZE,
								   ptReceivedMsg,
								   pU32InterpretedEvent,
								   pU32TableIndex,
								   pInstanceIndex );
			 break;

	    case MOD_process2:
			 /* Default value */
             retcode = eSM_EventLookup( (tTranslateTableEntry*) aprocess2_TranslateTable_ADR,
								   sizeof( aprocess2_TranslateTable_ADR ) / TT_ENTRY_SIZE,
								   ptReceivedMsg,
								   pU32InterpretedEvent,
								   pU32TableIndex,
								   pInstanceIndex );
			 break;

	    case MOD_process3:
	         /* Default value */
		     retcode = eSM_EventLookup( (tTranslateTableEntry*) aprocess3_TranslateTable_ADR,
								   sizeof( aprocess3_TranslateTable_ADR ) / TT_ENTRY_SIZE,
								   ptReceivedMsg,
								   pU32InterpretedEvent,
								   pU32TableIndex,
								   pInstanceIndex );
		     break;

	    default:
			 ASSERT( KAL_FALSE );
			 break;
    }
    return retcode ;
}

mSM_TRANSLATE_MSG_FN( ktest_TranslateMsg_always_false )
{
    return KAL_FALSE;
}

mSM_TRANSLATE_MSG_FN( ktest_TranslateMsg_corrupt_buff )
{
    kal_uint32 counter;
    for( counter =0; counter < 6; counter++ )
    {
        pU32InterpretedEvent[counter] = process1_event1;
        pU32TableIndex[counter] = process_1;
        pInstanceIndex[counter] = process1_instacne1;
    }

    return KAL_TRUE;
}

mSM_TRANSLATE_MSG_FN( ktest_TranslateMsg_error__process_event )
{
    kal_uint32 counter = 0;
    pU32InterpretedEvent[counter] = 0;
    pU32TableIndex[counter] = cSM_MAX_PROCESSES;
    pInstanceIndex[counter] = 0;

    return KAL_TRUE;
}

mSM_TRANSLATE_MSG_FN( ktest_TranslateMsg_error_instance_event )
{
    kal_uint32 counter = 0;
    pU32InterpretedEvent[counter] = 0;
    pU32TableIndex[counter] = 0;
    pInstanceIndex[counter] = cSM_MAX_INSTANCES;

    return KAL_TRUE;
}

mSM_TRANSLATE_MSG_FN( ktest_TranslateMsg_error_add_event )
{
    kal_uint32 counter;
    for( counter =0; counter < 6; counter++ )
    {
        pU32InterpretedEvent[counter] = process1_event1;
        pU32TableIndex[counter] = process1_instacne1;
        pInstanceIndex[counter] = process1_instacne1;
    }

    return KAL_TRUE;
}

mSM_TRANSLATE_MSG_FN( ktest_TranslateMsg_add_event_to_new_instance )
{
    kal_uint32 counter;
    for( counter =1; counter < 6; counter++ )
    {
        pU32InterpretedEvent[counter] = process1_event3;
        pU32TableIndex[counter] = process_1;
        pInstanceIndex[counter] = process1_instacne2;
    }
    return KAL_TRUE;
}

/******************************************************************************
* Function:    ilm_generator
*
* Parameters:  None
*
* Returns:     None
*
* Description:
******************************************************************************/
void ilm_generator( ilm_struct *ilm )
{
    kal_uint8 i;
    ilm->dest_mod_id = get_rand;
    ilm->src_mod_id  = get_rand;
    ilm->msg_id      = get_rand;
    ilm->sap_id      = get_rand;
    ilm->local_para_ptr = NULL;
    ilm->peer_buff_ptr = NULL;
    if( ilm->msg_id == change )
    {
        if( event_count[ilm->dest_mod_id] != 0 )
        {
            event_count[ilm->dest_mod_id]=0;
        }
    }
    else
    {
        event_count[ilm->dest_mod_id]++;
    }

    for( i = 0; i < ktest_NUM_SERVICES; i++ )
    {
        if( event_count[i] >= 5 )
        ilm->msg_id  = change;
    }
}

/******************************************************************************
* Function:    FSM_main
*
* Parameters:  None
*
* Returns:     None
*
* Description:
******************************************************************************/
void FSM_main( task_entry_struct *task_entry_ptr )
{
    ilm_struct current_ilm;
    kal_uint32 i=0;

    while( 1 )
    {
        /* process internal queue */
        ilm_generator( &current_ilm );
        i++;

        /* timeout message will not be received in internal queue,
         * execute state machine directly */
        eSM_ExecuteContext( &ktestContext, &current_ilm );
        check_result( current_ilm.dest_mod_id )
   }
}

/******************************************************************************
* Function:    FSM_init
*
* Parameters:  None
*
* Returns:     None
*
* Description:
******************************************************************************/
kal_bool FSM_init( void )
{
    /* assign component info */
    strcpy( (char *) compInfo.aU8CompName, "Ktest_FSM" );

    /****************************************/
    /* Populate the state machine structure */
    /****************************************/

    //kal_trace(L3_PROG,INITIALISE_RRCE);
    SM_POPULATE_STATED_PROCESS( stateMachine,
                              process_1,
                              process1 );

    //kal_trace(L3_PROG,INITIALISE_SLCE);
    SM_POPULATE_STATED_PROCESS( stateMachine,
                              process_2,
                              process2 );


    //kal_trace(L3_PROG,INITIALISE_CSCE);
    SM_POPULATE_STATED_PROCESS( stateMachine,
                              process_3,
                              process3 );

    /* set the entry functions */
    /* Initialise the RRC in the Idle state FSM */
    KtestEntryFn[process_1] = NULL ;
    KtestEntryFn[process_2] = NULL ;
    KtestEntryFn[process_3] = NULL ;

    stateMachine.numServices = ktest_NUM_SERVICES;
    stateMachine.pfTranslateMsg = ktest_TranslateMsg ;
    stateMachine.entryFn = KtestEntryFn;

    /* initialise the max number of instances per SM process */
    INIT_MAX_INSTANCES( &compInfo, KtestMaxInstances, ktest_NUM_SERVICES );

    ktestContext.ptCC = &ptCC;
    ktestContext.ptSM = &stateMachine;
    ktestContext.ptCC->ptCompInfo = &compInfo;

    eSM_InitContext( &ktestContext );

    return KAL_TRUE;
}

/******************************************************************************
 * special test case init function
 *****************************************************************************/
kal_bool FSM_testcase_init_one( void )
{
    /* assign component info */
    strcpy( (char *) compInfo.aU8CompName, "ktest_fsm_contextinit_case_one" );

    /****************************************/
    /* Populate the state machine structure */
    /****************************************/

    //kal_trace(L3_PROG,INITIALISE_RRCE);
    SM_POPULATE_STATED_PROCESS( stateMachine,
                              process_1,
                              process1 );

    /* set the entry functions */
    /* Initialise the RRC in the Idle state FSM */
    KtestEntryFn[process_1] = NULL ;

    stateMachine.numServices = 1;
    stateMachine.pfTranslateMsg = ktest_TranslateMsg ;
    stateMachine.entryFn = KtestEntryFn;

    /* initialise the max number of instances per SM process */
    INIT_MAX_INSTANCES( &compInfo, KtestMaxInstances_test_case_one, 1 );

    ktestContext.ptCC = &ptCC;
    ktestContext.ptSM = &stateMachine;
    ktestContext.ptCC->ptCompInfo = &compInfo;

    eSM_InitContext( &ktestContext );

    return KAL_TRUE;
}

kal_bool FSM_testcase_init_for_getfreeinstance( void )
{
    /* assign component info */
    strcpy( (char *) compInfo.aU8CompName, "ktest_fsm_contextinit_case_one" );

    /****************************************/
    /* Populate the state machine structure */
    /****************************************/

    //kal_trace(L3_PROG,INITIALISE_RRCE);
    SM_POPULATE_STATED_PROCESS( stateMachine,
                              process_1,
                              process1 );

    SM_POPULATE_STATED_PROCESS( stateMachine,
                                process_2,
                                process2 );

    /* set the entry functions */
    /* Initialise the RRC in the Idle state FSM */
    KtestEntryFn[process_1] = NULL;

    stateMachine.numServices = ktest_NUM_SERVICES;
    stateMachine.pfTranslateMsg = ktest_TranslateMsg ;
    stateMachine.entryFn = KtestEntryFn;

    /* initialise the max number of instances per SM process */
    INIT_MAX_INSTANCES( &compInfo, KtestMaxInstances_test_for_getfreeinstance,
                        ktest_NUM_SERVICES );

    ktestContext.ptCC = &ptCC;
    ktestContext.ptSM = &stateMachine;
    ktestContext.ptCC->ptCompInfo = &compInfo;

    eSM_InitContext( &ktestContext );

    return KAL_TRUE;
}

kal_bool FSM_testcase_init( void )
{
    /* assign component info */
    strcpy( (char *) compInfo.aU8CompName, "ktest_fsm_contextinit_case_one" );

    /****************************************/
    /* Populate the state machine structure */
    /****************************************/

    //kal_trace(L3_PROG,INITIALISE_RRCE);
    SM_POPULATE_STATED_PROCESS( stateMachine,
                              process_1,
                              process1 );

    /* set the entry functions */
    /* Initialise the RRC in the Idle state FSM */
    KtestEntryFn[process_1] = Entry_process1 ;

    stateMachine.numServices = 1;
    stateMachine.pfTranslateMsg = ktest_TranslateMsg ;
    stateMachine.entryFn = KtestEntryFn;

    /* initialise the max number of instances per SM process */
    INIT_MAX_INSTANCES( &compInfo, KtestMaxInstances_test, 1 );

    ktestContext.ptCC = &ptCC;
    ktestContext.ptSM = &stateMachine;
    ktestContext.ptCC->ptCompInfo = &compInfo;

    eSM_InitContext( &ktestContext );

    return KAL_TRUE;
}

kal_bool FSM_testcase_init_two( void )
{

   /* assign component info */
   strcpy( (char *) compInfo.aU8CompName, "ktest_fsm_contextinit_case_one" ) ;

   /****************************************/
   /* Populate the state machine structure */
   /****************************************/

   //kal_trace(L3_PROG,INITIALISE_RRCE);
   SM_POPULATE_STATED_PROCESS( stateMachine,
                              process_1,
                              process1 );

   /* set the entry functions */
   /* Initialise the RRC in the Idle state FSM */
   KtestEntryFn[process_1] = Entry_process1 ;



   stateMachine.numServices = 1;
   stateMachine.pfTranslateMsg = ktest_TranslateMsg ;
   stateMachine.entryFn = KtestEntryFn;

   /* initialise the max number of instances per SM process */
   INIT_MAX_INSTANCES( &compInfo, KtestMaxInstances_test, 1 );

   ktestContext.ptCC = &ptCC;
   ktestContext.ptSM = &stateMachine;

   eSM_InitContext( &ktestContext );

   return KAL_TRUE;
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_populate_case_one
 * @remark brief: Test populate functionality, should populate as design
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_populate_case_one( kal_uint32 argc, void *argv )
{
	void *buff_ptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    SM_POPULATE_STATED_PROCESS( stateMachine,
                                 process_1,
                                 process1 );
	/* corrupt the pool id */
    if( stateMachine.atTables[process_1].U32NumStates != NUM_STATES_process1 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( stateMachine.atTables[process_1].U32NumEvents != NUM_EVENTS_process1 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( stateMachine.atTables[process_1].aStateEventMatrix!= aprocess1_StateTable )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( ktest_strcmp( (kal_char *) (stateMachine.atTables[process_1].serviceName), "process1" ) != 0 )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

	/* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name:ktest_fsm_populate_case_two
 * @remark brief:Test populate error checking: NULL SM fatal error will happen
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_POPULATE_NULL_SM
 *****************************************************************************/
kal_int32 ktest_fsm_populate_case_two( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_POPULATE_NULL_SM;

    eSM_PopulateProcessServiceSM( NULL,process_1,NUM_STATES_process1,\
                                  NUM_EVENTS_process1,aprocess1_StateTable,\
                                  (kal_int8 *) "ktest_fsm_populate_case_two" );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_populate_case_three
 * @remark brief: Test populate error checking: serviseName too long
 * fatal error should happen and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_POPULATE_OVER_MAX_SERVICE_NAME
 *****************************************************************************/
kal_int32 ktest_fsm_populate_case_three( kal_uint32 argc, void *argv )
{
	kal_int8 fake[50];
    kal_uint8 counter;
    for( counter = 0; counter<50; counter++ )
    {
        fake[counter] = 5;
    }

	fake[49] = 0;
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_POPULATE_OVER_MAX_SERVICE_NAME;

    eSM_PopulateProcessServiceSM( &stateMachine,process_1,NUM_STATES_process1,\
                                  NUM_EVENTS_process1,aprocess1_StateTable,\
                                  fake );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_populate_case_four
 * @remark brief: Test populate error checking: numEvents 0
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_POPULATE_NO_EVENT
 *****************************************************************************/
kal_int32 ktest_fsm_populate_case_four( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_POPULATE_NO_EVENT;

    eSM_PopulateProcessServiceSM( &stateMachine, process_1, NUM_STATES_process1,\
                                  0, aprocess1_StateTable,\
                                  (kal_int8*) "proccess1" );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_populate_case_five
 * @remark brief: Test populate error checking: pStateTable NULL
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_POPULATE_NULL_STATE_TBL
 *****************************************************************************/
kal_int32 ktest_fsm_populate_case_five( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_POPULATE_NULL_STATE_TBL;

    eSM_PopulateProcessServiceSM( &stateMachine,process_1,NUM_STATES_process1,\
                                  NUM_EVENTS_process1, NULL,\
                                  (kal_int8 *) "ktest_fsm_populate_case_two" );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_contextinit_case_one
 * @remark brief: Test FSM_testcase_init() basic functionality, contest shoudle be
 * initialized successfully
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_contextinit_case_one( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_testcase_init_one();

    if( ktestContext.ptCC->pEventQueue == NULL )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( ktestContext.ptCC->ptCompInfo->pfTranslateMsg !=\
                 ktestContext.ptSM->pfTranslateMsg )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( ktestContext.ptCC->ptCompInfo->numProcesses != \
                 ktestContext.ptSM->numServices )
    {
         ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( ktestContext.ptCC->ptCompInfo->numProcesses != \
                 ktestContext.ptSM->numServices )
    {
         ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( ktestContext.ptCC->ptCompInfo->pInstanceArray == NULL )
    {
         ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( ktestContext.ptCC->ptCompInfo->pInstanceArray[0].pFsmContext != NULL )
    {
         ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    /* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
	ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_contextinit_case_two
 * @remark brief: Test context initial error checking:double init fatal error should happen
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_INIT_INST_ARRAY_NON_NULL_INST_ARRAY
 *****************************************************************************/
kal_int32 ktest_fsm_contextinit_case_two( kal_uint32 argc, void *argv )
{
	tInstanceEntry      dummy;
	tInstanceArray      pInstanceArray ;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_INIT_INST_ARRAY_NON_NULL_INST_ARRAY;

    pInstanceArray = &dummy;
    compInfo.pInstanceArray = pInstanceArray;
    FSM_testcase_init();

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_contextinit_case_three
 * @remark brief: Test Context init, forget init service number of ptSM, fatel error should
 * happen and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_INIT_INST_ARRAY_ZERO_PROCESS
 *****************************************************************************/
kal_int32 ktest_fsm_contextinit_case_three( kal_uint32 argc, void *argv )
{
	tInstanceArray      pInstanceArray;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_INIT_INST_ARRAY_ZERO_PROCESS;

    SM_POPULATE_STATED_PROCESS( stateMachine, process_1, process1 );
    INIT_MAX_INSTANCES( &compInfo, KtestMaxInstances, ktest_NUM_SERVICES );
    stateMachine.numServices = 0;
    ktestContext.ptCC = &ptCC;
    ktestContext.ptSM = &stateMachine;
    ktestContext.ptCC->ptCompInfo = &compInfo;

    eSM_InitContext( &ktestContext );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_contextinit_case_four
 * @remark brief: Test Context init, error max instance table, fatel error should
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_INIT_INST_ARRAY_INVALID_MAX_INST
 *****************************************************************************/
kal_int32 ktest_fsm_contextinit_case_four( kal_uint32 argc, void *argv )
{
    kal_uint16 error[] =
    {
       /* process_1 */     1
    };

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_INIT_INST_ARRAY_INVALID_MAX_INST;

    SM_POPULATE_STATED_PROCESS( stateMachine, process_1, process1) ;

    INIT_MAX_INSTANCES( &compInfo, error, 1 );
    stateMachine.numServices = 1;

    ktestContext.ptCC = &ptCC;
    ktestContext.ptSM = &stateMachine;
    ktestContext.ptCC->ptCompInfo = &compInfo;

    eSM_InitContext( &ktestContext );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_contextinit_case_five
 * @remark brief:Test Context init, context init before populate, fatel error should
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code 4
 *****************************************************************************/
kal_int32 ktest_fsm_contextinit_case_five( kal_uint32 argc, void *argv )
{
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_DABORT;

    eSM_InitContext( &ktestContext );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_one
 * @remark brief: Test add instance :input error checking :input context NULL
 * fatal error should happen and a target reset
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_ADD_INST_NULL_CONTEXT
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_one( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 processID = process_1;
    kal_uint32 pData;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_ADD_INST_NULL_CONTEXT;

    FSM_init();
    instance = eSM_AddInstance( NULL, processID, &pData, sizeof( pData ) );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_two
 * @remark brief: Test add instance :input error checking :input pocess id out of range
 * fatal error should happen and a target reset
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_ADD_INST_INVALID_SERVICE_ID
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_two( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 pData;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_ADD_INST_INVALID_SERVICE_ID;

    FSM_init();
    instance = eSM_AddInstance( &ktestContext, cSM_MAX_PROCESSES, &pData,
                                sizeof( pData ) );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_three
 * @remark brief: Test add instance :input error checking :input poccess id beyond actual process ID
 * fatal error should happen and a target reset
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_ADD_INST_INVALID_PROCESS_ID
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_three( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 pData;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_ADD_INST_INVALID_PROCESS_ID;

    FSM_init();
    instance = eSM_AddInstance( &ktestContext, ktest_NUM_SERVICES, &pData,
                                sizeof( pData ) );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_four
 * @remark brief: Test add instance :input error checking :data input error, size 0
 * fatal error should happen and a target reset
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_ADD_INST_INVALID_PROCESS_ID
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_four( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 processID = process_1;
    kal_uint32 pData;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_ADD_INST_ZERO_DATA_SIZE;

    FSM_init();
    instance = eSM_AddInstance( &ktestContext, processID, &pData, 0 );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_five
 * @remark brief: Test add instance :input error checking :data input error, size > 64K (100000 on MoDIS)
 * assert error should happen and a target reset
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_BUFFMNGR_GETBUFF_POOLINDX_OUT_OF_RANGE
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_five( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 processID = process_1;
    kal_uint32 pData;

	KTEST_TCID = KTEST_FUNCTION_NAME;
    KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_GETBUFF_POOLINDX_OUT_OF_RANGE;

    FSM_init();
    instance = eSM_AddInstance( &ktestContext, processID, &pData, 100001 );

	/* report error if not fatal error */
	ktest_report_reset3( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_six
 * @remark brief: Test add instance :not space for add new instance
 * fatal error should happen and a target reset
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_FSM_GET_FREEINST_NO_FREE_INST
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_six( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 processID = process_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_GET_FREEINST_NO_FREE_INST;

    FSM_init();
    while( 1 )
    {
        instance = eSM_AddInstance( &ktestContext, processID, NULL, 0 );
    }

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_seven
 * @remark brief: Test add instance :add new instance success
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_seven( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 processID = process_1;
    kal_uint32 pData = MAGIC;
    tFsmContext * paddFsmTLContext;
    DLIST_LINK_HANDLE Link;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    instance = eSM_AddInstance( &ktestContext, processID, &pData,
                                sizeof( pData ) );

    paddFsmTLContext = (tFsmContext *) DlistLast( ktestContext.ptCC->\
                                                  ptCompInfo->pInstanceArray[instance].FsmStack \
                                                  , &Link );

    if( paddFsmTLContext != \
        ktestContext.ptCC->ptCompInfo->pInstanceArray[instance].pFsmContext )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( *(kal_uint32 *) (ktestContext.ptCC->ptCompInfo->pInstanceArray[instance].pFsmContext->pvParams)\
        != MAGIC )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    /* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_addinstance_case_eight
 * @remark brief: Test add instance :add new permanent instance success
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_addinstance_case_eight( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 processID = process_1;
    kal_uint32 pData = MAGIC;
    tFsmContext * paddFsmTLContext;
    DLIST_LINK_HANDLE Link;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    instance = eSM_AddPermanentInstance( &ktestContext, processID, &pData,
                                         sizeof( pData ) );

    paddFsmTLContext = (tFsmContext *) DlistLast( ktestContext.ptCC->\
                                                  ptCompInfo->pInstanceArray[instance].FsmStack \
                                                  , &Link );

    if( paddFsmTLContext != \
        ktestContext.ptCC->ptCompInfo->pInstanceArray[instance].pFsmContext )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    if( *(kal_uint32 *) (ktestContext.ptCC->ptCompInfo->pInstanceArray[instance].pFsmContext->pvParams)\
        != MAGIC )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    /* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_deleteinstance_case_one
 * @remark brief: Test delete instance :error checking for input pContext NULL
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_DEL_INSTENTRY_NULL_COMP_INFO
 *****************************************************************************/
kal_int32 ktest_fsm_deleteinstance_case_one( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = 0;
    kal_uint32 processID = process_1;
    tContext   dummy;
    tComponentControl dummyptCC ;
    dummyptCC.ptCompInfo = NULL;
    dummy.ptCC = &dummyptCC;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_DEL_INSTENTRY_NULL_COMP_INFO;

    FSM_init();
    eSM_DeleteInstance( &dummy, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_deleteinstance_case_two
 * @remark brief: Test delete instance :error checking for input process ID outof FSM range
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_FSM_DEL_INST_INVALID_PROCESS_ID
 *****************************************************************************/
kal_int32 ktest_fsm_deleteinstance_case_two( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = 0;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_DEL_INST_INVALID_PROCESS_ID;

    FSM_init();
    eSM_DeleteInstance( &ktestContext, cSM_MAX_PROCESSES, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_deleteinstance_case_three
 * @remark brief: Test delete instance :error checking for input instance ID outof FSM range
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_FSM_DEL_INST_INVALID_SERVICE_ID
 *****************************************************************************/
kal_int32 ktest_fsm_deleteinstance_case_three( kal_uint32 argc, void *argv )
{
    kal_uint32 processID = process_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_DEL_INST_INVALID_SERVICE_ID;

    FSM_init();
    eSM_DeleteInstance( &ktestContext, processID, cSM_MAX_INSTANCES );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_deleteinstance_case_four
 * @remark brief: Test delete instance :error checking for input process ID outof register range
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_DEL_INSTENTRY_OVER_MAX_PROCESS
 *****************************************************************************/
kal_int32 ktest_fsm_deleteinstance_case_four( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = 0;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_DEL_INSTENTRY_OVER_MAX_PROCESS;

    FSM_init();
    eSM_DeleteInstance( &ktestContext, ktest_NUM_SERVICES, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_deleteinstance_case_five
 * @remark brief: Test delete instance :error checking for input instance outof register range
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_DEL_INSTENTRY_OVER_MAX_INST
 *****************************************************************************/
kal_int32 ktest_fsm_deleteinstance_case_five( kal_uint32 argc, void *argv )
{
    kal_uint32 processID = process_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_DEL_INSTENTRY_OVER_MAX_INST;

    FSM_init();
    eSM_DeleteInstance( &ktestContext, processID, NUM_INSTANCE_process1 );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_deleteinstance_case_six
 * @remark brief: Test delete instance :error checking delete a unregister instance
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_DEL_INSTENTRY_INACTIVE_INST
 *****************************************************************************/
kal_int32 ktest_fsm_deleteinstance_case_six( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne2;
    kal_uint32 processID = process_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_DEL_INSTENTRY_INACTIVE_INST;

    FSM_init();
    eSM_DeleteInstance( &ktestContext, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_deleteinstance_case_seven
 * @remark brief: Test delete instance :basic functionality
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_deleteinstance_case_seven( kal_uint32 argc, void *argv )
{
    kal_uint32 instance ;
    kal_uint32 processID = process_1;
    kal_uint32 pData     = MAGIC;
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;
    pReceivedMsg.peer_buff_ptr= NULL;
    pReceivedMsg.local_para_ptr= NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_DEL_INSTENTRY_ROOT_INST;

    FSM_init();
    ktestContext.ptCC->ptCompInfo->pfTranslateMsg =\
                                            ktest_TranslateMsg_add_event_to_new_instance;
    instance = eSM_AddInstance( &ktestContext, processID, &pData, sizeof( pData ) );

    if( !(ktestContext.ptCC->ptCompInfo->pInstanceArray[instance].pFsmContext) )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    eSM_DeleteInstance( &ktestContext, process_1, instance );

    if( !(ktestContext.ptCC->ptCompInfo->pInstanceArray[instance].pFsmContext) )
    {
         ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else  /* report error if not fatal error */
    {
         ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }

    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstancePointer_case_one
 * @remark brief: Test get instance pointer :error checking input context NULL
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_GET_INSTPTR_NULL_COMP_INFO
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstancePointer_case_one( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = process_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_GET_INSTPTR_NULL_COMP_INFO;

    FSM_init();
    eSM_GetInstancePointer( NULL, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstancePointer_case_two
 * @remark brief: Test get instance pointer :error checking input proccess outof register range
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_GET_INSTPTR_OVER_PROCESS_ID
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstancePointer_case_two( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = ktest_NUM_SERVICES;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_GET_INSTPTR_OVER_PROCESS_ID;

    FSM_init();
    eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstancePointer_case_three
 * @remark brief: Test get instance pointer :error checking delete parent instance
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_GET_INSTPTR_OVER_INST_ID
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstancePointer_case_three( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = NUM_INSTANCE_process1;
    kal_uint32 processID = process_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_GET_INSTPTR_OVER_INST_ID;

    FSM_init();
    eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstancePointer_case_four
 * @remark brief: Test get instance pointer :error checking instance id outof regester range
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_GET_INSTPTR_NULL_INST
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstancePointer_case_four( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne2;
    kal_uint32 processID = process_1;

    /* check for invalid error checking
       pInstance = &(ptCompInfo->pInstanceArray[instanceOffset]); shuold be
       checking istance context!= 0. */
	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstancePointer_case_five
 * @remark brief: Test get instance pointer :error checking instance array NULL
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_GET_INSTPTR_NULL_INST_ARRAY
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstancePointer_case_five( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne2;
    kal_uint32 processID = process_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_GET_INSTPTR_NULL_INST_ARRAY;

    FSM_init();
    ktestContext.ptCC->ptCompInfo->pInstanceArray = NULL;
    eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstancePointer_case_six
 * @remark brief: Test get instance pointer : basic functionality should get pointer
 * as expectation
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstancePointer_case_six( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = process_1;
    tInstanceEntry *pInstance;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    pInstance = eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );
    if( pInstance != &(ktestContext.ptCC->ptCompInfo->pInstanceArray[instance]) )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
    if( pInstance->processId != processID )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
    if( pInstance->instanceId != instance )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    /* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstanceData_case_one
 * @remark brief: Test get instance data :error checking input context NULL
 * fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_FSM_GET_INSTDATA_NULL_CONTEXT
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstanceData_case_one( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = process_1;
    void * ptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_GET_INSTDATA_NULL_CONTEXT;

    FSM_init();
    ptr = eSM_GetInstanceData( NULL, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstanceData_case_two
 * @remark brief: Test get instance pointer :error checking input process ID outof
 * FSM range fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_FSM_GET_INSTDATA_INVALID_SERVICE_ID
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstanceData_case_two( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = cSM_MAX_PROCESSES;
    void * ptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_GET_INSTDATA_INVALID_SERVICE_ID;

    FSM_init();
    ptr = eSM_GetInstanceData( &ktestContext, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstanceData_case_three
 * @remark brief: Test get instance pointer :error checking input process ID outof
 * FSM range fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_FSM_GET_INSTDATA_INVALID_SERVICE_ID
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstanceData_case_three( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = cSM_MAX_INSTANCES;
    kal_uint32 processID = process_1;
    void * ptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_GET_INSTDATA_INVALID_INST_ID;

    FSM_init();
    ptr = eSM_GetInstanceData( &ktestContext, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstanceData_case_four
 * @remark brief: Test get instance pointer :error checking get data after instance
 * delete fatal error will happen and a target reset will trigger
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_FSM_GET_INSTDATA_INACTIVE_INST
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstanceData_case_four( kal_uint32 argc, void *argv )
{
    kal_uint32 instance ;
    kal_uint32 processID = process_1;
    void * ptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_GET_INSTDATA_INACTIVE_INST;

    FSM_init();
    instance = eSM_AddInstance( &ktestContext, processID, NULL, 0 );
    eSM_DeleteInstance( &ktestContext, processID, instance );
    ptr = eSM_GetInstanceData( &ktestContext, processID, instance );

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_GetInstanceData_case_five
 * @remark brief: Test get instance pointer :basic functionality
 * should get data as exceptation
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_GetInstanceData_case_five( kal_uint32 argc, void *argv )
{
    kal_uint32 instance;
    kal_uint32 processID = process_2;
    kal_uint32 pData = MAGIC;
    kal_uint32 *ptr;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    instance = eSM_AddInstance( &ktestContext, processID, &pData, sizeof( pData ) );
    ptr = eSM_GetInstanceData( &ktestContext, processID, instance );

    if( *((kal_uint32 *) ptr) != MAGIC )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    /* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_one
 * @remark brief: Test executeContext error checking,ptContext NULL fata error
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_EXEC_CONTEXT_NULL_CONTEXT
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_one( kal_uint32 argc, void *argv )
{
	tContext   *ptContext = NULL;
    ilm_struct *pReceivedMsg = NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_EXEC_CONTEXT_NULL_CONTEXT;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( ptContext, pReceivedMsg );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name:ktest_fsm_executecontext_case_two
 * @remark brief: Test executeContext error checking,pReceivedMsg NULL fata error
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_EXEC_CONTEXT_NULL_MSG
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_two( kal_uint32 argc, void *argv )
{
    ilm_struct *pReceivedMsg = NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_EXEC_CONTEXT_NULL_MSG;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, pReceivedMsg );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_three
 * @remark brief: Test executeContext error checking,MSG translation fail.fatal error
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_EXEC_CONTEXT_TRAN_MSG_FAIL
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_three( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_EXEC_CONTEXT_TRAN_MSG_FAIL;

    FSM_init();
	ktestContext.ptCC->ptCompInfo->pfTranslateMsg =\
                                            ktest_TranslateMsg_always_false;

    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_four
 * @remark brief: Test executeContext error checking,translation too many MSG
 * fail fatal error and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: KAL_ERROR_ESM_EXEC_CONTEXT_NON_NULL_LAST_EVENT
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_four( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_EXEC_CONTEXT_NON_NULL_LAST_EVENT;

    FSM_init();
	ktestContext.ptCC->ptCompInfo->pfTranslateMsg =\
                                            ktest_TranslateMsg_corrupt_buff;

    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_five
 * @remark brief: Test executeContext, input one MSg, and get result. ASSERT will happen if
 * result is not match with except
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_five( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
    check_result( pReceivedMsg.dest_mod_id )

	/* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_six
 * @remark brief: Test executeContext, rand MSG input one MSg, and get result.
 * ASSERT will happen if
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_six( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    ktest_lib_createtask( 60, FSM_main, NULL );
    ktest_start_gpt_timer( 16, (gpt_timer_handler) ktest_report_reset, (void *) KTEST_PASS );

    /* report error if not fatal error */
    kal_sleep_task( KAL_SUSPEND );
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_seven
 * @remark brief: Test executeContext error checking,translation process out of range
 * fatal error should happen and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_FSM_PROCESS_EVENTS_INVALID_PROCESS_ID
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_seven( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_FSM_ADD_EVENTS_OVER_MAX_PROCESS;

    FSM_init();
	ktestContext.ptCC->ptCompInfo->pfTranslateMsg =\
                                            ktest_TranslateMsg_error__process_event;

    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_eight
 * @remark brief: Test executeContext error checking,translation instance out of range
 * fatal error happen and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_GET_INSTPTR_OVER_INST_ID
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_eight( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_GET_INSTPTR_OVER_INST_ID;

    FSM_init();
	ktestContext.ptCC->ptCompInfo->pfTranslateMsg =\
                                            ktest_TranslateMsg_error_instance_event;

    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_nine
 * @remark brief: Test executeContext error checking, buff event error fatal error happen
 * and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_ESM_EXEC_CONTEXT_NON_NULL_LAST_EVENT
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_nine( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_ESM_EXEC_CONTEXT_NON_NULL_LAST_EVENT;

    FSM_init();
	ktestContext.ptCC->ptCompInfo->pfTranslateMsg =\
                                            ktest_TranslateMsg_error_add_event;

    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );

	/* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_ten
 * @remark brief: Test executeContext :save event functionality check,should save event as
 * design.
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_ten( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;
    kal_uint32 counter;
    kal_uint32 num_saved = 0;

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;

    pReceivedMsg.peer_buff_ptr= NULL;
    pReceivedMsg.local_para_ptr= NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    for( counter = 0; counter<5; counter++ )
    {
        eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
    }

    GotoStart( ktestContext.pCurrentInstance->pSavedEventQueue );
    while( GetNextEvent( ktestContext.pCurrentInstance->pSavedEventQueue ) )
    {
        num_saved++;
    }

    /* report error if not fatal error */
    if( num_saved != counter )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
    else
    {
	    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }

    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_eleven
 * @remark brief: Test executeContext :infinite save event
 *  fatal error hanppen and a target reboot should happen.
 * @remark dependency: none
 * @remark expecation: fatal error with code KAL_ERROR_BUFFMNGR_GETBUFF_NOT_AVAILABLE
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_eleven( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;
    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;
    pReceivedMsg.peer_buff_ptr= NULL;
    pReceivedMsg.local_para_ptr= NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_GETBUFF_NOT_AVAILABLE;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    while( 1 )
    {
        eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
    }

    /* report error if not fatal error */
	ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_executecontext_case_twelve
 * @remark brief: Test executeContext :saved event should be processed when state
 * chang as design
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_executecontext_case_twelve( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;
    kal_uint32 counter;
    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;
    pReceivedMsg.peer_buff_ptr= NULL;
    pReceivedMsg.local_para_ptr= NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = KAL_ERROR_BUFFMNGR_GETBUFF_FAILED;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    for( counter=0; counter < 6; counter++ )
    {
        eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
    }

    pReceivedMsg.msg_id = MSG_ID_Ktest_process1_1;
    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
    if( GetNextEvent( ktestContext.pCurrentInstance->pSavedEventQueue )\
                              != NULL )
    {
        ASSERT( 0 );
    }

    /* report error if not fatal error */
	ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_eventlookup_case_one
 * @remark brief: Test eventlookup :basic functionality without additional translation function
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_eventlookup_case_one( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;
    kal_bool   retcode = KAL_FALSE;
    kal_uint32 pU32InterpretedEvent;
    kal_uint32 pU32TableIndex;
    kal_uint32 pInstanceIndex;

    const tTranslateTableEntry test_TranslateTable[]=
    {
        //evSIBE_ADR_SIB_IND = 0
        { MSG_ID_Ktest_process1_1,process1_event1,  NULL},
        { MSG_ID_Ktest_process1_2,process1_event2,  NULL},
        { MSG_ID_Ktest_process1_3,process1_event3, NULL}
    };

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;
    pReceivedMsg.peer_buff_ptr= NULL;
    pReceivedMsg.local_para_ptr= NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;
    retcode = eSM_EventLookup( (tTranslateTableEntry *) test_TranslateTable,
                                      sizeof( test_TranslateTable ) / TT_ENTRY_SIZE,
                                      &pReceivedMsg,
                                      &pU32InterpretedEvent,
                                      &pU32TableIndex,
                                      &pInstanceIndex );

    if( pU32InterpretedEvent != process1_event3 )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
    else  /* report error if not fatal error */
    {
	    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_eventlookup_case_two
 * @remark brief: Test eventlookup :basic functionality with additional translation function
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_eventlookup_case_two( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;
    kal_bool   retcode = KAL_FALSE;
    kal_uint32 pU32InterpretedEvent;
    kal_uint32 pU32TableIndex;
    kal_uint32 pInstanceIndex;

    const tTranslateTableEntry test_TranslateTable[]=
    {
        //evSIBE_ADR_SIB_IND = 0
        { MSG_ID_Ktest_process1_1,process1_event1,  NULL},
        { MSG_ID_Ktest_process1_2,process1_event2,  NULL},
        { MSG_ID_Ktest_process1_3,process1_event3,  ktest_fsm_eventlookup_case}
    };

    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;
    retcode = eSM_EventLookup( (tTranslateTableEntry *) test_TranslateTable,
                                      sizeof( test_TranslateTable ) / TT_ENTRY_SIZE,
                                      &pReceivedMsg,
                                      &pU32InterpretedEvent,
                                      &pU32TableIndex,
                                      &pInstanceIndex );

    if( pU32InterpretedEvent!=MAGIC || pU32TableIndex!=MAGIC ||\
        pInstanceIndex != MAGIC )
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
    else  /* report error if not fatal error */
    {
	    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_eventlookup_case_three
 * @remark brief: Test eventlookup :basic functionality with additional translation function
 * but forget set event in addtional translation function
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_eventlookup_case_three( kal_uint32 argc, void *argv )
{
    ilm_struct pReceivedMsg;
    kal_bool   retcode = KAL_FALSE;
    kal_uint32 pU32InterpretedEvent;
    kal_uint32 pU32TableIndex;
    kal_uint32 pInstanceIndex;

    const tTranslateTableEntry test_TranslateTable[]=
    {
        //evSIBE_ADR_SIB_IND = 0
        { MSG_ID_Ktest_process1_1,process1_event1,  NULL},
        { MSG_ID_Ktest_process1_2,process1_event2,  NULL},
        { MSG_ID_Ktest_process1_3,process1_event3,  ktest_fsm_eventlookup_case}
    };

    pU32InterpretedEvent = 0xFFFFFFFF;
    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_1;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    retcode = eSM_EventLookup( (tTranslateTableEntry *) test_TranslateTable,
                                      sizeof( test_TranslateTable ) / TT_ENTRY_SIZE,
                                      &pReceivedMsg,
                                      &pU32InterpretedEvent,
                                      &pU32TableIndex,
                                      &pInstanceIndex );

    if( pU32InterpretedEvent == process1_event1 )
    {
	    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
    }
    else  /* report error if not fatal error */
    {
	    ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_LookupSpcEvent_case_one
 * @remark brief: Test get instance pointer :basic functionality
 * should get data as exceptation
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_LookupSpcEvent_case_one( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = process_1;
    kal_uint32 pData = MAGIC;
    kal_uint32* data;
    kal_uint16* length;
    tInstanceEntry *ptr;
    ilm_struct pReceivedMsg;
    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;
    pReceivedMsg.peer_buff_ptr = NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    pReceivedMsg.local_para_ptr = construct_int_local_para( 8, 1, __FILE__, __LINE__ );
    data = (kal_uint32*) ((kal_uint8 *) pReceivedMsg.local_para_ptr + sizeof( local_para_struct ));
    *data = MAGIC;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
    ptr = eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );

    fSM_LookUpSpecificSavedEvent( ptr,  pReceivedMsg.msg_id, &pReceivedMsg );
    data = (kal_uint32*) ((kal_uint8 *) pReceivedMsg.local_para_ptr + sizeof( local_para_struct ));
    if( *data != MAGIC )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
	else  /* report error if not fatal error */
	{
	    ktest_report( KTEST_PASS, KTEST_TCID, NULL );
	}
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_LookupSpcEvent_case_two
 * @remark brief: Test get instance pointer :basic functionality
 * should get data as exceptation
 * @remark dependency: none
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_LookupSpcEvent_case_two( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = process_1;
    kal_uint32 pData[6] = {MAGIC,2,3,4,5,6};
    local_para_struct peerdata;
    kal_uint32* data;
    kal_uint16* length;
    tInstanceEntry *ptr;
    ilm_struct pReceivedMsg;
    kal_uint32 counter = 1;
    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;
    pReceivedMsg.peer_buff_ptr  = NULL;

    pReceivedMsg.local_para_ptr = construct_int_local_para( 8, 1, __FILE__, __LINE__ );
    data = (kal_uint32 *) ((kal_uint8 *) pReceivedMsg.local_para_ptr + sizeof( local_para_struct ));
    *data = pData[0];

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    ptr = eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );
    while( counter < 6 )
    {
        eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
        pReceivedMsg.local_para_ptr = construct_int_local_para( 4, 1, __FILE__, __LINE__ );
        data = (kal_uint32 *) ((kal_uint8 *) pReceivedMsg.local_para_ptr + sizeof( local_para_struct ));
        *data = pData[counter];
        counter++;
    }

    fSM_LookUpSpecificSavedEvent( ptr, pReceivedMsg.msg_id, &pReceivedMsg );
    data = (kal_uint32 *) ((kal_uint8 *) pReceivedMsg.local_para_ptr + sizeof( local_para_struct ));
    if( *data != MAGIC )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }
	else  /* report error if not fatal error */
	{
        ktest_report( KTEST_PASS, KTEST_TCID, NULL );
	}
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * @remark category: fsm
 * @remark name: ktest_fsm_DeleteSpcEvent_case_one
 * @remark brief: Test get instance pointer :basic functionality
 * should get data as exceptation
 * @remark dependency: fSM_LookUpSpecificSavedEvent
 * @remark expecation: KTEST_PASS
 *****************************************************************************/
kal_int32 ktest_fsm_DeleteSpcEvent_case_one( kal_uint32 argc, void *argv )
{
    kal_uint32 instance = process1_instacne1;
    kal_uint32 processID = process_1;
    kal_uint32 pData[6] = {MAGIC,2,3,4,5,6};
    tInstanceEntry *ptr;
    ilm_struct pReceivedMsg;
    ilm_struct pMsg;
    kal_uint32 counter = 0;
    kal_uint32 mark    = 0;
    pReceivedMsg.dest_mod_id = MOD_process1;
    pReceivedMsg.src_mod_id  = MOD_process2;
    pReceivedMsg.sap_id      = 0;
    pReceivedMsg.msg_id      = MSG_ID_Ktest_process1_3;
    pReceivedMsg.local_para_ptr = (local_para_struct *)&pData;
    pReceivedMsg.peer_buff_ptr  = NULL;

	KTEST_TCID = KTEST_FUNCTION_NAME;
	KTEST_EXPECT_ERR_CODE = 0;

    FSM_init();
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_1, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_2, NULL, 0 );
    eSM_AddPermanentInstance( &ktestContext, (kal_uint32) process_3, NULL, 0 );

    ptr = eSM_GetInstancePointer( ktestContext.ptCC->ptCompInfo, processID, instance );
    while( counter < 6 )
    {
        eSM_ExecuteContext( &ktestContext, &pReceivedMsg );
        counter++;
        pReceivedMsg.local_para_ptr = (local_para_struct *) &pData[counter];
    }

    while( fSM_LookUpSpecificSavedEvent( ptr, pReceivedMsg.msg_id, &pMsg ) )
    {
        if( fSM_DeleteSpecificSavedEvent( ptr, pReceivedMsg.msg_id ) )
        {
            mark++;
        }
        else
        {
            break;
        }
    }

    if( mark != counter )
    {
        ktest_report( KTEST_FAIL, KTEST_TCID, NULL );
    }

    /* report error if not fatal error */
	ktest_report(KTEST_PASS, KTEST_TCID, NULL);
    ktest_reset_target();
    return( 0 );
}

/******************************************************************************
 * test case table of fsm module in post-schedule stage.
 * note that the test case wrapped with FIX_OSCAR_FAIL will be tested only on
 *           target, and will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_tc_fsm_tbl[] =
{
    {ktest_fsm_populate_case_one, 0, NULL},
    {ktest_fsm_populate_case_two, 0, NULL},
    {ktest_fsm_populate_case_three, 0, NULL},
    {ktest_fsm_populate_case_four, 0, NULL},
    {ktest_fsm_populate_case_five, 0, NULL},
    {ktest_fsm_contextinit_case_one, 0, NULL},
    {ktest_fsm_contextinit_case_two, 0, NULL},
    {ktest_fsm_contextinit_case_three, 0, NULL},
    {ktest_fsm_contextinit_case_four, 0, NULL},
#ifdef FIX_OSCAR_FAIL
    /* a data abort will occur in this test case, and this will cause memory
     * corruption on Visual C++.*/
    {ktest_fsm_contextinit_case_five, 0, NULL},
#endif
    {ktest_fsm_addinstance_case_one, 0, NULL},
    {ktest_fsm_addinstance_case_two, 0, NULL},
    {ktest_fsm_addinstance_case_three, 0, NULL},
    {ktest_fsm_addinstance_case_four, 0, NULL},
    {ktest_fsm_addinstance_case_five, 0, NULL},
    {ktest_fsm_addinstance_case_six, 0, NULL},
    {ktest_fsm_addinstance_case_seven, 0, NULL},
    {ktest_fsm_addinstance_case_eight, 0, NULL},
    {ktest_fsm_deleteinstance_case_one, 0, NULL},
    {ktest_fsm_deleteinstance_case_two, 0, NULL},
    {ktest_fsm_deleteinstance_case_three, 0, NULL},
    {ktest_fsm_deleteinstance_case_four, 0, NULL},
    {ktest_fsm_deleteinstance_case_five, 0, NULL},
    {ktest_fsm_deleteinstance_case_six, 0, NULL},
    {ktest_fsm_deleteinstance_case_seven, 0, NULL},
    {ktest_fsm_GetInstancePointer_case_one, 0, NULL},
    {ktest_fsm_GetInstancePointer_case_two, 0, NULL},
    {ktest_fsm_GetInstancePointer_case_three, 0, NULL},
    {ktest_fsm_GetInstancePointer_case_four, 0, NULL},
    {ktest_fsm_GetInstancePointer_case_five, 0, NULL},
    {ktest_fsm_GetInstancePointer_case_six, 0, NULL},
    {ktest_fsm_GetInstanceData_case_one, 0, NULL},
    {ktest_fsm_GetInstanceData_case_two, 0, NULL},
    {ktest_fsm_GetInstanceData_case_three, 0, NULL},
    {ktest_fsm_GetInstanceData_case_four, 0, NULL},
    {ktest_fsm_GetInstanceData_case_five, 0, NULL},
    {ktest_fsm_executecontext_case_one, 0, NULL},
    {ktest_fsm_executecontext_case_two, 0, NULL},
    {ktest_fsm_executecontext_case_three, 0, NULL},
    {ktest_fsm_executecontext_case_four, 0, NULL},
    {ktest_fsm_executecontext_case_five, 0, NULL},
    {ktest_fsm_executecontext_case_six, 0, NULL},
    {ktest_fsm_executecontext_case_seven, 0, NULL},
    {ktest_fsm_executecontext_case_eight, 0, NULL},
    {ktest_fsm_executecontext_case_nine, 0, NULL},
    {ktest_fsm_executecontext_case_ten, 0, NULL},
    {ktest_fsm_executecontext_case_eleven, 0, NULL},
    {ktest_fsm_executecontext_case_twelve, 0, NULL},
    {ktest_fsm_eventlookup_case_one, 0, NULL},
    {ktest_fsm_eventlookup_case_two, 0, NULL},
    {ktest_fsm_eventlookup_case_three, 0, NULL},
    {ktest_fsm_LookupSpcEvent_case_one, 0, NULL},
    {ktest_fsm_LookupSpcEvent_case_two, 0, NULL},
    {ktest_fsm_DeleteSpcEvent_case_one, 0, NULL}
};

/******************************************************************************
 * test case table of fsm module in pre-schedule stage.
 * note that the test case wrapped with FIX_OSCAR_FAIL will be tested only on
 *           target, and will be ignored on OSCAR.
 *****************************************************************************/
const ktest_tc_struct ktest_pre_tc_fsm_tbl[] =
{
	{ktest_fake_test, 0, NULL},
};

/******************************************************************************
 * Name:
 *     ktest_tc_fsm_num
 * Functionality:
 *     caculate there are how many test cases of fsm module in post-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of fsm module in post-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_tc_fsm_num( void )
{
	return sizeof( ktest_tc_fsm_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_pre_tc_fsm_num
 * Functionality:
 *     caculate there are how many test cases of fsm module in pre-schedule
 *     stage.
 * Parameters:
 *     void.
 * Returns:
 *     the total number of test cases of fsm module in pre-schedule stage.
 *****************************************************************************/
kal_uint32 ktest_pre_tc_fsm_num( void )
{
	return sizeof( ktest_pre_tc_fsm_tbl ) / sizeof( ktest_tc_struct );
}

/******************************************************************************
 * Name:
 *     ktest_fsm_init
 * Functionality:
 *     the initialization function of fsm module.
 * Parameters:
 *     mod: id of fsm module.
 * Returns:
 *     void.
 * Note:
 *     we should call this function in ktest_testcase_register to register test
 *     cases of fsm module into KTEST.
 *****************************************************************************/
void ktest_fsm_init( kal_uint32 mod )
{
	tc_all_tbls[mod] = ktest_tc_fsm_tbl;
	pre_tc_all_tbls[mod] = ktest_pre_tc_fsm_tbl;

	tc_modules_num[mod] = ktest_tc_fsm_num();
	pre_tc_modules_num[mod] = ktest_pre_tc_fsm_num();
}

#endif  /*__KTEST__*/
