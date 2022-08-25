import sys
import os
import StringIO
import traceback
import time
import struct
import re
import shutil
import difflib
import csv
import getopt
import subprocess
import threading
from Queue import Queue
from threading import Thread
from datetime import datetime

####################################################
# Class WorkerThread
# - worker thead of a thread pool
####################################################
class WorkerThread(Thread):
	def __init__(self, tasks, name):
		Thread.__init__(self)
		self.tasks = tasks
		self.daemon = True
		self.name = name
		self.start()
    
	def run(self):
		while True:
			threadObj = self.tasks.get()
			try:
				threadObj.run()
			except Exception, e: print e
			self.tasks.task_done()

####################################################
# Class ThreadPool
# - Prepare a pool of threads to limit the thread creation
#   cost in the system
####################################################
class ThreadPool:
	def __init__(self, numOfThreads):
		self.tasks = Queue(numOfThreads)
		for item in range(numOfThreads):
			WorkerThread(self.tasks, item)

	def add(self, threadObj):
		self.tasks.put(threadObj)

	def waitForCompletion(self):
		self.tasks.join()

####################################################
# Class ImageContentFile
# - Image File Object, represents a single image file
#   object; a image file object may be associated to 
#   different image resource (one-to-many)
####################################################
class ImageContentFile:
	def __init__(self, filePath, colorNum = -1, size = 0):
		self.filePath = filePath.upper()
		self.colorNum = colorNum
		self.size = size

	def toString(self):
		return self.filePath + '\t' + str(self.colorNum) + '\t' + str(self.size)

####################################################
# Class ImageContentFileDAO
# - Handle the data access logic of ImageContentFile
#   object on external system/ storage
####################################################
class ImageContentFileDAO:

	def loadFromResourceModel(self, resModel, allowNoColor = False):
		colorMap = {}
		for item in resModel.items:
			if(allowNoColor == False and item.colorNum < 0 ):
				continue
			else:
				colorMap[item.contentPath] = ImageContentFile(item.contentPath, item.colorNum, item.size)
		return colorMap

	def loadColorMaps(self, filePath, allowNoColor = True):
		colorMap = {}
		if( os.path.exists(filePath) == False):
			print('file not found!!' + filePath)
			return {}
		intputStream = open(filePath, 'r')
		for lineItem in intputStream.readlines():
			buffer = lineItem.strip()
			items = buffer.split('\t')
			if(len(items) >=3 ):
				colorNum = int(items[1])
				contentPath = items[0].upper()
				imageSize = int(items[2])
				if(allowNoColor == False and colorNum < 0 ):
					continue
				else:
					colorMap[contentPath] = ImageContentFile(contentPath, colorNum, imageSize)
					
		intputStream.close()
		print('Load color map file: ' + filePath + ' success')
		return colorMap
	
	def saveColorMap(self, colorMap, filePath):
		outputStream = open(filePath, 'w')
		for keyItem in colorMap.keys():
			outputStream.write(colorMap[keyItem].toString() + '\n')
		outputStream.close()


####################################################
# Class MAUIResource
# - Abstract class for create a Resource class
#   in the system
####################################################
class MAUIResource:
	def __init__(self, resourceId, resourceIdString, appId, contentPath, descirption, usage):
		self.resourceId = resourceId
		self.resourceIdString = resourceIdString
		self.descirption = descirption
		self.usage = usage
		self.appId = appId

	def toString(self):
		result = str(self.resourceId) + '=' + '\"' + self.resourceIdString + '\",'+ '\"' + self.appId + '\",'+ '\"' + self.descirption + '\",\"' + self.usage + '\"'
		return result


####################################################
# Class ConvertedImageResource
# - Converted Imgae Resource Object: the image which 
#   has been converted to another type of format
####################################################
class ConvertedImageResource(MAUIResource):
	def __init__(self, resourceId, resourceIdString, appId, resBase, contentPath, size, resFile, converted='N'):
		self.resourceId = resourceId
		self.resourceIdString = resourceIdString
		self.appId = appId
		self.contentPath = contentPath.upper()
		self.resFile = resFile
		self.resBase = resBase
		self.size = size

		self.colorNum = -1
		self.populatedParam = None
		self.converted = converted

				
	def toString(self):
	  # APP_name	Res_base	ID	ID_name	size	data	res_filename
		result = self.appId + '\t' + self.resBase + '\t' + str(self.resourceId) + '\t' + self.resourceIdString + '\t' + str(self.size) + '\t' + self.contentPath + '\t' + self.resFile + '\t'+ str(self.colorNum) + '\t' + self.converted
		return result

