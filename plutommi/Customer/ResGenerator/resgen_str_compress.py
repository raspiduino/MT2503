import sys
import os
import StringIO
import traceback
import time
import struct
import re
import shutil
import difflib
import datetime
import csv
import getopt
import array
import math

from resgen_util_compress import LzmaCompressionAdaptor, ZlibCompressionAdaptor, ByteUtil, ThirdRomBinaryGenerator, ThirdROMEntry

####################################################
# Usgae print
####################################################
def usage():
	print('Usage: python res_str_compress.py')


####################################################
# MTK String Resource Source Generator
# -  Common part of string reource code generation
####################################################
class StringResourceCodeGenerator:
	def __init__(self, name):
		self.name = name
	
	def generateSearchMap(self, binaryStringModel):
		result = 'const CUSTOM_STRMAP_SEARCH StrMapSearch[] = {\n'
		searchMap = binaryStringModel.searchMap
		for entry in searchMap:
			result = result + '{' + str(entry[0]) + ',' + str(entry[1]) + ',' + str(entry[2]) +'}, \n'
		result = result + '};\n'
		return result

	def generateExtStringLangEntryWrapper(self, resDataSymbol, resDataROMSize, resDataRAMSize, mapDataSymbol, mapDataROMBytes, mapDataRAMBytes, is16Bit):
		mapDataROMSize = 0
		mapDataRAMSize = 0
		if(is16Bit is True):
			mapDataROMSize = len(ByteUtil.int16ToByteArray(mapDataROMBytes))
			mapDataRAMSize = len(ByteUtil.int16ToByteArray(mapDataRAMBytes))
		else:
			mapDataROMSize = len(ByteUtil.int32ToByteArray(mapDataROMBytes))
			mapDataRAMSize = len(ByteUtil.int32ToByteArray(mapDataRAMBytes))
		return self.generateExtStringLangEntry(resDataSymbol, resDataROMSize, resDataRAMSize, mapDataSymbol, mapDataROMSize, mapDataRAMSize)

	def generateExtStringLangEntry(self, resDataSymbol, resDataROMSize, resDataRAMSize, mapDataSymbol, mapDataROMSize, mapDataRAMSize):
		resultStrExt = ', ' + '(U8*)' + resDataSymbol  + ', ' 
		resultStrExt = resultStrExt + str(resDataROMSize) + ', ' 
		resultStrExt = resultStrExt + str(resDataRAMSize) + ', ' 
		resultStrExt = resultStrExt + '(U8*)'+ mapDataSymbol + ', ' 
		resultStrExt = resultStrExt + str(mapDataROMSize) + ', ' 
		resultStrExt = resultStrExt + str(mapDataRAMSize)
		return resultStrExt

	def generateStringLangEntry(self, strResSymbol, strResTotal, strMapSymbol, strMapTotal, strMapSearchSymbol, strMapSearchTotal, is16Bit):
		# resultStr = '(CUSTOM_STRING*)' + strResSymbol + ' ,'
		resultStr = '(void *)' + strResSymbol + ' ,'
		resultStr = resultStr +  str(strResTotal) + ', ' 
		resultStr = resultStr + '(void *)' + strMapSymbol + ', '
		resultStr = resultStr +  str(strMapTotal) + ', '
		resultStr = resultStr + '(CUSTOM_STRMAP_SEARCH *)' + strMapSearchSymbol + ', ' 
		resultStr = resultStr +  str(strMapSearchTotal) + ','
		if(is16Bit is True):
			resultStr = resultStr + '1'
		else:
			resultStr = resultStr + '0'	
		return resultStr

	def generateSearchSource(self, binaryStringModel, fileName):
		outputStream = open(fileName, 'w')
		self.appendHeaderLines(outputStream)
		outputStream.write('const U16 mtk_gTrans_string_count = ' + binaryStringModel.attribute['mtk_gTrans_string_count'] + ';\n')	
		outputStream.write('\n' + self.generateSearchMap(binaryStringModel) + '\n')
		outputStream.write(self.generateStringROMSymbolExterns(binaryStringModel))
		outputStream.write('\n')
		outputStream.write(self.generateStringResList(binaryStringModel))
		
		self.appendBottomLines(outputStream)
		outputStream.close()
	
	
	def generateStringResList(self, binaryStringModel, bufSymbolAdaptor=None):
		if(binaryStringModel is None):
			return None

		resultStr = bufSymbolAdaptor.getSymbolDeclaration()
		resultStr = resultStr + 'const StringResList mtk_gStringList[] = {\n'		
		totalLanguage = int(binaryStringModel.attribute['mtk_gMaxDeployedLangs'])

		# GENERAL STRING
		for index in range(1, (totalLanguage+1)):
			resultStr = resultStr + self.generateSingleStringLangEntry(str(index), binaryStringModel, bufSymbolAdaptor)

		# DUP STRING
		# DUP string's size info is calculated with 'max_total_len'
		if 'DUP' in binaryStringModel.langRess:
			resultStr = resultStr + self.generateSingleStringLangEntry('DUP', binaryStringModel, bufSymbolAdaptor)
		else:
			resultStr = resultStr + self.generateDummyDupStringLangEntry()

		# FIXED STRING
		if 'FIXED' in binaryStringModel.langRess:
			resultStr = resultStr + self.generateSingleStringLangEntry('FIXED', binaryStringModel, bufSymbolAdaptor)

		resultStr = resultStr + '};\n'
		return resultStr
		
	# Must implemented in the child class of StringResourceCodeGenerator
	def generateDupStringLangEntry(self, binaryStringModel, bufSymbolAdaptor=None):
		return ''
	
	# Must implemented in the child class of StringResourceCodeGenerator
	def generateSingleStringLangEntry(self, langKey, binaryStringModel, bufSymbolAdaptor = None):
		return ''
		
	def generateDummyDupStringLangEntry(self):
		return '{(CUSTOM_STRING*)NULL, 0, (void*)NULL, 0, (CUSTOM_STRMAP_SEARCH *)NULL, 0, 0, NULL, 0, 0, NULL, 0, 0 },\n'


####################################################
# Class: ThirdROMStrResCodeGeneartor
# -  3rd ROM string reource code generation
####################################################

