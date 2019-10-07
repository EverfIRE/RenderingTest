#include "Camera.h"

Camera::Camera():mPos(0.0f,0.0f,0.0f),mViewCenter(0.0f,0.0f,-1.0f),mUp(0.0f,1.0f,0.0f)
{
	camMoveState = MoveStat::defaults;
}

void Camera::Update(float deltaTime,float moveSpeed)
{
	Vector3f forwardvector = mViewCenter - mPos;
	forwardvector.Normalize();
	Vector3f rightvector = Cross(forwardvector,mUp);
	rightvector.Normalize();
	Vector3f delta = 0;
	switch (camMoveState)
	{
	case mbMoveLeft:
		delta = rightvector * deltaTime * moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;
		break;
	case mbMoveRight:
		delta = rightvector * deltaTime * moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;
		break;
	case mbMoveForward:
		delta = forwardvector * deltaTime * moveSpeed;
		mPos = mPos + delta;
		mViewCenter = mViewCenter + delta;
		break;
	case mbMoveBack:
		delta = forwardvector * deltaTime * moveSpeed;
		mPos = mPos - delta;
		mViewCenter = mViewCenter - delta;
		break;
	case defaults:
		break;
	}




	//float delta = -deltaTime * moveSpeed;

	//mViewCenter.z = mViewCenter.z - delta;

	glLoadIdentity();
	gluLookAt(mPos.x,mPos.y,mPos.z,
			  mViewCenter.x,mViewCenter.y,mViewCenter.z,
			  mUp.x,mUp.y,mUp.z);
}
