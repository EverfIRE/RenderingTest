#pragma once

class Sky
{
private:
	GLuint skyTexture[6];
public:
	Sky();
	~Sky();
	void Init();
	void BoxSky();
};