class ThirdROMStrResCodeGeneartor(StringResourceCodeGenerator):
	def appendHeaderLines(self, outputStream):
		outputStream.write('#include \"mmi_features.h\"\n\n')
		outputStream.write('#include \"ResCompressConfig.h\"\n')
		outputStream.write('#include \"CustDataRes.h\"\n')
		outputStream.write('#include \"FontDCl.h\"\n')
		outputStream.write('#if (!defined (__MTK_TARGET__))\n')
		outputStream.write('    #define __align(x)\n')
		outputStream.write('#endif\n\n')
		outputStream.write('#if defined(__MMI_RESOURCE_STR_THIRD_ROM__)\n')

	def appendBottomLines(self, outputStream):
		outputStream.write('\n#endif //__MMI_RESOURCE_STR_THIRD_ROM__\n')
	

	# For 3rd ROM
	def getResData(self, binaryStringModel, langKey):
		return binaryStringModel.langRess[langKey]
		
	def getMapData(self, binaryStringModel, langKey):
		return binaryStringModel.langMaps[langKey]
		
	def getResROMAddress(self, binaryStringModel, langKey):
		return str(binaryStringModel.thirdROMInfoRess[langKey].offset)
		
	def getMapROMAddress(self, binaryStringModel, langKey):
		return str(binaryStringModel.thirdROMInfoMaps[langKey].offset)
		
	def generateStringROMSymbolExterns(self, binaryStringModel):
		return '\n'
	

	def geneateBinaryFromStringModel(self, binaryStringModel, fileName, paddingSize = 2048):	
		thirdRomGenerator = ThirdRomBinaryGenerator('MMIString')
		# DUP String
		if('DUP' in binaryStringModel.langRess):
			binaryStringModel.thirdROMInfoRess['DUP'] = ThirdROMEntry('StrRes_Dup[]',binaryStringModel.langRess['DUP'])
			thirdRomGenerator.add(binaryStringModel.thirdROMInfoRess['DUP'])
			
		# Language String
		totalLanguage = int(binaryStringModel.attribute['mtk_gMaxDeployedLangs'])
		for index in range(1, (totalLanguage+1)):
			resData = binaryStringModel.langRess[str(index)]
			name = 'StrRes_'+ str(index) + '[]'
			binaryStringModel.thirdROMInfoRess[str(index)] = ThirdROMEntry(name,binaryStringModel.langRess[str(index)])
			name = 'StrMap_' + str(index) + '[]'
			mapData = None
			if(int(binaryStringModel.bitMode[str(index)]) == 16):	
				mapData = ByteUtil.int16ToByteArray(binaryStringModel.langMaps[str(index)])
			else:
				mapData = ByteUtil.int32ToByteArray(binaryStringModel.langMaps[str(index)])
			binaryStringModel.thirdROMInfoMaps[str(index)] = ThirdROMEntry(name,mapData)
				
			thirdRomGenerator.add(binaryStringModel.thirdROMInfoRess[str(index)])
			thirdRomGenerator.add(binaryStringModel.thirdROMInfoMaps[str(index)])

		if('FIXED' in binaryStringModel.langRess):
			name = 'StrRes_fixed[]'			
			binaryStringModel.thirdROMInfoRess['FIXED'] = ThirdROMEntry(name,binaryStringModel.langRess['FIXED'])
			name = 'StrMap_fixed[]'			
			mapData = None
			if(int(binaryStringModel.bitMode['FIXED']) == 16):	
				mapData = ByteUtil.int16ToByteArray(binaryStringModel.langMaps['FIXED'])
			else:
				mapData = ByteUtil.int32ToByteArray(binaryStringModel.langMaps['FIXED'])
			binaryStringModel.thirdROMInfoMaps['FIXED'] = ThirdROMEntry(name,mapData)			
			thirdRomGenerator.add(binaryStringModel.thirdROMInfoRess['FIXED'])
			thirdRomGenerator.add(binaryStringModel.thirdROMInfoMaps['FIXED'])
					
		thirdRomGenerator.generateBinary(fileName, paddingSize)

	def generateDupStringLangEntry(self, binaryStringModel, bufSymbolAdaptor=None):
		totalLen = int(binaryStringModel.attribute['max_total_len'])
		resSource = self.getResROMAddress(binaryStringModel,'DUP')
		resData = self.getResData(binaryStringModel, 'DUP')
		size1 = (totalLen>>16) & 0xFFFF
		size2 = totalLen & 0xFFFF
		maxNum = int(binaryStringModel.maxNum['DUP'])
		strResSymbol = bufSymbolAdaptor.getStrResSymbol('DUP')
		resultStrExt = self.generateExtStringLangEntry(resSource, len(resData), len(resData), 'NULL', 0, 0)
		resultStr = self.generateStringLangEntry(strResSymbol, (maxNum+1), 'NULL', size1, 'NULL', size2, 0)
		resultStr = '{ '+ resultStr + resultStrExt + ' },\n'
		return resultStr
		

	def generateSingleStringLangEntry(self, langKey, binaryStringModel, bufSymbolAdaptor = None):
		strResSymbol = bufSymbolAdaptor.getStrResSymbol(langKey)
		strMapSymbol = bufSymbolAdaptor.getStrMapSymbol(langKey)
		resultStrExt = ''
		resultStr = ''
		mapDataLen = 0	
		is16Bit = True
	
		# For DUP string
		if(langKey == 'DUP'):
			return self.generateDupStringLangEntry(binaryStringModel, bufSymbolAdaptor)
		
		resData = self.getResData(binaryStringModel, langKey)
		mapData = self.getMapData(binaryStringModel, langKey)
		bitNumber = int(binaryStringModel.bitMode[langKey])
		maxId = int(binaryStringModel.maxId[langKey])
		maxNum = int(binaryStringModel.maxNum[langKey])
		searchMap = binaryStringModel.searchMap
	
		if(bitNumber == 16):
			is16Bit = True
		else:
			is16Bit = False
	
		# For Fixed String
		if(langKey == 'FIXED'):
			mapEntryTotal = (maxId+1)
		else:
			mapEntryTotal = len(mapData)+ 1

		# Get Load address
		resSource = self.getResROMAddress(binaryStringModel,langKey)
		mapSource = self.getMapROMAddress(binaryStringModel,langKey)
			
		resultStrExt = self.generateExtStringLangEntryWrapper(resSource, len(resData), len(resData), mapSource, mapData, mapData, is16Bit)
		resultStr = self.generateStringLangEntry(strResSymbol, (maxNum+1), strMapSymbol, mapEntryTotal, 'StrMapSearch', len(searchMap), is16Bit)
		resultStr = '{ '+ resultStr + resultStrExt + ' },\n'
		
		return resultStr
	
