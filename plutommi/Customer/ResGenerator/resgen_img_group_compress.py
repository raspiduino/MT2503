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

from resgen_log import ResgenLog
from resgen_offline_param import ImageResParam, ImageResParamModel, GeneralResParamModel, ImageParamTextFileDAO
from resgen_util_compress import LzmaCompressionAdaptor, ZlibCompressionAdaptor, ByteUtil, ThirdRomBinaryGenerator, ThirdROMEntry

####################################################
# Usgae print
####################################################
def usage():
	print('Usage: python res_img_group.py')


			
####################################################
# MTK Binary Image Resource Domain Object
####################################################
class BinaryImage:
	def __init__(self, symbolName=''):
		self.symbolName = symbolName
		self.rawContent = array.array('B')
		self.group = 0
		self.offset = 0
		self.compressed = True
	
	def isCompressed(self):
		return self.compressed

	def setCompressed(self, compressed):
		self.compressed = compressed

	def getSize(self):
		return len(self.rawContent)
		
	def getType(self):
		index = self.symbolName.rfind('_')
		if(index < 0):
			return "unknown"
		else:
			return self.symbolName[(index+1):]

####################################################
# MTK Binary Image Resource Group Domain Object
####################################################
class BinaryImageGroup:
	def __init__(self, name):
		self.images = []
		self.mergedImage = array.array('B')
		self.compressedImage = None
		self.name = name
		self.thirdROMEntry = None
		self.compressedThirdROMEntry = None

	@staticmethod
	def getImageHandle(groupIndex, imageIndex, offsetLength):
		handle_flag = 1
		handle = (groupIndex<< (offsetLength + 1)) | (imageIndex<<1) | handle_flag
		return handle
	
	def getSimpleCacheName(self):
		return 'cache_' + self.name
		
	def getName(self):
		return self.name

	# When noCompreession is True, the compression size is replaces by original size
	def getHeader(self, isCompressed = True):
		oriSize = self.getOriginalSize()
		compressSize = self.getCompressedSize()
		header = array.array('B', [0,0,0,0])
		header[0] = (0xFF00 & oriSize) >>8
		header[1] = 0x00FF & oriSize
		if (isCompressed is True):
			header[2] = ((0xFF00 & compressSize) >>8)
			header[3] = 0x00FF & compressSize
		else:
			header[2] = ((0xFF00 & oriSize ) >>8)
			header[3] = 0x00FF & oriSize			
		return header
	
		
	def addImage(self, imgObject):
		self.images.append(imgObject)
		size = len(imgObject.rawContent)
		header = array.array('B', [0,0,0,0])
		header[0] = (0xFF000000 & size) >> 24
		header[1] = (0x00FF0000 & size) >> 16
		header[2] = (0x0000FF00 & size) >> 8
		header[3] = (0x000000FF & size)
		self.mergedImage.extend(header)
		self.mergedImage.extend(imgObject.rawContent)


	def getOriginalSize(self):
		return len(self.mergedImage)
	
	def getCompressedSize(self):
		if not self.compressedImage is None:
			return len(self.compressedImage)
		else:
			return 0
	
	def getContent(self, isCompressed = True):
		if(isCompressed is False):
			return self.getMergedImage()
		else:
			return self.getCompressedImage()
	
	def getMergedImage(self):
		return self.mergedImage
	
	def setCompressedImage(self, compressedImage):
		self.compressedImage = compressedImage
	
	def getCompressedImage(self):
		return self.compressedImage

	def setThirdROMEntry(self, entryObj, isCompression = True):
		if(isCompression is False):
			self.thirdROMEntry = entryObj
		else:
			self.compressedThirdROMEntry = entryObj
	
	def getThirdROMEntry(self, isCompression = True):
		if(isCompression is False):
			return self.thirdROMEntry
		else:
			return self.compressedThirdROMEntry
		
	def toDebugString(self):
		result = self.name + ', images:\n'
		for item in self.images:
			result = result + item.symbolName + '\n' + 'Group: ' + str(item.group) + ', Offset: ' + str(item.offset) + '\n'
		result = result + 'Ori Size = ' + str(self.getOriginalSize()) + ', Compress Size =  ' + str(self.getCompressedSize()) + '\n'
		return result


####################################################
# MTK Binary Image Group Greator
# - Parsed from custimage C arraies
####################################################

