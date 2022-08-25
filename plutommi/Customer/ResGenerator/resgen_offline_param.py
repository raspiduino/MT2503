#########################################################################
# MTK Resource Generation System
# Module:      resgen_offline_param
# Description: Define the domain object, data model and access utility
#              for MTK resource generation system
#########################################################################

import sys
import os
import traceback
import shutil

from resgen_log import ResgenLog


####################################################
# Offline Resource Population Object
####################################################
class ResPopParam:
    def __init__(self, idEnumValue, idEnumString, resFilePath, description, noCompiling):
        self.idEnumValue = idEnumValue
        self.idEnumString = idEnumString 
        self.resFilePath = resFilePath
        self.description = description
        self.noCompiling = noCompiling
        self.appId = 'APP name unknown'
    
    def setAppId(self, appId):
        self.appId = appId

    def toString(self):
        result = str(self.idEnumValue) + '\t' + self.idEnumString + '\t' + self.resFilePath + '\t' + self.description+ '\t' + str(self.noCompiling) + '\t'
        return result

    def getReportTitle(self):
        result = '\Id\tSource-Level Id\tRes File\tDesc.\tNoCompiling\t'
        return result

    def toReportString(self):
        return self.toString()

####################################################
# Binary Resource Population Object
####################################################
class BinaryResParam(ResPopParam):
    def __init__(self, idEnumValue, idEnumString, resFilePath, description, noCompiling, binaryType, binaryFilePath):
        self.idEnumValue = idEnumValue
        self.idEnumString = idEnumString.strip()
        self.resFilePath = resFilePath.strip()
        self.description = description.strip()
        self.noCompiling = noCompiling
        self.binaryType = binaryType
        self.binaryFilePath = binaryFilePath.strip()
        self.appId = 'APP name unknown'

    def toString(self):
        result = str(self.idEnumValue) + '\t' + self.idEnumString + '\t' + self.description + '\t' + self.resFilePath + '\t' + str(self.noCompiling) + '\t' + str(self.binaryType) + '\t' + self.binaryFilePath + '\t' + self.appId + '\t'
        return result
    
    def getReportTitle(self):
        result = 'FILEDS: [Id]\t[Source-Level Id]\t[Res File]\t[Description]\t[Binary-Type]\t[Content path]\t[App Name]\t'
        return result
        
    def toReportString(self):
        result = str(self.idEnumValue) + '\t' + self.idEnumString + '\t' + self.resFilePath + '\t' + self.description + '\t' + str(self.binaryType) + '\t' + self.binaryFilePath + '\t'  + self.appId + '\t'
        return result

####################################################
# Binary Resource Population Object
####################################################
class ImageResParam(ResPopParam):
    def __init__(self, idEnumValue, idEnumString, resFilePath, description, noCompiling, isMultipleBin, forceType, imageFilePath, isENFB, quality, appId, isCompression):
        self.idEnumValue = idEnumValue
        self.idEnumString = idEnumString.strip()
        self.resFilePath = resFilePath.strip()
        self.description = description.strip()
        self.noCompiling = noCompiling
        self.isMultipleBin = isMultipleBin
        self.forceType = forceType
        self.imageFilePath = imageFilePath
        self.isENFB = isENFB
        self.quality = quality
        self.appId = appId
        self.isCompression = isCompression
        self.symbolName = imageFilePath.strip().upper().replace('.','_').replace('/','_').replace('\\','_').replace('-','_')

    def toString(self):
        result = ''
        #  param: 0
        result = result + str(self.idEnumValue) + '\t' 
        #  param: 1
        result = result + self.idEnumString + '\t'
        #  param: 2
        result = result + self.description + '\t'
        #  param: 3
        result = result + self.resFilePath + '\t'
        #  param: 4
        result = result + str(self.noCompiling) + '\t'
        #  param: 5
        result = result + str(self.isMultipleBin) + '\t' 
        #  param: 6
        result = result + str(self.forceType) + '\t'
        #  param: 7
        result = result + self.imageFilePath + '\t'
        #  param: 8
        result = result + str(self.isENFB) + '\t'
        #  param: 9
        result = result + str(self.quality) + '\t'
        #  param: 10
        result = result + self.appId + '\t'
        #  param: 11
        result = result + str(self.isCompression)
        return result
    
    def getReportTitle(self):
        result = 'FILEDS: [idEnumString]\t[idEnumValue]\t[resFilePath]\t[resFilePath]\t[imageFilePath]\t[appId]\t[forceType]\t[symbolName]\t'
        return result
        
    def toReportString(self):
        return self.idEnumString + '\t' + str(self.idEnumValue) + '\t' + self.resFilePath + '\t' + self.imageFilePath + '\t' + self.appId + '\t' + self.symbolName


