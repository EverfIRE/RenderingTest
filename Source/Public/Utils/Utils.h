#pragma once
#include "GLRenderContext/GLRenderContext.h"

unsigned char* LoadFileContent(const char* path,int & filesize);

unsigned char* DecodeBMP(unsigned char* bmpFileData,int& width,int& height);