class GroupCreator:

	def __init__(self, imageModel, paramModel,  multiImgGroupMaxSize, singleImgGroupMaxSize, bootImgGroupMaxSize, bootImgResourceId, imageIndexFieldLength = 5, groupHandleLength = 16):
		# header bytes: 4 bytes
		self.singleImgGroupMaxSize = singleImgGroupMaxSize - 4
		self.bootImgGroupMaxSize = bootImgGroupMaxSize - 4
		self.multiImgGroupMaxSize = multiImgGroupMaxSize - 4
		self.bootImgResourceId = bootImgResourceId
		self.groupObject = []
		self.allImageModel = imageModel
		self.paramModel = paramModel
		self.noGroupingImageModel = BinaryImageModel('No Grouping Images')
		self.imageModel = BinaryImageModel('Grouped Images')
		self.offsetLength = imageIndexFieldLength
		self.filter = NoCompressionBinaryImageFilter('default filter', paramModel, self.singleImgGroupMaxSize, self.bootImgGroupMaxSize, bootImgResourceId)
		self.filter.filterAll(imageModel,self.noGroupingImageModel, self.imageModel)
		self.imageNumberLimit = (1<< self.offsetLength) -1
		self.groupNumberLimit = (1<< (groupHandleLength -self.offsetLength - 1)) - 1
		print('Image Number Limit of a Group:' + str(self.imageNumberLimit))
		print('Group Number Limit:' + str(self.groupNumberLimit))
		
			
	def getOffsetLength(self):
		return self.offsetLength
	
	def getNoCompressImages(self):
		return self.noGroupingImageModel

	def compressSingleGroup(self, groupObj, compressionAdaptor):
		total_size = 0
		total_effective_compress_size = 0
		total_compress_size = 0
		if not compressionAdaptor is None:
			compressMethod = compressionAdaptor.name
		else:
			compressMethod = 'No Compression'
		print("=======================================================")
		print(compressMethod + ': Sinal Group Compress')
		print("=======================================================")
		print('[Orig. Size]\t[Compressed Size]\t[Compression Ratio]')
		
		compressRawData = None
		
		if(not compressionAdaptor is None):
					
			completeFileName = '.\\temp\\' + groupObj.name + '.bin'
			outputFileName = completeFileName + '.' + compressionAdaptor.fileExtName
	
			ByteUtil.writeFile(groupObj.getMergedImage(),completeFileName)	
			
			compressionAdaptor.compress(outputFileName, completeFileName)

			compressRawData	= ByteUtil.readFile(outputFileName)
			# unite Test only-------------------------------
			tempCompressionFile = outputFileName + '.decom'
			ByteUtil.writeFile(compressRawData, tempCompressionFile)
			verificationFileName = outputFileName + '.' + 'verify'
			compressionAdaptor.decompress(verificationFileName, tempCompressionFile)
			decompressRawData = ByteUtil.readFile(verificationFileName)
			if(ByteUtil.compare(groupObj.getMergedImage(), decompressRawData) is True):
				print('Unit Test Passed')
			else:
				print('Unit Test Failed')				
			# -------------------------------unite Test only

			
			self.printCompressLog(len(groupObj.getMergedImage()), len(compressRawData))
		else:
			compressRawData = array.array('B')
			compressRawData.extend(groupObj.getMergedImage())

		groupObj.setCompressedImage(compressRawData)
		self.printCompressLog(groupObj.getOriginalSize(), groupObj.getCompressedSize())
	

	def printCompressLog(self, original_size, compression_size):
		compression_ratio = float( float(compression_size)/float(original_size))
		print(str(original_size) + '\t' + str(compression_size) + '\t' + str(compression_ratio))
	
	def debugImageHandle(self, handle):
		isHanle = handle & 0x0001
		groupMask = ( 0xFFFF >> (self.offsetLength + 1) ) << (self.offsetLength + 1)
		groupValueMask = ~ (0xFFFF << ( 16 - self.offsetLength - 1) )
		group  = ( handle & groupMask ) >> (self.offsetLength + 1)
		print('GROUP MASK: ' + hex(groupMask))
		offset = ( handle & (~groupMask)) >> 1
		result = 'Group: ' + str(group) + '\t Offse:' + str(self.offsetLength) + '\t isHandle:' + str(isHanle)
		return result
	
	# Create a image map model from Map meta file
	def loadImageMapFromMeta(self, fileName, imageFileMap):
		imageModel = BinaryImageModel('ImageMap')
		if(not os.path.exists(fileName)):
			print('[ERROR] File not found:' + fileName)
			return None
		# start load image map table
		inputStream = open(fileName)
		for line in inputStream.readlines():
			strippedLine = line.strip()
			if len(strippedLine) > 0:
				symbolName = strippedLine
				if not symbolName in imageFileMap:
					print('Fatal Error!!' + symbolName + ' doesn\'t EXIST!!')
				else:
					tempObj = imageFileMap[symbolName]
					imageModel.add(tempObj)
		return imageModel
	
	def generateNoCompressionGroup(self):
		return self.generateCompressionGroup(None)
	
	def generateCompressionGroup(self, compressAdaptor):
		self.groupObject = []
		imgeNumber = 0
		groupSize = 0
		currentGroup = None
		groupIndex = -1
		for item in self.imageModel.binaryObject:
			# size check with 4 bytes image wrapper header
			tempSize = groupSize + item.getSize() + 4 
			tempImageNum = imgeNumber + 1
			if((groupIndex+1) >= self.groupNumberLimit):
				print('** Can\'t put into group, group handle is out of use: ' + item.symbolName + ', limitation = ' + str(self.groupNumberLimit))
				self.noGroupingImageModel.add(item)
			else:
				if( (tempSize > self.multiImgGroupMaxSize) or tempImageNum > self.imageNumberLimit or currentGroup is None):
					groupIndex = groupIndex + 1
					currentGroup = BinaryImageGroup('image_group_' + str(groupIndex))
					self.groupObject.append(currentGroup)
					currentGroup.addImage(item)
					groupSize = item.getSize() + 4
					imgeNumber = 1
				else:
					currentGroup.addImage(item)
					groupSize = tempSize
					imgeNumber = tempImageNum
				item.group = len(self.groupObject) -1
				item.offset = len(currentGroup.images) -1
			
		# Output Group Information
		for item in self.groupObject:
			self.compressSingleGroup(item, compressAdaptor)
			print(item.toDebugString()+'\n')


class ImageCodeGenerator:
	def __init__(self, charsPerLine):
		self.charsPerLine = charsPerLine
	
	def appendImageMapTable(self, outputStream, imageMapModel, compressedImageModel, imageOffestLen):
		outputStream.write('#include \"CustResDef.h\"\n')
		outputStream.write('//const S8 CustImgPath[]=CUST_IMG_PATH;\n')
		outputStream.write('const unsigned short  mtk_CurrMaxHandlesNum = ' + str(len(imageMapModel.binaryObject))+ ';\n')
		outputStream.write('const CUSTOM_IMAGE	mtk_nCustImageHandles[]={\n')
		
		totalImage = len(imageMapModel.binaryObject)
		for index in range(0, totalImage):
			imageObj = imageMapModel.binaryObject[index]
			# check if the object is exsit in image object pool (imageAllModel)
			if not compressedImageModel.getBinaryObject(imageObj.symbolName) is None:
				# Create Handle Here
				hexStr = '0xB000%04X' % (BinaryImageGroup.getImageHandle(imageObj.group, imageObj.offset, imageOffestLen))
				outputStream.write('    (U8*)'+ hexStr)
			else:
				outputStream.write('    (U8*)&'+ imageObj.symbolName)
				
			if(index != (totalImage -1)):
				outputStream.write(', // ' + imageObj.symbolName + ', Group: ' + str(imageObj.group) + ', Offset: ' + str(imageObj.offset))
				outputStream.write('\n')
			else:
				outputStream.write('  //' + imageObj.symbolName + ', Group: ' + str(imageObj.group) + ', Offset: ' + str(imageObj.offset))
				outputStream.write('\n')
		outputStream.write('};\n')

	
