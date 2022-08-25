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
 *  ImgViewerCache.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal header of image viewer decoder.
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
 ****************************************************************************/

#if !defined(_IMG_VIEWER_DEC_H_)
#define _IMG_VIEWER_DEC_H_

#include "ImgViewerConfig.h"
#if defined(__MMI_IVF_CACHE__)
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "fs_gprot.h"
#include "ImgViewerCacheGProt.h"
#include "MMI_media_app_trc.h"  /* MMI_MEDIA_TRC_G2_APP */

/*******************************************************************************
* Feature Define
*******************************************************************************/
#if defined(__MMI_IVF_CACHE__)
#define __MMI_IVF_CACHE_ADP__
#define __MMI_IVF_CACHE_MGR__
#endif /* defined(__MMI_IVF_CACHE__) */ 

#if defined(__MMI_IVF_CACHE_DB__) && !defined(__MMI_IVF_CACHE_L1__)
#define __MMI_IVF_CACHE_DBC__
#endif 

/*******************************************************************************
* Macro Define
*******************************************************************************/
/*
 * Util macros.
 */
#if (defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
#define MMI_IVC_BITS_PER_PIXEL      (24)
#define MMI_IVC_CF                  (GDI_COLOR_FORMAT_24)
#else /* (defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24) */
#define MMI_IVC_BITS_PER_PIXEL      (16)
#define MMI_IVC_CF                  (GDI_COLOR_FORMAT_16)
#endif /* (defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24) */
#define MMI_IVC_BYTES_PER_PIXEL     (MMI_IVC_BITS_PER_PIXEL >> 3)

#define MMI_IVC_ALIGN(n)            ((((n) + 3) >> 2) << 2)
#define MMI_IVC_FULL_SCR_BUF_SIZE MMI_IVC_ALIGN(LCD_WIDTH * LCD_HEIGHT * MMI_IVC_BYTES_PER_PIXEL)

#define MMI_IVC_RATIO_MULTIPLE      (100.0)

#define MMI_IVC_GET_INS_FROM_MGR(p)     ((mmi_ivc_instance_struct*)((PU8)(p) - (PU8)(&((mmi_ivc_instance_struct*)NULL)->mgr)))
#if defined(__MMI_IVF_CACHE_DBC__)
#define MMI_IVC_GET_MGR_FROM_DBC(p)     ((mmi_ivc_mgr_cntx_struct*)((PU8)(p) - (PU8)(&((mmi_ivc_mgr_cntx_struct*)NULL)->dbc)))
#endif /* __MMI_IVF_CACHE_LARGE__ */
#if defined(__MMI_IVF_CACHE_L1__)
#define MMI_IVC_GET_MGR_FROM_L1(p)      ((mmi_ivc_mgr_cntx_struct*)((PU8)(p) - (PU8)(&((mmi_ivc_mgr_cntx_struct*)NULL)->l1)))
#endif 

#define MMI_IVC_GET_DB_FROM_LIST(p)     ((mmi_ivc_db_cntx_struct*)((PU8)(p) - (PU8)(&((mmi_ivc_db_cntx_struct*)NULL)->list)))

#define MMI_IVC_FILE_IDX_VALID(idx)     (idx != 0xFFFFFFFF ? MMI_TRUE : MMI_FALSE)
#define MMI_IVC_FILE_IDX_RESET(idx)     (idx = 0xFFFFFFFF)

#define MMI_IVC_PATH_MAX_LEN            (SRV_FMGR_PATH_MAX_LEN)
#define MMI_IVC_PATH_MAX_CHAR_COUNT     (MMI_IVC_PATH_MAX_LEN + 1)
#define MMI_IVC_PATH_BUF_SIZE           (MMI_IVC_PATH_MAX_CHAR_COUNT * ENCODING_LENGTH)

