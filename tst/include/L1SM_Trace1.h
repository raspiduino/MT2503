#ifndef L1TRC_L1SM_1_DEF_H
#define L1TRC_L1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1D_Trace_Str_TM_Sync_State(v1)  (unsigned char)(v1+0)
#define L1SM_Str_Wakeup(v1)  (unsigned char)(v1+2)
#define L1SM_Str_Bool(v1)  (unsigned char)(v1+13)
#define L1SM_Disable_Bool(v1)  (unsigned char)(v1+15)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER)
	#define L1SM_DBG_CALI_START() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CALI_START();\
} while(0)
#else
	#define L1SM_DBG_CALI_START()
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_CALI_DONE(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CALI_DONE((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1SM_DBG_CALI_DONE(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_TOPSM_PASS_2G(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_TOPSM_PASS_2G((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1SM_DBG_TOPSM_PASS_2G(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_SW_WAKEUP(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_SW_WAKEUP((unsigned char)(v1));\
} while(0)
#else
	#define L1SM_DBG_SW_WAKEUP(v1)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_CAL_SLEEP(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CAL_SLEEP((unsigned long)(v1), (unsigned long)(v2), (unsigned short)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1SM_DBG_CAL_SLEEP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_CAL_HW_SLEEP(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CAL_HW_SLEEP((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1SM_DBG_CAL_HW_SLEEP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1SM_DBG_CHECK_SLEEP_F(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SM_DBG_CHECK_SLEEP_F((unsigned long)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_F(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1SM_DBG_CHECK_HW_DEBOUNCE(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x04)!=0 )\
			L1TRC_Send_L1SM_DBG_CHECK_HW_DEBOUNCE((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1SM_DBG_CHECK_HW_DEBOUNCE(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SLEEP_C(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CHECK_SLEEP_C((unsigned char)(v1), (unsigned char)(v2), (unsigned short)(v3), (unsigned short)(v4), (unsigned char)(v5));\
} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_C(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SLEEP_TASK(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CHECK_SLEEP_TASK((unsigned long)(v1));\
} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_TASK(v1)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_CHECK_SLEEP_OS(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_CHECK_SLEEP_OS((unsigned char)(v1), (short)(v2), (unsigned char)(v3), (short)(v4));\
} while(0)
#else
	#define L1SM_DBG_CHECK_SLEEP_OS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_BEFORE_SLEEP(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_BEFORE_SLEEP((unsigned short)(v1), (unsigned short)(v2), (unsigned long)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1SM_DBG_BEFORE_SLEEP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1SM_TRC_DEBUG(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_TRC_DEBUG((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define L1SM_TRC_DEBUG(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1SM_TRC_DEBUG_HEX(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_TRC_DEBUG_HEX((unsigned short)(v1), (unsigned long)(v2), (unsigned long)(v3));\
} while(0)
#else
	#define L1SM_TRC_DEBUG_HEX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_2G_COMMON(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_DUAL_OS_TICK_2G_COMMON((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define DUAL_OS_TICK_2G_COMMON(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_2G_RECOVER(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_DUAL_OS_TICK_2G_RECOVER((unsigned short)(v1));\
} while(0)
#else
	#define DUAL_OS_TICK_2G_RECOVER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_INITIAL(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_DUAL_OS_TICK_INITIAL((unsigned char)(v1), (unsigned char)(v2), (unsigned char)(v3));\
} while(0)
#else
	#define DUAL_OS_TICK_INITIAL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_COMMON(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_DUAL_OS_TICK_3G_COMMON((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define DUAL_OS_TICK_3G_COMMON(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_RECOVER(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_DUAL_OS_TICK_3G_RECOVER((unsigned short)(v1));\
} while(0)
#else
	#define DUAL_OS_TICK_3G_RECOVER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_TICK_3G_DBG(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_DUAL_OS_TICK_3G_DBG((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define DUAL_OS_TICK_3G_DBG(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define DUAL_OS_TICK_ReSync() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x20)!=0 )\
			L1TRC_Send_DUAL_OS_TICK_ReSync();\
} while(0)
#else
	#define DUAL_OS_TICK_ReSync()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUAL_OS_RTC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x10)!=0 )\
			L1TRC_Send_DUAL_OS_RTC((unsigned char)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (long)(v5), (unsigned short)(v6), (unsigned long)(v7), (unsigned long)(v8), (unsigned char)(v9), (unsigned char)(v10), (unsigned short)(v11), (unsigned long)(v12));\
} while(0)
#else
	#define DUAL_OS_RTC(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#endif

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW1(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_Trace_SW1((unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
} while(0)
#else
	#define L1SM_Trace_SW1(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW2(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_Trace_SW2((short)(v1));\
} while(0)
#else
	#define L1SM_Trace_SW2(v1)
#endif

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW3(v1) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_Trace_SW3((unsigned long)(v1));\
} while(0)
#else
	#define L1SM_Trace_SW3(v1)
#endif

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW4(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_Trace_SW4((unsigned char)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned char)(v4), (unsigned long)(v5), (unsigned long)(v6));\
} while(0)
#else
	#define L1SM_Trace_SW4(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1SM_Trace_SW5(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_Trace_SW5((unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
} while(0)
#else
	#define L1SM_Trace_SW5(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_R_32K_UPDATE(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1SM_DBG_R_32K_UPDATE((unsigned long)(v1), (unsigned long)(v2));\
} while(0)
#else
	#define L1SM_DBG_R_32K_UPDATE(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1I_Msg_AvgTAC(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1I_Msg_AvgTAC((unsigned char)(v1), (short)(v2));\
} while(0)
#else
	#define L1I_Msg_AvgTAC(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_32KLESS_WAKEUP(v1, v2) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1SM_DBG_32KLESS_WAKEUP((unsigned short)(v1), (unsigned short)(v2));\
} while(0)
#else
	#define L1SM_DBG_32KLESS_WAKEUP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SM_DBG_32KLESS_FORCE_REPORT() do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1SM_DBG_32KLESS_FORCE_REPORT();\
} while(0)
#else
	#define L1SM_DBG_32KLESS_FORCE_REPORT()
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1SM_DBG_STABLE_PARAM(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1SM_DBG_STABLE_PARAM((short)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1SM_DBG_STABLE_PARAM(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x40)!=0 )\
			L1TRC_Send_L1SM_DBG_32KLESS_UPDATE_LPM((short)(v1), (unsigned short)(v2), (unsigned short)(v3), (unsigned short)(v4), (unsigned char)(v5), (unsigned char)(v6));\
} while(0)
#else
	#define L1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile(v1, v2, v3, v4, v5, v6) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_Timing_Profile((unsigned short)(v1), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
} while(0)
#else
	#define L1SM_DBG_Timing_Profile(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_A(v1, v2, v3, v4) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_TP_A((unsigned short)(v1), (long)(v2), (unsigned short)(v3), (long)(v4));\
} while(0)
#else
	#define L1SM_DBG_TP_A(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_B(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_TP_B((unsigned short)(v1), (long)(v2), (unsigned short)(v3), (long)(v4), (long)(v5));\
} while(0)
#else
	#define L1SM_DBG_TP_B(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_TP_C(v1, v2, v3, v4, v5) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_TP_C((unsigned short)(v1), (long)(v2), (unsigned short)(v3), (long)(v4), (long)(v5));\
} while(0)
#else
	#define L1SM_DBG_TP_C(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile_Best_Region(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_Timing_Profile_Best_Region((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define L1SM_DBG_Timing_Profile_Best_Region(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1SM_DBG_Timing_Profile_Worst_Region(v1, v2, v3) do {\
		if(L1SM_1_Trace_Filter[0]==1 && (L1SM_1_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_L1SM_DBG_Timing_Profile_Worst_Region((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define L1SM_DBG_Timing_Profile_Worst_Region(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1SM_DBG_CALI_START(void);
void L1TRC_Send_L1SM_DBG_CALI_DONE(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_DBG_TOPSM_PASS_2G(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_DBG_SW_WAKEUP(unsigned char v1);
void L1TRC_Send_L1SM_DBG_CAL_SLEEP(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_CAL_HW_SLEEP(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_F(unsigned long v1, unsigned short v2);
void L1TRC_Send_L1SM_DBG_CHECK_HW_DEBOUNCE(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_C(unsigned char v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned char v5);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_TASK(unsigned long v1);
void L1TRC_Send_L1SM_DBG_CHECK_SLEEP_OS(unsigned char v1, short v2, unsigned char v3, short v4);
void L1TRC_Send_L1SM_DBG_BEFORE_SLEEP(unsigned short v1, unsigned short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1SM_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1SM_TRC_DEBUG_HEX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_DUAL_OS_TICK_2G_COMMON(unsigned long v1, unsigned long v2);
void L1TRC_Send_DUAL_OS_TICK_2G_RECOVER(unsigned short v1);
void L1TRC_Send_DUAL_OS_TICK_INITIAL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DUAL_OS_TICK_3G_COMMON(unsigned long v1, unsigned long v2);
void L1TRC_Send_DUAL_OS_TICK_3G_RECOVER(unsigned short v1);
void L1TRC_Send_DUAL_OS_TICK_3G_DBG(unsigned char v1, unsigned char v2);
void L1TRC_Send_DUAL_OS_TICK_ReSync(void);
void L1TRC_Send_DUAL_OS_RTC(unsigned char v1, unsigned long v2, unsigned long v3, unsigned long v4, long v5, unsigned short v6, unsigned long v7, unsigned long v8, unsigned char v9, unsigned char v10, unsigned short v11, unsigned long v12);
void L1TRC_Send_L1SM_Trace_SW1(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L1SM_Trace_SW2(short v1);
void L1TRC_Send_L1SM_Trace_SW3(unsigned long v1);
void L1TRC_Send_L1SM_Trace_SW4(unsigned char v1, unsigned long v2, unsigned long v3, unsigned char v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_L1SM_Trace_SW5(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L1SM_DBG_R_32K_UPDATE(unsigned long v1, unsigned long v2);
void L1TRC_Send_L1I_Msg_AvgTAC(unsigned char v1, short v2);
void L1TRC_Send_L1SM_DBG_32KLESS_WAKEUP(unsigned short v1, unsigned short v2);
void L1TRC_Send_L1SM_DBG_32KLESS_FORCE_REPORT(void);
void L1TRC_Send_L1SM_DBG_STABLE_PARAM(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1SM_DBG_32KLESS_UPDATE_LPM(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5, unsigned char v6);
void L1TRC_Send_L1SM_DBG_Timing_Profile(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_L1SM_DBG_TP_A(unsigned short v1, long v2, unsigned short v3, long v4);
void L1TRC_Send_L1SM_DBG_TP_B(unsigned short v1, long v2, unsigned short v3, long v4, long v5);
void L1TRC_Send_L1SM_DBG_TP_C(unsigned short v1, long v2, unsigned short v3, long v4, long v5);
void L1TRC_Send_L1SM_DBG_Timing_Profile_Best_Region(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1SM_DBG_Timing_Profile_Worst_Region(unsigned short v1, long v2, long v3);

void Set_L1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1SM_1()	(L1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1SM_1_GSM_SM_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_SM_M()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_SM_L()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1SM_1_SM_LOCKER_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1SM_1_DUAL_OS_L()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1SM_1_DUAL_OS_DBG_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_32K_H()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1SM_1_GSM_32K_M()	(ChkL1ModFltr_L1SM_1()&&((L1SM_1_Trace_Filter[1]&0x80)!=0))
#define ChkL1MsgFltr_L1SM_DBG_CALI_START()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CALI_DONE()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TOPSM_PASS_2G()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_SW_WAKEUP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CAL_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CAL_HW_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_F()	ChkL1ClsFltr_L1SM_1_GSM_SM_L()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_HW_DEBOUNCE()	ChkL1ClsFltr_L1SM_1_GSM_SM_L()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_C()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_TASK()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_CHECK_SLEEP_OS()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_BEFORE_SLEEP()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_DEBUG()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_TRC_DEBUG_HEX()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_DUAL_OS_TICK_2G_COMMON()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_2G_RECOVER()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_INITIAL()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_COMMON()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_RECOVER()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_3G_DBG()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_DUAL_OS_TICK_ReSync()	ChkL1ClsFltr_L1SM_1_DUAL_OS_DBG_H()
#define ChkL1MsgFltr_DUAL_OS_RTC()	ChkL1ClsFltr_L1SM_1_DUAL_OS_L()
#define ChkL1MsgFltr_L1SM_Trace_SW1()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW2()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW3()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW4()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_Trace_SW5()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_R_32K_UPDATE()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1I_Msg_AvgTAC()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_WAKEUP()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_FORCE_REPORT()	ChkL1ClsFltr_L1SM_1_GSM_32K_M()
#define ChkL1MsgFltr_L1SM_DBG_STABLE_PARAM()	ChkL1ClsFltr_L1SM_1_GSM_32K_M()
#define ChkL1MsgFltr_L1SM_DBG_32KLESS_UPDATE_LPM()	ChkL1ClsFltr_L1SM_1_GSM_32K_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_A()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_B()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_TP_C()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile_Best_Region()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()
#define ChkL1MsgFltr_L1SM_DBG_Timing_Profile_Worst_Region()	ChkL1ClsFltr_L1SM_1_GSM_SM_H()


#endif
