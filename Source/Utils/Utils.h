#pragma once
#include "GLRenderContext.h"

char* SelectFile(HWND pHwnd);

unsigned char* LoadFileContent(char* path,int & filesize);

unsigned char* DecodeBMP(unsigned char* bmpFileData,int& width,int& height);

GLuint CreateTexture2D(unsigned char* pixelData,int width,int height,GLenum type);

GLuint CreateTextureToBMP();

GLuint CreateDefaultBMP(const char* vaule);

GLuint CreateDisplayList(std::function<void()>foo);

float GetFrameTime();