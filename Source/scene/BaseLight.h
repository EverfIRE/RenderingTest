#pragma once
#include "GLRenderContext/GLRenderContext.h"

class BaseLight
{
protected:
	GLenum mLightIdentifier;
	BaseLight();
public:
	void SetAmbientColor(float r,float g,float b,float a);
	void SetDiffuseColor(float r,float g,float b,float a);
	void SetSpecularColor(float r,float g,float b,float a);
	void Enable(bool isEnable);
private:

};