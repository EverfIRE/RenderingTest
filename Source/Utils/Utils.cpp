﻿#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Utils.h"

char szBuffer[MAX_PATH] = { 0 };

char* SelectFile(HWND pHwnd)
{
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
		MessageBox(NULL, TEXT("获取失败"), "提示", MB_ICONERROR);
		return NULL;
	}
	else
	{
		MessageBox(NULL, szBuffer, "提示", NULL);
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

	//Sampling mode setting when the picture is big and small and the picture is small
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//Sampling mode when UV exceeds 0-1 space
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Pass texture data to GPU, 1: texture type 2: mipmap level 3: texture data on GPU format 4: pixel width 
							  //5: pixel height 6: border(0) 7: texture data in memory format 8: pixel data Type of medium component 9:PixelData
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

GLuint CreateDefaultBMP(const char* vaule)
{
	int nFileSize = 0;
	unsigned char* filecontent = nullptr;
	FILE* pFile = fopen(vaule, "rb");

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
			nFileSize = nLen;
		}
		fclose(pFile);
	}
	unsigned char* bmpFileContent = filecontent;
	if (bmpFileContent == nullptr)
	{
		return 0;
	}
	int bmpWidth = 0, bmpHeight = 0;
	unsigned char*pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
	if (bmpWidth == 0)
	{
		delete bmpFileContent;
		return 0;
	}
	GLuint 	texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
	delete bmpFileContent;
	return texture;
}

GLuint CreateDisplayList(std::function<void()> foo)
{
	GLuint displayList=glGenLists(1);
	glNewList(displayList,GL_COMPILE);
	foo();
	glEndList();
	return displayList;
}