# Generate GroupArray
# The symbol should encoded the group objects
	def GroupToCArray(self, groupObject):
		symbolName = groupObject.getName()
		headerByteArray = groupObject.getHeader()
		headerLen = len(headerByteArray)
		contentByteArray = groupObject.getCompressedImage()
		contentLen = len(contentByteArray)

		cArrayString = '__align(4) const U8 ' + symbolName + '[] = {';
		cArrayString = cArrayString + self.byteArrayToCArrayContent(headerByteArray) + ','
		cArrayString = cArrayString + self.byteArrayToCArrayContent(contentByteArray) + '\n};\n'

		return cArrayString

# Generate Simple Group Cache
	def GroupToSimpleCacheArray(self, groupObject):
		cacheSize = len(groupObject.getMergedImage()) + len(groupObject.getHeader())
		return '__align(4) U8 '+ groupObject.getSimpleCacheName() + '[' + str(cacheSize) +'];\n'


# Generate C array content from byte array
	def byteArrayToCArrayContent(self, contentByteArray, padding = '    '):
		cArrayString = ''
		contentLen = len(contentByteArray)
		for byteIndex in range(0, contentLen):
			if(byteIndex % self.charsPerLine == 0 ):
				cArrayString = cArrayString + '\n' + padding
			cArrayString = cArrayString + '0x%02X' % (contentByteArray[byteIndex])
			
			if(byteIndex != (contentLen -1)):
				cArrayString = cArrayString + ', '
		return cArrayString


# Generate Single ImageArray
	def ImageToCArray(self, imageObject):
		cArrayString = '__align(4) const U8 '  + imageObject.symbolName + '[] = {'
		cArrayString = cArrayString + self.byteArrayToCArrayContent(imageObject.rawContent) + '\n};\n'
		return cArrayString

	
class MainBinImageCodeGenerator(ImageCodeGenerator):
	def __init__(self, charsPerLine):
		self.charsPerLine = charsPerLine

	def appendHeaderLines(self, outputStream, utAllowed = True):
		outputStream.write('#include \"CustDataRes.h\"\n')
		outputStream.write('#include \"ResCompressConfig.h\"\n\n')
		outputStream.write('#ifndef __MMI_RESOURCE_IMAGE_THIRD_ROM__\n')
		outputStream.write('#ifdef __MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__\n\n')
		if(utAllowed is False):
			outputStream.write('\n#ifndef  __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n\n')
		
		
	def appendBottomLines(self, outputStream, utAllowed = True):
		if(utAllowed is False):
			outputStream.write('\n#endif //__MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n\n')		
		outputStream.write('\n#endif  //__MMI_RESOURCE_LZMA_IMAGE_GROUP_COMPRESS__\n\n')
		outputStream.write('\n#endif  // __MMI_RESOURCE_IMAGE_THIRD_ROM__\n')


# Generate CustImgGroupSingleDataHW.h
# - Declaration of single image content
	def generateSingleImageHeader(self, headerFileName, noCompressionImageModel):
		headerOutputStream = open(headerFileName,'w')
		headerOutputStream.write('#ifndef __CUST_IMG_GROUP_SINGLE_RES_H__\n')
		headerOutputStream.write('#define __CUST_IMG_GROUP_SINGLE_RES_H__\n\n')
		self.appendHeaderLines(headerOutputStream, False)
				
		for item in noCompressionImageModel.binaryObject:
			headerOutputStream.write('extern const U8 ' + item.symbolName + '[];\n')	
			
		self.appendBottomLines(headerOutputStream, False)
		headerOutputStream.write('#endif // __CUST_IMG_GROUP_SINGLE_RES_H__\n')
		headerOutputStream.close()


#	Generate CustImgGroupSingleDataRes.c
# - Definition of single image content
	def generateSingleImageSource(self, resFileName, noCompressionImageModel):
		outputStream = open(resFileName,'w')
		self.appendHeaderLines(outputStream, False)
		
		outputStream.write('#if ( !defined (__MTK_TARGET__) )\n')
		outputStream.write('\t#define __align(x)\n')
		outputStream.write('#endif\n')
				
		for item in noCompressionImageModel.binaryObject:
			outputStream.write(self.ImageToCArray(item) + '\n')
		
		self.appendBottomLines(outputStream, False)
		outputStream.close()
		

# Generate CustImgGroupDataHW.h
# - Declaration of mage group content
	def generateGrouopImageHeader(self, resFileName, groupList, simpleCache):
		utAllowed = True
		headerOutputSteam = open(resFileName,'w')
		
		headerOutputSteam.write('#ifndef __CUST_IMG_GROUP_DATA_HW_H_\n')
		headerOutputSteam.write('#define __CUST_IMG_GROUP_DATA_HW_H_\n')
		
		self.appendHeaderLines(headerOutputSteam, utAllowed)

		headerOutputSteam.write('#if ( !defined (__MTK_TARGET__) )\n')
		headerOutputSteam.write('    #define __align(x)\n')	
		headerOutputSteam.write('#endif\n\n')	

		# Group array Output
		for groupItem in groupList:
			headerOutputSteam.write('extern const U8 ' + groupItem.getName() + '[];\n')
		
		if simpleCache is True:
			headerOutputSteam.write('\n#ifdef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__\n')
			for groupItem in groupList:
				headerOutputSteam.write('extern U8 ' + groupItem.getSimpleCacheName() + '[];\n')
			headerOutputSteam.write('\n#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__\n\n')
		
		self.appendBottomLines(headerOutputSteam, utAllowed)
		headerOutputSteam.write('\n#endif//__CUST_IMG_GROUP_DATA_HW_H_\n')
		headerOutputSteam.close()
		return True

