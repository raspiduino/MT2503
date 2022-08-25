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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * ddload.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Dynamic Download for DSP(MT6218 and later)
 *
 * Author:
 * -------
 * -------
 *
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
 * removed!
 *
 * removed!
 *******************************************************************************/
#ifndef  _DDLOAD_H_
#define  _DDLOAD_H_

typedef struct{
   int        Dsp_Start_Addr;
   const char *Array_Addr;
   int        Array_Len;
}DLL_Func;

typedef struct{
   const DLL_Func *dspFunc;
   const char *Compressed_Array_Addr;
   int        Compressed_Array_Len;
}DLL_FuncCompress;

typedef struct{
   DLL_Func dll;
   unsigned char isAlloc;
}DLL_FuncGen;

/* ------------------------------------------------------------------------- */

#define DPCHIP_DUAL_DSP            (                                                                            \
                                    defined(MT6235) || defined(MT6235B) ||defined(MT6238)  || defined(MT6239) \
                                    || defined(MT6268)                                        \
                                    || defined(MT6253) || defined(MT6253L) || defined(MT6253E) \
                                    || defined(MT6252) || defined(MT6252H) \
                                    || defined(MT6236) || defined(MT6236B) \
                                    || defined(TK6516) || defined(MT6516)  \
                                    || defined(MT6256_S00) || defined(MT6251) \
                                    )

#define DPCHIP_SINGLE_DSP           ( defined(MT6255)  || defined(MT6250)  || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) ) 

#define DPCHIP_CACHE_DSP            defined(MT6256_S01)

#define DPCHIP_BASE_MT6235          (  defined(MT6235) || defined(MT6235B) )

#define DPCHIP_IDMA_AUDIOHEADER   DPCHIP_DUAL_DSP || DPCHIP_SINGLE_DSP
#define DPCHIP_DDL_AUDIO_SUPPORT  ! (defined(TK6516) || defined(MT6516))


#define DPCHIP_DDL_AMRSBC         ( ((DPCHIP_DUAL_DSP) && !( defined(MT6253) || defined(MT6252) || defined(MT6251) || defined(MT6252H) ) ) || \
                                    DPCHIP_CACHE_DSP \
                                  ) 

#define DPCHIP_DDL_AWB            ( ((DPCHIP_DUAL_DSP ) && !(defined(MT6268) || defined(MT6251) || defined(MT6253L) || defined(MT6253E) || defined(MT6252) || defined(MT6252H)  ) ) || \
                                    DPCHIP_CACHE_DSP \
                                  )


#define DPCHIP_DDL_AWB_PM         ( ((DPCHIP_DUAL_DSP ) && !(defined(MT6268) || defined(MT6251) || defined(MT6253L) || defined(MT6253E) || defined(MT6252) || defined(MT6252H)  ) ) || \
                                    DPCHIP_CACHE_DSP || DPCHIP_SINGLE_DSP\
                                  )

#define DPCHIP_DDL_WT             (DPCHIP_DUAL_DSP)

#define DPCHIP_DDL_WMA_V2         (                                                                                                   \
                                   ( (DPCHIP_DUAL_DSP) && !( defined(MT6251) || defined(MT6253L) || defined(MT6253E) || defined(MT6252) || defined(MT6252H)  ) )    \
                                  )

#define DPCHIP_DDL_AAC            ( DPCHIP_DUAL_DSP || DPCHIP_CACHE_DSP || DPCHIP_SINGLE_DSP)

#define DPCHIP_DDL_AAC_PLUS       ( DPCHIP_DUAL_DSP )

#define DPCHIP_DDL_AAC_PLUS_PS    ( DPCHIP_DUAL_DSP )

#define DPCHIP_DDL_DAF            ( DPCHIP_DUAL_DSP )

                                  
#define DPCHIP_DDL_BSAC           ( defined(MT6235) || defined(MT6235B) || defined(MT6238)  ||  defined(MT6239) || \
                                    defined(MT6268) || defined(MT6236)  || defined(MT6236B) ||            \
                                    defined(MT6256_S00) )
#define DPCHIP_DDL_COOK           ( defined(MT6236) || defined(MT6236B) || defined(MT6252) || defined(MT6252H) || \
                                    defined(MT6253) || defined(MT6253E) )
                                  
#define DPCHIP_DDL_AUDIO_HUFFMAN_COSIM  ( defined(MT6253T) || defined(MT6253) || defined(MT6253L) || defined(MT6253E) || \
                                          defined(MT6252) || defined(MT6252H) || \
                                          defined(MT6236) || defined(MT6236B) || \
                                          defined(MT6256_S00) || defined(MT6251)  )

#define DPCHIP_DDL_AUDIO_AUDMA_COSIM  ( defined(MT6256_S00) )

#define DPCHIP_DDL_HANDSHAKE_IO_NOT_IO7 ( defined(MT6236) || defined(MT6236B) || defined(MT6251) || \
                                          defined(MT6253L) || defined(MT6253E) || defined(MT6252) || defined(MT6252H) || defined(MT6256_S00) || \
                                          DPCHIP_CACHE_DSP || DPCHIP_SINGLE_DSP )

