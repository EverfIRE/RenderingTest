#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Utils/Utils.h"
using namespace std;

char* SelectFile(HWND pHwnd)
{
	char szBuffer[MAX_PATH] = {0};
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = ("bmp文件(*.bmp)\0*.bmp\0所有文件(*.*)\0*.*\0");//要选择的文件后缀   
	ofn.lpstrInitialDir = ("D:\\Program Files");//默认的文件路径   
	ofn.lpstrFile = szBuffer;//存放文件的缓冲区   
	ofn.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//标志如果是多选要加上OFN_ALLOWMULTISELECT  
	if (!GetOpenFileName(&ofn))
	{
		MessageBox(NULL, TEXT("获取失败"), NULL, MB_ICONERROR);
		return NULL;
	}
	else
	{
		MessageBox(NULL, szBuffer, NULL, MB_ICONMASK);
		return szBuffer;
	}
}

unsigned char* LoadFileContent(char* path, int & filesize)
{
	unsigned char* filecontent = nullptr;
	filesize = 0;
	FILE* pFile = fopen(path, "rb");

	if (pFile)
	{
		fseek(pFile, 0, SEEK_END);
		int nLen = ftell(pFile);
		if (nLen > 0)
		{
			rewind(pFile);
			filecontent = new unsigned char[nLen + 1];
			fread(filecontent, sizeof(unsigned char), nLen, pFile);
			filecontent[nLen] = '\0';
			filesize = nLen;
		}
		fclose(pFile);
	}
	return filecontent;
}

unsigned char * DecodeBMP(unsigned char * bmpFileData, int & width, int & height)
{
	if (0x4d42 == *((unsigned short*)bmpFileData))
	{
		int pixelDataOffset = *((int*)(bmpFileData + 10));
		width = *((int*)(bmpFileData + 18));
		height = *((int*)(bmpFileData + 22));
		unsigned char* pixelData = bmpFileData + pixelDataOffset;
		for (int i=0;i<width*height*3;i+=3)
		{
			unsigned char temp = pixelData[i];
			pixelData[i] = pixelData[i + 2];
			pixelData[i + 2] = temp;
		}
		return pixelData;
	}
	return nullptr;
}

GLuint CreateTexture2D(unsigned char * pixelData, int width, int height, GLenum type)
{
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D,texture);

	//图片大贴小和图片小贴大的表面的时候采样模式设置
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//当UV超出0-1空间时的采样模式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//传递纹理数据到GPU, 1：纹理类型  2:mipmap级别 3:纹理数据在GPU上的格式 4:像素宽 5:像素高 6:border（0） 7:纹理数据在内存上的格式 8:像素数据中分量的类型 9:
	glTexImage2D(GL_TEXTURE_2D,0,type,width,height,0,type,GL_UNSIGNED_BYTE,pixelData);
	glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}

GLuint CreateTextureToBMP()
{
	int nFileSize = 0;
	unsigned char* bmpFileContent = LoadFileContent(SelectFile(NULL), nFileSize);
	if (bmpFileContent==nullptr)
	{
		return 0;
	}
	int bmpWidth = 0, bmpHeight = 0;
	unsigned char*pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
	if (bmpWidth==0)
	{
		delete bmpFileContent;
		return 0;
	}
	GLuint 	texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
	delete bmpFileContent;
	return texture;
}