#define MMI_IVC_CELL_SIZE               sizeof(mmi_ivc_cell_struct)
#define MMI_IVC_INSTANCE_SIZE           sizeof(mmi_ivc_instance_struct)
#define MMI_IVC_L1_NODE_SIZE            sizeof(mmi_ivc_mgr_l1_node_struct)

/*
 * Patten for check if an instance handle is valid.
 */
#define MMI_IVC_PATTEN_VALID           (0x0506)
#define MMI_IVC_PATTEN_INVALID         (0x0328)

/*
 * FS flags.
 */
#define MMI_IVC_DB_WORK_FOLDER_ATTR_INIT    (FS_ATTR_DIR | FS_ATTR_HIDDEN)
#define MMI_IVC_DB_WORK_FOLDER_ATTR_DEINIT  (FS_ATTR_DIR | FS_ATTR_HIDDEN | FS_ATTR_READ_ONLY)

/*
 * DB config.
 */
#define MMI_IVC_DB_SPACE_LIMIT              (100 * 1024)        /* Min free space size which is valid for create DB (in byte). */
#define MMI_IVC_DB_DEFAULT_CRITERIA         (LCD_WIDTH * LCD_HEIGHT)    /* Default criteria for DB. */
#define MMI_IVC_DB_OPACITY                  (1000)      /* Max count of files stored in DB. */
#define MMI_IVC_DB_FILENAME_LEN             (30)        /* Max length of filenames stored in DB, including ext. */
#define MMI_IVC_DB_SUFFIX                   ("_BAK")    /* Suffix of DB encoded filename */
#define MMI_IVC_DB_SUFFIX_LEN               (4)
#define MMI_IVC_DB_WORK_FOLDER_NAME         ("_BAK\\")
#define MMI_IVC_DB_WORK_FOLDER_NAME_LEN     (5)
#define MMI_IVC_DB_WORK_FOLDER_PATH_LEN     (MMI_IVC_PATH_MAX_LEN - MMI_IVC_DB_FILENAME_LEN - MMI_IVC_DB_SUFFIX_LEN)    /* Valid DB working folder len */
#define MMI_IVC_DB_LIST_FILE_NAME           ("LIST")
#define MMI_IVC_DB_LIST_FILE_NAME_LEN       (4)
#define MMI_IVC_DB_LIST_HEADER_FORMAT       ("%04d%04d%05d%05d")    /* "LCD width" and "LCD height", "idx" and "count" ASCII */
#define MMI_IVC_DB_LIST_HEADER_W_LEN        (4)
#define MMI_IVC_DB_LIST_HEADER_H_LEN        (4)
#define MMI_IVC_DB_LIST_HEADER_IDX_LEN      (5)
#define MMI_IVC_DB_LIST_HEADER_COUNT_LEN    (5)
#define MMI_IVC_DB_LIST_HEADER_LEN          \
(MMI_IVC_DB_LIST_HEADER_W_LEN + MMI_IVC_DB_LIST_HEADER_H_LEN + MMI_IVC_DB_LIST_HEADER_IDX_LEN + MMI_IVC_DB_LIST_HEADER_COUNT_LEN)
#define MMI_IVC_DB_LIST_HEADER_CHAR_COUNT   (MMI_IVC_DB_LIST_HEADER_LEN + 1)
#define MMI_IVC_DB_LIST_RECORD_OFFSET       (MMI_IVC_DB_LIST_HEADER_CHAR_COUNT)
#define MMI_IVC_DB_LIST_RECORD_CHAR_COUNT   (MMI_IVC_DB_FILENAME_LEN + 1)       /* +1 including empty char */
#define MMI_IVC_DB_LIST_RECORD_SIZE         (MMI_IVC_DB_LIST_RECORD_CHAR_COUNT * ENCODING_LENGTH)
#define MMI_IVC_DB_THUMB_TAIL_FORMAT            ("%04X%04X%4d%2d%2d%2d%2d%2d")  /* "width", "height", "YYYYMMDDThhmmss", ASCII */
#define MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT        (4 + 4 + 16 + 1)        /* 4+4+8+1 */
#define MMI_IVC_DB_THUMB_TAIL_OFFSET_FROM_END   ((-1) * MMI_IVC_DB_THUMB_TAIL_CHAR_COUNT)       /* 4+4+8 */

