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
* Filename:
* ---------
*  MeidaPlayerPlayList.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media Player Playlist module
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef __MEDIA_PLAYER_PLAY_LIST_H__
#define __MEDIA_PLAYER_PLAY_LIST_H__

    #include "MMI_features.h"

#ifdef __MMI_MEDIA_PLAYER__

    #include "FileMgrSrvGProt.h"
    #include "MMIDataType.h"
    #include "gui_data_types.h"
    #include "kal_general_types.h"
    #include "fs_type.h"
    #include "GlobalConstants.h"
    #include "mmi_frm_events_gprot.h"

/*****************************/
/*        Header         */
/*****************************/
////#include "meta_tag_parser.h"
#include "inlinecuigprot.h"
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
#include "sqlite3.h"
#include "sqlite3ex.h"
////#include "sqlite3kal.h"
////#include "sqlitelimit.h"
#endif/* __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__ */

////#include "FileMgrGProt.h"
#include "AlertScreen.h"
/*****************************/
/*  Function compile option  */
/*****************************/
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
#define DETAILS_SUPPORT_EDIT
#define PARSE_FILE_IN_GENERATE
#endif

/*****************************/
/*     Common definition     */
/*****************************/
/* buffer limit. */
#define MEDPLY_MAX_PATH_LEN			(SRV_FMGR_PATH_MAX_LEN + 1)
#define MEDPLY_MAX_FILE_LEN			(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)
#define MEDPLY_MAX_EXT_LEN			(SRV_FMGR_PATH_MAX_FILE_EXT_LEN)
#define MEDPLY_MAX_INPUT_FILE_LEN	(SRV_FMGR_PATH_MAX_FILE_NAME_LEN - SRV_FMGR_PATH_MAX_FILE_EXT_LEN)
#define MEDPLY_MAX_ERROR_STRING_LEN	((MEDPLY_MAX_FILE_LEN) * 2)

#define MEDPLY_MAX_PATH_SIZE		(MEDPLY_MAX_PATH_LEN * ENCODING_LENGTH)
#define MEDPLY_MAX_FILE_SIZE		(MEDPLY_MAX_FILE_LEN * ENCODING_LENGTH)
#define MEDPLY_MAX_EXT_SIZE			(MEDPLY_MAX_EXT_LEN * ENCODING_LENGTH)

#define MMI_MEDPLY_MAX_EDITOR_LEN               (MEDPLY_MAX_PATH_LEN)
#define MMI_MEDPLY_MAX_URL_LEN                  (256)

/* details item string length. */
#define MMI_MEDPLY_MAX_TITLE_LEN                (80+1)
#define MMI_MEDPLY_MAX_ARTISRT_LEN              (80+1)
#define MMI_MEDPLY_MAX_ALBUM_LEN                (80+1)
#define MMI_MEDPLY_MAX_GENRE_LEN                (80+1)
#define MMI_MEDPLY_MAX_AUTHOR_LEN               (80+1)
#define MMI_MEDPLY_MAX_COPYRIGHTS_LEN           (80+1)
#define MMI_MEDPLY_MAX_DESCRIPTION_LEN          (80+1)

#define MMI_MEDPLY_MAX_TRACKNUM_LEN             (4+1) /* max track number is "9999" */  
#define MMI_MEDPLY_MAX_YEAR_LEN                 (4+1) /* max year is "9999" */
#define MMI_MEDPLY_MAX_DURATION_LEN             (10+1)/* max duration for U32 milliseconds type is "1194:59:59" */
#define MMI_MEDPLY_MAX_SIZE_LEN                 (7+1) /* max duration for U32 milliseconds type is "4096.9M" */
#define MMI_MEDPLY_MAX_TIME_LEN                 (19+1)/* 2008-09-05 11:23 PM */
#define MMI_MEDPLY_MAX_USER_RATING_LEN          (41)  /* temp value */


/*****************************/
/*        error code         */
/*****************************/
#define MEDPLY_PLST_GOT_DATA                        (1)
#define MEDPLY_PLST_NO_ERROR                        (0)
/* file system erro code: -1 ~ -199  */
/* playlist module error code : -200 ~ -219 */
#define MEDPLY_PLST_ERR_BASE                        (-200)
#define MEDPLY_PLST_ERR_INVALID_PARA				(-201)
#define MEDPLY_PLST_ERR_EMPTY_FILENAME				(-202)
#define MEDPLY_PLST_ERR_FILE_EXISTS					(-203)
#define MEDPLY_PLST_ERR_LIST_FULL					(-204)
#define MEDPLY_PLST_ERR_LIST_DAMAGE					(-205)
#define MEDPLY_PLST_ERR_INVALID_LIST				(-206)
#define MEDPLY_PLST_ERR_CREATE_FAILED				(-207)
#define MEDPLY_PLST_ERR_OPEN_FAILED					(-208)
#define MEDPLY_PLST_ERR_NO_SPACE					(-209)
#define MEDPLY_PLST_ERR_NO_MEMORY					(-210)
#define MEDPLY_PLST_ERR_CAN_NOT_DELETE				(-211)
#define MEDPLY_PLST_ERR_READ_LIST_FAILED			(-212)
#define MEDPLY_PLST_ERR_WRITE_LIST_FAILED			(-213)
#define MEDPLY_PLST_ERR_EMPTY_LIST					(-214)
#define MEDPLY_PLST_ERR_INVALID_FILE_PATH			(-215)
#define MEDPLY_PLST_ERR_ITEM_EXISTS					(-216)
#define MEDPLY_PLST_ERR_OVER_LIMIT					(-217)
#define MEDPLY_PLST_ERR_CAN_NOT_FIND				(-218)
#define MEDPLY_PLST_ERR_OUT_OF_RANGE				(-219)    
/* meta parser error code : -220 ~ -229 */
#define MEDPLY_PLST_ERR_META_NO_MEMORY              (-221)
#define MEDPLY_PLST_ERR_META_NO_HANDLE              (-222)
#define MEDPLY_PLST_ERR_META_NO_INPUT               (-223)
#define MEDPLY_PLST_ERR_META_OPEN_FAILED            (-224)
#define MEDPLY_PLST_ERR_META_INVALID_HDLR           (-225)
#define MEDPLY_PLST_ERR_META_INVALID_DATA           (-226)
#define MEDPLY_PLST_ERR_META_NOT_SUPPORT            (-227)
#define MEDPLY_PLST_ERR_META_NO_ENOUGH_BUF          (-228)

/* sqlite error code : -229 ~ ? */
#define MEDPLY_PLST_ERR_DB_NOT_READY                (-230)
#define MEDPLY_PLST_ERR_DB_CREATE_TBL_FAILED        (-231)
#define MEDPLY_PLST_ERR_DB_ADD_ARTIST_FAILED        (-232)
#define MEDPLY_PLST_ERR_DB_ADD_ALBUM_FAILED         (-233)
#define MEDPLY_PLST_ERR_DB_DAMAGED                  (-234)
#define MEDPLY_PLST_ERR_DB_INVALID_FILE             (-235)
#define MEDPLY_PLST_ERR_DB_EMPTY                    (-236)
#define MEDPLY_PLST_ERR_DB_ERROR_LOG                (-237)
#define MEDPLY_PLST_ERR_DB_ERROR                    (-238)
#define MEDPLY_PLST_ERR_DB_IN_TRANSACTION           (-239)
#define MEDPLY_PLST_ERR_DB_NO_CONDITION             (-240)

