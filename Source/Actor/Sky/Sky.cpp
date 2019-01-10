#include "Sky.h"


Sky::Sky()
{
}


Sky::~Sky()
{
}

void Sky::BoxSky()
{
	//front
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f,1.0f); glColor4ub(255,255,255,255); glVertex3f(-0.5f,2.5f,-0.5f);
	glTexCoord2d(1.0f,1.0f); glColor4ub(255,255,255,255); glVertex3f(0.5,2.5f,-0.5f);
	glTexCoord2d(1.0f,0.0f); glColor4ub(255,255,255,255); glVertex3f(0.5f,1.5f,-0.5f);
	glEnd();
	//Top
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, 0.5f);
	glEnd();
	//back
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, 0.5f);
	glEnd();
	//down
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, 0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, -0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, -0.5f);
	glEnd();
	//left
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(-0.5f, 1.5f, 0.5f);
	glEnd();
	//right
	glBegin(GL_QUADS);
	glTexCoord2d(0.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, -0.5f);
	glTexCoord2d(0.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, -0.5f);
	glTexCoord2d(1.0f, 1.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 2.5f, 0.5f);
	glTexCoord2d(1.0f, 0.0f); glColor4ub(255, 255, 255, 255); glVertex3f(0.5f, 1.5f, 0.5f);
	glEnd();
}

