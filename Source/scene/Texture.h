#include <Utils/Struct.h>
#include <Utils/Enum.h>
#include "Utils/Utils.h"

class Texture
{
public:
	Texture(char*ObjPath);
	~Texture();

//private variable
private:
	QImageSize* qImageSize;

//Private Function
private:
	void Init(char*ObjPath);
	unsigned char* DecodeBMP(unsigned char * bmpFileData);
	ImageType GetImageType();
//get some private variable
public:
	QImageSize* GetImageSize() { return qImageSize; };
};
