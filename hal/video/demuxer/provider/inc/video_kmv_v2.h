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
 *   video_kmv_v2.h
 *
 * Project:
 * --------
 *  MTK
 *
 * Description:
 * ------------
 *   
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
 *
 * removed!
 ****************************************************************************/
 


#ifndef VIDEO_KMV_V2_H
#define VIDEO_KMV_V2_H

#include "drv_features_video.h"

//#if defined(__MTK_TARGET__)


//#include <stdint.h>
#include "mp4_parser.h"

#ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__

#include "mp4_provider.h"
#endif
#include "kal_general_types.h"


#include "video_types_v2.h"
#include "kal_public_defs.h"

typedef kal_uint32 uint32_t;
typedef kal_uint16 uint16_t;
typedef kal_uint8 uint8_t;
typedef kal_int32 int32_t;
typedef kal_int16 int16_t;
typedef kal_int8 int8_t;


#define KMV_ENCRYPT
//#define KMV_SPEED_MODE
//#define KMV_SPEED_INPLACE_MODE
//#define KMV_USE_HW_SCL
//#define KMV_USE_HW_DECODE

#define KMV_SYNCWORD_LENGTH     4
#define KMV_MAX_MB_LEN          396
#define KMV_META_LEN            (KMV_MAX_MB_LEN + KMV_SYNCWORD_LENGTH)
#define KMV_BUFFER_ELEMENT      (KMV_META_LEN + 2 + 2 + 2 + 1)
#define KMV_SMALL_RECBUF_SIZE   69120
#define KMV_AES_InvMixtab 256
#define KMV_AES_RoundKeyBuf 256
#define KMV_AES_CACHE ((KMV_AES_InvMixtab<<3) + KMV_AES_RoundKeyBuf)

// KMV Type:
// [3D FMT|Quality]:[VideoCodec]:[3D|SEI|Normal|NotKMV]
#define KMV_NOT_KMV          0x0000
#define KMV_NORMAL           0x0001
#define KMV_SEI              0x0002
#define KMV_DRM              0x0004
#define KMV_3D               0x0008
#define KMV_DUALVIEW         0x0010

#define KMV_AVC_FMT  0x0100
#define KMV_M4V_FMT  0x0200
#define KMV_QVGA     0x1000
#define KMV_HVGA     0x2000

#define KMV_QVGA_AVC (KMV_QVGA | KMV_AVC_FMT)
#define KMV_QVGA_M4V (KMV_QVGA | KMV_M4V_FMT)
#define KMV_HVGA_M4V (KMV_HVGA | KMV_M4V_FMT)

#define KMV_CHECK_INDEX_DATA
#define KMV_STCO_HEADER (4+4+3+1)
#define KMV_META_HEADER (4+4)
#define KMV_STSZ_HEADER (4+4)
#define KMV_SAMPLE_ELEMENT (1+2+2+1)
#define KMV_Gtype 2
#define KMV_CURRENT_VERSION 0x1

#ifdef KMV_ENCRYPT
#define KMV_NALU_TYPE_SLICE   1
#define KMV_NALU_TYPE_DPA     2
#define KMV_NALU_TYPE_DPB     3
#define KMV_NALU_TYPE_DPC     4
#define KMV_NALU_TYPE_IDR     5
#define KMV_NALU_TYPE_SEI     6
#define KMV_NALU_TYPE_SPS     7
#define KMV_NALU_TYPE_PPS     8
#define KMV_NALU_TYPE_AUD     9
#define KMV_NALU_TYPE_EOSEQ   10
#define KMV_NALU_TYPE_EOSTREAM 11
#define KMV_NALU_TYPE_FILLER  12

#define KMV_START_CODE_AVC1    3
#define KMV_NALU_TYPE_SLICE   1
#define KMV_NALU_TYPE_IDR     5
#define KMV_AVC_START_CODE1 0x000001
#define KMV_bsSWAP(a,b) (b=((a[0] << 24) | (a[1] << 16) | (a[2] << 8) | a[3]))
#define KMV_FUNSHIFT3(a,b)  (((a)<<24) | (((uint32_t)(b))>>8 ))
#define KMV_FUNSHIFT1(a,b)  (((a)<<8)  | (((uint32_t)(b))>>24))
#endif