####################################################
# Converted Image Resource DAO Object
####################################################
class ConvertedImageCATResourceDAO:
	def getResource(self, repoFileName, model):
		fileName = os.path.abspath(repoFileName)
		print('Load converted image resource from :' +  os.path.abspath(fileName))
		inputStream = open(fileName,'r')
		heaeLine = True
		for lineItem in inputStream.readlines():
			if(heaeLine == True):
				heaeLine = False
				continue
			param = lineItem.split('\t')
			if(len(param) >=7 ):
				appId = param[0].strip()
				resBase = param[1].strip()
				resourceId = int(param[2].strip())
				resourceIdString = param[3].strip()
				size = int(param[4].strip())
				contentPath = param[5].strip().upper()
				resFile = param[6].strip()
				tmpObj = ConvertedImageResource(resourceId, resourceIdString, appId, resBase, contentPath, size, resFile)
				if(not contentPath.upper().endswith('TTF')):
					model.add(tmpObj)
		inputStream.close()
		return model 


####################################################
# Class OfflineImageResource
# - Image Resource before resgen
####################################################
class OfflineImageResource(MAUIResource):
	def __init__(self, resourceId, resourceIdString, appId, contentPath, typeId, descirption, usage, mbaSupport, resFile):
		self.resourceId = resourceId
		self.resourceIdString = resourceIdString
		self.appId = appId
		self.contentPath = contentPath.upper()
		self.descirption = descirption
		self.usage = usage
		self.typeId = typeId
		self.mbaSupport = mbaSupport
		self.colorNum = -1
		self.finalContentPath = self.contentPath
		self.resFile = resFile
		
	def toString(self):
		result = str(self.resourceId) + '=' + '\"' + self.resourceIdString + '\",'+ '\"' + self.appId + '\",'+ '\"' + self.contentPath + '\",' + str(self.typeId) + ',\"' + self.resourceIdString + '\",\"' + self.usage + '\"'
		return result

####################################################
# Class: OfflineImageResourceDAO
# - Image Resource DAO Object
####################################################
class OfflineImageResourceDAO:
	def getResource(self, repoFileName, model):
		fileName = os.path.abspath(repoFileName)
		print('Load image resource from :' +  os.path.abspath(fileName))
		inputStream = open(fileName,'r')
		for line in inputStream.readlines():
			params = line.split('\t')
			if(len(params)>=10):
				id = int(params[0].strip())
				idString = params[1].strip()
				appId = params[10].strip()
				desc = params[2].strip()
				resFile = params[3].strip()
				contentPath = params[7].strip()
				typeId = int(params[6].strip())
				mbaSupport = int(params[5].strip())
				usage = 'COMMON'
				tmpObj = OfflineImageResource(id,idString,appId,contentPath,typeId,desc,usage,mbaSupport, resFile)
				model.add(tmpObj)
		return model
		
####################################################
# class: MAUIResourceModel
# - MAUI Resource MODEL Object
####################################################
class MAUIResourceModel:
	def __init__(self,name):
		self.name = name
		self.items = []
		self.itemsMap = {}
		self.allowDuplicated = False
	
	def get(self, id):
		if(id in self.itemsMap):
			return self.itemsMap[id]
		else:
			return None
	
	def add(self, mauiResoruce):
		if (self.allowDuplicated == False) and (mauiResoruce.resourceId in self.itemsMap):
			print('[WARN] Duplicated ID is ignored: <' + mauiResoruce.resourceIdString + ', ' + str(mauiResoruce.resourceId) + '>' )
		else:
			self.itemsMap[mauiResoruce.resourceId] = mauiResoruce
			self.items.append(mauiResoruce)

	def show(self):
		for item in self.items:
			print(item.toString())

####################################################
# Class: PathUtility
# - To operate the path strings on Resgen system
####################################################
class PathUtility:
	@staticmethod
	def normalizePath(path):
		#the path should be plutommi
		upperPath = path.upper()
		index = upperPath.find('CUSTOMER\\\\IMAGES\\\\')
		result = upperPath
		if(index>=0):
			result = result[index:]
			result = result.replace('\\\\','\\')
			result = 'plutommi\\' + result
		return result



####################################################
# Class ColorNumberCountRunnable
# - Runnable objet to count the color number
#   of a image content file object
####################################################