class CompressedStrResCodeGenerator(StringResourceCodeGenerator):
	def appendHeaderLines(self, outputStream):
		outputStream.write('#include \"mmi_features.h\"\n\n')
		outputStream.write('#include \"ResCompressConfig.h\"\n')
		outputStream.write('#if !defined(__MMI_RESOURCE_STR_THIRD_ROM__)\n')
		outputStream.write('#if defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__)\n')
		outputStream.write('#include \"CustDataRes.h\"\n')
		outputStream.write('#include \"FontDCl.h\"\n')
		outputStream.write('#if (!defined (__MTK_TARGET__))\n')
		outputStream.write('    #define __align(x)\n')
		outputStream.write('#endif\n\n')

		
	def appendBottomLines(self, outputStream):
		outputStream.write('\n#endif //__MMI_RESOURCE_STR_LZMA_COMPRESS__\n')
		outputStream.write('\n#endif //__MMI_RESOURCE_STR_THIRD_ROM__\n')
		
	# For general case
	def getResData(self, binaryStringModel, langKey):
		return binaryStringModel.langRess[langKey]
		
	def getMapData(self, binaryStringModel, langKey):
		return binaryStringModel.langMaps[langKey]
		
	def getCompressedResData(self, binaryStringModel, langKey):
		return binaryStringModel.langCompressedRess[langKey]
		
	def getCompressedMapData(self, binaryStringModel, langKey):
		return binaryStringModel.langCompressedMaps[langKey]
		
	def getResROMAddress(self, binaryStringModel, langKey):
		if( langKey == 'FIXED'):
			return 'StrRes_zip_fixed'
		if (langKey == 'DUP'):
			return 'StrRes_zip_Dup'
		else:
			return 'StrRes_zip_' + langKey
		
	def getMapROMAddress(self, binaryStringModel, langKey):
		if( langKey == 'FIXED'):
			return 'StrMap_zip_fixed'
		else:
			return 'StrMap_zip_' + langKey
	
	
	def generateDupStringLangEntry(self, binaryStringModel, bufSymbolAdaptor=None):
		totalLen = int(binaryStringModel.attribute['max_total_len'])
		resSource = self.getResROMAddress(binaryStringModel,'DUP')
		resData = self.getResData(binaryStringModel, 'DUP')
		compressedResData = self.getCompressedResData(binaryStringModel, 'DUP')
		size1 = (totalLen>>16) & 0xFFFF
		size2 = totalLen & 0xFFFF
		maxNum = int(binaryStringModel.maxNum['DUP'])
		strResSymbol = bufSymbolAdaptor.getStrResSymbol('DUP')
		resultStrExt = self.generateExtStringLangEntry(resSource, len(resData), len(compressedResData), 'NULL', 0, 0)
		resultStr = self.generateStringLangEntry(strResSymbol, (maxNum+1), 'NULL', size1, 'NULL', size2, 0)
		resultStr = '{ '+ resultStr + resultStrExt + ' },\n'
		return resultStr
		
	
	def generateMapSource(self, binaryStringModel, fileName):
		outputStream = open(fileName, 'w')
		self.appendHeaderLines(outputStream)
		outputStream.write('\n#ifdef __MTK_TARGET__\n')
		outputStream.write('#ifdef __CAT_SUPPORT__\n')
		outputStream.write('#if defined(_NAND_FLASH_BOOTING_) || !defined(__ZIMAGE_SUPPORT__) \n')
		outputStream.write('#pragma arm section rodata = \"CAT_RODATA_STR\"\n')
		outputStream.write('#else //_NAND_FLASH_BOOTING_ || !__ZIMAGE_SUPPORT__ \n')
		outputStream.write('#pragma arm section rodata = \"CAT_RODATA_STR_NO_ZIMAGE\"\n')
		outputStream.write('#endif //_NAND_FLASH_BOOTING_ || !__ZIMAGE_SUPPORT__ \n')
		outputStream.write('#endif // __CAT_SUPPORT__\n')
		outputStream.write('#endif // __MTK_TARGET__\n\n')
		

	# Output Language Map
		totalLanguage = int(binaryStringModel.attribute['mtk_gMaxDeployedLangs'])
		for index in range(1, (totalLanguage+1)):
			outputStream.write('__align(4) const U8 StrMap_zip_' + str(index) + '[] = ')
			ByteUtil.writeToOutputStream(outputStream,binaryStringModel.langCompressedMaps[str(index)])
			outputStream.write('\n')

		# Fixed Str Map
		if 'FIXED' in binaryStringModel.langCompressedMaps:
			outputStream.write('__align(4) const U8 StrMap_zip_fixed[] = ')
			ByteUtil.writeToOutputStream(outputStream,binaryStringModel.langCompressedMaps['FIXED'])
			outputStream.write('\n')
		
		outputStream.write('\n#ifdef __MTK_TARGET__\n')
		outputStream.write('#ifdef __CAT_SUPPORT__\n')
		outputStream.write('#pragma arm section rodata\n')
		outputStream.write('#endif // __CAT_SUPPORT__\n')
		outputStream.write('#endif // __MTK_TARGET__\n')
		
		self.appendBottomLines(outputStream)

		outputStream.close()
				
	def generateSingleStringLangEntry(self, langKey, binaryStringModel, bufSymbolAdaptor = None):
		strResSymbol = bufSymbolAdaptor.getStrResSymbol(langKey)
		strMapSymbol = bufSymbolAdaptor.getStrMapSymbol(langKey)
		resultStrExt = ''
		resultStr = ''
		mapDataLen = 0	
		is16Bit = True
	
		# For DUP string
		if(langKey == 'DUP'):
			return self.generateDupStringLangEntry(binaryStringModel, bufSymbolAdaptor)
		
		resData = self.getResData(binaryStringModel, langKey)
		mapData = self.getMapData(binaryStringModel, langKey)
		compressResData = self.getCompressedResData(binaryStringModel, langKey)
		compressMapData = self.getCompressedMapData(binaryStringModel, langKey)
		
		bitNumber = int(binaryStringModel.bitMode[langKey])
		maxId = int(binaryStringModel.maxId[langKey])
		maxNum = int(binaryStringModel.maxNum[langKey])
		searchMap = binaryStringModel.searchMap
		
		if(bitNumber == 16):
			is16Bit = True
			origialMapDataLen = len(ByteUtil.int16ToByteArray(mapData))
		else:
			is16Bit = False
			origialMapDataLen = len(ByteUtil.int32ToByteArray(mapData))
	
		# For Fixed String
		if(langKey == 'FIXED'):
			mapEntryTotal = (maxId+1)
		else:
			mapEntryTotal = len(mapData)+ 1

		# Get Load address
		resSource = self.getResROMAddress(binaryStringModel,langKey)
		mapSource = self.getMapROMAddress(binaryStringModel,langKey)
			
		resultStrExt = self.generateExtStringLangEntry(resSource, len(resData), len(compressResData), mapSource, origialMapDataLen, len(compressMapData))
		resultStr = self.generateStringLangEntry(strResSymbol, (maxNum+1), strMapSymbol, mapEntryTotal, 'StrMapSearch', len(searchMap), is16Bit)
		resultStr = '{ '+ resultStr + resultStrExt + ' },\n'
		
		return resultStr
		
	def geneateResSource(self, binaryStringModel, fileName, paddingSize = 0, isCATSupport=True):
		outputStream = open(fileName, 'w')
		self.appendHeaderLines(outputStream)
		outputStream.write('\n#ifdef __MTK_TARGET__\n')
		outputStream.write('#ifdef __CAT_SUPPORT__\n')
		outputStream.write('#if defined(_NAND_FLASH_BOOTING_) || !defined(__ZIMAGE_SUPPORT__) \n')
		outputStream.write('#pragma arm section rodata = \"CAT_RODATA_STR\"\n')
		outputStream.write('#else //_NAND_FLASH_BOOTING_ || !__ZIMAGE_SUPPORT__ \n')
		outputStream.write('#pragma arm section rodata = \"CAT_RODATA_STR_NO_ZIMAGE\"\n')
		outputStream.write('#endif //_NAND_FLASH_BOOTING_ || !__ZIMAGE_SUPPORT__ \n')
		outputStream.write('#endif // __CAT_SUPPORT__\n')
		outputStream.write('#endif // __MTK_TARGET__\n\n')
		
		# DUP String
		if('DUP' in binaryStringModel.langRess):
			# Check Compressed
			outputStream.write('__align(4) const CUSTOM_STRING StrRes_zip_Dup[] = \n')
			ByteUtil.writeToOutputStream(outputStream,binaryStringModel.langCompressedRess['DUP'], paddingSize)
			outputStream.write('\n')

		# Language String
		totalLanguage = int(binaryStringModel.attribute['mtk_gMaxDeployedLangs'])
		for index in range(1, (totalLanguage+1)):
			outputStream.write('extern const U8 StrMap_zip_' + str(index) + '[];\n')
			outputStream.write('__align(4) const CUSTOM_STRING StrRes_zip_'+ str(index) + '[] = \n')
			ByteUtil.writeToOutputStream(outputStream,binaryStringModel.langCompressedRess[str(index)], paddingSize)
			outputStream.write('\n')

		if('FIXED' in binaryStringModel.langRess):
			outputStream.write('extern const U8 StrMap_zip_fixed[];\n')
			outputStream.write('__align(4) const CUSTOM_STRING StrRes_zip_fixed[] = \n')
			ByteUtil.writeToOutputStream(outputStream,binaryStringModel.langCompressedRess['FIXED'], paddingSize)

		outputStream.write('\n#ifdef __MTK_TARGET__\n')
		outputStream.write('#ifdef __CAT_SUPPORT__\n')
		outputStream.write('#pragma arm section rodata\n')
		outputStream.write('#endif // __CAT_SUPPORT__\n')
		outputStream.write('#endif // __MTK_TARGET__\n\n')
				
		# output string counts
		self.appendBottomLines(outputStream)
		outputStream.close()
		

	def generateStringROMSymbolExterns(self, binaryStringModel):
		if(binaryStringModel is None):
			return None
		externStr = ''
		
		totalLanguage = int(binaryStringModel.attribute['mtk_gMaxDeployedLangs'])
		# GENERAL STRING
		for index in range(1, (totalLanguage+1)):
			externStr = externStr + 'extern const U8 StrMap_zip_' + str(index) + '[];\n' 
			externStr = externStr + 'extern const U8 StrRes_zip_' + str(index) + '[];\n'

		#DUP STRING
		# DUP string's size info is calculated with 'max_total_len'
		if 'DUP' in binaryStringModel.langRess:
			externStr = externStr + 'extern const U8 StrRes_zip_Dup[];\n'

		if 'FIXED' in binaryStringModel.langRess:
			externStr = externStr + 'extern const U8 StrMap_zip_fixed[];\n' 
			externStr = externStr + 'extern const U8 StrRes_zip_fixed[];\n'

		return (externStr + '\n\n')
		

		

