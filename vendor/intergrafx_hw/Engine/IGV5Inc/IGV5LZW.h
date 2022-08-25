/** 
 *
 *	@file		IGV5LZW.h	
 *
 *  @brief		header file for LZW compression
 *
 *	@author		George Li
 *
*/

#ifndef __IGV5LZW_H
#define __IGV5LZW_H

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif


/*!***************************************************************************
 @fn			LZWCompress
 @param			pInStream			input buffer data that needs to be compressed
 @param			iInStreamLength     the length of the input stream buffer
 @param			pOutStream			output buffer with the compressed stream data
									Usually, the caller allocates the same length
									of memory as the length of pInStream
 @param			OutStreamLength		the length of output buffer 
 @Return        0-failed: It could be the memory overflow problem, just contact the developer
                > 0: length of the compressed stream data

 @brief			Use LZW algorithm to compress a stream into IG data format.
                If compressing a stream will have a longer stream, such as png, jpg files, 
				the stream is simply wrapped up into IG data format
*****************************************************************************/
unsigned int LZWCompress(unsigned char *pInStream, unsigned int iInStreamLength, unsigned char *pOutStream, unsigned int OutStreamLength);

/*!***************************************************************************
 @fn			WrapStream
 @param			pInStream			input buffer data that needs to be compressed
 @param			iInStreamLength     the length of the input stream buffer
 @param			pOutStream			output buffer with the compressed stream data
									Usually, the caller allocates the same length
									of memory as the length of pInStream
 @param			OutStreamLength		the length of output buffer 
 @Return        0-failed: It could be the memory overflow problem, just contact the developer
                > 0: length of the compressed stream data

 @brief			Use LZW algorithm to compress a stream into IG data format.
                If compressing a stream will have a longer stream, such as png, jpg files, 
				the stream is simply wrapped up into IG data format
*****************************************************************************/
unsigned int WrapUpStream(unsigned char *pInStream, unsigned int iInStreamLength, unsigned char *pOutStream, unsigned int OutStreamLength);

/*!***************************************************************************
 @fn			UnwrapStream
 @param			pInStream			input buffer data that needs to be compressed
 @param			pOutStream			output buffer with the compressed stream data
									Usually, the caller allocates the same length
									of memory as the length of pInStream
 @param			OutStreamLength		the length of output buffer 
 @Return        0-failed: It could be the memory overflow problem, just contact the developer
                > 0: length of unwrapped data stream

 @brief			Unwrap a stream
*****************************************************************************/
unsigned int UnwrapStream(unsigned char *pInStream, unsigned char *pOutStream, unsigned int OutStreamLength);


/*!***************************************************************************
 @fn			LZWDecompress
 @param			pInStream			input buffer data that needs to be decompressed.
									This must be a valid compressed stream
 @param			pOutStream			output buffer with the decompressed stream data
									Call GetLZWDecompressionBufferLength(...) to retrieve the 
									required length of buffer.
 @param			OutStreamLength		the length of output buffer 
 @Return        0-failed: it could be the memory overflow problem, just contact the developer
                > 0: length of the decompressed stream data

 @brief			Use LZW algorithm to decompress a stream or unwrap a data stream
*****************************************************************************/
unsigned int LZWDecompress(unsigned char *pInStream, unsigned char *pOutStream, unsigned int OutStreamLength);


/*!***************************************************************************
 @fn			GetLZWDecompressionBufferLength
				GetLZWCompressedDataLength
				GetLZWDictionaryLength
				GetLZWDataBits	
 @param			pLZWCompressedStream		input buffer data that needs to be decompressed.
											This must be a valid compressed stream
 @Return        0-failed: invalid stream
                > 0 (GetLZWDecompressionBufferLength): length of buffer in bytes needed for the decompressed stream data
				> 0 (GetLZWCompressedDataLength): length of compressed data in bytes
				> 0 (GetLZWDictionaryLength): length of the dictionary
				> 0 (GetLZWDataBits): the compressed file data bits

 @brief			Get buffer length needed for decompression
                Get compressed data length (data header length is not included)
				Get dictionary length
				Get how many bits are used for data. Wrapped stream will return &xffffffffff
*****************************************************************************/
unsigned int GetLZWDecompressionBufferLength(unsigned char *pLZWCompressedStream);
unsigned int GetLZWCompressedDataLength(unsigned char *pLZWCompressedStream);
unsigned int GetLZWDictionaryLength(unsigned char *pLZWCompressedStream);
unsigned int GetLZWDataBits(unsigned char *pLZWCompressedStream);

#ifdef IGV5_WIN

/*!***************************************************************************
 @fn			LZWCompress
 @param			fpISource		input file name
 @param			fpTarget		onput file name
											
 @Return        0-failed: It could be the memory overflow problem, just contact the developer
                > 0: length of the output file

 @brief			Compress the source file and write into the target file
*****************************************************************************/
unsigned int LZWCompressFile(char *fnSource, char *fnTarget);	

/*!***************************************************************************
 @fn			LZWDecompress
 @param			fpISource		input file name
 @param			fpTarget		onput file name

 @Return        0-failed: invalid input stream
                > 0: length of the output file

				@brief			Decompress the source file and write into the target file
*****************************************************************************/
unsigned int LZWDecompressFile(char *fnSource, char *fnTarget);   

#endif


#ifdef __cplusplus
}
#endif

#endif   //end of __IGV5LZW_H