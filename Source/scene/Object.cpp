#include "Object.h"

Object::Object()
{

}

Object::~Object()
{
}

void Object::EnableLight(bool _enableLight)
{
	if (_enableLight)
	{
		glEnable(GL_LIGHTING);
	}
	else
	{
		glDisable(GL_LIGHTING);
	}
}




