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

####################################################
# CAT Resource Population Object
####################################################
class CATResource:
	def __init__(self, resourceId, resourceIdString, appId, contentPath, descirption, usage):
		self.resourceId = resourceId
		self.resourceIdString = resourceIdString
		self.descirption = descirption
		self.usage = usage
		self.appId = appId

	def toCATString(self):
		result = str(self.resourceId) + '=' + '\"' + self.resourceIdString + '\",'+ '\"' + self.appId + '\",'+ '\"' + self.descirption + '\",\"' + self.usage + '\"'
		return result

####################################################
# Image Resource Population Object
####################################################
class ImageCATResource(CATResource):
	def __init__(self, resourceId, resourceIdString, appId, contentPath, typeId, descirption, usage, mbaSupport):
	
		self.resourceId = resourceId
		self.resourceIdString = resourceIdString
		self.appId = appId
		self.contentPath = contentPath.upper()
		self.descirption = descirption
		self.usage = usage
		self.typeId = typeId
		self.mbaSupport = mbaSupport
	
	def toCATString(self):
		# since the original description is the path of the res now, we use ID name string as the CAT resoruce description
		result = str(self.resourceId) + '=' + '\"' + self.resourceIdString + '\",'+ '\"' + self.appId + '\",'+ '\"' + self.contentPath + '\",' + str(self.typeId) + ',\"' + self.resourceIdString + '\",\"' + self.usage + '\"'
		return result

####################################################
# Audio Resource Population Object
####################################################
class AudioCATResource(CATResource):
	def __init__(self, resourceId, resourceIdString, appId, contentPath, typeId, descirption, usage, mbaSupport):
		self.resourceId = resourceId
		self.resourceIdString = resourceIdString
		self.appId = appId
		self.contentPath = contentPath.upper()
		self.descirption = descirption
		self.usage = usage
		self.typeId=typeId
		self.mbaSupport = mbaSupport
			
	def toCATString(self):
		# since the original description is the path of the res now, we use ID name string as the CAT resoruce description
		result = str(self.resourceId) + '=' + '\"' + self.resourceIdString + '\",'+ '\"' + self.appId + '\",'+ '\"' + self.contentPath + '\",' + str(self.typeId) + ',\"' + self.resourceIdString + '\",\"' + self.usage + '\"'
		return result

####################################################
# String Resource Population Object
####################################################
class StringCATResource(CATResource):
	def __init__(self, resourceId, resourceIdString, appId, descirption, usage):
		self.resourceId = resourceId
		self.resourceIdString = resourceIdString
		self.descirption = descirption
		self.usage = usage
		self.appId = appId
	
#	def toCATString(self):
#		result = str(self.resourceId) + '=\"' + self.descirption + '\",\"' + self.usage + '\"'

####################################################
# CAT Resource MODEL Object
####################################################
class CATResourceModel:
	def __init__(self,name):
		self.name = name
		self.items = []
		self.itemsMap = {}
		self.allowDuplicated = False
	
	def add(self, catResource):
		if (self.allowDuplicated == False) and (catResource.resourceIdString in self.itemsMap):
			print('[WARN] Duplicated ID is ignored: <' + catResource.resourceIdString + ', ' + str(catResource.resourceId) + '>' )
		else:
			self.itemsMap[catResource.resourceIdString] = catResource
			self.items.append(catResource)

	def show(self):
		for item in self.items:
			print(item.toCATString())

####################################################
# String Resource DAO Object
####################################################
class StringCATResourceDAO:	
	def getCATResources(self, fileName, model):
		print('Load string resource from :' +  os.path.abspath(fileName))
		inputStream = open(fileName,'r')
		for line in inputStream.readlines():
			params = line.split('\t')
			id = int(params[0])
			idString = params[1]
			appId = params[6]
			desc = params[2]
			usage = 'COMMON'
			model.add(StringCATResource(id,idString,appId,desc,usage))
		return model