class ColorNumberCountRunnable(threading.Thread):
	def __init__(self, rootPath, cacheFolder, imageObj):
		threading.Thread.__init__(self) 
		self.imageObj = imageObj
		self.rootPath = rootPath
		self.cacheFolder = cacheFolder
		
	def run(self):
		self.imageObj.colorNum = self.getColorNumber()
		
	def getColorNumber(self):
		file = self.imageObj.contentPath
		rootPath = self.rootPath
		fileName = self.rootPath + '\\' + PathUtility.normalizePath(file)
		convertPath = self.rootPath + '\\plutommi\\customer\\resgenerator\\convert.exe'
		logFile = self.cacheFolder + '\\' + str(self.imageObj.resourceId) + '.txt'
		rawBMPFile =  self.cacheFolder + '\\' + str(self.imageObj.resourceId) + '.bmp'
		#os.system(convertPath + ' -identify '+ fileName + ' ' + rawBMPFile + '  > ' + logFile)
		inputStream = open(logFile,'r')
		
		for line in inputStream.readlines():
			buffer = line.strip()
			if(buffer.startswith('Colors: ')):
				params = line.split(':')
#				print('Found color Line!!-->' + buffer)
#				print(params)
				if(len(params) >= 2):
					inputStream.close()
					return int(params[1].strip())
		inputStream.close()
		return -1

####################################################
# Class ImageInfoGenerator
# - Create image information report
####################################################
		
class ImageInfoGenerator:
	def __init__(self, rootPath):
		self.colorMap = {}
		self.convertedColorMap = {}

		self.rootPath = rootPath
		
		self.imageCATResource = MAUIResourceModel('Image Params')
		self.convertedImageResource = MAUIResourceModel('Image Usage Log')
		
		self.cacheFolder = 'AutoAnalysis'
		self.imageAllConvertedObjects = self.cacheFolder  + '\\image_info_all_converted.txt'
		
		self.imageRepoXML = rootPath + '\\' + 'plutommi\\Customer\\ResGenerator\\offline_xml_image_repo.txt'
		self.imageRepoPreXML = rootPath + '\\' + 'plutommi\\Customer\\ResGenerator\\offline_pre_xml_legacy_image_repo.txt'
		self.imageRepoPostXML = rootPath + '\\' + 'plutommi\\Customer\\ResGenerator\\offline_post_xml_legacy_image_repo.txt'
		self.imageUsageLog = rootPath + '\\' + 'plutommi\\Customer\\ResGenerator\\debug\\image_resource_usage.txt'
		self.imageUpdatedConvertedObjects = rootPath + '\\' + 'plutommi\\Customer\\ResGenerator\\debug\\image_info_updated_all.txt'
		self.imageKeepOriginalObjects = rootPath + '\\' + 'plutommi\\Customer\\ResGenerator\\debug\\image_info_updated_no_converted.txt'
		self.imageUsageLogExt = rootPath + '\\' + 'plutommi\\Customer\\ResGenerator\\debug\\image_resource_usage_ext.txt'
		
	
	def prepareCache(self):
		cacheDir = self.cacheFolder
		
		# Create cache folder if it doesn't exist
		if not os.path.exists(cacheDir): 
			os.makedirs(cacheDir)
			
		# os.remove(hasCachedFile)
		# shutil.copyfile(cacheFile, hasCachedFile)
			
  # Parse image usage log file and creat the model objects
	def loadImageUsageResource(self):
		imageCATResourceDAO	= OfflineImageResourceDAO()
		convertedImageCATResourceDAO = ConvertedImageCATResourceDAO()
		self.prepareCache()

		imageCATResourceDAO.getResource(self.imageRepoXML,self.imageCATResource)
		imageCATResourceDAO.getResource(self.imageRepoPreXML,self.imageCATResource)
		imageCATResourceDAO.getResource(self.imageRepoPostXML,self.imageCATResource)
		convertedImageCATResourceDAO.getResource(self.imageUsageLog, self.convertedImageResource)
		
	def updateColorMap(self):
		self.prepareCache()
		imageContentDAO = ImageContentFileDAO()
		#load updated ABM colors
		updatedMap = imageContentDAO.loadColorMaps( self.imageUpdatedConvertedObjects, False)
		colorMap = imageContentDAO.loadColorMaps( self.imageAllConvertedObjects, True)
		
		if(not updatedMap is None):
			for keyItem in updatedMap.keys():
				colorMap[keyItem] = updatedMap[keyItem]
			imageContentDAO.saveColorMap( colorMap, self.imageAllConvertedObjects)
		else:
			print('updatedMap is none, didn\'t update the converted color map')
		return colorMap
		
	
	
	def createImageUsageLogExt(self):
	# 1. Load color map file
	# 2. Scan and collect objects whose size is unknown
		filePath = self.imageAllConvertedObjects
		self.convertedColorMap = self.updateColorMap()
		if(self.convertedColorMap is None):
			print('Error!!, convertedColorMap is None')
			self.convertedColorMap = {}		

		updateModel = MAUIResourceModel('Color Unknown Objects')
		
		for imageObj in self.convertedImageResource.items:
			# Update Res File Path
			if(imageObj.resourceId in self.imageCATResource.itemsMap):
				imageObj.resFile = self.imageCATResource.itemsMap[imageObj.resourceId].resFile

			# print(self.convertedColorMap)
			# Update Color Number
			if( imageObj.contentPath in self.convertedColorMap):
				imageObj.colorNum = self.convertedColorMap[imageObj.contentPath].colorNum
				imageObj.size = self.convertedColorMap[imageObj.contentPath].size
				
				# print('[INFO]update color info -->' + imageObj.contentPath)
				imageObj.converted = 'Y'
			# else:
				#	print('[INFO] No color info in MAP file -->' + imageObj.contentPath)
			if(imageObj.colorNum == -1):
				#	print('Add to original image info pool!!')
				imageObj.converted = 'N'
				updateModel.add(imageObj)
		self.createOriginalColorMap(updateModel,self.imageKeepOriginalObjects)
		
	# 3. Write the ext image usage log file
		logFilePath = self.imageUsageLogExt
		outputStream = open(logFilePath, 'w')
		outputStream.write('APP_name' +'\t'	+ 'Res_base'+'\t'	+ 'ID'+'\t'	+ 'ID_name'+'\t'	+ 'size'+'\t'	+ 'data'+'\t'	+ 'res_filename' + '\t' + 'color_num' + '\t' + 'ABMAB2_converted\n')
		
		for imageObj in self.convertedImageResource.items:
			outputStream.write(imageObj.toString() + '\n')
		outputStream.close()
	
	def createOriginalColorMap(self, modelObj, colorMapFile):
		timeStr = datetime.now()
		print(timeStr)
		colorImageJobMap = {}
		allThreadStarted = []
		pool = ThreadPool(32)
		print('Start original file color number counting')
		for item in modelObj.items:
			normalizedContentPath = self.rootPath + '\\' + PathUtility.normalizePath(item.contentPath)
			if item.contentPath in colorImageJobMap:
				# The color number retrieving job has been start, skip it
				# item.colorNum = colorImageJobMap[item.contentPath].colorNum
				print('Skip!! -->' + item.contentPath)
			else:
				if( os.path.exists(normalizedContentPath) and (not os.path.isdir(normalizedContentPath) == True) and ((item.contentPath.upper().endswith('PNG')) or (item.contentPath.upper().endswith('JPG')) or (item.contentPath.upper().endswith('BMP')) or (item.contentPath.upper().endswith('GIF')))):
					colorImageJobMap[item.contentPath] = item
					threadObj = ColorNumberCountRunnable(self.rootPath,self.cacheFolder, item)
					pool.add(threadObj)
				else:
					print('[WARN] Content file '+  normalizedContentPath +  ' not Found, Skip color number counting')
		pool.waitForCompletion()
		
