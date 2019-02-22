#include "Utils/Struct.h"

class Model
{
public:
	Model(char*TexPath);
	~Model();

	struct QTransform
	{
		QVector3D Position;
		QVector3D Rotation = {0.0f,0.0f,0.0f};
		QVector3D Scale = {1.0f,1.0f,1.0f};
	};

//private variable
private:
	enum ModelType
	{
		THREEDS=1,
		OBJ=2,
		FBX=3,
		DEFAULT=4,
	};
//Private Function
private:
	void Init(char*TexPath);
	unsigned char * DecodeObj(unsigned char * bmpFileData);
};
