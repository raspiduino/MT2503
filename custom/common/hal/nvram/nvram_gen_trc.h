typedef enum {
    _NVRAM_EF_SYS_LID = 0,
    _NVRAM_EF_CAT_TIMESTAMP_LID = 9,
    _NVRAM_EF_L1_AGCPATHLOSS_LID = 15,
    _NVRAM_EF_L1_RAMPTABLE_GSM850_LID = 16,
    _NVRAM_EF_L1_RAMPTABLE_GSM900_LID = 17,
    _NVRAM_EF_L1_RAMPTABLE_DCS1800_LID = 18,
    _NVRAM_EF_L1_RAMPTABLE_PCS1900_LID = 19,
    _NVRAM_EF_L1_AFCDATA_LID = 28,
    _NVRAM_EF_L1_TXIQ_LID = 29,
    _NVRAM_EF_L1_RFSPECIALCOEF_LID = 30,
    _NVRAM_EF_L1_INTERSLOT_RAMP_GSM850_LID = 31,
    _NVRAM_EF_L1_INTERSLOT_RAMP_GSM900_LID = 32,
    _NVRAM_EF_L1_INTERSLOT_RAMP_DCS1800_LID = 33,
    _NVRAM_EF_L1_INTERSLOT_RAMP_PCS1900_LID = 34,
    _NVRAM_EF_L1_CRYSTAL_AFCDATA_LID = 35,
    _NVRAM_EF_L1_CRYSTAL_CAPDATA_LID = 36,
    _NVRAM_EF_L1_GMSK_TX_POWER_ROLLBACK_TABLE_LID = 37,
    _NVRAM_EF_L1_CLOAD_FREQ_OFFSET_LID = 43,
    _NVRAM_EF_BARCODE_NUM_LID = 98,
    _NVRAM_EF_CAL_FLAG_LID = 99,
    _NVRAM_EF_CAL_DATA_CHECK_LID = 100,
    _NVRAM_EF_IMEI_IMEISV_LID = 161,
    _NVRAM_EF_SML_LID = 162,
    _NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID = 79,
    _NVRAM_EF_BT_INFO_LID = 183,
    _NVRAM_EF_BT_DEV_LIST_LID = 184,
    _NVRAM_EF_BT_DEV_LIST_INDEX_LID = 185,
    _NVRAM_EF_BT_SYS_INFO_LID = 186,
    _NVRAM_EF_SYS_EXCEPTION_LID = 6,
    _NVRAM_EF_SYS_STATISTICS_LID = 7,
    _NVRAM_EF_BAND_INFO_LID = 121,
    _NVRAM_EF_TST_FILTER_LID = 122,
    _NVRAM_EF_PORT_SETTING_LID = 123,
    _NVRAM_EF_SMSAL_SMS_LID = 154,
    _NVRAM_EF_SMSAL_MAILBOX_ADDR_LID = 155,
    _NVRAM_EF_SMSAL_COMMON_PARAM_LID = 156,
    _NVRAM_EF_SMSAL_SMSP_LID = 157,
    _NVRAM_EF_SMSAL_MWIS_LID = 158,
    _NVRAM_EF_CB_DEFAULT_CH_LID = 159,
    _NVRAM_EF_CB_CH_INFO_LID = 160,
    _NVRAM_EF_TCM_PDP_PROFILE_LID = 147,
    _NVRAM_EF_CFU_FLAG_LID = 148,
    _NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID = 149,
    _NVRAM_EF_ALS_LINE_ID_LID = 151,
    _NVRAM_EF_MSCAP_LID = 152,
    _NVRAM_EF_CLASSMARK_RACAP_LID = 125,
    _NVRAM_EF_SIM_ASSERT_LID = 126,
    _NVRAM_EF_RTC_DATA_LID = 127,
    _NVRAM_EF_NET_PAR_LID = 128,
    _NVRAM_EF_CSM_ESSP_LID = 171,
    _NVRAM_EF_CUST_HW_LEVEL_TBL_LID = 138,
    _NVRAM_EF_UEM_MANUFACTURE_DATA_LID = 139,
    _NVRAM_EF_UEM_RMI_DATA_LID = 140,
    _NVRAM_EF_GPS_SETTING_DATA_LID = 141,
    _NVRAM_EF_MS_SECURITY_LID = 164,
    _NVRAM_EF_PHB_LN_ENTRY_LID = 166,
    _NVRAM_EF_PHB_LN_TYPE_SEQ_LID = 167,
    _NVRAM_EF_SYS_CACHE_OCTET_LID = 173,
    _NVRAM_EF_RAC_PREFERENCE_LID = 177,
    _NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID = 168,
    _NVRAM_EF_TST_CONFIG_LID = 180,
    _NVRAM_EF_AT_PROFILE_LID = 187,
    _NVRAM_EF_USR_PWR_CLS_LID = 188,
    _NVRAM_EF_ADC_LID = 2560,
    _NVRAM_EF_TOUCHPANEL_PARA_LID = 2816,
    NVRAM_TRC_LID_TOTAL
}nvram_trc_lid_enum;