#define FILE_POS kal_uint32
#define FILE_OFF kal_int32
#define MP4FILE kal_int32
#define UUID_OFFSET 8
#define UUID_SN 16
#define UUID_KMV 4
#define UUID_DES_HEADER 12
#define UUID_DES_CONTENT 6
#define UUID_FILE_TYPE 3
#define UUID_FILE_TYPE_EXT 3
#define UUID_FILE_MIME_TYPE 11
#define UUID_HEADER (UUID_OFFSET+UUID_SN+UUID_KMV+UUID_DES_HEADER+UUID_DES_CONTENT+UUID_FILE_TYPE+UUID_FILE_TYPE_EXT+UUID_FILE_MIME_TYPE)

#define KMVSyncWordSize 50

#define KMV_STCO_CACHE  512
#define KMV_STSZ_CACHE  8704
#define KMV_MAP_CACHE   1024
#define KMV_STCOENTRY   4
#define KMV_STSZENTRY   6
#define KMV_MAPENTRY    256

#define KMV_EARLY_RECON_TIME (666666*3)


typedef struct tagkmvcache {
    uint8_t       *cache_page;
    uint32_t         page_idx;
} KMVCACHE;

typedef enum KMVRetCode_e
{
    //KMV Return Message
    KMV_SUCCESS = 0x9000,
    KMV_ERR_NOT_KMV,
    KMV_ERR_FILE_ERROR,
    KMV_SMALL_RECT,
    //KMV DRM
    KMV_DMX_LICENSE_NOTEXIST  = 0x9209,
    KMV_DMX_LICENSE_MISMATCH,
    KMV_DMX_PASSWORD_MISMATCH
} KMVRetCode;

#ifdef __VE_MP43GP_FILE_FORMAT_SUPPORT__


/***************************
   extern frunction
  ***************************/

extern void KMV_DecryptFrame(uint8_t *buf, int len, uint8_t* key, uint32_t kmv_type);
extern void KMV_DecryptKey(MP4_PROVIDER_CTRL_T* prMP4ProviderCtrl);
extern void KMV_InitHQfmt(uint16_t HQfmt, uint32_t *kmv_type);
extern int MP4DMX_InitKMVMeta(void *pInst, const uint8_t passwd[16]);
extern MP4_Parser_Status MP4DMX_ReadKMVMeta(void *pInst, uint32_t frameidx, uint8_t *tType,uint16_t *recH, uint16_t *recW, uint8_t *pBuf, uint16_t *nsize);

#endif


/************************************** PP ***********************************************/

#define kmv_init_semaphore() do{}while(0);
#define kmv_free(w,x,y,z) do{}while(0);

#define assert(x) ASSERT(x)
#define memcpy(x,y,z) kal_mem_cpy(x,y,z)
#define KMV_DBG_MSG(x, ...) ((void) 0)
#define KMV_SYNCWORD_LENGTH 4

#define MAX_COMPRESSED_MAP_SIZE 256
#define KMV_DROP_REC 1

#define KmvClip(iValue,imin,imax) (((iValue) < (imin))?(imin):(((iValue) > (imax))?(imax):(iValue)))
#define KmvClip2(iValue) (((iValue) > (255))?(255):(iValue))

#define KMV_ENCRYPT
//#define KMV_SPEED_MODE
//#define KMV_SPEED_INPLACE_MODE
//#define KMV_USE_HW_SCL
//#define KMV_USE_HW_DECODE

#define KMV_SW_SCALER_UP_BUFFER 3840 //(320x6x2)

// KMV Type:
// [3D FMT|Quality]:[VideoCodec]:[3D|SEI|Normal|NotKMV]
#define KMV_NOT_KMV          0x0000
#define KMV_NORMAL           0x0001
#define KMV_SEI              0x0002
#define KMV_DRM              0x0004
#define KMV_3D               0x0008
#define KMV_DUALVIEW         0x0010

#define KMV_AVC_FMT  0x0100
#define KMV_M4V_FMT  0x0200
#define KMV_QVGA     0x1000
#define KMV_HVGA     0x2000

#define KMV_QVGA_AVC (KMV_QVGA | KMV_AVC_FMT)
#define KMV_QVGA_M4V (KMV_QVGA | KMV_M4V_FMT)
#define KMV_HVGA_M4V (KMV_HVGA | KMV_M4V_FMT)

