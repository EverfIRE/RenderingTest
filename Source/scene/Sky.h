#pragma once
#include "Object.h"

class Sky:public Object
{
private:
	GLuint skyTexture[6];
	GLuint fastDrawCall;
public:

	void Init(const char*imageDir,bool _enableDraw);
	void DrawCommand();
	void Draw();
};