####################################################
# General Offline Resource MODEL Object
####################################################
class GeneralResParamModel:

    TAG = 'GeneralResParamModel'
    
    DEFAULT_REPO_BINARY_3D_META = 'offline_xml_binary3d_meta_repo.txt'
    DEFAULT_REPO_BINARY_3D_DEV = 'offline_xml_binary3d_dev_repo.txt'
    DEFAULT_REPO_BINARY_XML = 'offline_xml_binary_repo.txt'
    DEFAULT_REPO_BINARY_PREXML_LEGACY = 'offline_pre_xml_legacy_binary_repo.txt'
    DEFAULT_REPO_BINARY_POSTXML_LEGACY = 'offline_post_xml_legacy_binary_repo.txt'
    
    DEFAULT_REPO_IMAGE_XML = 'offline_xml_image_repo.txt'
    DEFAULT_REPO_IMAGE_PREXML_LEGACY = 'offline_pre_xml_legacy_image_repo.txt'
    DEFAULT_REPO_IMAGE_POSTXML_LEGACY = 'offline_post_xml_legacy_image_repo.txt'
    
    
    def __init__(self, name, redundantAllowed):
        self.name = name
        self.redundantAllowed = redundantAllowed
        self.items = []
        
    def add(self, resPopParam):
        self.items.append(resPopParam)

    # dao: ParamTextFileDAO object
    def loadFromRepository(self, repositoryFileName, dao):
        dao.getResources(repositoryFileName,self)

    # dao: BinaryParamTextFileDAO object
    def loadFrom3DMetaFile(self, metaFileName, dao):
        dao.getResourcesFrom3DMetaFile(metaFileName,self)

    # dao: ParamTextFileDAO
    def flush(self, repositoryFileName, dao):
        dao.saveToFile(repositoryFileName, self)
        
    def show(self):
        ResgenLog.v(ResParamModel.TAG,'Offline DB Model: ' + self.name + '==============')
        for item in self.items:
            if(not item is None):
                ResgenLog.v(GeneralResParamModel.TAG,item.toString())
                
        ResgenLog.v(ResParamModel.TAG,'======================================================')


class ImageResParamModel(GeneralResParamModel):
    def __init__(self, name, redundantAllowed):
        self.name = name
        self.redundantAllowed = redundantAllowed
        self.items = []
        self.symbolMap = {}
        
    def add(self, resPopParam):
        # add item to list
        self.items.append(resPopParam)
        # add item to symbol map too
        if not (resPopParam.symbolName in self.symbolMap):
            self.symbolMap[resPopParam.symbolName] = []
        self.symbolMap[resPopParam.symbolName].append(resPopParam)
    
    def getImageWithSymbol(self, symbolName):
        if not (symbolName in self.symbolMap):
            return None
        else:
            return self.symbolMap[symbolName]

####################################################
# Offline Resource MODEL Object
# - for binary 3D resource only, will be replaced by GeneratlResParamModel soon
####################################################
class ResParamModel:

    TAG = 'ResParamModel'
    
    DEFAULT_REPO_BINARY_3D_META = 'offline_xml_binary3d_meta_repo.txt'
    DEFAULT_REPO_BINARY_3D_DEV = 'offline_xml_binary3d_dev_repo.txt'
    DEFAULT_REPO_BINARY_XML = 'offline_xml_binary_repo.txt'
    DEFAULT_REPO_BINARY_PREXML_LEGACY = 'offline_pre_xml_legacy_binary_repo.txt'
    DEFAULT_REPO_BINARY_POSTXML_LEGACY = 'offline_post_xml_legacy_binary_repo.txt'
    
    def __init__(self, name, redundantAllowed):
        self.name = name
        self.redundantAllowed = redundantAllowed
        self.items = []
        
    def add(self, resPopParam):
        self.items.append(resPopParam)

    def loadFromRepository(self, repositoryFileName):
        dao = BinaryParamTextFileDAO(repositoryFileName)
        dao.getResources(repositoryFileName,self)
    
    def loadFrom3DMetaFile(self, metaFileName):
        dao = BinaryParamTextFileDAO(metaFileName)
        dao.getResourcesFrom3DMetaFile(metaFileName,self)

    def flush(self, repositoryFileName):
        dao = BinaryParamTextFileDAO(repositoryFileName)
        dao.saveToFile(repositoryFileName, self)
        
    def show(self):
        ResgenLog.v(ResParamModel.TAG,'Offline DB Model: ' + self.name + '==============')
        for item in self.items:
            if(not item is None):
                ResgenLog.v(ResParamModel.TAG,item.toString())
                
        ResgenLog.v(ResParamModel.TAG,'======================================================')