class StringBufferSymbolAdaptor:

	def calculateMapOffset(self, resSize):
		if(resSize % 4 ==0):
			return resSize
		else:
			return ((resSize/4) + 1 ) * 4
	
	def setMapOffset(self, langKey):
		resSize = self.model.getResBufferSize(langKey)
		self.mapOffset[langKey] = self.calculateMapOffset(resSize)
		return self.mapOffset[langKey]

	def __init__(self, model):
		self.model = model
		self.commonBufSymName = 'StrRuntimeBuf'
		self.fixedStrBufSymName = 'FixedStrRuntimeBuf'
		self.dupStrBufSymName = 'DupStrRuntimeBuf'
		self.mapOffset = {}
		self.commonBufSize = 0
		self.fixedStrBufSize = 0
		
		maxLangBufSize = 0
		totalLanguage = int(self.model.attribute['mtk_gMaxDeployedLangs'])
		for index in range(1, (totalLanguage+1)):
			langKey = str(index)
			mapOffset = self.setMapOffset(langKey)
			mapSize = self.model.getMapBufferSize(langKey)
			temp = mapOffset + mapSize
			if(temp > maxLangBufSize):
				maxLangBufSize = temp
		self.commonBufSize = maxLangBufSize

		langKey = 'FIXED'
		if( langKey in model.langRess):
			mapSize = self.model.getMapBufferSize(langKey)
			mapOffset = self.setMapOffset(langKey)
			self.fixedStrBufSize = mapOffset + mapSize


	def getStrResSymbol(self, langKey):
		if(langKey == 'DUP'):
			return self.dupStrBufSymName
		elif(langKey == 'FIXED'):
			return self.fixedStrBufSymName
		else:
			return self.commonBufSymName
	
	def getStrMapSymbol(self, langKey):
		if(langKey == 'DUP'):
			return 'NULL'
		if(langKey == 'FIXED'):
			return '(' + self.fixedStrBufSymName + '+' + str(self.mapOffset[langKey]) + ')' 
		else:
			return '(' + self.commonBufSymName + '+' + str(self.mapOffset[langKey]) + ')'
	
	def getSymbolDeclaration(self):
		# common buffer
		result = '__align(4) U8 ' + self.commonBufSymName + '[' + str(self.commonBufSize) + '];\n'
		if( 'DUP' in self.model.langRess):
			result = result + '__align(4) U8 ' + self.dupStrBufSymName + '[' + str(self.model.getResBufferSize('DUP')) + '];\n'
		if( 'FIXED' in self.model.langRess):
			result = result + '__align(4) U8 ' + self.fixedStrBufSymName + '[' + str(self.fixedStrBufSize) + '];\n'
		return result


