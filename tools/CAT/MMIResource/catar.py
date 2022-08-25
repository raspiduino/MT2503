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
import zipfile
import getopt

from catmeta import CATMetaModel

####################################################
# CAT Diff Item
####################################################
class CATDiffItem:
	def __init__(self, resourceId, timeStamp):
		self.resourceId = resourceId
		self.timeStamp = timeStamp
	
	def toMetaString(self):
		result = resourceId + '\t' + timeStamp
		return result

####################################################
# Image Diff Item
####################################################
class ImageDiffItem(CATDiffItem):
	def __init__(self, resourceId, contentPath, timeStamp):
		self.resourceId = resourceId
		self.timeStamp = timeStamp
		self.contentPath = contentPath
	
	def toMetaString(self):
		result = self.resourceId + '\t' + self.contentPath + '\t' + self.timeStamp
		return result

####################################################
# Audio Diff Item
####################################################
class AudioDiffItem(CATDiffItem):
	def __init__(self, resourceId, contentPath, timeStamp):
		self.resourceId = resourceId
		self.timeStamp = timeStamp
		self.contentPath = contentPath
	
	def toMetaString(self):
		result = self.resourceId + '\t' + self.contentPath + '\t' + self.timeStamp
		return result


####################################################
# CAT Diff MODEL Object
####################################################
class CATDiffModel:
	def __init__(self,name):
		self.name = name
		self.items = []
	def getName(self):
		return self.name
		
	def add(self, cadDiffItem):
		self.items.append(cadDiffItem)

	def show(self):
		for item in self.items:
			print(item.toMetaString())

####################################################
# CAT Diff Archive Meta File DAO
####################################################
class ImageDiffMetaDAO:
	DEFAULT_DIFF_FILE_NAME = "image_diff.txt"
	def writeToFile(self, fileName, model):
		print('Write image resource diff from :' + fileName)
		outputStream = open(fileName,'w')
		for item in model.items:
			outputStream.write(item.toMetaString()+'\n');
		outputStream.close()
		
	def getDiffItems(self, fileName, model):
		print('Load image resource diff from :' + fileName)
		inputStream = open(fileName,'r')
		for line in inputStream.readlines():
			params = line.split('\t')
			id = params[0]
			contentPath = params[1]
			timeStamp = params[2]
			temp = ImageDiffItem(id,contentPath,timeStamp)
			model.add(temp)
		return model

####################################################
# CAT Diff Archive Meta File DAO
####################################################
class AudioDiffMetaDAO:
	DEFAULT_DIFF_FILE_NAME = "audio_diff.txt"
	def writeToFile(self, fileName,model):
		print('Write audio resource diff from :' + fileName)
		outputStream = open(fileName,'w')
		for item in model.items:
			outputStream.write(item.toMetaString()+'\n');
		outputStream.close()
		
	
	def getDiffItems(self, fileName, model):
		print('Load audio resource diff from :' + fileName)
		inputStream = open(fileName,'r')
		for line in inputStream.readlines():
			params = line.split('\t')
			id = params[0]
			contentPath = params[1]
			timeStamp = params[2]
			temp = ImageDiffItem(id,contentPath,timeStamp)
			model.add(temp)
		return model


