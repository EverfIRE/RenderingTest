//ThisFile Is about all Scene 

#include "scene.h"

/*----Init Scene Context And Call Draw All Scene----*/
void Init()
{
	glMatrixMode(GL_PROJECTION);
	gluPerspective(50.0f,1280.0f/720.0f,0.01f,1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawTriangleStrip();
}

/**----------------------DrawTestScene--------------------**/
void DrawTriangle()
{
	glBegin(GL_TRIANGLES);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.2f, -0.2f, -1.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f( 0.2f, -0.2f, -1.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f( 0.0f,  0.2f, -1.5f);
	glEnd();
}

void DrawTriangleStrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	glColor4ub(255, 0, 0, 255); glVertex3f(-0.5f, -0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(0.5f, -0.25f, -2.5f);
	glColor4ub(0, 255, 0, 255); glVertex3f(-0.5f, 0.25f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.25f, -2.5f);
	glColor4ub(0, 0, 255, 255); glVertex3f(-0.5f, 0.75f, -2.5f);
	glColor4ub(255, 0, 0, 255); glVertex3f(0.5f, 0.75f, -2.5f);
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


