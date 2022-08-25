#ifndef L1TRC_L1D_3RD_DEF_H
#define L1TRC_L1D_3RD_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1D_Trace_Str_TM_Sync_State(v1)  (unsigned char)(v1+0)
#define L1SM_Str_Wakeup(v1)  (unsigned char)(v1+2)
#define L1SM_Str_Bool(v1)  (unsigned char)(v1+13)
#define L1SM_Disable_Bool(v1)  (unsigned char)(v1+15)
#define L1D_Dual_Afc_L1C_Ask_Msg(v1)  (unsigned char)(v1+17)
#define L1D_Trc_Str_NonSync_HO(v1)  (unsigned char)(v1+27)
#define L1D_Trc_Str_WGG_Event(v1)  (unsigned char)(v1+32)
#define L1D_Trc_Str_TDDM_SetGap(v1)  (unsigned char)(v1+34)
#define L1D_Trc_Str_TDDM_PM(v1)  (unsigned char)(v1+37)
#define L1D_Trc_Str_TDDM_STATE(v1)  (unsigned char)(v1+40)


/****************************/
/* Message macro definition */
/****************************/
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_VTuneCrt7AREA(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_XO_TRACE_VTuneCrt7AREA((char)(v1), (long)(v2), (short)(v3), (long)(v4));\
} while(0)
#else
	#define XO_TRACE_VTuneCrt7AREA(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_FreqCrtUpdate(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x01)!=0 )\
			L1TRC_Send_XO_TRACE_FreqCrtUpdate((char)(v1), (short)(v2));\
} while(0)
#else
	#define XO_TRACE_FreqCrtUpdate(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_ReadTempADC(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_XO_TRACE_ReadTempADC((short)(v1), (long)(v2));\
} while(0)
#else
	#define XO_TRACE_ReadTempADC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_CmpTempPhi(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_XO_TRACE_CmpTempPhi((long)(v1));\
} while(0)
#else
	#define XO_TRACE_CmpTempPhi(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_Phi2Dac(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x02)!=0 )\
			L1TRC_Send_XO_TRACE_Phi2Dac((long)(v1), (short)(v2));\
} while(0)
#else
	#define XO_TRACE_Phi2Dac(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define CH_afc_dbg(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_CH_afc_dbg((short)(v1), (short)(v2), (long)(v3), (long)(v4));\
} while(0)
#else
	#define CH_afc_dbg(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define CH_afc_dbg2(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_CH_afc_dbg2((long)(v1), (short)(v2), (long)(v3), (long)(v4));\
} while(0)
#else
	#define CH_afc_dbg2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define CH_afc_dbg3(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_CH_afc_dbg3((short)(v1), (long)(v2), (long)(v3), (short)(v4));\
} while(0)
#else
	#define CH_afc_dbg3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define CH_afc_dbg4(v1, v2, v3, v4, v5) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_CH_afc_dbg4((short)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define CH_afc_dbg4(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define CH_afc_dbg5(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_CH_afc_dbg5((short)(v1));\
} while(0)
#else
	#define CH_afc_dbg5(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_DUAL_AFC_L1C_ask(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_DUAL_AFC_L1C_ask((unsigned char)(v1));\
} while(0)
#else
	#define L1D_Trc_DUAL_AFC_L1C_ask(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trace_TM_Sync_State(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_Trace_TM_Sync_State((unsigned char)(v1));\
} while(0)
#else
	#define L1D_Trace_TM_Sync_State(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_FCCH_1(v1, v2, v3, v4, v5) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_FCCH_1((short)(v1), (short)(v2), (short)(v3), (long)(v4), (long)(v5));\
} while(0)
#else
	#define L1D_TDDM_FCCH_1(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_FB(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_FB((short)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_TDDM_FB(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_SetGap(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_SetGap((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1D_TDDM_SetGap(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_FBM_SHORT(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_FBM_SHORT((short)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1D_TDDM_FBM_SHORT(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_SBM(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_SBM((short)(v1), (short)(v2), (short)(v3), (short)(v4));\
} while(0)
#else
	#define L1D_TDDM_SBM(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_PM(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_PM((unsigned char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_TDDM_PM(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_STATE(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_STATE((unsigned char)(v1), (unsigned char)(v2));\
} while(0)
#else
	#define L1D_TDDM_STATE(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_TDDM_AFC_CON(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			L1TRC_Send_L1D_TDDM_AFC_CON((short)(v1));\
} while(0)
#else
	#define L1D_TDDM_AFC_CON(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_RepeatedACCH(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x80)!=0 )\
			L1TRC_Send_L1D_Trc_RepeatedACCH((unsigned char)(v1), (char)(v2), (char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6));\
} while(0)
#else
	#define L1D_Trc_RepeatedACCH(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER)
	#define L1D_TRC_DEBUG(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x40)!=0 )\
			L1TRC_Send_L1D_TRC_DEBUG((unsigned short)(v1), (long)(v2), (long)(v3));\
} while(0)
#else
	#define L1D_TRC_DEBUG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_DTS_TRACE_MACHINE(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x02)!=0 )\
			L1TRC_Send_L1D_DTS_TRACE_MACHINE((short)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_DTS_TRACE_MACHINE(v1, v2, v3)
#endif

#if defined(L1_CATCHER)
	#define L1D_TRC_NonSync_HO_Event(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x80)!=0 )\
			L1TRC_Send_L1D_TRC_NonSync_HO_Event((unsigned char)(v1), (char)(v2));\
} while(0)
#else
	#define L1D_TRC_NonSync_HO_Event(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_WGG_Event(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_WGG_Event((unsigned char)(v1));\
} while(0)
#else
	#define L1D_Trc_WGG_Event(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_WGG_ConsumePMQueue(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x01)!=0 )\
			L1TRC_Send_L1D_Trc_WGG_ConsumePMQueue((short)(v1));\
} while(0)
#else
	#define L1D_Trc_WGG_ConsumePMQueue(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_WCAL_RESULT(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x40)!=0 )\
			L1TRC_Send_L1D_Trc_WCAL_RESULT((char)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_Trc_WCAL_RESULT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_HRD_POWER_RESULT(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_HRD_POWER_RESULT((short)(v1), (short)(v2), (short)(v3));\
} while(0)
#else
	#define L1D_Trc_HRD_POWER_RESULT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_HRD_RESULT(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x08)!=0 )\
			L1TRC_Send_L1D_Trc_HRD_RESULT((char)(v1));\
} while(0)
#else
	#define L1D_Trc_HRD_RESULT(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_VAMOS_RESULT(v1, v2, v3, v4, v5) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x02)!=0 )\
			L1TRC_Send_L1D_Trc_VAMOS_RESULT((unsigned char)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5));\
} while(0)
#else
	#define L1D_Trc_VAMOS_RESULT(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_BLK_RESULT(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x04)!=0 )\
			L1TRC_Send_L1D_Trc_BLK_RESULT((short)(v1));\
} while(0)
#else
	#define L1D_Trc_BLK_RESULT(v1)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_DLIF_SWITCH_IF(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_DLIF_SWITCH_IF((short)(v1), (short)(v2));\
} while(0)
#else
	#define L1D_Trc_DLIF_SWITCH_IF(v1, v2)