# Generated Splitted CustImgGroupDataRes_[n].c
# - Definition of image group content
	def generateGroupImageSplittedSource(self, groupSourceFile, groupList, number):
		# Create the file name and list
		totalGroup = len(groupList)
		groupPerFile = totalGroup/number
		
		for fileIndex in range(0, number):
			fileName = groupSourceFile + '_' + str(fileIndex) + '.c'			
			if( fileIndex == (number-1)):
				groupListPerFile = groupList[groupPerFile*fileIndex:]
			else:
				groupListPerFile = groupList[groupPerFile*fileIndex:(groupPerFile*(fileIndex+1))]

			self.generateGroupImageSource(fileName,groupListPerFile)
		
		return True

# Generate CustImgGroupDataRes.c
# - Definition of image group content
	def generateGroupImageSource(self, groupSourceFile, groupList):
	
		outputStream = open(groupSourceFile,'w')
		groupCount = 0
		groupTotal = len(groupList)
		
		# Start: Header Inclusion --------------------------------------------
		self.appendHeaderLines(outputStream, True)

		outputStream.write('#if ( !defined (__MTK_TARGET__))\n')
		outputStream.write('    #define __align(x)\n')
		outputStream.write('#endif\n\n')
		outputStream.write('#include \"CustImgGroupDataHW.h\"\n')
		# End: Header Inclusion ----------------------------------------------
	
	  # Start: Group array output ------------------------------------------
		for groupItem in groupList:
			outputStream.write(self.GroupToCArray(groupItem))
	  # End: Group array output ------------------------------------------

		# Simple Cache Array Output, this feature is only for bug verification
		# Should not be enabled in OF load configuration
		outputStream.write('\n#ifdef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__\n')
		
		for groupItem in groupList:
			outputStream.write(self.GroupToSimpleCacheArray(groupItem))

		outputStream.write('#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__\n')
		self.appendBottomLines(outputStream, True)
		outputStream.close()
		return True

# Generate CustImgGroupRes.c
# - a table to access group by group index
	def generateImageMapSource(self, mapFileName, imageMapModel, compressedImageModel, imageOffestLen):
		outputStream = open(mapFileName,'w')
		self.appendHeaderLines(outputStream, True)
		
		outputStream.write('#include \"CustImgGroupDataHW.h\"\n')
		outputStream.write('#include \"CustGameDataHW.h\"\n')
		outputStream.write('#ifdef __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__ \n')
		outputStream.write('#include \"CustImgDataHW.h\"\n')
		outputStream.write('#else  //__MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n')
		outputStream.write('#include \"CustImgGroupSingleDataHW.h\"\n')
		outputStream.write('#endif // __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n')
		self.appendImageMapTable(outputStream, imageMapModel, compressedImageModel, imageOffestLen)	
		self.appendBottomLines(outputStream, True)
		outputStream.close()


# Generate CustImgGroupRes.c
# - a table to access image integtate image handle and noncompressed image buffer
	def generateGroupMapSource(self, mapFileName, groupList, simpleCache):
		groupTotal = len(groupList)
		outputStream = open(mapFileName, 'w')
		self.appendHeaderLines(outputStream, True)
		outputStream.write('#include \"CustResDef.h\"\n')
		outputStream.write('#include \"CustImgGroupDataHW.h\"\n')
		outputStream.write('const unsigned short  mtk_CurrMaxGroupsNum = ' + str(groupTotal)+ ';\n\n')
		outputStream.write('const CUSTOM_IMAGE	mtk_nCustGroupNames[]={\n')

		# Group array Output
		for groupIndex in range(0, groupTotal):
			outputStream.write('    (U8*)&' + groupList[groupIndex].getName())
			if(groupIndex != groupTotal - 1):
				outputStream.write(',\n')
		outputStream.write('\n};\n')		
		
		if simpleCache is True:
			outputStream.write('\n#ifdef __MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__\n')
			outputStream.write('const CUSTOM_IMAGE	mtk_nCustGroupCacheNames[]={\n')
			for groupIndex in range(0, groupTotal):
				outputStream.write('    (U8*)&' + groupList[groupIndex].getSimpleCacheName())
				if(groupIndex != groupTotal - 1):
					outputStream.write(',\n')
			outputStream.write('\n};\n')
			outputStream.write('\n#endif //__MMI_RESOURCE_UT_SIMPLE_CACHE_SUPPORT__\n\n')
		self.appendBottomLines(outputStream, True)
		outputStream.close()
		return True



					
class AbstractBinaryImageFilter:
	def __init__(self, name):
		self.name = name
	
	def filter(self, imageObject):
		return Ture
	
	def filterAll(self, sourceModel, includedModel, excludedModel):
		for item in sourceModel.binaryObject:
			if self.filter(item) is True:
				includedModel.add(item)
			else:
				excludedModel.add(item)
		return True

# filter by size and isCompressedAttribute
class NoCompressionBinaryImageFilter(AbstractBinaryImageFilter):
	def __init__(self, name, paramModel, singleImgMaxSize, bootImgMaxSize, bootupLogoId = None):
		self.name = name
		self.paramModel = paramModel
		self.singleImgMaxSize = singleImgMaxSize
		self.bootImgMaxSize = bootImgMaxSize
		self.bootupLogoId = bootupLogoId
		
	
	def filter(self, imageObject):
	# Allow large bootuplogo
		if( not self.bootupLogoId is None):
			foundParam = self.paramModel.getImageWithSymbol(imageObject.symbolName)
			for itemParam in foundParam:
				if ((itemParam.idEnumString == self.bootupLogoId) and ( (imageObject.getSize()+4) <= self.bootImgMaxSize)):
					return False
	# ________CUSTOMER__IMAGES__DEFAULT_BMP and ________CUSTOMER__IMAGES__EMPTYIMAGE_BMP must be filtered
		# Need add header size (4 bytes) when check image size
		if ((imageObject.getSize()+4 ) > self.singleImgMaxSize) or (not imageObject.isCompressed() or imageObject.symbolName.upper() ==  '________CUSTOMER__IMAGES__DEFAULT_BMP' or imageObject.symbolName.upper() ==  '________CUSTOMER__IMAGES__EMPTYIMAGE_BMP'):
			return True
		else:
			return False