####################################################
# Offline Resgen Report Creator
####################################################
class ResReportHelper:

    REPORT_FAILED_BINARY = 'debug/failed_3d_resource.txt'
    REPORT_USAGE_BINARY = 'debug/binary_resource_usage.txt'
    REPORT_DUPLICATED_BINARY = 'debug/binary_repeat_id_list.txt'   
    
    def createUsageReport(self, fileName, resModel):
        self.createReport(fileName, resModel,'THIS REPORT SHOWS THE USAGE OF THE GENERATED RESOURCES')
    
    def createFailedReport(self, fileName, resModel):
        self.createReport(fileName, resModel,'PLEASE CHECK THE FOLLOWING FAILED RESOURCES DECLARATION IN YOUR APPLICATION')
    
    def createDuplicatedReport(self, fileName, resModel):
        self.createReport(fileName, resModel,'THE FOLLOWING DUPLICATED RESOURCE IS NOT PROCESSED TO THIS BUILD')

    def createReport(self,fileName, resModel, comment=''):
        if( (not resModel is None) and (not fileName is None) ):
            outstream = file(fileName,'w')
            count = 0
            if(len(comment) != 0):
                outstream.write('# ' + comment + '\n')
            
            for entry in resModel.items:
                if(not entry is None):
                    if(count == 0):
                        outstream.write('# ' + entry.getReportTitle() + '\n')
                    outstream.write(entry.toReportString() + '\n')
                    count = count + 1 
            outstream.close()
        
####################################################
# Binary Resource DAO Object
####################################################
class ImageParamTextFileDAO:
    TAG = 'ImageParamTextFileDAO'
    

    def saveToFile(self, fileName, model):
        ResgenLog.v(ImageParamTextFileDAO.TAG, 'Save Model: ' + model.name + ' to ' + fileName)
        outputStream =  open(fileName,'w')
        for item in model.items:
             outputStream.write(item.toString() + "\n")
        outputStream.close()

    def getResources(self, fileName, model):
        ResgenLog.v(ImageParamTextFileDAO.TAG, 'Load '+ model.name + ' from ' + fileName)
        if not os.path.exists(fileName):
            ResgenLog.w(ImageParamTextFileDAO.TAG,'getResources: File open failed' + fileName)
            return
        inputStream = open(fileName,'r')
        for line in inputStream.readlines():
            try:
                params = line.split('\t')
                totalParam = len(params)
                # optional field
                quality = 1
                appId = 'N/A'
                isCompression = '1'
                
                if(totalParam >=8):
                    idEnumValue = int(params[0])
                    idEnumString = params[1]
                    description = params[2]
                    resFilePath = params[3]
                    noCompiling = int(params[4])
                    isMultipleBin = int(params[5])
                    forceType = int(params[6])
                    imageFilePath = params[7]
                    isENFB = int(params[8])
                    
                    if(totalParam >= 9):
                        quality = int(params[9])
                    if(totalParam >= 10):
                        appId = params[10]
                    if(totalParam >= 11):
                        isCompression = int(params[11])
                
                    temp = ImageResParam(idEnumValue,idEnumString,resFilePath,description,noCompiling,isMultipleBin,forceType,imageFilePath,isENFB,quality,appId,isCompression)
                    model.add(temp)
            except:
                ResgenLog.e(ImageParamTextFileDAO.TAG, 'exception when parsing entry: <'+ line +'>')
                print '\n', '-'*20, "python exception start", '-'*20
                traceback.print_exc(file=sys.stdout)
                print '-'*20, "python exception  end ", '-'*20
        inputStream.close()
        return model

