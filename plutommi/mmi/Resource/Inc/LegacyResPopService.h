#ifndef __LEGACY_RES_POP_SERVICE_H__
#define __LEGACY_RES_POP_SERVICE_H__

/////////////////////////////////////////////
// Resource Population Controller 
/////////////////////////////////////////////
extern void LegcayResPopController();

extern void PopulateResDataPreXML();
extern void PopulateResDataXML();
extern void PopulateResDataPostXML();


/////////////////////////////////////////////
// Res Population Init Functions
/////////////////////////////////////////////


// Image-------------------------------------
extern void ResPopImageSlimInit();
extern void ResPopImageIdListInit();
extern void ResPopImageUsageMetaFileInit();
extern void	ResPopImageDataFileInit();
extern void ResPopImageCurrIndexInit();
extern void ResPopImageENFBDataFileInit();
extern void ResPopImageIdMapInit();
//-------------------------------------------

// String------------------------------------
extern void ResPopStringIdListInit();
extern void ResPopStringUsageMetaFileInit();
extern void ResPopStringIdListWriteHeader();
extern void ResPopStringCurrIndexInit();
extern void ResPopStingCompressInit();
//-------------------------------------------

// Menu--------------------------------------
extern void ResPopMenuIdListInit();
extern void ResPopMenuUsageMetaFileInit();
extern void ResPopMenuCurrIndexInit();
extern void	ResPopMenuParentIdsInit();
extern void ResPopMenuHandlersInit();
//-------------------------------------------

// Audio-------------------------------------
extern void ResPopAudioIdListInit();
extern void ResPopAudioUsageMetaFileInit();
extern void ResPopAudioDataFileInit();
extern void ResPopAudioCurrIndexInit();
extern void ResPopAudioIdMapInit();
//-------------------------------------------

// Binary------------------------------------
extern void ResPopBinaryIdListInit();
//-------------------------------------------

// Shared Resource---------------------------
extern void ResPopSharedRepeadIdInit();
extern void	ResPopSharedPrintResBaseTable();
extern void ResPopSharedENFBCurrIndexInit();
extern void	ResPopSharedDefaultResourceInit();
//-------------------------------------------

// Font--------------------------------------
extern void ResPopFontObjListInit();
extern void ResPopFontDataFileInit();
extern void ResPopFontCurrIndexInit();
extern void ResPopFontIdMapInit();
//-------------------------------------------

// Others------------------------------------
extern void ResPopNFBImageInit();
extern void ResPopJavaGameDataFileInit();
extern void ResPopInitAll();
//-------------------------------------------


//////////////////////////////////////////
// Res Population Deinit Functions
//////////////////////////////////////////
extern void ResPopImageBinaryExecPostActions();
extern void ResPopImageIdListDeinit();
extern void ResPopImageUsageMetaFileDeinit();
extern void ResPopImageENFBDataFileDeinit();

// Others------------------------------------
extern void ResPopNFBImageDeinit();
extern void ResPopDeinitAll();
//-------------------------------------------

// String------------------------------------
extern void ResPopStringIdListDeinit();
extern void ResPopStringUsageMetaFileDeinit();
//-------------------------------------------


// Audio-------------------------------------
extern void	ResPopAudioIdListDeinit();
extern void ResPopAudioUsageMetaFileDeinit();
//-------------------------------------------

// Binary------------------------------------
extern void ResPopBinaryIdListDeinit();
//-------------------------------------------

// Shared Resource---------------------------
extern void ResPopSharedRepeadIdListDeinit();
//-------------------------------------------

// Menu--------------------------------------
extern void ResPopMenuIdListDeinit();
extern void ResPopMenuUsageMetaFileDeinit();
//-------------------------------------------

// Font--------------------------------------
extern void ResPopFontObjListDeInit();
//-------------------------------------------

#endif //__LEGACY_RES_POP_SERVICE_H__