class CATStringBufferSymbolAdaptor:

	def __init__(self, model):
		self.model = model

	def getStrResSymbol(self, langKey):
		if(langKey == 'DUP'):
			return 'StrRes.strRes_Dup'
		elif(langKey == 'FIXED'):
			return 'StrRes.strRes_Fixed'
		else:
			return 'StrRes.strRes'
	
	def getStrMapSymbol(self, langKey):
		if(langKey == 'DUP'):
			return 'NULL'
		elif (langKey == 'FIXED'):
			return 'StrRes.strMap_Fixed'
		else:
			return 'StrRes.strMap_' + langKey
	
	def getSymbolDeclaration(self):
		# find the max res buffer
		totalLanguage = int(self.model.attribute['mtk_gMaxDeployedLangs'])
		sizeOfResBuffer = 0
		
		for index in range(1, (totalLanguage+1)):
			resData = self.model.langRess[str(index)]
			if(len(resData) > sizeOfResBuffer):
				sizeOfResBuffer = len(resData)
		
		resultStr = 'struct StrResStruct{\n'
		resultStr = resultStr + 'CUSTOM_STRING strRes[' + str(sizeOfResBuffer) + '];\n'
		
		for index in range(1, (totalLanguage+1)):
			langKey = str(index)
			mapData = self.model.langMaps[langKey]
			if( self.model.is16Bits(langKey) ):
				resultStr = resultStr + 'CUSTOM_STRING_MAP_16 strMap_' + langKey + '[' + str(len(mapData)) + '];\n'
			else:
				resultStr = resultStr + 'CUSTOM_STRING_MAP strMap_' + langKey + '[' + str(len(mapData)) + '];\n'
		
		# DUP string buffer
		langKey ='DUP'
		if langKey in self.model.langRess:
			resultStr = resultStr + 'CUSTOM_STRING strRes_Dup[' + str(len(self.model.langRess[langKey])) + '];\n'
		# Fixed string buffer
		langKey ='FIXED'
		if langKey in self.model.langRess:
			resultStr = resultStr + 'CUSTOM_STRING strRes_Fixed[' + str(len(self.model.langRess[langKey])) + '];\n'
			mapData = self.model.langMaps[langKey]

			if( self.model.is16Bits(langKey) ):
				resultStr = resultStr + 'CUSTOM_STRING_MAP_16 strMap_Fixed[' + str(len(mapData)) + '];\n'
			else:
				resultStr = resultStr + 'CUSTOM_STRING_MAP strMap_Fixed[' + str(len(mapData)) + '];\n'
		
		resultStr = resultStr + '};'
		resultStr = resultStr + '\n__align(4) struct StrResStruct StrRes;\nlong mtk_gStrResSize = sizeof(StrRes);\n'	

		return resultStr