/*
 * Timers
 */
#define MMI_IVC_ADP_GET_PATH_TIMER_DURATION     (500)
#define MMI_IVC_L1_DEC_CELL_TIMER_DURATION      (0)
#define MMI_IVC_DB_ENCODE_TMER_DURATION         (50)

/*
 * Cell flags
 */
#define MMI_IVC_CELL_FLAG                   (0xFF00)
#define MMI_IVC_CELL_FLAG_DRM               (0x0100 << 0)
#define MMI_IVC_CELL_FLAG_FROM_DB           (0x0100 << 1)
#define MMI_IVC_CELL_FLAG_SET(cell, m, v)   ((cell)->flag)=((((cell)->flag)&(~(m)))|(v))
#define MMI_IVC_CELL_FLAG_GET(cell, m)      (((cell)->flag)&(m))
#define MMI_IVC_CELL_STATE                  (0x0F)      /* Decoding state of cell */
#define MMI_IVC_CELL_STATE_INIT             (0X00)
#define MMI_IVC_CELL_STATE_OK               (0x01 << 0)
#define MMI_IVC_CELL_STATE_ERR              (0x01 << 1)
#define MMI_IVC_CELL_STATE_GET(cell)        (MMI_IVC_CELL_FLAG_GET((cell), MMI_IVC_CELL_STATE))
#define MMI_IVC_CELL_STATE_SET(cell, v)     (MMI_IVC_CELL_FLAG_SET((cell), MMI_IVC_CELL_STATE, (v)))
#define MMI_IVC_CELL_TYPE                   (0xF0)      /* Cell type check result */
#define MMI_IVC_CELL_TYPE_INIT              (0x00)
#define MMI_IVC_CELL_TYPE_L1                (0x10 << 0)
#define MMI_IVC_CELL_TYPE_DBC               (0x10 << 1)
#define MMI_IVC_CELL_TYPE_GET(cell)         (MMI_IVC_CELL_FLAG_GET((cell), MMI_IVC_CELL_TYPE))
#define MMI_IVC_CELL_TYPE_SET(cell, v)      (MMI_IVC_CELL_FLAG_SET((cell), MMI_IVC_CELL_TYPE, (v)))

/*
 * For saving code size, ARM compiler will optimize the code if the "if condition" is "const 0"
 */
#if defined(__MMI_IVF_CACHE_L1__)
#define MMI_IVC_CELL_IS_L1(cell)    (MMI_IVC_CELL_TYPE_L1 == MMI_IVC_CELL_TYPE_GET(cell))
#else 
#define MMI_IVC_CELL_IS_L1(cell)    (0)
#endif 
#if defined(__MMI_IVF_CACHE_DBC__)
#define MMI_IVC_CELL_IS_DBC(cell)   (MMI_IVC_CELL_TYPE_DBC == MMI_IVC_CELL_TYPE_GET(cell))
#else 
#define MMI_IVC_CELL_IS_DBC(cell)   (0)
#endif 

/*
 * IVC internal error code
 */
#define MMI_IVC_ERR_FS_ERR        (-56201)
#define MMI_IVC_ERR_GDI_ERR       (-56202)

/*
 * Debug information
 */
#define MMI_IVC_TRACE_GROUP       MMI_MEDIA_TRC_G2_APP
#define MMI_IVC_TRACE             MMI_TRACE
#define MMI_IVC_ASSERT            MMI_ASSERT

/*******************************************************************************
* Type Define
*******************************************************************************/
typedef void (*mmi_ivc_dec_cb) (S32 result, void *userData);
typedef void (*mmi_ivc_preDec_cb) (WCHAR *filepath, void *userData);
typedef void (*mmi_ivc_get_folder_cb) (WCHAR *path, void *userData);