####################################################
# MTK Binary Image Resource Data Model
# - Parsed from custimage C arraies
####################################################
class BinaryImageModel:
	def __init__(self, name):
		self.name = name
		self.binaryObject = []
		self.dicRecord = {}

	def showBinaryObject(self, imageFilesFolder = 'images'):
		# Print PNG Report
		print('==========================================')
		print(self.name)
		print('==========================================')
		print('[Symbol]\t[File Size]')
		totalSize = 0;
		for item in self.binaryObject:
			singleSize = len(item.rawContent);
			print(item.symbolName + '\t' + str(singleSize))
		print('==========================================')
		print('Total Image Size = ' + str(self.getTotalSize()))
		print('==========================================')
		print('File Mappings')
		print('==========================================')
		#self.save(self.imageFilesFolder)
		return 0
		
	####################################################
	# File Append 
	####################################################
	def getTotalSize(self):
		totalSize = 0
		for binObj in self.binaryObject:
			totalSize += len(binObj.rawContent)
		return totalSize
		
	def getTotalImage(self):
		return len(self.binaryObject)
	
	def add(self, item):
		self.binaryObject.append(item)
		self.dicRecord[item.symbolName] = item
	
	def getBinaryObject(self, symbolName):
		if symbolName in self.dicRecord:
			return self.dicRecord[symbolName]
		else:
			return None
#		for  binObj in self.binaryObject:
#			if binObj.symbolName == symbolName:
#				return binObj
#		return None

	####################################################
	# File Append 
	####################################################
	def fileAppend(self, dest, source):
		print('File Append: ' + dest + ' to ' + source)
		inputStream = open(source,'rb')
		outputStream = open(dest, 'ab')
		while True:
			bytes = inputStream.read(2048)
			if not bytes: break
			outputStream.write(bytes)
		
		inputStream.close()
		outputStream.close()
	
	def getBinaryFileNames(self):
		count = 0		
		fileNames = []
		for obj in self.binaryObject:
			fileName = 'img' + str(count) + '.bin'
			fileNames.append(fileName)
			count = count + 1
		return fileNames
	
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

	def binaryParseOneLine(self, arrayObj, lineData):
		buffer = lineData.strip()
		if(len(buffer)<0 or buffer.startswith('{') or buffer.startswith('#')):
			#print('array mark of image data')	
			return -1
		elif (buffer.startswith('}')):
			#print('end of image data')
			# end of a image
			return -2
		elif (buffer.startswith('const') or buffer.startswith('__align(4)')):
			#print('start of image data')
			arrayObj.symbolName = self.getSymbolName(buffer)
			return 0
		else:
			#print('content...')
			bytesStrings = buffer.split(',')
			for element in bytesStrings:
				elelementInput = element.strip()
				if(len(elelementInput)>0):
					arrayObj.rawContent.append(self.binaryParse(elelementInput))
			#start parsing
			return 1

	def parse(self, fileName):
		# start parsing
		intputStram = open(fileName)
		# outputStream = array.array('B')
		outputStream = BinaryImage()
		for line in intputStram.readlines():
			result = self.binaryParseOneLine(outputStream, line)
			if(result == -2):
				# end of a image, create a new array object
				self.add(outputStream)
				outputStream = BinaryImage()
		print("Finish parse, Total Image: " + str(len(self.binaryObject))+ " Totl size:" + str(self.getTotalSize()) )
		
	def save(self, folderName):
		count = 0		
		for obj in self.binaryObject:
			fileName = 'img' + str(count) + '.bin'
			print(fileName + '-->' + obj.symbolName )
			outputstreamWriter = open(folderName + '\\' + fileName, 'wb')
			obj.rawContent.tofile(outputstreamWriter)
			outputstreamWriter.close()
			count = count + 1


####################################################
# ImageResourceLoader:
# - A broaker class load the required image data
#   from external system
####################################################
class ImageResourceLoader:
	def loadImageOfflineParam(self):
		offlineParamModel = ImageResParamModel('Image Resource Params', True)
		dao = ImageParamTextFileDAO()
		offlineParamModel.loadFromRepository(GeneralResParamModel.DEFAULT_REPO_IMAGE_XML, dao)
		offlineParamModel.loadFromRepository(GeneralResParamModel.DEFAULT_REPO_IMAGE_PREXML_LEGACY, dao)
		offlineParamModel.loadFromRepository(GeneralResParamModel.DEFAULT_REPO_IMAGE_POSTXML_LEGACY, dao)
		return offlineParamModel
	
	
	def loadDefaultMImageModel(self,offlineParamModel):
		# Load Image Symbols
		binObjModel = BinaryImageModel('Default MMIResource')
		binObjModel.parse(rootPath+'\\plutommi\\customer\\custresource\\custimgdatahwBak.h')
	
		# Load Image population paramters to get compression setting
		for item in offlineParamModel.items:
			if item.isCompression == 0:
				binObj = binObjModel.getBinaryObject(item.symbolName)
				if not binObj is None:
					binObj.compressed = False
				else:
					print('Error, symbol not found:' + item.symbolName)
					print(item.toString())
		binObjModel.showBinaryObject()
		return binObjModel

####################################################
# 3rd ROM Binary Generator
# - Generate final binary file
# - Generate resource base header for each type of mmiresource
####################################################