####################################################
# Image Resource DAO Object
####################################################
class ImageCATResourceDAO:
	
	def normalizePath(self, path):
		#the path should be plutommi
		upperPath = path.upper()
		index = upperPath.find('CUSTOMER\\\\IMAGES\\\\')
		result = upperPath
		if(index>=0):
			result = result[index:]
			result = result.replace('\\\\','\\')
			result = 'plutommi\\' + result
		return result
	

	def getCATResources(self, codebasePath, repoFileName, model):
		fileName = os.path.abspath(codebasePath + '\\' + repoFileName)
		print('Load image resource from :' +  os.path.abspath(fileName))
		inputStream = open(fileName,'r')
		for line in inputStream.readlines():
			params = line.split('\t')
			id = int(params[0])
			idString = params[1]
			appId = params[10]
			desc = params[3]
			contentPath = self.normalizePath(params[7])
			typeId = int(params[6])
			mbaSupport = int(params[5])
			usage = 'COMMON'
			tmpObj = ImageCATResource(id,idString,appId,contentPath,typeId,desc,usage,mbaSupport)
			model.add(tmpObj)
		return model


####################################################
# Audio Resource DAO Object
####################################################
class AudioCATResourceDAO:
	def normalizePath(self, path):
		#the path should be plutommi
		upperPath = path.upper()
		index = upperPath.find('CUSTOMER\\\\AUDIO\\\\')
		result = upperPath
		if(index>=0):
			result = result[index:]
			result = result.replace('\\\\','\\')
			result = 'plutommi\\' + result
		return result
	
	
	def getCATResources(self, codebasePath, repoFileName, model):
		fileName = os.path.abspath(codebasePath + '\\' + repoFileName)
		print('Load audio resource from :' + fileName)
		inputStream = open(fileName,'r')
		for line in inputStream.readlines():
			params = line.split('\t')
			id = int(params[0])
			idString = params[1]
			appId = params[8]
			desc = params[3]
			contentPath = self.normalizePath(params[7])
			typeId = int(params[6])
			mbaSupport = int(params[5])
			usage = 'COMMON'
			tmpObj = AudioCATResource(id,idString, appId, contentPath,typeId,desc,usage,mbaSupport)
			model.add(tmpObj)
		return model
		

####################################################
# Language Mapping Object
####################################################
class LanguageMapping:
	def __init__(self):
		self.item = []

	def addLanguage(self, langStr):
		if(langStr != None):
			self.item.append(langStr)

	def toString(self):
		result = "LANG_MAPPING="
		sizeLimit = len(self.item)
		index = 0
		while(index < sizeLimit):
			item = '\"'+ str(index) + ":" + self.item[index] + '\"'
			if(index == 0):
				result = result + item
			else:
				result = result + ',' + item
			index = index + 1
		return result

####################################################
# Language Mapping Data Access Object
####################################################
class LanguageMappingDAO:

	def getLanguageMapping(self, fileName):
		inputStream = open(fileName)
		rawBytes = inputStream.read()
		decoded = rawBytes.decode('utf16').encode('ascii','ignore')
#	print(decoded.encode('ascii','ignore'))
		lineNum = -1
		langMappingObj = LanguageMapping()
		for line in decoded.splitlines():
		# Skip the first line
			if(lineNum != -1):
				parsedStr = line.split('\t')
				if(len(parsedStr)>2):
					langStr = parsedStr[2]
					langMappingObj.addLanguage(langStr)
		#				print(str(lineNum) + ':' + langStr)
			lineNum = lineNum + 1
		return langMappingObj

####################################################
# CAT String Setting Helper
####################################################
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
		#if self.isCompress==True:
		#	result = result + 'IsCompression=' + '1'+ '\n'
		#else:
		#	result = result + 'IsCompression=' + '0'+ '\n'
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
		