typedef enum
{
    MMI_IVC_STATE_STOPPED,
    MMI_IVC_STATE_RUNNING,
    MMI_IVC_STATE_DESTORIED
} mmi_ivc_state_enum;

typedef struct
{
    U32 idx;
    WCHAR filename[MMI_IVC_DB_LIST_RECORD_CHAR_COUNT];
    U16 flag;
    U16 imgType;

    /* Original info of image */
    S32 orgW;
    S32 orgH;

    /* Information in cell */
    GDI_HANDLE imgLyr;
    S32 resizedW;
    S32 resizedH;

    /* Cell data buffer information */
    PU8 bufPtr;

    PU8 allocBufPtr;
} mmi_ivc_cell_struct;

#if defined(__MMI_IVF_CACHE_DB__)
typedef enum
{
    MMI_IVC_DB_STATE_INIT,
    MMI_IVC_DB_STATE_OK,
    MMI_IVC_DB_STATE_INVALID
} mmi_ivc_db_state_enum;

typedef struct
{
    /* Idx is used to check if the cell content is changed */
    U32 idx;

    mmi_ivc_cell_struct *cell;
} mmi_ivc_db_encode_struct;

typedef struct
{
    FS_HANDLE fHdl;
    U32 idx;
    U32 count;
    S32 fmgrAsyncJob;
} mmi_ivc_db_list_struct;

typedef struct
{
    WCHAR folderpath[MMI_IVC_PATH_MAX_CHAR_COUNT];
    mmi_ivc_db_encode_struct encode;
    mmi_ivc_db_list_struct list;
    mmi_ivc_db_state_enum state;
} mmi_ivc_db_cntx_struct;
#endif /* defined(__MMI_IVF_CACHE_DB__) */ 

#if defined(__MMI_IVF_CACHE_DBC__)
typedef struct
{
    /* If APP have not set memory or have removed memory, it will be invalid */
    mmi_ivc_cell_struct cell;
} mmi_ivc_mgr_dbc_cntx_struct;
#endif /* defined(__MMI_IVF_CACHE_DBC__) */

#if defined(__MMI_IVF_CACHE_L1__)
typedef struct mmi_ivc_mgr_l1_node
{
    struct mmi_ivc_mgr_l1_node *prev;
    struct mmi_ivc_mgr_l1_node *next;

    mmi_ivc_cell_struct cell;
} mmi_ivc_mgr_l1_node_struct;

typedef struct
{
    mmi_ivc_mgr_l1_node_struct *freeNodes;
    U32 nodeCount;
    mmi_ivc_mgr_l1_node_struct *curr;
} mmi_ivc_mgr_l1_cntx_struct;
#endif /* defined(__MMI_IVF_CACHE_L1__) */ 

typedef struct
{
    S32 currDecIdx;
    mmi_ivc_cell_struct *currDecCell;
#if defined(__MMI_IVF_CACHE_L1__)
    mmi_ivc_mgr_l1_cntx_struct l1;
#endif 
#if defined(__MMI_IVF_CACHE_DBC__)
    /* This cache is used to decode image and then encode to layer,
       or decode DB image for DB */
    mmi_ivc_mgr_dbc_cntx_struct dbc;
#endif /* defined(__MMI_IVF_CACHE_DBC__) */ 
} mmi_ivc_mgr_cntx_struct;

typedef struct
{
    struct
    {
        /* Decoding information */
        mmi_ivc_cell_struct *cell;
        mmi_ivc_dec_cb cb;
    #if defined(__MMI_IVF_CACHE_DB__)
        /* Used for DB to get thumb before decode from file */
        mmi_ivc_preDec_cb preDecCb;
    #endif /* defined(__MMI_IVF_CACHE_DB__) */ 
        void *userData;
        GDI_HANDLE hdl;
    } dec;

    struct
    {
        struct
        {
            /* Get file information */
            S32     idx;
            WCHAR   path[MMI_IVC_PATH_MAX_CHAR_COUNT];
        } file;

        struct
        {
            mmi_ivc_get_folder_cb   cb;
            void                    *userData;
            WCHAR   path[MMI_IVC_PATH_MAX_CHAR_COUNT];
        }folder;
    } getPath;
} mmi_ivc_adp_cntx_struct;

