#include "Model.h"
#include "Utils/Utils.h"

Model::Model(char* ObjPath)
{
	Init(ObjPath);
}

Model::~Model()
{
}

void Model::Init(char* ObjPath)
{
	ModelType _modelType;
	int _fileSize;
	unsigned char* _fileData= LoadFileContent(ObjPath,_fileSize);

	switch (_modelType)
	{
		case ModelType::THREEDS:
			break;
		case ModelType::OBJ:
			DecodeObj(_fileData);
			break;
		case ModelType::FBX:
			break;
		case ModelType::DEFAULT:
			break;
		default:
			break;
	}
}

unsigned char* Model::DecodeObj(unsigned char * bmpFileData)
{
	return nullptr;
}