####################################################
# CAT Diff Archive Main Meta File DAO
####################################################
class CATArchiveMeta:
	def __init__(self):
		self.stringPatchFile = ''
		self.imagePatchFile = ''
		self.audioPatchFile = ''
		self.codebaseVersion = ''
		
	def setStringPatchFile(self, fileName):
		self.stringPatchFile = fileName
		
	def setImagePatchFile(self, fileName):
		self.imagePatchFile = fileName
		
	def setAudioPatchFile(self, fileName):
		self.audioPatchFile = fileName
		
	def setCodeBaseVersion(self, version):
		return  self.codebaseVersion
		
	def getStringPatchFile(self):
		return  self.stringPatchFile
		
	def getImagePatchFile(self):
		return  self.imagePatchFile
		
	def getAudioPatchFile(self):
		return  self.audioPatchFile
		
	def getCodeBaseVersion(self):
		return self.codebaseVersion
	
	def parserMetaFile(self, name, value):
		#AUDIO_PATCH: audio_diff.csv
		#CODEBASE_VERSION: 0.00
		#IMAGE_PATCH: image_diff.csv
		#STRING_PATCH: string_diff.csv
		if(name.strip().startswith('IMAGE_PATCH') == True):
			self.setImagePatchFile(value.strip() )
		if(name.strip().startswith('AUDIO_PATCH') == True):
			self.setAudioPatchFile(value.strip())
		if(name.strip().startswith('STRING_PATCH') == True):
			self.setStringPatchFile(value.strip())
		if(name.strip().startswith('CODEBASE_VERSION') == True):
			self.setCodeBaseVersion(value.strip())
			
	def readFromFile(self, fileName):
		inputStream = open(fileName, 'r')
		for line in inputStream.readlines():
			sepIndex = line.find(':')
			if(sepIndex > 1):
				name = line[:(sepIndex)]
				value = line[(sepIndex+1):]
#				print('name ' + name + ', value ' + value + ', index ' + str(sepIndex))
				self.parserMetaFile(name,value)


####################################################
# CAT Diff Archive controller
####################################################
class CATDiffArchive:

	def checkAndCreateDir(self, destPath):
		destPath = destPath.replace('\\','/')
		dir = os.path.dirname(destPath) 
		if not os.path.exists(dir):     
			os.makedirs(dir)
			
# For python 2.5
	def extract_from_zip_2(self, name, destPath, zip_file):
		destPath = destPath.replace('\\','/')
		dir = os.path.dirname(destPath) 
		if not os.path.exists(dir):     
			os.makedirs(dir) 
		print('open '+ destPath)
		dest_file = open(destPath, 'wb')
		print('read '+ name)
		dest_file.write(zip_file.read(name))
		print('write '+ name)
		
		dest_file.close()


	def extract_from_zip(self, name, zip_file):
		destPath = ".\\" + name
		destPath = destPath.replace('\\','/')
		dir = os.path.dirname(destPath) 
		if not os.path.exists(dir):     
			os.makedirs(dir) 

		dest_file = open(name, 'wb')
		dest_file.write(zip_file.read(name))
		dest_file.close()

	def getMetaContentPath(self, contentPath):
		resultPath = contentPath
		index = resultPath.find(':\\')
		if( index != -1):
			resultPath = resultPath[index+2:]
		resultPath = resultPath.replace('\\','/')
		
		return resultPath
		

	def createArchieve(self,zipfileName, imageModel, audioModel):
		# 	import zipfile

		audioDao = AudioDiffMetaDAO()
		imageDao = ImageDiffMetaDAO()
		self.checkAndCreateDir(zipfileName)
		f = zipfile.ZipFile(zipfileName, 'w')
		for item in imageModel.items:
			print('[DEBUG] write '+ item.contentPath)
			updatedPath = self.getMetaContentPath(item.contentPath)
			f.write(item.contentPath, 'source/image/' + updatedPath)
#		Corrrect the path
			item.contentPath = updatedPath
			print('[DEBUG]Image Path in meta: ' + updatedPath)

		for item in audioModel.items:
			print('[DEBUG] write '+ item.contentPath)
			updatedPath = self.getMetaContentPath(item.contentPath)
			f.write(item.contentPath, 'source/audio/' + updatedPath)
			item.contentPath = updatedPath
			print('[DEBUG] Audio Path in meta: ' + updatedPath)

		audioDao.writeToFile(audioModel.getName(), audioModel)
		imageDao.writeToFile(imageModel.getName(), imageModel)

		f.write(imageModel.getName(), 'meta/' + ImageDiffMetaDAO.DEFAULT_DIFF_FILE_NAME)
		f.write(audioModel.getName(), 'meta/' + AudioDiffMetaDAO.DEFAULT_DIFF_FILE_NAME)
		
		f.close
	
	def readArchieve(self, zipFileName, imageModel, audioModel):
		f = zipfile.ZipFile(zipFileName, 'r')
		namelist = f.namelist()
		for name in namelist:
			print(name)
