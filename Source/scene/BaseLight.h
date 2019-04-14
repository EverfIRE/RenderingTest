#pragma once
#include "GLRenderContext/GLRenderContext.h"

class BaseLight
{
protected:
	BaseLight();
	GLenum mLightIdentifier;
	float mPosition[3];
public:
	void SetAmbientColor(float r,float g,float b,float a);
	void SetDiffuseColor(float r,float g,float b,float a);
	void SetSpecularColor(float r,float g,float b,float a);
	void SetPosition(float x,float y,float z);
	void UpdatePosition(float x,float y,float z);
	void Enable(bool isEnable);
private:

};