####################################################
# Binary Resource DAO Object
####################################################
class BinaryParamTextFileDAO:
    TAG = 'BinaryParamTextFileDAO'
    
    def __init__(self, fileName):
        self.fileName = fileName

    def saveToFile(self, fileName, model):
        ResgenLog.v(BinaryParamTextFileDAO.TAG, 'Save Model: ' + model.name + ' to ' + fileName)
        outputStream =  open(fileName,'w')
        for item in model.items:
             outputStream.write(item.toString() + "\n")
        outputStream.close()

    def getResourcesFrom3DMetaFile(self, fileName, model):
        ResgenLog.v(BinaryParamTextFileDAO.TAG, 'Load '+ model.name + ' from ' + fileName)
        
        if not os.path.exists(fileName):
            ResgenLog.w(BinaryParamTextFileDAO.TAG,'getResourcesFrom3DMetaFile: File open failed: ' + fileName)
            return
            
        inputStream = open(fileName,'r')
        
        for line in inputStream.readlines():
            params = line.split()
            if (not params is None) and (len(params)>=4) :
                idEnumValue = int(params[0])
                idEnumString = params[2]
                resFilePath = params[3]
                description = 'Generated by OfflineResgenUtility.py'
                noCompiling = 1
                binaryType = 0
                binaryFilePath = params[1]
                temp = BinaryResParam(idEnumValue,idEnumString,resFilePath,description,noCompiling,binaryType,binaryFilePath)
                model.add(temp)     

    def getResources(self, fileName, model):
        ResgenLog.v(BinaryParamTextFileDAO.TAG, 'Load '+ model.name + ' from ' + fileName)
        if not os.path.exists(fileName):
            ResgenLog.w(BinaryParamTextFileDAO.TAG,'getResourcesFrom3DMetaFile: File open failed' + fileName)
            return
        inputStream = open(fileName,'r')
        for line in inputStream.readlines():
            try:
                params = line.split('\t')
                if(len(params)>=7):
                    idEnumValue = int(params[0])
                    idEnumString = params[1]
                    description = params[2]
                    resFilePath = params[3]
                    noCompiling = int(params[4])
                    binaryType = int(params[5])
                    binaryFilePath = params[6]
                    temp = BinaryResParam(idEnumValue,idEnumString,resFilePath,description,noCompiling,binaryType,binaryFilePath)
                    # Set APP Name if the filed exists
                    if(len(params)>=8):
                        temp.setAppId(params[7])
                    model.add(temp)
            except:
                ResgenLog.e(BinaryParamTextFileDAO.TAG, 'exception when parsing entry: <'+ line +'>')
                print '\n', '-'*20, "python exception start", '-'*20
                traceback.print_exc(file=sys.stdout)
                print '-'*20, "python exception  end ", '-'*20
        inputStream.close()
        return model

####################################################
# Main Function (Unit Test Only)
####################################################
def main(rootPath):
    ResParamModelObj = ResParamModel('ResParamModel Unit Test Model', 0)
    print '------------------Load Offline resource data from Resgen DB------------------'
    ResParamModelObj.loadFromRepository(ResParamModel.DEFAULT_REPO_BINARY_XML)
    ResParamModelObj.show()
    ResParamModelObj.add(BinaryResParam(1, 'test_id', 'resFilePath', 'description', 1, 0, 'binaryFilePath'))
    print '-------------------------------------------------------------------------'
    ResParamModelObj.loadFrom3DMetaFile('mmi_rp_binary3d_populate_with_meta.txt');
    print '---------------------Output Offline Resource file--------------------------------'
    ResParamModelObj.flush('offline_xml_binary_repo_2.txt')
    reportHelper = ResReportHelper()
    reportHelper.createUsageReport('usage_test.log', ResParamModelObj)
    reportHelper.createFailedReport('fail_test.log', ResParamModelObj)
    
    print '-------------------------------------------------------------------------'
    
####################################################
# Module Entry (Unit Test Only)
####################################################
# Check if the file is being run as a top-level program file before 
# invoke main method
if __name__ == '__main__':
    old_path = os.getcwd()
    try:
        os.chdir(os.path.dirname(os.path.abspath(sys.argv[0])))
        #Parse command line parameter
        if(len(sys.argv)>1):
            rootPath = sys.argv[1]
        else:
            rootPath = '.'
        main(rootPath)
    except:
        print '\n', '-'*20, "python exception start", '-'*20
        traceback.print_exc(file=sys.stdout)
        print '-'*20, "python exception  end ", '-'*20
        raise
    finally:
        os.chdir(old_path)
####################################################