####################################################
# CAT Meta Data Model
####################################################
class CATMetaModel:
	def __init__(self, name):
		self.name = name
		self.audioCATResource = CATResourceModel('Audio')
		self.imageCATResource = CATResourceModel('Image')
		self.stringCATResource = CATResourceModel('String')
		self.catStringSetting = CATStringSetting(False, None)

		self.cacheFolder = 'tools\\CAT\\MMIResource\\cache'
		self.languageMappingObj = None
		self.imageRepoXML = 'plutommi\\Customer\\ResGenerator\\offline_xml_image_repo.txt'
		self.imageRepoPreXML = 'plutommi\\Customer\\ResGenerator\\offline_pre_xml_legacy_image_repo.txt'
		self.imageRepoPostXML = 'plutommi\\Customer\\ResGenerator\\offline_post_xml_legacy_image_repo.txt'
		
		self.stringRepoXML = 'plutommi\\Customer\\ResGenerator\\offline_xml_string_repo.txt'
		self.stringRepoPreXML = 'plutommi\\Customer\\ResGenerator\\offline_pre_xml_legacy_string_repo.txt'
		self.stringRepoPostXML = 'plutommi\\Customer\\ResGenerator\\offline_post_xml_legacy_string_repo.txt'	
		
		self.audioRepoXML = 'plutommi\\Customer\\ResGenerator\\offline_xml_audio_repo.txt'
		self.audioRepoPreXML = 'plutommi\\Customer\\ResGenerator\\offline_pre_xml_legacy_audio_repo.txt'
		self.audioRepoPostXML = 'plutommi\\Customer\\ResGenerator\\offline_post_xml_legacy_audio_repo.txt'	

		self.stringSettingFile = 'plutommi\\Customer\\ResGenerator\\debug\\cat_string_setting.txt'
		self.languageUsageFile = 'plutommi\\Customer\\ResGenerator\\debug\\language_usage.txt'
		self.cachedLanguageUsageFile = self.cacheFolder + '\\language_usage.txt'
		self.cachedStringSettingFile = self.cacheFolder + '\\cat_string_setting.txt'
		
		
	def updateCacheFile(self, cacheFile, hasCachedFile):
		if( os.path.exists(cacheFile)):
			if(os.path.exists(hasCachedFile)):
				os.remove(hasCachedFile)
			shutil.copyfile(cacheFile, hasCachedFile)
	
	def prepareCache(self, rootPath):
		cacheDir = rootPath + '\\' + self.cacheFolder
		cacheFileLang = rootPath + '\\' +  self.languageUsageFile
		cacheFileString = rootPath + '\\' +  self.stringSettingFile
		hasCachedFileLang = rootPath + '\\' + self.cachedLanguageUsageFile
		hasCachedFileString = rootPath + '\\' + self.cachedStringSettingFile
		
		# Create cache folder if it doesn't exist
		if not os.path.exists(cacheDir): 
			os.makedirs(cacheDir)
			
		# Prepare (check and update) String Language Mapping file cache
		self.updateCacheFile(cacheFileLang, hasCachedFileLang)
		self.updateCacheFile(cacheFileString, hasCachedFileString)
			

	def loadCATResource(self, rootPath):
		audioCATResourceDAO	= AudioCATResourceDAO()
		stringCATResourceDAO = StringCATResourceDAO()
		imageCATResourceDAO	= ImageCATResourceDAO()
		languageMappingDAO=LanguageMappingDAO()
		
		self.prepareCache(rootPath)
		
		self.languageMappingObj = languageMappingDAO.getLanguageMapping(rootPath + '\\' +  self.cachedLanguageUsageFile)
		audioCATResourceDAO.getCATResources(rootPath , self.audioRepoXML,self.audioCATResource)
		audioCATResourceDAO.getCATResources(rootPath ,self.audioRepoPreXML,self.audioCATResource)
		audioCATResourceDAO.getCATResources(rootPath ,self.audioRepoPostXML,self.audioCATResource)
	
		imageCATResourceDAO.getCATResources(rootPath , self.imageRepoXML,self.imageCATResource)
		imageCATResourceDAO.getCATResources(rootPath ,self.imageRepoPreXML,self.imageCATResource)
		imageCATResourceDAO.getCATResources(rootPath ,self.imageRepoPostXML,self.imageCATResource)
		
		self.catStringSetting.loadFromFile(rootPath + '\\' + self.cachedStringSettingFile )
		stringCATResourceDAO.getCATResources(rootPath + '\\' + self.stringRepoXML,self.stringCATResource)
		stringCATResourceDAO.getCATResources(rootPath + '\\' + self.stringRepoPreXML,self.stringCATResource)
		stringCATResourceDAO.getCATResources(rootPath + '\\' + self.stringRepoPostXML,self.stringCATResource)
		
	def writeStringCATResourceSection(self, outputStream, lineMappingObj, modelObj, catStringSetting):
		outputStream.write('[' + modelObj.name + ']\n')
		outputStream.write(self.catStringSetting.toString())
		outputStream.write(lineMappingObj.toString() + '\n')
		for item in modelObj.items:
			outputStream.write(item.toCATString() + '\n')
		
	def writeCATResourceSection(self, rootPath, outputStream, modelObj, mbaResourceOnly):
		# Write Section Name
		outputStream.write('[' + modelObj.name + ']\n')
		if(mbaResourceOnly == 1):
			for item in modelObj.items:
				if(item.mbaSupport == 1):
					if ( os.path.exists(rootPath + '\\'+ item.contentPath) and (not item.contentPath.upper().endswith('PBM'))):
						outputStream.write(item.toCATString() + '\n')
					else:
						print('[WARN] Content file '+  rootPath + '\\'+ item.contentPath +  ' not Found, Skip Resource:< ' + item.toCATString() + '>')
		else:
			for item in modelObj.items:
				if( os.path.exists(rootPath + '\\'+ item.contentPath) and (not item.contentPath.upper().endswith('PBM'))):
					outputStream.write(item.toCATString() + '\n')
				else:
					print('[WARN] Content file '+  rootPath + '\\'+ item.contentPath +  ' not Found, Skip Resource:< ' + item.toCATString() + '>')
	
	def toIniFile(self, root, fileName, mbaResourceOnly):
		absFileName = os.path.abspath(fileName)
		print('Start to write: ' + absFileName)
		outputStream = open(fileName,'w')
		outputStream.write('[Setting]\nMtkResGenerator=\"plutommi\\customer\\resgenerator\\mtk_resgenerator.exe\"\n')
		outputStream.write('Convert=\"plutommi\\customer\\resgenerator\\convert.exe\"\n');
		self.writeCATResourceSection(root, outputStream, self.audioCATResource, mbaResourceOnly)
		self.writeCATResourceSection(root, outputStream, self.imageCATResource, mbaResourceOnly)
		self.writeStringCATResourceSection(outputStream, self.languageMappingObj, self.stringCATResource, self.catStringSetting)
		outputStream.write('[ATTACH_FILE]\n')
		outputStream.write('imageRepoXML='+self.imageRepoXML.upper() + '\n')
		outputStream.write('imageRepoPreXML='+self.imageRepoPreXML.upper() +'\n')
		outputStream.write('imageRepoPostXML='+self.imageRepoPostXML.upper() +'\n')
		
		outputStream.write('stringRepoXML='+self.stringRepoXML.upper() + '\n')
		outputStream.write('stringRepoPreXML='+self.stringRepoPreXML.upper() +'\n')
		outputStream.write('stringRepoPostXML='+self.stringRepoPostXML.upper() +'\n')

		outputStream.write('audioRepoXML='+self.audioRepoXML.upper() + '\n')
		outputStream.write('audioRepoPreXML='+self.audioRepoPreXML.upper() +'\n')
		outputStream.write('audioRepoPostXML='+self.audioRepoPostXML.upper() +'\n')
		print('Finish writting: ' + absFileName)