/* mapping sqlite error code. */
#define MEDPLY_PLST_ERR_SQLITE_ERROR                (-241)   /* SQL error or missing database */
#define MEDPLY_PLST_ERR_SQLITE_INTERNAL             (-242)   /* Internal logic error in SQLite */
#define MEDPLY_PLST_ERR_SQLITE_PERM                 (-243)   /* Access permission denied */
#define MEDPLY_PLST_ERR_SQLITE_ABORT                (-244)   /* Callback routine requested an abort */
#define MEDPLY_PLST_ERR_SQLITE_BUSY                 (-245)   /* The database file is locked */
#define MEDPLY_PLST_ERR_SQLITE_LOCKED               (-246)   /* A table in the database is locked */
#define MEDPLY_PLST_ERR_SQLITE_NOMEM                (-247)   /* A malloc() failed */
#define MEDPLY_PLST_ERR_SQLITE_READONLY             (-248)   /* Attempt to write a readonly database */
#define MEDPLY_PLST_ERR_SQLITE_INTERRUPT            (-249)   /* Operation terminated by sqlite3_interrupt()*/
#define MEDPLY_PLST_ERR_SQLITE_IOERR                (-250)   /* Some kind of disk I/O error occurred */
#define MEDPLY_PLST_ERR_SQLITE_CORRUPT              (-251)   /* The database disk image is malformed */
#define MEDPLY_PLST_ERR_SQLITE_NOTFOUND             (-252)   /* NOT USED. Table or record not found */
#define MEDPLY_PLST_ERR_SQLITE_FULL                 (-253)   /* Insertion failed because database is full */
#define MEDPLY_PLST_ERR_SQLITE_CANTOPEN             (-254)   /* Unable to open the database file */
#define MEDPLY_PLST_ERR_SQLITE_PROTOCOL             (-255)   /* NOT USED. Database lock protocol error */
#define MEDPLY_PLST_ERR_SQLITE_EMPTY                (-256)   /* Database is empty */
#define MEDPLY_PLST_ERR_SQLITE_SCHEMA               (-257)   /* The database schema changed */
#define MEDPLY_PLST_ERR_SQLITE_TOOBIG               (-258)   /* String or BLOB exceeds size limit */
#define MEDPLY_PLST_ERR_SQLITE_CONSTRAINT           (-259)   /* Abort due to constraint violation */
#define MEDPLY_PLST_ERR_SQLITE_MISMATCH             (-260)   /* Data type mismatch */
#define MEDPLY_PLST_ERR_SQLITE_MISUSE               (-261)   /* Library used incorrectly */
#define MEDPLY_PLST_ERR_SQLITE_NOLFS                (-262)   /* Uses OS features not supported on host */
#define MEDPLY_PLST_ERR_SQLITE_AUTH                 (-263)   /* Authorization denied */
#define MEDPLY_PLST_ERR_SQLITE_FORMAT               (-264)   /* Auxiliary database format error */
#define MEDPLY_PLST_ERR_SQLITE_RANGE                (-265)   /* 2nd parameter to sqlite3_bind out of range */
#define MEDPLY_PLST_ERR_SQLITE_NOTADB               (-266)   /* File opened that is not a database file */
    
/*
** multiple list style error code.
*/
#define MEDPLY_PLST_ERR_WRITE_FAILED                (-501)
#define MEDPLY_PLST_ERR_READ_FAILED                 (-502)
#define MEDPLY_PLST_ERR_NOT_PLST                    (-503)    /* it is not playlist file. */
#define MEDPLY_PLST_ERR_INVALID_FILENAME            (-504)
#define MEDPLY_PLST_ERR_INVALID_INPUT               (-505)
#define MEDPLY_PLST_ERR_WRONG_VER                   (-507)    /* wrong version number. */
#define MEDPLY_PLST_ERR_LIST_DAMAGED                (-509)
#define MEDPLY_PLST_ERR_MEAT_PARSER                 (-515)
#define MEDPLY_PLST_ERR_NO_FILE_LOADED              (-516)
#define MEDPLY_PLST_ERR_UNSUPPORT_FORMAT            (-517)
#define MEDPLY_PLST_ERR_MS_MODE                     (-518)
/*****************************/
/*          Marcos           */
/*****************************/
#define ClrBitSet(index, bitset)        ((bitset)[(index)>>3] &= ~(1<<((index)&0x07)))
#define SetBitSet(index, bitset)        ((bitset)[(index)>>3] |= (1<<((index)&0x07)))
#define IsBitSetOn(index, bitset)       ((bitset)[(index)>>3] & (1<<((index)&0x07)))

#define EOS(nob)                        ((nob)>1 ? ((nob)>>1)-1: 0)

#define GET_BITSET_SIZE(total)          (((total%8)>0)?((total/8)+1):(total/8))


/*****************************/
/*          enum             */
/*****************************/
/* driver enum */
typedef enum
{
    MMI_MEDPLY_DRV_PHONE = 0,
#ifdef __FS_CARD_SUPPORT__       
    MMI_MEDPLY_DRV_CARD,
#endif
#ifdef __OTG_ENABLE__
    MMI_MEDPLY_DRV_REMOVABLE_OTG1,
    MMI_MEDPLY_DRV_REMOVABLE_OTG2,
    MMI_MEDPLY_DRV_REMOVABLE_OTG3,
    MMI_MEDPLY_DRV_REMOVABLE_OTG4,
    MMI_MEDPLY_DRV_REMOVABLE_OTG5,
    MMI_MEDPLY_DRV_REMOVABLE_OTG6,
    MMI_MEDPLY_DRV_REMOVABLE_OTG7,
    MMI_MEDPLY_DRV_REMOVABLE_OTG8,
#endif
#ifdef __SIM_PLUS__
    MMI_MEDPLY_DRV_REMOVABLE_SIM1,
    MMI_MEDPLY_DRV_REMOVABLE_SIM2,
    MMI_MEDPLY_DRV_REMOVABLE_SIM3,
    MMI_MEDPLY_DRV_REMOVABLE_SIM4,
#endif    
#ifdef __MSDC2_SD_MMC__
    MMI_MEDPLY_DRV_MSDC2_SD_STORAGE,
#endif /* __MSDC2_SD_MMC__ */
    MMI_MEDPLY_DRV_TOTAL
} mmi_medply_drv_support_list_struct;

/* editor type. */
typedef enum
{
    MMI_MEDPLY_EDITOR_NONE,
    MMI_MEDPLY_EDITOR_NEW,      /* create playlist. */
    MMI_MEDPLY_EDITOR_RENAME,   /* rename playlist. */
    MMI_MEDPLY_EDITOR_NEW_URL,
    MMI_MEDPLY_EDITOR_EDIT_URL, /* enter URL. */
    MMI_MEDPLY_EDITOR_EDIT_META_TEXT, /* edit title/artist/album/genre/description/author. */
    MMI_MEDPLY_EDITOR_EDIT_META_NUMERIC, /* edit year/ track number/volume. */
    MMI_MEDPLY_EDITOR_SAVE_RAM,
    MMI_MEDPLY_EDITOR_TYPE_TOTAL
} mmi_medply_editor_type_enum;

/* generater enum */
typedef enum
{
    MMI_MEDPLY_LIST_PHASE_INIT,   
    MMI_MEDPLY_LIST_PHASE_SET_DRV,
    MMI_MEDPLY_LIST_PHASE_SEARCH_FIRST,
    MMI_MEDPLY_LIST_PHASE_SEARCH_NEXT,
    MMI_MEDPLY_LIST_PHASE_SEARCH_FOLDER,
    MMI_MEDPLY_LIST_PHASE_FORWARDS,
    MMI_MEDPLY_LIST_PHASE_BACKWARDS,
    MMI_MEDPLY_LIST_PHASE_FINISH,
    MMI_MEDPLY_LIST_PHASE_ERR_HDLR,
    MMI_MEDPLY_LIST_PHASE_SEARCH_ODF,
    MMI_MEDPLY_LIST_PHASE_CANCEL,
    MMI_MEDPLY_LIST_PHASE_END
} mmi_medply_generate_phase_enum;

typedef enum
{
    MMI_MEDPLY_GENERATE_ADD,
    MMI_MEDPLY_GENERATE_UPDATE_ALL_DRV,
    MMI_MEDPLY_GENERATE_UPDATE_CURR_DRV,
    MMI_MEDPLY_GENERATE_TOTAL    
} mmi_medply_generate_run_type_enum;

