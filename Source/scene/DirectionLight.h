#pragma once
#include "BaseLight.h"

class DirectionLight:public BaseLight
{
public:
	DirectionLight(GLenum light);
	void SetPosition(float x,float y,float z);
};