class ThirdROMImageCodeGenerator(ImageCodeGenerator):
	def __init__(self, charsPerLine):
		self.charsPerLine = charsPerLine
	
	def appendHeaderLines(self, outputStream, utAllowed = True):
		outputStream.write('#include \"CustDataRes.h\"\n')
		outputStream.write('#include \"ResCompressConfig.h\"\n')	
		outputStream.write('#ifdef __MMI_RESOURCE_IMAGE_THIRD_ROM__\n')
		if(utAllowed is False):
			outputStream.write('#ifndef  __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n\n')
			
	def appendBottomLines(self, outputStream, utAllowed = True):
		if(utAllowed is False):
			outputStream.write('\n\n#endif // __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n\n')
		outputStream.write('\n\n#endif // __MMI_RESOURCE_IMAGE_THIRD_ROM__\n')
	
	
	# Generate CustImgGroupSingleDataHW.h
	# - Declaration of single image content
	def generateSingleImageHeader(self, headerFileName, noCompressionImageModel):
		headerOutputStream = open(headerFileName,'w')
		headerOutputStream.write('#ifndef __CUST_IMG_GROUP_SINGLE_THIRDROM_RES_H__\n')
		headerOutputStream.write('#define __CUST_IMG_GROUP_SINGLE_THIRDROM_RES_H__\n\n')
		self.appendHeaderLines(headerOutputStream, False)
				
		for item in noCompressionImageModel.binaryObject:
			headerOutputStream.write('extern const U8 ' + item.symbolName + '[];\n')	
		
		self.appendBottomLines(headerOutputStream, False)
		headerOutputStream.write('\n\n#endif // __CUST_IMG_GROUP_SINGLE_THIRDROM_RES_H__\n')
		headerOutputStream.close()


#	Generate CustImgGroupSingleDataRes.c
# - Definition of single image content
	def generateSingleImageSource(self, resFileName, noCompressionImageModel):
		outputStream = open(resFileName,'w')
		self.appendHeaderLines(outputStream, False)
		outputStream.write('#if ( !defined (__MTK_TARGET__) )\n')
		outputStream.write('\t#define __align(x)\n')
		outputStream.write('#endif\n')
				
		for item in noCompressionImageModel.binaryObject:
			outputStream.write(self.ImageToCArray(item) + '\n')

		self.appendBottomLines(outputStream, False)
		outputStream.close()


# Generate 3rd ROM binary file
	def generateThirdROMBinary(self, thirdROMFile, groupList, paddingSize = 0, isCompressed = False):
		thirdRomGenerator = ThirdRomBinaryGenerator('Image')
		thirdROMEntry = None
		
		# Add 3rd ROM entries here
		for groupObject in groupList:
			thridRomArray = array.array('B')		
			thridRomArray.extend(groupObject.getHeader(isCompressed ))
			thridRomArray.extend(groupObject.getContent(isCompressed ))
			thirdROMEntry = ThirdROMEntry(groupObject.getName(), thridRomArray, paddingSize)
			groupObject.setThirdROMEntry( thirdROMEntry, isCompressed)
			thirdRomGenerator.add(thirdROMEntry)
			
		# udpate offet in each 3rd rom entry
		# and generate the bin files
		thirdRomGenerator.generateBinary(thirdROMFile, paddingSize)

# Generate CustImgGroupRes.c
# - a table to access group by group index
	def generateImageMapSource(self, mapFileName, imageMapModel, compressedImageModel, imageOffestLen):
		outputStream = open(mapFileName,'w')
		self.appendHeaderLines(outputStream, True)
		
		outputStream.write('#include \"CustGameDataHW.h\"\n')
		outputStream.write('#ifdef __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__ \n')
		outputStream.write('#include \"CustImgDataHW.h\"\n')
		outputStream.write('#else  //__MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n')
		outputStream.write('#include \"CustImgGroupSingleData3rdROMHW.h\"\n')
		outputStream.write('#endif // __MMI_RESOURCE_UT_UNCOMPRESSED_IMAGE_SUPPORT__\n')
		self.appendImageMapTable(outputStream, imageMapModel, compressedImageModel, imageOffestLen)	
		self.appendBottomLines(outputStream, True)
		outputStream.close()

# Generate CustImgGroupResThirdROM.c
# - a table to access image integtate image handle and noncompressed image buffer
	def generateGroupMapSource(self, mapFileName, groupList, isCompressed = False):
		groupTotal = len(groupList)
		outputStream = open(mapFileName, 'w')
		self.appendHeaderLines(outputStream, True)
		outputStream.write('#include \"CustResDef.h\"\n')
		outputStream.write('const unsigned short  mtk_CurrMaxGroupsNum = ' + str(groupTotal)+ ';\n\n')
		outputStream.write('\nconst CUSTOM_IMAGE	mtk_nCustGroupNames[]={\n')
		# Group array Output
		for groupIndex in range(0, groupTotal):
			outputStream.write('    (U8*)' + str(groupList[groupIndex].getThirdROMEntry(isCompressed).offset))
			if(groupIndex != groupTotal - 1):
				outputStream.write(',\n')
		outputStream.write('\n};\n')
		
		self.appendBottomLines(outputStream, True)
		outputStream.close()
		return True


class ThirdRomBinaryEntry:
	def __init__(self, name, filePath):
		self.filePath = filePath
		self.name = name
		self.baseAddress = -1
		self.paddingBytes = -1
		self.contentSize = -1
		self.actualSize = -1
	
	def toHeaderString(self):
		resultString = '\n#define MMIRESOUCE_3RD_ROM_' + self.name + '_BASE_ADDR ' + str(self.baseAddress)
		resultString = resultString + '\n#define MMIRESOUCE_3RD_ROM_' + self.name + '_PADDING_SIZE ' + str(self.paddingBytes)
		resultString = resultString + '\n#define MMIRESOUCE_3RD_ROM_' + self.name + '_CONTENT_SIZE ' + str(self.contentSize)
		resultString = resultString + '\n#define MMIRESOUCE_3RD_ROM_' + self.name + '_ACTUAL_SIZE ' + str(self.actualSize)
		return resultString
		
		
