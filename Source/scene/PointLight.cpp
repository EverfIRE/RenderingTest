#include "PointLight.h"

PointLight::PointLight(GLenum light)
{
	mLightIdentifier = light;
}

void PointLight::SetConstAttenuation(float v)
{
	glLightf(mLightIdentifier,GL_CONSTANT_ATTENUATION,v);
}

void PointLight::SetLinearAttenuation(float v)
{
	glLightf(mLightIdentifier,GL_LINEAR_ATTENUATION,v);
}

void PointLight::SetQuadricAttenuation(float v)
{
	glLightf(mLightIdentifier,GL_QUADRATIC_ATTENUATION,v);
}