####################################################
# MTK String Resource Data Model
# - Parsed from custimage C arraies
####################################################
class BinaryStringModel:
	def __init__(self, name):
		self.name = name
		self.maxNum = {}
		self.maxId = {}
		self.langRess = {}
		self.langMaps = {}
		self.langCompressedRess = {}
		self.langCompressedMaps = {}	
		self.attribute = {}
		self.bitMode = {}
		self.searchMap = []
		self.compressed = False
		self.thirdROMInfoRess = {}
		self.thirdROMInfoMaps = {}
		
	def is16Bits(self, langKey):
		if(int(self.bitMode[langKey]) == 16):
			return True
		else:
			return False

	def getMapBufferSize(self, langKey):
		mapInts = self.langMaps[langKey]
		is16it = self.is16Bits(langKey)
		if(is16it):
			return len(ByteUtil.int16ToByteArray(mapInts))
		else:
			return len(ByteUtil.int32ToByteArray(mapInts))
		
	def getResBufferSize(self, langKey):
		resBytes = self.langRess[langKey]
		return len(resBytes)


	def decompressTest(self, compressAdaptor):
		totalLanguage = int(self.attribute['mtk_gMaxDeployedLangs'])
		for index in range(1, (totalLanguage+1)):
			resData = self.langRess[str(index)]
			compressedData = self.langCompressedRess[str(index)]
			compressedData2 = ByteUtil.readFile('strres_' + str(index) + '.compress')
			# read compression data back to memory
			compressedResFileName = 'strres_' + str(index) + 'bin.compress'
			originalResFileName = 'strres_' + str(index) + '.bin.decompress'
			ByteUtil.writeFile(compressedData, compressedResFileName)
			compressAdaptor.decompress(originalResFileName,compressedResFileName)
			decompressedData2 = ByteUtil.readFile(originalResFileName)
			print('read ' +originalResFileName + str(len(decompressedData2))+'\n')
			
			if(not compressedData ==compressedData2):
				print('Error !! compression data read back failed!! ' + str(len(compressedData2)) + ',' + str(len(compressedData))+' \n')
			if(not (decompressedData2==resData)):
				print('Error!! decompressed failed: ' + str(index) +  'len: ' + originalResFileName+ ',' + str(len(decompressedData2)) + ',' + str(len(resData)))
			
	def compress(self, compressAdaptor):
		if compressAdaptor is None:
			print('Error!!, CompressAdaptor can\'t be null')
			return
			
		totalLanguage = int(self.attribute['mtk_gMaxDeployedLangs'])
		for index in range(1, (totalLanguage+1)):
			resData = self.langRess[str(index)]
			mapData = self.langMaps[str(index)]
			originalResFileName = 'strres_' + str(index) + '.bin'
			compressedResFileName = 'strres_' + str(index) + '.compress'
			originalMapFileName = 'strmap_' + str(index) + '.bin'
			compressedMapFileName = 'strmap_' + str(index) + '.compress'
			ByteUtil.writeFile(resData, originalResFileName)
			compressAdaptor.compress(compressedResFileName, originalResFileName)
			self.langCompressedRess[str(index)]	= ByteUtil.readFile(compressedResFileName)
			if(int(self.bitMode[str(index)]) == 16):	
				ByteUtil.writeFile(ByteUtil.int16ToByteArray(mapData), originalMapFileName)
			else:
				ByteUtil.writeFile(ByteUtil.int32ToByteArray(mapData), originalMapFileName)
			compressAdaptor.compress(compressedMapFileName, originalMapFileName)
			self.langCompressedMaps[str(index)]	= ByteUtil.readFile(compressedMapFileName)
		#DUP strings
		if 'DUP' in self.langRess:
			resData = self.langRess['DUP']
			originalResFileName = 'strres_dup.bin'
			compressedResFileName = 'strres_dup.compress'
			ByteUtil.writeFile(resData, originalResFileName)
			compressAdaptor.compress(compressedResFileName, originalResFileName)
			self.langCompressedRess['DUP']	= ByteUtil.readFile(compressedResFileName)			

		if 'FIXED' in self.langRess:
			resData = self.langRess['FIXED']
			mapData = self.langMaps['FIXED']
			originalResFileName = 'strres_' + 'FIXED' + '.bin'
			compressedResFileName = 'strres_' + 'FIXED' + '.compress'
			originalMapFileName = 'strmap_' + 'FIXED' + '.bin'
			compressedMapFileName = 'strmap_' + 'FIXED' + '.compress'
			ByteUtil.writeFile(resData, originalResFileName)
			compressAdaptor.compress(compressedResFileName, originalResFileName)
			self.langCompressedRess['FIXED']	= ByteUtil.readFile(compressedResFileName)			
			if(int(self.bitMode['FIXED']) == 16):	
				ByteUtil.writeFile(ByteUtil.int16ToByteArray(mapData), originalMapFileName)
			else:
				ByteUtil.writeFile(ByteUtil.int32ToByteArray(mapData), originalMapFileName)
			compressAdaptor.compress(compressedMapFileName, originalMapFileName)
			self.langCompressedMaps['FIXED']	= ByteUtil.readFile(compressedMapFileName)

		self.compressed = True

		
	####################################################
	# Binary Parsing 
	####################################################
	def binaryParse(self, data):
	  test = data
	  if(test.startswith('0x') or test.startswith('0X') ):
		  testInt = int(test,16)
	  else:
		  testInt = int(test,10)  	
	#  print('Output: ' + str(testInt))
	  return testInt

	def getSymbolName(self, line):
		items = line.split(' ')
		for item in items:
			if(item.endswith('[]')):
				lastIndex = len(item) - 2
				return item[:lastIndex]

	def ParseResDataOneLine(self, arrayObj, lineData):
		buffer = lineData.strip()
		if(len(buffer)<0 or buffer.startswith('{') or buffer.startswith('#')):
			#print('array mark of image data')	
			return -1
		elif (buffer.startswith('}')):
			#print('end of image data')
			# end of a image
			return -2
		elif (buffer.startswith('const') or buffer.startswith('__align(4)')):
			print('symbol found:' + buffer +'\n')
			#arrayObj.symbolName = self.getSymbolName(buffer)
			return 0
		else:
			#print('content...')
			lastItem = False
			if(buffer.endswith('};')):
				bytesStrings = bytesStrings.replace('};','')
				lastItem = True
			bytesStrings = buffer.split(',')
			for element in bytesStrings:
				elelementInput = element.strip()
				if(len(elelementInput)>0):
					arrayObj.append(self.binaryParse(elelementInput))
			if(lastItem is True):
				return -2
			else:
				return 1
	
	def ParseMapDataOneLine(self, arrayObj, lineData):
		buffer = lineData.strip()
		if(len(buffer)<0 or buffer.startswith('{') or buffer.startswith('#')):
			#print('array mark of image data')	
			return -1
		elif (buffer.startswith('}')):
			#print('end of image data')
			# end of a image
			return -2
		elif (buffer.startswith('const') or buffer.startswith('__align(4)')):
			print('symbol found:' + buffer +'\n')
			#arrayObj.symbolName = self.getSymbolName(buffer)
			return 0
		else:
			#print('content...')
			bytesStrings = buffer.split(',')
			if(len(bytesStrings) > 1 and  not bytesStrings[0] is None):
				arrayObj.append(int(bytesStrings[0]))
			#start parsing
			return 1
	
	def ParseSearchMapDataOneLine(self, arrayObj, lineData):
		buffer = lineData.strip()
		#	{48788, 48788, 2996},
		if(len(buffer)<0 or buffer == '{'):
			#print('array mark of image data')	
			return -1
		elif (buffer.startswith('}')):
			#print('end of image data')
			# end of a image
			return -2
		elif (buffer.startswith('const') or buffer.startswith('__align(4)')):
			print('symbol found:' + buffer +'\n')
			#arrayObj.symbolName = self.getSymbolName(buffer)
			return 0
		else:
			#print('content...')
			bytesStrings = buffer.replace('{','').replace('}','').split(',')			
			if(len(bytesStrings) >= 3):
				newEntry = []
				for index in range(0,3):
					newEntry.append(bytesStrings[index])
				arrayObj.append(newEntry)
			else:
				print('Search map parse error!!' + buffer + '\n')
			#start parsing
			return 1


	def parseValue(self,keyward):
		splitted = keyward.strip().split(':')
		if(len(splitted)>=2):
			return splitted[1].strip()
		else:
			return None

	def parse(self, fileName):
		dataMode = 0
		currentType = None
		currentLang = None
		currentBITMODE = None
		currentName = None
		currentMaxNum = None
		currentMaxId = None
		# start parsing
		intputStram = open(fileName)
		outputStream = None
		for line in intputStram.readlines():
			# start parsing
			if(line.startswith('#######')):
				# New Meta Information
				print('Meta section found!!')
				dataMode = 0
				currentType = None
				currentLang = None
				currentBITMODE = None
				currentName = None
				currentValue = None
				currentMaxNum = None
				currentMaxId = None
			else:
				if dataMode == 1:
					# Parse RES
					if currentType == 'RES':
						result = self.ParseResDataOneLine(outputStream, line)
						if(result == 0):
							outputStream = array.array('B')
						elif(result == -2):
							self.langRess[currentLang] = outputStream
							outputStream = None
							dataMode = 0
					elif currentType == 'MAP':
						result = self.ParseMapDataOneLine(outputStream, line)
						if(result == 0):
							outputStream =[]
						if(result == -2):
							self.langMaps[currentLang] = outputStream
							self.bitMode[currentLang] = currentBITMODE
							outputStream = None
							dataMode = 0
					elif currentType == 'SEARCH_MAP':
							result = self.ParseSearchMapDataOneLine(self.searchMap, line)
							if(result == 0):
								self.searchMap = []
							if(result == -2):
								dataMode = 0
				else:
					if(line.startswith('TYPE:')):
						currentType = self.parseValue(line)
						print('Parse Type: '+ currentType)
					elif(line.startswith('LANG:')):
						currentLang = self.parseValue(line)
						print('Parse Language: ' + currentLang)
					elif(line.startswith('BIT_MODE:')):
						currentBITMODE = self.parseValue(line)
						print('Parse BIT_MODE: ' + currentBITMODE)
					elif(line.startswith('NAME:')):
						currentName = self.parseValue(line)
						print('Parse Name: ' + currentName)
					elif(line.startswith('MAXID:')):
						currentMaxId = self.parseValue(line)
						self.maxId[currentLang] = currentMaxId
					elif(line.startswith('MAXNUM:')):	
						currentMaxNum = self.parseValue(line)
						self.maxNum[currentLang] = currentMaxNum
					elif(line.startswith('VALUE:')):
						currentValue = self.parseValue(line)
						if((not currentValue is None) and (not currentName is None)):
							self.attribute[currentName] = currentValue
							print('Parse (NALE: VALUE) =  ('+ currentName + ',' + self.attribute[currentName] + ')')
						else:
							print('Error --> currentValue and currentName can\'t be None\n')			
					elif(line.startswith('DATA:')):
						dataMode = 1
		print('Finish parse\n' )

