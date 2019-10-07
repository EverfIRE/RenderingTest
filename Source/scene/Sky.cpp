#include "Sky.h"
#include "Utils/Utils.h"

void Sky::Init(const char*imageDir, bool _enableDraw)
{
	enableDraw = _enableDraw;

	if (enableDraw)
	{
		char temp[256];
		memset(temp, 0, 256);
		strcpy(temp, imageDir);
		strcat(temp, "front.bmp");
		skyTexture[0] = CreateDefaultBMP(temp);
		memset(temp, 0, 256);
		strcpy(temp, imageDir);
		strcat(temp, "back.bmp");
		skyTexture[1] = CreateDefaultBMP(temp);
		memset(temp, 0, 256);
		strcpy(temp, imageDir);
		strcat(temp, "left.bmp");
		skyTexture[2] = CreateDefaultBMP(temp);
		memset(temp, 0, 256);
		strcpy(temp, imageDir);
		strcat(temp, "right.bmp");
		skyTexture[3] = CreateDefaultBMP(temp);
		memset(temp, 0, 256);
		strcpy(temp, imageDir);
		strcat(temp, "top.bmp");
		skyTexture[4] = CreateDefaultBMP(temp);
		memset(temp, 0, 256);
		strcpy(temp, imageDir);
		strcat(temp, "bottom.bmp");
		skyTexture[5] = CreateDefaultBMP(temp);

		fastDrawCall = CreateDisplayList([this]()->void {DrawCommand(); });
	}

}

void Sky::DrawCommand()
{

	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	//front
	glBindTexture(GL_TEXTURE_2D, skyTexture[0]);
	glBegin(GL_QUADS);
	glColor4ub(255, 255, 255, 255);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, skyTexture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glEnd();
	//left
	glBindTexture(GL_TEXTURE_2D, skyTexture[2]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	//right
	glBindTexture(GL_TEXTURE_2D, skyTexture[3]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glEnd();
	//top
	glBindTexture(GL_TEXTURE_2D, skyTexture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);
	glEnd();
	//bottom
	glBindTexture(GL_TEXTURE_2D, skyTexture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);
	glEnd();
}

void Sky::Draw(Vector3f pos)
{
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glCallList(fastDrawCall);
	glPopMatrix();
}

