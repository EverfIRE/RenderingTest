#include "Utils/Struct.h"
#include <Utils/Enum.h>
#include "Utils/Utils.h"
#include "Object.h"

class Model:public Object
{
//private variable
private:
	QVertexData*mVertexesData;
	unsigned short* mIndexes;
	int mIndexCount;
	float mAmbientMaterial[4], mDiffuseMaterial[4], mSpecularMaterial[4];

//Private Function
private:
	unsigned char * DecodeObj(unsigned char * bmpFileData);

//public varible
public:
	GLuint mTexture;
//public function
public:
	Model();
	void Init(const char*TexPath);
	void Draw();
	void SetAmbientMaterial(float r, float g, float b, float a);
	void SetDiffuseMaterial(float r, float g, float b, float a);
	void SetSpecularMaterial(float r, float g, float b, float a);
};
