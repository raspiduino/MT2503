#ifndef __IMAGE_GROUP_CREATOR_H__
#define __IMAGE_GROUP_CREATOR_H__


#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>
#include <map>
#include <vector>
using namespace std;

class ImageSymbol{
private:
	string sourceFile;
	char * data;
	int size;
	int noCompression;
public:
	ImageSymbol(const char * sourceFile, char* data,int size, int noCompression);
	void toMetaString(string *buffer);
	string& getSourceFile();
	char* getData();
	int getSize();
	int getNoCompression();
	void setNoCompression(int noCompression);
};

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

class ImageGroupContentMetaCreator{
private:
    map<string,ImageSymbol *> symbolMap;
    vector<ImageSymbol*> orderedSymbolList;
public:
	// Release and Clear images added to the creator
	int reset();
	// Added a image data
	int addImage(const char * sourceFile, char* data, int size, int noCompression);
	// Create the meta file for the image symbols
	int generateMetaFile(const char * fileName);
	ImageGroupContentMetaCreator();
	~ImageGroupContentMetaCreator();
};


#endif __IMAGE_GROUP_CREATOR_H__