/* playlist type. */
typedef enum
{
    MMI_MEDPLY_PLST_MDP = 1,
    MMI_MEDPLY_PLST_TOTAL
} mmi_medply_playlist_type_enum;

/* repeat mode */
typedef enum
{
    MMI_MEDPLY_REPEAT_OFF = 0,
    MMI_MEDPLY_REPEAT_ONE,
    MMI_MEDPLY_REPEAT_ALL
} mmi_medply_playlist_repeat_type_enum;

/* search item */
typedef enum
{
    MEDPLY_SEARCH_TITEL,
    MEDPLY_SEARCH_ARTIST,
    MEDPLY_SEARCH_ALBUM,
    MEDPLY_SEARCH_GENRE,
    MEDPLY_SEARCH_TOTAL
} mmi_medply_playlist_search_type_enum;

/* search inline item */
typedef enum
{
    MEDPLY_SEARCH_TITLE_CAPTION   = CUI_INLINE_ITEM_ID_BASE,
    MEDPLY_SEARCH_TITLE_DISPLAY,
    MEDPLY_SEARCH_ARTIST_CAPTION,
    MEDPLY_SEARCH_ARTIST_DISPLAY,
    MEDPLY_SEARCH_ALBUM_CAPTION,
    MEDPLY_SEARCH_ALBUM_DISPLAY,
    MEDPLY_SEARCH_GENRE_CAPTION,
    MEDPLY_SEARCH_GENRE_DISPLAY,

    MEDPLY_SEARCH_INLINE_ITEM_END,
    MEDPLY_SEARCH_INLINE_ITEM_NUM = (MEDPLY_SEARCH_INLINE_ITEM_END - CUI_INLINE_ITEM_ID_BASE)
} mmi_medply_playlist_search_inline_item_enum;


/* details enum */
typedef enum
{
    MEDPLY_DETAILS_META_TITLE,
    MEDPLY_DETAILS_META_ARTIST,
    MEDPLY_DETAILS_META_ALBUM,
    MEDPLY_DETAILS_META_GENRE,
    MEDPLY_DETAILS_META_AUTHOR,
    MEDPLY_DETAILS_META_DESCRIPTION,
    MEDPLY_DETAILS_META_TRACK_NUM,
    MEDPLY_DETAILS_META_YEAR,
    MEDPLY_DETAILS_META_USER_RATING,
    MEDPLY_DETAILS_META_TOTAL
} mmi_medply_details_revisable_item_enum;

typedef enum
{
    MEDPLY_DETAILS_META_TITLE_CAPTION   = CUI_INLINE_ITEM_ID_BASE,
    MEDPLY_DETAILS_META_TITLE_DISPLAY,
    MEDPLY_DETAILS_META_ARTIST_CAPTION,
    MEDPLY_DETAILS_META_ARTIST_DISPLAY,
    MEDPLY_DETAILS_META_ALBUM_CAPTION,
    MEDPLY_DETAILS_META_ALBUM_DISPLAY,
    MEDPLY_DETAILS_META_GENRE_CAPTION,
    MEDPLY_DETAILS_META_GENRE_DISPLAY,
    MEDPLY_DETAILS_META_AUTHOR_CAPTION,
    MEDPLY_DETAILS_META_AUTHOR_DISPLAY,
    MEDPLY_DETAILS_META_DESCRIPTION_CAPTION,
    MEDPLY_DETAILS_META_DESCRIPTION_DISPLAY,
    MEDPLY_DETAILS_META_TRACK_NUM_CAPTION,
    MEDPLY_DETAILS_META_TRACK_NUM_DISPLAY,
    MEDPLY_DETAILS_META_YEAR_CAPTION,
    MEDPLY_DETAILS_META_YEAR_DISPLAY,
    MEDPLY_DETAILS_META_USER_RATING_CAPTION,
    MEDPLY_DETAILS_META_USER_RATING_DISPLAY,

    MEDPLY_DETAILS_META_INLINE_ITEM_END,
    MEDPLY_DETAILS_META_INLINE_ITEM_NUM = (MEDPLY_DETAILS_META_INLINE_ITEM_END - CUI_INLINE_ITEM_ID_BASE)
} mmi_medply_details_revisable_inline_item_enum;




#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
typedef enum
{
    MEDPLY_DETAIL_FILENAME,
    MEDPLY_DETAIL_TITLE,
    MEDPLY_DETAIL_ARTIST,
    MEDPLY_DETAIL_ALBUM,
    MEDPLY_DETAIL_AUTHOR,
    MEDPLY_DETAIL_GENRE,
    MEDPLY_DETAIL_COPYRIGHTS,
    MEDPLY_DETAIL_DESCRIPTION,
    MEDPLY_DETAIL_YEAR,
    MEDPLY_DETAIL_TRACK_NUM,
    MEDPLY_DETAIL_DURATION,
    MEDPLY_DETAIL_SIZE,
    MEDPLY_DETAIL_QUALITY,
    MEDPLY_DETAIL_CHANNEL, 
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__    
    MEDPLY_DETAIL_PLAY_COUNT,
    MEDPLY_DETAIL_USER_RATING,
    MEDPLY_DETAIL_VOLUME,
    MEDPLY_DETAIL_LAST_PLAYED,
    MEDPLY_DETAIL_LAST_MODIFIED,
#endif
    MEDPLY_DETAIL_LOCAL,
    MEDPLY_DETAIL_TOTAL
} mmi_medply_detail_items_enum;
#endif

typedef enum
{
    FILENAME_TYPE_CAPTION   = CUI_INLINE_ITEM_ID_BASE, 
    FILENAME_TYPE_ITEM,
    TILTE_TYPE_CAPTION,
    TILTE_TYPE_ITEM,
    ARTIST_TYPE_CAPTION,
    ARTIST_TYPE_ITEM,
    ALBUM_TYPE_CAPTION,
    ALBUM_TYPE_ITEM,
    AUTHOR_TYPE_CAPTION,
    AUTHOR_TYPE_ITEM,
    GENRE_TYPE_CAPTION,
    GENRE_TYPE_ITEM,
    COPYRIGHTS_TYPE_CAPTION,
    COPYRIGHTS_TYPE_ITEM,
    DESCRIPTION_TYPE_CAPTION,
    DESCRIPTION_TYPE_ITEM,
    YEAR_TYPE_CAPTION,
    YEAR_TYPE_ITEM,
    TACKNUM_TYPE_CAPTION,
    TACKNUM_TYPE_ITEM,
    DURATION_TYPE_CAPTION,
    DURATION_TYPE_ITEM,
    SIZE_TYPE_CAPTION,
    SIZE_TYPE_ITEM,
    QUALITY_TYPE_CAPTION,
    QUALITY_TYPE_ITEM,
    CHANNELNUM_TYPE_CAPTION,
    CHANNELNUM_TYPE_ITEM,
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__    
    PLAYCOUNT_TYPE_CAPTION,
    PLAYCOUNT_TYPE_ITEM,
    USERRATE_TYPE_CAPTION,
    USERRATE_TYPE_ITEM,
    VOLUME_TYPE_CAPTION,
    VOLUME_TYPE_ITEM,
    LASTPLAYED_TYPE_CAPTION,
    LASTPLAYED_TYPE_ITEM,
    LASTMODIFIED_TYPE_CAPTION,
    LASTMODIFIED_TYPE_ITEM,
#endif    
    LOCAL_TYPE_CAPTION,
    LOCAL_TYPE_ITEM,

    MEDPLY_PLST_INLINE_ITEM_END,
    MEDPLY_PLST_INLINE_ITEM_NUM = (MEDPLY_PLST_INLINE_ITEM_END - CUI_INLINE_ITEM_ID_BASE)
} mmi_medply_details_inline_item_enum;

typedef enum
{
    MEDPLY_PLST_DETAILS_EDIT_CONFIRM = 0,
    MEDPLY_PLST_ORGANIZE_SAVE_CONFIRM,
    MEDPLY_PLST_SEARCH_RESULT_CONFIRM,
    MEDPLY_PLST_MODULE_REBUILD_CONFIRM,
    
    MEDPLY_PLST_ALERT_TOTAL
}mmi_medply_playlist_alert_enum;


