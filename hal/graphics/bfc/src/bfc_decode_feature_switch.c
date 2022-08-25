#include "bfc_decode_raster.h"
#include "bfc_decode_rgb565.h"
#include "bfc_decode_rgb888.h"
#include "bfc_decode_argb8888.h"
#include "bfc_decode_1bpp.h"

static const SetPixelFuncNoClip setPixelFuncNoClip[5][5] =
{
   {
	   setPixel1BPPNormalNoClip,//1BPP just support Normal style,so switch all other style to Normal style.
	   setPixel1BPPNormalNoClip,
	   setPixel1BPPNormalNoClip,
	   setPixel1BPPNormalNoClip,
	   setPixel1BPPNormalNoClip
   },
   {
      setPixelRGB565NormalNoClip,
      setPixelRGB565BoldNoClip,
      setPixelRGB565ItalicNoClip,
      setPixelRGB565BoldItalicNoClip,
      setPixelRGB565BorderNoClip
   },
   {
      setPixelRGB888NormalNoClip,
      setPixelRGB888BoldNoClip,
      setPixelRGB888ItalicNoClip,
      setPixelRGB888BoldItalicNoClip,
      setPixelRGB888BorderNoClip
   },
   {
      setPixelARGB8888NormalNoClip,
      setPixelARGB8888BoldNoClip,
      setPixelARGB8888ItalicNoClip,
      setPixelARGB8888BoldItalicNoClip,
      setPixelARGB8888BorderNoClip
   },
   {
      setPixelARGB8888NormalNoClip,
      setPixelARGB8888BoldNoClip,
      setPixelARGB8888ItalicNoClip,
      setPixelARGB8888BoldItalicNoClip,
      setPixelARGB8888BorderNoClip
   }
};

static const SetPixelFuncWithClip setPixelFuncWithClip[5][5] =
{
   {
	   setPixel1BPPNormalWithClip,//1BPP just support Normal style,so switch all other style to Normal style.
	   setPixel1BPPNormalWithClip,
	   setPixel1BPPNormalWithClip,
	   setPixel1BPPNormalWithClip,
	   setPixel1BPPNormalWithClip
   },
   {
      setPixelRGB565NormalWithClip,
      setPixelRGB565BoldWithClip,
      setPixelRGB565ItalicWithClip,
      setPixelRGB565BoldItalicWithClip,
      setPixelRGB565BorderWithClip
   },
   {
      setPixelRGB888NormalWithClip,
      setPixelRGB888BoldWithClip,
      setPixelRGB888ItalicWithClip,
      setPixelRGB888BoldItalicWithClip,
      setPixelRGB888BorderWithClip
   },
   {
      setPixelARGB8888NormalWithClip,
      setPixelARGB8888BoldWithClip,
      setPixelARGB8888ItalicWithClip,
      setPixelARGB8888BoldItalicWithClip,
      setPixelARGB8888BorderWithClip
   },
   {
      setPixelARGB8888NormalWithClip,
      setPixelARGB8888BoldWithClip,
      setPixelARGB8888ItalicWithClip,
      setPixelARGB8888BoldItalicWithClip,
      setPixelARGB8888BorderWithClip
   }
};

static kal_int32 mapStyleToIndex(BFC_STYLE_ENUM style)
{
   kal_uint32 select;

   switch(style)
   {
      case BFC_STYLE_NORMAL:
         select = 0;
         break;
      case BFC_STYLE_BOLD:
         select = 1;
         break;
      case BFC_STYLE_ITALIC:
         select = 2;
         break;
      case BFC_STYLE_BOLD_ITALIC:
         select = 3;
         break;
      case BFC_STYLE_BORDER:
         select = 4;
         break;
      default:
         ASSERT(0);
         return -1;
   }

   return select;
}

SetPixelFuncNoClip getRasterFuncNoClip(BFC_RGB_FORMAT_ENUM format, BFC_STYLE_ENUM style)
{
   return setPixelFuncNoClip[format][mapStyleToIndex(style)];
}

SetPixelFuncWithClip getRasterFuncWithClip(BFC_RGB_FORMAT_ENUM format, BFC_STYLE_ENUM style)
{
   return setPixelFuncWithClip[format][mapStyleToIndex(style)];
}
