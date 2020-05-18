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

void Camera::Pitch(float angle)
{
	Vector3f viewDirection = mViewCenter - mPos;
	viewDirection.Normalize();
	Vector3f rightDirection = Cross(viewDirection,mUp);
	rightDirection.Normalize();
	RotateView(angle, rightDirection.x, rightDirection.y, rightDirection.z);
}

void Camera::Yaw(float angle)
{
	RotateView(angle, mUp.x, mUp.y, mUp.z);
}

void Camera::RotateView(float angle, float x, float y, float z)
{
	Vector3f viewDirection = mViewCenter - mPos;
	Vector3f newDirection(0.0f,0.0f,0.0f);

	float c = cosf(angle);
	float s = sinf(angle);
	Vector3f tempX(c+x*x*(1-c),x*y*(1-c)-z*s,x*z*(1-c)+y*s);
	newDirection.x = tempX * viewDirection;
	Vector3f tempY(x*y*(1-c)+z*s,c+y*y*(1-c),y*z*(1-c)-x*s);
	newDirection.y = tempY * viewDirection;
	Vector3f tempZ(x*z*(1-c)-y*s,y*z*(1-c)+x*s,c+z*z*(1-c));
	newDirection.z = tempZ * viewDirection;

	mViewCenter = mPos + newDirection;
}