#		f.extract('meta/' + AudioDiffMetaDAO.DEFAULT_DIFF_FILE_NAME)
#		f.extract('meta/' + ImageDiffMetaDAO.DEFAULT_DIFF_FILE_NAME)
		self.extract_from_zip_2('meta/' + ImageDiffMetaDAO.DEFAULT_DIFF_FILE_NAME,'output/temp/decompressed/meta/'+ImageDiffMetaDAO.DEFAULT_DIFF_FILE_NAME,f )
		self.extract_from_zip_2('meta/' + AudioDiffMetaDAO.DEFAULT_DIFF_FILE_NAME,'output/temp/decompressed/meta/'+AudioDiffMetaDAO.DEFAULT_DIFF_FILE_NAME,f )
		audioDao = AudioDiffMetaDAO()
		audioDao.getDiffItems('output/temp/decompressed/meta/' + AudioDiffMetaDAO.DEFAULT_DIFF_FILE_NAME, audioModel)
		imageDao = ImageDiffMetaDAO()
		imageDao.getDiffItems('output/temp/decompressed/meta/' + ImageDiffMetaDAO.DEFAULT_DIFF_FILE_NAME, imageModel)
		return f
	
	def findResourceById(self, id, model):
		for item in model.items:
			print('compare:' + item.resourceIdString  + ',' + id)
			if(item.resourceIdString == id):
				return item
		return None
		
	def createPatch(self, destDir, zipFileName, loadPath):
		#Load offline DB 

		catMetaResource = CATMetaModel('catresdiff.ini')
		catMetaResource.loadCATResource(loadPath + '\\mcu')

		audioCATResource = catMetaResource.audioCATResource
		imageCATResource = catMetaResource.imageCATResource

		
		imageDiffModel = CATDiffModel('image diff')
		audioDiffModel = CATDiffModel('audio diff')
		
		#catMetaResource.toIniFile('CatResMeta.ini', 1)
		
		f = self.readArchieve(zipFileName, imageDiffModel ,audioDiffModel)
		for item in imageDiffModel.items:
			print('Handle Image: ' + item.resourceId)
			temp = self.findResourceById(item.resourceId, imageCATResource)			
			if(temp is None):
				print(item.resourceId + ' not found in this SW-Load: ' + loadPath)
			else:
				print(temp.resourceIdString + ': ' + temp.contentPath)
#				f.extract('source/image/' + item.contentPath,'./source_temp')
				self.extract_from_zip_2('source/image/' +item.contentPath,'output/temp/decompressed/source/image/' + item.contentPath, f)
				print('finished extract ' + './source_temp/' +item.contentPath)
				destPath = destDir+'\\' +temp.contentPath
				destPath = destPath.replace('\\','/')
				dir = os.path.dirname(destPath) 
				if not os.path.exists(dir):     
					os.makedirs(dir) 
				shutil.copy('output/temp/decompressed/source/image/' + item.contentPath,  destPath)
		
		for item in audioDiffModel.items:
			print('Handle Audio: ' + item.resourceId)
			temp = self.findResourceById(item.resourceId, audioCATResource)			
			if(temp is None):
				print(item.resourceId + ' not found in this SW-Load: ' + loadPath)
			else:
#				f.extract('source/audio/' +item.contentPath,'.\\source_temp')
				self.extract_from_zip_2('source/audio/' +item.contentPath,'output/temp/decompressed/source/audio/' + item.contentPath, f)
				print('finished extract ' + './source_temp/' +item.contentPath)
				destPath = destDir+'\\' +temp.contentPath
				destPath = destPath.replace('\\','/')
				dir = os.path.dirname(destPath) 
				if not os.path.exists(dir):     
					os.makedirs(dir) 
				shutil.copy('output/temp/decompressed/source/audio/' + item.contentPath, destPath)
				print(temp.resourceIdString + ': ' + temp.contentPath)
		f.close()

