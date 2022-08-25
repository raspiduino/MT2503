/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2008]. All rights reserved.
*
*************************************************************************/ 
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mtk_gps.h
 *
 * Description:
 * ------------
 *   Prototype of MTK navigation library
 *
 ****************************************************************************/

#ifndef MTK_GPS_H
#define MTK_GPS_H


#include "mtk_gps_type.h"

/*function mtk_sys_xxx() for 3326 */
#ifdef __GPS_MT3326__ 
#include "mtk_gps_sys_wrap.h" 
#endif


#ifdef __cplusplus
  extern "C" {
#endif



/* ================= Application layer functions ================= */

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_init
 * DESCRIPTION
 *  Initialize MTK Nav Library
 * PARAMETERS
 *  start_type      [IN]  auto/warm/cold/factory start
 *  default_cfg     [IN]  factory default configuration
 * RETURNS
 *  mtk_gps_boot_status
 *****************************************************************************/
 #ifdef __GPS_MT3326__
    mtk_int32
#else
    mtk_gps_boot_status
#endif
mtk_gps_init (mtk_gps_start_type start_type, const mtk_init_cfg* default_cfg);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_run
 * DESCRIPTION
 *  The main routine for the MTK Nav Library task
 * PARAMETERS
 *  application_cb      [IN]
 *  default_cfg     [IN]  factory default configuration 
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/

#ifdef __GPS_MT3326__
    mtk_int32
    mtk_gps_run (mtk_gps_callback application_cb);
#else
    mtk_int32
    mtk_gps_run (mtk_gps_callback application_cb, const mtk_init_cfg* default_cfg);

#endif


/*****************************************************************************
 * FUNCTION
 *  mtk_gps_uninit
 * DESCRIPTION
 *  Free the resources used by MTK Nav Library
 *****************************************************************************/
void
mtk_gps_uninit (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_update_gps_data
 * DESCRIPTION
 *  Force to write NV-RAM data to storage file
 * PARAMETERS
 *
 * RETURNS
 *   success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_update_gps_data (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_data_input
 * DESCRIPTION
 *
 * PARAMETERS
 *  buffer      [IN] the content of the gps measuremnt
 *  length      [IN] the length of the gps measurement
 *  p_accepted_length [OUT]  indicate how many data was actually accepted into library
 *                          if this value is not equal to length, then it means library internal
 *                          fifo is full, please let library task can get cpu usage to digest input data
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_data_input (const char* buffer, mtk_uint32 length, mtk_uint32* p_accepted_length);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_rtcm_input
 * DESCRIPTION
 *  accept RTCM differential correction data
 * PARAMETERS
 *  buffer      [IN]   the content of RTCM data
 *  length      [IN]   the length of RTCM data (no more than 1KB)
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_rtcm_input (const char* buffer, mtk_uint32 length);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_nmea_input
 * DESCRIPTION
 *  accept NMEA (PMTK) sentence raw data
 * PARAMETERS
 *  buffer      [IN]   the content of NMEA (PMTK) data
 *  length      [IN]   the length of NMEA (PMTK) data
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32 
mtk_gps_nmea_input (const char* buffer, mtk_uint32 length);


/* ====================== Utility functions ====================== */
/*  These functions must be used in application_cb() callback
    function specified in mtk_gps_run()                            */

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_position
 * DESCRIPTION
 *  obtain detailed fix information
 * PARAMETERS
 *  pvt_data    [OUT]  pointer to detailed fix information
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_get_position (mtk_gps_position* pvt_data);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_sv_info
 * DESCRIPTION
 *  obtain detailed information of all satellites
 * PARAMETERS
 *  sv_data     [OUT]  pointer to satellites information
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_get_sv_info (mtk_gps_sv_info* sv_data);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_gleo_sv_info
 * DESCRIPTION
 *  obtain detailed information of all satellites for GALIILEO
 * PARAMETERS
 *  sv_data     [OUT]  pointer to satellites information
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_get_gleo_sv_info (mtk_gleo_sv_info* sv_gleo_data);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_glon_sv_info
 * DESCRIPTION
 *  obtain detailed information of all satellites for GALIILEO
 * PARAMETERS
 *  sv_data     [OUT]  pointer to satellites information
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_get_glon_sv_info (mtk_glon_sv_info* sv_glon_data);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_bedo_sv_info
 * DESCRIPTION
 *  obtain detailed information of all satellites for GALIILEO
 * PARAMETERS
 *  sv_data     [OUT]  pointer to satellites information
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_get_bedo_sv_info(mtk_bedo_sv_info* sv_bedo_data);
/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_param
 * DESCRIPTION
 *  Get the current setting of the GPS receiver
 * PARAMETERS
 *  key         [IN]   the configuration you want to know
 *  value       [OUT]  the current setting
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 * EXAMPLE
 *  // get the current DGPS mode
 *  mtk_param_dgps_config param_dgps_config;
 *  mtk_gps_get_param(MTK_PARAM_DGPS_CONFIG, &param_dgps_config);
 *  printf("DGPS mode=%d", (int)param_dgps_config.dgps_mode);
 *****************************************************************************/
mtk_int32
mtk_gps_get_param (mtk_gps_param key, void* value);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_param
 * DESCRIPTION
 *  Change the behavior of the GPS receiver
 * PARAMETERS
 *  key         [IN]   the configuration needs to be changed
 *  value       [IN]   the new setting
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_set_param (mtk_gps_param key, const void* value);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_pmtk_data
 * DESCRIPTION
 *  send PMTK command to GPS receiver
 * PARAMETERS
 *  prPdt       [IN]   pointer to the data structure of the PMTK command
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_set_pmtk_data (const MTK_PMTK_DATA_T *prPdt);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_pmtk_response
 * DESCRIPTION
 *  obtain detailed information of PMTK response
 * PARAMETERS
 *  rs_data     [OUT]  pointer to PMTK response data
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_get_pmtk_response (MTK_PMTK_RESPONSE_T *prRsp);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_position
 * DESCRIPTION
 *  Set the receiver's initial position
 *  Notes: To make the initial position take effect, please invoke restart
 *         (hot start/warm start) after this function
 * PARAMETERS
 *  LLH         [IN]  LLH[0]: receiver latitude in degrees (positive for North)
 *                    LLH[1]: receiver longitude in degrees (positive for East)
 *                    LLH[2]: receiver WGS84 height in meters
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_set_position (const double LLH[3]);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_time
 * DESCRIPTION
 *  Set the current GPS time
 *  Note:       The time will not be set if the receiver has better knowledge
 *              of the time than the new value.
 * PARAMETERS
 *  weekno      [IN]   GPS week number (>1024)
 *  TOW         [IN]   time of week (in second; 0.0~684800.0)
 *  timeRMS     [IN]   estimated RMS error of the TOW value (sec^2)
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_set_time (mtk_uint16 weekno, double tow, float timeRMS);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_ephemeris
 * DESCRIPTION
 *  Upload ephemeris
 * PARAMETERS
 *  svid        [IN]   GPS satellite PRN (1~32)
 *  data        [IN]   binary ephemeris words from words 3-10 of subframe 1-3
 *                     all parity bits (bit 5-0) have been removed
 *                     data[0]: bit 13-6 of word 3, subframe 1
 *                     data[1]: bit 21-14 of word 3, subframe 1
 *                     data[2]: bit 29-22 of word 3, subframe 1
 *                     data[3]: bit 13-6 of word 4, subframe 1
 *                     ......
 *                     data[71]: bit 29-22 of word 10, subframe 3
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_set_ephemeris (mtk_uint8 svid, const char data[72]);
/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_tcxo_mode
 * DESCRIPTION
 *  Set MNL TCXO mode
 * PARAMETERS
 * 

 *  MTK_TCXO_NORMAL,  //normal mode 
 *  MTK_TCXO_PHONE    //phone mode

 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/

mtk_int32
mtk_gps_set_tcxo_mode (mtk_gps_tcxo_mode tcxo_mode);


/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_AIC_mode
 * DESCRIPTION
 *  Set AIC mode
 * PARAMETERS
 * 
 * disalbe = 0
 * enable = 1

 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/

mtk_int32
mtk_gps_set_AIC_mode (mtk_gps_aic_mode AIC_Enable);


/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_almanac
 * DESCRIPTION
 *  Upload almanac
 * PARAMETERS
 *  svid        [IN]   GPS satellite PRN (1~32)
 *  weekno      [IN]   the week number of the almanac data record
 *  data        [IN]   binary almanac words from words 3-10 of either subframe 4
 *                     pages 2-10 or subframe 5 pages 1-24
 *                     all parity bits (bit 5-0) have been removed
 *                     data[0]: bit 13-6 of word 3
 *                     data[1]: bit 21-14 of word 3
 *                     data[2]: bit 29-22 of word 3
 *                     data[3]: bit 13-6 of word 4
 *                     ......
 *                     data[23]: bit 29-22 of word 10
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_set_almanac (mtk_uint8 svid, mtk_uint16 weekno, const char data[24]);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_ephemeris
 * DESCRIPTION
 *  Download ephemeris
 * PARAMETERS
 *  svid        [IN]   GPS satellite PRN (1~32)
 *  data        [OUT]  binary ephemeris words from words 3-10 of subframe 1-3
 *                     all parity bits (bit 5-0) have been removed
 *                     data[0]: bit 13-6 of word 3, subframe 1
 *                     data[1]: bit 21-14 of word 3, subframe 1
 *                     data[2]: bit 29-22 of word 3, subframe 1
 *                     data[3]: bit 13-6 of word 4, subframe 1
 *                     ......
 *                     data[71]: bit 29-22 of word 10, subframe 3
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_get_ephemeris (mtk_uint8 svid, char data[72]);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_almanac
 * DESCRIPTION
 *  Download almanac
 * PARAMETERS
 *  svid        [IN]   GPS satellite PRN (1~32)
 *  p_weekno    [OUT]  pointer to the week number of the almanac data record
 *  data        [OUT]  binary almanac words from words 3-10 of either subframe 4
 *                     pages 2-10 or subframe 5 pages 1-24
 *                     all parity bits (bit 5-0) have been removed
 *                     data[0]: bit 13-6 of word 3
 *                     data[1]: bit 21-14 of word 3
 *                     data[2]: bit 29-22 of word 3
 *                     data[3]: bit 13-6 of word 4
 *                     ......
 *                     data[23]: bit 29-22 of word 10
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_get_almanac (mtk_uint8 svid, mtk_uint16* p_weekno, char data[24]);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_clear_ephemeris
 * DESCRIPTION
 *  clear the ephemeris of the specified PRN
 * PARAMETERS
 *  svid        [IN]   GPS satellite PRN (1~32)
 *****************************************************************************/
void
mtk_gps_clear_ephemeris (mtk_uint8 svid);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_clear_almanac
 * DESCRIPTION
 *  clear the almanac of the specified PRN
 * PARAMETERS
 *  svid        [IN]   GPS satellite PRN (1~32)
 *****************************************************************************/
void
mtk_gps_clear_almanac (mtk_uint8 svid);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_sbas_msg_amount
 * DESCRIPTION
 *  Get the number of SBAS message blocks received in this epoch.
 *  Later on, please use mtk_gps_get_sbas_msg() to get the message 
 *  content one by one.
 * PARAMETERS
 *  p_msg_amount  [OUT]   The number of SBAS message blocks received in this epoch
 * RETURNS
 *  
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_get_sbas_msg_amount (mtk_uint32* p_msg_amount);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_sbas_msg
 * DESCRIPTION
 *  After calling mtk_gps_get_sbas_msg_amount(), we know the
 *  number of SBAS messages received in this epoch.
 *  mtk_gps_get_sbas_msg() gives a way to access each message
 *  data 
 * PARAMETERS
 *  index        [IN]   which message you want to read
 *  pSVID        [OUT]  the PRN of the SBAS satellite
 *  pMsgType     [OUT]  the SBAS message type
 *  pParityError [OUT]  nonzero(parity error); zero(parity check pass)
 *  data         [OUT]  The 212-bit message data excluding the preamble,
 *                      message type field, and the parity check.
 *                      Regarding to endian, the data[0] is the beginning the
 *                      message, such as IODP field. The data[26] is the end of
 *                      message, and the bit 3..0 are padding zero.
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 * EXAMPLE
 *   //dump the SBAS message to UART output
 *   int  i, count; 
 *   unsigned char PRN, MsgType, ParityError;
 *   char data[27];
 *
 *   mtk_gps_get_sbas_msg_amount(&count);
 *   for (i = 0; i < count; i++)
 *   {
 *      mtk_gps_get_sbas_msg(i, &PRN, &MsgType, &ParityError, data);
 *   }
 *****************************************************************************/
mtk_int32
mtk_gps_get_sbas_msg (mtk_int32 index, unsigned char* pSVID,
     unsigned char* pMsgType, unsigned char* pParityError, char data[27]);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_chn_status
 * DESCRIPTION
 *  Get Channel SNR and Clock Drift Status in Channel Test Mode
 * PARAMETERS
 *  ChnSNR       [OUT]  Channel SNR
 *  ClkDrift     [OUT]  Clock Drift
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *  if you do not enter test mode first or Channel tracking not ready,
 *  return MTK_GPS_ERROR
 *****************************************************************************/
 #ifdef __GPS_MT3326__

mtk_int32
    mtk_gps_get_chn_test(float ChnSNR[16], float *ClkDrift);
 #endif
 #ifdef __GPS_MT3332__
mtk_int32

mtk_gps_get_chn_test(mtk_r4 ChnSNR[16], float *ClkDrift);
#else
mtk_int32
    mtk_gps_get_chn_test(mtk_uint8 ChnSNR[16], float *ClkDrift);
#endif
/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_glonass_chn_status
 * DESCRIPTION
 *  Get Channel SNR and Clock Drift Status in Channel Test Mode
 * PARAMETERS
 *  ChnSNR       [OUT]  Channel SNR
 *  ClkDrift     [OUT]  Clock Drift
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *  if you do not enter test mode first or Channel tracking not ready,
 *  return MTK_GPS_ERROR
 *****************************************************************************/
mtk_int32
mtk_gps_get_glonass_chn_test(mtk_r4 ChnSNR[3]);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_jammer_test
 * DESCRIPTION
 *  Obtain the CW jammer estimation result
 * PARAMETERS
 *  Freq         [OUT]  jammer frequency offset in KHz
 *  JNR          [OUT]  JNR of the associated jammer
 *  jammer_peaks [OUT]  The number (0~195) of jammer peaks if ready
 *                      0 means no jammer detected
 *                      Negative if not ready
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_get_jammer_test(mtk_int32 *jammer_peaks, short Freq[195], mtk_uint16 JNR[195]);


//jiawangask
#ifdef __GPS_MT3326__
/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_jammer_test
 * DESCRIPTION
 *  Enter or leave Jammer Test Mode
 * PARAMETERS
 *  action       [IN]   1 = enter Jammer test; 0 = leave Jammer test, not ready
 *  mode         [IN]   0 = IF spectrum (old version); 1 = baseband JNR tool (new version)
 *  arg          [IN]   unused
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
*****************************************************************************/
mtk_int32
mtk_gps_set_jammer_test(mtk_int32 action, mtk_uint8 SVid, mtk_uint16 range);

#else
/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_jammer_test
 * DESCRIPTION
 *  Enter or leave Jammer Test Mode
 * PARAMETERS
 *  action [IN]   1 = enter Jammer test(old); 2 = enter Jammer test(new); 0 = leave Jammer test
 *  SVid [IN] please assign any value between 1~32
 *  range [IN] no use in new jammer scan, any value is ok.
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
*****************************************************************************/

mtk_int32
mtk_gps_set_jammer_test(mtk_int32 action, mtk_uint16 mode, mtk_uint16 arg);

#endif

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_phase_test
 * DESCRIPTION
 *  Obtain the last phase error calibration result
 * PARAMETERS
 *  result       [OUT]  0~64 (success)
 *                      Negative (failure or not ready)
 *                      The return value is 64*{|I|/sqrt(I*I + Q*Q)}
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_get_phase_test(mtk_int32 *result);


//*************************************************************************************
// mtk_gps_get_sat_accurate_snr  :  Get the accurate SNR of all satellites
//
//    Note  :  SNR is an array with 32 float.
// Example:
//    float SNR[32];
//    mtk_gps_get_sat_accurate_snr(SNR);
//    //Get SNR of SV 17
//    MTK_UART_OutputData("SV17: SNR = %lf", SNR[16]);
//    
// =====> SV17: SNR = 38.1

void mtk_gps_get_sat_accurate_snr(mtk_r4 SNR[32]);
//*************************************************************************************
// mtk_gps_get_glon_sat_accurate_snr  :  Get the accurate SNR of all GLONASS satellites
//
//    Note  :  SNR is an array with [24] float.
// Example:
//    float SNR[24];
//    mtk_gps_get_glon_sat_accurate_snr(SNR);
//    //Get SNR of SV 1
//    MTK_UART_OutputData("GLON,SV1: SNR = %lf", SNR[0]);
//    
// =====>GLON,SV1: SNR = 38.1

void mtk_gps_get_glon_sat_accurate_snr ( float ASNR[24] );

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_set_per_test
 * DESCRIPTION
 *   Enable PER test, and output data in mtk_gps_sys_data_output_dbg
 * PARAMETERS
 *  Threshold       [IN]   power of 2 (1,2,4,8,...)
 *  SVid               [IN]   SVid for PER test that can be tracked in sky
 *  TargetCount   [IN]   Test time in 20ms unit
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_set_per_test(mtk_int16 Threshold, mtk_uint16 SVid, mtk_uint16 TargetCount);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_time_change_notify
 * DESCRIPTION
 *  Notify MNL to handle RTC time change
 * PARAMETERS
 *  i4RtcDiff      [IN]  System RTC time changed: old rtc time - new rtc time
 * RETURNS
 *  
 *****************************************************************************/
void
mtk_gps_time_change_notify(mtk_int32 i4RtcDiff);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_get_rtc_offset
 * DESCRIPTION
 *  Notify MNL to handle RTC time change
 * PARAMETERS
 *  r8RtcOffset      [OUT]  System RTC time changed
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_get_rtc_offset(mtk_r8 *r8RtcOffset);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_time_update_notify
 * DESCRIPTION
 *  Notify MNL to handle RTC time change
 * PARAMETERS
 *  fgSyncGpsTime      [IN]  System time sync to GPS time
 *  i4RtcDiff      [IN]  Difference of system RTC time changed
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_time_update_notify(mtk_uint8 fgSyncGpsTime, mtk_int32 i4RtcDiff);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_debug_config
 * DESCRIPTION
 *  config the debug log type and level
 * PARAMETERS
 *  DbgType         [IN]  Debug message category
 *  DbgLevel        [IN]  Debug message output level
 *
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/

mtk_int32
mtk_gps_debug_config(mtk_gps_dbg_type DbgType, mtk_gps_dbg_level DbgLevel);

//*************************************************************************************//
// mtk_gps_get_assist_bitmap  :  Get  assist bitmap 
// input: none
// output: return mtk_int16  
//   32-bit assist bitmap:
// #define ASSIST_BIT_ALM   0x0001  // Satellite Almanac
// #define ASSIST_BIT_UCP   0x0002  // UTC Model
// #define ASSIST_BIT_KLB   0x0004  // Ionospheric Model
// #define ASSIST_BIT_EPH   0x0008  // Navigation Model
// #define ASSIST_BIT_DGPS 0x0010  // DGPS Corrections
// #define ASSIST_BIT_LOC   0x0020  // Reference Location
// #define ASSIST_BIT_TIME  0x0040  // Reference Time
// #define ASSIST_BIT_ACQ  0x0080  // Acquisition Assistance
// #define ASSIST_BIT_BSV   0x0100  // Real-Time Integrity
// #define ASSIST_BIT_EPO   0x0200  // Real-Time Integrity
mtk_uint16 
mtk_gps_get_assistance_bitmap(void);


/* =================== Porting layer functions =================== */
/*            The function body needs to be implemented            */

/*****************************************************************************
* FUNCTION
*  mtk_gps_sys_time_tick_get
* DESCRIPTION
*  get the current system tick of target platform (msec)
* PARAMETERS
*  none
* RETURNS
*  system time tick
*****************************************************************************/
mtk_uint32
mtk_gps_sys_time_tick_get (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_time_tick_get_max
 * DESCRIPTION
 *  get the maximum system tick of target platform (msec)
 * PARAMETERS
 *  none
 * RETURNS
 *  system time tick
 *****************************************************************************/
mtk_uint32
mtk_gps_sys_time_tick_get_max (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_time_read
 * DESCRIPTION
 *  Read system time
 * PARAMETERS
 *  utctime     [IN/OUT] get the host system time
 * RETURNS
 *  success (MTK_GPS_SUCCESS)
 *  failed (MTK_GPS_ERROR)
 *  system time changed since last call (MTK_GPS_ERROR_TIME_CHANGED)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_time_read (mtk_time* utctime);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_task_sleep
 * DESCRIPTION
 *  Task sleep function
 * PARAMETERS
 *  milliseconds [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_task_sleep (mtk_uint32 milliseconds);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_storage_open
 * DESCRIPTION
 *  Open a non-volatile file
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_storage_open (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_storage_close
 * DESCRIPTION
 *  Close a non-volatile file
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_storage_close (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_storage_delete
 * DESCRIPTION
 *  Delete a non-volatile file  
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_storage_delete (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_storage_read
 * DESCRIPTION
 *  Read a non-volatite file 
 *  - blocking read until reaching 'length' or EOF
 * PARAMETERS
 *  buffer      [OUT]
 *  offset      [IN]
 *  length      [IN]
 *  p_nRead     [OUT]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_storage_read (void* buffer, mtk_uint32 offset, mtk_uint32 length,
                      mtk_uint32* p_nRead);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_storage_write
 * DESCRIPTION
 *  Write a non-volatite file
 * PARAMETERS
 *  buffer      [IN]
 *  offset      [IN]
 *  length      [IN]
 *  p_nWritten  [OUT]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_storage_write (const void* buffer, mtk_uint32 offset, mtk_uint32 length,
                       mtk_uint32* p_nWritten);


#if 1//Hiki, modify
/*****************************************************************************
* FUNCTION
*  mtk_gps_sys_event_delete
* DESCRIPTION
*  event delete 
* PARAMETERS
*  event_idx         [IN] mtk_gps_event_enum
* RETURNS
*  success(MTK_GPS_SUCCESS)
*****************************************************************************/
mtk_int32
mtk_gps_sys_event_delete(mtk_gps_event_enum event_idx);

/*****************************************************************************
* FUNCTION
*  mtk_gps_sys_event_create
* DESCRIPTION
*  event create for Android
* PARAMETERS
*  event_idx         [IN] mtk_gps_event_enum
* RETURNS
*  success(MTK_GPS_SUCCESS)
*****************************************************************************/
mtk_int32
mtk_gps_sys_event_create(mtk_gps_event_enum event_idx);

/*****************************************************************************
* FUNCTION
*  mtk_gps_sys_event_set
* DESCRIPTION
*  event set for Android
* PARAMETERS
*  event_idx         [IN] mtk_gps_event_enum
* RETURNS
*  success(MTK_GPS_SUCCESS)
*****************************************************************************/
mtk_int32
mtk_gps_sys_event_set(mtk_gps_event_enum event_idx);

/*****************************************************************************
* FUNCTION
*  mtk_gps_sys_event_wait
* DESCRIPTION
*  event wait for android
*  
* PARAMETERS
*  event_idx         [IN] mtk_gps_event_enum
* RETURNS
*  success(MTK_GPS_SUCCESS)
*****************************************************************************/
mtk_int32
mtk_gps_sys_event_wait(mtk_gps_event_enum event_idx); 

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_uart_init
 * DESCRIPTION
 *  Initiialize UART 
 * PARAMETERS
 *  portname      [IN]
 *  baudrate      [IN]
 *  txbufsize      [IN]
 *  rxbufsize      [IN]
 * RETURNS
 *  Result of Handler 
 *****************************************************************************/
mtk_int32
mtk_gps_sys_uart_init(char* portname, mtk_uint32 baudrate, mtk_uint32 txbufsize,  
                      mtk_uint32 rxbufsize);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_uart_read
 * DESCRIPTION
 *  Initiialize UART 
 * PARAMETERS
 *  UARTHandle  [IN]
 *  buffer      [IN]
 *  bufsize     [IN]
 *  length      [IN]
 * RETURNS
 *  Result of Handler 
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_uart_read(mtk_int32 UARTHandle, char* buffer, mtk_uint32 bufsize,
                      mtk_int32* length);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_uart_write
 * DESCRIPTION
 *  Initiialize UART 
 * PARAMETERS
 *  UARTHandle  [IN]
 *  buffer      [IN]
 *  bufsize     [IN]
 *  length      [IN]
 * RETURNS
 *  Result of Handler 
 *****************************************************************************/
mtk_int32  
mtk_gps_sys_uart_write(mtk_int32 UARTHandle, const char* buffer, mtk_uint32 bufsize,
                       mtk_int32* wrotenlength);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_uart_uninit
 * DESCRIPTION
 *  Initiialize UART 
 * PARAMETERS
 *  UARTHandle      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_uart_uninit(mtk_int32 UARTHandle);	//change return param type "void" to "mtk_int32"

/*****************************************************************************
* FUNCTION
*  mtk_gps_sys_nmea_output_to_app
* DESCRIPTION
*  Transmit NMEA data out to APP layer
*  (The function body needs to be implemented)
* PARAMETERS
*  buffer         [IN] data pointer
*  length         [IN] size of data
* RETURNS
*  success(MTK_GPS_SUCCESS)
*****************************************************************************/
mtk_int32
mtk_gps_sys_nmea_output_to_app(const char * buffer, mtk_uint32 length);
#endif

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_msg_cnt
 * DESCRIPTION
 *
 * PARAMETERS
 * RETURNS
 *  message count of main GPS thread
 *****************************************************************************/
mtk_int32
mtk_gps_sys_msg_cnt (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_msg_init
 * DESCRIPTION
 *  Initialize mnl's message queue
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_msg_init (void);


/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_msg_recv
 * DESCRIPTION
 *  Receive a message from main GPS thread
 * PARAMETERS
 *  msg         [OUT]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_msg_recv (mtk_gps_msg** msg);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_msg_send
 * DESCRIPTION
 *  Send a message to main GPS thread
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_msg_send (const mtk_gps_msg* msg);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_msg_alloc
 * DESCRIPTION
 *  Allocate a block of memory for message
 * PARAMETERS
 *  size        [IN]   the length of the whole mtk_gps_msg structure
 * RETURNS
 *  pointer to the created message if succeeded
 *  NULL (0) if failed
 *****************************************************************************/
mtk_gps_msg*
mtk_gps_sys_msg_alloc (mtk_uint16 size);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_msg_free
 * DESCRIPTION
 *  Free a block of memory for message
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_msg_free (mtk_gps_msg* msg);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_mem_alloc
 * DESCRIPTION
 *  Allocate a block of memory
 * PARAMETERS
 *  size        [IN]   the length of the whole memory to be allocated
 * RETURNS
 *  On success, return the pointer to the allocated memory
 *  NULL (0) if failed
 *****************************************************************************/
void*
mtk_gps_sys_mem_alloc (mtk_uint32 size);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_mem_free
 * DESCRIPTION
 *  Release unused memory
 * PARAMETERS
 *  pmem         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_mem_free (void* pmem);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_agps_msg_init
 * DESCRIPTION
 *  Initialize mnl's message queue
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_agps_msg_init (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_agps_msg_recv
 * DESCRIPTION
 *  Receive a message from main GPS thread
 * PARAMETERS
 *  msg         [OUT]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_agps_msg_recv (mtk_gps_msg** msg);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_agps_msg_send
 * DESCRIPTION
 *  Send a message to main GPS thread
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_agps_msg_send (const mtk_gps_msg* msg);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_agps_msg_alloc
 * DESCRIPTION
 *  Allocate a block of memory for message
 * PARAMETERS
 *  size        [IN]   the length of the whole mtk_gps_msg structure
 * RETURNS
 *  pointer to the created message if succeeded
 *  NULL (0) if failed
 *****************************************************************************/
mtk_gps_msg*
mtk_gps_sys_agps_msg_alloc (mtk_uint16 size);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_agps_msg_free
 * DESCRIPTION
 *  Free a block of memory for message
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_agps_msg_free (mtk_gps_msg* msg);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_data_output
 * DESCRIPTION
 *  Transmit data to the GPS chip
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  msg         [IN]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_data_output (char* buffer, mtk_uint32 length);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_data_output_dbg
 * DESCRIPTION
 *  Transmit debug data out to task
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  buffer         [IN] data pointer
 *  length         [IN] size of data
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_data_output_dbg (char* buffer, mtk_uint32 length);

/*****************************************************************************
* FUNCTION
*  mtk_gps_sys_nmea_output
* DESCRIPTION
*  Transmit NMEA data out to task
*  (The function body needs to be implemented)
* PARAMETERS
*  buffer         [IN] data pointer
*  length         [IN] size of data
* RETURNS
*  success(MTK_GPS_SUCCESS)
*****************************************************************************/
mtk_int32
mtk_gps_sys_nmea_output (char* buffer, mtk_uint32 length);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_if_set_spd
 * DESCRIPTION
 *  Set baud rate at host side from GPS lib
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  baudrate         [IN] UART baudrate 
 *  hw_fc            [IN] UART hardware flow control 
 *                        0: without hardware flow contorl (defualt)
 *                        1: with hardware flow contorl
 * RETURNS
 *  success(0)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_if_set_spd (mtk_uint32 baudrate, mtk_uint8 hw_fc);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_spi_poll
 * DESCRIPTION
 *  Polling data input routine for SPI during dsp boot up stage.
 *  If use UART interface, this function can do nothing at all.
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  void
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_spi_poll(void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_set_spi_mode
 * DESCRIPTION
 *  Set SPI interrupt/polling and support burst or not.
 *  If use UART interface, this function can do nothing at all.
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  enable_int         [IN]  1 for enter interrupt mode , 0 for entering polling mode
 *  enable_burst       [IN]  1 for enable burst transfer, 0 for disable burst transfer
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_set_spi_mode(mtk_uint8 enable_int, mtk_uint8 enable_burst);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_epo_open
 * DESCRIPTION
 *  Open EPO file
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_epo_open (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_epo_close
 * DESCRIPTION
 *  Close EPO file
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_epo_close (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_epo_read
 * DESCRIPTION
 *  Read EPO file
 *  (blocking read until reaching 'length' or EOF)
 * PARAMETERS
 *  buffer      [OUT]
 *  offset      [IN]
 *  length      [IN]
 *  p_nRead     [OUT]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_epo_read (void* buffer, mtk_uint32 offset, mtk_uint32 length,
                      mtk_uint32* p_nRead);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_initialize_mutex
 * DESCRIPTION
 *  Inialize mutex array
 * PARAMETERS
 *  void
  * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_initialize_mutex(void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_create_mutex
 * DESCRIPTION
 *  Create a mutex object
 * PARAMETERS
 *  mutex_num        [IN]  mutex index used by MTK Nav Library
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_create_mutex(mtk_mutex_enum mutex_idx);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_take_mutex
 * DESCRIPTION
 *  Request ownership of a mutex and if it's not available now, then block the thread execution
 * PARAMETERS
 *  mutex_num        [IN]  mutex index used by MTK Nav Library
 * RETURNS
 *  void
 *****************************************************************************/
mtk_int32
mtk_gps_sys_take_mutex(mtk_mutex_enum mutex_idx);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_give_mutex
 * DESCRIPTION
 *  Release a mutex ownership
 * PARAMETERS
 *  mutex_num        [IN]  mutex index used by MTK Nav Library
 * RETURNS
 *  void
 *****************************************************************************/
mtk_int32
mtk_gps_sys_give_mutex(mtk_mutex_enum mutex_idx);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_destroy_mutex
 * DESCRIPTION
 *  Destroy a mutex object
 * PARAMETERS
 *  mutex_num        [IN]  mutex index used by MTK Nav Library
 * RETURNS
 *  success(MTK_GPS_SUCCESS); failure (MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32
mtk_gps_sys_destroy_mutex(mtk_mutex_enum mutex_idx);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_pmtk_cmd_cb
 * DESCRIPTION
 *  Notify porting layer that MNL has received one PMTK command.
 * PARAMETERS
 *  u2CmdNum        [IN]  The received PMTK command number.
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_sys_pmtk_cmd_cb(mtk_uint16 u2CmdNum);

 /*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_uart_poll
 * DESCRIPTION
 *  GPS RX polling function 
 * PARAMETERS
 *  void
 * RETURNS
 *  success(0)
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_uart_poll(void);

#if 1//Hiki, move back MAUI specific porting layer function
/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_start_result_handler
 * DESCRIPTION
 *  Handler routine for the result of restart command
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  result         [IN]  the result of restart
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_start_result_handler(mtk_gps_start_result result);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_dsp_boot_begin_handler
 * DESCRIPTION
 *  Handler routine for porting layer implementation right before GPS DSP boot up
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  none
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_dsp_boot_begin_handler(void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_dsp_boot_end_handler
 * DESCRIPTION
 *  Handler routine for porting layer implementation right after GPS DSP boot up
 *  (The function body needs to be implemented)
 * PARAMETERS
 *  none
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_dsp_boot_end_handler(void);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_frame_sync_meas_req
 * DESCRIPTION
 *  issue a frame sync measurement request
 * PARAMETERS
 *  mode       [out] frame sync request indication for aiding or maintain
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *  fail(MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_frame_sync_meas_req(mtk_gps_fs_work_mode mode);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_frame_sync_meas_req_by_network
 * DESCRIPTION
 *  issue a frame sync measurement request
 * PARAMETERS
 *  none
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *  fail(MTK_GPS_ERROR)
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_frame_sync_meas_req_by_network(void);
/*****************************************************************************
 * FUNCTION
 *  gps_frame_sync_meas_req_by_utran
 * DESCRIPTION
 *  issue a frame sync measurement request
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
void gps_frame_sync_meas_req_by_utran(mtk_bool mode);

/*****************************************************************************
 * FUNCTION
 *  gps_frame_sync_meas_req_by_ftime
 * DESCRIPTION
 *  issue a frame sync measurement request
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
void gps_frame_sync_meas_req_by_ftime(mtk_bool mode);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_frame_sync_ftime_diff
 * DESCRIPTION
 *  calculate ftime difference between two frame sync request
 * PARAMETERS
 *  none
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *  fail(MTK_GPS_ERROR)
 *****************************************************************************/
mtk_r8 
mtk_gps_sys_frame_sync_ftime_diff(mtk_r8 dfFTime_New, mtk_r8 dfFTime_Old);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_frame_sync_ftime_diff_by_network
 * DESCRIPTION
 *  calculate ftime difference between two frame sync request
 * PARAMETERS
 *  none
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *  fail(MTK_GPS_ERROR)
 *****************************************************************************/
mtk_r8 
mtk_gps_sys_frame_sync_ftime_diff_by_network(mtk_r8 dfFTime_New, mtk_r8 dfFTime_Old);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_frame_sync_meas_resp
 * DESCRIPTION
 *  accept a frame sync measurement response
 * PARAMETERS
 *  eResult     [IN] success to issue a frame sync meas request
 *  dfFrameTime [IN] frame time of the issued frame pulse (seconds) 
 * RETURNS
 *  void
 *****************************************************************************/
void
mtk_gps_frame_sync_meas_resp(mtk_gps_fs_result eResult, mtk_r8 dfFrameTime);

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_frame_sync_enable_sleep_mode
 * DESCRIPTION
 *  enable/disable modem sleep mode
 * PARAMETERS
 *  mode        [IN] 0: sleep mode disable
 *                   1: sleep mode enable
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
mtk_int32 
mtk_gps_sys_frame_sync_enable_sleep_mode(mtk_bool mode);
#endif

#ifdef __cplusplus
   }
#endif

#endif /* MTK_GPS_H */
