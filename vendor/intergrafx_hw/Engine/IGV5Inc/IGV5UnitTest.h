/** 
 *
 *	@file		IGV5UnitTest.h	
 *
 *  @brief		Header file Unit test functions
 *
 *	@author		George Li
 *
*/

#ifndef  __IGV5UNITTEST_H
#define  __IGV5UNITTEST_H

#include "IGV5Def.h"
#include "IGV5MathHelper.h"
#include "IGV5LZW.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef IGV5_WIN

void TestMatrixDecomposition(char *logfn);

void TestArchTanSinCos(char *logfn);

void TestSqrt(char *logfn);

void TestLZWCompAndDecomWithSimpleStream(char *logfn);
void TestLZWCompAndDecomFile(char *fnToBeCompressed, char *fnCompressed, char *fnDecompressed, char *logfn);


#endif

#ifdef __cplusplus
}
#endif			


#endif    //end of __IGV5MATHHELPER_H