typedef struct kmv_meta_s
{
    kal_uint8  kmvMeta[KMV_META_LEN];
    kal_uint16 recH;
    kal_uint16 recW;
    kal_uint16 nsize;
    kal_uint8  tType;
} kmv_meta_st;


typedef enum
{
    I420 = 0,
    NV12,
    IMC2,
    Num_BUF_FORMAT,
} KMV_BUF_FORMAT;

typedef enum
{
    I420toI420 = 0,
    NV12toI420,
    I420toIMC2,
    NV12toNV12,
    Num_IO_FORMAT
} KMV_IO_FORMAT;

typedef enum
{
    SRC_YUV = 0,
    SRC_Y
} KMV_ADDR_FORMAT;

typedef struct KMV_MB_s
{
    uint16_t x;
    uint16_t y;
} KMV_MB_st;

typedef struct KMV_BUFFERINFO_s
{
    uint8_t *pBufY;
    uint8_t *pBufU;
    uint8_t *pBufV;
    uint16_t nBufH;
    uint16_t nBufW;
    uint16_t nstride_y;
    uint16_t nstride_uv;
    KMV_BUF_FORMAT efmt;
    KMV_ADDR_FORMAT eBuffmt;
} KMV_BUFFERINFO;

typedef struct KMV_OPERATION_s
{
    int SMRECT;
    KMV_IO_FORMAT io_fmt;
} KMV_OPERATION;


typedef enum{
    KMV_EG_IDP_COMPLETE        = 0x00000001,
} KMV_comp_eg_enum;


typedef struct kmv_class_s
{
    int g_rMB;
    int g_bMB;
    int g_tMB;
    int g_lMB;
    void *outframebuf;
    uint8_t *g_pMapBuf;
    int g_referenced;
    int g_preserved_fps;
    
#ifdef KMV_OUTBUF_FROM_GBUF
    global_buffer_st *pGbuf;
#endif
    int kmv_speed_mode;
    int kmv_drpnum;
        
    kal_bool fg_kmv_inited;
    kal_int32 i4dPelx;
    kal_int32 i4dPely;

    kal_eventgrpid eEvent;

#ifndef KMV_USE_HW_SCL
    char* pu8kmv_scaleup_buffer;//[KMV_SW_SCALER_UP_BUFFER];
#endif // KMV_USE_HW_SCL      

#ifdef __VE_KMV_PROFILE_ENABLE__
    kal_uint32 u4PPTotalTime;
    kal_uint32 u4PPCounter;

    kal_uint32 u4CopyFrmTotalTime;
    kal_uint32 u4CopyFrmCounter;

    kal_uint32 u4MAPTotalTime;
    kal_uint32 u4MAPCounter;

    kal_uint32 u4USLTotalTime;
    kal_uint32 u4USLCounter;

    kal_uint32 u4RECONTotalTime;
    kal_uint32 u4RECONCounter;

    kal_uint32 u4DSL_ReconTotalTime;
    kal_uint32 u4DSL_ReconCounter;    

    kal_uint32 u4GetIdpKeyTotalTime;
    kal_uint32 u4GetIdpKeyCounter;
    
#endif
    
} KMV_Class;

typedef struct kmv_frame_info
{
    /*
    uint8_t       u1src_y;
    uint8_t       u1src_u;
    uint8_t       u1src_v;
    */
    int           i4stride_y;
    int           i4stride_uv;    
}KMV_FRAME_INFO;

typedef struct kmv_frame_buffer_ext
{
    uint8_t       **src_y;
    uint8_t       **src_u;
    uint8_t       **src_v;
    int             width;
    int             height;
    int            *stride_y;
    int            *stride_uv;
    kmv_meta_st    *kmv_metabuf;
    int             in_fmt;
    int             out_fmt;
    void          **privateData;
} KMV_frame_buffer_ext;

typedef struct
{
    unsigned int u4PayloadNumber;
    void *pu1PayloadAddress;
    
#ifdef __VE_KMV_SUPPORT__
    void *pu1KMVPayloadAddress;
    kal_uint32 u4KMVSize;  
#endif

} KMV_PRIVATE_PAYLOAD_T;

extern int kmv_recon_frame2(KMV_frame_buffer_ext *frame_buf, KMV_Class* kmv_obj, uint32_t kmv_type, uint32_t *need_rec_buffer);
extern int KMV_IsM4vfmt(uint32_t kmv_type);
//#endif // MTK_TARGET

#endif /* VIDEO_KMV_V2_H */

