#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Utils/Utils.h"

char* SelectFile(HWND pHwnd)
{
	char szFilePath[1024] = { 0 };   // ��ѡ����ļ����յ�·��
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = pHwnd;
	ofn.lpstrFilter = "bmp�ļ�(*.bmp)\0";//Ҫѡ����ļ���׺   
	ofn.lpstrInitialDir = "./";//Ĭ�ϵ��ļ�·��   
	ofn.lpstrFile = szFilePath;//����ļ��Ļ�����   
	ofn.nMaxFile = sizeof(szFilePath) / sizeof(*szFilePath);
	ofn.nFilterIndex = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER; //��־����Ƕ�ѡҪ����OFN_ALLOWMULTISELECT 
	if (!GetOpenFileName(&ofn))
	{
		return szFilePath;
	}
	if (strcmp(szFilePath, "") == 0)
	{
		// �����Ƿ��ȡ�ɹ�
		return szFilePath;
	}
}

unsigned char * LoadFileContent(const char * path, int & filesize)
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

	//ͼƬ����С��ͼƬС����ı����ʱ�����ģʽ����
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//��UV����0-1�ռ�ʱ�Ĳ���ģʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//�����������ݵ�GPU, 1����������  2:mipmap���� 3:����������GPU�ϵĸ�ʽ 4:���ؿ� 5:���ظ� 6:border��0�� 7:�����������ڴ��ϵĸ�ʽ 8:���������з��������� 9:
	glTexImage2D(GL_TEXTURE_2D,0,type,width,height,0,type,GL_UNSIGNED_BYTE,pixelData);
	glBindTexture(GL_TEXTURE_2D, 0);

	return texture;
}

GLuint CreateTextureToBMP(const char * bmpPath)
{
	int nFileSize = 0;
	unsigned char* bmpFileContent = LoadFileContent(bmpPath, nFileSize);
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