typedef struct
{
    U16 pattenStart;

    mmi_ivc_state_enum state;

    U32 currIdx;
    U32 count;

    /* Event handler information */
    mmi_proc_func eventProc;
    void *userData;

    mmi_ivc_adp_cntx_struct adp;

    mmi_ivc_mgr_cntx_struct mgr;

#if defined(__MMI_IVF_CACHE_DB__)
    mmi_ivc_db_cntx_struct db;
#endif 

    U16 pattenEnd;
} mmi_ivc_instance_struct;

/*******************************************************************************
* Module APIs
*******************************************************************************/
/*
 * ADP will always exist with IVC, so need to wrap options
 */
extern void mmi_ivc_adp_init(mmi_ivc_instance_struct *ins, PU8 runBufPtr, U32 runBufSize);
extern void mmi_ivc_adp_stop(mmi_ivc_instance_struct *ins);
extern S32 mmi_ivc_adp_send_event(mmi_ivc_instance_struct *ins, mmi_ivc_event_struct *evt);
extern void mmi_ivc_adp_get_folder(mmi_ivc_instance_struct *ins, mmi_ivc_get_folder_cb cb, void *userData);
extern void mmi_ivc_adp_cell_cancel_dec(mmi_ivc_instance_struct *ins);
extern void mmi_ivc_adp_cell_dec_cell(
                mmi_ivc_instance_struct *ins,
                mmi_ivc_cell_struct *cell,
                mmi_ivc_preDec_cb preDecCb,
                mmi_ivc_dec_cb cb,
                void *userData);
extern void mmi_ivc_adp_cell_create_layer_ext(mmi_ivc_cell_struct *cell
#if defined(__MMI_IVC_LAYER_DEBUG__)
                                              , char *file_p, long line_p
#endif 
    );
extern void mmi_ivc_adp_cell_free_layer_ext(mmi_ivc_cell_struct *cell
#if defined(__MMI_IVC_LAYER_DEBUG__)
                                            , char *file_p, long line_p
#endif 
    );

#if defined(__MMI_IVC_LAYER_DEBUG__)
#define mmi_ivc_adp_cell_create_layer(cell)                 mmi_ivc_adp_cell_create_layer_ext(cell, __IVCMODULE__, __LINE__)
#define mmi_ivc_adp_cell_free_layer(cell)                   mmi_ivc_adp_cell_free_layer_ext(cell, __IVCMODULE__, __LINE__)
#else /* defined(__MMI_IVC_LAYER_DEBUG__) */ 
#define mmi_ivc_adp_cell_create_layer(cell)                 mmi_ivc_adp_cell_create_layer_ext(cell)
#define mmi_ivc_adp_cell_free_layer(cell)                   mmi_ivc_adp_cell_free_layer_ext(cell)
#endif /* defined(__MMI_IVC_LAYER_DEBUG__) */ 
#define mmi_ivc_adp_start(ins)                              mmi_ivc_mgr_start(ins)
#define mmi_ivc_adp_deinit(ins)                             mmi_ivc_mgr_deinit(ins)
#define mmi_ivc_adp_add_memory(ins, bufPtr, bufSize)        mmi_ivc_mgr_add_memory(ins, bufPtr, bufSize)
#define mmi_ivc_adp_remove_memory(ins, bufPtr)              mmi_ivc_mgr_remove_memory(ins, bufPtr)
#define mmi_ivc_adp_get_curr_img(ins, dstLyr)               mmi_ivc_mgr_get_curr_img(ins, dstLyr)
#define mmi_ivc_adp_set_curr_idx(ins, idx)                  mmi_ivc_mgr_set_curr_idx(ins, idx)
#define mmi_ivc_adp_query_img(ins, idx, dstLyr)             mmi_ivc_mgr_query_img(ins, idx, dstLyr)

