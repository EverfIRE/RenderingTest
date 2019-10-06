//ThisFile Is about all Scene 

#include "scene.h"
#include "Utils.h"
#include "Sky.h"
#include "Model.h"
#include "Ground.h"
#include "DirectionLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Camera.h"
#include "Enum.h"

GLuint texture;
Sky aSky;
Model model;
Ground ground;
DirectionLight directionlight(GL_LIGHT0);
PointLight pointLight(GL_LIGHT1), pointLight1(GL_LIGHT2);
SpotLight spotlight(GL_LIGHT3);
Camera maincamera;

/*----Init Scene Context And Call Draw All Scene----*/
void Init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0f,1280.0f/720.0f,0.01f,1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	directionlight.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
	directionlight.SetDiffuseColor(0.6f, 0.6f, 0.6f, 1.0f);
	directionlight.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	directionlight.SetPosition(0.0f, 1.0f, 0.0f);

	pointLight.SetAmbientColor(0.1f,0.1f,0.1f,1.0f);
	pointLight.SetDiffuseColor(0.8f,1.0f,0.8f,1.0f);
	pointLight.SetSpecularColor(1.0f,1.0f,1.0f,1.0f);
	pointLight.SetPosition(0.0f,0.0f,0.0f);
	pointLight.SetConstAttenuation(1.0f);
	pointLight.SetLinearAttenuation(0.2f);

	pointLight1.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
	pointLight1.SetDiffuseColor(1.0f, 0.8f, 0.8f, 1.0f);
	pointLight1.SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	pointLight1.SetPosition(-10.0f, 0.0f, -15.0f);
	pointLight1.SetConstAttenuation(1.0f);
	pointLight1.SetLinearAttenuation(0.2f);

	spotlight.SetAmbientColor(0.1f, 0.1f, 0.1f, 1.0f);
	spotlight.SetDiffuseColor(0.0f, 0.8f, 0.0f, 1.0f);
	spotlight.SetSpecularColor(1.0f, 0.0f, 0.0f, 1.0f);
	spotlight.SetPosition(10.0f,50.0f,-30.0f);
	spotlight.SetDirection(0.0f,-1.0f,0.0f);
	spotlight.SetExponent(5.0f);
	spotlight.SetCutoff(10.0f);

	texture = CreateDefaultBMP("Default.bmp");
	aSky.Init("Resource/Res_skybox/",true);
	model.Init("Resource/SceneOBJ/Sphere.obj");	
	model.mTexture = CreateDefaultBMP("Resource/earth.bmp");
	model.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f);
	model.SetDiffuseMaterial(0.8f, 0.8f, 0.8f, 1.0f);
	model.SetSpecularMaterial(1.0f, 1.0f, 1.0f, 1.0f);

	ground.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f);
	ground.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
	ground.SetSpecularMaterial(0.0f, 0.0f, 0.0f, 1.0f);
}

void Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float frameTime = GetFrameTime();
	maincamera.Update(frameTime,5.0);

	directionlight.Enable(false);
	pointLight.Enable(true);
	pointLight.UpdatePosition(0, 0, 0);
	pointLight1.Enable(true);
	pointLight1.UpdatePosition(0, 0, 0);
	spotlight.Enable(true);
	spotlight.UpdatePosition(0, 0, 0);
	aSky.EnableLight(false);
	aSky.Draw();

	model.EnableLight(true);
	model.Draw();

	ground.EnableLight(true);
	ground.Draw();
	//DrawTriangle();
}

void OneKeyDown(char key)
{
	switch (key)
	{
	case 'A':
		maincamera.camMoveState = MoveStat::mbMoveLeft;
		break;
	case 'D':
		maincamera.camMoveState = MoveStat::mbMoveRight;
		break;
	case 'W':
		maincamera.camMoveState = MoveStat::mbMoveForward;
		break;
	case 'S':
		maincamera.camMoveState = MoveStat::mbMoveBack;
		break;
	default:
		break;
	}
}

void OneKeyUp(char key)
{
	switch (key)
	{
	case 'A':
		maincamera.camMoveState = MoveStat::defaults;
		break;
	case 'D':
		maincamera.camMoveState = MoveStat::defaults;
		break;
	case 'W':
		maincamera.camMoveState = MoveStat::defaults;
		break;
	case 'S':
		maincamera.camMoveState = MoveStat::defaults;
		break;
	default:
		break;
	}
}

void OneMouseMove(float deltax, float deltay)
{

}

/**----------------------DrawTestScene--------------------**/
void DrawTriangle()
{
	glBindTexture(GL_TEXTURE_2D, texture);
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

//Enable And Bind Texture
//glBindTexture(GL_TEXTURE_2D, texture);

//Setting Opengl Diffuse Lighting
//glEnable(GL_LIGHTING);
//glEnable(GL_LIGHT0);

//float LightPosp[] = { 0.5f,0.0f,0.0f,0.5f };
//glLightfv(GL_LIGHT0, GL_POSITION, LightPosp);
//
//float whiteColor[] = {1.0f,1.0f,1.0f,1.0f};
//float ambientMat[] = {0.07f,0.07f,0.07f,1.0f};
//float diffuseMat[] = { 0.4f,0.4f,0.4f,1.0f };
//float specularMat[] = { 0.9f,0.9f,0.9f,1.0f };
//float blackColor[] = { 0.0f,0.0f,0.0f,1.0f };

//glLightfv(GL_LIGHT0, GL_AMBIENT, whiteColor);
//glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMat);

//glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteColor);
//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMat);

//glLightfv(GL_LIGHT0, GL_SPECULAR, whiteColor);
//glMaterialfv(GL_FRONT, GL_SPECULAR, specularMat);
