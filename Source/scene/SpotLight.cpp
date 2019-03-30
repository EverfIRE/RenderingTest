#include "SpotLight.h"

SpotLight::SpotLight(GLenum light) :PointLight(light) 
{
}

void SpotLight::SetDirection(float x, float y, float z)
{
	float direction[] = {x,y,z};
	glLightfv(mLightIdentifier,GL_SPOT_DIRECTION,direction);
}

void SpotLight::SetExponent(float v)
{
	glLightf(mLightIdentifier,GL_SPOT_EXPONENT,v);
}

void SpotLight::SetCutoff(float v)
{
	glLightf(mLightIdentifier,GL_SPOT_CUTOFF,v);
}