/*****************************/
/*          Struct           */
/*****************************/

/* time struct */
#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
typedef struct
{
    U16 year;
    U8 month;
    U8 day;
    U8 hour;
    U8 min;
} mmi_medply_time_record_struct;
#endif

/* export details data struct. */
typedef struct
{
    U32 size;
    U8* buffer;
    U32 buffer_size;
    U8  mime_type;
} mmi_medply_details_artwork_struct;

typedef struct
{
    U32 size;
    U8  lrc_type;
} mmi_medply_detials_lyrics_struct;

typedef struct
{
    UI_character_type title[MMI_MEDPLY_MAX_TITLE_LEN+1];
    UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN+1];
    UI_character_type album[MMI_MEDPLY_MAX_ALBUM_LEN+1];
    mmi_medply_details_artwork_struct artwork;
    mmi_medply_detials_lyrics_struct lyrics;
    U8 user_rating;
} mmi_medply_details_for_display_struct;

//typedef MMI_BOOL (*Edit_done)(U8 action, S32 result, mmi_id editor_id);

/*
**  Editor.
*/
typedef struct
{
    U8 editor_type;
    U16 limit; 
    U16 editor_title_id;
    MMI_MENU_ID     parent_id;
    UI_string_type original_string_p;
    FuncPtr done_func;
    UI_character_type editor_buffer[MMI_MEDPLY_MAX_EDITOR_LEN + 1];
} mmi_medply_editor_cntx_struct;

/*
** Driver.
*/
typedef struct
{
    U8 is_active;
    CHAR drv_letter;
    U16 reserved;
    U32 serial_number;
} mmi_medply_plst_drv_struct;

/*
** details preview struct
*/
typedef struct
{
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    UI_character_type title[MMI_MEDPLY_MAX_TITLE_LEN];
    UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN];
    UI_character_type album[MMI_MEDPLY_MAX_ALBUM_LEN];
    UI_character_type author[MMI_MEDPLY_MAX_AUTHOR_LEN];
    UI_character_type genre[MMI_MEDPLY_MAX_GENRE_LEN];
    UI_character_type year[MMI_MEDPLY_MAX_YEAR_LEN];
    UI_character_type copyrights[MMI_MEDPLY_MAX_COPYRIGHTS_LEN];
    UI_character_type description[MMI_MEDPLY_MAX_DESCRIPTION_LEN];
    UI_character_type track_num[MMI_MEDPLY_MAX_TRACKNUM_LEN];
    UI_character_type duration[MMI_MEDPLY_MAX_DURATION_LEN];
    UI_character_type size[MMI_MEDPLY_MAX_SIZE_LEN];/* max size for U32 bytes type is "1194:59:59" */
    UI_character_type quality[25];
    UI_character_type channel_num[20];
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__    
    UI_character_type play_count[20];    /* 65536 */ 
    UI_character_type user_rating[MMI_MEDPLY_MAX_USER_RATING_LEN]; 
    UI_character_type volume[20];/* 65535 */
    UI_character_type last_played[MMI_MEDPLY_MAX_TIME_LEN];
    UI_character_type last_modified[MMI_MEDPLY_MAX_TIME_LEN];
#endif    
    UI_character_type local[MEDPLY_MAX_FILE_LEN];
} mmi_medply_details_preview_struct;

/*
** Generater.
*/
typedef struct
{
    U16 level;               /* stack level. */
    U16 total_sub_folder;    /* total sub-folder number in this level. */
    U16 index;               /* current index in all sub-folder. */
    U16 fs_index;            /* fs index for FS_FindFirst(). */
} mmi_medply_plst_stack_node_struct;

/*******************************************************************************
*******************************************************************************/
/* common part end. */



#ifdef __MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__
/*****************************/
/*        definition         */
/*****************************/


/* cache limit. */
#define MMI_MEDPLY_LIST_BUFF_SIZE               (16)

/* database version limit. */
#define MMI_MEDPLY_DB_MIN_DISK_SPACE            (10*1024)

/* limit about most played list and recently played list. */
#define MEDPLY_MAX_RECENT_PLAYED_ITEM           (20)
#define MEDPLY_MAX_MOST_PLAYED_ITEM             (20)

/* default playlist ID. */
typedef enum
{
    MMI_MEDPLY_DB_LST_DUMMEY_ID = 1,
    MMI_MEDPLY_DB_LST_ALL_MEDIA_ID,
    MMI_MEDPLY_DB_LST_RECENT_ID,
    MMI_MEDPLY_DB_LST_BOOKMARK_ID,
    MMI_MEDPLY_DB_LST_FAVOURITE_ID,
    MMI_MEDPLY_DB_LST_MOST_PLAYED_ID,
    MMI_MEDPLY_DB_LST_SEARCH_RESULT_ID,
    MMI_MEDPLY_DB_LST_ON_THE_FLY_ID,
    MMI_MEDPLY_DB_LST_TOTAL
} mmi_medply_db_default_list_id;


#define MMI_MEDPLY_DB_UNKNOWN_ARTIST_ID         (1)
#define MMI_MEDPLY_DB_UNKNOWN_ALBUM_ID          (1)

#define MMI_MEDPLY_BITSET_BLOCK_SIZE            (128)	// support 1024 item
#define MMI_MEDPLY_MAX_URL_LEN                  (256)

/* generate limit. */
#define MMI_MEDPLY_MAX_DEPTH_DIRECTORY          (16)
#define MMI_MEDPLY_MAX_PICK_PER_SLICE           (5)

#define MEDPLY_DB_DEFALUT_PAGE_SIZE				(SQLITE_DEFAULT_PAGE_SIZE)
/* internal file info. */
#define MMI_MEDPLY_DB_FILENAME                  L"media_lib"
#define MMI_MEDPLY_DB_VERSION                   L"_V04" /* version number. */
#define MMI_MEDPLY_DB_VERSION_NUM               (4)
#define MMI_MEDPLY_DB_EXTENSION                 L".db"
#define MMI_MEDPLY_DB_DEFAULT_FOLDER            L"@media_player_internal"
#define MMI_MEDPLY_DB_DEFAULT_DRV               SRV_FMGR_PUBLIC_DRV
#define MMI_MEDPLY_DB_JOURNAL_POSTFIX  			L"-journal"
/* sqlite3 error class */
typedef enum
{
    MEDPLY_NO_ERROR,
    MEDPLY_DB_GOT_DATA,
    MEDPLY_ERR_INTERNAL,
    MEDPLY_ERR_FS,
    MEDPLY_ERR_META,
    MEDPLY_ERR_DB
} mmi_medply_plst_error_type_enum;

/* database version ID type. */
typedef enum
{
    MMI_MEDPLY_DB_MEDIA_ID,
    MMI_MEDPLY_DB_ALBUM_ID,
    MMI_MEDPLY_DB_ARTIST_ID,
    MMI_MEDPLY_DB_PLST_ID,
    MMI_MEDPLY_DB_ID_TYPE_END
} mmi_medply_db_id_type_enum;

/* database table enum. */
typedef enum
{
    MMI_MEDPLY_DB_TABLE_TARGET_INFO,
    MMI_MEDPLY_DB_TABLE_PLAYLIST,
    MMI_MEDPLY_DB_TABLE_PLAYLIST_ITEM,
    MMI_MEDPLY_DB_TABLE_MEDIA,
    MMI_MEDPLY_DB_TABLE_MEDIA_META,
    MMI_MEDPLY_DB_TABLE_MEDIA_EXT,
    MMI_MEDPLY_DB_TABLE_URL,	
    MMI_MEDPLY_DB_TABLE_ENUM_END
} mmi_medply_table_name_enum;

