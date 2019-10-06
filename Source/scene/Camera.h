#pragma once
#include "vector3f.h"
#include "Enum.h"

class Camera
{
public:
	Camera();
	Vector3f mPos, mViewCenter, mUp;
	MoveStat camMoveState;

	void Update(float deltaTime, float moveSpeed);
};

