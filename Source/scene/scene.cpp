//ThisFile Is about all Scene 

#include "scene/scene.h"
#include "Utils/Utils.h"

GLuint texture;

/*----Init Scene Context And Call Draw All Scene----*/
void Init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0f,1280.0f/720.0f,0.01f,1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	texture = CreateTextureToBMP("Test.bmp");
}

void Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f,2.0f,0.0f,0.0f,0.0f,-1.0f,0.0f,1.0f,0.0f);

	glEnable(GL_DEPTH_TEST);

	//Enable And Bind Texture
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	//Setting Opengl Diffuse Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float LightPosp[] = { 0.5f,0.0f,0.0f,0.5f };
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosp);
	
	float whiteColor[] = {1.0f,1.0f,1.0f,1.0f};
	float ambientMat[] = {0.07f,0.07f,0.07f,1.0f};
	float diffuseMat[] = { 0.4f,0.4f,0.4f,1.0f };
	float specularMat[] = { 0.9f,0.9f,0.9f,1.0f };
	float blackColor[] = { 0.0f,0.0f,0.0f,1.0f };

	glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMat);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMat);

	glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);

	//Render Model
	glPushMatrix();
	glTranslatef(0.0f, -0.5f, 0.0f);
	DrawTriangle();
	glPopMatrix();

	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(30.0f, -1.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -2.0f);
	DrawPlant();

	//glPushMatrix();
	//  glTranslatef(-0.5f,0.0f,-0.7f);
	//  glRotatef(85.0f,-1.0f,0.0f,0.0f);
	//  glScalef(1.0f,1.0f,1.0f);
	// DrawTriangleStrip();
	//glPopMatrix();

	//glRotatef(15.0f, -0.2f, 0.0f, -0.3f);
	//glPushMatrix();
	//  glTranslatef(0.5f, 0.0f, -0.5f);
	//  DrawTriangle();
	//glPopMatrix();
}

/**----------------------DrawTestScene--------------------**/
void DrawTriangle()
{
	glBegin(GL_TRIANGLES);
	glTexCoord2d(0.0f,0.0f); glVertex3f(-0.2f, -0.2f, -1.5f);
	glTexCoord2d(1.0f,0.0f); glVertex3f( 0.2f, -0.2f, -1.5f);
	glTexCoord2d(0.5f,1.0f); glVertex3f( 0.0f,  0.2f, -1.5f);
	glEnd();
}

void DrawTriangleStrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, 0.0f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, 0.0f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.5f, 0.25f, 0.0f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.25f, 0.0f);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.5f, 0.75f, 0.0f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.75f, 0.0f);
	glEnd();
}

void DrawTriangleFan()
{
	glBegin(GL_TRIANGLE_FAN);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.35f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, -0.20f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2f, 0.25f, -2.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.5f, 0.5f, -2.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-1.2f, 0.25f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(-1.5f, -0.20f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(-1.5f, -0.35f, -2.5f);
	glEnd();
}

void DrawPoint()
{
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2f, -0.2f, -1.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2f, -0.2f, -1.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.0f, 0.2f, -1.5f);
	glEnd();
}

void DrawLines()
{
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2f, -0.2f, -1.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2f, -0.2f, -1.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2f, -0.2f, -1.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.0f, 0.2f, -1.5f);
	glEnd();
}

void DrawLineLoop()
{
	glLineWidth(10.0f);
	glBegin(GL_LINE_LOOP);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2f, -0.2f, -1.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2f, -0.2f, -1.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.0f, 0.2f, -1.5f);
	glEnd();
}

void DrawLineStrip()
{
	glLineWidth(10.0f);
	glBegin(GL_LINE_STRIP);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2f, -0.2f, -1.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(0.2f, -0.2f, -1.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.0f, 0.2f, -1.5f);
	glEnd();
}

void DrawQuads()
{
	glBegin(GL_QUADS);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.25f, -2.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.5f, 0.25f, -2.5f);
	glEnd();
}

void DrawQudaStrip()
{
	glBegin(GL_QUAD_STRIP);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, -2.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.5f, 0.25f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.5f, 0.75f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.75f, -2.5f);
	glEnd();
}

void DrawPolygon()
{
	glBegin(GL_POLYGON);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.35f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, -0.20f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.2f, 0.25f, -2.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.5f, 0.5f, -2.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-1.2f, 0.25f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(-1.5f, -0.20f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(-1.5f, -0.35f, -2.5f);
	glEnd();
}

void DrawPlant()
{
	glBegin(GL_QUADS);
	glColor4ub(128, 128, 128, 255);
	glTexCoord2d(0.0f,0.0f); glVertex3f(-2.0f, -0.2f, 0.0f);
	glTexCoord2d(1.f, 0.0f); glVertex3f(2.0f, -0.2f, 0.0f);
	glTexCoord2d(1.f, 1.f); glVertex3f(2.0f, -0.2f, -4.5f);
	glTexCoord2d(0.0f, 1.f); glVertex3f(-2.0f, -0.2f, -4.5f);
	glEnd();
}


