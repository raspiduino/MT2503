#ifndef L1TRC_SleepDrv_1_DEF_H
#define L1TRC_SleepDrv_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define SLEEPDRV_Disable_Bool(v1)  (unsigned char)(v1+0)
#define SLEEPDRV_Str_Modem(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SM_CALLER(v1, v2, v3, v4, v5) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CHECK_SM_CALLER((unsigned long)(v1), (unsigned char)(v2), (short)(v3), (unsigned long)(v4), (unsigned long)(v5));\
} while(0)
#else
	#define L1SM_DBG_CHECK_SM_CALLER(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define SLEEPDRV_DBG_CHECK_SM_LOCKER(v1, v2) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_SLEEPDRV_DBG_CHECK_SM_LOCKER((short)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define SLEEPDRV_DBG_CHECK_SM_LOCKER(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define SLEEPDRV_DBG_CHECK_SM_LOCKERIndex(v1, v2) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_SLEEPDRV_DBG_CHECK_SM_LOCKERIndex((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define SLEEPDRV_DBG_CHECK_SM_LOCKERIndex(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define SLEEPDRV_DBG_CHECK_MODEM_LOCKER(v1) do {\
		if(SleepDrv_1_Trace_Filter[0]==1 && (SleepDrv_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_SLEEPDRV_DBG_CHECK_MODEM_LOCKER((unsigned char)(v1));\
} while(0)
#else
	#define SLEEPDRV_DBG_CHECK_MODEM_LOCKER(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char SleepDrv_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1SM_DBG_CHECK_SM_CALLER(unsigned long v1, unsigned char v2, short v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_SLEEPDRV_DBG_CHECK_SM_LOCKER(short v1, unsigned long v2);
void L1TRC_Send_SLEEPDRV_DBG_CHECK_SM_LOCKERIndex(unsigned long v1, unsigned long v2);
void L1TRC_Send_SLEEPDRV_DBG_CHECK_MODEM_LOCKER(unsigned char v1);

void Set_SleepDrv_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_SleepDrv_1()	(SleepDrv_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()	(ChkL1ModFltr_SleepDrv_1()&&((SleepDrv_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SM_CALLER()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()
#define ChkL1MsgFltr_SLEEPDRV_DBG_CHECK_SM_LOCKER()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()
#define ChkL1MsgFltr_SLEEPDRV_DBG_CHECK_SM_LOCKERIndex()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()
#define ChkL1MsgFltr_SLEEPDRV_DBG_CHECK_MODEM_LOCKER()	ChkL1ClsFltr_SleepDrv_1_SLEEPDRV_LOCKER_H()


#endif