#define DPCHIP_DDL_ABF                ( defined(MT6256_S00) )

#define DPCHIP_SHERIF_INTERNAL_DM_BASE  ( (DPCHIP_CACHE_DSP ) || DPCHIP_SINGLE_DSP )

#define DPCHIP_DDL_AUDIO_AAC_DM     ( defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) )

#define DPCHIP_DDL_AUDIO_DMREMAP_COSIM  ( defined(MT6250) )

#define SPH_ENH_DDLOAD_TWO_PARTS      (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))


/* ------------------------------------------------------------------------- */

#define CM_PAGE   4

#if defined(__CACHED_BASE_DSP__)
  #define CM_PAGE_TCH_DDL               8
#endif

#if defined(__CACHED_BASE_DSP__)
   //CM DDL page definition for cache-DSP
   //page index for cache-DSP
   #define CACHE_DSP_MEMTYPE_CM              0
   #define CACHE_DSP_MEMTYPE_PM              1
   #define CACHE_DSP_MEMTYPE_DM              2

   //CM page remap index of codec for cache-DSP
   #define CACHE_DSP_CM_REMAP_AMR            0
   #define CACHE_DSP_CM_REMAP_AAC            1
   #define CACHE_DSP_CM_REMAP_AWB            2
   #define CACHE_DSP_CM_REMAP_AWBDEC         3
   #define CACHE_DSP_CM_REMAP_COSIM          (CACHE_DSP_CM_REMAP_AAC+1)  //use special load
   
   //PM page remap index of codec for cache-DSP
   #define CACHE_DSP_PM_REMAP_AAC            0
   #define CACHE_DSP_PM_REMAP_AWB            1
   #define CACHE_DSP_PM_REMAP_COSIM          (CACHE_DSP_PM_REMAP_AAC+1)  //use special load
#endif

#if DPCHIP_DDL_AUDIO_AAC_DM
#if defined( MT6250 ) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define DSP_AUDIO_DM_TABLE_PAGE1               5
   #define DSP_AUDIO_DM_TABLE_PAGE2               6
 #endif  
#endif
/* ------------------------------------------------------------------------- */
#define  DDID_NONE                      0

#define  DDID_DAF                       1
#define  DDID_WAVETABLE                 3
#define  DDID_AMR_CC_SCHEDULE           4
#define  DDID_AAC                       5
#define  DDID_HEADER                    6
#define  DDID_AMRSBC                   14

#define  DDID_EES                     7
#define  DDID_AEC                     7
#define  DDID_NR                      7
#define  DDID_SBSD                    7
#define  DDID_AWB                    11

#if DPCHIP_DDL_WMA_V2
  #define  DDID_WMA_16OB_HighRate    12
  #define  DDID_WMA_44OB             13
  #define  DDID_WMA_44QB_HighRate    15
  #define  DDID_WMA_16OB_LowRate     16
  #define  DDID_WMA_44QB_LowRate     17
#endif

#define DDID_AAC_PLUS                   8
#define DDID_AAC_PLUS_PS               18
#define DDID_AWBDEC                    19
#define DDID_MUSICAM                   20
#define DDID_AWB_PLUS                  21
#define DDID_BSAC                      22
#define DDID_SBC                       23
#define DDID_AudioHeader               24
#define DDID_I2S                       25
#define DDID_COOK_256                  26
#define DDID_COOK_512                  27 
#define DDID_COOK_1024                 28
#define DDID_IPS                       29
#define DDID_VSG                       30
#define DDID_PCM                       31
#define DDID_Internal_AAC_SBR         252
#define DDID_Internal_WMA_44OB_2      253
#define DDID_Internal_ABF             254
#define DDID_Internal_Header_Kernal   255

#define DDID_HW_HUFFMAN_COSIM        5000     // Only for Hardware Huffman cosim
#define DDID_HW_AUDMA_COSIM          5001     // Only for Hardware AuDMA cosim
#define DDID_AUDIO_CACHE_REMAP       5002     // Only for Cache-DSP cosim remapping
#define DDID_AUDIO_DM_REMAP          5003     // Only for DM remapping cosim
#define DDID_SPH_TCH_1               6001     // For SPH ENH seperate into two parts
#define DDID_SPH_TCH_2               6002     // For SPH ENH seperate into two parts




/* ------------------------------------------------------------------------- */

// for WMA L2 support
void _idma_load_pm_d2(unsigned short int page, unsigned short int addr, unsigned int len, const unsigned char *image);
void FreeFuncPtr(DLL_FuncGen *dllGenPtr);
int GetPmDllFuncPtr(unsigned int fw_id, DLL_FuncGen *dllResult);

void DSP_DynamicDownload_Init( void );
int DSP_DynamicDownload( int dsp_fw_id );

void aud_7z_res_decompress(unsigned char * dest, int dest_len, unsigned char * src, int src_len);
/* ------------------------------------------------------------------------- */

#endif  /*_DDLOAD_H_ */


