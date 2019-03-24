#pragma once
#include "GLRenderContext/GLRenderContext.h"

class Object
{
public:
	Object();
	~Object();

	void EnableLight(bool _enableLight);

	bool enableDraw;
};

