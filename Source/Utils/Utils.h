#pragma once
#include "GLRenderContext/GLRenderContext.h"

char* SelectFile(HWND pHwnd);

unsigned char* LoadFileContent(char* path,int & filesize);

unsigned char* DecodeBMP(unsigned char* bmpFileData,int& width,int& height);

GLuint CreateTexture2D(unsigned char* pixelData,int width,int height,GLenum type);

GLuint CreateTextureToBMP();