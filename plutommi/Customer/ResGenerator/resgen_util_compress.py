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


####################################################
# Compression Method Adaptor
####################################################
class CompressionAdaptor:
	def __init__(self, name):
		self.name = name
	def compress(self, dest, src):
		return -1

####################################################
# ZLIB Compression Method Adaptor
####################################################
class ZlibCompressionAdaptor(CompressionAdaptor):
	def __init__(self, name, commandPath = 'plutommi\\customer\\resgenerator\\mtk_resgenerator.exe'):
		self.name = name
		self.commandPath = commandPath
		self.fileExtName = 'zlib'		
	
	# doesn't retuen error code now
	def compress(self, dest, source):
			os.system(self.commandPath + ' -z ' + dest + ' ' + source)
			return 0

####################################################
# LZMA Compression Method Adaptor
####################################################
class LzmaCompressionAdaptor(CompressionAdaptor):
	def __init__(self, name, commandPath = 'tools\\7lzma'):
		self.name = name
		self.commandPath = commandPath
		self.fileExtName = 'lzma'		

	def compress(self,dest,source):
		os.system(self.commandPath  + ' e ' + source + ' ' + dest)
		return 0
	
	def decompress(self,dest,source):
		os.system(self.commandPath  + ' d ' + source + ' ' + dest)
		return 0

####################################################
# Class: ByteUtil
####################################################

class ByteUtil:
	@staticmethod
	def compare(byteArray1, byteArray2):
		return (byteArray1 == byteArray2)
		
	@staticmethod
	def alignByPadding(byteArray, alignBytes):
		if(alignBytes == 0):
			return byteArray
		contentSize = len(byteArray)
		paddingBytes = alignBytes - ( contentSize % alignBytes )
		if(paddingBytes == alignBytes):
			paddingBytes = 0
		# add padding bytes into entryBinContent
		for n in range(0, paddingBytes):
			byteArray.append(0)
		return byteArray
 
	
	@staticmethod
	def writeToOutputStream(outputStream, byteArray, paddingSize = 0):
		totalBytes = len(byteArray)
		outputStream.write('{\n')
		for byteIndex in range(0,totalBytes):
			hexStr = '0x%02X' % (byteArray[byteIndex])
			outputStream.write(hexStr)
			if(byteIndex != (totalBytes -1) or (paddingSize!=0)):
				outputStream.write(', ')
			if(byteIndex % 16 == 15):
				outputStream.write('\n')
		outputStream.write('\n')
		for byteIndex in range(0,paddingSize):
			hexStr = '0x00'
			outputStream.write(hexStr)
			if(byteIndex != (paddingSize -1)):
				outputStream.write(', ')
			if(byteIndex % 16 == 15):
				outputStream.write('\n')
		outputStream.write('\n };')

	@staticmethod
	def int32ToByteArray(intArray):
		output = array.array('B')
		for intObj in intArray:
			byte0 = (intObj & 0x000000FF)
			byte1 = (intObj & 0x0000FF00) >> 8
			byte2 = (intObj & 0x00FF0000) >> 16
			byte3 = (intObj) >> 24
			output.append(byte0)
			output.append(byte1)
			output.append(byte2)
			output.append(byte3)
		return output
	
	@staticmethod
	def int16ToByteArray(intArray):
		output = array.array('B')
		for intObj in intArray:
			byte0 = (intObj & 0x000000FF)
			byte1 = (intObj & 0x0000FF00) >> 8
			output.append(byte0)
			output.append(byte1)
		return output
		
	@staticmethod
	def readFile(fileName):
		print('Read data from ' + fileName)
		rawData = array.array('B')
		original_size = os.path.getsize(fileName)
		inputStream = open(fileName,'rb')
		rawData.fromfile(inputStream, original_size)
		inputStream.close()
		return rawData
		
	@staticmethod
	def writeFile(bytes, fileName):
		outputstreamWriter = open(fileName, 'wb')
		bytes.tofile(outputstreamWriter)
		outputstreamWriter.close()
		
class ThirdROMEntry:
	def __init__(self, name, rawContent, alignBytes=2048, offset = -1, associatedObj = None):
		self.name = name
		self.rawContent = array.array('B')
		print('content lengh:' + str(len(rawContent)))
		self.rawContent.extend(rawContent)
		self.offset = offset
		self.contentSize = len(self.rawContent)
		self.rawContent = ByteUtil.alignByPadding(self.rawContent, alignBytes)
		self.actualSize = len(self.rawContent)
		self.paddingBytes = self.actualSize - self.contentSize
		
	def toDebugString(self):
		result = ''
		result = result + self.name + ': offset = ' + str(self.offset) + '\t size= ' + str(self.actualSize) + '\t padding = ' + str(paddingBytes)
		return result


class ThirdRomBinaryGenerator:
	def __init__(self, name):
		self.name = name
		self.thirdRomEntrys = []
	
	def add(self, entry):
		if(not entry is None):
			self.thirdRomEntrys.append(entry)
		else:
			print('StringThirdRomBinaryGenerator: add paramter can\'t be None')
	
	def generateBinary(self, binaryFileName, alignBytes=2048):
		thirdROMbinaryContent = array.array('B')
		currentIndex = 0
		
		for entry in self.thirdRomEntrys:
			# read entry binary content to entryBinContent
			entryBinContent = entry.rawContent
			thirdROMbinaryContent.extend(entryBinContent)
			entry.offset = currentIndex
			currentIndex = len(thirdROMbinaryContent)						
		ByteUtil.writeFile(thirdROMbinaryContent, binaryFileName)