####################################################
# Controller of the parser
####################################################
def main(rootPath, targetIniFile):
	CATModelObj = CATMetaModel(targetIniFile)
	print '------------------Load CAT resource data from Resgen DB------------------'
	CATModelObj.loadCATResource(rootPath)
	print '-------------------------------------------------------------------------'
	print '---------------------Output CAT meta file--------------------------------'
	CATModelObj.toIniFile(rootPath,targetIniFile, 1)
	print '-------------------------------------------------------------------------'

####################################################
# Usgae print
####################################################
def usage():
	print('Usage: catmeta [meta file name] [-s codebase]')

####################################################
# Module Entry
####################################################
# Check if the file is being run as a top-level program file before 
# invoke main method
if __name__ == '__main__':
	rootPath = '.'
	targetIniFile= 'catresmeta.ini'
	result = 0

	if(len(sys.argv)<2):
		usage()
		result = 1
	try:
		#Parse command line parameter
		targetIniFile= sys.argv[1]
		opts, args = getopt.getopt(sys.argv[2:], 's:')
		for o, a in opts:
			if o == '-s':
				rootPath = a
		rootPath = os.path.normpath(rootPath)
		print('Root of SW-Load: ' + os.path.abspath(rootPath))
		main(rootPath, targetIniFile)
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