/* database action enum. */
typedef enum
{
    MEDPLY_DB_ACT_CREATE_TABLE = 1,
    MEDPLY_DB_ACT_CREATE_DEFAULT,
    MEDPLY_DB_ACT_SET_TARGET_INFO,
    MEDPLY_DB_ACT_GET_TARGET_INFO,
    /* list manager */
    MEDPLY_DB_ACT_QUERY_TOTAL_OF_LIST,
    MEDPLY_DB_ACT_QUERY_MAX_LIST_ID,
    MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_TITLE,/* 5 */
    MEDPLY_DB_ACT_QUERY_LIST_EXIST_BY_ID,
    MEDPLY_DB_ACT_QUERY_LISTMGR_TBL,
    MEDPLY_DB_ACT_QUERY_LISTMGR_TBL_EXT,
    /* play list */
    MEDPLY_DB_ACT_MODIFY_PLST_CREATE,
    MEDPLY_DB_ACT_MODIFY_PLST_RENAME,       /* 10 */
    MEDPLY_DB_ACT_MODIFY_PLST_CLEAR,
    MEDPLY_DB_ACT_MODIFY_PLST_CLEAR_SUB,
    MEDPLY_DB_ACT_MODIFY_PLST_DELETE,
    MEDPLY_DB_ACT_QUERY_PLST_MAX_ROWID,
    MEDPLY_DB_ACT_QUERY_PLST_TOTAL,
    MEDPLY_DB_ACT_QUERY_PLST_TITLE,
    MEDPLY_DB_ACT_QUERY_PLST_TBL,            /* 15 */
    MEDPLY_DB_ACT_QUERY_PLST_MOST_TBL,
    MEDPLY_DB_ACT_QUERY_PLST_RECENT_TBL,

    /* playlist item */
    MEDPLY_DB_ACT_QUERY_ITEM_EXIST,
    MEDPLY_DB_ACT_QUERY_ITEM_ID,
    MEDPLY_DB_ACT_QUERY_ITEM_ID_EXT,        /* 20 */
    MEDPLY_DB_ACT_QUERY_ITEM_IDX,
    
    MEDPLY_DB_ACT_MODIFY_ITEM_ADD,
    MEDPLY_DB_ACT_MODIFY_ITEM_ADD_EXT,
    MEDPLY_DB_ACT_MODIFY_ITEM_SET_IDX,
    MEDPLY_DB_ACT_MODIFY_ITEM_REMOVE,       /* 25 */
    
    /* media file */
    MEDPLY_DB_ACT_QUERY_MEDIA_MAX_ID,
    MEDPLY_DB_ACT_QUERY_MEDIA_PATH,
    MEDPLY_DB_ACT_QUERY_MEDIA_ID_BY_PATH,
    MEDPLY_DB_ACT_QUERY_MEDIA_TOTAL,
    MEDPLY_DB_ACT_QUERY_MEDIA_BASIC_INFO,   /* 30 */
    MEDPLY_DB_ACT_QUERY_MEDIA_LIST_INFO,
    MEDPLY_DB_ACT_QUERY_MEDIA_EXIST,
    MEDPLY_DB_ACT_QUERY_MEDIA_EXIST_EXT,
    MEDPLY_DB_ACT_QUERY_MEDIA_ARTIST_NAME,
    MEDPLY_DB_ACT_QUERY_MEDIA_ALBUM_TITLE,		/* 35 */
    MEDPLY_DB_ACT_QUERY_MEDIA_FULL_INFO,
    MEDPLY_DB_ACT_QUERY_MEDIA_DISPLAY_INFO,

    MEDPLY_DB_ACT_MODIFY_MEDIA_ADD,
    MEDPLY_DB_ACT_MODIFY_MEDIA_DELETE,
   
    MEDPLY_DB_ACT_MODIFY_MEDIA_MODIFY,
    MEDPLY_DB_ACT_MODIFY_MEDIA_UPDATE_TIME,
    MEDPLY_DB_ACT_MODIFY_MEDIA_INCREACE_COUNT,

    MEDPLY_DB_ACT_MODIFY_ADD_TO_RECENT,
    
    MEDPLY_DB_ACT_QUERY_PATH_BY_PLST_IDX,
    MEDPLY_DB_ACT_QUERY_MEDIA_APPLY_INFO,
    MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TOTAL,
    MEDPLY_DB_ACT_QUERY_ALL_MEDIA_FILE_TBL,

    MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART1,
    MEDPLY_DB_ACT_QUERY_AMF_SEARCH_PART2,
    MEDPLY_DB_ACT_MODIFY_BMK_ADD,
    MEDPLY_DB_ACT_MODIFY_BMK_REMOVE,
    MEDPLY_DB_ACT_QUERY_BMK_INFO,
    MEDPLY_DB_ACT_QUERY_BMK_URL,
    MEDPLY_DB_ACT_QUERY_BMK_TOTAL,
    MEDPLY_DB_ACT_QUERY_BMK_LIST,
    MEDPLY_DB_ACT_QUERY_BMK_EXIST,
    MEDPLY_DB_ACT_MODIFY_BMK_CLEAR,
    MEDPLY_DB_ACT_MODIFY_ITEM_APPEND,
    
    MEDPLY_DB_ACT_END
} mmi_medply_db_action_enum;

/* database column flag */
typedef enum
{
    /* base info. */
    MEDPLY_DB_UPDATE_TITLE              = 0x00000001,
    MEDPLY_DB_UPDATE_ARTIST             = 0x00000002,
    MEDPLY_DB_UPDATE_ALBUM              = 0x00000004,
    /* details info. */
    MEDPLY_DB_UPDATE_GENRE              = 0x00000100,
    MEDPLY_DB_UPDATE_DESCRIPTION        = 0x00000200,
    MEDPLY_DB_UPDATE_AUTHOR             = 0x00000400,
    MEDPLY_DB_UPDATE_YEAR               = 0x00000800,
    MEDPLY_DB_UPDATE_TRACKNUM           = 0x00001000,
    /* ext info. */
    MEDPLY_DB_UPDATE_COUNT              = 0x00010000,
    MEDPLY_DB_UPDATE_VOL                = 0x00020000,
    MEDPLY_DB_UPDATE_RATING             = 0x00040000,
    MEDPLY_DB_UPDATE_PLAYED             = 0x00080000,
    MEDPLY_DB_UPDATE_MODIFIED           = 0x00100000,
    /* display info. */
    MEDPLY_DB_UPDATE_LYRICS             = 0x01000000,
    MEDPLY_DB_UPDATE_ARTWORK            = 0x02000000,
    
    MEDPLY_DB_UPDATE_ALL                = 0x7FFFFFFF
} mmi_medply_db_update_item_flag;

typedef enum
{
    DB_SORT_BY_TITLE    = 0x00000001,/*bsae sorting type. */
    DB_SORT_BY_ARTIST   = 0x00000002,
    DB_SORT_BY_ALBUM    = 0x00000004,
    DB_SORT_BY_GENRE    = 0x00000008,
    DB_SORT_ALL         = 0x0000FFFF
} mmi_medply_db_sorting_type;



/*****************************/
/*          Struct           */
/*****************************/
typedef void (*FuncPtr)(void);

typedef enum
{
    MEDPLY_TARGET_INFO_VERSION,
    MEDPLY_TARGET_INFO_SERIAL,
    MEDPLY_TARGET_INFO_IMEI,
    MEDPLY_TARGET_INFO_CHIP_ID,
    MEDPLY_TARGET_INFO_END
} mmi_medply_target_info_enum;

typedef struct
{
    U32 version;
    U32 default_drv_serial_num;
    U32 imei;
    U32 chip_id;
} mmi_medply_target_info_struct;

typedef struct
{
    U32 media_id;
    S16 year;
    S16 track_num;
    S16 artwork_type;
    S16 lyrics_type;
    UI_character_type title[MMI_MEDPLY_MAX_TITLE_LEN];
    UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN];
    UI_character_type album[MMI_MEDPLY_MAX_ALBUM_LEN];
    UI_character_type genre[MMI_MEDPLY_MAX_GENRE_LEN];
    UI_character_type copyrights[MMI_MEDPLY_MAX_COPYRIGHTS_LEN];
    UI_character_type description[MMI_MEDPLY_MAX_DESCRIPTION_LEN];
    UI_character_type author[MMI_MEDPLY_MAX_AUTHOR_LEN];
} mmi_medply_db_media_meta_struct;