class CompoundCodeGenerator:
	def __init__(self, strResourceGenerator, thirdROMResourceGenerator):
		self.strResourceGenerator = strResourceGenerator
		self.thirdROMResourceGenerator = thirdROMResourceGenerator
	
	def appendHeaderLines(self, outputStream):
		outputStream.write('#include \"mmi_features.h\"\n\n')
		outputStream.write('#include \"ResCompressConfig.h\"\n')
		outputStream.write('//---------------------------- THIRD ROM DATA START -------------------------------\n')
		outputStream.write('#if defined(__MMI_RESOURCE_STR_THIRD_ROM__)\n')
		outputStream.write('#include \"CustDataRes.h\"\n')
		outputStream.write('#include \"FontDCl.h\"\n')
		outputStream.write('#if (!defined (__MTK_TARGET__))\n')
		outputStream.write('    #define __align(x)\n')
		outputStream.write('#endif\n\n')

	def appendMediumLines(self, outputStream):
		outputStream.write('\n#endif //__MMI_RESOURCE_STR_THIRD_ROM__\n')
		outputStream.write('//---------------------------- THIRD ROM DATA END -------------------------------\n')
		outputStream.write('//------------------ NORMAL COMPRESSED ROM DATA START ---------------------------\n')
		outputStream.write('#if !defined(__MMI_RESOURCE_STR_THIRD_ROM__)\n')
		outputStream.write('#if defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__)\n')
		outputStream.write('#include \"CustDataRes.h\"\n')
		outputStream.write('#include \"FontDCl.h\"\n')
		outputStream.write('#if (!defined (__MTK_TARGET__))\n')
		outputStream.write('    #define __align(x)\n')
		outputStream.write('#endif\n\n')

	def appendBottomLines(self, outputStream):
		outputStream.write('\n#endif // __MMI_RESOURCE_STR_LZMA_COMPRESS__\n')
		outputStream.write('\n#endif //__MMI_RESOURCE_STR_THIRD_ROM__\n')
		outputStream.write('//------------------ NORMAL COMPRESSED ROM DATA START ---------------------------\n')

	def appendSearchSourceEntry(self, binaryStringModel, generator, outputStream):
		catBufSymAdaptor = CATStringBufferSymbolAdaptor(binaryStringModel)
		slimBufSymAdaptor = StringBufferSymbolAdaptor(binaryStringModel)

		outputStream.write('const U16 mtk_gTrans_string_count = ' + binaryStringModel.attribute['mtk_gTrans_string_count'] + ';\n')	
		outputStream.write('\n' + generator.generateSearchMap(binaryStringModel) + '\n')
		outputStream.write(generator.generateStringROMSymbolExterns(binaryStringModel) + '\n')
		outputStream.write('#ifdef __CAT_SUPPORT__\n')
		outputStream.write(generator.generateStringResList(binaryStringModel, catBufSymAdaptor))
		outputStream.write('#else //__CAT_SUPPORT__\n')
		outputStream.write(generator.generateStringResList(binaryStringModel, slimBufSymAdaptor))
		outputStream.write('#endif  //__CAT_SUPPORT__\n')
		

	def generateSearchSource(self, strObjectModel, fileName):
		outputStream = open(fileName, 'w')
		self.appendHeaderLines(outputStream)
		self.appendSearchSourceEntry(strObjectModel, self.thirdROMResourceGenerator, outputStream)
		self.appendMediumLines(outputStream)
		self.appendSearchSourceEntry(strObjectModel, self.strResourceGenerator, outputStream)
		self.appendBottomLines(outputStream)
		outputStream.close()


