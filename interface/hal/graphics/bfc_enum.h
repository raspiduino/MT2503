#ifndef __BFC_ENUM_H__
#define __BFC_ENUM_H__

typedef enum BFC_STATUS_ENUM
{
   BFC_STATUS_RETURN_SUCCESS     =  0,       ///< No error, everything is normal
   BFC_STATUS_INVALID_POINTER    = -1,
   BFC_STATUS_INVALID_HANDLE     = -2,       ///< The decoder contet is invalid
   BFC_STATUS_INVALID_STYLE      = -3,       ///< The bitmap font style is invalid
   BFC_STATUS_INVALID_CANVAS     = -4,       ///< The canvas buffer address is invalid    
   BFC_STATUS_INVALID_WIDTH      = -5,       ///< The canvas or clip width is invalid  
   BFC_STATUS_INVALID_PITCH      = -6,       ///< The canvas pitch is invalid
   BFC_STATUS_INVALID_HEIGHT     = -7,       ///< The canvas or clip height is invalid
   BFC_STATUS_INVALID_FORMAT     = -8        ///< The cnavas buffer format is invalid
} BFC_STATUS_ENUM;

typedef enum BFC_STYLE_ENUM
{
   BFC_STYLE_NORMAL              = 0x01,     ///< Decode the font into normal style
   BFC_STYLE_BOLD                = 0x02,     ///< Decode the font into bold style
   BFC_STYLE_ITALIC              = 0x04,     ///< Decode the font into italic style
   BFC_STYLE_BOLD_ITALIC         = 0x06,     ///< Decode the font into bold and italic style
   BFC_STYLE_BORDER              = 0x20      ///< Decode the font into border style
} BFC_STYLE_ENUM;

typedef enum BFC_RGB_FORMAT_ENUM
{
   BFC_RGB_FORMAT_1BPP           = 0,        ///< Canvas is in 1-bit per pixel
   BFC_RGB_FORMAT_RGB565         = 1,        ///< Canvas is in RGB565 format
   BFC_RGB_FORMAT_RGB888         = 2,        ///< Canvas is in RGB888 format
   BFC_RGB_FORMAT_PARGB8888      = 3,        ///< Canvas is in PARGB8888 format
   BFC_RGB_FORMAT_ARGB8888       = 4         ///< Canvas is in ARGB8888 format
} BFC_RGB_FORMAT_ENUM;

#endif  // __BFC_ENUM_H__
