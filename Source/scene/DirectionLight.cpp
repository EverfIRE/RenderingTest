#include "DirectionLight.h"

DirectionLight::DirectionLight(GLenum light)
{
	mLightIdentifier = light;
}

void DirectionLight::SetPosition(float x, float y, float z)
{
	float pos[] = {x,y,z,0.0f};
	glLightfv(mLightIdentifier,GL_POSITION,pos);
}
