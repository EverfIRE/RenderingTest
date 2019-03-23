#include "BaseLight.h"

BaseLight::BaseLight()
{
}

void BaseLight::SetAmbientColor(float r, float g, float b, float a)
{
	float ambientColor[] = {r,g,b,a};
	glLightfv(mLightIdentifier,GL_AMBIENT,ambientColor);
}

void BaseLight::SetDiffuseColor(float r, float g, float b, float a)
{
	float difusseColor[] = {r,g,b,a};
	glLightfv(mLightIdentifier, GL_DIFFUSE, difusseColor);
}

void BaseLight::SetSpecularColor(float r, float g, float b, float a)
{
	float specularColor[] = {r,g,b,a};
	glLightfv(mLightIdentifier,GL_SPECULAR,specularColor);
}

void BaseLight::Enable(bool isEnable)
{
	if (isEnable)
	{
		glEnable(GL_LIGHTING);
		glEnable(mLightIdentifier);
	}
	else
	{
		glDisable(GL_LIGHTING);
		glDisable(mLightIdentifier);
	}

}
