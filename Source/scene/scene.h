//ThisFile Is about all Scene 
#pragma once

#include "GLRenderContext.h"

//Init Scene Draw Context
void Init();

//Draw All Scene
void Draw();

//Imput Message
void OneKeyDown(char key);
void OneKeyUp(char key);
void OneMouseMove(float deltax,float deltay);

/**------------------Draw triangle--------------------**/
void DrawTriangle();

void DrawTriangleStrip();

void DrawTriangleFan();

/**------------------Draw Point And Line--------------------**/
void DrawPoint();

//Draw Discontinuous Line segment
void DrawLines();

//Draw Closed Line
void DrawLineLoop();

//Draw Continuous Line
void DrawLineStrip();

/**------------------ Draw Quads --------------------**/
void DrawQuads();

void DrawQudaStrip();

void DrawPolygon();

void DrawPlant();