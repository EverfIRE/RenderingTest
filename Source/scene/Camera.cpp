#include "Camera.h"

Camera::Camera():mPos(0.0f,0.0f,0.0f),mViewCenter(0.0f,0.0f,-1.0f),mUp(0.0f,1.0f,0.0f)
{
	mbMoveLeft = false;
	mbMoveRight = false;
	mbMoveForward = false;
	mbMoveBack = false;
}

void Camera::Update(float deltaTime)
{
	float moveSpeed = 10.0f;
	Vector3f forwardvector = mViewCenter - mPos;
	forwardvector.Normalize();
	Vector3f rightvector = Cross(forwardvector,mUp);
	rightvector.Normalize();

	float delta = -deltaTime * moveSpeed;
	mPos = mPos - delta;
	//mViewCenter.z = mViewCenter.z - delta;

	glLoadIdentity();
	gluLookAt(mPos.x,mPos.y,mPos.z,
			  mViewCenter.x,mViewCenter.y,mViewCenter.z,
			  mUp.x,mUp.y,mUp.z);
}