typedef struct
{
    U32 id;
    U32 path_hash;
    U32 serial_num;
    U8  local;
    U8  reserved;
    U16 format;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
} mmi_medply_db_media_base_struct;


typedef struct
{
    U32 media_id;
    U16 play_count;
    S16 volume;
    U8  user_rating;
    U8  reserved;
    mmi_medply_time_record_struct last_played;
    mmi_medply_time_record_struct last_modified;    
} mmi_medply_db_media_ext_struct;

typedef struct
{
	U32 url_hash;
	UI_character_type url[MMI_MEDPLY_MAX_URL_LEN];
	UI_character_type title[MEDPLY_MAX_FILE_LEN];
	U16 type;
} mmi_medply_db_bookmark_item_struct;

/*
** details struct 
*/
typedef struct
{
    U32 id;
    
    U16 format;
    S16 year;
    S16 track_num;
    S16 volume;
    U16 play_count;

    U32 serial_num;
    U8 local;
    U8 user_rating;
    S16 lyrics_type;
    S16 artwork_type;
    U32 path_hash;
    UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN];
    UI_character_type album[MMI_MEDPLY_MAX_ALBUM_LEN];
    UI_character_type title[MMI_MEDPLY_MAX_TITLE_LEN];
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    UI_character_type copyrights[MMI_MEDPLY_MAX_COPYRIGHTS_LEN];
    UI_character_type description[MMI_MEDPLY_MAX_DESCRIPTION_LEN];
    UI_character_type author[MMI_MEDPLY_MAX_AUTHOR_LEN];
    UI_character_type genre[MMI_MEDPLY_MAX_GENRE_LEN];
    
    mmi_medply_time_record_struct last_played;
    mmi_medply_time_record_struct last_modified;
} mmi_medply_db_media_struct;


typedef struct
{
    U16 initiate_grp_id;
    U16 initiate_scr_id;
    U16 preview_title_id[MEDPLY_DETAIL_TOTAL];
    U32 media_id;
    UI_character_type media_path[MEDPLY_MAX_PATH_LEN];
    
    mmi_medply_details_preview_struct* preview_data_p;
#ifdef DETAILS_SUPPORT_EDIT
    mmi_medply_details_preview_struct* preview_backup_p;
    mmi_medply_db_media_struct*	db_raw_data_p;

    U8 set_rate_scr_higlight_index;
    U8 reserved;
    
    U16 edit_index;
    U16 highlighted_item;
    U32 modify_flag;
#endif
} mmi_medply_details_cntx_struct;


/*
** Table.
*/
typedef struct
{
    U32 size;/* total = size / sizeof(U32) */
    U32* data;
    U32 pattern;/* for debug. */
} mmi_medply_db_tbl_struct;

/*
** Bitset
*/
typedef struct
{
    U32 size;
    U8* data;
} mmi_medply_db_bitset_struct;


/*
** Organize.
*/
typedef struct
{   
    MMI_BOOL list_changed;
    MMI_BOOL hold;
    MMI_BOOL exchanged;
    
    S32 save_count;
    S32 hold_hilite;
    S32 hilite;
    S32 last_hilite;
    U32 hold_id;
    mmi_medply_db_tbl_struct backup_table; 
    
    FuncPtr save_func;
} mmi_medply_plstui_organize_struct;


/*
**  Search.
*/
typedef struct
{
    UI_character_type s_title[MMI_MEDPLY_MAX_TITLE_LEN + 2];/*include two wildcards*/
    UI_character_type s_artist[MMI_MEDPLY_MAX_ARTISRT_LEN + 2];
    UI_character_type s_album[MMI_MEDPLY_MAX_ALBUM_LEN + 2];
    UI_character_type s_genre[MMI_MEDPLY_MAX_GENRE_LEN + 2];

    U16 highlighted_item;
    U16 edit_index;
    U16 initiate_grp_id;
    U16 initiate_scr_id;
    U16 result_scr_id;
    U32 result_total;
} mmi_medply_db_search_struct;


/*
** Generate.
*/
typedef struct
{
    U8  run_type;   /* add or update. */
    U8  drv_idx;
    U16 initiate_grp_id;
    U16 initiate_scr_id;
    U16 phase;
    U16 stack_index;     /* folder level & stack level. */
    U32 found;
    U32 appended;
    S32 last_error_code;
    FS_HANDLE search_handle;
    UI_character_type path_cache[MEDPLY_MAX_PATH_LEN];
    mmi_medply_plst_stack_node_struct stack[MMI_MEDPLY_MAX_DEPTH_DIRECTORY];
#ifdef __DRM_V02__
    void* DRM_find_cntx;
#endif
} mmi_medply_generate_cntx_struct;

/*
**  option data.
*/
typedef struct
{
    UI_character_type curr_hilite_path[MEDPLY_MAX_PATH_LEN];
    U32 curr_hilite_id;
    S32 opt_hilite_index;
    U16 opt_menu_id;
    U16 opt_scr_id;
    //MMI_BOOL is_show_rit;
} mmi_medply_plstui_opt_data_struct;

/*
**  list cache
*/
typedef struct
{
    U32 media_id;
    U16 format;
    U16 reserved;
    UI_character_type title[MEDPLY_MAX_FILE_LEN];  
} mmi_medply_plstui_db_cache_item_struct;

typedef struct
{
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    UI_character_type ext[MEDPLY_MAX_EXT_LEN];   
    U16 file_type;
    U8  is_short;
    U8  reserved;
} mmi_medply_plstui_normal_cache_item_struct;

typedef struct
{
    U64 rowid_begin;
    U64 rowid_end;
} mmi_medply_db_list_clear_struct;

typedef struct
{
    S32 error;
    U32 list_id;
    U32 cur_index;
    U32 total;
    U32 count;
    U32 done_count;
    U32 commit_count;
    mmi_medply_db_tbl_struct *id_tbl;
} mmi_medply_db_add_marked_struct;

typedef struct
{
    U32 target_id;
    U16 target_grp_id;
    U16 target_scr_id;
    U16 total;
    U16 selected;
    mmi_medply_db_bitset_struct bitset;
} mmi_medply_plstui_multiselect_struct;

typedef struct
{
    S32 hint_idx;
    UI_character_type hint_buff[MAX_SUBMENU_CHARACTERS];
} mmi_medply_plstui_hint_cache_struct;


typedef struct
{
    U16 initiate_grp_id;
    U16 initiate_scr_id;
    U16 list_grp_id;
    U16 list_scr_id;

    U32 plstid;
    U32 plstid_original;
    U32 flag;/* multiplex flag: sorting type. */
    mmi_medply_db_tbl_struct id_table;  /* array to save all media files' ID list which sort by name and type. */ 
    UI_character_type title[MEDPLY_MAX_FILE_LEN];
    /* Add-ons */
    union
    {
        mmi_medply_plstui_multiselect_struct multiselect;
        mmi_medply_plstui_opt_data_struct opt_data;
        mmi_medply_plstui_organize_struct organize;
    } add_ons;
    /* cache */
    S32 head;
    S32 tail; 
    S32 total;
    S32 highlight; 
    mmi_medply_plstui_hint_cache_struct hint_cache;
    mmi_medply_plstui_db_cache_item_struct db_cache[MMI_MEDPLY_LIST_BUFF_SIZE];   
} mmi_medply_plstui_list_cache_struct;


/*
**  intro play
*/
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
typedef struct
{
    S32 total;
    S32 begin_idx;
    S32 count;
    S32 pick_idx;
    U32 plst_id;
    U32 picked_id;
} mmi_medply_plst_intro_play_struct;
#endif /* __MMI_MEDIA_PLAYER_INTRO_PLAY__ */