/*
 * Cache will always exist with IVC, so need to wrap options.
 * Extern cache APIs, these APIs are only called in adp except init, init will be called in infc module.
 */
extern void mmi_ivc_mgr_init(mmi_ivc_instance_struct *ins, PU8 runBufPtr, U32 runBufSize);
extern void mmi_ivc_mgr_start(mmi_ivc_instance_struct *ins);
extern void mmi_ivc_mgr_stop(mmi_ivc_instance_struct *ins);
extern S32 mmi_ivc_mgr_add_memory(mmi_ivc_instance_struct *ins, PU8 bufPtr, U32 bufSize);
extern void mmi_ivc_mgr_remove_memory(mmi_ivc_instance_struct *ins, PU8 bufPtr);
extern S32 mmi_ivc_mgr_get_curr_img(mmi_ivc_instance_struct *ins, GDI_HANDLE dstLyr);
extern void mmi_ivc_mgr_set_curr_idx(mmi_ivc_instance_struct *ins, U32 idx);
extern S32 mmi_ivc_mgr_query_img(mmi_ivc_instance_struct *ins, U32 idx, GDI_HANDLE dstLyr);

#define mmi_ivc_mgr_deinit(ins)         mmi_ivc_db_deinit(ins)

#if defined(__MMI_IVF_CACHE_DB__)
/* Extern DB APIs, these APIs are only called in cache except init, init will be called in infc module. */
extern void mmi_ivc_db_init(mmi_ivc_instance_struct *ins);
extern void mmi_ivc_db_deinit(mmi_ivc_instance_struct *ins);
extern void mmi_ivc_db_start(mmi_ivc_instance_struct *ins);
extern void mmi_ivc_db_stop(mmi_ivc_instance_struct *ins);
extern void mmi_ivc_db_save(mmi_ivc_instance_struct *ins, mmi_ivc_cell_struct *cell);
extern S32 mmi_ivc_db_get(mmi_ivc_instance_struct *ins, mmi_ivc_cell_struct *cell, WCHAR *filepath);
#else /* defined(__MMI_IVF_CACHE_DB__) */
#define mmi_ivc_db_init(ins)                    MMI_IVC_OK
#define mmi_ivc_db_deinit(ins)
#define mmi_ivc_db_stop(ins)
#define mmi_ivc_db_save(ins, cell)
#define mmi_ivc_db_get(ins, cell, filepath)     MMI_IVC_FAILE
#endif /* defined(__MMI_IVF_CACHE_DB__) */

/*******************************************************************************
* Debug
*******************************************************************************/
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_IVC_MEASURE_PERFORMANCE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_IVC_MEASURE_PERFORMANCE__) */ 
#define IVC_PMD_START(_symbol_)
#define IVC_PMD_STOP(_symbol_)

#define IVC_PMD_FS_OPEN                     FS_Open
#define IVC_PMD_FS_CLOSE                    FS_Close
#define IVC_PMD_FS_SEEK                     FS_Seek
#define IVC_PMD_FS_READ                     FS_Read
#define IVC_PMD_FS_WRITE                    FS_Write
#define IVC_PMD_FS_SET_ATTR                 FS_SetAttributes
#define IVC_PMD_FS_GET_INFO                 FS_GetFileInfo
#define IVC_PMD_GDI_GET_DIM                 gdi_image_get_dimension_file
#define IVC_PMD_GDI_GET_TYPE                gdi_image_get_type_from_file
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_IVC_MEASURE_PERFORMANCE__) */ 

#endif /* defined(__MMI_IVF_CACHE__) */ 
#endif /* !defined(_IMG_VIEWER_DEC_H_) */ 

