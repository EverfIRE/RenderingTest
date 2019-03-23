#pragma once
//All Common Struct

struct QImageSize
{
	int Height;
	int Width;
};

struct QVector2D
{
	float x;
	float y;
};

struct QFaceIndex
{
	int posIndex;
	int texcoordIndex;
	int normalIndex;
};

struct QVertexData {
	float position[3];
	float normal[3];
	float texcoord[2];
};

struct QVector3D
{
	float x;
	float y;
	float z;
};

struct QFloatData {
	float v[3];
};

struct QTransform
{
	QVector3D Position = {0.0f,0.0f,0.0f};
	QVector3D Rotation = { 0.0f,0.0f,0.0f };
	QVector3D Scale = { 1.0f,1.0f,1.0f };
};