#endif

#if defined(L1_CATCHER)
	#define L1D_Trc_DLIF_PEER_IF(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x20)!=0 )\
			L1TRC_Send_L1D_Trc_DLIF_PEER_IF((short)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6));\
} while(0)
#else
	#define L1D_Trc_DLIF_PEER_IF(v1, v2, v3, v4, v5, v6)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_DLIF_RETURN_IF(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x10)!=0 )\
			L1TRC_Send_L1D_Trc_DLIF_RETURN_IF((short)(v1), (short)(v2), (short)(v3), (short)(v4), (short)(v5), (short)(v6), (short)(v7));\
} while(0)
#else
	#define L1D_Trc_DLIF_RETURN_IF(v1, v2, v3, v4, v5, v6, v7)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1D_3RD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_XO_TRACE_VTuneCrt7AREA(char v1, long v2, short v3, long v4);
void L1TRC_Send_XO_TRACE_FreqCrtUpdate(char v1, short v2);
void L1TRC_Send_XO_TRACE_ReadTempADC(short v1, long v2);
void L1TRC_Send_XO_TRACE_CmpTempPhi(long v1);
void L1TRC_Send_XO_TRACE_Phi2Dac(long v1, short v2);
void L1TRC_Send_CH_afc_dbg(short v1, short v2, long v3, long v4);
void L1TRC_Send_CH_afc_dbg2(long v1, short v2, long v3, long v4);
void L1TRC_Send_CH_afc_dbg3(short v1, long v2, long v3, short v4);
void L1TRC_Send_CH_afc_dbg4(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_CH_afc_dbg5(short v1);
void L1TRC_Send_L1D_Trc_DUAL_AFC_L1C_ask(unsigned char v1);
void L1TRC_Send_L1D_Trace_TM_Sync_State(unsigned char v1);
void L1TRC_Send_L1D_TDDM_FCCH_1(short v1, short v2, short v3, long v4, long v5);
void L1TRC_Send_L1D_TDDM_FB(short v1, short v2, short v3);
void L1TRC_Send_L1D_TDDM_SetGap(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_TDDM_FBM_SHORT(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_TDDM_SBM(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_TDDM_PM(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_TDDM_STATE(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_TDDM_AFC_CON(short v1);
void L1TRC_Send_L1D_Trc_RepeatedACCH(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1D_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1D_DTS_TRACE_MACHINE(short v1, short v2, short v3);
void L1TRC_Send_L1D_TRC_NonSync_HO_Event(unsigned char v1, char v2);
void L1TRC_Send_L1D_Trc_WGG_Event(unsigned char v1);
void L1TRC_Send_L1D_Trc_WGG_ConsumePMQueue(short v1);
void L1TRC_Send_L1D_Trc_WCAL_RESULT(char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_HRD_POWER_RESULT(short v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_HRD_RESULT(char v1);
void L1TRC_Send_L1D_Trc_VAMOS_RESULT(unsigned char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1D_Trc_BLK_RESULT(short v1);
void L1TRC_Send_L1D_Trc_DLIF_SWITCH_IF(short v1, short v2);
void L1TRC_Send_L1D_Trc_DLIF_PEER_IF(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_Trc_DLIF_RETURN_IF(short v1, short v2, short v3, short v4, short v5, short v6, short v7);

void Set_L1D_3RD_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1D_3RD()	(L1D_3RD_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1D_3RD_XO_VTUNE_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DM_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1D_3RD_GSM_SM_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1D_3RD_GSM_SM_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1D_3RD_SM_LOCKER_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_RepeatedACCH_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DBG_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_FHC_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_Improve_HO_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1D_3RD_GSM_SM_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DBG_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_Improve_HO_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1D_3RD_VAMOS_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_BLK_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_BLK_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DLIF_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DLIF_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_WCAL_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x40)!=0))
#define ChkL1MsgFltr_XO_TRACE_VTuneCrt7AREA()	ChkL1ClsFltr_L1D_3RD_XO_VTUNE_L()
#define ChkL1MsgFltr_XO_TRACE_FreqCrtUpdate()	ChkL1ClsFltr_L1D_3RD_XO_VTUNE_L()
#define ChkL1MsgFltr_XO_TRACE_ReadTempADC()	ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()
#define ChkL1MsgFltr_XO_TRACE_CmpTempPhi()	ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()
#define ChkL1MsgFltr_XO_TRACE_Phi2Dac()	ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()
#define ChkL1MsgFltr_CH_afc_dbg()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg2()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg3()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg4()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg5()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_L1D_Trc_DUAL_AFC_L1C_ask()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_L1D_Trace_TM_Sync_State()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_FCCH_1()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_FB()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_SetGap()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_FBM_SHORT()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_SBM()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_PM()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_STATE()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_AFC_CON()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_Trc_RepeatedACCH()	ChkL1ClsFltr_L1D_3RD_L1D_RepeatedACCH_L()
#define ChkL1MsgFltr_L1D_TRC_DEBUG()	ChkL1ClsFltr_L1D_3RD_L1D_DBG_H()
#define ChkL1MsgFltr_L1D_DTS_TRACE_MACHINE()	ChkL1ClsFltr_L1D_3RD_L1D_FHC_M()
#define ChkL1MsgFltr_L1D_TRC_NonSync_HO_Event()	ChkL1ClsFltr_L1D_3RD_L1D_Improve_HO_H()
#define ChkL1MsgFltr_L1D_Trc_WGG_Event()	ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_H()
#define ChkL1MsgFltr_L1D_Trc_WGG_ConsumePMQueue()	ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_H()
#define ChkL1MsgFltr_L1D_Trc_WCAL_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_WCAL_M()
#define ChkL1MsgFltr_L1D_Trc_HRD_POWER_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_BLK_M()
#define ChkL1MsgFltr_L1D_Trc_HRD_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_BLK_M()
#define ChkL1MsgFltr_L1D_Trc_VAMOS_RESULT()	ChkL1ClsFltr_L1D_3RD_VAMOS_H()
#define ChkL1MsgFltr_L1D_Trc_BLK_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_BLK_H()
#define ChkL1MsgFltr_L1D_Trc_DLIF_SWITCH_IF()	ChkL1ClsFltr_L1D_3RD_L1D_DLIF_H()
#define ChkL1MsgFltr_L1D_Trc_DLIF_PEER_IF()	ChkL1ClsFltr_L1D_3RD_L1D_DLIF_H()
#define ChkL1MsgFltr_L1D_Trc_DLIF_RETURN_IF()	ChkL1ClsFltr_L1D_3RD_L1D_DLIF_L()


#endif
