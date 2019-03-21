#pragma once

class Sky
{
private:
	GLuint skyTexture[6];
	GLuint fastDrawCall;
public:
	void Init(const char*imageDir);
	void DrawCommand();
	void Draw();
};