####################################################
# Unit Test
####################################################
def unitTest():
	imageModel = CATDiffModel('image diff')
	audioModel = CATDiffModel('audio diff')
	imageDiff = ImageDiffItem('IMG_ID_PHNSET_ON_ANIMATION_DEFAULT','testimage/EM_APD.gif', time.strftime('[%H:%M:%S]', time.localtime()))
	imageModel.add(imageDiff)
	imageDiff = ImageDiffItem('IMG_ID_PHNSET_OFF_ANIMATION_DEFAULT','testimage/EM_SYC/0.png', time.strftime('[%H:%M:%S]', time.localtime()))
	imageModel.add(imageDiff)
	audioDiff = AudioDiffItem('AUD_ID_PROF_RING5', 'testaudio/Aclassical04.mid', time.strftime('[%H:%M:%S]', time.localtime()))
	audioModel.add(audioDiff)
	
	ar = CATDiffArchive()
	ar.createArchieve('diff.zip',imageModel, audioModel)
	ar.createPatch('.\\patch','diff.zip','F:\\home\\mtk03859\\Codebase\\11B\\CAD\\LION52_V2_6432_GPRS.W12.12_CAT2')
	
####################################################
# Controller of the parser
####################################################
def main(rootPath):
	CATModelObj = CATMetaModel('catresmeta.ini')
	print '------------------Load CAT resource data from Resgen DB------------------'
	CATModelObj.loadCATResource(rootPath)
	print '-------------------------------------------------------------------------'
	print '---------------------Output CAT meta file--------------------------------'
	CATModelObj.toIniFile('CatResMeta.ini', 1)
	print '-------------------------------------------------------------------------'

def usage():
	print('catar [package|patch] [-m metafile] [-d dest folder] [-s MAUI codebase root]')
####################################################
# Module Entry
####################################################
# Check if the file is being run as a top-level program file before 
# invoke main method
if __name__ == '__main__':
	packageMode = 0
	patchMode = 1
	archiveName = 'catdiff.car'
	output = None
	verbose = False
	metaFilePath = None
	destPath = None
	sourcePath = None

	try:
		#Parse command line parameter
		if(len(sys.argv) < 2):
			usage()
			sys.exit()
		archiveName = sys.argv[1]
		
		try:
			opts, args = getopt.getopt(sys.argv[2:], "m:s:d:cp")
		except getopt.GetoptError, err:
			# print help information and exit:
			usage()
			sys.exit(1)
			
		for o, a in opts:
			if o == "-m":
				metaFilePath = a
			elif o == '-d':
				destPath = a
			elif o == '-s':
				sourcePath = a
			elif o == '-c':
				mode = packageMode
			elif o == '-p':
				mode = patchMode
#		print("m: " + metaFilePath + " d: " + destPath +" s: " + sourcePath)
		
#		unitTest()
		if mode == packageMode:
#		create archive:	
#		1. load files need to be archieved:
			catMeta = CATArchiveMeta()
			catMeta.readFromFile(metaFilePath)
			print("readFromFile: "+ metaFilePath)
			audioDao = AudioDiffMetaDAO()
			audioModel = CATDiffModel(catMeta.getAudioPatchFile())
			audioDao.getDiffItems(catMeta.getAudioPatchFile(),audioModel)
			imageDao = ImageDiffMetaDAO()
			imageModel = CATDiffModel(catMeta.getImagePatchFile())
			imageDao.getDiffItems(catMeta.getImagePatchFile(),imageModel)
			print("CATDiffArchive: "+ archiveName)
			ar = CATDiffArchive()
			ar.createArchieve(archiveName,imageModel, audioModel)
		if mode == patchMode:
			ar = CATDiffArchive()
			ar.createPatch(destPath, archiveName, sourcePath)

	except:
		print '\n', '-'*20, "python exception start", '-'*20
		traceback.print_exc(file=sys.stdout)
		print '-'*20, "python exception  end ", '-'*20
#		raise
		sys.exit(1)
####################################################