#pragma once
#include "vector3f.h"

class Camera
{
public:
	Camera();
	Vector3f mPos, mViewCenter, mUp;
	bool mbMoveLeft, mbMoveRight, mbMoveForward, mbMoveBack;

	void Update(float deltaTime);
};

