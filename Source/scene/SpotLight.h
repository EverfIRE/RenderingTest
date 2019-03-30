#pragma once
#include "PointLight.h"

class SpotLight:public PointLight
{
public:
	SpotLight(GLenum light);
	void SetDirection(float x,float y,float z);
	void SetExponent(float v);
	void SetCutoff(float v);
};