class ThirdRomBinaryPackGenerator:
	def __init__(self, name):
		self.name = name
		self.thirdRomEntrys = []
	
	def add(self, entry):
		if(not entry is None):
			self.thirdRomEntrys.append(entry)
		else:
			print('ThirdRomBinaryEntry: add paramter can\'t be None')
	
	def generateBinary(self, binaryFileName, headeFileName, alignBytes=2048):
		thirdROMbinaryContent = array.array('B')
		currentIndex = 0
		# Inint header file writing
		#print(headeFileName)
		outpuStream = open(headeFileName,'w')
		outpuStream.write('#ifndef __CUST_IMG_3RD_ROM_BASE_H__\n')
		outpuStream.write('#define __CUST_IMG_3RD_ROM_BASE_H__\n\n')
		
		for entry in self.thirdRomEntrys:
			# read entry binary content to entryBinContent
			entryBinContent = ByteUtil.readFile(entry.filePath)
			entry.contentSize = len(entryBinContent)
			entry.paddingBytes = alignBytes - ( entry.contentSize % alignBytes )
			if(entry.paddingBytes == alignBytes):
				entry.paddingBytes = 0
			# add padding bytes into entryBinContent
			for n in range(0, entry.paddingBytes):
				entryBinContent.append(0)
			entry.actualSize = len(entryBinContent)
			thirdROMbinaryContent.extend(entryBinContent)
			entry.baseAddress = currentIndex
			# write base and length information to header files
			outpuStream.write(entry.toHeaderString() + '\n')
			currentIndex = len(thirdROMbinaryContent)
						
		ByteUtil.writeFile(thirdROMbinaryContent, binaryFileName)
		outpuStream.write('\n#endif // __CUST_IMG_3RD_ROM_BASE_H__')
		

####################################################
# Report helper
# - Used to create the compression report
####################################################
class ImageReportWrapper:
	def __init__(self, symbol, param=None):
		self.symbol = symbol
		self.param = param
	
	def toReportString(self):
		result = ''
		if(not self.param is None):
			result += self.param.toReportString() + '\t'
		result += self.symbol.symbolName + '\t' + str(self.symbol.getSize())
		return result
		
	
class ReportHelper:
	def checkNoCompressionReason(self,imageParamList, imgSize, sizeLimitation):
		if(imageParamList is None):
			return 0
		
		# if any one set the compression flag to false, it is use setting
		# or it is 'size too large' issue
		userSetting = False
		for item in imageParamList:
			if item.isCompression == 0:
				userSetting = True
		if userSetting is True:
			return 1
		else:
			if( imgSize > sizeLimitation):
				return 2
			else:
				return 3
		
	def generateNoCompressionReport(self,binImageModel, imageParamModel, singleImageLimit):
		noIdImages = []
		userSettingImages = []
		sizeTooLargeImages = []
		handleOutOfUseImages = []
		wastTotalSize = [0,0,0,0]
		
		result = '=======================================================\n'
		result += 'Please Check the No Compresion Images:\n'
		result += '=======================================================\n'
	
		# data collection
		for item in binImageModel.binaryObject:
			if (not item.symbolName.upper() == '________CUSTOMER__IMAGES__EMPTYIMAGE_BMP') and (not item.symbolName.upper() == '________CUSTOMER__IMAGES__DEFAULT_BMP'):
			  # foundParam: All image param mapped to the same image object
				foundParam = imageParamModel.getImageWithSymbol(item.symbolName)
				reason = self.checkNoCompressionReason(foundParam, item.getSize(), singleImageLimit)
				
				# Statistic the waste sizes
				wastTotalSize[reason] = wastTotalSize[reason] + item.getSize()
				
				# No id found
				if(reason == 0):
					noIdImages.append(ImageReportWrapper(item,None))
				# User set no compression flag in res file
				elif (reason == 1):
					for itemParam in foundParam:
						if itemParam.isCompression == 0:
							userSettingImages.append(ImageReportWrapper(item,itemParam))
				# Size is too large
				elif (reason == 2):
					for itemParam in foundParam:
						sizeTooLargeImages.append(ImageReportWrapper(item,itemParam))
				# Handle out of use
				elif (reason == 3):
					for itemParam in foundParam:
						handleOutOfUseImages.append(ImageReportWrapper(item,itemParam))

				
						
		# report output
		result += '** User Setting (' + str(wastTotalSize[1]) + ' bytes ):\n'
		result += 'FILEDS: [idEnumString]\t[idEnumValue]\t[resFilePath]\t[resFilePath]\t[imageFilePath]\t[appId]\t[forceType]\t[symbolName]\t[size]\n'
		for itemParam in userSettingImages:
			result += itemParam.toReportString() + '\n'
	
		result += '\n** Image Size is Too Large (' + str(wastTotalSize[2]) + ' bytes )\n'
		result += 'FILEDS: [idEnumString]\t[idEnumValue]\t[resFilePath]\t[resFilePath]\t[imageFilePath]\t[appId]\t[forceType]\t[symbolName]\t[size]\n'		
		for itemParam in sizeTooLargeImages:
			result += itemParam.toReportString() + '\n'
			
		result += '\n** Image handle space are out of use (' + str(wastTotalSize[3]) + ' bytes )\n'
		result += 'FILEDS: [idEnumString]\t[idEnumValue]\t[resFilePath]\t[resFilePath]\t[imageFilePath]\t[appId]\t[forceType]\t[symbolName]\t[size]\n'		
		for itemParam in handleOutOfUseImages:
			result += itemParam.toReportString() + '\n'
		
		result += '\n** ID not Found: (' + str(wastTotalSize[0]) + ' bytes )\n[Symbol Name]\t[size]\n'
		for item in noIdImages:
			result += itemParam.toReportString() + '\n'
		
		result += '\n** Total : ' + str(wastTotalSize[0]+wastTotalSize[1]+wastTotalSize[2]) + ' bytes'
				
		return result
	