# Write to colorMapFile
		imageContentDAO = ImageContentFileDAO()
		print('Write to ' + colorMapFile + ': ' + str(len(modelObj.items)))
		colorMap = imageContentDAO.loadFromResourceModel(modelObj)
		imageContentDAO.saveColorMap(colorMap, colorMapFile)
		timeStr = datetime.now()
		print(timeStr)
	
	 
#		absFileName = os.path.abspath(fileName)
#		print('Start to write: ' + absFileName)


####################################################
# Controller of the parser
####################################################
def main(rootPath):
	imageInfoGenerator = ImageInfoGenerator(rootPath)
	print '----------------- Load MAUI resource data from Resgen DB-----------------'
	imageInfoGenerator.loadImageUsageResource()
	print '----------------- Generate Image Analysis Report ------------------------'
	imageInfoGenerator.createImageUsageLogExt()
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
	rootPath = '..\..\..'
	result = 0

	if(len(sys.argv)<1):
		usage()
		result = 1
	try:
		#Parse command line parameter
		opts, args = getopt.getopt(sys.argv[1:], 's:')
		for o, a in opts:
			if o == '-s':
				rootPath = a
		rootPath = os.path.normpath(rootPath)
		print('Root of SW-Load: ' + os.path.abspath(rootPath))
		main(rootPath)
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