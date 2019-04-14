#pragma once
#include "BaseLight.h"

class PointLight : public BaseLight
{
public:
	PointLight(GLenum light);
	void SetConstAttenuation(float v);
	void SetLinearAttenuation(float v);
	void SetQuadricAttenuation(float v);
};