####################################################
# Module Entry
####################################################
# Check if the file is being run as a top-level program file before 
# invoke main method
if __name__ == '__main__':
	rootPath = '..\\..\\..\\'
	result = 0
	compressionAlgo = 'LZMA'
	imageIndexFieldLength = 5
	mode = all 
	multiImgGroupMaxSize = 3 * 1024
	singleImgGroupMaxSize = 3 * 1024
	bootImgGroupMaxSize = 3 * 1024
	bootImgResourceId = None

	if(len(sys.argv)<1):
		usage()
		result = 1
	try:
		#Parse command line parameter
		opts, args = getopt.getopt(sys.argv[1:], 's:a:i:m:', ['mg=','bg=','sg=','bgid='])

		for o, a in opts:
			print (o, a)
			if o == '-s':
				rootPath = a
			if o == '-a':
				compressAlgo = a
			if o == '--mg':
				multiImgGroupMaxSize = int (a)
			if o == '--sg':
				singleImgGroupMaxSize = int (a)
			if o == '--bg':
				bootImgGroupMaxSize = int (a)
			if o == '--bgid':
				bootImgResourceId = a
			if o == '-i':
				imageIndexFieldLength = int (a)
			if o == '-m':
				mode = a
		
		if bootImgResourceId is None:
			bootImgGroupMaxSize = singleImgGroupMaxSize
		
		rootPath = os.path.normpath(rootPath)
		print('Root of SW-Load:\t' + os.path.abspath(rootPath))
		print('Compressor:\t' + compressionAlgo)
		print('Multi-Image Group Size Limit:\t' + str(multiImgGroupMaxSize))
		print('Single-Image Group Size Limit:\t' + str(singleImgGroupMaxSize))
		print('Boot-Image Group Size Limit:\t' + str(bootImgGroupMaxSize))
		
		if not bootImgResourceId is None:
			print('Boot-Image ID:\t' + bootImgResourceId)
		else:
			print('Boot-Image ID:\t' + 'Not Set')
		print('Image Index Field Length:\t' + str(imageIndexFieldLength))
		
		imageResourceLoader = ImageResourceLoader()
		# Load image popluation paramters
		imageParamModel = imageResourceLoader.loadImageOfflineParam()
		# Load image symbols
		allImageModel = imageResourceLoader.loadDefaultMImageModel(imageParamModel)
		reportHelper = ReportHelper()
		
		groupCreator = GroupCreator(allImageModel, imageParamModel, multiImgGroupMaxSize, singleImgGroupMaxSize, bootImgGroupMaxSize, bootImgResourceId, imageIndexFieldLength)
		codeGenerator = MainBinImageCodeGenerator(16)
		thirdROMCodeGenerator = ThirdROMImageCodeGenerator(16)
		lzmaAdapter = LzmaCompressionAdaptor('LZMA',rootPath + '\\tools\\7lzma')
		groupCreator.generateCompressionGroup(lzmaAdapter)
		mapOrderedModel = groupCreator.loadImageMapFromMeta(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgMapMeta.txt', allImageModel.dicRecord)

		# Generate main bin source codes
		codeGenerator.generateSingleImageHeader(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupSingleDataHW.h', groupCreator.getNoCompressImages())
		codeGenerator.generateSingleImageSource(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupSingleDataRes.c', groupCreator.getNoCompressImages())
		codeGenerator.generateGrouopImageHeader(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupDataHW.h', groupCreator.groupObject, True)
		codeGenerator.generateGroupImageSplittedSource(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupDataRes', groupCreator.groupObject, 4)
		codeGenerator.generateGroupMapSource(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupMap.c', groupCreator.groupObject, True)
		codeGenerator.generateImageMapSource(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupRes.c', mapOrderedModel, groupCreator.imageModel, groupCreator.getOffsetLength())

		# Generate 3rd ROM source codes 
		thirdROMCodeGenerator.generateSingleImageHeader(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupSingleData3rdROMHW.h', groupCreator.getNoCompressImages())
		thirdROMCodeGenerator.generateSingleImageSource(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroupSingleData3rdROMRes.c', groupCreator.getNoCompressImages())
		thirdROMCodeGenerator.generateImageMapSource(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroup3rdROMRes.c', mapOrderedModel, groupCreator.imageModel, groupCreator.getOffsetLength())
		# Generate binary file and fill the corrosponding offset into groups in models
		thirdROMCodeGenerator.generateThirdROMBinary(rootPath + '\\plutommi\\Customer\\CustResource\\CustImg3rdROM.bin', groupCreator.groupObject, 0)
		thirdROMCodeGenerator.generateGroupMapSource(rootPath + '\\plutommi\\Customer\\CustResource\\CustImgGroup3rdROMMap.c', groupCreator.groupObject)
		
		# Generate the uncompression image report, classified by reason
		print(reportHelper.generateNoCompressionReport(groupCreator.getNoCompressImages(), imageParamModel, groupCreator.singleImgGroupMaxSize))
		
		
		thirdROMGenerator = ThirdRomBinaryPackGenerator('new 3rd ROM')
		if(not (mode == 'no_str')):
			thirdROMGenerator.add(ThirdRomBinaryEntry('String',rootPath + '\\plutommi\\Customer\\CustResource\\CustStr3rdROM.bin'))
		thirdROMGenerator.add(ThirdRomBinaryEntry('Image',rootPath + '\\plutommi\\Customer\\CustResource\\CustImg3rdROM.bin'))
		thirdROMGenerator.generateBinary(rootPath + '\\plutommi\\Customer\\CustResource\\CustMMI3rdROM', rootPath + '\\plutommi\\Customer\\CustResource\\CustMMI3rdROM.h')
		
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