typedef struct
{
    MMI_BOOL loaded;
    S32 total;
    S32 pick_index;
    S32 pick_count;
    S32 played_count;
    mmi_medply_db_bitset_struct bitset;
    UI_character_type title[MEDPLY_MAX_FILE_LEN];
    
    U32 plst_id;
    U32 id;
} mmi_medply_plst_playing_cntx_struct;

#define MEDPLY_MAX_LIST_CACHE           (5)

typedef struct
{
    mmi_medply_details_cntx_struct      details_cntx;
    mmi_medply_editor_cntx_struct       editor_cntx;
    U8 stack_count;
    mmi_medply_plstui_list_cache_struct     *list_stack[MEDPLY_MAX_LIST_CACHE];
} mmi_medply_ui_cntx_struct;

typedef struct
{
    mmi_medply_plst_playing_cntx_struct playing;
#ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
    mmi_medply_plst_intro_play_struct intro;
#endif
} mmi_medply_list_cntx_struct;

/* common part end. */


typedef struct
{
    MMI_BOOL enable_count;
    MMI_BOOL instance_initialized;
    MMI_BOOL db_opend;
    MMI_BOOL in_transaction;
    void* sqlite_buf;
    sqlite3* db;
    sqlite3_instance sqlite_instance;
    UI_character_type db_path[MEDPLY_MAX_PATH_LEN];
} mmi_medply_db_cntx_struct;


/* playlist module cntx - style 2 */
typedef struct
{
    MMI_BOOL list_module_ready;
    mmi_medply_db_cntx_struct           db_cntx;
    mmi_medply_list_cntx_struct         list_cntx;
    mmi_medply_ui_cntx_struct           ui_cntx;
    
    mmi_medply_plst_drv_struct          drv_list[MMI_MEDPLY_DRV_TOTAL];
    mmi_medply_db_search_struct         search_cntx;
    mmi_medply_generate_cntx_struct     *generate_cntx_p;
} mmi_medply_plst_cntx_struct;


#else
/*****************************/
/*        definition         */
/*****************************/

/* list cache buffer size. */
#define MMI_MEDPLY_LIST_BUFF_SIZE               (16)

/* generate limit */
#define MMI_MEDPLY_MAX_PICK_PER_SLICE           (10)
#define MMI_MEDPLY_GENERATE_LIMIT               MMI_MEDPLY_MAX_PLAYLIST_ITEM
#define MMI_MEDPLY_MAX_DEPTH_DIRECTORY          (16)

/* max list item limit. */
#define MMI_MEDPLY_MAX_PLAYLIST_ITEM            (1024)

/* bitset buffer size. */
#define MMI_MEDPLY_MAX_BITSET_SIZE              (MMI_MEDPLY_MAX_PLAYLIST_ITEM / 8)

/* block size. */
#define MMI_MEDPLY_BLOCK_DATA_SIZE              (130)

/* max block number of one record. */
#define MMI_MEDPLY_MAX_BLOCK_NUM                (MEDPLY_MAX_PATH_LEN / (MMI_MEDPLY_BLOCK_DATA_SIZE / sizeof(UI_character_type)))

/* definition for file system. */
#define MMI_MEDPLY_DEFAULT_FOLDER                       L"@Playlists"
#define MMI_MEDPLY_DEFAULT_LIST_EXT                     L".mdp"
#define MMI_MEDPLY_DEFAULT_LIST_EXT_NO_DOT              L"mdp"
#define MUSIC_FOLDER                                    L"My Music\\"
#define MMI_MEDPLY_ALL_AUDIO_LIST                       L"All songs"
#define MMI_MEDPLY_ALL_VIDEO_LIST                       L"All videos"

typedef struct
{
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];   
    U16 index_in_list;
    U8 file_type;
    U8 is_short;
    MMI_BOOL is_used;
#ifdef __MMI_KURO_SUPPORT__
    U8 is_activate;
#endif
} mmi_medply_dynamic_list_item_info_struct;

typedef void (*FuncPtr)(void);

typedef struct
{
    U16 initiate_scr_id;
    
    MMI_BOOL list_changed;
    MMI_BOOL hold;
    MMI_BOOL exchanged;
    
    S32 total;
    S32 hold_hilite;
    S32 hilite;
    S32 last_hilite;
    
    U32* index_table;
    
    FuncPtr save_func;
    mmi_medply_dynamic_list_item_info_struct hold_item;
} mmi_medply_plst_organize_struct;

typedef struct
{
    U32 list_total;
    U8  run_type;   /* add or update. */
    U32 footer_pattern_offset;
    FS_HANDLE list_file_handle;
} mmi_medply_plst_generate_setting_struct;


typedef S32 (*AppendPtr)(UI_string_type, MMI_BOOL);


typedef struct
{
/* data given by caller. */
    U32 list_total;
    U32 appended;
    U8  run_type;   /* add or update. */
} mmi_medply_plst_generate_struct;

#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
typedef struct
{
    U16 initiate_scr_id;
    U16 preview_title_id[MEDPLY_DETAIL_TOTAL];
    
    mmi_medply_details_preview_struct* preview_data_p;
    
    
    U32 media_id;
    UI_character_type media_path[MEDPLY_MAX_PATH_LEN];
} mmi_medply_details_struct;
#endif