class CATStringSetting:
	def __init__(self, isCompress=False, compressAlgo = None):
		self.isCompress = isCompress
		self.compressAlgo = compressAlgo
	
	def writeToFile(self, fileName):
		outputStream = open(fileName, 'w')
		outputStream.write('# CAT Settings\n# MMIResource String\n')
		outputStream.write(self.toString())
		outputStream.close()
	
	def loadSettingItem(self, itemName, itemValue):
		if itemName.strip() == 'IsCompression':
			if int(itemValue.strip()) == 1:
				self.isCompress = True
			else:
				self.isCompress = False
			
		elif itemName.strip() == 'CompressAlgo':
			self.compressAlgo = itemValue.strip()
	
	def toString(self):
		result = ''
		if self.isCompress==True:
			result = result + 'IsCompression=' + '1'+ '\n'
		else:
			result = result + 'IsCompression=' + '0'+ '\n'
		if(not self.compressAlgo is None):
			result = result + 'CompressAlgo=' + self.compressAlgo + '\n'
		return result
		
	def loadFromFile(self, fileName):
		if( os.path.exists(fileName)):
			intputStream = open(fileName,'r')
			for line in intputStream.readlines():
				if(not line.startswith('#')):
					items = line.split('=')
					if(len(items) >= 2):
						self.loadSettingItem(items[0], items[1])
			if(self.isCompress is True):
				print('Load CAT String Setting: Compress = ' + str(self.isCompress) + ' ,Algo = ' + self.compressAlgo)
			else:
				print('Load CAT String Setting: Compress = ' + str(self.isCompress))
			
			intputStream.close()
			
def backupFile(fileName):
	originFileName = fileName
	newFileName= fileName + '.comp.bak'
	if(os.path.exists(fileName)):
		shutil.copyfile(fileName, newFileName)

####################################################
# Module Entry
####################################################
# Check if the file is being run as a top-level program file before 
# invoke main method
if __name__ == '__main__':
	rootPath = '..\\..\\..\\'
	result = 0
	paddingSize = 0

	if(len(sys.argv)<1):
		usage()
		result = 1
	try:
		#Parse command line parameter
		opts, args = getopt.getopt(sys.argv[1:], 'sp:')
		for o, a in opts:
			if o == '-s':
				rootPath = a
			if o == '-p':
				paddingSize = int(a)
		rootPath = os.path.normpath(rootPath)
		print('Root of SW-Load: ' + os.path.abspath(rootPath))
		print('paddingSize: ' + str(paddingSize))
		
		strObjectModel = BinaryStringModel('Test')
		strObjectModel.parse(rootPath + '\\plutommi\\Customer\\CustResource\\CustStrMapMeta.txt')
		strObjectModel.parse(rootPath + '\\plutommi\\Customer\\CustResource\\CustStrResMeta.txt')
#		compressionAdapter = ZlibCompressionAdaptor('ZLIB', '..\\..\\..\\plutommi\\customer\\resgenerator\\mtk_resgenerator.exe')
		compressionAdapter = LzmaCompressionAdaptor('LZMA', '..\\..\\..\\tools\\7lzma')
		strObjectModel.compress(compressionAdapter)
		strObjectModel.decompressTest(compressionAdapter)
		backupFile(rootPath + '\\plutommi\\Customer\\CustResource\\CustStrRes.c')
		backupFile(rootPath + '\\plutommi\\Customer\\CustResource\\CustStrMap.c')
		thirdROMResourceGenerator = ThirdROMStrResCodeGeneartor('Third ROM')
		strResourceGenerator = CompressedStrResCodeGenerator('Compressed ROM')
		compoundCodeGenerator = CompoundCodeGenerator(strResourceGenerator, thirdROMResourceGenerator)
		strResourceGenerator.geneateResSource(strObjectModel,rootPath + '\\plutommi\\Customer\\CustResource\\CustStrResComp.c', paddingSize)
		strResourceGenerator.generateMapSource(strObjectModel,rootPath + '\\plutommi\\Customer\\CustResource\\CustStrMapComp.c')
		# strResourceGenerator.generateSearchSource(strObjectModel,rootPath + '\\plutommi\\Customer\\CustResource\\CustStrSearchComp.c')
		thirdROMResourceGenerator.geneateBinaryFromStringModel(strObjectModel,rootPath + '\\plutommi\\Customer\\CustResource\\CustStr3rdROM.bin',2048)
		compoundCodeGenerator.generateSearchSource(strObjectModel,rootPath + '\\plutommi\\Customer\\CustResource\\CustStrSearchComp.c')
		
		# Save setting for CAT DB gen
		catSetting = CATStringSetting(True, 'LZMA')
		catSetting.writeToFile(rootPath + '\\plutommi\\customer\\resgenerator\\debug\\cat_string_setting.txt')
		
		result = 0
		
	except getopt.GetoptError, err:
		usage()
		result = 1	
	except:
		result = 1
		print '\n', '-'*20, "python exception start", '-'*20
		traceback.print_exc(file=sys.stdout)
		print '-'*20, "python exception  end ", '-'*20
		raise
	finally:
		sys.exit(result)
####################################################