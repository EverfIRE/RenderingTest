#include "GLRenderContext/GLRenderContext.h"
#include "Sky.h"
#include "Utils/Utils.h"

Sky::Sky()
{
}


Sky::~Sky()
{
}

void Sky::Init(const char * imageDir)
{
	skyTexture[0] = CreateTextureToBMP();
	skyTexture[1] = CreateTextureToBMP();
	skyTexture[2] = CreateTextureToBMP();
	skyTexture[3] = CreateTextureToBMP();
	skyTexture[4] = CreateTextureToBMP();
	skyTexture[5] = CreateTextureToBMP();
}

void Sky::BoxSky()
{
	//front
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D,skyTexture[0]);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f,1.0f); glColor4ub(255,255,255,255); glVertex3f(-0.5f,2.5f,-0.5f);
	glTexCoord2d(1.0f,1.0f); glColor4ub(255,255,255,255); glVertex3f(0.5,2.5f,-0.5f);
	glTexCoord2d(1.0f,0.0f); glColor4ub(255,255,255,255); glVertex3f(0.5f,1.5f,-0.5f);
	glEnd();
	//Top
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, skyTexture[1]);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, 0.5f);
	glEnd();
	//back
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D,skyTexture[2]);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, 0.5f);
	glEnd();
	//down
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, skyTexture[3]);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, -0.5f);
	glEnd();
	//left
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, skyTexture[4]);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, 0.5f);
	glEnd();
	//right
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, skyTexture[5]);
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, 0.5f);
	glEnd();
}