typedef struct
{
    U32 total;
    U32 highlight;
    U16 cache_start_index;
    U16 cache_end_index;
    U16 head;
    U16 tail;
    UI_character_type temp_buffer[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_item_info_struct cache[MMI_MEDPLY_LIST_BUFF_SIZE];
    MMI_BOOL cancel_deleteall;
} mmi_medply_dynamic_list_data_struct;

 
typedef struct
{
    U32 pattern_begin;
    U32 next_ptr;
    U32 pattern_end;
    CHAR data[MMI_MEDPLY_BLOCK_DATA_SIZE];
} mmi_medply_plst_block_node_struct;

typedef struct
{
    U32 offset;
    U16 index;
    U8  used_block;
    U8  is_active;  /* short name: is_active == 2, long name: is_active == 1. */
} mmi_medply_plst_index_node_struct;


typedef struct
{
    CHAR type_id[4];
    CHAR version[2];
    U16 total_slot;
    U32 footer_pattern_offset;
    mmi_medply_plst_index_node_struct empty_node;
    mmi_medply_plst_index_node_struct index[MMI_MEDPLY_MAX_PLAYLIST_ITEM];
    U32 pattern;
} mmi_medply_plst_header_struct;

#define MEDPLY_PLAYLIST_TYPE_ID                 "ALST"
#define MEDPLY_PLAYLIST_VERSION                 "02"
#define MEDPLY_PLAYLIST_DATA_OFFSET             (sizeof(mmi_medply_plst_header_struct))
#define MEDPLY_PLAYLIST_FOOTER_PATTERN          0xFEFEFEFE
#define MEDPLY_PLAYLIST_BLOCK_PATTERN_1         0x3F3F3F3F      
#define MEDPLY_PLAYLIST_BLOCK_PATTERN_2         0x4F4F4F4F


typedef struct
{
    S32 pick_index;
    S32 pick_count;
    S32 total;
    
    U8 bitset[MMI_MEDPLY_MAX_BITSET_SIZE];
    FS_HANDLE fs_hdlr;
    
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    UI_character_type title[MEDPLY_MAX_FILE_LEN];	
    mmi_medply_plst_header_struct header;
} mmi_medply_plst_struct;

#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
typedef struct
{
    U8 default_storage;
    MMI_BOOL list_module_ready;
    MMI_BOOL list_loaded;
#ifdef __MMI_KURO_SUPPORT__
    MMI_BOOL activate_from_list;
#endif
    mmi_medply_plst_drv_struct drv_list[MMI_MEDPLY_DRV_TOTAL];

    mmi_medply_editor_cntx_struct editor;
    mmi_medply_details_struct details_cntx;

    mmi_medply_plst_struct *browser_list_p;
    mmi_medply_plst_struct *backup_list_p;
    mmi_medply_plst_struct current_list;
    mmi_medply_dynamic_list_data_struct list_ui;
    mmi_medply_plst_generate_struct generate_cntx;
} mmi_medply_plst_cntx_struct;
#endif



/********************************* search cui start *************************************/
/* length macro */
#define MEDPLY_CUI_SEARCH_FILE_LEN                      (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)
#define MEDPLY_CUI_SEARCH_PATH_LEN                      (SRV_FMGR_PATH_MAX_LEN + 1)
#define MEDPLY_CUI_SEARCH_EXT_LEN                       (SRV_FMGR_PATH_MAX_FILE_EXT_LEN)
/* search limit */
#define MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY           (16)
#define MEDPLY_CUI_SEARCH_MAX_PICK_PER_SLICE            (8)

/* search phase enum */
typedef enum
{
    MEDPLY_CUI_SEARCH_PHASE_INIT,   
    MEDPLY_CUI_SEARCH_PHASE_SET_DRV,
    MEDPLY_CUI_SEARCH_PHASE_SEARCH_FIRST,
    MEDPLY_CUI_SEARCH_PHASE_SEARCH_NEXT,
    MEDPLY_CUI_SEARCH_PHASE_SEARCH_FOLDER,
    MEDPLY_CUI_SEARCH_PHASE_FORWARDS,
    MEDPLY_CUI_SEARCH_PHASE_BACKWARDS,
    MEDPLY_CUI_SEARCH_PHASE_FINISH,
    MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR,
    MEDPLY_CUI_SEARCH_PHASE_SEARCH_ODF,
    MEDPLY_CUI_SEARCH_PHASE_CANCEL,
    MEDPLY_CUI_SEARCH_PHASE_END
} mmi_medply_cui_search_phase;

/* CUI search error enum */
typedef enum
{
    MEDPLY_CUI_SEARCH_ERR_NO_ERROR = 0,
    MEDPLY_CUI_SEARCH_ERR_NO_MEMORY = -1000,
    MEDPLY_CUI_SEARCH_ERR_UNKNOW,

    MEDPLY_CUI_SEARCH_ERR_TOTAL
} mmi_medply_cui_search_error;

/* CUI search type enum */
typedef enum
{
    MEDPLY_CUI_SEARCH_TYPE_UPDATE_DEFAULT = 0,
    MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV = 0,
    MEDPLY_CUI_SEARCH_TYPE_UPDATE_FOLDER, /* search from folder with init path , need to set path before run*/
    MEDPLY_CUI_SEARCH_TYPE_ADD_FOLDER,  // N/A

    MEDPLY_CUI_SEARCH_TYPE_TOTAL
} mmi_medply_cui_search_type;

/* CUI search filter enum */
typedef enum
{
    MEDPLY_CUI_SEARCH_FILTER_DEFAULT = 0,
    MEDPLY_CUI_SEARCH_FILTER_ALL_MEDIA = 0,
    MEDPLY_CUI_SEARCH_FILTER_AUDIO,
    MEDPLY_CUI_SEARCH_FILTER_VIDEO,

    MEDPLY_CUI_SEARCH_FILTER_TOTAL
} mmi_medply_cui_search_filter;

/* CUI search driver */
typedef struct
{
    U8                                  is_active;
    CHAR                                  drv_letter;
    U16                                 reserved;
    U32                                 serial_number;
} mmi_medply_cui_search_drv_struct;

/* CUI search internal context struct */
typedef struct
{
    U8                                  drv_idx;
    mmi_id                              parent_id;
    mmi_id                              search_cui_gid;
    mmi_id                              waiting_scr_gid;
    U16                                 stack_index;     /* folder level & stack level. */
    U16                                 phase;
    WCHAR                               path_cache[MEDPLY_CUI_SEARCH_PATH_LEN];
    WCHAR                               file_path[MEDPLY_CUI_SEARCH_PATH_LEN];
    mmi_medply_cui_search_drv_struct    drv_list[MMI_MEDPLY_DRV_TOTAL];
    mmi_medply_plst_stack_node_struct   stack[MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY];
    S32                                 last_error_code;
    FS_HANDLE                           search_handle;
    void*                               DRM_find_cntx;
} mmi_medply_cui_search_struct;

/* CUI search context struct */
typedef struct
{
    S32                                 run_timer;
    S32                                 no_cancel;  // 0: use cancel in waiting screen ; 1: no cancel;
    S32                                 is_multi_part_odf;
    mmi_medply_cui_search_type          run_type;
    mmi_medply_cui_search_filter        run_filter;
    mmi_medply_cui_search_struct        search;
    
} mmi_medply_cui_search_context_struct;


/*Search CUI event start*/
//EVT_ID_MEDPLY_CUI_SEARCH_CLOSE,
//EVT_ID_MEDPLY_CUI_SEARCH_FINISH,
//EVT_ID_MEDPLY_CUI_SEARCH_ERROR,
//EVT_ID_MEDPLY_CUI_SEARCH_CANCEL,
//EVT_ID_MEDPLY_CUI_SEARCH_APPEND,
/*Search CUI event end*/

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_id search_cui_gid;
} mmi_medply_cui_search_close_event_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_id search_cui_gid;
} mmi_medply_cui_search_finish_event_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_id search_cui_gid;
    S32 error_code;
} mmi_medply_cui_search_error_event_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_id search_cui_gid;
} mmi_medply_cui_search_cancel_event_struct;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    mmi_id search_cui_gid;
    WCHAR* filepath;
} mmi_medply_cui_search_append_event_struct;

/********************************* search cui end *************************************/



#endif /**********************************************************************/
extern S32 mmi_medply_plst_get_current_details(mmi_medply_details_for_display_struct* details_data);
extern S32 mmi_medply_plst_get_current_artwork(void* buffer, U32 buffer_size);
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
extern S32 mmi_medply_plst_get_current_artwork_ex(void* buffer, U32* buffer_size);
extern MMI_BOOL mmi_medply_plst_is_video_list(void);
#endif

#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
extern void mmi_medply_plst_popup_simple_ex(S32 error_code, U16 line);
extern void mmi_medply_plst_popup_simple_with_string_ex(WCHAR* string, mmi_event_notify_enum event_id, U16 line);
#define mmi_medply_plst_popup_simple_with_string(string, event_id) \
        mmi_medply_plst_popup_simple_with_string_ex(string, event_id, __LINE__)
#define mmi_medply_plst_popup_simple(error_code) \
        mmi_medply_plst_popup_simple_ex(error_code, __LINE__)
#else
extern void mmi_medply_plst_popup_simple(S32 error_code);
extern void mmi_medply_plst_popup_simple_with_string(WCHAR* string, mmi_event_notify_enum event_id);
#endif
extern FuncPtr mmi_medply_util_get_menu_handler(U16 menu_id);
extern void mmi_medply_plst_display_popup(S32 error_code, FuncPtr callback);
extern void mmi_medply_plst_confirm_simple(MMI_ID parent_id, WCHAR* string, FuncPtr confirm_done, mmi_confirm_type_enum type, MMI_BOOL no_csk_icon,  mmi_event_notify_enum event_type);
extern void mmi_medply_plst_confirm(MMI_ID parent_id, WCHAR* string, mmi_medply_playlist_alert_enum alert_type, mmi_confirm_type_enum type, MMI_BOOL no_csk_icon,  mmi_event_notify_enum event_type);
extern void mmi_medply_plst_clear_gui_buffer(U16 parent_id, U16 scr_id);
extern void mmi_medply_plst_generic_exit_screen(MMI_ID parent_id, U16 scrnID, mmi_proc_func entryFuncPtr);

#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
extern void mmi_medply_plst_gobacktomain(void);
extern S32 mmi_medply_plst_listmgr_list_all(void);
extern MMI_BOOL mmi_medply_plst_storage_check(void);

#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */

#endif /* __MMI_MEDIA_PLAYER__ */ 

#endif /* __MEDIA_PLAYER_PLAY_LIST_H__ */


