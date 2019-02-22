#include "Texture.h"
#include "Utils/Utils.h"

Texture::Texture(char*TexPath)
{
	Init(TexPath);
}

Texture::~Texture()
{

}

void Texture::Init(char * TexPath)
{
	ImageType _imageType;
	int _fileSize;
	unsigned char* fileData = LoadFileContent(TexPath,_fileSize);
	switch (_imageType)
	{
		case ImageType::BMP:
			DecodeBMP(fileData);
			break;
		case ImageType::JPG:
			break;
		case ImageType::PNG:
			break;
		case ImageType::TGA:
			break;
		default:
			break;
	}
}

unsigned char * Texture::DecodeBMP(unsigned char * bmpFileData)
{
	if (0x4d42 == *((unsigned short*)bmpFileData))
	{
		int pixelDataOffset = *((int*)(bmpFileData + 10));
		qImageSize->Width = *((int*)(bmpFileData + 18));
		qImageSize->Height = *((int*)(bmpFileData + 22));
		unsigned char* pixelData = bmpFileData + pixelDataOffset;
		for (int i = 0; i < qImageSize->Width * qImageSize->Height * 3; i += 3)
		{
			unsigned char temp = pixelData[i];
			pixelData[i] = pixelData[i + 2];
			pixelData[i + 2] = temp;
		}
		return pixelData;
	}
	return nullptr;
}