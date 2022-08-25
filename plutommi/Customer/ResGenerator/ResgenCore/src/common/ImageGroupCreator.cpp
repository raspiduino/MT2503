#include "stdafx.h"
#include "ImageGroupCreator.h"

/*
Reference: 
class ImageSymbol{
private:
string sourceFile;
char * data;
int size;
int * noCompression;
public:
ImageSymbol(char * sourceFile, char* data, int noCompression);
void toMetaString(string *buffer);
string& getSourceFile();
char* getData();
int getSize();
int getNoCompression();
void setNoCompression(int noCompression);
};
*/
string & ImageSymbol::getSourceFile(){
	return this->sourceFile;
}

int ImageSymbol::getSize(){
	return this->size;
}

int ImageSymbol::getNoCompression(){
	return this->noCompression;
}

void ImageSymbol::setNoCompression(int noCompression){
	this->noCompression = noCompression;
}

ImageSymbol::ImageSymbol(const char * sourceFile, char* data, int size,int noCompression){
	this->sourceFile = sourceFile;
	this->data = data;
	this->size = size;
	this->noCompression = noCompression;
}

// META section format:
// ########################################################
// FILE: [FILE NAME]
// NO_COMPRESSION: [Y/N]
// DATA: 
void ImageSymbol::toMetaString(string *buffer){
	if(this->size <= 0 && buffer !=NULL){
		*buffer = "";
		return;
	}

	stringstream oss;
	oss<<"########################################################"<<endl;
	oss<<"FILE:\t"<<this->sourceFile<<endl;
	oss<<"NO_COMPRESSION:\t";
	if(this->noCompression > 0){
		oss<<"Y"<<endl;
	}else{
		oss<<"N"<<endl;
	}
	oss<<"DATA:"<<endl;
	// ensure the string has the end pattern
	char * safeData = new char[this->size+1];
	memcpy(safeData, data, size);
	safeData[size] = '\0';

	oss<<safeData<<endl;
	if(buffer !=NULL){
		*buffer = oss.str();
	}
	delete [] safeData;
	return;
}

/*
class ImageGroupContentMetaCreator{
private:
map<string,ImageSymbol *> symbolMap;
vector<ImageSymbol*> orderedSymbolList;
public:
// Release and Clear images added to the creator
int reset();
// Added a image data
int addImage(char * sourceFile, char* data, int noCompression);
// Create the meta file for the image symbols
int generateMetaFile(char * fileName);
};
*/

ImageGroupContentMetaCreator::ImageGroupContentMetaCreator(){
	// Do nothing now
}

int ImageGroupContentMetaCreator::addImage(const char * sourceFile, char* data, int size, int noCompression){
	if(sourceFile == NULL || data == NULL || size <=0){
		return 0;
	}
	//check if the symbol already added
	if(this->symbolMap[sourceFile] == NULL){
		this->symbolMap[sourceFile]  = new ImageSymbol(sourceFile,data,size,noCompression);
		orderedSymbolList.push_back(this->symbolMap[sourceFile]);
	}else{
		if(noCompression == 1){
			this->symbolMap[sourceFile]->setNoCompression(1);
		}
	}
	return 1;
}

ImageGroupContentMetaCreator::~ImageGroupContentMetaCreator(){
	this->reset();
}

int ImageGroupContentMetaCreator::reset(){
	for(unsigned int i=0;i<orderedSymbolList.size();i++){
		if(orderedSymbolList[i]!=NULL){
			delete orderedSymbolList[i];
			orderedSymbolList[i] = NULL;
		}
	}
	orderedSymbolList.clear();
	symbolMap.clear();
	return 1;
}

int ImageGroupContentMetaCreator::generateMetaFile(const char * fileName){
	unsigned int i = 0;

	if( fileName ==NULL){
		return 0;
	}

	ofstream outfile;
	outfile.open(fileName);
	string tmp("");

	for(i=0;i<orderedSymbolList.size();i++){
		if(orderedSymbolList[i]!=NULL){
			orderedSymbolList[i]->toMetaString(&tmp);
			outfile<<tmp<<'\n';
		}

	}
	outfile.close();
	return 1;
}

/*
class ImageGroupMappingMetaCreator{
private:
    vector<string*> orderedSymbolList;
public:
	int reset();
	int addImage(const char * symbolName);
	int generateMetaFile(const char * fileName);
	ImageGroupMappingMetaCreator();
	~ImageGroupMappingMetaCreator();
};
*/
ImageGroupMappingMetaCreator::ImageGroupMappingMetaCreator(){
	//Do nothing now
}

int ImageGroupMappingMetaCreator::addImage(const char * image){
	string * str = new string(image);
	orderedSymbolList.push_back(str);
	return 1;
}

int ImageGroupMappingMetaCreator::reset(){
	for(unsigned int i=0;i<orderedSymbolList.size();i++){
		if(orderedSymbolList[i]!=NULL){
			delete orderedSymbolList[i];
			orderedSymbolList[i] = NULL;
		}
	}
	orderedSymbolList.clear();
	return 1;
}

int ImageGroupMappingMetaCreator::generateMetaFile(const char * fileName){
		unsigned int i = 0;

	if( fileName ==NULL){
		return 0;
	}

	ofstream outfile;
	outfile.open(fileName);
	string tmp("");

	for(i=0;i<orderedSymbolList.size();i++){
		if(orderedSymbolList[i]!=NULL){
			outfile<<*(orderedSymbolList[i])<<'\n';
		}

	}
	outfile.close();
	return 1;
}
ImageGroupMappingMetaCreator::~ImageGroupMappingMetaCreator(){
	this->reset();
}