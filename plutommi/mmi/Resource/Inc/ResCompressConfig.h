#ifndef __RES_COMPRESS_CONFIG_H__
#define __RES_COMPRESS_CONFIG_H__

#include "MMI_features.h"

// Define MMI resource slim option for 6261
#ifndef __MMI_RESOURCE_6261_SLIM__
    #define __MMI_RESOURCE_6261_SLIM__
#endif

#if defined(__MMI_RESOURCE_IMAGE_THIRD_ROM__) && !defined(__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__)
    #ifdef __COSMOS_MMI__
	    #define RES_MULTI_IMG_GROUP_MAX_SIZE (2 * 1024)
	    #define RES_SINGLE_IMG_GROUP_MAX_SIZE (10 * 1024)
	    #define RES_BOOT_IMG_GROUP_MAX_SIZE (24 * 1024)
	    // The number of bits of image offset field in Handle
	    // | Group Index  | Image offset| Compression Flag |
	    #define IMAGE_HANDL_OFFSET_LENGTH (5)
    #else // __COSMOS_MMI__
	    #define RES_MULTI_IMG_GROUP_MAX_SIZE (2 * 1024)
	    #define RES_SINGLE_IMG_GROUP_MAX_SIZE (10 * 1024)
	    #define RES_BOOT_IMG_GROUP_MAX_SIZE (10 * 1024)
	    // The number of bits of image offset field in Handle
	    // | Group Index  | Image offset| Compression Flag |
	    #define IMAGE_HANDL_OFFSET_LENGTH (5)
    #endif // __COSMOS_MMI__
#else
	  #if defined(__MMI_FTE_SUPPORT__) && (defined(__32_32_SEG__) || defined(__64_32_SEG__) || defined(__32_64_SEG__)) && defined(__MMI_MAINLCD_240X320__)
    		#define RES_SINGLE_IMG_GROUP_MAX_SIZE (4 * 1024)
   		  #define RES_MULTI_IMG_GROUP_MAX_SIZE (4 * 1024)
        #define RES_BOOT_IMG_GROUP_MAX_SIZE (4 * 1024)
        // The number of bits of image offset field in Handle
       // | Group Index  | Image offset| Compression Flag |
        #define IMAGE_HANDL_OFFSET_LENGTH (5)
    #else
        #define RES_SINGLE_IMG_GROUP_MAX_SIZE (3 * 1024)
   		  #define RES_MULTI_IMG_GROUP_MAX_SIZE (3 * 1024)
        #define RES_BOOT_IMG_GROUP_MAX_SIZE (3 * 1024)   
        // The number of bits of image offset field in Handle
       // | Group Index  | Image offset| Compression Flag |
       #define IMAGE_HANDL_OFFSET_LENGTH (5)
    #endif
#endif //__MMI_RESOURCE_IMAGE_THIRD_ROM__


#ifdef __COSMOS_MMI_PACKAGE__
    #define RES_BOOT_IMG_GROUPD_ID_CONFIG "IMG_ID_VAPP_BOOTUP_ANIMATION"
#endif //__COSMOS_MMI_PACKAGE__

#define DEFAULT_IMAGE_CACHE_POOL 0

// Control if the image resoruce are cached by group or single image
// #define __MMI_RESOURCE_IMAGE_CACHCED_BY_GROUP__

// Hook GetImage for GetImageData UT:
// Use cache to simulate the original GetImage hehavior
// In this mode, GetImage = GetImageHandle + GetImageContent
//#define __MMI_RESOURCE_UT_HOOK_WITH_GET_IMAGE_CONTENT__

// Hook GetImage for GetImageData UT:
// Compare image from cached decompression pool and original image pool
// But return the image in original image pool,
// so that the behavior is just like __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__ disabled state
//#define __MMI_RRESOURCE_UT_HOOK_WITH_ORIGINAL_COMPARE__

// Support get original image content with debugging API
// It shoud not be enabled in official build
// API List:
//    - extern S8 *DebugGetImageRaw(U16 ImageId);
//    - extern S8 *DebugGetImage(U16 ImageId);
//#define __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__

// A simple cache only support group data stroring and the data 
// is never flushed, only used in image group compression UT
//#define __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__

