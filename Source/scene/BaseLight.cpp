#include "BaseLight.h"

BaseLight::BaseLight()
{
	memset(mPosition,0,sizeof(mPosition));
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

void BaseLight::SetPosition(float x, float y, float z)
{
	mPosition[0] = x;
	mPosition[1] = y;
	mPosition[2] = z;
	mPosition[3] = 1.0f;
	glLightfv(mLightIdentifier, GL_POSITION, mPosition);
}

void BaseLight::UpdatePosition(float x, float y, float z)
{
	float pos[] = {mPosition[0]-x,mPosition[1]-y,mPosition[2]-z,1.0f};
	glLightfv(mLightIdentifier,GL_POSITION,pos);
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
