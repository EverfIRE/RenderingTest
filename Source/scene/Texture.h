#include "Utils/Struct.h"

class Texture
{
public:
	Texture(char*ObjPath);
	~Texture();

//private variable
private:
	enum ImageType
	{
		BMP = 1,
		JPG = 2,
		PNG = 3,
		TGA = 4,
	};
	QImageSize* qImageSize;

//Private Function
private:
	void Init(char*ObjPath);
	unsigned char* DecodeBMP(unsigned char * bmpFileData);

//get some private variable
public:
	QImageSize* GetImageSize() { return qImageSize; };
};