// Helper APIs for develop group image decompress and cache system
// API List:
//    - extern S8 *DebugGetImageHandle(U16 ImageId);
//    - extern S8 *DebugGetImageHandleRaw(U16 ImageId);
//    - extern MMI_BOOL DebugImageCompare(S8 * image, S8* image2)
//#define __MMI_RESOURCE_UT_IMAGE_GROUP_DEBUG_HELPER__

//ADD MMI_Trace for ResSlim
#if 0
/* under construction !*/
#endif

// Auto configurtion for image handle parsing
#define IMAGE_GROUP_COMPRESSION_FLAG (0x00000001)
#define IMAGE_GROUP_MASK ( (0xFFFFFFFF >> (IMAGE_HANDL_OFFSET_LENGTH+1)) << (IMAGE_HANDL_OFFSET_LENGTH+1))

// Assigned Default Cache Size
#if !defined( __MMI_RESOURCE_IMAGE_CACHE_SIZE__)
    #if defined(__VENUS_UI_ENGINE__)
        #ifdef __COSMOS_MMI__
            #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
                #ifdef __MMI_RESOURCE_IMAGE_THIRD_ROM__
                    #define MMI_RESOURCE_IMAGE_CACHE_SIZE (80 * 1024)
                #else //__MMI_RESOURCE_IMAGE_THIRD_ROM__
                    #define MMI_RESOURCE_IMAGE_CACHE_SIZE (32 * 1024)
                #endif //#ifdef __MMI_RESOURCE_IMAGE_THIRD_ROM__
            #else
                #define MMI_RESOURCE_IMAGE_CACHE_SIZE (64 * 1024)
            #endif
        #else
            #define MMI_RESOURCE_IMAGE_CACHE_SIZE (64 * 1024)
        #endif //__COSMOS_MMI__
    #else //__VENUS_UI_ENGINE__
        #ifdef __MMI_FTE_SUPPORT__
            #if defined(__32_32_SEG__)
                #define MMI_RESOURCE_IMAGE_CACHE_SIZE (32 * 1024)
            #else
                #define MMI_RESOURCE_IMAGE_CACHE_SIZE (48 * 1024)
            #endif //__32_32_SEG__
        #else  //__MMI_FTE_SUPPORT__
            #ifdef __MMI_RESOURCE_IMAGE_THIRD_ROM__
                #define MMI_RESOURCE_IMAGE_CACHE_SIZE (32 * 1024)
            #else //__MMI_RESOURCE_IMAGE_THIRD_ROM__
                #if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_360X640__) ||defined(__MMI_MAINLCD_480X800__)
                    #define MMI_RESOURCE_IMAGE_CACHE_SIZE (48 * 1024)
                #else // (__MMI_MAINLCD_320X480__) || (__MMI_MAINLCD_360X640__) ||(__MMI_MAINLCD_480X800__)
                    #ifdef __MMI_RESOURCE_6261_SLIM__
                        #define MMI_RESOURCE_IMAGE_CACHE_SIZE (15 * 1024)
                    #else
                    #define MMI_RESOURCE_IMAGE_CACHE_SIZE (24 * 1024)
                    #endif
                #endif // (__MMI_MAINLCD_320X480__) || (__MMI_MAINLCD_360X640__) ||(__MMI_MAINLCD_480X800__)
            #endif //__MMI_RESOURCE_IMAGE_THIRD_ROM__
        #endif //__MMI_FTE_SUPPORT__
    #endif //__VENUS_UI_ENGINE__
#else // __MMI_RESOURCE_IMAGE_CACHE_SIZE__
    #define MMI_RESOURCE_IMAGE_CACHE_SIZE (__MMI_RESOURCE_IMAGE_CACHE_SIZE__)
#endif // __MMI_RESOURCE_IMAGE_CACHE_SIZE__

#ifdef __MMI_FONT_GROUP_COMPRESSION__
	#define RESORCE_LZMA_DECOMPRESS_WORKING_BUFFER_SIZE (16 * 1024)
#else
#define RESORCE_LZMA_DECOMPRESS_WORKING_BUFFER_SIZE (10 * 1024)
#endif

// Define String Compressor here, Support __MMI_RESOURCE_STR_LZMA_COMPRESS__ and __MMI_RESOURCE_STR_ZLIB_COMPRESS__
#ifdef __MMI_RESOURCE_STR_COMPRESS__
    #define __MMI_RESOURCE_STR_LZMA_COMPRESS__
#endif //__MMI_RESOURCE_STR_COMPRESS__



#endif //__RES_COMPRESS_CONFIG_H__
